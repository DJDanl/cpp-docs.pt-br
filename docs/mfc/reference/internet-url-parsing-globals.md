---
title: Ajuda e globais de análise de URL da Internet
ms.date: 04/03/2017
helpviewer_keywords:
- parsing, URLs
- URLs, parsing
ms.assetid: 46c6384f-e4a6-4dbd-9196-219c19040ec5
ms.openlocfilehash: c7ce6eeee6deb4537d09e102b925a742ada04650
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88837158"
---
# <a name="internet-url-parsing-globals-and-helpers"></a>Ajuda e globais de análise de URL da Internet

Quando um cliente envia uma consulta ao servidor de Internet, você pode usar um dos globais de análise de URL para extrair informações sobre o cliente. As funções auxiliares fornecem outras funcionalidades da Internet.

## <a name="internet-url-parsing-globals"></a>Globais de análise de URL da Internet

|Nome|Descrição|
|-|-|
|[AfxParseURL](#afxparseurl)|Analisa uma cadeia de caracteres de URL e retorna o tipo de serviço e seus componentes.|
|[AfxParseURLEx](#afxparseurlex)|Analisa uma cadeia de caracteres de URL e retorna o tipo de serviço e seus componentes, bem como fornecer o nome de usuário e a senha.|

## <a name="other-internet-helpers"></a>Outros auxiliares da Internet

|Nome|Descrição|
|-|-|
|[AfxThrowInternetException](#afxthrowinternetexception)|Gera uma exceção relacionada à conexão com a Internet.|
|[AfxGetInternetHandleType](#afxgetinternethandletype)|Determina o tipo de um identificador da Internet.|

## <a name="afxparseurl"></a><a name="afxparseurl"></a> AfxParseURL

Esse global é usado em [CInternetSession:: OpenURL](../../mfc/reference/cinternetsession-class.md#openurl).

```
BOOL AFXAPI AfxParseURL(
    LPCTSTR pstrURL,
    DWORD& dwServiceType,
    CString& strServer,
    CString& strObject,
    INTERNET_PORT& nPort);
```

### <a name="parameters"></a>parâmetros

*pstrURL*<br/>
Um ponteiro para uma cadeia de caracteres que contém a URL a ser analisada.

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
Um objeto ao qual a URL se refere (pode estar vazio).

*nPort*<br/>
Determinado das partes do servidor ou do objeto da URL, se existir.

### <a name="return-value"></a>Valor Retornado

Diferente de zero se a URL foi analisada com êxito; caso contrário, 0 se estiver vazio ou não contiver um tipo de serviço de Internet conhecido.

### <a name="remarks"></a>Comentários

Ele analisa uma cadeia de caracteres de URL e retorna o tipo de serviço e seus componentes.

Por exemplo, `AfxParseURL` analisa URLs do formato *Service://Server/dir/dir/Object.ext:Port* e retorna seus componentes armazenados da seguinte maneira:

*strServer* = = "servidor"

*strObject* = = "/dir/dir/Object/Object.ext"

*nPort* = = #port

*dwServiceType* = = #service

> [!NOTE]
> Para chamar essa função, seu projeto deve incluir AFXINET. T.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AFXINET. h

## <a name="afxparseurlex"></a><a name="afxparseurlex"></a> AfxParseURLEx

Essa função global é a versão estendida do [AfxParseURL](#afxparseurl) e é usada em [CInternetSession:: OpenURL](../../mfc/reference/cinternetsession-class.md#openurl).

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

### <a name="parameters"></a>parâmetros

*pstrURL*<br/>
Um ponteiro para uma cadeia de caracteres que contém a URL a ser analisada.

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
Um objeto ao qual a URL se refere (pode estar vazio).

*nPort*<br/>
Determinado das partes do servidor ou do objeto da URL, se existir.

*strUsername*<br/>
Uma referência a um `CString` objeto que contém o nome do usuário.

*strPassword*<br/>
Uma referência a um `CString` objeto que contém a senha do usuário.

*dwFlags*<br/>
Os sinalizadores que controlam como analisar a URL. Pode ser uma combinação dos seguintes valores:

|Valor|Significado|
|-----------|-------------|
|ICU_DECODE|Converta% XX sequências de escape em caracteres.|
|ICU_NO_ENCODE|Não converta caracteres não seguros em sequência de escape.|
|ICU_NO_META|Não remova as metasequências (como "\." e "\...") da URL.|
|ICU_ENCODE_SPACES_ONLY|Codificar somente espaços.|
|ICU_BROWSER_MODE|Não codifique nem decodifique caracteres após ' # ' ou ' ' e não remova o espaço em branco à direita após ' '. Se esse valor não for especificado, toda a URL será codificada e o espaço em branco à direita será removido.|

Se você usar o padrão do MFC, que não é nenhum sinalizador, a função converterá todos os caracteres e metasequências não seguros (como \\ ., \... e \\ ...) em sequências de escape.

### <a name="return-value"></a>Valor Retornado

Diferente de zero se a URL foi analisada com êxito; caso contrário, 0 se estiver vazio ou não contiver um tipo de serviço de Internet conhecido.

### <a name="remarks"></a>Comentários

Ele analisa uma cadeia de caracteres de URL e retorna o tipo de serviço e seus componentes, bem como fornecer o nome e a senha do usuário. Os sinalizadores indicam como os caracteres não seguros são manipulados.

> [!NOTE]
> Para chamar essa função, seu projeto deve incluir AFXINET. T.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AFXINET. h

## <a name="afxgetinternethandletype"></a><a name="afxgetinternethandletype"></a> AfxGetInternetHandleType

Use essa função global para determinar o tipo de um identificador da Internet.

### <a name="syntax"></a>Sintaxe

  ```
DWORD AFXAPI AfxGetInternetHandleType(  HINTERNET hQuery );
```

### <a name="parameters"></a>parâmetros

*hQuery*<br/>
Um identificador para uma consulta à Internet.

### <a name="return-value"></a>Valor Retornado

Qualquer um dos tipos de serviço de Internet definidos pelo WININET. T. Consulte a seção comentários para obter uma lista desses serviços de Internet. Se o identificador for nulo ou não for reconhecido, a função retornará AFX_INET_SERVICE_UNK.

### <a name="remarks"></a>Comentários

A lista a seguir inclui possíveis tipos de Internet retornados pelo `AfxGetInternetHandleType` .

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
> Para chamar essa função, seu projeto deve incluir AFXINET. T.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXINET. h

## <a name="afxthrowinternetexception"></a><a name="afxthrowinternetexception"></a> AfxThrowInternetException

Gera uma exceção da Internet.

### <a name="syntax"></a>Sintaxe

```
   void AFXAPI AfxThrowInternetException(  DWORD dwContext,  DWORD dwError = 0 );
```

### <a name="parameters"></a>parâmetros

*dwContext*<br/>
O identificador de contexto para a operação que causou o erro. O valor padrão de *dwContext* é especificado originalmente em [CInternetSession](cinternetsession-class.md) e é passado para classes derivadas de [CInternetConnection](cinternetconnection-class.md)e [CInternetFile](cinternetfile-class.md). Para operações específicas executadas em uma conexão ou um arquivo, você geralmente substitui o padrão por um *dwContext* próprio. Esse valor é retornado para [CInternetSession:: OnStatusCallback](cinternetsession-class.md#onstatuscallback) para identificar o status da operação específica.

*dwError*<br/>
O erro que causou a exceção.

### <a name="remarks"></a>Comentários

Você é responsável por determinar a causa com base no código de erro do sistema operacional.

> [!NOTE]
> Para chamar essa função, seu projeto deve incluir AFXINET. T.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXINET. h

## <a name="see-also"></a>Confira também

[Macros e globais](mfc-macros-and-globals.md)<br/>
[Classe CInternetException](cinternetexception-class.md)<br/>
[AfxParseURL](internet-url-parsing-globals.md#afxparseurl)
