---
title: Referência de codificação ATL
ms.date: 11/04/2016
helpviewer_keywords:
- encoding
- encoding, functions
ms.assetid: 82d4fdf3-3c4a-4fe2-b297-8ffb4714406f
ms.openlocfilehash: a284645030b5bcdb30b72d7df92231680efb36b4
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88831886"
---
# <a name="atl-encoding-reference"></a>Referência de codificação ATL

A codificação em uma variedade de padrões comuns da Internet, como uuencode, hexadecimal e UTF8, é suportada pelo código encontrado em *`atlenc.h`* .

### <a name="functions"></a>Funções

| Função | Caso de uso |
|--|--|
| [AtlGetHexValue](reference/atl-text-encoding-functions.md#atlgethexvalue) | Chame essa função para obter o valor numérico de um dígito hexadecimal. |
| [AtlHexDecode](reference/atl-text-encoding-functions.md#atlhexdecode) | Decodifica uma cadeia de caracteres de dados que foi codificada como texto hexadecimal, como por uma chamada anterior para [AtlHexEncode](reference/atl-text-encoding-functions.md#atlhexencode). |
| [AtlHexDecodeGetRequiredLength](reference/atl-text-encoding-functions.md#atlhexdecodegetrequiredlength) | Chame essa função para obter o tamanho em bytes de um buffer que pode conter os dados decodificados de uma cadeia de caracteres com codificação hexadecimal do comprimento especificado. |
| [AtlHexEncode](reference/atl-text-encoding-functions.md#atlhexencode) | Chame essa função para codificar alguns dados como uma cadeia de caracteres de texto hexadecimal. |
| [AtlHexEncodeGetRequiredLength](reference/atl-text-encoding-functions.md#atlhexencodegetrequiredlength) | Chame essa função para obter o tamanho em caracteres de um buffer que pode conter de uma cadeia de caracteres codificada dos dados do tamanho especificado. |
| [AtlUnicodeToUTF8](reference/atl-text-encoding-functions.md#atlunicodetoutf8) | Chame essa função para converter uma cadeia de caracteres Unicode em UTF-8. |
| [BEncode](reference/atl-text-encoding-functions.md#bencode) | Chame essa função para converter alguns dados usando a codificação “B”. |
| [BEncodeGetRequiredLength](reference/atl-text-encoding-functions.md#bencodegetrequiredlength) | Chame essa função para obter o tamanho em caracteres de um buffer que pode conter de uma cadeia de caracteres codificada dos dados do tamanho especificado. |
| [EscapeXML](reference/atl-text-encoding-functions.md#escapexml) | Chame essa função para converter os caracteres que não são seguros para uso em XML em seus equivalentes seguros. |
| [GetExtendedChars](reference/atl-text-encoding-functions.md#getextendedchars) | Chame essa função para obter o número de caracteres estendidos em uma cadeia de caracteres. |
| [IsExtendedChar](reference/atl-text-encoding-functions.md#isextendedchar) | Chame essa função para descobrir se um determinado caractere é um caractere estendido (menos de 32, maior que 126 e não uma tabulação, alimentação de linha ou retorno de carro) |
| [QEncode](reference/atl-text-encoding-functions.md#qencode) | Chame essa função para converter alguns dados usando a codificação “Q”. |
| [QEncodeGetRequiredLength](reference/atl-text-encoding-functions.md#qencodegetrequiredlength) | Chame essa função para obter o tamanho em caracteres de um buffer que pode conter de uma cadeia de caracteres codificada dos dados do tamanho especificado. |
| [QPDecode](reference/atl-text-encoding-functions.md#qpdecode) | Decodifica uma cadeia de caracteres de dados que foram codificados no formato entre aspas, como por uma chamada anterior para [QPEncode](reference/atl-text-encoding-functions.md#qpencode). |
| [QPDecodeGetRequiredLength](reference/atl-text-encoding-functions.md#qpdecodegetrequiredlength) | Chame essa função para obter o tamanho em bytes de um buffer que pode conter os dados decodificados de uma cadeia de caracteres com codificação entre aspas imprimível do comprimento especificado. |
| [QPEncode](reference/atl-text-encoding-functions.md#qpencode) | Chame essa função para codificar alguns dados no formato entre aspas imprimível. |
| [QPEncodeGetRequiredLength](reference/atl-text-encoding-functions.md#qpencodegetrequiredlength) | Chame essa função para obter o tamanho em caracteres de um buffer que pode conter de uma cadeia de caracteres codificada dos dados do tamanho especificado. |
| [UUDecode](reference/atl-text-encoding-functions.md#uudecode) | Decodifica uma cadeia de caracteres de dados que foi UUencoded, como por uma chamada anterior para [uuencode](reference/atl-text-encoding-functions.md#uuencode). |
| [UUDecodeGetRequiredLength](reference/atl-text-encoding-functions.md#uudecodegetrequiredlength) | Chame essa função para obter o tamanho em bytes de um buffer que pode conter os dados decodificados de uma cadeia de caracteres com codificação UU do comprimento especificado. |
| [UUEncode](reference/atl-text-encoding-functions.md#uuencode) | Chame essa função para codificar alguns dados em UU. |
| [UUEncodeGetRequiredLength](reference/atl-text-encoding-functions.md#uuencodegetrequiredlength) | Chame essa função para obter o tamanho em caracteres de um buffer que pode conter de uma cadeia de caracteres codificada dos dados do tamanho especificado. |

## <a name="see-also"></a>Confira também

[Conceitos](../atl/active-template-library-atl-concepts.md)<br/>
[Componentes da área de trabalho ATL COM](../atl/atl-com-desktop-components.md)
