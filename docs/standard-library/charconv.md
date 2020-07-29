---
title: '&lt;charconv&gt;'
ms.date: 07/22/2020
f1_keywords:
- <charconv>
helpviewer_keywords:
- charconv header
ms.openlocfilehash: 59807749105512e0eb61acfdf60ef463febbc3a8
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87246091"
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

| Type | DESCRIÇÃO |
|-|:-|
| [chars_format](chars-format-class.md) | Especifica o tipo de formatação, como científico, Hex e assim por diante. |
| [from_chars_result](from-chars-result-structure.md) | Mantém o resultado de uma `from_chars` conversão. |
| [to_chars_result](to-chars-result-structure.md) | Mantém o resultado de uma `to_chars` conversão. |

### <a name="functions"></a>Funções

| Função | Descrição |
|-|:-|
| [from_chars](charconv-functions.md#from_chars) | Converter caracteres em um número inteiro, flutuante ou duplo. |
| [to_chars](charconv-functions.md#to_chars)| Converta um inteiro, float ou Double em chars. |

## <a name="see-also"></a>Confira também

[Referência de Arquivos de Cabeçalho](cpp-standard-library-header-files.md)

