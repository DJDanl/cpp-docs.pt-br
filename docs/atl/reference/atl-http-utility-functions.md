---
title: Funções do utilitário HTTP da ATL
ms.date: 11/04/2016
ms.assetid: 4db57ef2-31fa-4696-bbeb-79a9035033ed
ms.openlocfilehash: c95681503da0d661382e6da33bd33e8f2004838b
ms.sourcegitcommit: 2bc15c5b36372ab01fa21e9bcf718fa22705814f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/27/2020
ms.locfileid: "82168599"
---
# <a name="atl-http-utility-functions"></a>Funções do utilitário HTTP da ATL

Essas funções dão suporte à manipulação de URLs.

|||
|-|-|
|[AtlCanonicalizeUrl](#atlcanonicalizeurl)|Canonicalizes uma URL, que inclui a conversão de caracteres e espaços não seguros em sequências de escape.|
|[AtlCombineUrl](#atlcombineurl)|Combina uma URL base e uma URL relativa em uma única URL canônica.|
|[AtlEscapeUrl](#atlescapeurl)|Converte todos os caracteres não seguros em sequências de escape.|
|[AtlGetDefaultUrlPort](#atlgetdefaulturlport)|Obtém o número da porta padrão associado a um esquema ou protocolo de Internet específico.|
|[AtlIsUnsafeUrlChar](#atlisunsafeurlchar)|Determina se um caractere é seguro para uso em uma URL.|
|[AtlUnescapeUrl](#atlunescapeurl)|Converte caracteres de escape de volta em seus valores originais.|
|[RGBToHtml](#rgbtohtml)|Converte um valor de [COLORREF](/windows/win32/gdi/colorref) para o texto HTML correspondente a esse valor de cor.|
|[SystemTimeToHttpDate](#systemtimetohttpdate)|Chame essa função para converter uma hora do sistema em uma cadeia de caracteres em um formato adequado para uso em cabeçalhos HTTP.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlutil. h

## <a name="atlcanonicalizeurl"></a><a name="atlcanonicalizeurl"></a>AtlCanonicalizeUrl

Chame essa função para canonizar uma URL, o que inclui converter caracteres e espaços não seguros em sequências de escape.

```cpp
inline BOOL AtlCanonicalizeUrl(
   LPCTSTR szUrl,
   LPTSTR szCanonicalized,
   DWORD* pdwMaxLength,
   DWORD dwFlags = 0) throw();
```

### <a name="parameters"></a>Parâmetros

*szUrl*<br/>
A URL a ser canônica.

*szCanonicalized*<br/>
Buffer alocado ao chamador para receber a URL canônica.

*pdwMaxLength*<br/>
Ponteiro para uma variável que contém o comprimento em caracteres de *szCanonicalized*. Se a função for realizada com sucesso, a variável receberá o número de caracteres gravados no buffer, incluindo o caractere nulo de terminação. Se a função falhar, a variável receberá o comprimento necessário em bytes do buffer, incluindo o espaço para o caractere nulo de terminação.

*dwFlags*<br/>
ATL_URL sinalizadores que controlam o comportamento dessa função.

- ATL_URL_BROWSER_MODE não codifica ou Decodifica caracteres após "#" ou "?" e não remove o espaço em branco à direita após "?". Se esse valor não for especificado, toda a URL será codificada e o espaço em branco à direita será removido.

- ATL_URL_DECODE converte todas as% XX sequências em caracteres, incluindo sequências de escape, antes de a URL ser analisada.

- ATL_URL_ENCODE_PERCENT codifica quaisquer sinais de porcentagem encontrados. Por padrão, os sinais de porcentagem não são codificados.

- ATL_URL_ENCODE_SPACES_ONLY codifica apenas espaços.

- ATL_URL_ESCAPE converte todas as sequências de escape (% XX) em seus caracteres correspondentes.

- ATL_URL_NO_ENCODE não converte caracteres não seguros em sequências de escape.

- ATL_URL_NO_META não remove meta sequences (como "." e "..") da URL.

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

Comporta-se como a versão atual do [InternetCanonicalizeUrl](/windows/win32/api/wininet/nf-wininet-internetcanonicalizeurlw) , mas não requer que o WinInet ou o Internet Explorer sejam instalados.

## <a name="atlcombineurl"></a><a name="atlcombineurl"></a>AtlCombineUrl

Chame essa função para combinar uma URL de base e uma URL relativa em uma única URL canônica.

```cpp
inline BOOL AtlCombineUrl(
   LPCTSTR szBaseUrl,
   LPCTSTR szRelativeUrl,
   LPTSTR szBuffer,
   DWORD* pdwMaxLength,
   DWORD dwFlags = 0) throw();
```

### <a name="parameters"></a>Parâmetros

*szBaseUrl*<br/>
A URL de base.

*szRelativeUrl*<br/>
A URL relativa à URL base.

*szBuffer*<br/>
Buffer alocado ao chamador para receber a URL canônica.

*pdwMaxLength*<br/>
Ponteiro para uma variável que contém o comprimento em caracteres de *szBuffer*. Se a função for realizada com sucesso, a variável receberá o número de caracteres gravados no buffer, incluindo o caractere nulo de terminação. Se a função falhar, a variável receberá o comprimento necessário em bytes do buffer, incluindo o espaço para o caractere nulo de terminação.

*dwFlags*<br/>
Sinalizadores que controlam o comportamento dessa função. Consulte [AtlCanonicalizeUrl](#atlcanonicalizeurl).

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

Comporta-se como a versão atual do [InternetCombineUrl](/windows/win32/api/wininet/nf-wininet-internetcombineurlw) , mas não requer que o WinInet ou o Internet Explorer sejam instalados.

## <a name="atlescapeurl"></a><a name="atlescapeurl"></a>AtlEscapeUrl

Chame essa função para converter todos os caracteres não seguros em sequências de escape.

```cpp
inline BOOL AtlEscapeUrl(
   LPCSTR szStringIn,
   LPSTR szStringOut,
   DWORD* pdwStrLen,
   DWORD dwMaxLength,
   DWORD dwFlags = 0) throw();

inline BOOL AtlEscapeUrl(
   LPCWSTR szStringIn,
   LPWSTR szStringOut,
   DWORD* pdwStrLen,
   DWORD dwMaxLength,
   DWORD dwFlags = 0) throw();
```

### <a name="parameters"></a>Parâmetros

*lpszStringIn*<br/>
A URL a ser convertida.

*lpszStringOut*<br/>
Buffer alocado para o chamador no qual a URL convertida será gravada.

*pdwStrLen*<br/>
Ponteiro para uma variável DWORD. Se a função for realizada com sucesso, o *pdwStrLen* receberá o número de caracteres gravados no buffer, incluindo o caractere nulo de terminação. Se a função falhar, a variável receberá o comprimento necessário em bytes do buffer, incluindo o espaço para o caractere nulo de terminação. Ao usar a versão de caractere largo desse método, *pdwStrLen* recebe o número de caracteres necessário, e não o número de bytes.

*dwMaxLength*<br/>
O tamanho do buffer *lpszStringOut*.

*dwFlags*<br/>
ATL_URL sinalizadores que controlam o comportamento dessa função. Consulte [ATLCanonicalizeUrl](#atlcanonicalizeurl) para obter os valores possíveis.

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro em caso de êxito, falso em caso de falha.

## <a name="atlgetdefaulturlport"></a><a name="atlgetdefaulturlport"></a>AtlGetDefaultUrlPort

Chame essa função para obter o número da porta padrão associado a um IP ou esquema específico.

```cpp
inline ATL_URL_PORT AtlGetDefaultUrlPort(ATL_URL_SCHEME m_nScheme) throw();
```

### <a name="parameters"></a>Parâmetros

*m_nScheme*<br/>
O valor [ATL_URL_SCHEME](atl-url-scheme-enum.md) identificando o esquema para o qual você deseja obter o número da porta.

### <a name="return-value"></a>Valor retornado

O [ATL_URL_PORT](atl-typedefs.md#atl_url_port) associado ao esquema especificado ou ATL_URL_INVALID_PORT_NUMBER se o esquema não for reconhecido.

## <a name="atlisunsafeurlchar"></a><a name="atlisunsafeurlchar"></a>AtlIsUnsafeUrlChar

Chame essa função para descobrir se um caractere é seguro para uso em uma URL.

```cpp
inline BOOL AtlIsUnsafeUrlChar(char chIn) throw();
```

### <a name="parameters"></a>Parâmetros

*chIn*<br/>
O caractere a ser testado quanto à segurança.

### <a name="return-value"></a>Valor retornado

Retornará TRUE se o caractere de entrada não for seguro; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Os caracteres que não devem ser usados em URLs podem ser testados usando essa função e convertidos usando [AtlCanonicalizeUrl](#atlcanonicalizeurl).

## <a name="atlunescapeurl"></a><a name="atlunescapeurl"></a>AtlUnescapeUrl

Chame essa função para converter caracteres de escape de volta aos valores originais.

```cpp
inline BOOL AtlUnescapeUrl(
   LPCSTR szStringIn,
   LPSTR szStringOut,
   LPDWORD pdwStrLen,
   DWORD dwMaxLength) throw();

inline BOOL AtlUnescapeUrl(
   LPCWSTR szStringIn,
   LPWSTR szStringOut,
   LPDWORD pdwStrLen,
   DWORD dwMaxLength) throw();
```

### <a name="parameters"></a>Parâmetros

*lpszStringIn*<br/>
A URL a ser convertida.

*lpszStringOut*<br/>
Buffer alocado para o chamador no qual a URL convertida será gravada.

*pdwStrLen*<br/>
Ponteiro para uma variável DWORD. Se a função for realizada com sucesso, a variável receberá o número de caracteres gravados no buffer, incluindo o caractere nulo de terminação. Se a função falhar, a variável receberá o comprimento necessário em bytes do buffer, incluindo o espaço para o caractere nulo de terminação.

*dwMaxLength*<br/>
O tamanho do buffer *lpszStringOut*.

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

Reverte o processo de conversão aplicado pelo [AtlEscapeUrl](#atlescapeurl).

## <a name="rgbtohtml"></a><a name="rgbtohtml"></a>RGBToHtml

Converte um valor de [COLORREF](/windows/win32/gdi/colorref) para o texto HTML correspondente a esse valor de cor.

```cpp
bool inline RGBToHtml(
   COLORREF color,
   LPTSTR pbOut,
   long nBuffer);
```

### <a name="parameters"></a>Parâmetros

*color*<br/>
Um valor de cor RGB.

*pbOut*<br/>
Buffer alocado para o chamador para receber o texto do valor de cor HTML. O buffer deve ter espaço para pelo menos 8 caracteres, incluindo o espaço para o terminador nulo).

*nBuffer*<br/>
O tamanho em bytes do buffer (incluindo o espaço para o terminador nulo).

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

Um valor de cor HTML é um sinal de libra seguido por um valor hexadecimal de seis dígitos usando 2 dígitos para cada um dos componentes vermelho, verde e azul da cor (por exemplo, #FFFFFF é branco).

## <a name="systemtimetohttpdate"></a><a name="systemtimetohttpdate"></a>SystemTimeToHttpDate

Chame essa função para converter uma hora do sistema em uma cadeia de caracteres em um formato adequado para uso em cabeçalhos HTTP.

```cpp
inline void SystemTimeToHttpDate(
   const SYSTEMTIME& st,
   CStringA& strTime);
```

### <a name="parameters"></a>Parâmetros

*St*<br/>
A hora do sistema a ser obtida como uma cadeia de caracteres de formato HTTP.

*strTime*<br/>
Uma referência a uma variável de cadeia de caracteres para receber a data e hora HTTP, conforme[https://www.ietf.org/rfc/rfc2616.txt](https://www.ietf.org/rfc/rfc2616.txt)definido em RFC 2616 ([https://www.ietf.org/rfc/rfc1123.txt](https://www.ietf.org/rfc/rfc1123.txt)) e RFC 1123 ().

## <a name="see-also"></a>Confira também

[Conceitos](../active-template-library-atl-concepts.md)<br/>
[Componentes de área de trabalho COM da ATL](../atl-com-desktop-components.md)<br/>
[InternetCanonicalizeUrl](/windows/win32/api/wininet/nf-wininet-internetcanonicalizeurlw)
