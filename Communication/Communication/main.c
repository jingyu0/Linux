////�����ĵĹ���
//post  /form/entry HTTP/1.1

//Host:hackr.jp
//Connection:keep-alive
//Content-Type:application/x-www-form-urlencoded
//Content-Length:16

//name=ueno&age=37

//��Ӧ���ĵĹ���
//HTTP/1.1  200  OK
//Date��Tue,  10 Jul 2012  06:50:15  GMT
//Content-Length: 362
//Content-Type: text/html

//<html>
//...

//����URI
//Get http://hackr.jp/index.htm HTTP/1.1

//Get /index.htm HTTP/1.1
//Host:hackr.jp

//1. �����ģ�û��  Cookie  ��Ϣ��״̬��
// GET��/reader/��HTTP/1.1
// Host��hackr.jp
// * �ײ��ֶ���û�� Cookie �������Ϣ

//��.��Ӧ���ģ�������������  Cookie  ��Ϣ��
//HTTP / 1.1  200 OK
//Date : Tue, 12 Jul 2012 07 : 12 : 20 GMT
//Server : Apache
//< Set - Cookie : sid = 1342077140226724; path = / ; expires = Web, =>
//10 - Oct - 12 07 : 12 : 20 GMT >
//Content - Type:text / plain; charset = UTF - 8

////��.�����ģ��Զ����ͱ����ŵ�  Cookie  ��Ϣ��
//GET /image/ HTTP/1.1
//Host: hackr.jp
//Cookie: sid=1342077140226724