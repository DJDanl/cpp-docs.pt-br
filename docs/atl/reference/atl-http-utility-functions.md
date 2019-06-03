---
title: Funções de utilitário de HTTP da ATL
ms.date: 11/04/2016
ms.assetid: 4db57ef2-31fa-4696-bbeb-79a9035033ed
ms.openlocfilehash: 8f26a23190f9358ff8913e35f5ed7274c8b274ea
ms.sourcegitcommit: 28eae422049ac3381c6b1206664455dbb56cbfb6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/31/2019
ms.locfileid: "66449970"
---
# <a name="atl-http-utility-functions"></a>Funções de utilitário de HTTP da ATL

Essas funções dão suporte a manipulação de URLs.

|||
|-|-|
|[AtlCanonicalizeUrl](#atlcanonicalizeurl)|Padroniza a uma URL, que inclui converter caracteres desprotegidos e espaços em sequências de escape.|
|[AtlCombineUrl](#atlcombineurl)|Combina uma URL base e uma URL relativa em uma única URL canônica.|
|[AtlEscapeUrl](#atlescapeurl)|Converte todos os caracteres não seguros em sequências de escape.|
|[AtlGetDefaultUrlPort](#atlgetdefaulturlport)|Obtém o número da porta padrão associado a um determinado protocolo de Internet ou o esquema.|
|[AtlIsUnsafeUrlChar](#atlisunsafeurlchar)|Determina se um caractere é seguro para uso em uma URL.|
|[AtlUnescapeUrl](#atlunescapeurl)|Converte caracteres de escape para seus valores originais.|
|[RGBToHtml](#rgbtohtml)|Converte um [COLORREF](/windows/desktop/gdi/colorref) valor para o texto HTML correspondente ao valor da cor.|
|[SystemTimeToHttpDate](#systemtimetohttpdate)|Chame essa função para converter uma hora do sistema em uma cadeia de caracteres em um formato adequado para uso em cabeçalhos HTTP.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlutil

## <a name="atlcanonicalizeurl"></a> AtlCanonicalizeUrl

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
A URL a ser canonizado.

*szCanonicalized*<br/>
Buffer alocado pelo chamador para receber a URL canonizada.

*pdwMaxLength*<br/>
Ponteiro para uma variável que contém o comprimento em caracteres de *szCanonicalized*. Se a função for bem-sucedida, a variável recebe o número de caracteres gravados no buffer, incluindo o caractere nulo de terminação. Se a função falhar, a variável recebe o comprimento necessário em bytes do buffer, incluindo o espaço para o caractere nulo de terminação.

*dwFlags*<br/>
Sinalizadores ATL_URL controlar o comportamento dessa função.

- ATL_URL_BROWSER_MODE não codificar ou decodificar os caracteres após o "#" ou "?" e não remove o espaço em branco à direita após "?". Se esse valor não for especificado, a URL inteira é codificada e espaço em branco à direita é removido.

- ATL_URL_DECODE converte todas as sequências XX % em caracteres, incluindo sequências de escape, antes que a URL é analisada.

- Todos os sinais de porcentagem ATL_URL_ENCODE_PERCENT codifica encontrado. Por padrão, os sinais de porcentagem não são codificadas.

- Codifica ATL_URL_ENCODE_SPACES_ONLY somente espaços.

- ATL_URL_ESCAPE converte todas as sequências de escape de (% XX) para seus caracteres correspondentes.

- ATL_URL_NO_ENCODE não converte os caracteres não seguros em sequências de escape.

- ATL_URL_NO_META não remove as sequências de metadados (como "."e"..") da URL.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

### <a name="remarks"></a>Comentários

Se comporta como a versão atual do [InternetCanonicalizeUrl](/windows/desktop/api/wininet/nf-wininet-internetcanonicalizeurla) , mas não requer o WinInet ou Internet Explorer para ser instalado.

## <a name="atlcombineurl"></a> AtlCombineUrl

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
A URL base.

*szRelativeUrl*<br/>
A URL em relação a URL base.

*szBuffer*<br/>
Buffer alocado pelo chamador para receber a URL canonizada.

*pdwMaxLength*<br/>
Ponteiro para uma variável que contém o comprimento em caracteres de *szBuffer*. Se a função for bem-sucedida, a variável recebe o número de caracteres gravados no buffer, incluindo o caractere nulo de terminação. Se a função falhar, a variável recebe o comprimento necessário em bytes do buffer, incluindo o espaço para o caractere nulo de terminação.

*dwFlags*<br/>
Sinalizadores de controlar o comportamento dessa função. Ver [AtlCanonicalizeUrl](#atlcanonicalizeurl).

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

### <a name="remarks"></a>Comentários

Se comporta como a versão atual do [InternetCombineUrl](/windows/desktop/api/wininet/nf-wininet-internetcombineurla) , mas não requer o WinInet ou Internet Explorer para ser instalado.

## <a name="atlescapeurl"></a> AtlEscapeUrl

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
A URL a ser convertido.

*lpszStringOut*<br/>
Buffer alocado pelo chamador para o qual a URL convertida será gravada.

*pdwStrLen*<br/>
Ponteiro para uma variável DWORD. Se a função for bem-sucedida, *pdwStrLen* recebe o número de caracteres gravados no buffer, incluindo o caractere nulo de terminação. Se a função falhar, a variável recebe o comprimento necessário em bytes do buffer, incluindo o espaço para o caractere nulo de terminação. Ao usar esse método, a versão de caractere largo *pdwStrLen* recebe o número de caracteres necessários, não o número de bytes.

*dwMaxLength*<br/>
O tamanho do buffer *lpszStringOut*.

*dwFlags*<br/>
Sinalizadores ATL_URL controlar o comportamento dessa função. Ver [ATLCanonicalizeUrl](#atlcanonicalizeurl) para os valores possíveis.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

## <a name="atlgetdefaulturlport"></a> AtlGetDefaultUrlPort

Chame essa função para obter o número da porta padrão associado a um IP ou esquema específico.

```
inline ATL_URL_PORT AtlGetDefaultUrlPort(ATL_URL_SCHEME m_nScheme) throw();
```

### <a name="parameters"></a>Parâmetros

*m_nScheme*<br/>
O [ATL_URL_SCHEME](atl-url-scheme-enum.md) valor que identifica o esquema para o qual você deseja obter o número da porta.

### <a name="return-value"></a>Valor de retorno

O [ATL_URL_PORT](atl-typedefs.md#atl_url_port) associados ao esquema especificado ou ATL_URL_INVALID_PORT_NUMBER se o esquema não é reconhecido.

## <a name="atlisunsafeurlchar"></a> AtlIsUnsafeUrlChar

Chame essa função para descobrir se um caractere é seguro para uso em uma URL.

```
inline BOOL AtlIsUnsafeUrlChar(char chIn) throw();
```

### <a name="parameters"></a>Parâmetros

*chIn*<br/>
O caractere a ser testado para segurança.

### <a name="return-value"></a>Valor de retorno

Retornará TRUE se o caractere de entrada é não seguro, FALSE caso contrário.

### <a name="remarks"></a>Comentários

Caracteres que não devem ser usados em URLs podem ser testadas usando essa função e convertidos usando [AtlCanonicalizeUrl](#atlcanonicalizeurl).

## <a name="atlunescapeurl"></a> AtlUnescapeUrl

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
A URL a ser convertido.

*lpszStringOut*<br/>
Buffer alocado pelo chamador para o qual a URL convertida será gravada.

*pdwStrLen*<br/>
Ponteiro para uma variável DWORD. Se a função for bem-sucedida, a variável recebe o número de caracteres gravados no buffer, incluindo o caractere nulo de terminação. Se a função falhar, a variável recebe o comprimento necessário em bytes do buffer, incluindo o espaço para o caractere nulo de terminação.

*dwMaxLength*<br/>
O tamanho do buffer *lpszStringOut*.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

### <a name="remarks"></a>Comentários

Reverte o processo de conversão aplicado pelo [AtlEscapeUrl](#atlescapeurl).

## <a name="rgbtohtml"></a> RGBToHtml

Converte um [COLORREF](/windows/desktop/gdi/colorref) valor para o texto HTML correspondente ao valor da cor.

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
Buffer alocado pelo chamador para receber o texto para o valor de cor HTML. O buffer deve ter espaço para pelo menos 8 caracteres, incluindo o espaço para o terminador nulo).

*nBuffer*<br/>
O tamanho em bytes do buffer (incluindo o espaço para o terminador nulo).

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

### <a name="remarks"></a>Comentários

Um valor de cor HTML é um sinal de libra seguido por um valor hexadecimal de 6 dígitos usando 2 dígitos para cada um dos componentes vermelhos, verdes e azuis da cor (por exemplo, #FFFFFF é branco).

## <a name="systemtimetohttpdate"></a> SystemTimeToHttpDate

Chame essa função para converter uma hora do sistema em uma cadeia de caracteres em um formato adequado para uso em cabeçalhos HTTP.

```cpp
inline void SystemTimeToHttpDate(
   const SYSTEMTIME& st,
   CStringA& strTime);
```

### <a name="parameters"></a>Parâmetros

*st*<br/>
A hora do sistema a ser obtido como uma cadeia de caracteres de formato HTTP.

*strTime*<br/>
Uma referência a uma variável de cadeia de caracteres para receber o HTTP data hora, conforme definido na RFC 2616 ([https://www.ietf.org/rfc/rfc2616.txt](https://www.ietf.org/rfc/rfc2616.txt)) e o RFC 1123 ([https://www.ietf.org/rfc/rfc1123.txt](https://www.ietf.org/rfc/rfc1123.txt)).

## <a name="see-also"></a>Consulte também

[Conceitos](../active-template-library-atl-concepts.md)<br/>
[Componentes de área de trabalho COM da ATL](../atl-com-desktop-components.md)<br/>
[InternetCanonicalizeUrl](/windows/desktop/api/wininet/nf-wininet-internetcanonicalizeurla)
