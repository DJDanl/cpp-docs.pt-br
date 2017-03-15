---
title: "Globais de análise de URL da Internet | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.mfc.macros.isapi
dev_langs:
- C++
helpviewer_keywords:
- parsing, URLs
- URLs, parsing
ms.assetid: 46c6384f-e4a6-4dbd-9196-219c19040ec5
caps.latest.revision: 14
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 17a158366f94d27b7a46917282425d652e6b9042
ms.openlocfilehash: 3aec259acae2f5e9c9b65ac4e5c898ca57ff3d52
ms.lasthandoff: 02/25/2017

---
# <a name="internet-url-parsing-globals"></a>Globais de análise de URL da Internet
Quando um cliente envia uma consulta ao servidor da Internet, você pode usar uma das URLs globais de análise para extrair informações sobre o cliente.  
  
### <a name="internet-url-parsing-globals"></a>Globais de análise de URL da Internet  
  
|||  
|-|-|  
|[AfxParseURL](#afxparseurl)|Analisa uma cadeia de caracteres de URL e retorna o tipo de serviço e seus componentes.|  
|[AfxParseURLEx](#afxparseurlex)|Analisa uma cadeia de caracteres de URL e retorna o tipo de serviço e seus componentes, bem como fornecendo o nome de usuário e senha.|  
  
##  <a name="a-nameafxparseurla--afxparseurl"></a><a name="afxparseurl"></a>AfxParseURL  
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
 O primeiro segmento da URL após o tipo de serviço.  
  
 `strObject`  
 Um objeto que se refere a URL para (pode estar vazia).  
  
 `nPort`  
 Determinada a partir do servidor ou o objeto parte da URL, ou se ela existe.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a URL foi analisada com êxito. Caso contrário, 0 se ele está vazio ou não contém um tipo de serviço de Internet conhecido.  
  
### <a name="remarks"></a>Comentários  
 Ele analisa uma cadeia de caracteres de URL e retorna o tipo de serviço e seus componentes.  
  
 Por exemplo, `AfxParseURL` analisa as URLs do formulário **service://server/dir/dir/object.ext:port** e retorna seus componentes armazenados da seguinte maneira:  
  
 `strServer`= = "server"  
  
 `strObject`= = "/ dir/dir/object/object.ext"  
  
 `nPort`= = #port  
  
 `dwServiceType`= = #service  
  
> [!NOTE]
>  Para chamar essa função, seu projeto deve incluir AFXINET. H.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxinet.h  
  
##  <a name="a-nameafxparseurlexa--afxparseurlex"></a><a name="afxparseurlex"></a>AfxParseURLEx  
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
 O primeiro segmento da URL após o tipo de serviço.  
  
 `strObject`  
 Um objeto que se refere a URL para (pode estar vazia).  
  
 `nPort`  
 Determinada a partir do servidor ou o objeto parte da URL, ou se ela existe.  
  
 *strUsername*  
 Uma referência a um `CString` objeto que contém o nome do usuário.  
  
 `strPassword`  
 Uma referência a um `CString` objeto que contém a senha do usuário.  
  
 `dwFlags`  
 Os sinalizadores de controle como analisar a URL. Pode ser uma combinação dos seguintes valores:  
  
|Valor|Significado|  
|-----------|-------------|  
|**ICU_DECODE**|Converta as sequências de escape XX % caracteres.|  
|**ICU_NO_ENCODE**|Não faça a conversão de caracteres não seguros em sequência de escape.|  
|**ICU_NO_META**|Não remova as sequências de metadados (como "\". e "\"...) da URL.|  
|**ICU_ENCODE_SPACES_ONLY**|Codifica somente espaços.|  
|**ICU_BROWSER_MODE**|Não codificar ou decodificar caracteres após '#' ou ' e não remova o espaço em branco à direita após '. Se esse valor não for especificado, a URL inteira é codificada e espaço em branco à direita será removido.|  
  
 Se você usar o padrão do MFC, que é sem sinalizadores, a função converte todos os caracteres não seguros e sequências de metadados (como \\., \..., e \\...) escapar sequências.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a URL foi analisada com êxito. Caso contrário, 0 se ele está vazio ou não contém um tipo de serviço de Internet conhecido.  
  
### <a name="remarks"></a>Comentários  
 Ele analisa uma cadeia de caracteres de URL e retorna o tipo de serviço e seus componentes, bem como fornecendo o nome e a senha do usuário. Os sinalizadores indicam caracteres como inseguros são tratadas.  
  
> [!NOTE]
>  Para chamar essa função, seu projeto deve incluir AFXINET. H.  

### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxinet.h  
    
## <a name="see-also"></a>Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)

