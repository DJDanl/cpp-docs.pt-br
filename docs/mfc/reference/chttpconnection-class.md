---
title: Classe CHttpConnection
ms.date: 03/27/2019
f1_keywords:
- CHttpConnection
- AFXINET/CHttpConnection
- AFXINET/CHttpConnection::CHttpConnection
- AFXINET/CHttpConnection::OpenRequest
helpviewer_keywords:
- CHttpConnection [MFC], CHttpConnection
- CHttpConnection [MFC], OpenRequest
ms.assetid: a402b662-c445-4988-800d-c8278551babe
ms.openlocfilehash: af402b532b3aba28bdfefea5afa67331765db4c5
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81351824"
---
# <a name="chttpconnection-class"></a>Classe CHttpConnection

Gerencia sua conexão a um servidor HTTP.

## <a name="syntax"></a>Sintaxe

```
class CHttpConnection : public CInternetConnection
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[ChttpConnection::ChttpConnection](#chttpconnection)|Cria um objeto `CHttpConnection`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[ChttpConnection::OpenRequest](#openrequest)|Abre uma solicitação HTTP.|

## <a name="remarks"></a>Comentários

HTTP é um dos três protocolos de servidor de Internet implementados pelas classes MFC WinInet.

A `CHttpConnection` classe contém um construtor e uma função de membro, [OpenRequest,](#openrequest)que gerencia conexões a um servidor com um protocolo HTTP.

Para se comunicar com um servidor HTTP, primeiro você deve criar uma instância de [CInternetSession](../../mfc/reference/cinternetsession-class.md)e, em seguida, criar um objeto [CHttpConnection.](#chttpconnection) Você nunca `CHttpConnection` cria um objeto diretamente; em vez disso, chame [CInternetSession::GetHttpConnection](../../mfc/reference/cinternetsession-class.md#gethttpconnection), que cria o `CHttpConnection` objeto e retorna um ponteiro para ele.

Para saber mais `CHttpConnection` sobre como funciona as outras aulas de Internet do MFC, consulte o artigo [Programação na Internet com WinInet](../../mfc/win32-internet-extensions-wininet.md). Para obter mais informações sobre como se conectar a servidores usando os outros dois protocolos de Internet suportados, gopher e FTP, consulte as classes [CGopherConnection](../../mfc/reference/cgopherconnection-class.md) e [CFtpConnection](../../mfc/reference/cftpconnection-class.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cinternetconnection](../../mfc/reference/cinternetconnection-class.md)

`CHttpConnection`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxinet.h

## <a name="chttpconnectionchttpconnection"></a><a name="chttpconnection"></a>ChttpConnection::ChttpConnection

Esta função membro é `CHttpConnection` chamada para construir um objeto.

```
CHttpConnection(
    CInternetSession* pSession,
    HINTERNET hConnected,
    LPCTSTR pstrServer,
    DWORD_PTR dwContext);

CHttpConnection(
    CInternetSession* pSession,
    LPCTSTR pstrServer,
    INTERNET_PORT nPort = INTERNET_INVALID_PORT_NUMBER,
    LPCTSTR pstrUserName = NULL,
    LPCTSTR pstrPassword = NULL,
    DWORD_PTR dwContext = 1);

CHttpConnection(
    CInternetSession* pSession,
    LPCTSTR pstrServer,
    DWORD dwFlags,
    INTERNET_PORT nPort = INTERNET_INVALID_PORT_NUMBER,
    LPCTSTR pstrUserName = NULL,
    LPCTSTR pstrPassword = NULL,
    DWORD_PTR dwContext = 1);
```

### <a name="parameters"></a>Parâmetros

*pSession*<br/>
Um ponteiro para um objeto [CInternetSession.](../../mfc/reference/cinternetsession-class.md)

*hConnected*<br/>
Uma alça para uma conexão com a Internet.

*PstrServer*<br/>
Um ponteiro para uma seqüência contendo o nome do servidor.

*Dwcontext*<br/>
O identificador de `CInternetConnection` contexto para o objeto. Para obter mais informações sobre *o dwContext,* consulte a seção **Observações.**

*nPort*<br/>
O número que identifica a porta da Internet para essa conexão.

*pstrUserName*<br/>
Pointer para uma seqüência de terminadas nula que especifica o nome do usuário para fazer login. Se NULO, o padrão é anônimo.

*Pstrpassword*<br/>
Um ponteiro para uma seqüência de terminadas nula que especifica a senha a ser usada para fazer login. Se tanto *pstrPassword* quanto *pstrUserName* forem NULL, a senha anônima padrão é o nome de e-mail do usuário. Se *pstrPassword* for NULL ou uma seqüência vazia, mas *pstrUserName* não for NULL, uma senha em branco será usada. A tabela a seguir descreve o comportamento das quatro configurações possíveis de *pstrUserName* e *pstrPassword*:

|*pstrUserName*|*Pstrpassword*|Nome de usuário enviado para servidor FTP|Senha enviada para servidor FTP|
|--------------------|--------------------|---------------------------------|---------------------------------|
|NULO ou " "|NULO ou " "|"anônimo"|Nome de e-mail do usuário|
|String não-nula|NULO ou " "|*pstrUserName*|" "|
|NULO |String não-nula|ERROR|ERROR|
|String não-nula|String não-nula|*pstrUserName*|*Pstrpassword*|

*dwFlags*<br/>
Qualquer combinação `INTERNET_FLAG_*` das bandeiras. Veja a tabela na seção **Observações** de [CHttpConnection::OpenRequest](#openrequest) para obter uma descrição dos valores *dwFlags.*

### <a name="remarks"></a>Comentários

Você nunca `CHttpConnection` cria um diretamente. Em vez disso, você cria um objeto chamando [CInternetSession::GetHttpConnection](../../mfc/reference/cinternetsession-class.md#gethttpconnection).

## <a name="chttpconnectionopenrequest"></a><a name="openrequest"></a>ChttpConnection::OpenRequest

Ligue para esta função de membro para abrir uma conexão HTTP.

```
CHttpFile* OpenRequest(
    LPCTSTR pstrVerb,
    LPCTSTR pstrObjectName,
    LPCTSTR pstrReferer = NULL,
    DWORD_PTR dwContext = 1,
    LPCTSTR* ppstrAcceptTypes = NULL,
    LPCTSTR pstrVersion = NULL,
    DWORD dwFlags = INTERNET_FLAG_EXISTING_CONNECT);

CHttpFile* OpenRequest(
    int nVerb,
    LPCTSTR pstrObjectName,
    LPCTSTR pstrReferer = NULL,
    DWORD_PTR dwContext = 1,
    LPCTSTR* ppstrAcceptTypes = NULL,
    LPCTSTR pstrVersion = NULL,
    DWORD dwFlags = INTERNET_FLAG_EXISTING_CONNECT);
```

### <a name="parameters"></a>Parâmetros

*pstrVerb*<br/>
Um ponteiro para uma seqüência contendo o verbo para usar na solicitação. Se NULO, "GET" é usado.

*pstrObjectName*<br/>
Um ponteiro para uma seqüência contendo o objeto alvo do verbo especificado. Esta seqüência é geralmente um nome de arquivo, um módulo executável ou um especificador de pesquisa.

*pstrReferer*<br/>
Um ponteiro para uma seqüência que especifica o endereço (URL) do documento a partir do qual a URL na solicitação *(pstrObjectName)* foi obtida. Se NULA, nenhum cabeçalho HTTP será especificado.

*Dwcontext*<br/>
O identificador de `OpenRequest` contexto para a operação. Para obter mais informações sobre *o dwContext,* consulte a seção Observações.

*ppstrAcceptTypes*<br/>
Um ponteiro para uma matriz de ponteiros LPCTSTR com final ação final nula para strings que indicam tipos de conteúdo aceitos pelo cliente. Se *ppstrAcceptTypes* for NULL, os servidores interpretam que o cliente só aceita documentos do tipo "texto/*" (ou seja, apenas documentos de texto e não imagens ou outros arquivos binários). O tipo de conteúdo é equivalente à variável CGI CONTENT_TYPE, que identifica o tipo de dados para consultas que anexaram informações, como HTTP POST e PUT.

*pstrVersion*<br/>
Um ponteiro para uma seqüência definindo a versão HTTP. Se NULO, "HTTP/1.0" é usado.

*dwFlags*<br/>
Qualquer combinação das bandeiras INTERNET_ FLAG_*. Consulte a seção Observações para obter uma descrição dos possíveis valores *dwFlags.*

*Nverb*<br/>
Um número associado ao tipo de solicitação HTTP. Um dos seguintes pode ser feito:

|Tipo de solicitação HTTP|*valor nVerb*|
|-----------------------|-------------------|
|HTTP_VERB_POST|0|
|HTTP_VERB_GET|1|
|HTTP_VERB_HEAD|2|
|HTTP_VERB_PUT|3|
|HTTP_VERB_LINK|4|
|HTTP_VERB_DELETE|5|
|HTTP_VERB_UNLINK|6|

### <a name="return-value"></a>Valor retornado

Um ponteiro para o objeto [CHttpFile](../../mfc/reference/chttpfile-class.md) solicitado.

### <a name="remarks"></a>Comentários

*dwFlags* pode ser um dos seguintes:

|Bandeira da Internet|Descrição|
|-------------------|-----------------|
|INTERNET_FLAG_RELOAD|Força o download da listagem de arquivo, objeto ou diretório solicitado do servidor de origem, não do cache.|
|INTERNET_FLAG_DONT_CACHE|Não adiciona a entidade devolvida ao cache.|
|INTERNET_FLAG_MAKE_PERSISTENT|Adiciona a entidade devolvida ao cache como uma entidade persistente. Isso significa que a limpeza padrão do cache, a verificação de consistência ou a coleta de lixo não podem remover esse item do cache.|
|INTERNET_FLAG_SECURE|Usa semântica de transação segura. Ele se traduz em usar SSL/PCT e só é significativo em solicitações HTTP|
|INTERNET_FLAG_NO_AUTO_REDIRECT|Usado apenas com HTTP, especifica que os redirecionamentos não devem ser tratados automaticamente em [CHttpFile::SendRequest](../../mfc/reference/chttpfile-class.md#sendrequest).|

Anular o `dwContext` padrão para definir o identificador de contexto a um valor de sua escolha. O identificador de contexto está associado `CHttpConnection` a esta operação específica do objeto criado pelo objeto [CInternetSession.](../../mfc/reference/cinternetsession-class.md) O valor é devolvido ao [CInternetSession::OnStatusCallback](../../mfc/reference/cinternetsession-class.md#onstatuscallback) para fornecer status na operação com a qual ele é identificado. Veja o artigo [Primeiros Passos da Internet: WinInet](../../mfc/wininet-basics.md) para obter mais informações sobre o identificador de contexto.

Exceções podem ser lançadas com esta função.

## <a name="see-also"></a>Confira também

[Classe CInternetConnection](../../mfc/reference/cinternetconnection-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CInternetConnection](../../mfc/reference/cinternetconnection-class.md)<br/>
[Classe CHttpFile](../../mfc/reference/chttpfile-class.md)
