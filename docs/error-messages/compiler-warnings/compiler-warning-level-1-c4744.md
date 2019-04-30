---
title: Compilador aviso (nível 1) C4744
ms.date: 11/04/2016
f1_keywords:
- C4744
helpviewer_keywords:
- C4744
ms.assetid: f2a7d0b5-afd5-4926-abc3-cfbd367e3ff5
ms.openlocfilehash: 2118a32af8b99d35c1e1a6691561391ec5d2b8cc
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62385414"
---
# <a name="compiler-warning-level-1-c4744"></a>Compilador aviso (nível 1) C4744

'var' possui tipo diferente em 'file1' e 'file2': 'type1' e 'type2'

Uma variável externa referenciadas ou definidas em dois arquivos tem tipos diferentes nesses arquivos.  Para resolver, verifique as definições de tipo o mesmo, ou alterar o nome da variável em um dos arquivos.

C4744 é emitido somente quando arquivos são compilados com /GL.  Para obter mais informações, consulte [/GL (otimização de programa inteiro)](../../build/reference/gl-whole-program-optimization.md).

> [!NOTE]
>  C4744 geralmente ocorre em arquivos de C (não C++), porque em C++, um nome de variável é decorado com informações de tipo.  Quando o exemplo (abaixo) é compilado como C++, você obterá um erro de vinculador LNK2019.

## <a name="example"></a>Exemplo

Este exemplo contém a primeira definição.

```
// C4744.c
// compile with: /c /GL
int global;
```

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4744.

```
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