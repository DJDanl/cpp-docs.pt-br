---
title: Aviso do compilador (nível 1) C4744
ms.date: 11/04/2016
f1_keywords:
- C4744
helpviewer_keywords:
- C4744
ms.assetid: f2a7d0b5-afd5-4926-abc3-cfbd367e3ff5
ms.openlocfilehash: f932b1bcdf011678d4f85e0edf1e116a954b59fe
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81367373"
---
# <a name="compiler-warning-level-1-c4744"></a>Aviso do compilador (nível 1) C4744

'var' tem tipo diferente em 'file1' e 'file2': 'type1' e 'type2'

Uma variável externa referenciada ou definida em dois arquivos tem tipos diferentes nesses arquivos.  Para resolver, faça as definições do tipo iguais ou altere o nome da variável em um dos arquivos.

C4744 é emitido somente quando os arquivos são compilados com /GL.  Para obter mais informações, consulte [/GL (otimização de programa inteiro)](../../build/reference/gl-whole-program-optimization.md).

> [!NOTE]
> C4744 geralmente ocorre em arquivos C (não C++), porque em C++ um nome variável é decorado com informações de tipo.  Quando a amostra (abaixo) for compilada como C++, você terá erro de linker LNK2019.

## <a name="example"></a>Exemplo

Esta amostra contém a primeira definição.

```c
// C4744.c
// compile with: /c /GL
int global;
```

## <a name="example"></a>Exemplo

A seguinte amostra gera C4744.

```c
// C4744b.c
// compile with: C4744.c /GL /W1
// C4744 expected
#include <stdio.h>

extern unsigned global;

main()
{
    printf_s("%d\n", global);
}
```
