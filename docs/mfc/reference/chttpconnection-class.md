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
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62237553"
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
|[CHttpConnection::CHttpConnection](#chttpconnection)|Cria um objeto `CHttpConnection`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CHttpConnection::OpenRequest](#openrequest)|Abre uma solicitação HTTP.|

## <a name="remarks"></a>Comentários

HTTP é um dos três protocolos de servidor de Internet implementados pelas classes WinInet do MFC.

A classe `CHttpConnection` contém um construtor e a função de um membro [OpenRequest](#openrequest), que gerencia conexões para um servidor com um protocolo HTTP.

Para se comunicar com um servidor HTTP, você deve primeiro criar uma instância do [CInternetSession](../../mfc/reference/cinternetsession-class.md)e, em seguida, crie um [CHttpConnection](#chttpconnection) objeto. Você nunca de criar uma `CHttpConnection` objeto diretamente; em vez disso, chame [CInternetSession::GetHttpConnection](../../mfc/reference/cinternetsession-class.md#gethttpconnection), que cria o `CHttpConnection` de objeto e retorna um ponteiro para ele.

Para saber mais sobre como `CHttpConnection` funciona com as outras classes de Internet do MFC, consulte o artigo [Internet Programando com WinInet](../../mfc/win32-internet-extensions-wininet.md). Para obter mais informações sobre como se conectar a servidores usando os outros dois com suporte a protocolos de Internet, gopher e FTP, consulte as classes [CGopherConnection](../../mfc/reference/cgopherconnection-class.md) e [CFtpConnection](../../mfc/reference/cftpconnection-class.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CInternetConnection](../../mfc/reference/cinternetconnection-class.md)

`CHttpConnection`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxinet.h

##  <a name="chttpconnection"></a>  CHttpConnection::CHttpConnection

Essa função membro é chamada para construir um `CHttpConnection` objeto.

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
Um ponteiro para um [CInternetSession](../../mfc/reference/cinternetsession-class.md) objeto.

*hConnected*<br/>
Um identificador para uma conexão de Internet.

*pstrServer*<br/>
Um ponteiro para uma cadeia de caracteres que contém o nome do servidor.

*dwContext*<br/>
O identificador de contexto para o `CInternetConnection` objeto. Para obter mais informações sobre *dwContext*, consulte o **comentários** seção.

*nPort*<br/>
O número que identifica a porta de Internet para esta conexão.

*pstrUserName*<br/>
Ponteiro para uma cadeia de caracteres terminada em nulo que especifica o nome do usuário para entrar. Se for NULL, o padrão é anônimo.

*pstrPassword*<br/>
Um ponteiro para uma cadeia de caracteres terminada em nulo que especifica a senha a ser usada para entrar. Se os dois *pstrPassword* e *pstrUserName* forem nulos, a senha de padrão anônimo é o nome de email do usuário. Se *pstrPassword* é nulo ou uma cadeia de caracteres vazia, mas *pstrUserName* não for nulo, uma senha em branco será usada. A tabela a seguir descreve o comportamento para as quatro configurações possíveis dos *pstrUserName* e *pstrPassword*:

|*pstrUserName*|*pstrPassword*|Nome de usuário enviado ao servidor FTP|Senha enviados ao servidor FTP|
|--------------------|--------------------|---------------------------------|---------------------------------|
|NULO ou ""|NULO ou ""|"anônimo"|Nome de email do usuário|
|Cadeia de caracteres não nula|NULO ou ""|*pstrUserName*|" "|
|NULL |Cadeia de caracteres não nula|ERROR|ERROR|
|Cadeia de caracteres não nula|Cadeia de caracteres não nula|*pstrUserName*|*pstrPassword*|

*dwFlags*<br/>
Qualquer combinação da `INTERNET_FLAG_*` sinalizadores. Consulte a tabela a **comentários** seção [CHttpConnection::OpenRequest](#openrequest) para obter uma descrição *dwFlags* valores.

### <a name="remarks"></a>Comentários

Você nunca criará um `CHttpConnection` diretamente. Em vez disso, você cria um objeto chamando [CInternetSession::GetHttpConnection](../../mfc/reference/cinternetsession-class.md#gethttpconnection).

##  <a name="openrequest"></a>  CHttpConnection::OpenRequest

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

### <a name="parameters"></a>Parâmetros

*pstrVerb*<br/>
Um ponteiro para uma cadeia de caracteres que contém o verbo a ser usado na solicitação. Se for NULL, "GET" é usado.

*pstrObjectName*<br/>
Um ponteiro para uma cadeia de caracteres que contém o objeto de destino do verbo especificado. Geralmente, essa cadeia de caracteres é um nome de arquivo, um módulo executável ou um especificador de pesquisa.

*pstrReferer*<br/>
Um ponteiro para uma cadeia de caracteres que especifica o endereço (URL) do documento do qual a URL na solicitação (*pstrObjectName*) foi obtido. Se for NULL, nenhum cabeçalho HTTP é especificado.

*dwContext*<br/>
O identificador de contexto para o `OpenRequest` operação. Para obter mais informações sobre *dwContext*, consulte a seção comentários.

*ppstrAcceptTypes*<br/>
Um ponteiro para uma matriz terminada em nulo de ponteiros LPCTSTR para cadeias de caracteres que indica os tipos de conteúdo aceitos pelo cliente. Se *ppstrAcceptTypes* for NULL, os servidores de interpretam o que o cliente só aceita documentos do tipo "texto / *" (ou seja, documentos de texto única e não imagens ou outros arquivos binários). O tipo de conteúdo é equivalente de CONTENT_TYPE variável CGI, que identifica o tipo de dados para consultas que anexou informações, como HTTP POST e PUT.

*pstrVersion*<br/>
Um ponteiro para uma cadeia de caracteres que define a versão do HTTP. Se for NULL, "HTTP 1.0" é usado.

*dwFlags*<br/>
Qualquer combinação dos sinalizadores de Internet _ Flag _ *. Consulte a seção comentários para obter uma descrição de possíveis *dwFlags* valores.

*nVerb*<br/>
Um número associado ao tipo de solicitação HTTP. Pode ser uma das seguintes opções:

|Tipo de solicitação HTTP|*nVerb* value|
|-----------------------|-------------------|
|HTTP_VERB_POST|0|
|HTTP_VERB_GET|1|
|HTTP_VERB_HEAD|2|
|HTTP_VERB_PUT|3|
|HTTP_VERB_LINK|4|
|HTTP_VERB_DELETE|5|
|HTTP_VERB_UNLINK|6|

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o [CHttpFile](../../mfc/reference/chttpfile-class.md) objeto solicitado.

### <a name="remarks"></a>Comentários

*dwFlags* pode ser uma das seguintes opções:

|Sinalizador de Internet|Descrição|
|-------------------|-----------------|
|INTERNET_FLAG_RELOAD|Força um download do arquivo solicitado, do objeto ou da listagem de diretório do servidor de origem, não do cache.|
|INTERNET_FLAG_DONT_CACHE|Não adiciona a entidade retornada para o cache.|
|INTERNET_FLAG_MAKE_PERSISTENT|Adiciona a entidade retornada para o cache como uma entidade persistente. Isso significa que a limpeza de cache padrão, a verificação de consistência ou coleta de lixo não é possível remover este item do cache.|
|INTERNET_FLAG_SECURE|Usa semântica de transação segura. Ela é convertida no uso de SSL/PCT e só é significativa em solicitações HTTP|
|INTERNET_FLAG_NO_AUTO_REDIRECT|Usado somente com HTTP, especifica que redirecionamentos não devem ser tratados automaticamente no [CHttpFile::SendRequest](../../mfc/reference/chttpfile-class.md#sendrequest).|

Substituir o `dwContext` padrão para definir o identificador de contexto para um valor de sua escolha. O identificador de contexto está associado com esta operação específica do `CHttpConnection` objeto criado pelo seu [CInternetSession](../../mfc/reference/cinternetsession-class.md) objeto. O valor é retornado a [CInternetSession::OnStatusCallback](../../mfc/reference/cinternetsession-class.md#onstatuscallback) para fornecer o status sobre a operação com a qual ela é identificada. Consulte o artigo [Internet primeiras etapas: O WinInet](../../mfc/wininet-basics.md) para obter mais informações sobre o identificador de contexto.

Exceções podem ser geradas com essa função.

## <a name="see-also"></a>Consulte também

[Classe CInternetConnection](../../mfc/reference/cinternetconnection-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CInternetConnection](../../mfc/reference/cinternetconnection-class.md)<br/>
[Classe CHttpFile](../../mfc/reference/chttpfile-class.md)
