#pragma once
#pragma once

template<class Body>
class Response
{
public:
	Body body;
	int statusCode;
	Response(Body body, int statusCode) : body(body), statusCode(statusCode) {}
	Response() {}
	~Response() {}
};