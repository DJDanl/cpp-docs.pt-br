---
title: Classe CUrl
ms.date: 05/06/2019
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
helpviewer_keywords:
- CUrl class
ms.assetid: b3894d34-47b9-4961-9719-4197153793da
ms.openlocfilehash: 3468e17b031d0a72bc56d915c689fbe4c78859e0
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81330481"
---
# <a name="curl-class"></a>Classe CUrl

Esta classe representa uma URL. Ele permite que você manipule cada elemento da URL independentemente dos outros, seja parando uma seqüência de URL existente ou construindo uma string do zero.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
class CUrl
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CUrl::CUrl](#curl)|O construtor.|
|[CUrl::~cUrl](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CUrl::Canonicalize](#canonicalize)|Chame este método para converter a seqüência de URL em forma canônica.|
|[CUrl::Clear](#clear)|Chame este método para limpar todos os campos de URL.|
|[CUrl::crackurl](#crackurl)|Chame este método para decodificar e analisar a URL.|
|[CUrl::CreateUrl](#createurl)|Chame este método para criar a URL.|
|[Curl::getextrainfo](#getextrainfo)|Chame este método para obter informações extras (como *texto* ou *texto*# ) da URL.|
|[curl::getextrainfolength](#getextrainfolength)|Chame este método para obter o comprimento das informações extras (como *texto* ou *texto*# ) para recuperar da URL.|
|[CUrl::GetHostName](#gethostname)|Chame este método para obter o nome do host da URL.|
|[curl::getHostNameLength](#gethostnamelength)|Chame este método para obter o comprimento do nome do host.|
|[CUrl::GetPassword](#getpassword)|Ligue para este método para obter a senha da URL.|
|[curl::getpasswordLength](#getpasswordlength)|Chame este método para obter o comprimento da senha.|
|[curl::getPortNumber](#getportnumber)|Chame este método para obter o número da porta em termos de ATL_URL_PORT.|
|[CUrl::GetScheme](#getscheme)|Chame este método para obter o esquema de URL.|
|[CUrl::GetSchemeName](#getschemename)|Chame este método para obter o nome do esquema de URL.|
|[curl::getSchemeNameLength](#getschemenamelength)|Chame este método para obter o comprimento do nome do esquema url.|
|[curl::geturllength](#geturllength)|Chame este método para obter o comprimento da URL.|
|[Curl::geturlpath](#geturlpath)|Chame este método para obter o caminho da URL.|
|[curl::geturlPathLength](#geturlpathlength)|Chame este método para obter o comprimento do caminho da URL.|
|[CUrl::GetUserName](#getusername)|Chame este método para obter o nome de usuário da URL.|
|[curl::getuserNameLength](#getusernamelength)|Chame este método para obter o comprimento do nome de usuário.|
|[CUrl::Setextrainfo](#setextrainfo)|Chame este método para definir as informações extras (como *texto* ou *texto*#) da URL.|
|[CUrl::SetHostName](#sethostname)|Chame este método para definir o nome do host.|
|[CUrl::SetPassword](#setpassword)|Chame este método para definir a senha.|
|[curl::setPortNumber](#setportnumber)|Chame este método para definir o número da porta em termos de ATL_URL_PORT.|
|[curl::setScheme](#setscheme)|Chame este método para definir o esquema de URL.|
|[cUrl::setSchemeNome](#setschemename)|Chame este método para definir o nome do esquema url.|
|[curl::seturlpath](#seturlpath)|Chame este método para definir o caminho da URL.|
|[cUrl::SetUserName](#setusername)|Chame este método para definir o nome de usuário.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CUrl::operador =](#operator_eq)|Atribui o objeto `CUrl` especificado `CUrl` ao objeto atual.|

## <a name="remarks"></a>Comentários

`CUrl`permite manipular os campos de uma URL, como o caminho ou o número da porta. `CUrl`entende URLs da seguinte forma:

\<Esquema>:\<>\<de \@ \<nome de\<usuário: senha\<>\<HostName>: PortNumber>/ UrlPath>ExtraInfo>

(Alguns campos são opcionais.) Por exemplo, considere esta URL:

`http://someone:secret@www.microsoft.com:80/visualc/stuff.htm#contents`

[CUrl::CrackUrl](#crackurl) analisa da seguinte forma:

- Esquema: "http" ou [ATL_URL_SCHEME_HTTP](atl-url-scheme-enum.md)

- Nome do usuário: "alguém"

- Senha: "segredo"

- Nome do`www.microsoft.com`host: "

- Número de porta: 80

- UrlPath: "visualc/stuff.htm"

- ExtraInfo: "#contents"

Para manipular o campo UrlPath (por exemplo), você usaria [GetUrlPath,](#geturlpath) [GetUrlPathLength](#geturlpathlength)e [SetUrlPath](#seturlpath). Você usaria [CreateUrl](#createurl) para criar a seqüência completa de URL.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlutil.h

## <a name="curlcanonicalize"></a><a name="canonicalize"></a>CUrl::Canonicalize

Chame este método para converter a seqüência de URL em forma canônica.

```
inline BOOL Canonicalize(DWORD dwFlags = 0) throw();
```

### <a name="parameters"></a>Parâmetros

*dwFlags*<br/>
As bandeiras que controlam a canonização. Se nenhum sinalizador for especificado *(dwFlags* = 0), o método converte \\todos os caracteres \\e seqüências de meta inseguros (como .,\ .., e ...) para escapar de seqüências. *dwFlags* pode ser um dos seguintes valores:

- ATL_URL_BROWSER_MODE: Não codifica ou decodifica caracteres após "#" ou "" e não remove o espaço em branco após "". Se esse valor não for especificado, toda a URL será codificada e o espaço em branco de arrasto será removido.

- ATL_URL _DECODE: Converte todas as seqüências %XX em caracteres, incluindo seqüências de fuga, antes que a URL seja analisada.

- ATL_URL _ENCODE_PERCENT: Codifica todos os sinais encontrados. Por padrão, os sinais por cento não são codificados.

- ATL_URL _ENCODE_SPACES_ONLY: Codifica apenas espaços.

- ATL_URL _NO_ENCODE: Não converte caracteres inseguros em sequências de fuga.

- ATL_URL _NO_META: Não remove seqüências de meta (como "." e "..") da URL.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

### <a name="remarks"></a>Comentários

Converter-se para forma canônica envolve converter caracteres e espaços inseguros para escapar de sequências.

## <a name="curlclear"></a><a name="clear"></a>CUrl::Clear

Chame este método para limpar todos os campos de URL.

```
inline void Clear() throw();
```

## <a name="curlcrackurl"></a><a name="crackurl"></a>CUrl::crackurl

Chame este método para decodificar e analisar a URL.

```
BOOL CrackUrl(LPCTSTR lpszUrl, DWORD dwFlags = 0) throw();
```

### <a name="parameters"></a>Parâmetros

*Lpszurl*<br/>
A URL.

*dwFlags*<br/>
Especifique ATL_URL_DECODE ou ATL_URL_ESCAPE para converter todos os caracteres de escape em *lpszUrl* para seus valores reais após a análise. (Antes do Visual C++ 2005, ATL_URL_DECODE converti todos os caracteres de fuga antes de analisar.)

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

## <a name="curlcreateurl"></a><a name="createurl"></a>CUrl::CreateUrl

Este método constrói uma seqüência de URL a partir dos campos de componentes de um objeto CUrl.

```
inline BOOL CreateUrl(
    LPTSTR lpszUrl,
    DWORD* pdwMaxLength,
    DWORD dwFlags = 0) const throw();
```

### <a name="parameters"></a>Parâmetros

*Lpszurl*<br/>
Um buffer de string para segurar a seqüência completa de URL.

*pdwMaxLength*<br/>
O comprimento máximo do buffer de string *lpszUrl.*

*dwFlags*<br/>
Especificar ATL_URL_ESCAPE converter todos os caracteres de escape em *lpszUrl* para seus valores reais.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

### <a name="remarks"></a>Comentários

Este método anexa seus campos individuais para construir a seqüência completa de URL usando o seguinte formato:

**\<\<>:> usuário:\< \@ \<passar>\<domínio \<>: caminho>da porta>\<>extra**

Ao chamar este método, o parâmetro *pdwMaxLength* deve inicialmente conter o comprimento máximo do buffer de string referenciado pelo parâmetro *lpszUrl.* O valor do parâmetro *pdwMaxLength* será atualizado com o comprimento real da seqüência de URL.

### <a name="example"></a>Exemplo

Esta amostra demonstra a criação de um objeto CUrl e a recuperação de sua seqüência de URL

[!code-cpp[NVC_ATL_Utilities#133](../../atl/codesnippet/cpp/curl-class_1.cpp)]

## <a name="curlcurl"></a><a name="curl"></a>CUrl::CUrl

O construtor.

```
CUrl() throw();
CUrl(const CUrl& urlThat) throw();
```

### <a name="parameters"></a>Parâmetros

*urlThat*<br/>
O `CUrl` objeto a ser copiado para criar a URL.

## <a name="curlcurl"></a><a name="dtor"></a>CUrl::~cUrl

O destruidor.

```
~CUrl() throw();
```

## <a name="curlgetextrainfo"></a><a name="getextrainfo"></a>Curl::getextrainfo

Chame este método para obter informações extras (como *texto* ou *texto*# ) da URL.

```
inline LPCTSTR GetExtraInfo() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna uma seqüência contendo as informações extras.

## <a name="curlgetextrainfolength"></a><a name="getextrainfolength"></a>curl::getextrainfolength

Chame este método para obter o comprimento das informações extras (como *texto* ou *texto*# ) para recuperar da URL.

```
inline DWORD GetExtraInfoLength() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o comprimento da seqüência contendo as informações extras.

## <a name="curlgethostname"></a><a name="gethostname"></a>CUrl::GetHostName

Chame este método para obter o nome do host da URL.

```
inline LPCTSTR GetHostName() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o nome do anfitrião.

## <a name="curlgethostnamelength"></a><a name="gethostnamelength"></a>curl::getHostNameLength

Chame este método para obter o comprimento do nome do host.

```
inline DWORD GetHostNameLength() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o comprimento do nome do hospedeiro.

## <a name="curlgetpassword"></a><a name="getpassword"></a>CUrl::GetPassword

Ligue para este método para obter a senha da URL.

```
inline LPCTSTR GetPassword() const throw();
```

### <a name="return-value"></a>Valor retornado

Devolve a senha.

## <a name="curlgetpasswordlength"></a><a name="getpasswordlength"></a>curl::getpasswordLength

Chame este método para obter o comprimento da senha.

```
inline DWORD GetPasswordLength() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o comprimento da senha.

## <a name="curlgetportnumber"></a><a name="getportnumber"></a>curl::getPortNumber

Ligue para este método para obter o número da porta.

```
inline ATL_URL_PORT GetPortNumber() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o número da porta.

## <a name="curlgetscheme"></a><a name="getscheme"></a>CUrl::GetScheme

Chame este método para obter o esquema de URL.

```
inline ATL_URL_SCHEME GetScheme() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o valor [ATL_URL_SCHEME](atl-url-scheme-enum.md) descrevendo o esquema da URL.

## <a name="curlgetschemename"></a><a name="getschemename"></a>CUrl::GetSchemeName

Chame este método para obter o nome do esquema de URL.

```
inline LPCTSTR GetSchemeName() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o nome do esquema de URL (como "http" ou "ftp").

## <a name="curlgetschemenamelength"></a><a name="getschemenamelength"></a>curl::getSchemeNameLength

Chame este método para obter o comprimento do nome do esquema url.

```
inline DWORD GetSchemeNameLength() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o comprimento do nome do esquema de URL.

## <a name="curlgeturllength"></a><a name="geturllength"></a>curl::geturllength

Chame este método para obter o comprimento da URL.

```
inline DWORD GetUrlLength() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o comprimento da URL.

## <a name="curlgeturlpath"></a><a name="geturlpath"></a>Curl::geturlpath

Chame este método para obter o caminho da URL.

```
inline LPCTSTR GetUrlPath() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o caminho da URL.

## <a name="curlgeturlpathlength"></a><a name="geturlpathlength"></a>curl::geturlPathLength

Chame este método para obter o comprimento do caminho da URL.

```
inline DWORD GetUrlPathLength() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o comprimento do caminho da URL.

## <a name="curlgetusername"></a><a name="getusername"></a>CUrl::GetUserName

Chame este método para obter o nome de usuário da URL.

```
inline LPCTSTR GetUserName() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o nome de usuário.

## <a name="curlgetusernamelength"></a><a name="getusernamelength"></a>curl::getuserNameLength

Chame este método para obter o comprimento do nome de usuário.

```
inline DWORD GetUserNameLength() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o comprimento do nome do usuário.

## <a name="curloperator-"></a><a name="operator_eq"></a>CUrl::operador =

Atribui o objeto `CUrl` especificado `CUrl` ao objeto atual.

```
CUrl& operator= (const CUrl& urlThat) throw();
```

### <a name="parameters"></a>Parâmetros

*urlThat*<br/>
O `CUrl` objeto para copiar no objeto atual.

### <a name="return-value"></a>Valor retornado

Retorna uma referência ao objeto atual.

## <a name="curlsetextrainfo"></a><a name="setextrainfo"></a>CUrl::Setextrainfo

Chame este método para definir as informações extras (como *texto* ou *texto*#) da URL.

```
inline BOOL SetExtraInfo(LPCTSTR lpszInfo) throw();
```

### <a name="parameters"></a>Parâmetros

*lpszInfo*<br/>
A seqüência que contém as informações extras a serem insonadas na URL.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

## <a name="curlsethostname"></a><a name="sethostname"></a>CUrl::SetHostName

Chame este método para definir o nome do host.

```
inline BOOL SetHostName(LPCTSTR lpszHost) throw();
```

### <a name="parameters"></a>Parâmetros

*lpszHost*<br/>
O nome de host.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

## <a name="curlsetpassword"></a><a name="setpassword"></a>CUrl::SetPassword

Chame este método para definir a senha.

```
inline BOOL SetPassword(LPCTSTR lpszPass) throw();
```

### <a name="parameters"></a>Parâmetros

*LpszPass*<br/>
A senha.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

## <a name="curlsetportnumber"></a><a name="setportnumber"></a>curl::setPortNumber

Ligue para este método para definir o número da porta.

```
inline BOOL SetPortNumber(ATL_URL_PORT nPrt) throw();
```

### <a name="parameters"></a>Parâmetros

*nPrt*<br/>
O número da porta.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

## <a name="curlsetscheme"></a><a name="setscheme"></a>curl::setScheme

Chame este método para definir o esquema de URL.

```
inline BOOL SetScheme(ATL_URL_SCHEME nScheme) throw();
```

### <a name="parameters"></a>Parâmetros

*nEsquema*<br/>
Um dos [valores ATL_URL_SCHEME](atl-url-scheme-enum.md) para o esquema.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

### <a name="remarks"></a>Comentários

Você também pode definir o esquema por nome (ver [CUrl::SetSchemeName](#setschemename)).

## <a name="curlsetschemename"></a><a name="setschemename"></a>cUrl::setSchemeNome

Chame este método para definir o nome do esquema url.

```
inline BOOL SetSchemeName(LPCTSTR lpszSchm) throw();
```

### <a name="parameters"></a>Parâmetros

*LpszSchm*<br/>
O nome do esquema de URL.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

### <a name="remarks"></a>Comentários

Você também pode definir o esquema usando [uma](atl-url-scheme-enum.md) ATL_URL_SCHEME constante (ver [CUrl::SetScheme](#setscheme)).

## <a name="curlseturlpath"></a><a name="seturlpath"></a>curl::seturlpath

Chame este método para definir o caminho da URL.

```
inline BOOL SetUrlPath(LPCTSTR lpszPath) throw();
```

### <a name="parameters"></a>Parâmetros

*lpszPath*<br/>
O caminho da URL.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

## <a name="curlsetusername"></a><a name="setusername"></a>cUrl::SetUserName

Chame este método para definir o nome de usuário.

```
inline BOOL SetUserName(LPCTSTR lpszUser) throw();
```

### <a name="parameters"></a>Parâmetros

*lpszUser*<br/>
O nome do usuário.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

## <a name="see-also"></a>Confira também

[Classes](../../atl/reference/atl-classes.md)
