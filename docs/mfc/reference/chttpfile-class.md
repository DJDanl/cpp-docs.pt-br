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
ms.openlocfilehash: 0c8c401b43361a5e1472e3470f5ea452c91b957f
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69505957"
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
|[CHttpFile::EndRequest](#endrequest)|Encerra uma solicitação enviada a um servidor HTTP com a função de membro [SendRequestEx](#sendrequestex) .|
|[CHttpFile::GetFileURL](#getfileurl)|Obtém a URL para o arquivo especificado.|
|[CHttpFile::GetObject](#getobject)|Obtém o objeto de destino do verbo em uma solicitação para um servidor HTTP.|
|[CHttpFile::GetVerb](#getverb)|Obtém o verbo que foi usado em uma solicitação para um servidor HTTP.|
|[CHttpFile::QueryInfo](#queryinfo)|Retorna os cabeçalhos de resposta ou de solicitação do servidor HTTP.|
|[CHttpFile::QueryInfoStatusCode](#queryinfostatuscode)|Recupera o código de status associado a uma solicitação HTTP e o coloca no parâmetro `dwStatusCode` fornecido.|
|[CHttpFile::SendRequest](#sendrequest)|Envia uma solicitação para um servidor HTTP.|
|[CHttpFile::SendRequestEx](#sendrequestex)|Envia uma solicitação para um servidor HTTP usando os métodos [Write](../../mfc/reference/cinternetfile-class.md#write) ou [WriteString](../../mfc/reference/cinternetfile-class.md#writestring) de `CInternetFile`.|

## <a name="remarks"></a>Comentários

Se a sua sessão de Internet ler dados de um servidor HTTP, você deverá criar uma `CHttpFile`instância do.

Para saber mais sobre como `CHttpFile` o funciona com as outras classes de Internet do MFC, confira o artigo [programação da Internet com WinInet](../../mfc/win32-internet-extensions-wininet.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CFile](../../mfc/reference/cfile-class.md)

[CStdioFile](../../mfc/reference/cstdiofile-class.md)

[CInternetFile](../../mfc/reference/cinternetfile-class.md)

`CHttpFile`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXINET. h

##  <a name="addrequestheaders"></a>  CHttpFile::AddRequestHeaders

Chame essa função de membro para adicionar um ou mais cabeçalhos de solicitação HTTP ao identificador de solicitação HTTP.

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
Um ponteiro para uma cadeia de caracteres que contém o cabeçalho ou cabeçalhos a serem acrescentados à solicitação. Cada cabeçalho deve ser terminado por um par CR/LF.

*dwFlags*<br/>
Modifica a semântica dos novos cabeçalhos. Pode ser um dos seguintes:

- HTTP_ADDREQ_FLAG_COALESCE mescla os cabeçalhos de mesmo nome, usando o sinalizador para adicionar o primeiro cabeçalho encontrado ao cabeçalho subsequente. Por exemplo, "Accept: Text/\*" seguido de "Accept: áudio/\*" resulta na formação do único cabeçalho "Accept: Text/\*, Audio/\*". Cabe ao aplicativo de chamada garantir um esquema coeso em relação aos dados recebidos por solicitações enviadas com cabeçalhos agrupados ou separados.

- HTTP_ADDREQ_FLAG_REPLACE Executa uma remoção e adição para substituir o cabeçalho atual. O nome do cabeçalho será usado para remover o cabeçalho atual e o valor completo será usado para adicionar o novo cabeçalho. Se o cabeçalho-valor estiver vazio e o cabeçalho for encontrado, ele será removido. Se não estiver vazio, o cabeçalho-Value será substituído.

- HTTP_ADDREQ_FLAG_ADD_IF_NEW só adicionará o cabeçalho se ele ainda não existir. Se houver um, um erro será retornado.

- HTTP_ADDREQ_FLAG_ADD usado com REPLACE. Adiciona o cabeçalho se ele não existir.

*dwHeadersLen*<br/>
O comprimento, em caracteres, de *pstrHeaders*. Se for-1L, *pstrHeaders* será considerado como terminação zero e o comprimento será computado.

*str*<br/>
Uma referência a um objeto [CString](../../atl-mfc-shared/reference/cstringt-class.md) que contém o cabeçalho da solicitação ou os cabeçalhos a serem adicionados.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0. Se a chamada falhar, a função do Win32 [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) poderá ser chamada para determinar a causa do erro.

### <a name="remarks"></a>Comentários

`AddRequestHeaders`acrescenta cabeçalhos de formato livre adicionais ao identificador de solicitação HTTP. Ele é destinado ao uso por clientes sofisticados que precisam de controle detalhado sobre a solicitação exata enviada ao servidor HTTP.

> [!NOTE]
>  O aplicativo pode passar vários cabeçalhos em *pstrHeaders* ou *Str* para uma `AddRequestHeaders` chamada usando HTTP_ADDREQ_FLAG_ADD ou HTTP_ADDREQ_FLAG_ADD_IF_NEW. Se o aplicativo tentar remover ou substituir um cabeçalho usando HTTP_ADDREQ_FLAG_REMOVE ou HTTP_ADDREQ_FLAG_REPLACE, somente um cabeçalho poderá ser fornecido em *lpszHeaders*.

##  <a name="chttpfile"></a>  CHttpFile::CHttpFile

Essa função de membro é chamada para construir `CHttpFile` um objeto.

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
Um ponteiro para uma cadeia de caracteres `CHttpFile` que contém o objeto.

*pstrServer*<br/>
Um ponteiro para uma cadeia de caracteres que contém o nome do servidor.

*pstrVerb*<br/>
Um ponteiro para uma cadeia de caracteres que contém o método a ser usado ao enviar a solicitação. Pode ser POST, HEAD ou GET.

*dwContext*<br/>
O identificador de contexto para `CHttpFile` o objeto. Consulte **comentários** para obter mais informações sobre esse parâmetro.

*pConnection*<br/>
Um ponteiro para um objeto [CHttpConnection](../../mfc/reference/chttpconnection-class.md) .

### <a name="remarks"></a>Comentários

Você nunca constrói um `CHttpFile` objeto diretamente; em vez disso, chame [CInternetSession:: OpenURL](../../mfc/reference/cinternetsession-class.md#openurl) ou [CHttpConnection:: OpenRequest](../../mfc/reference/chttpconnection-class.md#openrequest) .

O valor padrão para `dwContext` é enviado pelo MFC para o `CHttpFile` objeto do objeto [CInternetSession](../../mfc/reference/cinternetsession-class.md) que criou o `CHttpFile` objeto. Ao chamar `CInternetSession::OpenURL` ou `CHttpConnection` construir um `CHttpFile` objeto, você pode substituir o padrão para definir o identificador de contexto como um valor de sua escolha. O identificador de contexto é retornado para [CInternetSession:: OnStatusCallback](../../mfc/reference/cinternetsession-class.md#onstatuscallback) para fornecer o status no objeto com o qual ele é identificado. Consulte o artigo [primeiras etapas da Internet: WinInet](../../mfc/wininet-basics.md) para obter mais informações sobre o identificador de contexto.

##  <a name="endrequest"></a>  CHttpFile::EndRequest

Chame essa função de membro para encerrar uma solicitação enviada a um servidor HTTP com a função de membro [SendRequestEx](#sendrequestex) .

```
BOOL EndRequest(
    DWORD dwFlags = 0,
    LPINTERNET_BUFFERS lpBuffIn = NULL,
    DWORD_PTR dwContext = 1);
```

### <a name="parameters"></a>Parâmetros

*dwFlags*<br/>
Sinalizadores que descrevem a operação. Para obter uma lista dos sinalizadores apropriados, consulte [HttpEndRequest](/windows/win32/api/wininet/nf-wininet-httpendrequestw) no SDK do Windows.

*lpBuffIn*<br/>
Ponteiro para um [INTERNET_BUFFERS](/windows/win32/api/wininet/ns-wininet-internet_buffersw) inicializado que descreve o buffer de entrada usado para a operação.

*dwContext*<br/>
O identificador de contexto para `CHttpFile` a operação. Consulte comentários para obter mais informações sobre esse parâmetro.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0. Se a chamada falhar, determine a causa da falha examinando o objeto [CInternetException](../../mfc/reference/cinternetexception-class.md) gerado.

### <a name="remarks"></a>Comentários

O valor padrão para *dwContext* é enviado pelo MFC para o `CHttpFile` objeto do objeto [CInternetSession](../../mfc/reference/cinternetsession-class.md) que criou o `CHttpFile` objeto. Ao chamar [CInternetSession:: OpenURL](../../mfc/reference/cinternetsession-class.md#openurl) ou [CHttpConnection](../../mfc/reference/chttpconnection-class.md) para construir um `CHttpFile` objeto, você pode substituir o padrão para definir o identificador de contexto como um valor de sua escolha. O identificador de contexto é retornado para [CInternetSession:: OnStatusCallback](../../mfc/reference/cinternetsession-class.md#onstatuscallback) para fornecer o status no objeto com o qual ele é identificado. Consulte o [artigo primeiras etapas da Internet: WinInet](../../mfc/wininet-basics.md) para obter mais informações sobre o identificador de contexto.

##  <a name="getfileurl"></a>  CHttpFile::GetFileURL

Chame essa função de membro para obter o nome do arquivo HTTP como uma URL.

```
virtual CString GetFileURL() const;
```

### <a name="return-value"></a>Valor de retorno

Um objeto [CString](../../atl-mfc-shared/reference/cstringt-class.md) que contém uma URL que referencia o recurso associado a esse arquivo.

### <a name="remarks"></a>Comentários

Use essa função de membro somente após uma chamada bem-sucedida para [SendRequest](#sendrequest) ou em `CHttpFile` um objeto criado com êxito pelo [OpenURL](../../mfc/reference/cinternetsession-class.md#openurl).

##  <a name="getobject"></a>  CHttpFile::GetObject

Chame essa função de membro para obter o nome do objeto associado a isso `CHttpFile`.

```
CString GetObject() const;
```

### <a name="return-value"></a>Valor de retorno

Um objeto [CString](../../atl-mfc-shared/reference/cstringt-class.md) que contém o nome do objeto.

### <a name="remarks"></a>Comentários

Use essa função de membro somente após uma chamada bem-sucedida para [SendRequest](#sendrequest) ou em `CHttpFile` um objeto criado com êxito pelo [OpenURL](../../mfc/reference/cinternetsession-class.md#openurl).

##  <a name="getverb"></a>  CHttpFile::GetVerb

Chame essa função de membro para obter o verbo HTTP (ou o método) associado `CHttpFile`a isso.

```
CString GetVerb() const;
```

### <a name="return-value"></a>Valor de retorno

Um objeto [CString](../../atl-mfc-shared/reference/cstringt-class.md) que contém o nome do verbo http (ou método).

### <a name="remarks"></a>Comentários

Use essa função de membro somente após uma chamada bem-sucedida para [SendRequest](#sendrequest) ou em `CHttpFile` um objeto criado com êxito pelo [OpenURL](../../mfc/reference/cinternetsession-class.md#openurl).

##  <a name="queryinfo"></a>  CHttpFile::QueryInfo

Chame essa função de membro para retornar cabeçalhos de resposta ou de solicitação de uma solicitação HTTP.

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
Uma combinação do atributo a ser consultada e os seguintes sinalizadores que especificam o tipo de informação solicitada:

- HTTP_QUERY_CUSTOM Localiza o nome do cabeçalho e retorna esse valor em *lpvBuffer* na saída. HTTP_QUERY_CUSTOM gera uma asserção se o cabeçalho não for encontrado.

- HTTP_QUERY_FLAG_REQUEST_HEADERS normalmente, o aplicativo consulta os cabeçalhos de resposta, mas um aplicativo também pode consultar cabeçalhos de solicitação usando esse sinalizador.

- HTTP_QUERY_FLAG_SYSTEMTIME para os cabeçalhos cujo valor é uma cadeia de caracteres de data/hora, como "Last-Modified-Time", esse sinalizador retorna o valor do cabeçalho como uma estrutura padrão do Win32 [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) que não exige que o aplicativo analise os dados. Se você usar esse sinalizador, talvez queira usar a `SYSTEMTIME` substituição da função.

- HTTP_QUERY_FLAG_NUMBER para os cabeçalhos cujo valor é um número, como o código de status, esse sinalizador retorna os dados como um número de 32 bits.

Consulte a seção **comentários** para obter uma lista dos valores possíveis.

*lpvBuffer*<br/>
Um ponteiro para o buffer que recebe as informações.

*lpdwBufferLength*<br/>
Na entrada, isso aponta para um valor que contém o comprimento do buffer de dados, em número de caracteres ou bytes. Consulte a seção **comentários** para obter informações mais detalhadas sobre esse parâmetro.

*lpdwIndex*<br/>
Um ponteiro para um índice de cabeçalho baseado em zero. Pode ser NULL. Use este sinalizador para enumerar vários cabeçalhos com o mesmo nome. Na entrada, *lpdwIndex* indica o índice do cabeçalho especificado a ser retornado. Na saída, *lpdwIndex* indica o índice do próximo cabeçalho. Se o índice seguinte não puder ser encontrado, ERROR_HTTP_HEADER_NOT_FOUND será retornado.

*str*<br/>
Uma referência ao objeto [CString](../../atl-mfc-shared/reference/cstringt-class.md) que recebe as informações retornadas.

*dwIndex*<br/>
Um valor de índice. Consulte *lpdwIndex*.

*pSysTime*<br/>
Um ponteiro para uma estrutura [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) do Win32.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0. Se a chamada falhar, a função do Win32 [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) poderá ser chamada para determinar a causa do erro.

### <a name="remarks"></a>Comentários

Use essa função de membro somente após uma chamada bem-sucedida para [SendRequest](#sendrequest) ou em `CHttpFile` um objeto criado com êxito pelo [OpenURL](../../mfc/reference/cinternetsession-class.md#openurl).

Você pode recuperar os seguintes tipos de dados de `QueryInfo`:

- cadeias de caracteres (padrão)

- `SYSTEMTIME`(para "dados:" "expira:" etc., cabeçalhos)

- DWORD (para STATUS_CODE, CONTENT_LENGTH, etc.)

Quando uma cadeia de caracteres é gravada no buffer e a função de membro é `lpdwBufferLength` bem sucedido, contém o comprimento da cadeia de caracteres, em caracters menos 1 para o caractere nulo de terminação.

Os possíveis valores de *dwInfoLevel* incluem:

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

Chame essa função de membro para obter o código de status associado a uma solicitação HTTP e colocá-lo no parâmetro *dwStatusCode* fornecido.

```
BOOL QueryInfoStatusCode(DWORD& dwStatusCode) const;
```

### <a name="parameters"></a>Parâmetros

*dwStatusCode*<br/>
Uma referência a um código de status. Os códigos de status indicam o êxito ou a falha do evento solicitado. Consulte **comentários** para obter uma seleção de descrições de código de status.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0. Se a chamada falhar, a função do Win32 [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) poderá ser chamada para determinar a causa do erro.

### <a name="remarks"></a>Comentários

Use essa função de membro somente após uma chamada bem-sucedida para [SendRequest](#sendrequest) ou em `CHttpFile` um objeto criado com êxito pelo [OpenURL](../../mfc/reference/cinternetsession-class.md#openurl).

Os códigos de status HTTP se enquadram em grupos que indicam o êxito ou a falha da solicitação. As tabelas a seguir descrevem os grupos de códigos de status e os códigos de status HTTP mais comuns.

|Grupo|Significado|
|-----------|-------------|
|200-299|Êxito|
|300-399|Informações|
|400-499|Erro de solicitação|
|500-599|Erro do servidor|

Códigos de status HTTP comuns:

|Código de status|Significado|
|-----------------|-------------|
|200|URL localizada, a transmissão segue|
|400|Solicitação ininteligível|
|404|URL solicitada não encontrada|
|405|O servidor não dá suporte ao método solicitado|
|500|Erro de servidor desconhecido|
|503|Capacidade do servidor atingida|

##  <a name="sendrequest"></a>CHttpFile:: SendRequest

Chame essa função de membro para enviar uma solicitação a um servidor HTTP.

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
Um ponteiro para uma cadeia de caracteres que contém o nome dos cabeçalhos a serem enviados.

*dwHeadersLen*<br/>
O comprimento dos cabeçalhos identificados por *pstrHeaders*.

*lpOptional*<br/>
Todos os dados opcionais a serem enviados imediatamente após os cabeçalhos de solicitação. Isso geralmente é usado para operações POST e PUT. Isso pode ser nulo se não houver dados opcionais a serem enviados.

*dwOptionalLen*<br/>
O comprimento de *lpOptional*.

*strHeaders*<br/>
Uma cadeia de caracteres que contém o nome dos cabeçalhos para a solicitação que está sendo enviada.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0. Se a chamada falhar, determine a causa da falha examinando o objeto [CInternetException](../../mfc/reference/cinternetexception-class.md) gerado.

##  <a name="sendrequestex"></a>CHttpFile::SendRequestEx

Chame essa função de membro para enviar uma solicitação a um servidor HTTP.

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
Sinalizadores que descrevem a operação. Para obter uma lista de sinalizadores apropriados, consulte [HttpSendRequestEx](/windows/win32/api/wininet/nf-wininet-httpsendrequestexw) no SDK do Windows.

*dwContext*<br/>
O identificador de contexto para `CHttpFile` a operação. Consulte comentários para obter mais informações sobre esse parâmetro.

*lpBuffIn*<br/>
Ponteiro para um [INTERNET_BUFFERS](/windows/win32/api/wininet/ns-wininet-internet_buffersw) inicializado que descreve o buffer de entrada usado para a operação.

*lpBuffOut*<br/>
Ponteiro para um INTERNET_BUFFERS inicializado que descreve o buffer de saída usado para a operação.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido. Se a chamada falhar, determine a causa da falha examinando o objeto [CInternetException](../../mfc/reference/cinternetexception-class.md) gerado.

### <a name="remarks"></a>Comentários

Essa função permite que seu aplicativo envie dados usando os métodos [Write](../../mfc/reference/cinternetfile-class.md#write) e [WriteString](../../mfc/reference/cinternetfile-class.md#writestring) do `CInternetFile`. Você deve saber o comprimento dos dados a serem enviados antes de chamar a substituição dessa função. A primeira substituição permite que você especifique o comprimento dos dados que deseja enviar. A segunda substituição aceita ponteiros para estruturas INTERNET_BUFFERS, que podem ser usadas para descrever o buffer em grande detalhe.

Depois que o conteúdo é gravado no arquivo, chame [endRequest](#endrequest) para encerrar a operação.

O valor padrão para *dwContext* é enviado pelo MFC para o `CHttpFile` objeto do objeto [CInternetSession](../../mfc/reference/cinternetsession-class.md) que criou o `CHttpFile` objeto. Ao chamar [CInternetSession:: OpenURL](../../mfc/reference/cinternetsession-class.md#openurl) ou [CHttpConnection](../../mfc/reference/chttpconnection-class.md) para construir um `CHttpFile` objeto, você pode substituir o padrão para definir o identificador de contexto como um valor de sua escolha. O identificador de contexto é retornado para [CInternetSession:: OnStatusCallback](../../mfc/reference/cinternetsession-class.md#onstatuscallback) para fornecer o status no objeto com o qual ele é identificado. Consulte o artigo [primeiras etapas da Internet: WinInet](../../mfc/wininet-basics.md) para obter mais informações sobre o identificador de contexto.

### <a name="example"></a>Exemplo

Esse fragmento de código envia o conteúdo de uma cadeia de caracteres para uma DLL chamada MFCISAPI. DLL no servidor LOCALHOST. Embora este exemplo use apenas uma chamada para `WriteString`, o uso de várias chamadas para enviar dados em blocos é aceitável.

[!code-cpp[NVC_MFCWinInet#9](../../mfc/codesnippet/cpp/chttpfile-class_1.cpp)]

## <a name="see-also"></a>Consulte também

[Classe CInternetFile](../../mfc/reference/cinternetfile-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CInternetFile](../../mfc/reference/cinternetfile-class.md)<br/>
[Classe CGopherFile](../../mfc/reference/cgopherfile-class.md)<br/>
[Classe CHttpConnection](../../mfc/reference/chttpconnection-class.md)
