---
title: Aviso do compilador (nível 1) C4744
ms.date: 11/04/2016
f1_keywords:
- C4744
helpviewer_keywords:
- C4744
ms.assetid: f2a7d0b5-afd5-4926-abc3-cfbd367e3ff5
ms.openlocfilehash: 38a05c04181efb95ec3e7549c40056b8d223e128
ms.sourcegitcommit: c1fd917a8c06c6504f66f66315ff352d0c046700
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/16/2020
ms.locfileid: "90685548"
---
# <a name="compiler-warning-level-1-c4744"></a>Aviso do compilador (nível 1) C4744

' var ' tem um tipo diferente em ' arquivo1 ' e ' arquivo2 ': ' type1 ' e ' type2 '

Uma variável externa referenciada ou definida em dois arquivos tem tipos diferentes nesses arquivos.  Para resolver, torne as definições de tipo iguais ou altere o nome da variável em um dos arquivos.

C4744 é emitido somente quando os arquivos são compilados com/GL.  Para obter mais informações, consulte [/GL (otimização de programa inteiro)](../../build/reference/gl-whole-program-optimization.md).

> [!NOTE]
> C4744 geralmente ocorre em arquivos C (não C++), porque em C++ um nome de variável é decorado com informações de tipo.  Quando o exemplo (abaixo) for compilado como C++, você obterá o erro do vinculador LNK2019.

## <a name="examples"></a>Exemplos

Este exemplo contém a primeira definição.

```c
// C4744.c
// compile with: /c /GL
int global;
```

O exemplo a seguir gera C4744.

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
