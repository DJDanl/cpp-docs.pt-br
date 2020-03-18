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
ms.openlocfilehash: 1941af1e16a897235dd90db509d6ed29c2d9a875
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79420396"
---
# <a name="chttpconnection-class"></a>Classe CHttpConnection

Gerencia sua conexão com um servidor HTTP.

## <a name="syntax"></a>Sintaxe

```
class CHttpConnection : public CInternetConnection
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CHttpConnection::CHttpConnection](#chttpconnection)|Cria um objeto `CHttpConnection`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CHttpConnection::OpenRequest](#openrequest)|Abre uma solicitação HTTP.|

## <a name="remarks"></a>Comentários

O HTTP é um dos três protocolos de servidor de Internet implementados pelas classes do MFC WinInet.

A classe `CHttpConnection` contém um construtor e uma função de membro, [OpenRequest](#openrequest), que gerencia conexões com um servidor com um protocolo http.

Para se comunicar com um servidor HTTP, você deve primeiro criar uma instância de [CInternetSession](../../mfc/reference/cinternetsession-class.md)e, em seguida, criar um objeto [CHttpConnection](#chttpconnection) . Você nunca cria um objeto `CHttpConnection` diretamente; em vez disso, chame [CInternetSession:: GetHttpConnection](../../mfc/reference/cinternetsession-class.md#gethttpconnection), que cria o objeto `CHttpConnection` e retorna um ponteiro para ele.

Para saber mais sobre como `CHttpConnection` funciona com as outras classes de Internet do MFC, confira o artigo [programação de Internet com o WinInet](../../mfc/win32-internet-extensions-wininet.md). Para obter mais informações sobre como se conectar a servidores usando os outros dois protocolos de Internet com suporte, o Gopher e o FTP, consulte as classes [CGopherConnection](../../mfc/reference/cgopherconnection-class.md) e [CFtpConnection](../../mfc/reference/cftpconnection-class.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CInternetConnection](../../mfc/reference/cinternetconnection-class.md)

`CHttpConnection`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXINET. h

##  <a name="chttpconnection"></a>CHttpConnection::CHttpConnection

Essa função de membro é chamada para construir um objeto de `CHttpConnection`.

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

### <a name="parameters"></a>parâmetros

*pSession*<br/>
Um ponteiro para um objeto [CInternetSession](../../mfc/reference/cinternetsession-class.md) .

*hConnected*<br/>
Um identificador para uma conexão com a Internet.

*pstrServer*<br/>
Um ponteiro para uma cadeia de caracteres que contém o nome do servidor.

*dwContext*<br/>
O identificador de contexto para o objeto `CInternetConnection`. Para obter mais informações sobre *dwContext*, consulte a seção **comentários** .

*nPort*<br/>
O número que identifica a porta da Internet para esta conexão.

*pstrUserName*<br/>
Ponteiro para uma cadeia de caracteres terminada em nulo que especifica o nome do usuário para entrar. Se for NULL, o padrão será Anonymous.

*pstrPassword*<br/>
Um ponteiro para uma cadeia de caracteres terminada em nulo que especifica a senha a ser usada para entrar. Se *pstrPassword* e *pstrUserName* forem nulos, a senha anônima padrão será o nome de email do usuário. Se *pstrPassword* for nulo ou uma cadeia de caracteres vazia, mas *PSTRUSERNAME* não for NULL, uma senha em branco será usada. A tabela a seguir descreve o comportamento para as quatro configurações possíveis de *pstrUserName* e *pstrPassword*:

|*pstrUserName*|*pstrPassword*|Nome de usuário enviado ao servidor FTP|Senha enviada ao servidor FTP|
|--------------------|--------------------|---------------------------------|---------------------------------|
|NULL ou ""|NULL ou ""|modo|Nome de email do usuário|
|Cadeia de caracteres não nula|NULL ou ""|*pstrUserName*|" "|
|NULO |Cadeia de caracteres não nula|ERROR|ERROR|
|Cadeia de caracteres não nula|Cadeia de caracteres não nula|*pstrUserName*|*pstrPassword*|

*dwFlags*<br/>
Qualquer combinação dos sinalizadores de `INTERNET_FLAG_*`. Consulte a tabela na seção **comentários** de [CHttpConnection:: OpenRequest](#openrequest) para obter uma descrição dos valores de *dwFlags* .

### <a name="remarks"></a>Comentários

Você nunca cria um `CHttpConnection` diretamente. Em vez disso, você cria um objeto chamando [CInternetSession:: GetHttpConnection](../../mfc/reference/cinternetsession-class.md#gethttpconnection).

##  <a name="openrequest"></a>CHttpConnection::OpenRequest

Chame essa função de membro para abrir uma conexão HTTP.

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

### <a name="parameters"></a>parâmetros

*pstrVerb*<br/>
Um ponteiro para uma cadeia de caracteres que contém o verbo a ser usado na solicitação. Se for NULL, "GET" será usado.

*pstrObjectName*<br/>
Um ponteiro para uma cadeia de caracteres que contém o objeto de destino do verbo especificado. Essa cadeia de caracteres é geralmente um nome de arquivo, um módulo executável ou um especificador de pesquisa.

*pstrReferer*<br/>
Um ponteiro para uma cadeia de caracteres que especifica o endereço (URL) do documento do qual a URL na solicitação (*pstrObjectName*) foi obtida. Se for NULL, nenhum cabeçalho HTTP será especificado.

*dwContext*<br/>
O identificador de contexto para a operação de `OpenRequest`. Para obter mais informações sobre *dwContext*, consulte a seção comentários.

*ppstrAcceptTypes*<br/>
Um ponteiro para uma matriz terminada em nulo de ponteiros LPCTSTR para cadeias de caracteres indicando tipos de conteúdo aceitos pelo cliente. Se *ppstrAcceptTypes* for NULL, os servidores interpretarão que o cliente só aceita documentos do tipo "text/*" (ou seja, somente documentos de texto e não imagens ou outros arquivos binários). O tipo de conteúdo é equivalente à variável CGI CONTENT_TYPE, que identifica o tipo de dados para consultas que têm informações anexadas, como HTTP POST e PUT.

*pstrVersion*<br/>
Um ponteiro para uma cadeia de caracteres que define a versão HTTP. Se for NULL, "HTTP/1.0" será usado.

*dwFlags*<br/>
Qualquer combinação dos sinalizadores INTERNET_ FLAG_ *. Consulte a seção comentários para obter uma descrição dos possíveis valores *dwFlags* .

*nVerb*<br/>
Um número associado ao tipo de solicitação HTTP. Um dos seguintes pode ser feito:

|Tipo de solicitação HTTP|valor de *nVerb*|
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

|Sinalizador da Internet|DESCRIÇÃO|
|-------------------|-----------------|
|INTERNET_FLAG_RELOAD|Força um download da listagem de arquivo, objeto ou diretório solicitada do servidor de origem, não do cache.|
|INTERNET_FLAG_DONT_CACHE|Não adiciona a entidade retornada ao cache.|
|INTERNET_FLAG_MAKE_PERSISTENT|Adiciona a entidade retornada ao cache como uma entidade persistente. Isso significa que a limpeza do cache padrão, a verificação de consistência ou a coleta de lixo não podem remover esse item do cache.|
|INTERNET_FLAG_SECURE|Usa semântica de transação segura. Ele se traduz no uso de SSL/PCT e só é significativo em solicitações HTTP|
|INTERNET_FLAG_NO_AUTO_REDIRECT|Usado somente com HTTP, especifica que os redirecionamentos não devem ser manipulados automaticamente em [CHttpFile:: SendRequest](../../mfc/reference/chttpfile-class.md#sendrequest).|

Substitua o `dwContext` padrão para definir o identificador de contexto como um valor de sua escolha. O identificador de contexto é associado a essa operação específica do objeto `CHttpConnection` criado por seu objeto [CInternetSession](../../mfc/reference/cinternetsession-class.md) . O valor é retornado para [CInternetSession:: OnStatusCallback](../../mfc/reference/cinternetsession-class.md#onstatuscallback) para fornecer o status na operação com a qual ele é identificado. Consulte o artigo [primeiras etapas da Internet: WinInet](../../mfc/wininet-basics.md) para obter mais informações sobre o identificador de contexto.

Exceções podem ser geradas com essa função.

## <a name="see-also"></a>Confira também

[Classe CInternetConnection](../../mfc/reference/cinternetconnection-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CInternetConnection](../../mfc/reference/cinternetconnection-class.md)<br/>
[Classe CHttpFile](../../mfc/reference/chttpfile-class.md)
