---
title: Classe CHttpFile
ms.date: 11/04/2016
f1_keywords:
- CHttpFile
- AFXINET/CHttpFile
- AFXINET/CHttpFile::CHttpFile
- AFXINET/CHttpFile::AddRequestHeaders
- AFXINET/CHttpFile::EndRequest
- AFXINET/CHttpFile::GetFileURL
- AFXINET/CHttpFile::GetObject
- AFXINET/CHttpFile::GetVerb
- AFXINET/CHttpFile::QueryInfo
- AFXINET/CHttpFile::QueryInfoStatusCode
- AFXINET/CHttpFile::SendRequest
- AFXINET/CHttpFile::SendRequestEx
helpviewer_keywords:
- CHttpFile [MFC], CHttpFile
- CHttpFile [MFC], AddRequestHeaders
- CHttpFile [MFC], EndRequest
- CHttpFile [MFC], GetFileURL
- CHttpFile [MFC], GetObject
- CHttpFile [MFC], GetVerb
- CHttpFile [MFC], QueryInfo
- CHttpFile [MFC], QueryInfoStatusCode
- CHttpFile [MFC], SendRequest
- CHttpFile [MFC], SendRequestEx
ms.assetid: 399e7c68-bbce-4374-8c55-206e9c7baac6
ms.openlocfilehash: 3c701f933d622adc5f3d8b1eb2371406e5b45e6f
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62345793"
---
# <a name="chttpfile-class"></a>Classe CHttpFile

Fornece a funcionalidade para solicitar e ler arquivos em um servidor HTTP.

## <a name="syntax"></a>Sintaxe

```
class CHttpFile : public CInternetFile
```

## <a name="members"></a>Membros

### <a name="protected-constructors"></a>Construtores Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CHttpFile::CHttpFile](#chttpfile)|Cria um objeto `CHttpFile`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CHttpFile::AddRequestHeaders](#addrequestheaders)|Adiciona cabeçalhos à solicitação enviada a um servidor HTTP.|
|[CHttpFile::EndRequest](#endrequest)|Encerra uma solicitação enviada a um servidor HTTP com o [SendRequestEx](#sendrequestex) função de membro.|
|[CHttpFile::GetFileURL](#getfileurl)|Obtém a URL para o arquivo especificado.|
|[CHttpFile::GetObject](#getobject)|Obtém o objeto de destino do verbo em uma solicitação para um servidor HTTP.|
|[CHttpFile::GetVerb](#getverb)|Obtém o verbo que foi usado em uma solicitação para um servidor HTTP.|
|[CHttpFile::QueryInfo](#queryinfo)|Retorna os cabeçalhos de solicitação ou resposta do servidor HTTP.|
|[CHttpFile::QueryInfoStatusCode](#queryinfostatuscode)|Recupera o código de status associado a uma solicitação HTTP e o coloca na fornecido `dwStatusCode` parâmetro.|
|[CHttpFile::SendRequest](#sendrequest)|Envia uma solicitação para um servidor HTTP.|
|[CHttpFile::SendRequestEx](#sendrequestex)|Envia uma solicitação para um servidor HTTP usando o [escrever](../../mfc/reference/cinternetfile-class.md#write) ou [WriteString](../../mfc/reference/cinternetfile-class.md#writestring) métodos de `CInternetFile`.|

## <a name="remarks"></a>Comentários

Se sua sessão de Internet lê dados de um servidor HTTP, você deve criar uma instância de `CHttpFile`.

Para saber mais sobre como `CHttpFile` funciona com as outras classes de Internet do MFC, consulte o artigo [Internet Programando com WinInet](../../mfc/win32-internet-extensions-wininet.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CFile](../../mfc/reference/cfile-class.md)

[CStdioFile](../../mfc/reference/cstdiofile-class.md)

[CInternetFile](../../mfc/reference/cinternetfile-class.md)

`CHttpFile`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxinet.h

##  <a name="addrequestheaders"></a>  CHttpFile::AddRequestHeaders

Chame essa função de membro para adicionar um ou mais cabeçalhos de solicitação HTTP para a solicitação HTTP manipular.

```
BOOL AddRequestHeaders(
    LPCTSTR pstrHeaders,
    DWORD dwFlags = HTTP_ADDREQ_FLAG_ADD_IF_NEW,
    int dwHeadersLen = -1);

BOOL AddRequestHeaders(
    CString& str,
    DWORD dwFlags = HTTP_ADDREQ_FLAG_ADD_IF_NEW);
```

### <a name="parameters"></a>Parâmetros

*pstrHeaders*<br/>
Um ponteiro para uma cadeia de caracteres que contém o cabeçalho ou os cabeçalhos para acrescentar à solicitação. Cada cabeçalho deve ser terminado por um par de CR/LF.

*dwFlags*<br/>
Modifica a semântica dos cabeçalhos de novo. Pode ser uma das seguintes opções:

- Cabeçalhos HTTP_ADDREQ_FLAG_COALESCE mescla o mesmo nome, usando o sinalizador para adicionar o primeiro cabeçalho encontrado para o cabeçalho subsequente. Por exemplo, "Accept: texto /\*" seguido por "Accept: áudio /\*" resulta na formação de um único cabeçalho "Accept: texto /\*, áudio /\*". É até o aplicativo de chamada para garantir que um esquema coeso em relação aos dados recebidos por solicitações enviadas com cabeçalhos conciliados ou separados.

- HTTP_ADDREQ_FLAG_REPLACE executa uma remover e adicionar para substituir o cabeçalho atual. O nome do cabeçalho será usado para remover o cabeçalho atual e o valor completo será usado para adicionar o novo cabeçalho. Se o valor do cabeçalho está vazio e o cabeçalho for encontrado, ele será removido. Se não estiver vazio, o valor do cabeçalho é substituído.

- HTTP_ADDREQ_FLAG_ADD_IF_NEW apenas adiciona o cabeçalho se ele ainda não existir. Se houver um, um erro será retornado.

- HTTP_ADDREQ_FLAG_ADD usado com substituição. Adiciona o cabeçalho se ele não existir.

*dwHeadersLen*<br/>
O comprimento, em caracteres, de *pstrHeaders*. Quando se trata de L-1, em seguida *pstrHeaders* deve para ser terminada em zero e o tamanho é calculado.

*str*<br/>
Uma referência a um [CString](../../atl-mfc-shared/reference/cstringt-class.md) objeto que contém o cabeçalho de solicitação ou cabeçalhos a serem adicionados.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0. Se a chamada falhar, a função Win32 [GetLastError](https://msdn.microsoft.com/library/windows/desktop/ms679360) pode ser chamado para determinar a causa do erro.

### <a name="remarks"></a>Comentários

`AddRequestHeaders` acrescenta os cabeçalhos adicionais de formato livre para o identificador da solicitação HTTP. Ele destina para uso por clientes sofisticados que precisam de controle detalhado sobre a solicitação exata enviado para o servidor HTTP.

> [!NOTE]
>  O aplicativo pode passar vários cabeçalhos na *pstrHeaders* ou *str* para um `AddRequestHeaders` chamar usando HTTP_ADDREQ_FLAG_ADD ou HTTP_ADDREQ_FLAG_ADD_IF_NEW. Se o aplicativo tenta remover ou substituir um cabeçalho usando HTTP_ADDREQ_FLAG_REMOVE ou HTTP_ADDREQ_FLAG_REPLACE, apenas um cabeçalho pode ser fornecido em *lpszHeaders*.

##  <a name="chttpfile"></a>  CHttpFile::CHttpFile

Essa função membro é chamada para construir um `CHttpFile` objeto.

```
CHttpFile(
    HINTERNET hFile,
    HINTERNET hSession,
    LPCTSTR pstrObject,
    LPCTSTR pstrServer,
    LPCTSTR pstrVerb,
    DWORD_PTR dwContext);

CHttpFile(
    HINTERNET hFile,
    LPCTSTR pstrVerb,
    LPCTSTR pstrObject,
    CHttpConnection* pConnection);
```

### <a name="parameters"></a>Parâmetros

*hFile*<br/>
Um identificador para um arquivo da Internet.

*hSession*<br/>
Um identificador para uma sessão da Internet.

*pstrObject*<br/>
Um ponteiro para uma cadeia de caracteres que contém o `CHttpFile` objeto.

*pstrServer*<br/>
Um ponteiro para uma cadeia de caracteres que contém o nome do servidor.

*pstrVerb*<br/>
Um ponteiro para uma cadeia de caracteres que contém o método a ser usado ao enviar a solicitação. Pode ser o POST, HEAD, ou obter.

*dwContext*<br/>
O identificador de contexto para o `CHttpFile` objeto. Ver **comentários** para obter mais informações sobre esse parâmetro.

*pConnection*<br/>
Um ponteiro para um [CHttpConnection](../../mfc/reference/chttpconnection-class.md) objeto.

### <a name="remarks"></a>Comentários

Você nunca construir uma `CHttpFile` objeto diretamente; em vez disso, chame [CInternetSession::OpenURL](../../mfc/reference/cinternetsession-class.md#openurl) ou [CHttpConnection::OpenRequest](../../mfc/reference/chttpconnection-class.md#openrequest) em vez disso.

O valor padrão para `dwContext` é enviado pelo MFC para o `CHttpFile` objeto o [CInternetSession](../../mfc/reference/cinternetsession-class.md) do objeto que criou o `CHttpFile` objeto. Quando você chama `CInternetSession::OpenURL` ou `CHttpConnection` para construir um `CHttpFile` do objeto, você pode substituir o padrão para definir o identificador de contexto para um valor de sua escolha. O identificador de contexto é retornado ao [CInternetSession::OnStatusCallback](../../mfc/reference/cinternetsession-class.md#onstatuscallback) para fornecer status no objeto com a qual ela é identificada. Consulte o artigo [Internet primeiras etapas: O WinInet](../../mfc/wininet-basics.md) para obter mais informações sobre o identificador de contexto.

##  <a name="endrequest"></a>  CHttpFile::EndRequest

Chame essa função de membro para encerrar uma solicitação enviada a um servidor HTTP com o [SendRequestEx](#sendrequestex) função de membro.

```
BOOL EndRequest(
    DWORD dwFlags = 0,
    LPINTERNET_BUFFERS lpBuffIn = NULL,
    DWORD_PTR dwContext = 1);
```

### <a name="parameters"></a>Parâmetros

*dwFlags*<br/>
Sinalizadores que descrevem a operação. Para obter uma lista dos sinalizadores apropriados, consulte [HttpEndRequest](/windows/desktop/api/wininet/nf-wininet-httpendrequesta) no SDK do Windows.

*lpBuffIn*<br/>
Ponteiro para uma inicializado [INTERNET_BUFFERS](/windows/desktop/api/wininet/ns-wininet-_internet_buffersa) que descreve o buffer de entrada usado para a operação.

*dwContext*<br/>
O identificador de contexto para o `CHttpFile` operação. Consulte os comentários para obter mais informações sobre esse parâmetro.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0. Se a chamada falhar, determinar a causa da falha, examinando o lançada [CInternetException](../../mfc/reference/cinternetexception-class.md) objeto.

### <a name="remarks"></a>Comentários

O valor padrão para *dwContext* é enviado pelo MFC para o `CHttpFile` objeto o [CInternetSession](../../mfc/reference/cinternetsession-class.md) do objeto que criou o `CHttpFile` objeto. Quando você chama [CInternetSession::OpenURL](../../mfc/reference/cinternetsession-class.md#openurl) ou [CHttpConnection](../../mfc/reference/chttpconnection-class.md) para construir um `CHttpFile` do objeto, você pode substituir o padrão para definir o identificador de contexto para um valor de sua escolha. O identificador de contexto é retornado ao [CInternetSession::OnStatusCallback](../../mfc/reference/cinternetsession-class.md#onstatuscallback) para fornecer status no objeto com a qual ela é identificada. Consulte o artigo [Internet primeiras etapas: O WinInet](../../mfc/wininet-basics.md) para obter mais informações sobre o identificador de contexto.

##  <a name="getfileurl"></a>  CHttpFile::GetFileURL

Chame essa função de membro para obter o nome do arquivo como uma URL HTTP.

```
virtual CString GetFileURL() const;
```

### <a name="return-value"></a>Valor de retorno

Um [CString](../../atl-mfc-shared/reference/cstringt-class.md) objeto que contém uma URL referenciando o recurso associado a esse arquivo.

### <a name="remarks"></a>Comentários

Use essa função membro somente após uma chamada bem-sucedida para [SendRequest](#sendrequest) ou em um `CHttpFile` objeto criado com êxito pelo [OpenURL](../../mfc/reference/cinternetsession-class.md#openurl).

##  <a name="getobject"></a>  CHttpFile::GetObject

Chame essa função de membro para obter o nome do objeto associado a este `CHttpFile`.

```
CString GetObject() const;
```

### <a name="return-value"></a>Valor de retorno

Um [CString](../../atl-mfc-shared/reference/cstringt-class.md) objeto que contém o nome do objeto.

### <a name="remarks"></a>Comentários

Use essa função membro somente após uma chamada bem-sucedida para [SendRequest](#sendrequest) ou em um `CHttpFile` objeto criado com êxito pelo [OpenURL](../../mfc/reference/cinternetsession-class.md#openurl).

##  <a name="getverb"></a>  CHttpFile::GetVerb

Chame essa função de membro para obter o HTTP verbo (ou método) associado a este `CHttpFile`.

```
CString GetVerb() const;
```

### <a name="return-value"></a>Valor de retorno

Um [CString](../../atl-mfc-shared/reference/cstringt-class.md) objeto que contém o nome do verbo HTTP (ou método).

### <a name="remarks"></a>Comentários

Use essa função membro somente após uma chamada bem-sucedida para [SendRequest](#sendrequest) ou em um `CHttpFile` objeto criado com êxito pelo [OpenURL](../../mfc/reference/cinternetsession-class.md#openurl).

##  <a name="queryinfo"></a>  CHttpFile::QueryInfo

Chame essa função de membro para retornar a resposta ou cabeçalhos de solicitação de uma solicitação HTTP.

```
BOOL QueryInfo(
    DWORD dwInfoLevel,
    LPVOID lpvBuffer,
    LPDWORD lpdwBufferLength,
    LPDWORD lpdwIndex = NULL) const;

BOOL QueryInfo(
    DWORD dwInfoLevel,
    CString& str,
    LPDWORD dwIndex = NULL) const;

BOOL QueryInfo(
    DWORD dwInfoLevel,
    SYSTEMTIME* pSysTime,
    LPDWORD dwIndex = NULL) const;
```

### <a name="parameters"></a>Parâmetros

*dwInfoLevel*<br/>
Uma combinação do atributo para consultar e os seguintes sinalizadores que especificam o tipo de informação solicitada:

- HTTP_QUERY_CUSTOM localiza o nome do cabeçalho e retorna esse valor em *lpvBuffer* na saída. HTTP_QUERY_CUSTOM gera uma asserção se o cabeçalho não for encontrado.

- HTTP_QUERY_FLAG_REQUEST_HEADERS normalmente, o aplicativo consulta os cabeçalhos de resposta, mas um aplicativo também pode consultar cabeçalhos de solicitação usando esse sinalizador.

- HTTP_QUERY_FLAG_SYSTEMTIME para os cabeçalhos cujo valor é uma cadeia de caracteres de data/hora, como "Last-Modified-Time," esse sinalizador retorna o valor do cabeçalho como um padrão do Win32 [SYSTEMTIME](/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) estrutura que não exige que o aplicativo Analise os dados. Se você usar esse sinalizador, você talvez queira usar o `SYSTEMTIME` substituir da função.

- HTTP_QUERY_FLAG_NUMBER para os cabeçalhos cujo valor é um número, como o código de status, esse sinalizador retorna os dados como um número de 32 bits.

Consulte a **comentários** seção para obter uma lista dos possíveis valores.

*lpvBuffer*<br/>
Um ponteiro para o buffer que recebe as informações.

*lpdwBufferLength*<br/>
Na entrada, isso aponta para um valor que contém o comprimento do buffer de dados, no número de caracteres ou bytes. Consulte a **comentários** seção para obter mais informações sobre esse parâmetro.

*lpdwIndex*<br/>
Um ponteiro para um índice baseado em zero do cabeçalho. Pode ser NULL. Use esse sinalizador para enumerar os vários cabeçalhos com o mesmo nome. Na entrada, *lpdwIndex* indica o índice do cabeçalho especificado para retornar. Na saída, *lpdwIndex* indica o índice do próximo cabeçalho. Se o próximo índice não for encontrado, ERROR_HTTP_HEADER_NOT_FOUND será retornado.

*str*<br/>
Uma referência para o [CString](../../atl-mfc-shared/reference/cstringt-class.md) receber as informações retornadas do objeto.

*dwIndex*<br/>
Um valor de índice. Ver *lpdwIndex*.

*pSysTime*<br/>
Um ponteiro para um Win32 [SYSTEMTIME](/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) estrutura.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0. Se a chamada falhar, a função Win32 [GetLastError](https://msdn.microsoft.com/library/windows/desktop/ms679360) pode ser chamado para determinar a causa do erro.

### <a name="remarks"></a>Comentários

Use essa função membro somente após uma chamada bem-sucedida para [SendRequest](#sendrequest) ou em um `CHttpFile` objeto criado com êxito pelo [OpenURL](../../mfc/reference/cinternetsession-class.md#openurl).

Você pode recuperar os seguintes tipos de dados de `QueryInfo`:

- cadeias de caracteres (padrão)

- `SYSTEMTIME` (para "dados:" "Expires:" cabeçalhos etc,)

- DWORD (para STATUS_CODE CONTENT_LENGTH, etc.)

Quando uma cadeia de caracteres é gravada no buffer e a função de membro for bem-sucedida, `lpdwBufferLength` contém o comprimento da cadeia de caracteres em caracteres menos 1 para o caractere nulo de terminação.

Os possíveis *dwInfoLevel* valores incluem:

- HTTP_QUERY_MIME_VERSION

- HTTP_QUERY_CONTENT_TYPE

- HTTP_QUERY_CONTENT_TRANSFER_ENCODING

- HTTP_QUERY_CONTENT_ID

- HTTP_QUERY_CONTENT_DESCRIPTION

- HTTP_QUERY_CONTENT_LENGTH

- HTTP_QUERY_ALLOWED_METHODS

- HTTP_QUERY_PUBLIC_METHODS

- HTTP_QUERY_DATE

- HTTP_QUERY_EXPIRES

- HTTP_QUERY_LAST_MODIFIED

- HTTP_QUERY_MESSAGE_ID

- HTTP_QUERY_URI

- HTTP_QUERY_DERIVED_FROM

- HTTP_QUERY_LANGUAGE

- HTTP_QUERY_COST

- HTTP_QUERY_WWW_LINK

- HTTP_QUERY_PRAGMA

- HTTP_QUERY_VERSION

- HTTP_QUERY_STATUS_CODE

- HTTP_QUERY_STATUS_TEXT

- HTTP_QUERY_RAW_HEADERS

- HTTP_QUERY_RAW_HEADERS_CRLF

##  <a name="queryinfostatuscode"></a>  CHttpFile::QueryInfoStatusCode

Chame essa função de membro para obter o código de status associado a uma solicitação HTTP e colocá-lo em fornecido *dwStatusCode* parâmetro.

```
BOOL QueryInfoStatusCode(DWORD& dwStatusCode) const;
```

### <a name="parameters"></a>Parâmetros

*dwStatusCode*<br/>
Uma referência a um código de status. Códigos de status indicam o êxito ou falha do evento solicitado. Ver **comentários** para uma seleção das descrições de código de status.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0. Se a chamada falhar, a função Win32 [GetLastError](https://msdn.microsoft.com/library/windows/desktop/ms679360) pode ser chamado para determinar a causa do erro.

### <a name="remarks"></a>Comentários

Use essa função membro somente após uma chamada bem-sucedida para [SendRequest](#sendrequest) ou em um `CHttpFile` objeto criado com êxito pelo [OpenURL](../../mfc/reference/cinternetsession-class.md#openurl).

Códigos de status HTTP se enquadram em grupos que indica o êxito ou falha da solicitação. As tabelas a seguir descrevem os grupos de códigos de status e códigos de status HTTP mais comuns.

|Grupo|Significado|
|-----------|-------------|
|200-299|Êxito|
|300-399|Informações|
|400-499|Erro de solicitação|
|500-599|Erro de servidor|

Códigos de Status HTTP comuns:

|Código de status|Significado|
|-----------------|-------------|
|200|URL localizada, da seguinte maneira de transmissão|
|400|Solicitação ininteligível|
|404|Solicitou a URL não encontrado|
|405|Servidor não suporta o método solicitado|
|500|Erro de servidor desconhecido|
|503|Alcançada a capacidade do servidor|

##  <a name="sendrequest"></a>  CHttpFile::SendRequest

Chame essa função de membro para enviar uma solicitação para um servidor HTTP.

```
BOOL SendRequest(
    LPCTSTR pstrHeaders = NULL,
    DWORD dwHeadersLen = 0,
    LPVOID lpOptional = NULL,
    DWORD dwOptionalLen = 0);

BOOL SendRequest(
    CString& strHeaders,
    LPVOID lpOptional = NULL,
    DWORD dwOptionalLen = 0);
```

### <a name="parameters"></a>Parâmetros

*pstrHeaders*<br/>
Um ponteiro para uma cadeia de caracteres que contém o nome de cabeçalhos a enviar.

*dwHeadersLen*<br/>
O comprimento dos cabeçalhos identificado pelo *pstrHeaders*.

*lpOptional*<br/>
Dados opcionais para enviar imediatamente após os cabeçalhos de solicitação. Isso geralmente é usado para operações POST e PUT. Isso pode ser NULL se não houver nenhum dado opcional para enviar.

*dwOptionalLen*<br/>
O comprimento da *lpOptional*.

*strHeaders*<br/>
Uma cadeia de caracteres que contém o nome dos cabeçalhos da solicitação que está sendo enviada.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0. Se a chamada falhar, determinar a causa da falha, examinando o lançada [CInternetException](../../mfc/reference/cinternetexception-class.md) objeto.

##  <a name="sendrequestex"></a>  CHttpFile::SendRequestEx

Chame essa função de membro para enviar uma solicitação para um servidor HTTP.

```
BOOL SendRequestEx(
    DWORD dwTotalLen,
    DWORD dwFlags = HSR_INITIATE,
    DWORD_PTR dwContext = 1);

BOOL SendRequestEx(
    LPINTERNET_BUFFERS lpBuffIn,
    LPINTERNET_BUFFERS lpBuffOut,
    DWORD dwFlags = HSR_INITIATE,
    DWORD_PTR dwContext = 1);
```

### <a name="parameters"></a>Parâmetros

*dwTotalLen*<br/>
Número de bytes a serem enviados na solicitação.

*dwFlags*<br/>
Sinalizadores que descrevem a operação. Para obter uma lista dos sinalizadores apropriados, consulte [HttpSendRequestEx](/windows/desktop/api/wininet/nf-wininet-httpsendrequestexa) no SDK do Windows.

*dwContext*<br/>
O identificador de contexto para o `CHttpFile` operação. Consulte os comentários para obter mais informações sobre esse parâmetro.

*lpBuffIn*<br/>
Ponteiro para uma inicializado [INTERNET_BUFFERS](/windows/desktop/api/wininet/ns-wininet-_internet_buffersa) que descreve o buffer de entrada usado para a operação.

*lpBuffOut*<br/>
Ponteiro para um INTERNET_BUFFERS inicializado que descreve o buffer de saída usado para a operação.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se for bem-sucedido. Se a chamada falhar, determinar a causa da falha, examinando o lançada [CInternetException](../../mfc/reference/cinternetexception-class.md) objeto.

### <a name="remarks"></a>Comentários

Essa função permite que seu aplicativo para enviar dados usando o [escrever](../../mfc/reference/cinternetfile-class.md#write) e [WriteString](../../mfc/reference/cinternetfile-class.md#writestring) métodos de `CInternetFile`. Você deve saber o comprimento dos dados serem enviados antes de chamar qualquer substituição dessa função. A primeira substituição permite que você especifique o comprimento dos dados que você deseja enviar. A segunda substituição aceita ponteiros para estruturas INTERNET_BUFFERS, que podem ser usados para descrever o buffer em detalhes.

Depois que o conteúdo é gravado no arquivo, chame [EndRequest](#endrequest) para encerrar a operação.

O valor padrão para *dwContext* é enviado pelo MFC para o `CHttpFile` objeto o [CInternetSession](../../mfc/reference/cinternetsession-class.md) do objeto que criou o `CHttpFile` objeto. Quando você chama [CInternetSession::OpenURL](../../mfc/reference/cinternetsession-class.md#openurl) ou [CHttpConnection](../../mfc/reference/chttpconnection-class.md) para construir um `CHttpFile` do objeto, você pode substituir o padrão para definir o identificador de contexto para um valor de sua escolha. O identificador de contexto é retornado ao [CInternetSession::OnStatusCallback](../../mfc/reference/cinternetsession-class.md#onstatuscallback) para fornecer status no objeto com a qual ela é identificada. Consulte o artigo [Internet primeiras etapas: O WinInet](../../mfc/wininet-basics.md) para obter mais informações sobre o identificador de contexto.

### <a name="example"></a>Exemplo

Este fragmento de código envia o conteúdo de uma cadeia de caracteres para uma DLL denominada MFCISAPI. DLL no servidor de LOCALHOST. Embora este exemplo usa apenas uma chamada para `WriteString`, usando várias chamadas para enviar dados em blocos é aceitável.

[!code-cpp[NVC_MFCWinInet#9](../../mfc/codesnippet/cpp/chttpfile-class_1.cpp)]

## <a name="see-also"></a>Consulte também

[Classe CInternetFile](../../mfc/reference/cinternetfile-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CInternetFile](../../mfc/reference/cinternetfile-class.md)<br/>
[Classe CGopherFile](../../mfc/reference/cgopherfile-class.md)<br/>
[Classe CHttpConnection](../../mfc/reference/chttpconnection-class.md)
