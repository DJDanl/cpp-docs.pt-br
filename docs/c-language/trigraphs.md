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
ms.openlocfilehash: 001eb90b5cb4dda933571fd053598995d3ef613e
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62345299"
---
# <a name="trigraphs"></a>Trígrafos

O conjunto de caracteres de origem dos programas de origem em C está contido dentro do conjunto de caracteres ASCII de 7 bits, mas é um superconjunto do conjunto de código invariável ISO 646-1983. As sequências de trígrafos permitem que os programas em C sejam escritos usando apenas o conjunto de código invariável da ISO (Organização Internacional de Padronização). Trígrafos são sequências de três caracteres (introduzidos por dois pontos de interrogação consecutivos) que o compilador substitui pelos caracteres de pontuação correspondentes. Você pode usar trígrafos em arquivos de origem em C com um conjunto de caracteres que não contenha representações gráficas convenientes para alguns caracteres de pontuação.

O C++17 remove trígrafos da linguagem. As implementações podem continuar a dar suporte a trígrafos como parte do mapeamento definido pela implementação do arquivo de origem físico para o *conjunto de caracteres de origem básico*, embora o padrão incentive as implementações a não fazer isso. Por meio de C++14, os trígrafos tem suporte como em C.

O Visual C++ continua a dar suporte à substituição de trígrafo, mas é desabilitado por padrão. Para obter informações sobre como habilitar substituição de trígrafos, consulte [/Zc:trigraphs (Substituição de trígrafos)](../build/reference/zc-trigraphs-trigraphs-substitution.md).

A tabela a seguir mostra as nove sequências de trígrafos. Em um arquivo de origem, todas as ocorrências dos caracteres de pontuação na primeira coluna são substituídas pelo caractere correspondente na segunda coluna.

### <a name="trigraph-sequences"></a>Sequências de trígrafos

| Trígrafo | Caractere de pontuação |
|----------|-----------------------|
| ??= | # |
| ??( | \[ |
| ??/ | \\ |
| ??) | ] |
| ??' | ^ |
| ??\< | { |
| ??! | &#124; |
| ??> | } |
| ??- | ~ |

Um trígrafo é sempre tratado como um único caractere de origem. A conversão de trígrafos ocorre na primeira [fase de conversão](../preprocessor/phases-of-translation.md), antes do reconhecimento dos caracteres de escape em literais de cadeias e constantes de caracteres. Somente os nove trígrafos mostrados na tabela acima são reconhecidos. Todas as outras sequências de caracteres são mantidas sem conversão.

A sequência de escape de caractere, ** \\?**, impede a interpretação inapropriada de sequências de caracteres como trigraphs. (Para obter informações sobre sequências de escape, consulte [sequências de escape](../c-language/escape-sequences.md).) Por exemplo, se você tentar imprimir a cadeia de `What??!` caracteres com `printf` esta instrução

```C
printf( "What??!\n" );
```

a cadeia impressa será `What|` porque `??!` é uma sequência de trígrafo que é substituída pelo caractere `|`. Escreva a instrução da seguinte maneira para imprimir a cadeia de caracteres corretamente:

```C
printf( "What?\?!\n" );
```

Nessa instrução `printf`, um caractere de escape de barra invertida na frente do segundo ponto de interrogação impede a interpretação errônea de `??!` como um trígrafo.

## <a name="see-also"></a>Confira também

[/Zc:trigraphs (substituição de trígrafos)](../build/reference/zc-trigraphs-trigraphs-substitution.md)<br/>
[Identificadores de C](../c-language/c-identifiers.md)
