---
title: '#Diretiva undef (C/C++)'
ms.date: 08/29/2019
f1_keywords:
- '#undef'
helpviewer_keywords:
- '#undef directive'
- undef directive (#undef)
- preprocessor, directives
ms.assetid: 88900e0e-2c19-4a63-b681-f3d3133c24ca
ms.openlocfilehash: 1a69bc568579e7da7c7e3816cb67c8153b8f1a27
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70220208"
---
# <a name="undef-directive-cc"></a>Diretiva de #undef (CC++/)

Remove (não define) um nome criado anteriormente com `#define`.

## <a name="syntax"></a>Sintaxe

> **#undef** *identificador* do

## <a name="remarks"></a>Comentários

A diretiva **#undef** remove a definição atual do *identificador*. Consequentemente, ocorrências subsequentes do *identificador* são ignoradas pelo pré-processador. Para remover uma definição de macro usando **#undef**, conceda apenas o *identificador*de macro, não uma lista de parâmetros.

Você também pode aplicar a diretiva **#undef** a um identificador que não tem nenhuma definição anterior. Isso garante que o identificador seja indefinido. A substituição de macro não é executada dentro de instruções **#undef** .

A diretiva de **#undef** normalmente é emparelhada com `#define` uma diretiva para criar uma região em um programa de origem no qual um identificador tem um significado especial. Por exemplo, uma função específica do programa de origem pode usar constantes manifestas para definir os valores específicos que não afetam o restante do programa. A diretiva **#undef** também funciona com a `#if` diretiva para controlar a compilação condicional do programa de origem. Para obter mais informações, consulte [as diretivas #if, #elif, #else e #endif](../preprocessor/hash-if-hash-elif-hash-else-and-hash-endif-directives-c-cpp.md).

No exemplo a seguir, a diretiva **#undef** Remove definições de uma constante simbólica e uma macro. Somente o identificador de macro será fornecido.

```C
#define WIDTH 80
#define ADD( X, Y ) ((X) + (Y))
.
.
.
#undef WIDTH
#undef ADD
```

**Seção específica da Microsoft**

As macros podem ser indefinidas na linha de `/U` comando usando a opção, seguida pelos nomes de macro a serem indefinidos. O efeito de emitir esse comando é equivalente a uma sequência de instruções `#undef` de *nome de macro* no início do arquivo.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Diretivas de pré-processador](../preprocessor/preprocessor-directives.md)
