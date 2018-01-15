---
title: Classe do cUrl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CUrl
- ATLUTIL/ATL::CUrl
- ATLUTIL/ATL::CUrl::CUrl
- ATLUTIL/ATL::CUrl::Canonicalize
- ATLUTIL/ATL::CUrl::Clear
- ATLUTIL/ATL::CUrl::CrackUrl
- ATLUTIL/ATL::CUrl::CreateUrl
- ATLUTIL/ATL::CUrl::GetExtraInfo
- ATLUTIL/ATL::CUrl::GetExtraInfoLength
- ATLUTIL/ATL::CUrl::GetHostName
- ATLUTIL/ATL::CUrl::GetHostNameLength
- ATLUTIL/ATL::CUrl::GetPassword
- ATLUTIL/ATL::CUrl::GetPasswordLength
- ATLUTIL/ATL::CUrl::GetPortNumber
- ATLUTIL/ATL::CUrl::GetScheme
- ATLUTIL/ATL::CUrl::GetSchemeName
- ATLUTIL/ATL::CUrl::GetSchemeNameLength
- ATLUTIL/ATL::CUrl::GetUrlLength
- ATLUTIL/ATL::CUrl::GetUrlPath
- ATLUTIL/ATL::CUrl::GetUrlPathLength
- ATLUTIL/ATL::CUrl::GetUserName
- ATLUTIL/ATL::CUrl::GetUserNameLength
- ATLUTIL/ATL::CUrl::SetExtraInfo
- ATLUTIL/ATL::CUrl::SetHostName
- ATLUTIL/ATL::CUrl::SetPassword
- ATLUTIL/ATL::CUrl::SetPortNumber
- ATLUTIL/ATL::CUrl::SetScheme
- ATLUTIL/ATL::CUrl::SetSchemeName
- ATLUTIL/ATL::CUrl::SetUrlPath
- ATLUTIL/ATL::CUrl::SetUserName
dev_langs: C++
helpviewer_keywords: CUrl class
ms.assetid: b3894d34-47b9-4961-9719-4197153793da
caps.latest.revision: "22"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: eb60fcef5fdfd30b4121f5c2277667829772dcd6
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="curl-class"></a>Classe de rotação
Essa classe representa uma URL. Ele permite que você manipule cada elemento da URL, independentemente de outras pessoas se uma URL existente de análise de cadeia de caracteres ou criando uma cadeia de caracteres a partir do zero.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CUrl
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CUrl::CUrl](#curl)|O construtor.|  
|[CUrl:: ~ CUrl](#dtor)|O destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CUrl::Canonicalize](#canonicalize)|Chame este método para converter a cadeia de caracteres de URL em forma canônica.|  
|[CUrl::Clear](#clear)|Chame este método para limpar todos os campos de URL.|  
|[CUrl::CrackUrl](#crackurl)|Chame esse método para decodificar e analisar a URL.|  
|[CUrl::CreateUrl](#createurl)|Chame esse método para criar a URL.|  
|[CUrl::GetExtraInfo](#getextrainfo)|Chame esse método para obter informações adicionais (como *texto* ou # *texto*) da URL.|  
|[CUrl::GetExtraInfoLength](#getextrainfolength)|Chame esse método para obter o comprimento das informações adicionais (como *texto* ou # *texto*) para recuperar da URL.|  
|[CUrl::GetHostName](#gethostname)|Chame este método para obter o nome do host da URL.|  
|[CUrl::GetHostNameLength](#gethostnamelength)|Chame esse método para obter o comprimento do nome do host.|  
|[CUrl::GetPassword](#getpassword)|Chame este método para obter a senha da URL.|  
|[CUrl::GetPasswordLength](#getpasswordlength)|Chame esse método para obter o comprimento da senha.|  
|[CUrl::GetPortNumber](#getportnumber)|Chame este método para obter o número da porta em termos de ATL_URL_PORT.|  
|[CUrl::GetScheme](#getscheme)|Chame este método para obter o esquema de URL.|  
|[CUrl::GetSchemeName](#getschemename)|Chame este método para obter o nome do esquema de URL.|  
|[CUrl::GetSchemeNameLength](#getschemenamelength)|Chame esse método para obter o comprimento do nome do esquema de URL.|  
|[CUrl::GetUrlLength](#geturllength)|Chame este método para obter o comprimento da URL.|  
|[CUrl::GetUrlPath](#geturlpath)|Chame este método para obter o caminho da URL.|  
|[CUrl::GetUrlPathLength](#geturlpathlength)|Chame esse método para obter o comprimento de caminho de URL.|  
|[CUrl::GetUserName](#getusername)|Chame este método para obter o nome de usuário da URL.|  
|[CUrl::GetUserNameLength](#getusernamelength)|Chame esse método para obter o comprimento do nome de usuário.|  
|[CUrl::SetExtraInfo](#setextrainfo)|Chame este método para definir as informações adicionais (como *texto* ou # *texto*) da URL.|  
|[CUrl::SetHostName](#sethostname)|Chame este método para definir o nome do host.|  
|[CUrl::SetPassword](#setpassword)|Chame este método para definir a senha.|  
|[CUrl::SetPortNumber](#setportnumber)|Chame este método para definir o número da porta em termos de ATL_URL_PORT.|  
|[CUrl::SetScheme](#setscheme)|Chame este método para definir o esquema de URL.|  
|[CUrl::SetSchemeName](#setschemename)|Chame este método para definir o nome do esquema de URL.|  
|[CUrl::SetUrlPath](#seturlpath)|Chame este método para definir o caminho da URL.|  
|[CUrl::SetUserName](#setusername)|Chame este método para definir o nome de usuário.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CUrl::operator =](#operator_eq)|Atribui especificado `CUrl` objeto atual `CUrl` objeto.|  
  
## <a name="remarks"></a>Comentários  
 `CUrl`permite que você manipule os campos de uma URL, como o número de porta ou caminho. `CUrl`Entenda as URLs da seguinte forma:  
  
 \<Esquema > ://\<nome de usuário >:\<senha > @\<HostName >:\<PortNumber > /\<UrlPath >\<ExtraInfo >  
  
 (Alguns campos são opcionais.) Por exemplo, considere esta URL:  
  
 http://someone:secret@www.microsoft.com:80/visualc/stuff.htm#contents  
  
 [CUrl::CrackUrl](#crackurl) analisa-lo da seguinte maneira:  
  
-   Esquema: "http" ou [ATL_URL_SCHEME_HTTP](atl-url-scheme-enum.md)  
  
-   Nome de usuário: "outra"  
  
-   Senha: "segredo"  
  
-   Nome do host: "www.microsoft.com"  
  
-   PortNumber: 80  
  
-   UrlPath: "visualc/stuff.htm"  
  
-   ExtraInfo: "#contents"  
  
 Para manipular o campo UrlPath (por exemplo), você usaria [GetUrlPath](#geturlpath), [GetUrlPathLength](#geturlpathlength), e [SetUrlPath](#seturlpath). Você usaria [CreateUrl](#createurl) para criar a cadeia de caracteres de URL completa.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlutil.h  
  
##  <a name="canonicalize"></a>CUrl::Canonicalize  
 Chame este método para converter a cadeia de caracteres de URL em forma canônica.  
  
```
inline BOOL Canonicalize(DWORD dwFlags = 0) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwFlags`  
 Os sinalizadores que controlam a conversão em formato canônico. Se nenhum sinalizador for especificado ( `dwFlags` = 0), o método converte todos os caracteres não seguros e sequências de metadados (como \\., \..., e \\...) escapar sequências. `dwFlags`pode ser um dos seguintes valores:  
  
-   ATL_URL_BROWSER_MODE: Não codificar ou decodificar caracteres depois de "#" ou "" e não remova o espaço em branco à direita após "". Se esse valor não for especificado, a URL inteira é codificada e espaço em branco à direita é removido.  
  
-   ATL_URL _DECODE: converte todas as sequências XX % em caracteres, incluindo as sequências de escape, antes que a URL é analisada.  
  
-   ATL_URL _ENCODE_PERCENT: codifica qualquer sinais de porcentagem encontrados. Por padrão, os sinais de porcentagem não são codificados.  
  
-   ATL_URL _ENCODE_SPACES_ONLY: codifica apenas espaços.  
  
-   ATL_URL _NO_ENCODE: não converte os caracteres não seguros para sequências de escape.  
  
-   ATL_URL _NO_META: não remove as sequências de metadados (como "."e"...") da URL.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna verdadeiro no caso de sucesso, falso em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Conversão em formato canônico envolve a conversão de caracteres inseguros e espaços para sequências de escape.  
  
##  <a name="clear"></a>CUrl::Clear  
 Chame este método para limpar todos os campos de URL.  
  
```
inline void Clear() throw();
```  
  
##  <a name="crackurl"></a>CUrl::CrackUrl  
 Chame esse método para decodificar e analisar a URL.  
  
```
BOOL CrackUrl(LPCTSTR lpszUrl, DWORD dwFlags = 0) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszUrl`  
 A URL.  
  
 `dwFlags`  
 Especifique ATL_URL_DECODE ou ATL_URL_ESCAPE para converter todos os caracteres de escape em `lpszUrl` para os valores reais após a análise. (Antes do Visual C++ 2005, ATL_URL_DECODE convertido todos os caracteres de escape antes da análise.)  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna verdadeiro no caso de sucesso, falso em caso de falha.  
  
##  <a name="createurl"></a>CUrl::CreateUrl  
 Esse método constrói uma cadeia de caracteres de URL de campos de componente de um objeto rotação.  
  
```
inline BOOL CreateUrl(
    LPTSTR lpszUrl,
    DWORD* pdwMaxLength,
    DWORD dwFlags = 0) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpszUrl*  
 Um buffer de cadeia de caracteres para manter a cadeia de caracteres de URL completa.  
  
 `pdwMaxLength`  
 O comprimento máximo do *lpszUrl* buffer de cadeia de caracteres.  
  
 `dwFlags`  
 Especifique ATL_URL_ESCAPE para converter todos os caracteres de escape em *lpszUrl* para os valores reais.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna verdadeiro no caso de sucesso, falso em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Esse método acrescenta seus campos individuais para construir a cadeia de caracteres de URL completa usando o seguinte formato:  
  
 **\<esquema > ://\<usuário >:\<passar > @\<domínio >:\<porta >\<caminho >\<extra >**  
  
 Ao chamar esse método, o `pdwMaxLength` parâmetro inicialmente deve conter o comprimento máximo do buffer de cadeia de caracteres referenciado pelo *lpszUrl* parâmetro. O valor de `pdwMaxLength` parâmetro será atualizado com o comprimento real da cadeia de caracteres de URL.  
  
### <a name="example"></a>Exemplo  
 Este exemplo demonstra a criação de um objeto de ondulação e recuperar sua cadeia de caracteres de URL  
  
 [!code-cpp[NVC_ATL_Utilities#133](../../atl/codesnippet/cpp/curl-class_1.cpp)]  
  
##  <a name="curl"></a>CUrl::CUrl  
 O construtor.  
  
```
CUrl() throw();
CUrl(const CUrl& urlThat) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `urlThat`  
 O `CUrl` objeto a ser copiado para criar a URL.  
  
##  <a name="dtor"></a>CUrl:: ~ CUrl  
 O destruidor.  
  
```
~CUrl() throw();
```  
  
##  <a name="getextrainfo"></a>CUrl::GetExtraInfo  
 Chame esse método para obter informações adicionais (como *texto* ou # *texto*) da URL.  
  
```
inline LPCTSTR GetExtraInfo() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna uma cadeia de caracteres que contém as informações adicionais.  
  
##  <a name="getextrainfolength"></a>CUrl::GetExtraInfoLength  
 Chame esse método para obter o comprimento das informações adicionais (como *texto* ou # *texto*) para recuperar da URL.  
  
```
inline DWORD GetExtraInfoLength() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o comprimento da cadeia de caracteres que contém as informações adicionais.  
  
##  <a name="gethostname"></a>CUrl::GetHostName  
 Chame este método para obter o nome do host da URL.  
  
```
inline LPCTSTR GetHostName() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o nome do host.  
  
##  <a name="gethostnamelength"></a>CUrl::GetHostNameLength  
 Chame esse método para obter o comprimento do nome do host.  
  
```
inline DWORD GetHostNameLength() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o host do comprimento do nome.  
  
##  <a name="getpassword"></a>CUrl::GetPassword  
 Chame este método para obter a senha da URL.  
  
```
inline LPCTSTR GetPassword() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a senha.  
  
##  <a name="getpasswordlength"></a>CUrl::GetPasswordLength  
 Chame esse método para obter o comprimento da senha.  
  
```
inline DWORD GetPasswordLength() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o comprimento da senha.  
  
##  <a name="getportnumber"></a>CUrl::GetPortNumber  
 Chame este método para obter o número da porta.  
  
```
inline ATL_URL_PORT GetPortNumber() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o número da porta.  
  
##  <a name="getscheme"></a>CUrl::GetScheme  
 Chame este método para obter o esquema de URL.  
  
```
inline ATL_URL_SCHEME GetScheme() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o [ATL_URL_SCHEME](atl-url-scheme-enum.md) valor que descreve o esquema da URL.  
  
##  <a name="getschemename"></a>CUrl::GetSchemeName  
 Chame este método para obter o nome do esquema de URL.  
  
```
inline LPCTSTR GetSchemeName() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o nome do esquema de URL (por exemplo, "http" ou "ftp").  
  
##  <a name="getschemenamelength"></a>CUrl::GetSchemeNameLength  
 Chame esse método para obter o comprimento do nome do esquema de URL.  
  
```
inline DWORD GetSchemeNameLength() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o comprimento de nome de esquema de URL.  
  
##  <a name="geturllength"></a>CUrl::GetUrlLength  
 Chame este método para obter o comprimento da URL.  
  
```
inline DWORD GetUrlLength() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o comprimento da URL.  
  
##  <a name="geturlpath"></a>CUrl::GetUrlPath  
 Chame este método para obter o caminho da URL.  
  
```
inline LPCTSTR GetUrlPath() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o caminho da URL.  
  
##  <a name="geturlpathlength"></a>CUrl::GetUrlPathLength  
 Chame esse método para obter o comprimento de caminho de URL.  
  
```
inline DWORD GetUrlPathLength() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o comprimento do caminho de URL.  
  
##  <a name="getusername"></a>CUrl::GetUserName  
 Chame este método para obter o nome de usuário da URL.  
  
```
inline LPCTSTR GetUserName() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o nome de usuário.  
  
##  <a name="getusernamelength"></a>CUrl::GetUserNameLength  
 Chame esse método para obter o comprimento do nome de usuário.  
  
```
inline DWORD GetUserNameLength() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o comprimento do nome de usuário.  
  
##  <a name="operator_eq"></a>CUrl::operator =  
 Atribui especificado `CUrl` objeto atual `CUrl` objeto.  
  
```
CUrl& operator= (const CUrl& urlThat) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `urlThat`  
 O `CUrl` objeto a ser copiado para o objeto atual.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna uma referência ao objeto atual.  
  
##  <a name="setextrainfo"></a>CUrl::SetExtraInfo  
 Chame este método para definir as informações adicionais (como *texto* ou # *texto*) da URL.  
  
```
inline BOOL SetExtraInfo(LPCTSTR lpszInfo) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpszInfo*  
 A cadeia de caracteres que contém as informações extras para incluir na URL.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna verdadeiro no caso de sucesso, falso em caso de falha.  
  
##  <a name="sethostname"></a>CUrl::SetHostName  
 Chame este método para definir o nome do host.  
  
```
inline BOOL SetHostName(LPCTSTR lpszHost) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszHost`  
 O nome do host.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna verdadeiro no caso de sucesso, falso em caso de falha.  
  
##  <a name="setpassword"></a>CUrl::SetPassword  
 Chame este método para definir a senha.  
  
```
inline BOOL SetPassword(LPCTSTR lpszPass) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpszPass*  
 A senha.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna verdadeiro no caso de sucesso, falso em caso de falha.  
  
##  <a name="setportnumber"></a>CUrl::SetPortNumber  
 Chame este método para definir o número de porta.  
  
```
inline BOOL SetPortNumber(ATL_URL_PORT nPrt) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *nPrt*  
 O número da porta.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna verdadeiro no caso de sucesso, falso em caso de falha.  
  
##  <a name="setscheme"></a>CUrl::SetScheme  
 Chame este método para definir o esquema de URL.  
  
```
inline BOOL SetScheme(ATL_URL_SCHEME nScheme) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `nScheme`  
 Uma da [ATL_URL_SCHEME](atl-url-scheme-enum.md) valores para o esquema.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna verdadeiro no caso de sucesso, falso em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Você também pode definir o esquema por nome (consulte [CUrl::SetSchemeName](#setschemename)).  
  
##  <a name="setschemename"></a>CUrl::SetSchemeName  
 Chame este método para definir o nome do esquema de URL.  
  
```
inline BOOL SetSchemeName(LPCTSTR lpszSchm) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpszSchm*  
 O nome do esquema de URL.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna verdadeiro no caso de sucesso, falso em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Você também pode definir o esquema usando um [ATL_URL_SCHEME](atl-url-scheme-enum.md) constante (consulte [CUrl::SetScheme](#setscheme)).  
  
##  <a name="seturlpath"></a>CUrl::SetUrlPath  
 Chame este método para definir o caminho da URL.  
  
```
inline BOOL SetUrlPath(LPCTSTR lpszPath) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszPath`  
 O caminho da URL.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna verdadeiro no caso de sucesso, falso em caso de falha.  
  
##  <a name="setusername"></a>CUrl::SetUserName  
 Chame este método para definir o nome de usuário.  
  
```
inline BOOL SetUserName(LPCTSTR lpszUser) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpszUser*  
 O nome do usuário.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna verdadeiro no caso de sucesso, falso em caso de falha.  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../atl/reference/atl-classes.md)
