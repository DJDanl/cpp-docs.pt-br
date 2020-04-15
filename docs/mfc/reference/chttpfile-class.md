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
ms.openlocfilehash: cba3ba7d86577703de2bf5709d66bbd5e0298863
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81368387"
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
|[chttpfile::ChttpFile](#chttpfile)|Cria um objeto `CHttpFile`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CHttpFile::AddRequestHeaders](#addrequestheaders)|Adiciona cabeçalhos à solicitação enviada a um servidor HTTP.|
|[chttpfile::EndRequest](#endrequest)|Termina uma solicitação enviada a um servidor HTTP com a função de membro [SendRequestEx.](#sendrequestex)|
|[chttpfile::getFileURL](#getfileurl)|Obtém a URL do arquivo especificado.|
|[chttpfile::getobject](#getobject)|Obtém o objeto-alvo do verbo em uma solicitação a um servidor HTTP.|
|[CHttpFile::GetVerb](#getverb)|Obtém o verbo que foi usado em uma solicitação a um servidor HTTP.|
|[CHttpFile::QueryInfo](#queryinfo)|Retorna os cabeçalhos de resposta ou solicitação do servidor HTTP.|
|[CHttpFile::QueryInfoStatusCode](#queryinfostatuscode)|Recupera o código de status associado a uma solicitação `dwStatusCode` HTTP e coloca-o no parâmetro fornecido.|
|[chttpfile::SendRequest](#sendrequest)|Envia uma solicitação a um servidor HTTP.|
|[chttpfile::SendRequestEx](#sendrequestex)|Envia uma solicitação a um servidor HTTP usando `CInternetFile`os métodos [Write](../../mfc/reference/cinternetfile-class.md#write) ou [WriteString](../../mfc/reference/cinternetfile-class.md#writestring) de .|

## <a name="remarks"></a>Comentários

Se a sessão da Internet ler dados de um `CHttpFile`servidor HTTP, você deve criar uma instância de .

Para saber mais `CHttpFile` sobre como funciona as outras aulas de Internet do MFC, consulte o artigo [Programação na Internet com WinInet](../../mfc/win32-internet-extensions-wininet.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cfile](../../mfc/reference/cfile-class.md)

[Cstdiofile](../../mfc/reference/cstdiofile-class.md)

[Cinternetfile](../../mfc/reference/cinternetfile-class.md)

`CHttpFile`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxinet.h

## <a name="chttpfileaddrequestheaders"></a><a name="addrequestheaders"></a>CHttpFile::AddRequestHeaders

Ligue para esta função de membro para adicionar um ou mais cabeçalhos de solicitação HTTP à alça de solicitação HTTP.

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

*Pstrheaders*<br/>
Um ponteiro para uma seqüência contendo o cabeçalho ou cabeçalhos para anexar à solicitação. Cada cabeçalho deve ser terminado por um par CR/LF.

*dwFlags*<br/>
Modifica a semântica dos novos cabeçalhos. Um dos seguintes pode ser feito:

- HTTP_ADDREQ_FLAG_COALESCE Mescla cabeçalhos de mesmo nome, usando o sinalizador para adicionar o primeiro cabeçalho encontrado ao cabeçalho subseqüente. Por exemplo, "Aceitar:\*texto/ " seguido\*de "Aceitar: áudio/ " resulta\*na formação\*do cabeçalho único "Aceitar: texto/ , áudio/ ". Cabe ao aplicativo de chamada garantir um esquema coeso em relação aos dados recebidos por solicitações enviadas com cabeçalhos coalesceus ou separados.

- HTTP_ADDREQ_FLAG_REPLACE Executa uma remoção e adicionar para substituir o cabeçalho atual. O nome do cabeçalho será usado para remover o cabeçalho atual, e o valor total será usado para adicionar o novo cabeçalho. Se o valor do cabeçalho estiver vazio e o cabeçalho for encontrado, ele será removido. Se não estiver vazio, o valor do cabeçalho será substituído.

- HTTP_ADDREQ_FLAG_ADD_IF_NEW só adiciona o cabeçalho se ele ainda não existir. Se existe um, um erro é devolvido.

- HTTP_ADDREQ_FLAG_ADD Usado com REPLACE. Adiciona o cabeçalho se ele não existir.

*dwHeadersLen*<br/>
O comprimento, em caracteres, de *pstrHeaders*. Se isso for -1L, então *pstrHeaders* é assumido como sendo zero-terminado e o comprimento é calculado.

*Str*<br/>
Uma referência a um objeto [CString](../../atl-mfc-shared/reference/cstringt-class.md) contendo o cabeçalho de solicitação ou cabeçalhos a serem adicionados.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0. Se a chamada falhar, a função Win32 [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) pode ser chamada para determinar a causa do erro.

### <a name="remarks"></a>Comentários

`AddRequestHeaders`anexa cabeçalhos adicionais de formato livre para o cabo de solicitação HTTP. Destina-se a ser usado por clientes sofisticados que precisam de controle detalhado sobre a solicitação exata enviada ao servidor HTTP.

> [!NOTE]
> O aplicativo pode passar vários cabeçalhos em `AddRequestHeaders` *pstrHeaders* ou *str* para uma chamada usando HTTP_ADDREQ_FLAG_ADD ou HTTP_ADDREQ_FLAG_ADD_IF_NEW. Se o aplicativo tentar remover ou substituir um cabeçalho usando HTTP_ADDREQ_FLAG_REMOVE ou HTTP_ADDREQ_FLAG_REPLACE, apenas um cabeçalho pode ser fornecido em *lpszHeaders*.

## <a name="chttpfilechttpfile"></a><a name="chttpfile"></a>chttpfile::ChttpFile

Esta função membro é `CHttpFile` chamada para construir um objeto.

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

*Hfile*<br/>
Uma alça para um arquivo da Internet.

*hSession*<br/>
Uma alça para uma sessão de Internet.

*pstrObject*<br/>
Um ponteiro para uma `CHttpFile` seqüência contendo o objeto.

*PstrServer*<br/>
Um ponteiro para uma seqüência contendo o nome do servidor.

*pstrVerb*<br/>
Um ponteiro para uma seqüência contendo o método a ser usado ao enviar a solicitação. Pode ser POST, HEAD ou GET.

*Dwcontext*<br/>
O identificador de `CHttpFile` contexto para o objeto. Consulte **Observações** para obter mais informações sobre este parâmetro.

*pConnection*<br/>
Um ponteiro para um objeto [CHttpConnection.](../../mfc/reference/chttpconnection-class.md)

### <a name="remarks"></a>Comentários

Você nunca `CHttpFile` constrói um objeto diretamente; em vez disso, chamar [CInternetSession::OpenURL](../../mfc/reference/cinternetsession-class.md#openurl) ou [CHttpConnection::OpenRequest](../../mfc/reference/chttpconnection-class.md#openrequest) em vez disso.

O valor `dwContext` padrão para é enviado `CHttpFile` pelo MFC para o objeto `CHttpFile` do objeto [CInternetSession](../../mfc/reference/cinternetsession-class.md) que criou o objeto. Quando você `CInternetSession::OpenURL` `CHttpConnection` liga ou `CHttpFile` constrói um objeto, você pode substituir o padrão para definir o identificador de contexto para um valor de sua escolha. O identificador de contexto é retornado ao [CInternetSession::OnStatusCallback](../../mfc/reference/cinternetsession-class.md#onstatuscallback) para fornecer status no objeto com o qual ele é identificado. Veja o artigo [Primeiros Passos da Internet: WinInet](../../mfc/wininet-basics.md) para obter mais informações sobre o identificador de contexto.

## <a name="chttpfileendrequest"></a><a name="endrequest"></a>chttpfile::EndRequest

Ligue para esta função de membro para encerrar uma solicitação enviada a um servidor HTTP com a função de membro [SendRequestEx.](#sendrequestex)

```
BOOL EndRequest(
    DWORD dwFlags = 0,
    LPINTERNET_BUFFERS lpBuffIn = NULL,
    DWORD_PTR dwContext = 1);
```

### <a name="parameters"></a>Parâmetros

*dwFlags*<br/>
Bandeiras descrevendo a operação. Para obter uma lista dos sinalizadores apropriados, consulte [HttpEndRequest](/windows/win32/api/wininet/nf-wininet-httpendrequestw) no Windows SDK.

*lpBuffin*<br/>
Ponteiro para um [INTERNET_BUFFERS](/windows/win32/api/wininet/ns-wininet-internet_buffersw) inicializado que descreve o buffer de entrada usado para a operação.

*Dwcontext*<br/>
O identificador de `CHttpFile` contexto para a operação. Consulte Observações para obter mais informações sobre este parâmetro.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0. Se a chamada falhar, determine a causa da falha examinando o objeto [CInternetException](../../mfc/reference/cinternetexception-class.md) lançado.

### <a name="remarks"></a>Comentários

O valor padrão para *dwContext* é `CHttpFile` enviado pelo MFC para o `CHttpFile` objeto do objeto [CInternetSession](../../mfc/reference/cinternetsession-class.md) que criou o objeto. Quando você chama [CInternetSession::OpenURL](../../mfc/reference/cinternetsession-class.md#openurl) ou [CHttpConnection](../../mfc/reference/chttpconnection-class.md) para construir um `CHttpFile` objeto, você pode substituir o padrão para definir o identificador de contexto como um valor de sua escolha. O identificador de contexto é retornado ao [CInternetSession::OnStatusCallback](../../mfc/reference/cinternetsession-class.md#onstatuscallback) para fornecer status no objeto com o qual ele é identificado. Veja o artigo [Primeiros Passos da Internet: WinInet](../../mfc/wininet-basics.md) para obter mais informações sobre o identificador de contexto.

## <a name="chttpfilegetfileurl"></a><a name="getfileurl"></a>chttpfile::getFileURL

Chame esta função de membro para obter o nome do arquivo HTTP como uma URL.

```
virtual CString GetFileURL() const;
```

### <a name="return-value"></a>Valor retornado

Um objeto [CString](../../atl-mfc-shared/reference/cstringt-class.md) contendo uma URL fazendo referência ao recurso associado a este arquivo.

### <a name="remarks"></a>Comentários

Use esta função de membro somente após uma `CHttpFile` chamada bem-sucedida para [SendRequest](#sendrequest) ou em um objeto criado com sucesso pelo [OpenURL](../../mfc/reference/cinternetsession-class.md#openurl).

## <a name="chttpfilegetobject"></a><a name="getobject"></a>chttpfile::getobject

Chame esta função de membro para obter `CHttpFile`o nome do objeto associado a isso .

```
CString GetObject() const;
```

### <a name="return-value"></a>Valor retornado

Um objeto [CString](../../atl-mfc-shared/reference/cstringt-class.md) contendo o nome do objeto.

### <a name="remarks"></a>Comentários

Use esta função de membro somente após uma `CHttpFile` chamada bem-sucedida para [SendRequest](#sendrequest) ou em um objeto criado com sucesso pelo [OpenURL](../../mfc/reference/cinternetsession-class.md#openurl).

## <a name="chttpfilegetverb"></a><a name="getverb"></a>CHttpFile::GetVerb

Ligue para esta função de membro para obter o `CHttpFile`verbo HTTP (ou método) associado a isso .

```
CString GetVerb() const;
```

### <a name="return-value"></a>Valor retornado

Um objeto [CString](../../atl-mfc-shared/reference/cstringt-class.md) contendo o nome do verbo HTTP (ou método).

### <a name="remarks"></a>Comentários

Use esta função de membro somente após uma `CHttpFile` chamada bem-sucedida para [SendRequest](#sendrequest) ou em um objeto criado com sucesso pelo [OpenURL](../../mfc/reference/cinternetsession-class.md#openurl).

## <a name="chttpfilequeryinfo"></a><a name="queryinfo"></a>CHttpFile::QueryInfo

Ligue para esta função de membro para retornar a resposta ou solicitar cabeçalhos a partir de uma solicitação HTTP.

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
Uma combinação do atributo com a consulta e os seguintes sinalizadores que especificam o tipo de informação solicitada:

- HTTP_QUERY_CUSTOM Encontra o nome do cabeçalho e retorna este valor em *lpvBuffer* na saída. HTTP_QUERY_CUSTOM lança uma afirmação se o cabeçalho não for encontrado.

- HTTP_QUERY_FLAG_REQUEST_HEADERS Normalmente, o aplicativo consulta os cabeçalhos de resposta, mas um aplicativo também pode consultar cabeçalhos de solicitação usando esse sinalizador.

- HTTP_QUERY_FLAG_SYSTEMTIME Para aqueles cabeçalhos cujo valor é uma seqüência de data/hora, como "Last-Modified-Time", este sinalizador retorna o valor do cabeçalho como uma estrutura padrão do Win32 [SYSTEMTIME](/windows/win32/api/minwinbase/ns-minwinbase-systemtime) que não requer o aplicativo para analisar os dados. Se você usar este sinalizador, você `SYSTEMTIME` pode querer usar a substituição da função.

- HTTP_QUERY_FLAG_NUMBER Para aqueles cabeçalhos cujo valor é um número, como o código de status, este sinalizador retorna os dados como um número de 32 bits.

Consulte a seção **Observações** para obter uma lista dos valores possíveis.

*Lpvbuffer*<br/>
Um ponteiro para o buffer que recebe as informações.

*Lpdwbufferlength*<br/>
Na entrada, isso aponta para um valor que contém o comprimento do buffer de dados, em número de caracteres ou bytes. Consulte a seção Observações para obter informações mais **detalhadas** sobre este parâmetro.

*Lpdwindex*<br/>
Um ponteiro para um índice de cabeçalho baseado em zero. Pode ser NULL. Use este sinalizador para enumerar vários cabeçalhos com o mesmo nome. Na entrada, *lpdwIndex* indica o índice do cabeçalho especificado para retornar. Na saída, *lpdwIndex* indica o índice do próximo cabeçalho. Se o próximo índice não for encontrado, ERROR_HTTP_HEADER_NOT_FOUND é devolvido.

*Str*<br/>
Uma referência ao objeto [CString](../../atl-mfc-shared/reference/cstringt-class.md) que recebe as informações devolvidas.

*Dwindex*<br/>
Um valor de índice. Consulte *lpdwIndex*.

*pSysTime*<br/>
Um ponteiro para uma estrutura Win32 [SYSTEMTIME.](/windows/win32/api/minwinbase/ns-minwinbase-systemtime)

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0. Se a chamada falhar, a função Win32 [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) pode ser chamada para determinar a causa do erro.

### <a name="remarks"></a>Comentários

Use esta função de membro somente após uma `CHttpFile` chamada bem-sucedida para [SendRequest](#sendrequest) ou em um objeto criado com sucesso pelo [OpenURL](../../mfc/reference/cinternetsession-class.md#openurl).

Você pode recuperar os seguintes tipos de dados de: `QueryInfo`

- strings (padrão)

- `SYSTEMTIME`(para "Dados:" "Expira:" etc, cabeçalhos)

- DWORD (para STATUS_CODE, CONTENT_LENGTH, etc.)

Quando uma seqüência é escrita no buffer, `lpdwBufferLength` e a função de membro é bem sucedida, contém o comprimento da seqüência de caracteres menos 1 para o caractere NULL terminante.

Os possíveis valores *do dwInfoLevel* incluem:

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

## <a name="chttpfilequeryinfostatuscode"></a><a name="queryinfostatuscode"></a>CHttpFile::QueryInfoStatusCode

Ligue para esta função de membro para obter o código de status associado a uma solicitação HTTP e colocá-lo no parâmetro *dwStatusCode* fornecido.

```
BOOL QueryInfoStatusCode(DWORD& dwStatusCode) const;
```

### <a name="parameters"></a>Parâmetros

*dwStatusCode*<br/>
Uma referência a um código de status. Os códigos de status indicam o sucesso ou falha do evento solicitado. Consulte **Observações** para uma seleção de descrições de código de status.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0. Se a chamada falhar, a função Win32 [GetLastError](/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) pode ser chamada para determinar a causa do erro.

### <a name="remarks"></a>Comentários

Use esta função de membro somente após uma `CHttpFile` chamada bem-sucedida para [SendRequest](#sendrequest) ou em um objeto criado com sucesso pelo [OpenURL](../../mfc/reference/cinternetsession-class.md#openurl).

Os códigos de status HTTP caem em grupos que indicam o sucesso ou a falha da solicitação. As tabelas a seguir descrevem os grupos de código de status e os códigos de status HTTP mais comuns.

|Agrupar|Significado|
|-----------|-------------|
|200 a 299|Sucesso|
|300 a 399|Informações|
|400-499|Erro de solicitação|
|500-599|Erro do servidor|

Códigos comuns de status HTTP:

|Código de status|Significado|
|-----------------|-------------|
|200|URL localizado, transmissão segue|
|400|Pedido ininteligível|
|404|URL solicitado não encontrado|
|405|Servidor não suporta método solicitado|
|500|Erro de servidor desconhecido|
|503|Capacidade do servidor alcançada|

## <a name="chttpfilesendrequest"></a><a name="sendrequest"></a>chttpfile::SendRequest

Ligue para esta função de membro para enviar uma solicitação a um servidor HTTP.

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

*Pstrheaders*<br/>
Um ponteiro para uma seqüência contendo o nome dos cabeçalhos para enviar.

*dwHeadersLen*<br/>
O comprimento dos cabeçalhos identificados por *pstrHeaders*.

*lpOpcional*<br/>
Quaisquer dados opcionais a serem enviados imediatamente após os cabeçalhos de solicitação. Isso é geralmente usado para operações POST e PUT. Isso pode ser NULO se não houver dados opcionais para enviar.

*dwOptionalLen*<br/>
O comprimento do *lpOptional*.

*strHeaders*<br/>
Uma seqüência contendo o nome dos cabeçalhos para a solicitação que está sendo enviada.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0. Se a chamada falhar, determine a causa da falha examinando o objeto [CInternetException](../../mfc/reference/cinternetexception-class.md) lançado.

## <a name="chttpfilesendrequestex"></a><a name="sendrequestex"></a>chttpfile::SendRequestEx

Ligue para esta função de membro para enviar uma solicitação a um servidor HTTP.

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
Bandeiras descrevendo a operação. Para obter uma lista de sinalizadores apropriados, consulte [HttpSendRequestEx](/windows/win32/api/wininet/nf-wininet-httpsendrequestexw) no Windows SDK.

*Dwcontext*<br/>
O identificador de `CHttpFile` contexto para a operação. Consulte Observações para obter mais informações sobre este parâmetro.

*lpBuffin*<br/>
Ponteiro para um [INTERNET_BUFFERS](/windows/win32/api/wininet/ns-wininet-internet_buffersw) inicializado que descreve o buffer de entrada usado para a operação.

*lpBuffOut*<br/>
Ponteiro para uma INTERNET_BUFFERS inicializada que descreve o buffer de saída usado para a operação.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido. Se a chamada falhar, determine a causa da falha examinando o objeto [CInternetException](../../mfc/reference/cinternetexception-class.md) lançado.

### <a name="remarks"></a>Comentários

Esta função permite que seu aplicativo envie dados usando `CInternetFile`os métodos [Write](../../mfc/reference/cinternetfile-class.md#write) e [WriteString](../../mfc/reference/cinternetfile-class.md#writestring) de . Você deve saber o comprimento dos dados a serem enviados antes de chamar qualquer substituição desta função. A primeira substituição permite especificar o comprimento dos dados que você gostaria de enviar. A segunda substituição aceita ponteiros para estruturas INTERNET_BUFFERS, que podem ser usadas para descrever o buffer em grande detalhe.

Depois que o conteúdo for gravado no arquivo, ligue para [EndRequest](#endrequest) para encerrar a operação.

O valor padrão para *dwContext* é `CHttpFile` enviado pelo MFC para o `CHttpFile` objeto do objeto [CInternetSession](../../mfc/reference/cinternetsession-class.md) que criou o objeto. Quando você chama [CInternetSession::OpenURL](../../mfc/reference/cinternetsession-class.md#openurl) ou [CHttpConnection](../../mfc/reference/chttpconnection-class.md) para construir um `CHttpFile` objeto, você pode substituir o padrão para definir o identificador de contexto como um valor de sua escolha. O identificador de contexto é retornado ao [CInternetSession::OnStatusCallback](../../mfc/reference/cinternetsession-class.md#onstatuscallback) para fornecer status no objeto com o qual ele é identificado. Veja o artigo [Primeiros Passos da Internet: WinInet](../../mfc/wininet-basics.md) para obter mais informações sobre o identificador de contexto.

### <a name="example"></a>Exemplo

Este fragmento de código envia o conteúdo de uma string para um DLL chamado MFCISAPI. DLL no servidor LOCALHOST. Embora este exemplo use `WriteString`apenas uma chamada para, usar várias chamadas para enviar dados em blocos é aceitável.

[!code-cpp[NVC_MFCWinInet#9](../../mfc/codesnippet/cpp/chttpfile-class_1.cpp)]

## <a name="see-also"></a>Confira também

[Classe CInternetFile](../../mfc/reference/cinternetfile-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CInternetFile](../../mfc/reference/cinternetfile-class.md)<br/>
[Classe CGopherFile](../../mfc/reference/cgopherfile-class.md)<br/>
[Classe CHttpConnection](../../mfc/reference/chttpconnection-class.md)
