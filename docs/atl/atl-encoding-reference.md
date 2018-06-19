---
title: Referência de codificação de ATL | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- encoding
- encoding, functions
ms.assetid: 82d4fdf3-3c4a-4fe2-b297-8ffb4714406f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1d8cbb23c390a47b1bbfb7b1a78b327f07b06869
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32358622"
---
# <a name="atl-encoding-reference"></a>Referência de codificação ATL
Há suporte para a codificação em uma variedade de padrões de Internet comuns como uuencode, hexadecimal e UTF8 pelo código encontrado em atlenc.h.  
  
### <a name="functions"></a>Funções  
  
|||  
|-|-|  
|[AtlGetHexValue](reference/atl-text-encoding-functions.md#atlgethexvalue)|Chame essa função para obter o valor numérico de um dígito hexadecimal.|  
|[AtlHexDecode](reference/atl-text-encoding-functions.md#atlhexdecode)|Decodifica uma cadeia de caracteres de dados que tem sido codificados como texto hexadecimal, como por uma chamada anterior a [AtlHexEncode](reference/atl-text-encoding-functions.md#atlhexencode).|  
|[AtlHexDecodeGetRequiredLength](reference/atl-text-encoding-functions.md#atlhexdecodegetrequiredlength)|Chame essa função para obter o tamanho em bytes de um buffer que pode conter os dados decodificados de uma cadeia de caracteres com codificação hexadecimal do comprimento especificado.|  
|[AtlHexEncode](reference/atl-text-encoding-functions.md#atlhexencode)|Chame essa função para codificar alguns dados como uma cadeia de caracteres de texto hexadecimal.|  
|[AtlHexEncodeGetRequiredLength](reference/atl-text-encoding-functions.md#atlhexencodegetrequiredlength)|Chame essa função para obter o tamanho em caracteres de um buffer que pode conter de uma cadeia de caracteres codificada dos dados do tamanho especificado.|  
|[AtlUnicodeToUTF8](reference/atl-text-encoding-functions.md#atlunicodetoutf8)|Chame essa função para converter uma cadeia de caracteres Unicode em UTF-8.|  
|[BEncode](reference/atl-text-encoding-functions.md#bencode)|Chame essa função para converter alguns dados usando a codificação “B”.|  
|[BEncodeGetRequiredLength](reference/atl-text-encoding-functions.md#bencodegetrequiredlength)|Chame essa função para obter o tamanho em caracteres de um buffer que pode conter de uma cadeia de caracteres codificada dos dados do tamanho especificado.|  
|[EscapeXML](reference/atl-text-encoding-functions.md#escapexml)|Chame essa função para converter os caracteres que não são seguros para uso em XML em seus equivalentes seguros.|  
|[GetExtendedChars](reference/atl-text-encoding-functions.md#getextendedchars)|Chame essa função para obter o número de caracteres estendidos em uma cadeia de caracteres.|  
|[IsExtendedChar](reference/atl-text-encoding-functions.md#isextendedchar)|Chame essa função para descobrir se um caractere fornecido é um caractere estendido (menor que 32, maior que 126, e não uma guia, um avanço de linha ou retorno de carro)|  
|[QEncode](reference/atl-text-encoding-functions.md#qencode)|Chame essa função para converter alguns dados usando a codificação “Q”.|  
|[QEncodeGetRequiredLength](reference/atl-text-encoding-functions.md#qencodegetrequiredlength)|Chame essa função para obter o tamanho em caracteres de um buffer que pode conter de uma cadeia de caracteres codificada dos dados do tamanho especificado.|  
|[QPDecode](reference/atl-text-encoding-functions.md#qpdecode)|Decodifica uma cadeia de caracteres de dados que tem sido codificados no formato imprimíveis entre aspas, como por uma chamada anterior a [QPEncode](reference/atl-text-encoding-functions.md#qpencode).|  
|[QPDecodeGetRequiredLength](reference/atl-text-encoding-functions.md#qpdecodegetrequiredlength)|Chame essa função para obter o tamanho em bytes de um buffer que pode conter os dados decodificados de uma cadeia de caracteres com codificação entre aspas imprimível do comprimento especificado.|  
|[QPEncode](reference/atl-text-encoding-functions.md#qpencode)|Chame essa função para codificar alguns dados no formato entre aspas imprimível.|  
|[QPEncodeGetRequiredLength](reference/atl-text-encoding-functions.md#qpencodegetrequiredlength)|Chame essa função para obter o tamanho em caracteres de um buffer que pode conter de uma cadeia de caracteres codificada dos dados do tamanho especificado.|  
|[UUDecode](reference/atl-text-encoding-functions.md#uudecode)|Decodifica uma cadeia de caracteres de dados que tem sido uuencoded como por uma chamada anterior a [UUEncode](reference/atl-text-encoding-functions.md#uuencode).|  
|[UUDecodeGetRequiredLength](reference/atl-text-encoding-functions.md#uudecodegetrequiredlength)|Chame essa função para obter o tamanho em bytes de um buffer que pode conter os dados decodificados de uma cadeia de caracteres com codificação UU do comprimento especificado.|  
|[UUEncode](reference/atl-text-encoding-functions.md#uuencode)|Chame essa função para codificar alguns dados em UU.|  
|[UUEncodeGetRequiredLength](reference/atl-text-encoding-functions.md#uuencodegetrequiredlength)|Chame essa função para obter o tamanho em caracteres de um buffer que pode conter de uma cadeia de caracteres codificada dos dados do tamanho especificado.|  
  
## <a name="see-also"></a>Consulte também  
 [Conceitos](../atl/active-template-library-atl-concepts.md)   
 [Componentes de área de trabalho COM da ATL](../atl/atl-com-desktop-components.md)

