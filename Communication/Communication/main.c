////请求报文的构成
//post  /form/entry HTTP/1.1

//Host:hackr.jp
//Connection:keep-alive
//Content-Type:application/x-www-form-urlencoded
//Content-Length:16

//name=ueno&age=37

//响应报文的构成
//HTTP/1.1  200  OK
//Date：Tue,  10 Jul 2012  06:50:15  GMT
//Content-Length: 362
//Content-Type: text/html

//<html>
//...

//请求URI
//Get http://hackr.jp/index.htm HTTP/1.1

//Get /index.htm HTTP/1.1
//Host:hackr.jp

//1. 请求报文（没有  Cookie  信息的状态）
// GET　/reader/　HTTP/1.1
// Host：hackr.jp
// * 首部字段内没有 Cookie 的相关信息

//２.响应报文（服务器端生成  Cookie  信息）
//HTTP / 1.1  200 OK
//Date : Tue, 12 Jul 2012 07 : 12 : 20 GMT
//Server : Apache
//< Set - Cookie : sid = 1342077140226724; path = / ; expires = Web, =>
//10 - Oct - 12 07 : 12 : 20 GMT >
//Content - Type:text / plain; charset = UTF - 8

////３.请求报文（自动发送保存着的  Cookie  信息）
//GET /image/ HTTP/1.1
//Host: hackr.jp
//Cookie: sid=1342077140226724