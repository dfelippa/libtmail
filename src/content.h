/*
 * Mail.h
 *
 *  Created on: 2010-6-15
 *      Author: thor
 */

#ifndef CONTENT_H_
#define CONTENT_H_

#include "config.h"

#include <string>
#include <vector>
#include <ostream>
#include "header.h"


namespace tmail
{


class Content;
typedef tlib::RefPtr<Content> ContentPtr;
typedef std::vector<ContentPtr> Contents;

const std::wstring generate_boundary();

// Map the file extension name to MIME type.
const char* ext_to_mime(const char* ext_name);
// Map the MIME type to file extension name.
const char* mime_to_ext(const char* mime);

class Content : public tlib::Object
{
public:
	virtual ~Content();
private:
	class ContentHeaders
	{
	private:
		friend class Content;
		inline ContentHeaders();
	public:
		HeaderPtr add(const std::wstring& name);
		HeaderPtr add(HeaderPtr header);
		HeaderPtr get_header(const std::wstring& name) const;
		inline size_t count() const;
		inline void erase(size_t n);
		void erase(const std::wstring& name);
		inline HeaderPtr operator [] (size_t n);
		inline HeaderPtr operator [] (size_t n) const;
		inline void clear();
	private:
		Headers _headers;
	};
	class ContentMultiparts
	{
	private:
		friend class Content;
		inline ContentMultiparts();
	public:
		inline ContentPtr add(ContentPtr content);
		inline size_t count() const;
		inline void erase(size_t n);
		inline ContentPtr operator [] (size_t n);
		inline ContentPtr operator [] (size_t n) const;
		inline void clear();
	private:
		Contents _contents;
	};
public:
	void generate_id();
	const ContentHeaderPtr get_content_id() const;
	const ContentHeaderPtr get_content_type() const;
	const ContentHeaderPtr get_content_transfer_encoding() const;
	const ContentHeaderPtr get_content_disposition() const;
	const ContentHeaderPtr get_content_location() const;
	const std::string to_string(bool support_8bit = true) const;
	void parse(const char* str, size_t len, bool only_headers = false);
	bool load(const std::string& file_name, bool only_headers = false);
	bool load(const std::wstring& file_name, bool only_headers = false);
	bool save(const std::string& file_name);
	bool save(const std::wstring& file_name);
	void set_body_text(const std::wstring& text);
	const std::wstring get_body_text() const;
	bool load_body(const std::wstring& filename);
	bool save_body(const std::wstring& filename);
	inline void set_content_type(const std::wstring& content_type);
	void set_content_type(const std::wstring& content_type, const Parameters& parameters);
	inline void set_content_transfer_encoding(const std::wstring& encoding);
	void set_content_transfer_encoding(const std::wstring& encoding, const Parameters& parameters);
	inline void set_content_disposition(const std::wstring& disposition);
	void set_content_disposition(const std::wstring& disposition, const Parameters& parameters);
	inline void set_content_location(const std::wstring& location);
	void set_content_location(const std::wstring& location, const Parameters& parameters);

	void create_normal_body(const std::wstring& text, const std::wstring& html,
			const std::vector<std::wstring>& attachment_filenames) throw (std::runtime_error);
	inline
	void create_normal_body(const std::wstring& text,
			const std::wstring& html) throw (std::runtime_error);

	inline void create_normal_text_body(const std::wstring& text)  throw (std::runtime_error);
	inline void create_normal_text_body(const std::wstring& text,
			const std::vector<std::wstring>& attachment_filenames) throw (std::runtime_error);
	inline void create_normal_html_body(const std::wstring& html) throw (std::runtime_error);
	inline void create_normal_html_body(const std::wstring& html,
			const std::vector<std::wstring>& attachment_filenames) throw (std::runtime_error);

	void create_related_body(const std::wstring& html,
			const std::vector<std::wstring>& picture_filenames,
			const std::vector<std::wstring>& attachment_filenames, 
			bool use_cid = false) throw (std::runtime_error);
	inline
	void create_related_body(const std::wstring& html,
			const std::vector<std::wstring>& picture_filenames, 
			bool use_cid = false) throw (std::runtime_error);
private:
	void _parse_body(const char* entities, size_t len);
	void _parse_part(const char* entities, size_t len);
	void _parse_entities(const char* entity_begin, size_t len);
public:
	ContentHeaders headers;
	tlib::BinaryData body;
	ContentMultiparts multiparts;
};


inline
Content::ContentHeaders::ContentHeaders()
{
}

inline
HeaderPtr Content::ContentHeaders::operator [] (Headers::size_type n)
{
	return _headers.at(n);
}

inline
HeaderPtr Content::ContentHeaders::operator [] (Headers::size_type n) const
{
	return _headers.at(n);
}

inline
size_t Content::ContentHeaders::count() const
{
	return _headers.size();
}

inline
void Content::ContentHeaders::erase(size_t n)
{
	_headers.erase(_headers.begin() + n);
}
inline
void Content::ContentHeaders::clear()
{
	_headers.clear();
}


inline
Content::ContentMultiparts::ContentMultiparts()
{
}
inline
ContentPtr Content::ContentMultiparts::add(ContentPtr content)
{
	_contents.push_back(content);
	return content;
}
inline
size_t Content::ContentMultiparts::count() const
{
	return _contents.size();
}
inline
void Content::ContentMultiparts::erase(size_t n)
{
	_contents.erase(_contents.begin() + n);
}
inline
ContentPtr Content::ContentMultiparts::operator [] (size_t n)
{
	return _contents.at(n);
}
inline
ContentPtr Content::ContentMultiparts::operator [] (size_t n) const
{
	return _contents.at(n);
}
inline
void Content::ContentMultiparts::clear()
{
	_contents.clear();
}

inline
void Content::set_content_type(const std::wstring& content_type)
{
	Parameters p;
	set_content_type(content_type, p);
}
inline
void Content::set_content_transfer_encoding(const std::wstring& encoding)
{
	Parameters p;
	set_content_transfer_encoding(encoding, p);
}
inline
void Content::set_content_disposition(const std::wstring& disposition)
{
	Parameters p;
	set_content_disposition(disposition, p);
}
inline
void Content::set_content_location(const std::wstring& location)
{
	Parameters p;
	set_content_location(location, p);
}
inline
void Content::create_normal_body(const std::wstring& text,
		const std::wstring& html) throw (std::runtime_error)
{
	std::vector<std::wstring> empty;
	create_normal_body(text, html, empty);
}

inline 
void Content::create_normal_text_body(const std::wstring& text) throw (std::runtime_error)
{
	std::vector<std::wstring> empty;
	create_normal_body(text, L"", empty);
}
inline 
void Content::create_normal_text_body(const std::wstring& text, 
		const std::vector<std::wstring>& attachment_filenames) throw (std::runtime_error)
{
	create_normal_body(text, L"", attachment_filenames);
}
inline 
void Content::create_normal_html_body(const std::wstring& html) throw (std::runtime_error)
{
	std::vector<std::wstring> empty;
	create_normal_body(L"", html, empty);
}
inline 
void Content::create_normal_html_body(const std::wstring& html, 
		const std::vector<std::wstring>& attachment_filenames) throw (std::runtime_error)
{
	create_normal_body(L"", html, attachment_filenames);
}
inline
void Content::create_related_body(const std::wstring& html,
		const std::vector<std::wstring>& pictures, 
		bool use_cid) throw (std::runtime_error)
{
	std::vector<std::wstring> empty;
	create_related_body(html, pictures, empty, use_cid);
}

} // End of namespace.



#endif /* CONTENT_H_ */
