#include <tmail/tmail.h>
#include <iostream>

using namespace tmail;
using namespace std;

#define SMTP_VERIFY(x) \
	{ if (!x) { \
		cout << smtp.get_last_error_message() << endl; exit(-1); } }

void show_progress(size_t sent_bytes, const Request& request, bool& cancel)
{
	// set cancel=true to cancel the transmission.
	cout << "sent bytes: " << sent_bytes << endl;
}

int main(int argc, char* argv[])
{
	// This is important for use non-ASCII charset.
	setlocale(LC_ALL, "");

	// Sometimes, the address of the user input is non-standard,
	// but don't worry, libtmail will take care of.
	wstring from = L"Thor Qin <thor.qin@gmail.com>";
	wstring to = L"mailbox@google.com, "
			L"<mailbox@google.com>,"
			L"姓名 <mailbox@google.com>; "
			L"User Name mailbox@google.com,"
			L"\"Some Name\"@google.com";
//	wstring to = L"\"秦诺\" <thor.qin@gmail.com>";

	Mail mail;
	mail.set_from(from);
	mail.set_to(to);
	mail.set_subject(L"Simple message.");
	mail.create_normal_text_body(L"This is a test.");

	// save the mail content.
	mail.save("demo.eml");

	Smtp smtp;
	cout << "connect..." << endl;
	SMTP_VERIFY(smtp.connect("smtp.gmail.com"));
	SMTP_VERIFY(smtp.hello());
	if (smtp.is_enable_starttls())
	{
		cout << "starttls..." << endl;
		SMTP_VERIFY(smtp.starttls());
		SMTP_VERIFY(smtp.hello());
	}

	// Some SMTP servers only support login method,
	// but they didn't return any auth-types.
	cout << "auth..." << endl;
	SMTP_VERIFY(smtp.auth_login("username", "password"));

	cout << "send mail ..." << endl;
	SMTP_VERIFY(smtp.send_addresses_by_mail(mail));

	// If want to show the sending progress then register the signal call back function.
	// By this way, users can control the transmission (Usually put the sending process in other thread.)
	TcpConnection::SendingReportSignal::iterator iter =
			smtp.signal_sending_report().connect(sigc::ptr_fun(&show_progress));
	SMTP_VERIFY(smtp.send_mail(mail));
	iter->disconnect();

	smtp.quit();
	cout << "OK." << endl;
	return 0;
}
