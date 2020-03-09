---
title: Funções de codificação de texto ATL
ms.date: 11/04/2016
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
ms.openlocfilehash: 1380d33c485c1ac895558bbcaf86c902c6074cd4
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78865013"
---
# <a name="atl-text-encoding-functions"></a>Funções de codificação de texto ATL

Essas funções dão suporte à codificação e decodificação de texto.

|||
|-|-|
|[AtlGetHexValue](#atlgethexvalue)|Chame essa função para obter o valor numérico de um dígito hexadecimal.|
|[AtlGetVersion](#atlgetversion)|Chame essa função para obter a versão da biblioteca do ATL que você está usando.  |
|[AtlHexDecode](#atlhexdecode)|Decodifica uma cadeia de caracteres de dados que foi codificada como texto hexadecimal, como por uma chamada anterior para [AtlHexEncode](#atlhexencode).|
|[AtlHexDecodeGetRequiredLength](#atlhexdecodegetrequiredlength)|Chame essa função para obter o tamanho em bytes de um buffer que pode conter os dados decodificados de uma cadeia de caracteres com codificação hexadecimal do comprimento especificado.|
|[AtlHexEncode](#atlhexencode)|Chame essa função para codificar alguns dados como uma cadeia de caracteres de texto hexadecimal.|
|[AtlHexEncodeGetRequiredLength](#atlhexencodegetrequiredlength)|Chame essa função para obter o tamanho em caracteres de um buffer que pode conter de uma cadeia de caracteres codificada dos dados do tamanho especificado.|
|[AtlHexValue](#atlhexvalue)|Chame essa função para obter o valor numérico de um dígito hexadecimal. |
|[AtlUnicodeToUTF8](#atlunicodetoutf8)|Chame essa função para converter uma cadeia de caracteres Unicode em UTF-8. |
|[BEncode](#bencode)|Chame essa função para converter alguns dados usando a codificação “B”.|
|[BEncodeGetRequiredLength](#bencodegetrequiredlength)|Chame essa função para obter o tamanho em caracteres de um buffer que pode conter de uma cadeia de caracteres codificada dos dados do tamanho especificado.|
|[EscapeXML](#escapexml)|Chame essa função para converter os caracteres que não são seguros para uso em XML em seus equivalentes seguros.|
|[GetExtendedChars](#getextendedchars)|Chame essa função para obter o número de caracteres estendidos em uma cadeia de caracteres.|
|[IsExtendedChar](#isextendedchar)|Chame essa função para descobrir se um determinado caractere é um caractere estendido (menos de 32, maior que 126 e não uma tabulação, alimentação de linha ou retorno de carro)|
|[QEncode](#qencode)|Chame essa função para converter alguns dados usando a codificação “Q”.  |
|[QEncodeGetRequiredLength](#qencodegetrequiredlength)|Chame essa função para obter o tamanho em caracteres de um buffer que pode conter de uma cadeia de caracteres codificada dos dados do tamanho especificado.|
|[QPDecode](#qpdecode)|Decodifica uma cadeia de caracteres de dados que foram codificados no formato entre aspas, como por uma chamada anterior para [QPEncode](#qpencode).|
|[QPDecodeGetRequiredLength](#qpdecodegetrequiredlength)|Chame essa função para obter o tamanho em bytes de um buffer que pode conter os dados decodificados de uma cadeia de caracteres com codificação entre aspas imprimível do comprimento especificado.|
|[QPEncode](#qpencode)|Chame essa função para codificar alguns dados no formato entre aspas imprimível.|
|[QPEncodeGetRequiredLength](#qpencodegetrequiredlength)|Chame essa função para obter o tamanho em caracteres de um buffer que pode conter de uma cadeia de caracteres codificada dos dados do tamanho especificado.|
|[UUDecode](#uudecode)|Decodifica uma cadeia de caracteres de dados que foi UUencoded, como por uma chamada anterior para [uuencode](#uuencode).|
|[UUDecodeGetRequiredLength](#uudecodegetrequiredlength)|Chame essa função para obter o tamanho em bytes de um buffer que pode conter os dados decodificados de uma cadeia de caracteres com codificação UU do comprimento especificado.|
|[UUEncode](#uuencode)|Chame essa função para codificar alguns dados em UU. |
|[UUEncodeGetRequiredLength](#uuencodegetrequiredlength)|Chame essa função para obter o tamanho em caracteres de um buffer que pode conter de uma cadeia de caracteres codificada dos dados do tamanho especificado.|

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** atlenc. h

## <a name="atlgethexvalue"></a>AtlGetHexValue

Chame essa função para obter o valor numérico de um dígito hexadecimal.

```
inline char AtlGetHexValue(char chIn) throw();
```

### <a name="parameters"></a>Parâmetros

*chIn*<br/>
O caractere hexadecimal ' 0 '-' 9 ', ' a-'F ' ou ' a-'F '.

### <a name="return-value"></a>Valor retornado

O valor numérico do caractere de entrada interpretado como um dígito hexadecimal. Por exemplo, uma entrada de ' 0 ' retorna um valor de 0 e uma entrada de ' A ' retorna um valor de 10. Se o caractere de entrada não for um dígito hexadecimal, essa função retornará-1.

## <a name="atlgetversion"></a>AtlGetVersion

Chame essa função para obter a versão da biblioteca do ATL que você está usando.

```
ATLAPI_(DWORD) AtlGetVersion(void* pReserved);
```

### <a name="parameters"></a>Parâmetros

*Preservação*<br/>
Um ponteiro reservado.

### <a name="return-value"></a>Valor retornado

Retorna um valor inteiro DWORD da versão da biblioteca do ATL que você está compilando ou executando.

## <a name="example"></a>{1&gt;Exemplo&lt;1}

A função deve ser chamada da seguinte maneira.

[!code-cpp[NVC_ATL_Utilities#95](../../atl/codesnippet/cpp/atl-text-encoding-functions_1.cpp)]

### <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** atlbase. h

## <a name="atlhexdecode"></a>AtlHexDecode

Decodifica uma cadeia de caracteres de dados que foi codificada como texto hexadecimal, como por uma chamada anterior para [AtlHexEncode](#atlhexencode).

```
inline BOOL AtlHexDecode(
   LPCSTR pSrcData,
   int nSrcLen,
   LPBYTE pbDest,
   int* pnDestLen) throw();
```

### <a name="parameters"></a>Parâmetros

*pSrcData*<br/>
A cadeia de caracteres que contém os dados a serem decodificados.

*nSrcLen*<br/>
O comprimento em caracteres de *pSrcData*.

*pbDest*<br/>
Buffer alocado ao chamador para receber os dados decodificados.

*pnDestLen*<br/>
Ponteiro para uma variável que contém o comprimento em bytes de *pbDest*. Se a função for realizada com sucesso, a variável receberá o número de bytes gravados no buffer. Se a função falhar, a variável receberá o comprimento necessário em bytes do buffer.

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro em caso de êxito, falso em caso de falha.

## <a name="atlhexdecodegetrequiredlength"></a>AtlHexDecodeGetRequiredLength

Chame essa função para obter o tamanho em bytes de um buffer que pode conter os dados decodificados de uma cadeia de caracteres com codificação hexadecimal do comprimento especificado.

```
inline int AtlHexDecodeGetRequiredLength(int nSrcLen) throw();
```

### <a name="parameters"></a>Parâmetros

*nSrcLen*<br/>
O número de caracteres na cadeia de caracteres codificada.

### <a name="return-value"></a>Valor retornado

O número de bytes necessários para um buffer que pode conter uma cadeia de caracteres decodificada de *nSrcLen* .

## <a name="atlhexencode"></a>AtlHexEncode

Chame essa função para codificar alguns dados como uma cadeia de caracteres de texto hexadecimal.

```
inline BOOL AtlHexEncode(
   const BYTE * pbSrcData,
   int nSrcLen,
   LPSTR szDest,
int * pnDestLen) throw();
```

### <a name="parameters"></a>Parâmetros

*pbSrcData*<br/>
O buffer que contém os dados a serem codificados.

*nSrcLen*<br/>
O comprimento em bytes dos dados a serem codificados.

*szDest*<br/>
Buffer alocado para o chamador para receber os dados codificados.

*pnDestLen*<br/>
Ponteiro para uma variável que contém o comprimento em caracteres de *szDest*. Se a função for realizada com sucesso, a variável receberá o número de caracteres gravados no buffer. Se a função falhar, a variável receberá o comprimento necessário em caracteres do buffer.

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

Cada byte de dados de origem é codificado como dois caracteres hexadecimais.

## <a name="atlhexencodegetrequiredlength"></a>AtlHexEncodeGetRequiredLength

Chame essa função para obter o tamanho em caracteres de um buffer que pode conter de uma cadeia de caracteres codificada dos dados do tamanho especificado.

```
inline int AtlHexEncodeGetRequiredLength(int nSrcLen) throw();
```

### <a name="parameters"></a>Parâmetros

*nSrcLen*<br/>
O número de bytes de dados a serem codificados.

### <a name="return-value"></a>Valor retornado

O número de caracteres necessários para um buffer que pode conter dados codificados de *nSrcLen* bytes.

## <a name="atlhexvalue"></a>AtlHexValue

Chame essa função para obter o valor numérico de um dígito hexadecimal.

```
inline short AtlHexValue(char chIn) throw();
```

### <a name="parameters"></a>Parâmetros

*chIn*<br/>
O caractere hexadecimal ' 0 '-' 9 ', ' a-'F ' ou ' a-'F '.

### <a name="return-value"></a>Valor retornado

O valor numérico do caractere de entrada interpretado como um dígito hexadecimal. Por exemplo, uma entrada de ' 0 ' retorna um valor de 0 e uma entrada de ' A ' retorna um valor de 10. Se o caractere de entrada não for um dígito hexadecimal, essa função retornará-1.

## <a name="atlunicodetoutf8"></a>AtlUnicodeToUTF8

Chame essa função para converter uma cadeia de caracteres Unicode em UTF-8.

```
ATL_NOINLINE inline int AtlUnicodeToUTF8(
   LPCWSTR wszSrc,
   int nSrc,
   LPSTR szDest,
   int nDest) throw();
```

### <a name="parameters"></a>Parâmetros

*wszSrc*<br/>
A cadeia de caracteres Unicode a ser convertida

*nSrc*<br/>
O comprimento em caracteres da cadeia de caracteres Unicode.

*szDest*<br/>
Buffer alocado ao chamador para receber a cadeia de caracteres convertida.

*nDest*<br/>
O comprimento em bytes do buffer.

### <a name="return-value"></a>Valor retornado

Retorna o número de caracteres para a cadeia de caracteres convertida.

### <a name="remarks"></a>Comentários

Para determinar o tamanho do buffer necessário para a cadeia de caracteres convertida, chame essa função passando 0 para *szDest* e *nDest*.

## <a name="bencode"></a>BEncode

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

*pbSrcData*<br/>
O buffer que contém os dados a serem codificados.

*nSrcLen*<br/>
O comprimento em bytes dos dados a serem codificados.

*szDest*<br/>
Buffer alocado para o chamador para receber os dados codificados.

*pnDestLen*<br/>
Ponteiro para uma variável que contém o comprimento em caracteres de *szDest*. Se a função for realizada com sucesso, a variável receberá o número de caracteres gravados no buffer. Se a função falhar, a variável receberá o comprimento necessário em caracteres do buffer.

*pszCharSet*<br/>
O conjunto de caracteres a ser usado para a conversão.

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

O esquema de codificação "B" é descrito em RFC 2047 ([https://www.ietf.org/rfc/rfc2047.txt](https://www.ietf.org/rfc/rfc2047.txt)).

## <a name="bencodegetrequiredlength"></a>BEncodeGetRequiredLength

Chame essa função para obter o tamanho em caracteres de um buffer que pode conter de uma cadeia de caracteres codificada dos dados do tamanho especificado.

```
inline int BEncodeGetRequiredLength(int nSrcLen, int nCharsetLen) throw();
```

### <a name="parameters"></a>Parâmetros

*nSrcLen*<br/>
O número de bytes de dados a serem codificados.

*nCharsetLen*<br/>
O comprimento em caracteres do conjunto de caracteres a ser usado para a conversão.

### <a name="return-value"></a>Valor retornado

O número de caracteres necessários para um buffer que pode conter dados codificados de *nSrcLen* bytes.

### <a name="remarks"></a>Comentários

O esquema de codificação "B" é descrito em RFC 2047 ([https://www.ietf.org/rfc/rfc2047.txt](https://www.ietf.org/rfc/rfc2047.txt)).

## <a name="escapexml"></a>EscapeXML

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

*szIn*<br/>
A cadeia de caracteres a ser convertida.

*nSrclen*<br/>
O comprimento em caracteres da cadeia de caracteres a ser convertida.

*szEsc*<br/>
Buffer alocado ao chamador para receber a cadeia de caracteres convertida.

*nDestLen*<br/>
O comprimento em caracteres do buffer alocado pelo chamador.

*dwFlags*<br/>
ATL_ESC sinalizadores que descrevem como a conversão deve ser executada.

- ATL_ESC_FLAG_NONE comportamento padrão. Aspas e apóstrofos não são convertidos.
- ATL_ESC_FLAG_ATTR as aspas e apóstrofos são convertidos em `&quot;` e `&apos;`, respectivamente.

### <a name="return-value"></a>Valor retornado

O comprimento em caracteres da cadeia de caracteres convertida.

### <a name="remarks"></a>Comentários

Conversões possíveis executadas por essa função são mostradas na tabela:

|Origem|Destino|
|------------|-----------------|
|\<|&lt;|
|>|&gt;|
|&|&amp;|
|'|&apos;|
|"|&quot;|

## <a name="getextendedchars"></a>GetExtendedChars

Chame essa função para obter o número de caracteres estendidos em uma cadeia de caracteres.

```
inline int GetExtendedChars(LPCSTR szSrc, int nSrcLen) throw();
```

### <a name="parameters"></a>Parâmetros

*szSrc*<br/>
A cadeia de caracteres a ser analisada.

*nSrcLen*<br/>
O comprimento da cadeia em caracteres.

### <a name="return-value"></a>Valor retornado

Retorna o número de caracteres estendidos encontrados na cadeia de caracteres conforme determinado por [IsExtendedChar](#isextendedchar).

## <a name="isextendedchar"></a>IsExtendedChar

Chame essa função para descobrir se um determinado caractere é um caractere estendido (menos de 32, maior que 126 e não uma tabulação, alimentação de linha ou retorno de carro)

```
inline int IsExtendedChar(char ch) throw();
```

### <a name="parameters"></a>Parâmetros

*CH*<br/>
O caractere a ser testado

### <a name="return-value"></a>Valor retornado

TRUE se o caractere for estendido; caso contrário, FALSE.

## <a name="qencode"></a>QEncode

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

*pbSrcData*<br/>
O buffer que contém os dados a serem codificados.

*nSrcLen*<br/>
O comprimento em bytes dos dados a serem codificados.

*szDest*<br/>
Buffer alocado para o chamador para receber os dados codificados.

*pnDestLen*<br/>
Ponteiro para uma variável que contém o comprimento em caracteres de *szDest*. Se a função for realizada com sucesso, a variável receberá o número de caracteres gravados no buffer. Se a função falhar, a variável receberá o comprimento necessário em caracteres do buffer.

*pszCharSet*<br/>
O conjunto de caracteres a ser usado para a conversão.

*pnNumEncoded*<br/>
Um ponteiro para uma variável que, em retorno, contém o número de caracteres não seguros que precisaram ser convertidos.

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

O esquema de codificação "Q" é descrito em RFC 2047 ([https://www.ietf.org/rfc/rfc2047.txt](https://www.ietf.org/rfc/rfc2047.txt)).

## <a name="qencodegetrequiredlength"></a>QEncodeGetRequiredLength

Chame essa função para obter o tamanho em caracteres de um buffer que pode conter de uma cadeia de caracteres codificada dos dados do tamanho especificado.

```
inline int QEncodeGetRequiredLength(int nSrcLen, int nCharsetLen) throw();
```

### <a name="parameters"></a>Parâmetros

*nSrcLen*<br/>
O número de bytes de dados a serem codificados.

*nCharsetLen*<br/>
O comprimento em caracteres do conjunto de caracteres a ser usado para a conversão.

### <a name="return-value"></a>Valor retornado

O número de caracteres necessários para um buffer que pode conter dados codificados de *nSrcLen* bytes.

### <a name="remarks"></a>Comentários

O esquema de codificação "Q" é descrito em RFC 2047 ([https://www.ietf.org/rfc/rfc2047.txt](https://www.ietf.org/rfc/rfc2047.txt)).

## <a name="qpdecode"></a>QPDecode

Decodifica uma cadeia de caracteres de dados que foram codificados no formato entre aspas, como por uma chamada anterior para [QPEncode](#qpencode).

```
inline BOOL QPDecode(
   BYTE* pbSrcData,
   int nSrcLen,
   LPSTR szDest,
   int* pnDestLen,
   DWORD dwFlags = 0) throw();
```

### <a name="parameters"></a>Parâmetros

*pbSrcData*<br/>
no O buffer que contém os dados a serem decodificados.

*nSrcLen*<br/>
no O comprimento em bytes de *pbSrcData*.

*szDest*<br/>
fora Buffer alocado ao chamador para receber os dados decodificados.

*pnDestLen*<br/>
fora Ponteiro para uma variável que contém o comprimento em bytes de *szDest*. Se a função for realizada com sucesso, a variável receberá o número de bytes gravados no buffer. Se a função falhar, a variável receberá o comprimento necessário em bytes do buffer.

*dwFlags*<br/>
no ATLSMTP_QPENCODE sinalizadores que descrevem como a conversão deve ser executada.

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

O esquema de codificação com impressão entre aspas é descrito na RFC 2045 ([https://www.ietf.org/rfc/rfc2045.txt](https://www.ietf.org/rfc/rfc2045.txt)).

## <a name="qpdecodegetrequiredlength"></a>QPDecodeGetRequiredLength

Chame essa função para obter o tamanho em bytes de um buffer que pode conter os dados decodificados de uma cadeia de caracteres com codificação entre aspas imprimível do comprimento especificado.

```
inline int QPDecodeGetRequiredLength(int nSrcLen) throw();
```

### <a name="parameters"></a>Parâmetros

*nSrcLen*<br/>
O número de caracteres na cadeia de caracteres codificada.

### <a name="return-value"></a>Valor retornado

O número de bytes necessários para um buffer que pode conter uma cadeia de caracteres decodificada de *nSrcLen* .

### <a name="remarks"></a>Comentários

O esquema de codificação com impressão entre aspas é descrito na RFC 2045 ([https://www.ietf.org/rfc/rfc2045.txt](https://www.ietf.org/rfc/rfc2045.txt)).

## <a name="qpencode"></a>QPEncode

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

*pbSrcData*<br/>
O buffer que contém os dados a serem codificados.

*nSrcLen*<br/>
O comprimento em bytes dos dados a serem codificados.

*szDest*<br/>
Buffer alocado para o chamador para receber os dados codificados.

*pnDestLen*<br/>
Ponteiro para uma variável que contém o comprimento em caracteres de *szDest*. Se a função for realizada com sucesso, a variável receberá o número de caracteres gravados no buffer. Se a função falhar, a variável receberá o comprimento necessário em caracteres do buffer.

*dwFlags*<br/>
ATLSMTP_QPENCODE sinalizadores que descrevem como a conversão deve ser executada.

- ATLSMTP_QPENCODE_DOT se um ponto for exibido no início de uma linha, ele será adicionado à saída, bem como codificado.

- ATLSMTP_QPENCODE_TRAILING_SOFT acrescenta `=\r\n` à cadeia de caracteres codificada.

O esquema de codificação com impressão entre aspas é descrito em [RFC 2045](https://www.ietf.org/rfc/rfc2045.txt).

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

O esquema de codificação com impressão entre aspas é descrito na RFC 2045 ([https://www.ietf.org/rfc/rfc2045.txt](https://www.ietf.org/rfc/rfc2045.txt)).

## <a name="qpencodegetrequiredlength"></a>QPEncodeGetRequiredLength

Chame essa função para obter o tamanho em caracteres de um buffer que pode conter de uma cadeia de caracteres codificada dos dados do tamanho especificado.

```
inline int QPEncodeGetRequiredLength(int nSrcLen) throw ();
```

### <a name="parameters"></a>Parâmetros

*nSrcLen*<br/>
O número de bytes de dados a serem codificados.

### <a name="return-value"></a>Valor retornado

O número de caracteres necessários para um buffer que pode conter dados codificados de *nSrcLen* bytes.

### <a name="remarks"></a>Comentários

O esquema de codificação com impressão entre aspas é descrito na RFC 2045 ([https://www.ietf.org/rfc/rfc2045.txt](https://www.ietf.org/rfc/rfc2045.txt)).

## <a name="uudecode"></a>UUDecode

Decodifica uma cadeia de caracteres de dados que foi UUencoded, como por uma chamada anterior para [uuencode](#uuencode).

```
inline BOOL UUDecode(
   BYTE* pbSrcData,
   int nSrcLen,
   BYTE* pbDest,
   int* pnDestLen) throw ();
```

### <a name="parameters"></a>Parâmetros

*pbSrcData*<br/>
A cadeia de caracteres que contém os dados a serem decodificados.

*nSrcLen*<br/>
O comprimento em bytes de *pbSrcData*.

*pbDest*<br/>
Buffer alocado ao chamador para receber os dados decodificados.

*pnDestLen*<br/>
Ponteiro para uma variável que contém o comprimento em bytes de *pbDest*. Se a função for realizada com sucesso, a variável receberá o número de bytes gravados no buffer. Se a função falhar, a variável receberá o comprimento necessário em bytes do buffer.

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

Essa implementação de uuencoding segue a especificação POSIX P 1003.2 b/D11.

## <a name="uudecodegetrequiredlength"></a>UUDecodeGetRequiredLength

Chame essa função para obter o tamanho em bytes de um buffer que pode conter os dados decodificados de uma cadeia de caracteres com codificação UU do comprimento especificado.

```
inline int UUDecodeGetRequiredLength(int nSrcLen) throw ();
```

### <a name="parameters"></a>Parâmetros

*nSrcLen*<br/>
O número de caracteres na cadeia de caracteres codificada.

### <a name="return-value"></a>Valor retornado

O número de bytes necessários para um buffer que pode conter uma cadeia de caracteres decodificada de *nSrcLen* .

### <a name="remarks"></a>Comentários

Essa implementação de uuencoding segue a especificação POSIX P 1003.2 b/D11.

## <a name="uuencode"></a>UUEncode

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

*pbSrcData*<br/>
O buffer que contém os dados a serem codificados.

*nSrcLen*<br/>
O comprimento em bytes dos dados a serem codificados.

*szDest*<br/>
Buffer alocado para o chamador para receber os dados codificados.

*pnDestLen*<br/>
Ponteiro para uma variável que contém o comprimento em caracteres de *szDest*. Se a função for realizada com sucesso, a variável receberá o número de caracteres gravados no buffer. Se a função falhar, a variável receberá o comprimento necessário em caracteres do buffer.

*lpszFile*<br/>
O arquivo a ser adicionado ao cabeçalho quando ATLSMTP_UUENCODE_HEADER é especificado em *dwFlags*.

*dwFlags*<br/>
Sinalizadores que controlam o comportamento dessa função.

- ATLSMTP_UUENCODE_HEADE o cabeçalho será codificado.

- ATLSMTP_UUENCODE_END o final será codificado.

- ATLSMTP_UUENCODE_DOT as coisas de dados serão executadas.

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

Essa implementação de uuencoding segue a especificação POSIX P 1003.2 b/D11.

## <a name="uuencodegetrequiredlength"></a>UUEncodeGetRequiredLength

Chame essa função para obter o tamanho em caracteres de um buffer que pode conter de uma cadeia de caracteres codificada dos dados do tamanho especificado.

```
inline int UUEncodeGetRequiredLength(int nSrcLen) throw ();
```

### <a name="parameters"></a>Parâmetros

*nSrcLen*<br/>
O número de bytes de dados a serem codificados.

### <a name="return-value"></a>Valor retornado

O número de caracteres necessários para um buffer que pode conter dados codificados de *nSrcLen* bytes.

### <a name="remarks"></a>Comentários

Essa implementação de uuencoding segue a especificação POSIX P 1003.2 b/D11.

## <a name="see-also"></a>Consulte também

[Conceitos](../active-template-library-atl-concepts.md)<br/>
[Componentes de área de trabalho COM da ATL](../atl-com-desktop-components.md)
