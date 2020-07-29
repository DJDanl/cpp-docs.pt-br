---
title: Trígrafos
ms.date: 11/04/2016
helpviewer_keywords:
- ??) trigraph
- ??- trigraph
- question mark, in trigraphs
- ??= trigraph
- ?? trigraph
- ??< trigraph
- ??/ trigraph
- trigraphs
- '? symbol, trigraph'
- ??> trigraph
- ??! trigraph
- ??' trigraph
ms.assetid: 617f76ec-b8e8-4cfe-916c-4bc32cbd9aeb
ms.openlocfilehash: 3ed8849656ac57f4774825294aba7bb41a050eee
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87227745"
---
# <a name="trigraphs"></a>Trígrafos

O conjunto de caracteres de origem dos programas de origem em C está contido dentro do conjunto de caracteres ASCII de 7 bits, mas é um superconjunto do conjunto de código invariável ISO 646-1983. As sequências de trígrafos permitem que os programas em C sejam escritos usando apenas o conjunto de código invariável da ISO (Organização Internacional de Padronização). Trígrafos são sequências de três caracteres (introduzidos por dois pontos de interrogação consecutivos) que o compilador substitui pelos caracteres de pontuação correspondentes. Você pode usar trígrafos em arquivos de origem em C com um conjunto de caracteres que não contenha representações gráficas convenientes para alguns caracteres de pontuação.

O C++17 remove trígrafos da linguagem. As implementações podem continuar a dar suporte a trígrafos como parte do mapeamento definido pela implementação do arquivo de origem físico para o *conjunto de caracteres de origem básico*, embora o padrão incentive as implementações a não fazer isso. Por meio de C++14, os trígrafos tem suporte como em C.

O Visual C++ continua a dar suporte à substituição de trígrafo, mas é desabilitado por padrão. Para obter informações sobre como habilitar a substituição de trigraphl, consulte [ `/Zc:trigraphs` (substituição de trigrafos)](../build/reference/zc-trigraphs-trigraphs-substitution.md).

A tabela a seguir mostra as nove sequências de trígrafos. Em um arquivo de origem, todas as ocorrências dos caracteres de pontuação na primeira coluna são substituídas pelo caractere correspondente na segunda coluna.

### <a name="trigraph-sequences"></a>Sequências de trígrafos

| Trígrafo | Caractere de pontuação |
|----------|-----------------------|
| `??=` | `#` |
| `??(` | `[` |
| `??/` | `\` |
| `??)` | `]` |
| `??'` | `^` |
| `??<` | `{` |
| `??!` | `|` |
| `??>` | `}` |
| `??-` | `~` |

Um trígrafo é sempre tratado como um único caractere de origem. A conversão de trígrafos ocorre na primeira [fase de conversão](../preprocessor/phases-of-translation.md), antes do reconhecimento dos caracteres de escape em literais de cadeias e constantes de caracteres. Somente os nove trígrafos mostrados na tabela acima são reconhecidos. Todas as outras sequências de caracteres são mantidas sem conversão.

A sequência de escape de caractere, **`\?`** , impede a interpretação inapropriada das sequências de caracteres do tipo trigrafos. (Para obter informações sobre sequências de escape, consulte [sequências de escape](../c-language/escape-sequences.md).) Por exemplo, se você tentar imprimir a cadeia de caracteres `What??!` com esta `printf` instrução

```C
printf( "What??!\n" );
```

a cadeia impressa será `What|` porque `??!` é uma sequência de trígrafo que é substituída pelo caractere `|`. Escreva a instrução da seguinte maneira para imprimir a cadeia de caracteres corretamente:

```C
printf( "What?\?!\n" );
```

Nessa instrução `printf`, um caractere de escape de barra invertida na frente do segundo ponto de interrogação impede a interpretação errônea de `??!` como um trígrafo.

## <a name="see-also"></a>Confira também

[`/Zc:trigraphs`(Substituição de trigrafos)](../build/reference/zc-trigraphs-trigraphs-substitution.md)<br/>
[Identificadores de C](../c-language/c-identifiers.md)
