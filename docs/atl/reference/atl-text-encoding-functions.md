---
title: Funções de codificação de texto ATL | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- atlbase/ATL::AtlGetHexValue
- atlbase/ATL::AtlGetVersion
- atlenc/ATL::AtlHexDecode
- atlenc/ATL::AtlHexDecodeGetRequiredLength
- atlenc/ATL::AtlHexEncode
- atlenc/ATL::AtlHexEncodeGetRequiredLength
- atlenc/ATL::AtlHexValue
- atlenc/ATL::BEncode
- atlenc/ATL::BEncodeGetRequiredLength
- atlenc/ATL::EscapeXML
- atlenc/ATL::GetExtendedChars
- atlenc/ATL::IsExtendedChar
- atlenc/ATL::QEncode
- atlenc/ATL::QEncodeGetRequiredLength
- atlenc/ATL::QPDecode
- atlenc/ATL::QPDecodeGetRequiredLength
- atlenc/ATL::QPEncode
- atlenc/ATL::QPEncodeGetRequiredLength
- atlenc/ATL::UUDecode
- atlenc/ATL::UUDecodeGetRequiredLength
- atlenc/ATL::UUEncode
- atlenc/ATL::UUEncodeGetRequiredLength
ms.assetid: 2ae1648b-2b87-4112-92aa-0069fcfd23da
ms.openlocfilehash: 26eb0709c4009070e6255c6ee178f19d13d8a9c3
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="atl-text-encoding-functions"></a>Funções de codificação de texto ATL
Essas funções oferecem suporte a codificação e decodificação de texto.

|||  
|-|-|  
|[AtlGetHexValue](#atlgethexvalue)|Chame essa função para obter o valor numérico de um dígito hexadecimal.|   
|[AtlGetVersion](#atlgetversion)|Chame essa função para obter a versão da biblioteca de ATL que você está usando.  |  
|[AtlHexDecode](#atlhexdecode)|Decodifica uma cadeia de caracteres de dados que tem sido codificados como texto hexadecimal, como por uma chamada anterior a [AtlHexEncode](#atlhexencode).|
|[AtlHexDecodeGetRequiredLength](#atlhexdecodegetrequiredlength)|Chame essa função para obter o tamanho em bytes de um buffer que pode conter os dados decodificados de uma cadeia de caracteres com codificação hexadecimal do comprimento especificado.|
|[AtlHexEncode](#atlhexencode)|Chame essa função para codificar alguns dados como uma cadeia de caracteres de texto hexadecimal.|
|[AtlHexEncodeGetRequiredLength](#atlhexencodegetrequiredlength)|Chame essa função para obter o tamanho em caracteres de um buffer que pode conter de uma cadeia de caracteres codificada dos dados do tamanho especificado.|
|[AtlHexValue](#atlhexvalue)|Chame essa função para obter o valor numérico de um dígito hexadecimal. |
|[AtlUnicodeToUTF8](#atlunicodetoutf8)|Chame essa função para converter uma cadeia de caracteres Unicode em UTF-8. |
|[BEncode](#bencode)|Chame essa função para converter alguns dados usando a codificação “B”.|
|[BEncodeGetRequiredLength](#bencodegetrequiredlength)|Chame essa função para obter o tamanho em caracteres de um buffer que pode conter de uma cadeia de caracteres codificada dos dados do tamanho especificado.|
|[EscapeXML](#escapexml)|Chame essa função para converter os caracteres que não são seguros para uso em XML em seus equivalentes seguros.|
|[GetExtendedChars](#getextendedchars)|Chame essa função para obter o número de caracteres estendidos em uma cadeia de caracteres.|
|[IsExtendedChar](#isextendedchar)|Chame essa função para descobrir se um caractere fornecido é um caractere estendido (menor que 32, maior que 126, e não uma guia, um avanço de linha ou retorno de carro)|
|[QEncode](#qencode)|Chame essa função para converter alguns dados usando a codificação “Q”.  |
|[QEncodeGetRequiredLength](#qencodegetrequiredlength)|Chame essa função para obter o tamanho em caracteres de um buffer que pode conter de uma cadeia de caracteres codificada dos dados do tamanho especificado.|
|[QPDecode](#qpdecode)|Decodifica uma cadeia de caracteres de dados que tem sido codificados no formato imprimíveis entre aspas, como por uma chamada anterior a [QPEncode](#qpencode).|
|[QPDecodeGetRequiredLength](#qpdecodegetrequiredlength)|Chame essa função para obter o tamanho em bytes de um buffer que pode conter os dados decodificados de uma cadeia de caracteres com codificação entre aspas imprimível do comprimento especificado.|
|[QPEncode](#qpencode)|Chame essa função para codificar alguns dados no formato entre aspas imprimível.|
|[QPEncodeGetRequiredLength](#qpencodegetrequiredlength)|Chame essa função para obter o tamanho em caracteres de um buffer que pode conter de uma cadeia de caracteres codificada dos dados do tamanho especificado.|
|[UUDecode](#uudecode)|Decodifica uma cadeia de caracteres de dados que tem sido uuencoded como por uma chamada anterior a [UUEncode](#uuencode).|
|[UUDecodeGetRequiredLength](#uudecodegetrequiredlength)|Chame essa função para obter o tamanho em bytes de um buffer que pode conter os dados decodificados de uma cadeia de caracteres com codificação UU do comprimento especificado.|
|[UUEncode](#uuencode)|Chame essa função para codificar alguns dados em UU. |
|[UUEncodeGetRequiredLength](#uuencodegetrequiredlength)|Chame essa função para obter o tamanho em caracteres de um buffer que pode conter de uma cadeia de caracteres codificada dos dados do tamanho especificado.|

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlenc.h  
 
## <a name="atlgethexvalue"></a> AtlGetHexValue
Chame essa função para obter o valor numérico de um dígito hexadecimal.  
  
```    
inline char AtlGetHexValue(char chIn) throw();  
```  
  
### <a name="parameters"></a>Parâmetros  
 `chIn`  
 O caractere hexadecimal '0'-'9', 'A'-'F' ou 'a'-'f'.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor numérico do caractere de entrada é interpretado como um dígito hexadecimal. Por exemplo, uma entrada de '0' Retorna um valor de 0 e uma entrada de 'A' Retorna um valor de 10. Se o caractere de entrada não é um dígito hexadecimal, essa função retornará -1.  
  
## <a name="atlgetversion"></a> AtlGetVersion
Chame essa função para obter a versão da biblioteca de ATL que você está usando.  
  
```  
ATLAPI_(DWORD) AtlGetVersion(void* pReserved);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pReserved`  
 Um ponteiro reservado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um `DWORD` valor de inteiro da versão da biblioteca de ATL que você está compilando ou em execução.  
  
## <a name="example"></a>Exemplo  
 A função deve ser chamada da seguinte maneira.  
  
 [!code-cpp[NVC_ATL_Utilities#95](../../atl/codesnippet/cpp/atl-text-encoding-functions_1.cpp)]  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlbase  

## <a name="atlhexdecode"></a> AtlHexDecode
Decodifica uma cadeia de caracteres de dados que tem sido codificados como texto hexadecimal, como por uma chamada anterior a [AtlHexEncode](#atlhexencode).  
  
```    
inline BOOL AtlHexDecode(  
   LPCSTR pSrcData,  
   int nSrcLen,  
   LPBYTE pbDest,  
   int* pnDestLen) throw();  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pSrcData`  
 A cadeia de caracteres que contém os dados a ser decodificado.  
  
 `nSrcLen`  
 O comprimento em caracteres de `pSrcData`.  
  
 `pbDest`  
 Buffer alocada pelo chamador para receber os dados decodificados.  
  
 `pnDestLen`  
 Ponteiro para uma variável que contém o comprimento em bytes do `pbDest`. Se a função tiver êxito, a variável recebe o número de bytes gravados no buffer. Se a função falhar, a variável recebe o comprimento necessário em bytes do buffer.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **TRUE** em caso de sucesso, **FALSE** em caso de falha.  
  
## <a name="atlhexdecodegetrequiredlength"></a> AtlHexDecodeGetRequiredLength
Chame essa função para obter o tamanho em bytes de um buffer que pode conter os dados decodificados de uma cadeia de caracteres com codificação hexadecimal do comprimento especificado.  
  
```  
inline int AtlHexDecodeGetRequiredLength(int nSrcLen) throw();  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nSrcLen`  
 O número de caracteres na cadeia de caracteres codificada.  
  
### <a name="return-value"></a>Valor de retorno  
 O número de bytes necessários para um buffer que pode conter uma cadeia de caracteres decodificada `nSrcLen` caracteres.  
  
## <a name="atlhexencode"></a> AtlHexEncode
Chame essa função para codificar alguns dados como uma cadeia de caracteres de texto hexadecimal.  
  
```  
inline BOOL AtlHexEncode(  
   const BYTE * pbSrcData,  
   int nSrcLen,  
   LPSTR szDest,  
int * pnDestLen) throw();  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pbSrcData`  
 O buffer que contém os dados a ser decodificado.  
  
 `nSrcLen`  
 O comprimento em bytes de dados a ser decodificado.  
  
 `szDest`  
 Buffer alocada pelo chamador para receber os dados codificados.  
  
 `pnDestLen`  
 Ponteiro para uma variável que contém o comprimento em caracteres de `szDest`. Se a função tiver êxito, a variável recebe o número de caracteres gravada no buffer. Se a função falhar, a variável recebe o comprimento necessário em caracteres do buffer.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **TRUE** em caso de sucesso, **FALSE** em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Cada byte de dados de origem é codificado como 2 caracteres hexadecimais.  
  
## <a name="atlhexencodegetrequiredlength"></a> AtlHexEncodeGetRequiredLength
Chame essa função para obter o tamanho em caracteres de um buffer que pode conter de uma cadeia de caracteres codificada dos dados do tamanho especificado.  
  
```  
inline int AtlHexEncodeGetRequiredLength(int nSrcLen) throw();  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nSrcLen`  
 O número de bytes de dados a ser decodificado.  
  
### <a name="return-value"></a>Valor de retorno  
 O número de caracteres necessários para um buffer que pode conter dados codificados de `nSrcLen` bytes.  
  
## <a name="atlhexvalue"></a> AtlHexValue
Chame essa função para obter o valor numérico de um dígito hexadecimal.  
  
```  
inline short AtlHexValue(char chIn) throw();  
```  
  
### <a name="parameters"></a>Parâmetros  
 `chIn`  
 O caractere hexadecimal '0'-'9', 'A'-'F' ou 'a'-'f'.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor numérico do caractere de entrada é interpretado como um dígito hexadecimal. Por exemplo, uma entrada de '0' Retorna um valor de 0 e uma entrada de 'A' Retorna um valor de 10. Se o caractere de entrada não é um dígito hexadecimal, essa função retornará -1.  
  
## <a name="atlunicodetoutf8"></a> AtlUnicodeToUTF8
Chame essa função para converter uma cadeia de caracteres Unicode em UTF-8.  
  
```  
ATL_NOINLINE inline int AtlUnicodeToUTF8(  
   LPCWSTR wszSrc,  
   int nSrc,  
   LPSTR szDest,  
   int nDest) throw();  
```  
  
### <a name="parameters"></a>Parâmetros  
 *wszSrc*  
 A cadeia de caracteres Unicode a ser convertido  
  
 `nSrc`  
 O comprimento de caracteres da cadeia de caracteres Unicode.  
  
 `szDest`  
 Buffer alocada pelo chamador para receber a cadeia de caracteres convertida.  
  
 `nDest`  
 O comprimento em bytes do buffer.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o número de caracteres para a cadeia de caracteres convertida.  
  
### <a name="remarks"></a>Comentários  
 Para determinar o tamanho do buffer necessário para a cadeia de caracteres convertida, chamar esta função passagem 0 `szDest` e `nDest`.  
  
## <a name="bencode"></a> BEncode  
Chame essa função para converter alguns dados usando a codificação “B”.  
  
```  
inline BOOL BEncode(  
   BYTE* pbSrcData,  
   int nSrcLen,  
   LPSTR szDest,  
   int* pnDestLen,  
   LPCSTR pszCharSet) throw();  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pbSrcData`  
 O buffer que contém os dados a ser decodificado.  
  
 `nSrcLen`  
 O comprimento em bytes de dados a ser decodificado.  
  
 `szDest`  
 Buffer alocada pelo chamador para receber os dados codificados.  
  
 `pnDestLen`  
 Ponteiro para uma variável que contém o comprimento em caracteres de `szDest`. Se a função tiver êxito, a variável recebe o número de caracteres gravada no buffer. Se a função falhar, a variável recebe o comprimento necessário em caracteres do buffer.  
  
 `pszCharSet`  
 O conjunto a ser usado para a conversão de caracteres.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **TRUE** em caso de sucesso, **FALSE** em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 O esquema de codificação de "B" é descrito no RFC 2047 ([http://www.ietf.org/rfc/rfc2047.txt](http://www.ietf.org/rfc/rfc2047.txt)).  
  
## <a name="bencodegetrequiredlength"></a> BEncodeGetRequiredLength 
Chame essa função para obter o tamanho em caracteres de um buffer que pode conter de uma cadeia de caracteres codificada dos dados do tamanho especificado.  
  
```  
inline int BEncodeGetRequiredLength(int nSrcLen, int nCharsetLen) throw();  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nSrcLen`  
 O número de bytes de dados a ser decodificado.  
  
 `nCharsetLen`  
 O comprimento em caracteres do conjunto a ser usado para a conversão de caracteres.  
  
### <a name="return-value"></a>Valor de retorno  
 O número de caracteres necessários para um buffer que pode conter dados codificados de `nSrcLen` bytes.  
  
### <a name="remarks"></a>Comentários  
 O esquema de codificação de "B" é descrito no RFC 2047 ([http://www.ietf.org/rfc/rfc2047.txt](http://www.ietf.org/rfc/rfc2047.txt)).  
  
## <a name="escapexml"></a> EscapeXML
Chame essa função para converter os caracteres que não são seguros para uso em XML em seus equivalentes seguros.  
  
```  
inline int EscapeXML(  
   const wchar_t * szIn,  
   int nSrcLen,  
   wchar_t * szEsc,  
   int nDestLen,  
   DWORD dwFlags = ATL_ESC_FLAG_NONE) throw();  
```  
  
### <a name="parameters"></a>Parâmetros  
 `szIn`  
 A cadeia de caracteres a ser convertida.  
  
 *nSrclen*  
 O comprimento de caracteres da cadeia de caracteres a ser convertido.  
  
 *szEsc*  
 Buffer alocada pelo chamador para receber a cadeia de caracteres convertida.  
  
 *nDestLen*  
 O comprimento em caracteres do buffer alocado pelo chamador.  
  
 `dwFlags`  
 Sinalizadores de ATL_ESC que descrevem como a conversão a ser executada. 

- `ATL_ESC_FLAG_NONE` Comportamento padrão. Aspas marcas e apóstrofos não são convertidos.
- `ATL_ESC_FLAG_ATTR` Aspas marcas e apóstrofos são convertidos em `&quot;` e `&apos;` respectivamente.


  
### <a name="return-value"></a>Valor de retorno  
 O comprimento de caracteres da cadeia de caracteres convertida.  
  
### <a name="remarks"></a>Comentários  
 Possíveis conversões executadas por essa função são mostrados na tabela:  
  
|Origem|Destino|  
|------------|-----------------|  
|\<|&lt;|  
|>|&gt;|  
|&|&amp;|  
|'|&apos;|  
|"|&quot;|  
  
## <a name="getextendedchars"></a> GetExtendedChars
Chame essa função para obter o número de caracteres estendidos em uma cadeia de caracteres.  
  
```  
inline int GetExtendedChars(LPCSTR szSrc, int nSrcLen) throw();  
```  
  
### <a name="parameters"></a>Parâmetros  
 `szSrc`  
 A cadeia de caracteres a serem analisados.  
  
 `nSrcLen`  
 O comprimento da cadeia de caracteres.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o número de caracteres estendidos encontrado na cadeia de caracteres, conforme determinado pela [IsExtendedChar](#isextendedchar).  
  
## <a name="isextendedchar"></a> IsExtendedChar
Chame essa função para descobrir se um caractere fornecido é um caractere estendido (menor que 32, maior que 126, e não uma guia, um avanço de linha ou retorno de carro)  
  
```  
inline int IsExtendedChar(char ch) throw();  
```  
  
### <a name="parameters"></a>Parâmetros  
 *ch*  
 O caractere a ser testada  
  
### <a name="return-value"></a>Valor de retorno  
 **TRUE** se o caractere estendido, **FALSE** caso contrário.  
  
## <a name="qencode"></a> QEncode
Chame essa função para converter alguns dados usando a codificação “Q”.  
  
```  
inline BOOL QEncode(  
   BYTE* pbSrcData,  
   int nSrcLen,  
   LPSTR szDest,  
   int* pnDestLen,  
   LPCSTR pszCharSet,  
   int* pnNumEncoded = NULL) throw();  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pbSrcData`  
 O buffer que contém os dados a ser decodificado.  
  
 `nSrcLen`  
 O comprimento em bytes de dados a ser decodificado.  
  
 `szDest`  
 Buffer alocada pelo chamador para receber os dados codificados.  
  
 `pnDestLen`  
 Ponteiro para uma variável que contém o comprimento em caracteres de `szDest`. Se a função tiver êxito, a variável recebe o número de caracteres gravada no buffer. Se a função falhar, a variável recebe o comprimento necessário em caracteres do buffer.  
  
 `pszCharSet`  
 O conjunto a ser usado para a conversão de caracteres.  
  
 *pnNumEncoded*  
 Um ponteiro para uma variável que contém o número de caracteres não seguros que tiveram de ser convertido no retorno.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **TRUE** em caso de sucesso, **FALSE** em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 O esquema de codificação "P" é descrito no RFC 2047 ([http://www.ietf.org/rfc/rfc2047.txt](http://www.ietf.org/rfc/rfc2047.txt)).  
  
## <a name="qencodegetrequiredlength"></a> QEncodeGetRequiredLength 
Chame essa função para obter o tamanho em caracteres de um buffer que pode conter de uma cadeia de caracteres codificada dos dados do tamanho especificado.  
  
```  
inline int QEncodeGetRequiredLength(int nSrcLen, int nCharsetLen) throw();  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nSrcLen`  
 O número de bytes de dados a ser decodificado.  
  
 `nCharsetLen`  
 O comprimento em caracteres do conjunto a ser usado para a conversão de caracteres.  
  
### <a name="return-value"></a>Valor de retorno  
 O número de caracteres necessários para um buffer que pode conter dados codificados de `nSrcLen` bytes.  
  
### <a name="remarks"></a>Comentários  
 O esquema de codificação "P" é descrito no RFC 2047 ([http://www.ietf.org/rfc/rfc2047.txt](http://www.ietf.org/rfc/rfc2047.txt)).  
  
## <a name="qpdecode"></a> QPDecode
Decodifica uma cadeia de caracteres de dados que tem sido codificados no formato imprimíveis entre aspas, como por uma chamada anterior a [QPEncode](#qpencode).  
  
```  
inline BOOL QPDecode(  
   BYTE* pbSrcData,  
   int nSrcLen,  
   LPSTR szDest,  
   int* pnDestLen,  
   DWORD dwFlags = 0) throw();  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pbSrcData`  
 O buffer que contém os dados a ser decodificado.  
  
 [in] `nSrcLen`  
 O comprimento em bytes do `pbSrcData`.  
  
 [out] `szDest`  
 Buffer alocada pelo chamador para receber os dados decodificados.  
  
 [out] `pnDestLen`  
 Ponteiro para uma variável que contém o comprimento em bytes do `szDest`. Se a função tiver êxito, a variável recebe o número de bytes gravados no buffer. Se a função falhar, a variável recebe o comprimento necessário em bytes do buffer.  
  
 [in] `dwFlags`  
 Sinalizadores que descrevem como a conversão a ser executada. Consulte [ATLSMTP_QPENCODE sinalizadores](http://msdn.microsoft.com/library/6b15a3ab-8e57-49e4-8104-09b26ebb96c4).  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `TRUE` em caso de sucesso, `FALSE` em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 O esquema de codificação entre aspas imprimíveis é descrito na RFC 2045 ([http://www.ietf.org/rfc/rfc2045.txt](http://www.ietf.org/rfc/rfc2045.txt)).  
  
## <a name="qpdecodegetrequiredlength"></a> QPDecodeGetRequiredLength
Chame essa função para obter o tamanho em bytes de um buffer que pode conter os dados decodificados de uma cadeia de caracteres com codificação entre aspas imprimível do comprimento especificado.  
  
```  
inline int QPDecodeGetRequiredLength(int nSrcLen) throw();  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nSrcLen`  
 O número de caracteres na cadeia de caracteres codificada.  
  
### <a name="return-value"></a>Valor de retorno  
 O número de bytes necessários para um buffer que pode conter uma cadeia de caracteres decodificada `nSrcLen` caracteres.  
  
### <a name="remarks"></a>Comentários  
 O esquema de codificação entre aspas imprimíveis é descrito na RFC 2045 ([http://www.ietf.org/rfc/rfc2045.txt](http://www.ietf.org/rfc/rfc2045.txt)).  
  
## <a name="qpencode"></a> QPEncode
Chame essa função para codificar alguns dados no formato entre aspas imprimível.  
  
```  
inline BOOL QPEncode(  
   BYTE* pbSrcData,  
   int nSrcLen,  
   LPSTR szDest,  
   int* pnDestLen,  
   DWORD dwFlags = 0) throw ();  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pbSrcData`  
 O buffer que contém os dados a ser decodificado.  
  
 `nSrcLen`  
 O comprimento em bytes de dados a ser decodificado.  
  
 `szDest`  
 Buffer alocada pelo chamador para receber os dados codificados.  
  
 `pnDestLen`  
 Ponteiro para uma variável que contém o comprimento em caracteres de `szDest`. Se a função tiver êxito, a variável recebe o número de caracteres gravada no buffer. Se a função falhar, a variável recebe o comprimento necessário em caracteres do buffer.  
  
 `dwFlags`  
 Sinalizadores ATLSMTP_QPENCODE que descrevem como a conversão a ser executada. 
- `ATLSMTP_QPENCODE_DOT` Se um período aparece no início de uma linha, ela é adicionada à saída, bem como codificada.
- `ATLSMTP_QPENCODE_TRAILING_SOFT` Acrescenta `=\r\n` para a cadeia de caracteres codificada.

O esquema de codificação entre aspas imprimíveis é descrito em [2045 RFC](http://www.ietf.org/rfc/rfc2045.txt).
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **TRUE** em caso de sucesso, **FALSE** em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 O esquema de codificação entre aspas imprimíveis é descrito na RFC 2045 ([http://www.ietf.org/rfc/rfc2045.txt](http://www.ietf.org/rfc/rfc2045.txt)).  
  
## <a name="qpencodegetrequiredlength"></a> QPEncodeGetRequiredLength
Chame essa função para obter o tamanho em caracteres de um buffer que pode conter de uma cadeia de caracteres codificada dos dados do tamanho especificado.  
  
```  
inline int QPEncodeGetRequiredLength(int nSrcLen) throw ();  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nSrcLen`  
 O número de bytes de dados a ser decodificado.  
  
### <a name="return-value"></a>Valor de retorno  
 O número de caracteres necessários para um buffer que pode conter dados codificados de `nSrcLen` bytes.  
  
### <a name="remarks"></a>Comentários  
 O esquema de codificação entre aspas imprimíveis é descrito na RFC 2045 ([http://www.ietf.org/rfc/rfc2045.txt](http://www.ietf.org/rfc/rfc2045.txt)).  
  
## <a name="uudecode"></a> UUDecode
Decodifica uma cadeia de caracteres de dados que tem sido uuencoded como por uma chamada anterior a [UUEncode](#uuencode).  
  
```  
inline BOOL UUDecode(  
   BYTE* pbSrcData,  
   int nSrcLen,  
   BYTE* pbDest,  
   int* pnDestLen) throw ();  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pbSrcData`  
 A cadeia de caracteres que contém os dados a ser decodificado.  
  
 `nSrcLen`  
 O comprimento em bytes do `pbSrcData`.  
  
 `pbDest`  
 Buffer alocada pelo chamador para receber os dados decodificados.  
  
 `pnDestLen`  
 Ponteiro para uma variável que contém o comprimento em bytes do `pbDest`. Se a função tiver êxito, a variável recebe o número de bytes gravados no buffer. Se a função falhar, a variável recebe o comprimento necessário em bytes do buffer.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **TRUE** em caso de sucesso, **FALSE** em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Essa implementação uuencoding segue a especificação de P1003.2b/D11 POSIX.  
  
## <a name="uudecodegetrequiredlength"></a> UUDecodeGetRequiredLength
Chame essa função para obter o tamanho em bytes de um buffer que pode conter os dados decodificados de uma cadeia de caracteres com codificação UU do comprimento especificado.  
  
```  
inline int UUDecodeGetRequiredLength(int nSrcLen) throw ();  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nSrcLen`  
 O número de caracteres na cadeia de caracteres codificada.  
  
### <a name="return-value"></a>Valor de retorno  
 O número de bytes necessários para um buffer que pode conter uma cadeia de caracteres decodificada `nSrcLen` caracteres.  
  
### <a name="remarks"></a>Comentários  
 Essa implementação uuencoding segue a especificação de P1003.2b/D11 POSIX.  
  
## <a name="uuencode"></a> UUEncode
Chame essa função para codificar alguns dados em UU.  
  
```  
inline BOOL UUEncode(  
   const BYTE* pbSrcData,  
   int nSrcLen,  
   LPSTR szDest,  
   int* pnDestLen,  
   LPCTSTR lpszFile = _T("file"),  
   DWORD dwFlags = 0) throw ();  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pbSrcData`  
 O buffer que contém os dados a ser decodificado.  
  
 `nSrcLen`  
 O comprimento em bytes de dados a ser decodificado.  
  
 `szDest`  
 Buffer alocada pelo chamador para receber os dados codificados.  
  
 `pnDestLen`  
 Ponteiro para uma variável que contém o comprimento em caracteres de `szDest`. Se a função tiver êxito, a variável recebe o número de caracteres gravada no buffer. Se a função falhar, a variável recebe o comprimento necessário em caracteres do buffer.  
  
 *lpszFile*  
 O arquivo a ser adicionado ao cabeçalho quando ATLSMTP_UUENCODE_HEADER é especificado em `dwFlags`.  
  
 `dwFlags`  
 Sinalizadores de controlar o comportamento dessa função. 
- `ATLSMTP_UUENCODE_HEADE` O cabeçalho será codificado.
- `ATLSMTP_UUENCODE_END` Final será codificado.
- `ATLSMTP_UUENCODE_DOT` Capacidade interna de dados será executada.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **TRUE** em caso de sucesso, **FALSE** em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Essa implementação uuencoding segue a especificação de P1003.2b/D11 POSIX.  
  
## <a name="uuencodegetrequiredlength"></a> UUEncodeGetRequiredLength
Chame essa função para obter o tamanho em caracteres de um buffer que pode conter de uma cadeia de caracteres codificada dos dados do tamanho especificado.  
  
```  
inline int UUEncodeGetRequiredLength(int nSrcLen) throw ();  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nSrcLen`  
 O número de bytes de dados a ser decodificado.  
  
### <a name="return-value"></a>Valor de retorno  
 O número de caracteres necessários para um buffer que pode conter dados codificados de `nSrcLen` bytes.  
  
### <a name="remarks"></a>Comentários  
 Essa implementação uuencoding segue a especificação de P1003.2b/D11 POSIX.  
  
### <a name="see-also"></a>Consulte também  
 [Conceitos](../../atl/active-template-library-atl-concepts.md)   
 [Componentes de área de trabalho COM da ATL](../../atl/atl-com-desktop-components.md)   