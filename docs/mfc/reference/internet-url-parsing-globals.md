---
title: Globais de análise de URL da Internet e os auxiliares | Microsoft Docs
ms.custom: ''
ms.date: 04/03/2017
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- vc.mfc.macros.isapi
dev_langs:
- C++
helpviewer_keywords:
- parsing, URLs
- URLs, parsing
ms.assetid: 46c6384f-e4a6-4dbd-9196-219c19040ec5
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 02b7ea1a6d22d3e16230acafa25c53f8748a825a
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33374788"
---
# <a name="internet-url-parsing-globals-and-helpers"></a>Auxiliares e globais de análise de URL da Internet
Quando um cliente envia uma consulta para o servidor de Internet, você pode usar uma das URLs globais de análise para extrair informações sobre o cliente. As funções auxiliares fornecem outros recursos da internet.
  
## <a name="internet-url-parsing-globals"></a>Globais de análise de URL da Internet  
  
|||  
|-|-|  
|[AfxParseURL](#afxparseurl)|Analisa uma cadeia de caracteres de URL e retorna o tipo de serviço e seus componentes.|  
|[AfxParseURLEx](#afxparseurlex)|Analisa uma cadeia de caracteres de URL e retorna o tipo de serviço e seus componentes, bem como fornecer o nome de usuário e senha.|  

## <a name="other-internet-helpers"></a>Outros auxiliares da Internet
|||
|-|-|
|[AfxThrowInternetException](#afxthrowinternetexception)|Gera uma exceção relacionada para a conexão de internet.|
|[AfxGetInternetHandleType](#afxgetinternethandletype)|Determina o tipo de um identificador de Internet.|
  
##  <a name="afxparseurl"></a>  AfxParseURL  
 Nesse global é usado em [CInternetSession::OpenURL](../../mfc/reference/cinternetsession-class.md#openurl).  
  
```   
BOOL AFXAPI AfxParseURL(
    LPCTSTR pstrURL,  
    DWORD& dwServiceType,  
    CString& strServer,  
    CString& strObject,  
    INTERNET_PORT& nPort); 
```  
  
### <a name="parameters"></a>Parâmetros  
 *pstrURL*  
 Um ponteiro para uma cadeia de caracteres que contém a URL a ser analisado.  
  
 `dwServiceType`  
 Indica o tipo de serviço de Internet. Os valores possíveis são:  
  
-   AFX_INET_SERVICE_FTP  
  
-   AFX_INET_SERVICE_HTTP  
  
-   AFX_INET_SERVICE_HTTPS  
  
-   AFX_INET_SERVICE_GOPHER  
  
-   AFX_INET_SERVICE_FILE  
  
-   AFX_INET_SERVICE_MAILTO  
  
-   AFX_INET_SERVICE_NEWS  
  
-   AFX_INET_SERVICE_NNTP  
  
-   AFX_INET_SERVICE_TELNET  
  
-   AFX_INET_SERVICE_WAIS  
  
-   AFX_INET_SERVICE_MID  
  
-   AFX_INET_SERVICE_CID  
  
-   AFX_INET_SERVICE_PROSPERO  
  
-   AFX_INET_SERVICE_AFS  
  
-   AFX_INET_SERVICE_UNK  
  
 `strServer`  
 O primeiro segmento da URL que o tipo de serviço a seguir.  
  
 `strObject`  
 Um objeto que se refere a URL para (pode estar vazia).  
  
 `nPort`  
 Determinado a partir do servidor ou o objeto partes da URL, ou se ela existe.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a URL foi analisada com êxito. Caso contrário, 0 se ele está vazio ou não contém um tipo de serviço de Internet conhecido.  
  
### <a name="remarks"></a>Comentários  
 Ele analisa uma cadeia de caracteres de URL e retorna o tipo de serviço e seus componentes.  
  
 Por exemplo, `AfxParseURL` analisa URLs do formulário **service://server/dir/dir/object.ext:port** e retorna seus componentes armazenados da seguinte maneira:  
  
 `strServer` = = "server"  
  
 `strObject` = = "/ dir/dir/object/object.ext"  
  
 `nPort` = = #port  
  
 `dwServiceType` = = #service  
  
> [!NOTE]
>  Para chamar esta função, o projeto deve incluir AFXINET. H.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxinet.h  
  
##  <a name="afxparseurlex"></a>  AfxParseURLEx  
 Esta é a versão estendida do [AfxParseURL](#afxparseurl) e é usado em [CInternetSession::OpenURL](../../mfc/reference/cinternetsession-class.md#openurl).  
  
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
 *pstrURL*  
 Um ponteiro para uma cadeia de caracteres que contém a URL a ser analisado.  
  
 `dwServiceType`  
 Indica o tipo de serviço de Internet. Os valores possíveis são:  
  
-   AFX_INET_SERVICE_FTP  
  
-   AFX_INET_SERVICE_HTTP  
  
-   AFX_INET_SERVICE_HTTPS  
  
-   AFX_INET_SERVICE_GOPHER  
  
-   AFX_INET_SERVICE_FILE  
  
-   AFX_INET_SERVICE_MAILTO  
  
-   AFX_INET_SERVICE_NEWS  
  
-   AFX_INET_SERVICE_NNTP  
  
-   AFX_INET_SERVICE_TELNET  
  
-   AFX_INET_SERVICE_WAIS  
  
-   AFX_INET_SERVICE_MID  
  
-   AFX_INET_SERVICE_CID  
  
-   AFX_INET_SERVICE_PROSPERO  
  
-   AFX_INET_SERVICE_AFS  
  
-   AFX_INET_SERVICE_UNK  
  
 `strServer`  
 O primeiro segmento da URL que o tipo de serviço a seguir.  
  
 `strObject`  
 Um objeto que se refere a URL para (pode estar vazia).  
  
 `nPort`  
 Determinado a partir do servidor ou o objeto partes da URL, ou se ela existe.  
  
 *strUsername*  
 Uma referência a um `CString` objeto que contém o nome do usuário.  
  
 `strPassword`  
 Uma referência a um `CString` objeto que contém a senha do usuário.  
  
 `dwFlags`  
 Os sinalizadores de controle como analisar a URL. Pode ser uma combinação dos seguintes valores:  
  
|Valor|Significado|  
|-----------|-------------|  
|**ICU_DECODE**|Converta caracteres sequências de escape % XX.|  
|**ICU_NO_ENCODE**|Não faça a conversão de caracteres não seguros para a sequência de escape.|  
|**ICU_NO_META**|Não remova as sequências de metadados (por exemplo, "\". e "\"...) da URL.|  
|**ICU_ENCODE_SPACES_ONLY**|Codifica apenas espaços.|  
|**ICU_BROWSER_MODE**|Não codificar ou decodificar caracteres após '#' ou ' e não remova o espaço em branco à direita após '. Se esse valor não for especificado, a URL inteira é codificada e espaço em branco à direita é removido.|  
  
 Se você usar o padrão MFC, que não é nenhum sinalizador, a função converte todos os caracteres não seguros e sequências de metadados (como \\., \..., e \\...) escapar sequências.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a URL foi analisada com êxito. Caso contrário, 0 se ele está vazio ou não contém um tipo de serviço de Internet conhecido.  
  
### <a name="remarks"></a>Comentários  
 Ele analisa uma cadeia de caracteres de URL e retorna o tipo de serviço e seus componentes, bem como fornecer o nome e a senha do usuário. Os sinalizadores indicam como inseguros caracteres são tratados.  
  
> [!NOTE]
>  Para chamar esta função, o projeto deve incluir AFXINET. H.  

### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxinet.h  
    
## <a name="see-also"></a>Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)
 
## <a name="afxgetinternethandletype"></a>  AfxGetInternetHandleType
Use esta função global para determinar o tipo de um identificador de Internet.  
   
### <a name="syntax"></a>Sintaxe  
  ```
DWORD AFXAPI AfxGetInternetHandleType(  HINTERNET hQuery );  
```
### <a name="parameters"></a>Parâmetros  
 `hQuery`  
 Um identificador para uma consulta de Internet.  
   
### <a name="return-value"></a>Valor de retorno  
 Nenhum dos tipos de serviços de Internet definidos pelo WININET. H. Consulte a seção de comentários para obter uma lista desses serviços de Internet. Se o identificador é nulo ou não reconhecido, a função retornará AFX_INET_SERVICE_UNK.  
   
### <a name="remarks"></a>Comentários  
 A lista a seguir inclui os possíveis tipos de Internet retornados por `AfxGetInternetHandleType`.  
  
-   INTERNET_HANDLE_TYPE_INTERNET  
  
-   INTERNET_HANDLE_TYPE_CONNECT_FTP  
  
-   INTERNET_HANDLE_TYPE_CONNECT_GOPHER  
  
-   INTERNET_HANDLE_TYPE_CONNECT_HTTP  
  
-   INTERNET_HANDLE_TYPE_FTP_FIND  
  
-   INTERNET_HANDLE_TYPE_FTP_FIND_HTML  
  
-   INTERNET_HANDLE_TYPE_FTP_FILE  
  
-   INTERNET_HANDLE_TYPE_FTP_FILE_HTML  
  
-   INTERNET_HANDLE_TYPE_GOPHER_FIND  
  
-   INTERNET_HANDLE_TYPE_GOPHER_FIND_HTML  
  
-   INTERNET_HANDLE_TYPE_GOPHER_FILE  
  
-   INTERNET_HANDLE_TYPE_GOPHER_FILE_HTML  
  
-   INTERNET_HANDLE_TYPE_HTTP_REQUEST  
  
> [!NOTE]
>  Para chamar esta função, o projeto deve incluir AFXINET. H.  
   
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxinet.h  
   
### <a name="see-also"></a>Consulte também  
 [Macros e globais](mfc-macros-and-globals.md)   
 [AfxParseURL](internet-url-parsing-globals.md#afxparseurl)
 
## <a name="afxthrowinternetexception"></a>  AfxThrowInternetException
Gera uma exceção de Internet.  
   
### <a name="syntax"></a>Sintaxe    
```
   void AFXAPI AfxThrowInternetException(  DWORD dwContext,  DWORD dwError = 0 );  
```
### <a name="parameters"></a>Parâmetros  
 `dwContext`  
 O identificador de contexto para a operação que causou o erro. O valor padrão de `dwContext` especificada originalmente no [CInternetSession](cinternetsession-class.md) e é passado para [CInternetConnection](cinternetconnection-class.md)- e [CInternetFile](cinternetfile-class.md)-classes derivadas. Para operações específicas executadas em uma conexão ou um arquivo, você geralmente substituir o padrão com um `dwContext` de sua preferência. Em seguida, esse valor é retornado para [CInternetSession::OnStatusCallback](cinternetsession-class.md#onstatuscallback) para identificar o status da operação específica. 
  
 `dwError`  
 O erro que causou a exceção.  
   
### <a name="remarks"></a>Comentários  
 Você é responsável por determinar a causa com base no código de erro do sistema operacional.  
  
> [!NOTE]
>  Para chamar esta função, o projeto deve incluir AFXINET. H.  
   
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxinet.h  
   
### <a name="see-also"></a>Consulte também  
 [Macros e globais](mfc-macros-and-globals.md)   
 [Classe CInternetException](cinternetexception-class.md)   
 [THROW](#throw)
 

