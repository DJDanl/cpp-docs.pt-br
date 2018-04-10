---
title: Classe CHttpFile | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-windows
ms.tgt_pltfrm: ''
ms.topic: reference
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
dev_langs:
- C++
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
caps.latest.revision: 23
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 0e9af23bb74ba8e96f29a5b7cc4139d2932df8c1
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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
|[CHttpFile::AddRequestHeaders](#addrequestheaders)|Adiciona cabeçalhos para a solicitação enviada a um servidor HTTP.|  
|[CHttpFile::EndRequest](#endrequest)|Termina uma solicitação enviada a um servidor HTTP com o [SendRequestEx](#sendrequestex) função de membro.|  
|[CHttpFile::GetFileURL](#getfileurl)|Obtém a URL para o arquivo especificado.|  
|[CHttpFile::GetObject](#getobject)|Obtém o objeto de destino do verbo em uma solicitação para um servidor HTTP.|  
|[CHttpFile::GetVerb](#getverb)|Obtém o verbo que foi usado em uma solicitação para um servidor HTTP.|  
|[CHttpFile::QueryInfo](#queryinfo)|Retorna os cabeçalhos de solicitação ou resposta do servidor HTTP.|  
|[CHttpFile::QueryInfoStatusCode](#queryinfostatuscode)|Recupera o código de status associado a uma solicitação HTTP e o coloca em fornecido `dwStatusCode` parâmetro.|  
|[CHttpFile::SendRequest](#sendrequest)|Envia uma solicitação para um servidor HTTP.|  
|[CHttpFile::SendRequestEx](#sendrequestex)|Envia uma solicitação para um servidor HTTP usando o [gravar](../../mfc/reference/cinternetfile-class.md#write) ou [WriteString](../../mfc/reference/cinternetfile-class.md#writestring) métodos de `CInternetFile`.|  
  
## <a name="remarks"></a>Comentários  
 Se a sessão da Internet lê dados de um servidor HTTP, você deve criar uma instância de `CHttpFile`.  
  
 Para saber mais sobre como `CHttpFile` funciona com as outras classes de Internet MFC, consulte o artigo [Internet Programando com WinInet](../../mfc/win32-internet-extensions-wininet.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CFile](../../mfc/reference/cfile-class.md)  
  
 [CStdioFile](../../mfc/reference/cstdiofile-class.md)  
  
 [CInternetFile](../../mfc/reference/cinternetfile-class.md)  
  
 `CHttpFile`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxinet.h  
  
##  <a name="addrequestheaders"></a>CHttpFile::AddRequestHeaders  
 Chamar essa função de membro para adicionar um ou mais cabeçalhos de solicitação HTTP para a solicitação HTTP tratar.  
  
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
 `pstrHeaders`  
 Um ponteiro para uma cadeia de caracteres que contém o cabeçalho ou cabeçalhos para acrescentar à solicitação. Cada cabeçalho deve ser terminado por um par RC/AL.  
  
 `dwFlags`  
 Modifica a semântica dos cabeçalhos de novo. Pode ser um dos seguintes:  
  
- `HTTP_ADDREQ_FLAG_COALESCE`Mescla os cabeçalhos de mesmo nome, usando o sinalizador para adicionar o primeiro cabeçalho encontrado para o cabeçalho subsequente. Por exemplo, "aceitar: texto / *" seguido por "aceitar: áudio /\*" resulta na formação de um único cabeçalho "aceitar: texto /\*, áudio /\*". É responsabilidade do aplicativo de chamada para garantir um esquema consistente com relação aos dados recebidos pelo solicitações enviadas com cabeçalhos separados ou agrupados.  
  
- `HTTP_ADDREQ_FLAG_REPLACE`Executa uma remover e adicionar para substituir o cabeçalho atual. O nome do cabeçalho será usado para remover o cabeçalho atual e o valor total será usado para adicionar o novo cabeçalho. Se o valor de cabeçalho está vazio e o cabeçalho for encontrado, ele será removido. Se não estiver vazia, o valor do cabeçalho é substituído.  
  
- `HTTP_ADDREQ_FLAG_ADD_IF_NEW`Apenas adiciona o cabeçalho se ele ainda não existir. Se existir, um erro será retornado.  
  
- `HTTP_ADDREQ_FLAG_ADD`Usado com substituição. Adiciona o cabeçalho se ele não existir.  
  
 `dwHeadersLen`  
 O comprimento, em caracteres, de `pstrHeaders`. Se esse for o L-1, em seguida, `pstrHeaders` deve para ser terminada em zero e o comprimento é calculado.  
  
 `str`  
 Uma referência a um [CString](../../atl-mfc-shared/reference/cstringt-class.md) objeto que contém o cabeçalho de solicitação ou cabeçalhos a serem adicionados.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0. Se a chamada falhar, a função Win32 [GetLastError](http://msdn.microsoft.com/library/windows/desktop/ms679360) pode ser chamado para determinar a causa do erro.  
  
### <a name="remarks"></a>Comentários  
 `AddRequestHeaders`acrescenta cabeçalhos adicionais de formato livre para o identificador de solicitação HTTP. Ele é destinado ao uso por clientes sofisticados que precisam de controle detalhado sobre a solicitação exata enviado para o servidor HTTP.  
  
> [!NOTE]
>  O aplicativo pode passar vários cabeçalhos em `pstrHeaders` ou `str` para um `AddRequestHeaders` chamar usando `HTTP_ADDREQ_FLAG_ADD` ou `HTTP_ADDREQ_FLAG_ADD_IF_NEW`. Se o aplicativo tenta remover ou substituir um cabeçalho usando **HTTP_ADDREQ_FLAG_REMOVE** ou `HTTP_ADDREQ_FLAG_REPLACE`, apenas um cabeçalho pode ser fornecido no `lpszHeaders`.  
  
##  <a name="chttpfile"></a>CHttpFile::CHttpFile  
 Essa função de membro é chamada para construir um `CHttpFile` objeto.  
  
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
 `hFile`  
 Um identificador para um arquivo da Internet.  
  
 `hSession`  
 Um identificador para uma sessão de Internet.  
  
 *pstrObject*  
 Um ponteiro para uma cadeia de caracteres que contém o `CHttpFile` objeto.  
  
 `pstrServer`  
 Um ponteiro para uma cadeia de caracteres que contém o nome do servidor.  
  
 `pstrVerb`  
 Um ponteiro para uma cadeia de caracteres que contém o método a ser usado ao enviar a solicitação. Pode ser **POST**, **HEAD**, ou `GET`.  
  
 dwContext  
 O identificador de contexto para o `CHttpFile` objeto. Consulte **comentários** para obter mais informações sobre esse parâmetro.  
  
 `pConnection`  
 Um ponteiro para um [CHttpConnection](../../mfc/reference/chttpconnection-class.md) objeto.  
  
### <a name="remarks"></a>Comentários  
 Você nunca construir um `CHttpFile` objeto diretamente; em vez disso, chame [CInternetSession::OpenURL](../../mfc/reference/cinternetsession-class.md#openurl) ou [CHttpConnection::OpenRequest](../../mfc/reference/chttpconnection-class.md#openrequest) em vez disso.  
  
 O valor padrão para `dwContext` é enviada pelo MFC para o `CHttpFile` de objeto o [CInternetSession](../../mfc/reference/cinternetsession-class.md) do objeto que criou o `CHttpFile` objeto. Quando você chama `CInternetSession::OpenURL` ou `CHttpConnection` para construir um `CHttpFile` do objeto, você pode substituir o padrão para definir o identificador de contexto para um valor de sua escolha. O identificador de contexto é retornado ao [CInternetSession::OnStatusCallback](../../mfc/reference/cinternetsession-class.md#onstatuscallback) para fornecer o status do objeto ao qual ela é identificada. Consulte o artigo [Internet primeiras etapas: WinInet](../../mfc/wininet-basics.md) para obter mais informações sobre o identificador de contexto.  
  
##  <a name="endrequest"></a>CHttpFile::EndRequest  
 Chamar essa função de membro para encerrar uma solicitação enviada a um servidor HTTP com o [SendRequestEx](#sendrequestex) função de membro.  
  
```  
BOOL EndRequest(
    DWORD dwFlags = 0,  
    LPINTERNET_BUFFERS lpBuffIn = NULL,  
    DWORD_PTR dwContext = 1);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwFlags`  
 Sinalizadores que descrevem a operação. Para obter uma lista dos sinalizadores apropriados, consulte [HttpEndRequest](http://msdn.microsoft.com/library/windows/desktop/aa384230) no SDK do Windows.  
  
 `lpBuffIn`  
 Ponteiro para uma inicializado [INTERNET_BUFFERS](http://msdn.microsoft.com/library/windows/desktop/aa385132) que descreve o buffer de entrada usado para a operação.  
  
 `dwContext`  
 O identificador de contexto para o `CHttpFile` operação. Consulte comentários para obter mais informações sobre esse parâmetro.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0. Se a chamada falhar, determinar a causa da falha, examinando o lançado [CInternetException](../../mfc/reference/cinternetexception-class.md) objeto.  
  
### <a name="remarks"></a>Comentários  
 O valor padrão para `dwContext` é enviada pelo MFC para o `CHttpFile` de objeto o [CInternetSession](../../mfc/reference/cinternetsession-class.md) do objeto que criou o `CHttpFile` objeto. Quando você chama [CInternetSession::OpenURL](../../mfc/reference/cinternetsession-class.md#openurl) ou [CHttpConnection](../../mfc/reference/chttpconnection-class.md) para construir um `CHttpFile` do objeto, você pode substituir o padrão para definir o identificador de contexto para um valor de sua escolha. O identificador de contexto é retornado ao [CInternetSession::OnStatusCallback](../../mfc/reference/cinternetsession-class.md#onstatuscallback) para fornecer o status do objeto ao qual ela é identificada. Consulte o artigo [Internet primeiras etapas: WinInet](../../mfc/wininet-basics.md) para obter mais informações sobre o identificador de contexto.  
  
##  <a name="getfileurl"></a>CHttpFile::GetFileURL  
 Chame essa função de membro para obter o nome do arquivo como uma URL HTTP.  
  
```  
virtual CString GetFileURL() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um [CString](../../atl-mfc-shared/reference/cstringt-class.md) objeto que contém uma URL de referência o recurso associado a este arquivo.  
  
### <a name="remarks"></a>Comentários  
 Use esta função de membro somente após uma chamada bem-sucedida para [SendRequest](#sendrequest) ou em um `CHttpFile` objeto criado com êxito pelo [Abrirurl](../../mfc/reference/cinternetsession-class.md#openurl).  
  
##  <a name="getobject"></a>CHttpFile::GetObject  
 Chamar essa função de membro para obter o nome do objeto associado a esta `CHttpFile`.  
  
```  
CString GetObject() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um [CString](../../atl-mfc-shared/reference/cstringt-class.md) objeto que contém o nome do objeto.  
  
### <a name="remarks"></a>Comentários  
 Use esta função de membro somente após uma chamada bem-sucedida para [SendRequest](#sendrequest) ou em um `CHttpFile` objeto criado com êxito pelo [Abrirurl](../../mfc/reference/cinternetsession-class.md#openurl).  
  
##  <a name="getverb"></a>CHttpFile::GetVerb  
 Chamar essa função de membro para obter o HTTP verbo (ou método) associado a esta `CHttpFile`.  
  
```  
CString GetVerb() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um [CString](../../atl-mfc-shared/reference/cstringt-class.md) objeto que contém o nome do verbo HTTP (ou método).  
  
### <a name="remarks"></a>Comentários  
 Use esta função de membro somente após uma chamada bem-sucedida para [SendRequest](#sendrequest) ou em um `CHttpFile` objeto criado com êxito pelo [Abrirurl](../../mfc/reference/cinternetsession-class.md#openurl).  
  
##  <a name="queryinfo"></a>CHttpFile::QueryInfo  
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
 `dwInfoLevel`  
 Uma combinação de atributo para consulta e os seguintes sinalizadores que especificam o tipo de informações solicitadas:  
  
- **HTTP_QUERY_CUSTOM** localiza o nome do cabeçalho e retorna esse valor em `lpvBuffer` na saída. **HTTP_QUERY_CUSTOM** lança uma asserção se o cabeçalho não for encontrado.  
  
- **HTTP_QUERY_FLAG_REQUEST_HEADERS** normalmente, o aplicativo consulta os cabeçalhos de resposta, mas um aplicativo também pode consultar os cabeçalhos de solicitação usando esse sinalizador.  
  
- **HTTP_QUERY_FLAG_SYSTEMTIME** para esses cabeçalhos cujo valor é uma cadeia de caracteres de data/hora, como "Last-Modified-Time," esse sinalizador retorna o valor do cabeçalho como Win32 padrão [SYSTEMTIME](http://msdn.microsoft.com/library/windows/desktop/ms724950) estrutura que não exigem o aplicativo para analisar os dados. Se você usar esse sinalizador, convém usar o `SYSTEMTIME` substituir da função.  
  
- **HTTP_QUERY_FLAG_NUMBER** para esses cabeçalhos cujo valor é um número, como o código de status, este sinalizador retorna os dados como um número de 32 bits.  
  
 Consulte o **comentários** seção para obter uma lista dos possíveis valores.  
  
 `lpvBuffer`  
 Um ponteiro para o buffer que recebe as informações.  
  
 `lpdwBufferLength`  
 Na entrada, aponta para um valor que contém o comprimento do buffer de dados, no número de caracteres ou bytes. Consulte o **comentários** seção para obter mais informações sobre esse parâmetro.  
  
 `lpdwIndex`  
 Um ponteiro para um índice com base em zero do cabeçalho. Pode ser **nulo**. Use este sinalizador para enumerar vários cabeçalhos com o mesmo nome. Na entrada, `lpdwIndex` indica o índice do cabeçalho especificado para retornar. Na saída, `lpdwIndex` indica o índice do próximo cabeçalho. Se o próximo índice não for encontrado, **ERROR_HTTP_HEADER_NOT_FOUND** é retornado.  
  
 `str`  
 Uma referência para o [CString](../../atl-mfc-shared/reference/cstringt-class.md) objeto que recebe as informações retornadas.  
  
 `dwIndex`  
 Um valor de índice. Consulte `lpdwIndex`.  
  
 *pSysTime*  
 Um ponteiro para um Win32 [SYSTEMTIME](http://msdn.microsoft.com/library/windows/desktop/ms724950) estrutura.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0. Se a chamada falhar, a função Win32 [GetLastError](http://msdn.microsoft.com/library/windows/desktop/ms679360) pode ser chamado para determinar a causa do erro.  
  
### <a name="remarks"></a>Comentários  
 Use esta função de membro somente após uma chamada bem-sucedida para [SendRequest](#sendrequest) ou em um `CHttpFile` objeto criado com êxito pelo [Abrirurl](../../mfc/reference/cinternetsession-class.md#openurl).  
  
 Você pode recuperar os seguintes tipos de dados de `QueryInfo`:  
  
-   cadeias de caracteres (padrão)  
  
- `SYSTEMTIME`(para "dados:" "Expires:" etc, cabeçalhos)  
  
- `DWORD`(para **STATUS_CODE**, **CONTENT_LENGTH**, etc.)  
  
 Quando uma cadeia de caracteres é gravada no buffer e a função de membro for bem-sucedida, `lpdwBufferLength` contém o comprimento da cadeia de caracteres em caracteres menos 1 para a terminação **nulo** caracteres.  
  
 Os possíveis `dwInfoLevel` valores incluem:  
  
- **HTTP_QUERY_MIME_VERSION**  
  
- **HTTP_QUERY_CONTENT_TYPE**  
  
- **HTTP_QUERY_CONTENT_TRANSFER_ENCODING**  
  
- **HTTP_QUERY_CONTENT_ID**  
  
- **HTTP_QUERY_CONTENT_DESCRIPTION**  
  
- **HTTP_QUERY_CONTENT_LENGTH**  
  
- **HTTP_QUERY_ALLOWED_METHODS**  
  
- **HTTP_QUERY_PUBLIC_METHODS**  
  
- **HTTP_QUERY_DATE**  
  
- **HTTP_QUERY_EXPIRES**  
  
- **HTTP_QUERY_LAST_MODIFIED**  
  
- **HTTP_QUERY_MESSAGE_ID**  
  
- **HTTP_QUERY_URI**  
  
- **HTTP_QUERY_DERIVED_FROM**  
  
- **HTTP_QUERY_LANGUAGE**  
  
- **HTTP_QUERY_COST**  
  
- **HTTP_QUERY_WWW_LINK**  
  
- **HTTP_QUERY_PRAGMA**  
  
- **HTTP_QUERY_VERSION**  
  
- **HTTP_QUERY_STATUS_CODE**  
  
- **HTTP_QUERY_STATUS_TEXT**  
  
- **HTTP_QUERY_RAW_HEADERS**  
  
- **HTTP_QUERY_RAW_HEADERS_CRLF**  
  
##  <a name="queryinfostatuscode"></a>CHttpFile::QueryInfoStatusCode  
 Chamar essa função de membro para obter o código de status associado a uma solicitação HTTP e colocá-lo em fornecido `dwStatusCode` parâmetro.  
  
```  
BOOL QueryInfoStatusCode(DWORD& dwStatusCode) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwStatusCode`  
 Uma referência a um código de status. Códigos de status indicam o êxito ou falha do evento solicitado. Consulte **comentários** para uma seleção de descrições de códigos de status.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0. Se a chamada falhar, a função Win32 [GetLastError](http://msdn.microsoft.com/library/windows/desktop/ms679360) pode ser chamado para determinar a causa do erro.  
  
### <a name="remarks"></a>Comentários  
 Use esta função de membro somente após uma chamada bem-sucedida para [SendRequest](#sendrequest) ou em um `CHttpFile` objeto criado com êxito pelo [Abrirurl](../../mfc/reference/cinternetsession-class.md#openurl).  
  
 Códigos de status HTTP se enquadram em grupos que indica o êxito ou falha da solicitação. As tabelas a seguir descrevem os grupos de códigos de status e os códigos de status HTTP mais comuns.  
  
|Grupo|Significado|  
|-----------|-------------|  
|200-299|Êxito|  
|300-399|Informações|  
|400-499|Erro de solicitação|  
|500-599|Erro de servidor|  
  
 Códigos de Status HTTP comuns:  
  
|Código de status|Significado|  
|-----------------|-------------|  
|200|URL localizado, a maneira de transmissão|  
|400|Solicitação ininteligível|  
|404|Solicitou a URL não encontrado|  
|405|Servidor não suporta o método solicitado|  
|500|Erro de servidor desconhecido|  
|503|Alcançada a capacidade do servidor|  
  
##  <a name="sendrequest"></a>CHttpFile::SendRequest  
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
 `pstrHeaders`  
 Um ponteiro para uma cadeia de caracteres que contém o nome dos cabeçalhos de enviar.  
  
 `dwHeadersLen`  
 O comprimento dos cabeçalhos identificado por `pstrHeaders`.  
  
 `lpOptional`  
 Nenhum dado opcional para enviar imediatamente após os cabeçalhos de solicitação. Isso geralmente é usado para **POST** e **colocar** operações. Isso pode ser **nulo** se não houver dados opcionais a serem enviados.  
  
 *dwOptionalLen*  
 O comprimento de `lpOptional`.  
  
 `strHeaders`  
 Uma cadeia de caracteres que contém o nome dos cabeçalhos da solicitação que está sendo enviado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0. Se a chamada falhar, determinar a causa da falha, examinando o lançado [CInternetException](../../mfc/reference/cinternetexception-class.md) objeto.  
  
##  <a name="sendrequestex"></a>CHttpFile::SendRequestEx  
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
 *dwTotalLen*  
 Número de bytes a serem enviados na solicitação.  
  
 `dwFlags`  
 Sinalizadores que descrevem a operação. Para obter uma lista de sinalizadores apropriados, consulte [HttpSendRequestEx](http://msdn.microsoft.com/library/windows/desktop/aa384318) no SDK do Windows.  
  
 `dwContext`  
 O identificador de contexto para o `CHttpFile` operação. Consulte comentários para obter mais informações sobre esse parâmetro.  
  
 `lpBuffIn`  
 Ponteiro para uma inicializado [INTERNET_BUFFERS](http://msdn.microsoft.com/library/windows/desktop/aa385132) que descreve o buffer de entrada usado para a operação.  
  
 *lpBuffOut*  
 Ponteiro para uma inicializado **INTERNET_BUFFERS** que descreve o buffer de saída usado para a operação.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se tiver êxito. Se a chamada falhar, determinar a causa da falha, examinando o lançado [CInternetException](../../mfc/reference/cinternetexception-class.md) objeto.  
  
### <a name="remarks"></a>Comentários  
 Essa função permite que seu aplicativo para enviar dados usando o [gravar](../../mfc/reference/cinternetfile-class.md#write) e [WriteString](../../mfc/reference/cinternetfile-class.md#writestring) métodos de `CInternetFile`. Você deve saber o comprimento dos dados para enviar antes de chamar qualquer substituição dessa função. A primeira substituição permite que você especifique o comprimento dos dados que você gostaria de enviar. A substituição de segundo aceita ponteiros para **INTERNET_BUFFERS** estruturas, o que podem ser usadas para descrever o buffer em detalhes.  
  
 Depois que o conteúdo é gravado no arquivo, chame [EndRequest](#endrequest) para encerrar a operação.  
  
 O valor padrão para `dwContext` é enviada pelo MFC para o `CHttpFile` de objeto o [CInternetSession](../../mfc/reference/cinternetsession-class.md) do objeto que criou o `CHttpFile` objeto. Quando você chama [CInternetSession::OpenURL](../../mfc/reference/cinternetsession-class.md#openurl) ou [CHttpConnection](../../mfc/reference/chttpconnection-class.md) para construir um `CHttpFile` do objeto, você pode substituir o padrão para definir o identificador de contexto para um valor de sua escolha. O identificador de contexto é retornado ao [CInternetSession::OnStatusCallback](../../mfc/reference/cinternetsession-class.md#onstatuscallback) para fornecer o status do objeto ao qual ela é identificada. Consulte o artigo [Internet primeiras etapas: WinInet](../../mfc/wininet-basics.md) para obter mais informações sobre o identificador de contexto.  
  
### <a name="example"></a>Exemplo  
 Este fragmento de código envia o conteúdo de uma cadeia de caracteres para uma DLL denominada MFCISAPI. DLL no servidor host local. Embora este exemplo usa apenas uma chamada para `WriteString`, usar várias chamadas para enviar dados em blocos é aceitável.  
  
 [!code-cpp[NVC_MFCWinInet#9](../../mfc/codesnippet/cpp/chttpfile-class_1.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Classe CInternetFile](../../mfc/reference/cinternetfile-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CInternetFile](../../mfc/reference/cinternetfile-class.md)   
 [Classe CGopherFile](../../mfc/reference/cgopherfile-class.md)   
 [Classe CHttpConnection](../../mfc/reference/chttpconnection-class.md)
