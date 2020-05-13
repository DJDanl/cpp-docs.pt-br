---
title: Análise de urls da Internet globales e ajudantes
ms.date: 04/03/2017
helpviewer_keywords:
- parsing, URLs
- URLs, parsing
ms.assetid: 46c6384f-e4a6-4dbd-9196-219c19040ec5
ms.openlocfilehash: 742b381ecb55c433d0f384174b7612fcc21e9716
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81356615"
---
# <a name="internet-url-parsing-globals-and-helpers"></a>Análise de urls da Internet globales e ajudantes

Quando um cliente envia uma consulta para o servidor da Internet, você pode usar um dos globals de análise de URL para extrair informações sobre o cliente. As funções auxiliares fornecem outras funcionalidades de internet.

## <a name="internet-url-parsing-globals"></a>Globais de análise de URL da Internet

|||
|-|-|
|[AfxParseURL](#afxparseurl)|Analisa uma seqüência de URL e retorna o tipo de serviço e seus componentes.|
|[AfxParseURLEx](#afxparseurlex)|Analisa uma seqüência de URL e retorna o tipo de serviço e seus componentes, além de fornecer o nome de usuário e senha.|

## <a name="other-internet-helpers"></a>Outros ajudantes de Internet

|||
|-|-|
|[AfxThrowInternetException](#afxthrowinternetexception)|Abre uma exceção relacionada à conexão com a internet.|
|[AfxGetInternetHandleType](#afxgetinternethandletype)|Determina o tipo de alça da Internet.|

## <a name="afxparseurl"></a><a name="afxparseurl"></a>Afxparseurl

Este global é usado em [CInternetSession::OpenURL](../../mfc/reference/cinternetsession-class.md#openurl).

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
Um ponteiro para uma seqüência contendo a URL a ser analisado.

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
O primeiro segmento da URL seguindo o tipo de serviço.

*strObject*<br/>
Um objeto a que a URL se refere (pode estar vazio).

*nPort*<br/>
Determinado a partir das partes servidor ou objeto da URL, se existir.

### <a name="return-value"></a>Valor retornado

Não zero se a URL foi analisado com sucesso; caso contrário, 0 se estiver vazio ou não contiver um tipo de serviço de Internet conhecido.

### <a name="remarks"></a>Comentários

Ele analisa uma seqüência de URL e retorna o tipo de serviço e seus componentes.

Por exemplo, `AfxParseURL` analisa URLs do formulário *service://server/dir/dir/object.ext:port* e retorna seus componentes armazenados da seguinte forma:

*strServer* == "servidor"

*strObject* == "/dir/dir/object/object.ext"

*nPorto* == #port

*dwServiceType* == #service

> [!NOTE]
> Para chamar essa função, seu projeto deve incluir AFXINET. H.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxinet.h

## <a name="afxparseurlex"></a><a name="afxparseurlex"></a>AfxParseURLEx

Esta função global é a versão estendida do [AfxParseURL](#afxparseurl) e é usada em [CInternetSession::OpenURL](../../mfc/reference/cinternetsession-class.md#openurl).

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
Um ponteiro para uma seqüência contendo a URL a ser analisado.

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
O primeiro segmento da URL seguindo o tipo de serviço.

*strObject*<br/>
Um objeto a que a URL se refere (pode estar vazio).

*nPort*<br/>
Determinado a partir das partes servidor ou objeto da URL, se existir.

*strUsername*<br/>
Uma referência `CString` a um objeto que contém o nome do usuário.

*strPassword*<br/>
Uma referência `CString` a um objeto contendo a senha do usuário.

*dwFlags*<br/>
Os sinalizadores controlam como analisar a URL. Pode ser uma combinação dos seguintes valores:

|Valor|Significado|
|-----------|-------------|
|ICU_DECODE|Converta seqüências de fuga %XX em caracteres.|
|ICU_NO_ENCODE|Não converta caracteres inseguros para escapar da seqüência.|
|ICU_NO_META|Não remova seqüências de meta (como "\ ." e "\.") da URL.|
|ICU_ENCODE_SPACES_ONLY|Apenas codificar espaços.|
|ICU_BROWSER_MODE|Não decodificar ou decodificar caracteres após '#' ou '', e não remova o espaço branco após ''. Se esse valor não for especificado, toda a URL será codificada e o espaço em branco de arrasto será removido.|

Se você usar o padrão MFC, que não é sinalizador, a função \\converterá todos os \\caracteres e seqüências de meta (como .,\ .., e ...) para escapar de seqüências.

### <a name="return-value"></a>Valor retornado

Não zero se a URL foi analisado com sucesso; caso contrário, 0 se estiver vazio ou não contiver um tipo de serviço de Internet conhecido.

### <a name="remarks"></a>Comentários

Ele analisa uma seqüência de URL e retorna o tipo de serviço e seus componentes, além de fornecer o nome e a senha do usuário. As bandeiras indicam como os caracteres inseguros são tratados.

> [!NOTE]
> Para chamar essa função, seu projeto deve incluir AFXINET. H.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxinet.h

## <a name="afxgetinternethandletype"></a><a name="afxgetinternethandletype"></a>AfxGetInternetHandleType

Use esta função global para determinar o tipo de alça da Internet.

### <a name="syntax"></a>Sintaxe

  ```
DWORD AFXAPI AfxGetInternetHandleType(  HINTERNET hQuery );
```

### <a name="parameters"></a>Parâmetros

*hQuery*<br/>
Uma alça para uma consulta na Internet.

### <a name="return-value"></a>Valor retornado

Qualquer um dos tipos de serviços de Internet definidos pelo WININET. H. Consulte a seção Observações para obter uma lista desses serviços de Internet. Se a alça for NULA ou não for reconhecida, a função retorna AFX_INET_SERVICE_UNK.

### <a name="remarks"></a>Comentários

A lista a seguir inclui possíveis `AfxGetInternetHandleType`tipos de Internet retornados por .

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
> Para chamar essa função, seu projeto deve incluir AFXINET. H.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxinet.h

## <a name="afxthrowinternetexception"></a><a name="afxthrowinternetexception"></a>Afxthrowinternetexception

Abre uma exceção na Internet.

### <a name="syntax"></a>Sintaxe

```
   void AFXAPI AfxThrowInternetException(  DWORD dwContext,  DWORD dwError = 0 );
```

### <a name="parameters"></a>Parâmetros

*Dwcontext*<br/>
O identificador de contexto para a operação que causou o erro. O valor padrão do *dwContext* é especificado originalmente no [CInternetSession](cinternetsession-class.md) e é passado para [cInternetConnection](cinternetconnection-class.md)- e [CInternetFile](cinternetfile-class.md)-drived classes. Para operações específicas realizadas em uma conexão ou um arquivo, você geralmente anula o padrão com um *dwContext* de sua autoria. Esse valor é então devolvido ao [CInternetSession::OnStatusCallback](cinternetsession-class.md#onstatuscallback) para identificar o status da operação específica.

*Dwerror*<br/>
O erro que causou a exceção.

### <a name="remarks"></a>Comentários

Você é responsável por determinar a causa com base no código de erro do sistema operacional.

> [!NOTE]
> Para chamar essa função, seu projeto deve incluir AFXINET. H.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxinet.h

## <a name="see-also"></a>Confira também

[Macros e globais](mfc-macros-and-globals.md)<br/>
[Classe CInternetException](cinternetexception-class.md)<br/>
[AfxParseURL](internet-url-parsing-globals.md#afxparseurl)
