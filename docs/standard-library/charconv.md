---
title: '&lt;charconv&gt;'
ms.date: 07/22/2020
f1_keywords:
- <charconv>
helpviewer_keywords:
- charconv header
ms.openlocfilehash: c9dfb8e18a8f7fd367ec4f6b52b1a0af74b3f939
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91507713"
---
# <a name="ltcharconvgt"></a>&lt;charconv&gt;

Converta rapidamente uma sequência de caracteres em um valor inteiro ou de ponto flutuante e o contrário.
Uma maneira de usar essa biblioteca é gravar e circular valores de ponto flutuante em arquivos JSON e de texto.

As funções de conversão são ajustadas para desempenho e também oferecem suporte ao comportamento de viagem de ida e volta mais curto. O comportamento de viagem de ida e volta mais curto significa que quando um número é convertido em caracteres, apenas precisão suficiente é gravada para habilitar a recuperação do número original ao converter esses caracteres de volta em um ponto flutuante. Nenhuma outra função CRT ou STL fornece essa funcionalidade.

Alguns dos benefícios de usar a `<charconv>` biblioteca são:

- A sequência de caracteres que representa um valor numérico não precisa ser terminada em nulo. Da mesma forma, quando um número é convertido em chars, o resultado não é terminada em nulo.
- As funções de conversão não alocam memória. Você possui o buffer em todos os casos.
- As funções de conversão não são lançadas. Elas retornam uma estrutura que contém informações de erro.
- As conversões não são sensíveis ao modo de arredondamento em tempo de execução.
- Conversões não têm reconhecimento de localidade. Eles sempre imprimem e analisam pontos decimais como '. ' nunca como ', ' para localidades que usam vírgulas.

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<charconv>

**Namespace:** std

/std: c++ 17 ou posterior, é necessário.

## <a name="members"></a>Membros

### <a name="types"></a>Tipos

| Tipo | Descrição |
|-|:-|
| [chars_format](chars-format-class.md) | Especifica o tipo de formatação, como científico, Hex e assim por diante. |
| [from_chars_result](from-chars-result-structure.md) | Mantém o resultado de uma `from_chars` conversão. |
| [to_chars_result](to-chars-result-structure.md) | Mantém o resultado de uma `to_chars` conversão. |

### <a name="functions"></a>Funções

| Função | Descrição |
|-|:-|
| [from_chars](charconv-functions.md#from_chars) | Converter caracteres em um número inteiro, flutuante ou duplo. |
| [to_chars](charconv-functions.md#to_chars)| Converta um inteiro, float ou Double em chars. |

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](cpp-standard-library-header-files.md)
