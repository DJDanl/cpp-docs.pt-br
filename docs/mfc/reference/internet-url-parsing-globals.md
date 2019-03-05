---
title: Auxiliares e globais de análise de URL da Internet
ms.date: 04/03/2017
f1_keywords:
- vc.mfc.macros.isapi
helpviewer_keywords:
- parsing, URLs
- URLs, parsing
ms.assetid: 46c6384f-e4a6-4dbd-9196-219c19040ec5
ms.openlocfilehash: 0831d94f1a6f0293d3605a5e2e9ebde0564baf24
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57293466"
---
# <a name="internet-url-parsing-globals-and-helpers"></a>Auxiliares e globais de análise de URL da Internet

Quando um cliente envia uma consulta para o servidor de Internet, você pode usar uma das URLs globais de análise para extrair informações sobre o cliente. As funções auxiliares fornecem outra funcionalidade de internet.

## <a name="internet-url-parsing-globals"></a>Globais de análise de URL da Internet

|||
|-|-|
|[AfxParseURL](#afxparseurl)|Analisa uma cadeia de caracteres de URL e retorna o tipo de serviço e seus componentes.|
|[AfxParseURLEx](#afxparseurlex)|Analisa uma cadeia de caracteres de URL e retorna o tipo de serviço e seus componentes, bem como fornecendo o nome de usuário e senha.|

## <a name="other-internet-helpers"></a>Outros auxiliares de Internet

|||
|-|-|
|[AfxThrowInternetException](#afxthrowinternetexception)|Gera uma exceção relacionada para a conexão de internet.|
|[AfxGetInternetHandleType](#afxgetinternethandletype)|Determina o tipo de um identificador de Internet.|

##  <a name="afxparseurl"></a>  AfxParseURL

Nesse global é usado na [CInternetSession::OpenURL](../../mfc/reference/cinternetsession-class.md#openurl).

```
BOOL AFXAPI AfxParseURL(
    LPCTSTR pstrURL,
    DWORD& dwServiceType,
    CString& strServer,
    CString& strObject,
    INTERNET_PORT& nPort);
```

### <a name="parameters"></a>Parâmetros

*pstrURL*<br/>
Um ponteiro para uma cadeia de caracteres que contém a URL a ser analisado.

*dwServiceType*<br/>
Indica o tipo de serviço de Internet. Os valores possíveis são:

- AFX_INET_SERVICE_FTP

- AFX_INET_SERVICE_HTTP

- AFX_INET_SERVICE_HTTPS

- AFX_INET_SERVICE_GOPHER

- AFX_INET_SERVICE_FILE

- AFX_INET_SERVICE_MAILTO

- AFX_INET_SERVICE_NEWS

- AFX_INET_SERVICE_NNTP

- AFX_INET_SERVICE_TELNET

- AFX_INET_SERVICE_WAIS

- AFX_INET_SERVICE_MID

- AFX_INET_SERVICE_CID

- AFX_INET_SERVICE_PROSPERO

- AFX_INET_SERVICE_AFS

- AFX_INET_SERVICE_UNK

*strServer*<br/>
O primeiro segmento da URL após o tipo de serviço.

*strObject*<br/>
Um objeto que se refere a URL a (pode estar vazia).

*nPort*<br/>
Determinado a partir do servidor ou o objeto parte da URL, ou se ela existe.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a URL foi analisada com êxito; Caso contrário, 0 se ele está vazio ou não contém um tipo de serviço de Internet conhecido.

### <a name="remarks"></a>Comentários

Ele analisa uma cadeia de caracteres de URL e retorna o tipo de serviço e seus componentes.

Por exemplo, `AfxParseURL` analisa as URLs no formato *service://server/dir/dir/object.ext:port* e retorna seus componentes armazenados da seguinte maneira:

*strServer* == "server"

*strObject* == "/dir/dir/object/object.ext"

*nPort* == #port

*dwServiceType* == #service

> [!NOTE]
>  Para chamar essa função, seu projeto deve incluir AFXINET. H.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxinet.h

##  <a name="afxparseurlex"></a>  AfxParseURLEx

Essa função global é a versão estendida do [AfxParseURL](#afxparseurl) e é usada na [CInternetSession::OpenURL](../../mfc/reference/cinternetsession-class.md#openurl).

```
BOOL AFXAPI AfxParseURLEx(
    LPCTSTR pstrURL,
    DWORD& dwServiceType,
    CString& strServer,
    CString& strObject,
    INTERNET_PORT& nPort,
    CString& strUsername,
    CString& strPassword,
    DWORD dwFlags = 0);
```

### <a name="parameters"></a>Parâmetros

*pstrURL*<br/>
Um ponteiro para uma cadeia de caracteres que contém a URL a ser analisado.

*dwServiceType*<br/>
Indica o tipo de serviço de Internet. Os valores possíveis são:

- AFX_INET_SERVICE_FTP

- AFX_INET_SERVICE_HTTP

- AFX_INET_SERVICE_HTTPS

- AFX_INET_SERVICE_GOPHER

- AFX_INET_SERVICE_FILE

- AFX_INET_SERVICE_MAILTO

- AFX_INET_SERVICE_NEWS

- AFX_INET_SERVICE_NNTP

- AFX_INET_SERVICE_TELNET

- AFX_INET_SERVICE_WAIS

- AFX_INET_SERVICE_MID

- AFX_INET_SERVICE_CID

- AFX_INET_SERVICE_PROSPERO

- AFX_INET_SERVICE_AFS

- AFX_INET_SERVICE_UNK

*strServer*<br/>
O primeiro segmento da URL após o tipo de serviço.

*strObject*<br/>
Um objeto que se refere a URL a (pode estar vazia).

*nPort*<br/>
Determinado a partir do servidor ou o objeto parte da URL, ou se ela existe.

*strUsername*<br/>
Uma referência a um `CString` objeto que contém o nome do usuário.

*strPassword*<br/>
Uma referência a um `CString` objeto que contém a senha do usuário.

*dwFlags*<br/>
Os sinalizadores de controle como analisar a URL. Pode ser uma combinação dos seguintes valores:

|Valor|Significado|
|-----------|-------------|
|ICU_DECODE|Converta caracteres sequências de escape % XX.|
|ICU_NO_ENCODE|Não converta caracteres não seguros em sequência de escape.|
|ICU_NO_META|Não remova as sequências de meta (por exemplo, "\". e "\"...) da URL.|
|ICU_ENCODE_SPACES_ONLY|Codifica apenas espaços.|
|ICU_BROWSER_MODE|Não codificar ou decodificar os caracteres '#' ou ' e não remova o espaço em branco à direita após '. Se esse valor não for especificado, a URL inteira é codificada e espaço em branco à direita é removido.|

Se você usar o padrão MFC, que não é nenhum sinalizador, a função converte todos os caracteres não seguros e sequências de metadados (como \\., \..., e \\...) escapar sequências.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a URL foi analisada com êxito; Caso contrário, 0 se ele está vazio ou não contém um tipo de serviço de Internet conhecido.

### <a name="remarks"></a>Comentários

Ele analisa uma cadeia de caracteres de URL e retorna o tipo de serviço e seus componentes, bem como fornecendo o nome e a senha do usuário. Os sinalizadores indicam caracteres não seguros como são tratadas.

> [!NOTE]
>  Para chamar essa função, seu projeto deve incluir AFXINET. H.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxinet.h

## <a name="afxgetinternethandletype"></a>  AfxGetInternetHandleType

Use essa função global para determinar o tipo de um identificador de Internet.

### <a name="syntax"></a>Sintaxe

  ```
DWORD AFXAPI AfxGetInternetHandleType(  HINTERNET hQuery );
```

### <a name="parameters"></a>Parâmetros

*hQuery*<br/>
Um identificador para uma consulta de Internet.

### <a name="return-value"></a>Valor de retorno

Qualquer um dos tipos de serviço de Internet definidos pelo WININET. H. Consulte a seção de comentários para obter uma lista desses serviços de Internet. Se o identificador for NULL ou não reconhecido, a função retornará AFX_INET_SERVICE_UNK.

### <a name="remarks"></a>Comentários

A lista a seguir inclui os tipos possíveis de Internet retornados por `AfxGetInternetHandleType`.

- INTERNET_HANDLE_TYPE_INTERNET

- INTERNET_HANDLE_TYPE_CONNECT_FTP

- INTERNET_HANDLE_TYPE_CONNECT_GOPHER

- INTERNET_HANDLE_TYPE_CONNECT_HTTP

- INTERNET_HANDLE_TYPE_FTP_FIND

- INTERNET_HANDLE_TYPE_FTP_FIND_HTML

- INTERNET_HANDLE_TYPE_FTP_FILE

- INTERNET_HANDLE_TYPE_FTP_FILE_HTML

- INTERNET_HANDLE_TYPE_GOPHER_FIND

- INTERNET_HANDLE_TYPE_GOPHER_FIND_HTML

- INTERNET_HANDLE_TYPE_GOPHER_FILE

- INTERNET_HANDLE_TYPE_GOPHER_FILE_HTML

- INTERNET_HANDLE_TYPE_HTTP_REQUEST

> [!NOTE]
>  Para chamar essa função, seu projeto deve incluir AFXINET. H.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxinet.h

## <a name="afxthrowinternetexception"></a>  AfxThrowInternetException

Gera uma exceção de Internet.

### <a name="syntax"></a>Sintaxe

```
   void AFXAPI AfxThrowInternetException(  DWORD dwContext,  DWORD dwError = 0 );
```

### <a name="parameters"></a>Parâmetros

*dwContext*<br/>
O identificador de contexto para a operação que causou o erro. O valor padrão de *dwContext* é especificado originalmente no [CInternetSession](cinternetsession-class.md) e é passado para [CInternetConnection](cinternetconnection-class.md)- e [CInternetFile](cinternetfile-class.md)-as classes derivadas. Para operações específicas realizadas em uma conexão ou um arquivo, você geralmente substituir o padrão com um *dwContext* de sua preferência. Esse valor é retornado, em seguida, para [CInternetSession::OnStatusCallback](cinternetsession-class.md#onstatuscallback) para identificar o status da operação específica.

*dwError*<br/>
O erro que causou a exceção.

### <a name="remarks"></a>Comentários

Você é responsável por determinar a causa, com base no código de erro do sistema operacional.

> [!NOTE]
>  Para chamar essa função, seu projeto deve incluir AFXINET. H.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxinet.h

## <a name="see-also"></a>Consulte também

[Macros e globais](mfc-macros-and-globals.md)<br/>
[Classe CInternetException](cinternetexception-class.md)<br/>
[AfxParseURL](internet-url-parsing-globals.md#afxparseurl)
