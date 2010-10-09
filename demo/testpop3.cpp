#include <tmail/tmail.h>
#include <iostream>

using namespace tmail;
using namespace std;

#define POP3_VERIFY(x) \
	{ if (!x) { \
		cout << pop3.get_last_error_message() << endl; exit(-1); } }

static size_t mail_size = 0;
static size_t recv_size = 0;

void show_progress(size_t recv_bytes, const Response& response, bool& cancel)
{
	recv_size += recv_bytes;
	cout << int((recv_size / float(mail_size)) * 100) << "% ";
	cout.flush();
	// set cancel=true to cancel the transmission.
}

int main(int argc, char* argv[])
{
	// This is important for use non-ASCII charset.
	setlocale(LC_ALL, "");

	tmail::Pop3 pop3;
	cout << "connect..." << endl;
	POP3_VERIFY(pop3.connect("pop.gmail.com", 995, true));

	// POP3_VERIFY(pop3.capability());
	// Use this method to get server supported auth-types,
	// But not all servers support this method. In this case,
	// user may want to try every possible method of authentication.

	cout << "auth..." << endl;
	POP3_VERIFY(pop3.user("username"));
	POP3_VERIFY(pop3.pass("password"));

	cout << "get mail list ..." << endl;
//	Some server don't support UIDL command.
//	Pop3::UidIndex index;
//	POP3_VERIFY(pop3.uidl(index));
	Pop3::MailIndex index;
	pop3.list(index);

	TcpConnection::ReceivingReportSignal::iterator iter =
			pop3.signal_receiving_report().connect(sigc::ptr_fun(&show_progress));
	for (size_t i = 0; i < index.size(); i++)
	{
		cout << "receive mail " << index[i].first << " ..." << endl;
		mail_size = index[i].second;
		recv_size = 0;
		Mail mail;
		POP3_VERIFY(pop3.return_mail(index[i].first, mail));
		mail.save(tlib::wstrfrom<int>(index[i].first) + L"."
				+ mail.get_subject()->get_value());
		//pop3.delete_mail(index[i].first);
		cout << endl;
	}
	iter->disconnect();
	pop3.quit();
	cout << "OK." << endl;
}
