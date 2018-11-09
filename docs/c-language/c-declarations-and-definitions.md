---
title: Declarações e definições C
ms.date: 11/04/2016
ms.assetid: 575f0c9b-5554-4346-be64-b2129ca9227f
ms.openlocfilehash: d0dbd74dd54b6ee80fc1f02cf1cb07379a778be0
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50427957"
---
# <a name="c-declarations-and-definitions"></a>Declarações e definições C

Uma "declaração" estabelece uma associação entre uma variável, uma função ou um tipo específico e os respectivos atributos. A [visão geral das declarações](../c-language/overview-of-declarations.md) apresenta a sintaxe ANSI para o não terminal `declaration`. Uma declaração também especifica onde e quando um identificador pode ser acessado (a "vinculação" de um identificador). Consulte [Tempo de vida, escopo, visibilidade e vinculação](../c-language/lifetime-scope-visibility-and-linkage.md) para obter informações sobre vinculação.

Uma "definição" de uma variável estabelece as mesmas associações que uma declaração, mas também faz com que ocorra a alocação de armazenamento para a variável.

Por exemplo, as funções `main`, `find` e `count` e as variáveis `var` e `val` são definidas em um arquivo de origem, nesta ordem:

```
int main() {}

int var = 0;
double val[MAXVAL];
char find( fileptr ) {}
int count( double f ) {}
```

As variáveis `var` e `val` podem ser usadas nas funções `find` e `count`; nenhuma declaração adicional é necessária. Porém, esses nomes não são visíveis (não podem ser acessados) em `main`.

## <a name="see-also"></a>Consulte também

[Arquivos e programas de origem](../c-language/source-files-and-source-programs.md)