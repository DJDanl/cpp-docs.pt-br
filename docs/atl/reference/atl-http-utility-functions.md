---
title: "Funções de utilitário ATL HTTP | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: 4db57ef2-31fa-4696-bbeb-79a9035033ed
caps.latest.revision: "4"
author: mikeblome
ms.author: mblome
ms.openlocfilehash: 9cdb12373d93c17258fb615f667d7321e06f6728
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="atl-http-utility-functions"></a>Funções de utilitário de HTTP do ATL

Essas funções oferecem suporte a manipulação de URLs.

|||  
|-|-|  
|[AtlCanonicalizeUrl](#atlcanonicalizeurl)|Padroniza uma URL, que inclui a conversão de caracteres inseguros e espaços em sequências de escape.|  
|[AtlCombineUrl](#atlcombineurl)|Combina uma URL base e uma URL relativa em um único URL canônica.|  
|[AtlEscapeUrl](#atlescapeurl)|Converte todos os caracteres não seguros para sequências de escape.|  
|[AtlGetDefaultUrlPort](#atlgetdefaulturlport)|Obtém o número de porta padrão associado a um determinado protocolo de Internet ou o esquema.|  
|[AtlIsUnsafeUrlChar](#atlisunsafeurlchar)|Determina se um caractere é seguro para uso em uma URL.|  
|[AtlUnescapeUrl](#atlunescapeurl)|Converte caracteres de escape para seus valores originais.|  
|[RGBToHtml](#rgbtohtml)|Converte um [COLORREF](http://msdn.microsoft.com/library/windows/desktop/dd183449) valor para o texto HTML correspondente a esse valor de cor.|
|[SystemTimeToHttpDate](#systemtimetohttpdate)|Chame essa função para converter uma hora do sistema em uma cadeia de caracteres em um formato adequado para uso em cabeçalhos HTTP.|

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlutil.h  

## <a name="atlcanonicalizeurl"></a>AtlCanonicalizeUrl
Chame essa função para canonizar uma URL, o que inclui converter caracteres e espaços não seguros em sequências de escape.  
  
```    
inline BOOL AtlCanonicalizeUrl(  
   LPCTSTR szUrl,  
   LPTSTR szCanonicalized,  
   DWORD* pdwMaxLength,  
   DWORD dwFlags = 0) throw();  
```  
  
### <a name="parameters"></a>Parâmetros  
 `szUrl`  
 A URL a ser canonizado.  
  
 `szCanonicalized`  
 Buffer alocada pelo chamador para receber a URL de conversão em formato canônico.  
  
 `pdwMaxLength`  
 Ponteiro para uma variável que contém o comprimento em caracteres de `szCanonicalized`. Se a função tiver êxito, a variável recebe o número de caracteres gravada no buffer, incluindo o caractere null de terminação. Se a função falhar, a variável recebe o comprimento necessário em bytes do buffer incluindo espaço para o caractere null de terminação.  
  
 `dwFlags`  
 Sinalizadores ATL_URL controlar o comportamento dessa função. 

- `ATL_URL_BROWSER_MODE`Não codificar ou decodificar caracteres depois de "#" ou "?" e não remova o espaço em branco à direita após "?". Se esse valor não for especificado, a URL inteira é codificada e espaço em branco à direita é removido.
- `ATL_URL_DECODE`Converte todas as sequências XX % em caracteres, incluindo as sequências de escape, antes que a URL é analisada.
- `ATL_URL_ENCODE_PERCENT`Codifica qualquer sinais de porcentagem encontrados. Por padrão, os sinais de porcentagem não são codificados.
- `ATL_URL_ENCODE_SPACES_ONLY`Codifica apenas espaços.
- `ATL_URL_ESCAPE`Converte todas as sequências de escape (% XX) em seus caracteres correspondentes.
- `ATL_URL_NO_ENCODE`Converte os caracteres não seguros para sequências de escape.
- `ATL_URL_NO_META`Não remove as sequências de metadados (como "."e"...") da URL. 
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **TRUE** em caso de sucesso, **FALSE** em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Se comporta como a versão atual do [InternetCanonicalizeUrl](http://msdn.microsoft.com/library/windows/desktop/aa384342) , mas não exige WinInet ou o Internet Explorer esteja instalado.  
  
### <a name="see-also"></a>Consulte também  
 [InternetCanonicalizeUrl](http://msdn.microsoft.com/library/windows/desktop/aa384342)

 ## <a name="atlcombineurl"></a>AtlCombineUrl
 Chame essa função para combinar uma URL de base e uma URL relativa em uma única URL canônica.  
  
```    
inline BOOL AtlCombineUrl(  
   LPCTSTR szBaseUrl,  
   LPCTSTR szRelativeUrl,  
   LPTSTR szBuffer,  
   DWORD* pdwMaxLength,  
   DWORD dwFlags = 0) throw();  
```  
  
### <a name="parameters"></a>Parâmetros  
 *szBaseUrl*  
 A URL base.  
  
 *szRelativeUrl*  
 A URL em relação a URL base.  
  
 `szBuffer`  
 Buffer alocada pelo chamador para receber a URL de conversão em formato canônico.  
  
 `pdwMaxLength`  
 Ponteiro para uma variável que contém o comprimento em caracteres de `szBuffer`. Se a função tiver êxito, a variável recebe o número de caracteres gravada no buffer, incluindo o caractere null de terminação. Se a função falhar, a variável recebe o comprimento necessário em bytes do buffer incluindo espaço para o caractere null de terminação.  
  
 `dwFlags`  
 Sinalizadores de controlar o comportamento dessa função. Consulte [AtlCanonicalizeUrl](#atlcanonicalizeurl).  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **TRUE** em caso de sucesso, **FALSE** em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Se comporta como a versão atual do [InternetCombineUrl](http://msdn.microsoft.com/library/windows/desktop/aa384355) , mas não exige WinInet ou o Internet Explorer esteja instalado.  
  
## <a name="atlescapeurl"></a>AtlEscapeUrl
 Chame essa função para converter todos os caracteres não seguros em sequências de escape.  
  
```    
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
 `lpszStringIn`  
 A URL a ser convertido.  
  
 `lpszStringOut`  
 Buffer alocada pelo chamador que a URL convertida será gravada.  
  
 `pdwStrLen`  
 Ponteiro para uma variável DWORD. Se a função tiver êxito, `pdwStrLen` recebe o número de caracteres gravada no buffer, incluindo o caractere null de terminação. Se a função falhar, a variável recebe o comprimento necessário em bytes do buffer incluindo espaço para o caractere null de terminação. Ao usar a versão de caractere largo desse método `pdwStrLen` recebe o número de caracteres necessários, não o número de bytes.  
  
 `dwMaxLength`  
 O tamanho do buffer `lpszStringOut`.  
  
 `dwFlags`  
 Sinalizadores ATL_URL controlar o comportamento dessa função. Consulte [ATLCanonicalizeUrl](#atlcanonicalizeurl) para os valores possíveis.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **TRUE** em caso de sucesso, **FALSE** em caso de falha.  
  
## <a name="atlgetdefaulturlport"></a> 
 Chame essa função para obter o número da porta padrão associado a um IP ou esquema específico.  
  
```  
inline ATL_URL_PORT AtlGetDefaultUrlPort(ATL_URL_SCHEME m_nScheme) throw();  
```  
  
### <a name="parameters"></a>Parâmetros  
 *m_nScheme*  
 O [ATL_URL_SCHEME](atl-url-scheme-enum.md) valor que identifica o esquema para o qual você deseja obter o número da porta.  
  
### <a name="return-value"></a>Valor de retorno  
 O [ATL_URL_PORT](atl-typedefs.md#atl_url_port) associado com o esquema especificado ou ATL_URL_INVALID_PORT_NUMBER se o esquema não é reconhecido.  

## <a name="atlisunsafeurlchar"></a>AtlIsUnsafeUrlChar
 Chame essa função para descobrir se um caractere é seguro para uso em uma URL.  
  
```  
inline BOOL AtlIsUnsafeUrlChar(char chIn) throw();  
```  
  
### <a name="parameters"></a>Parâmetros  
 `chIn`  
 O caractere a ser testado para segurança.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **TRUE** se o caractere de entrada não é seguro, **FALSE** caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Caracteres que não devem ser usados em URLs podem ser testadas usando essa função e convertido usando [AtlCanonicalizeUrl](#atlcanonicalizeurl).  
  
## <a name="atlunescapeurl"></a>AtlUnescapeUrl
 Chame essa função para converter caracteres de escape de volta aos valores originais.  
  
```    
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
 `lpszStringIn`  
 A URL a ser convertido.  
  
 `lpszStringOut`  
 Buffer alocada pelo chamador que a URL convertida será gravada.  
  
 `pdwStrLen`  
 Ponteiro para uma variável DWORD. Se a função tiver êxito, a variável recebe o número de caracteres gravada no buffer, incluindo o caractere null de terminação. Se a função falhar, a variável recebe o comprimento necessário em bytes do buffer incluindo espaço para o caractere null de terminação.  
  
 `dwMaxLength`  
 O tamanho do buffer `lpszStringOut`.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **TRUE** em caso de sucesso, **FALSE** em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Reverte o processo de conversão aplicado por [AtlEscapeUrl](#atlescapeurl).  
  
## <a name="rgbtohtml"></a>RGBToHtml
Converte um [COLORREF](http://msdn.microsoft.com/library/windows/desktop/dd183449) valor para o texto HTML correspondente a esse valor de cor.  
  
```  
bool inline RGBToHtml(  
   COLORREF color,  
   LPTSTR pbOut,  
   long nBuffer);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `color`  
 Um valor de cor RGB.  
  
 `pbOut`  
 Buffer alocada pelo chamador para receber o texto para o valor de cor HTML. O buffer deve ter espaço para pelo menos 8 caracteres, incluindo o espaço para o terminador nulo).  
  
 *nBuffer*  
 O tamanho em bytes do buffer (incluindo o espaço para o terminador nulo).  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **TRUE** em caso de sucesso, **FALSE** em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Um valor de cor HTML é um sinal numérico seguido por um valor hexadecimal de 6 dígitos usando 2 dígitos para cada um dos componentes vermelhos, verdes e azuis da cor (por exemplo, #FFFFFF é branco).  
  
## <a name="systemtimetohttpdate"></a>SystemTimeToHttpDate
Chame essa função para converter uma hora do sistema em uma cadeia de caracteres em um formato adequado para uso em cabeçalhos HTTP.  
  
```  
inline void SystemTimeToHttpDate( 
   const SYSTEMTIME& st,  
   CStringA& strTime);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `st`  
 A hora do sistema a ser obtido como uma cadeia de caracteres de formato HTTP.  
  
 *strTime*  
 Uma referência a uma variável de cadeia de caracteres para receber o HTTP data hora, conforme definido na RFC 2616 ([http://www.ietf.org/rfc/rfc2616.txt](http://www.ietf.org/rfc/rfc2616.txt)) e RFC 1123 ([http://www.ietf.org/rfc/rfc1123.txt](http://www.ietf.org/rfc/rfc1123.txt)).  
  
## <a name="see-also"></a>Consulte também  
 [Conceitos](../../atl/active-template-library-atl-concepts.md)   
 [Componentes de área de trabalho COM da ATL](../../atl/atl-com-desktop-components.md)   

