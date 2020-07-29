---
title: Aviso do compilador (nível 4) C4714
ms.date: 11/04/2016
f1_keywords:
- C4714
helpviewer_keywords:
- C4714
ms.assetid: 22c7fd0c-899d-4e9b-95f3-725b2c49fb46
ms.openlocfilehash: 286a9e6e12643d3dadd070e7c4cf4b2dd350c02c
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87219853"
---
# <a name="compiler-warning-level-4-c4714"></a>Aviso do compilador (nível 4) C4714

> função ' function ' marcada como __forceinline não embutida

A função fornecida foi selecionada para expansão embutida, mas o compilador não executou o inalinhamento.

Embora **`__forceinline`** o seja uma indicação mais forte para o compilador do que o **`__inline`** , o inlining ainda é realizado na critério do compilador, mas nenhuma heurística é usada para determinar os benefícios de inlinear essa função.

Em alguns casos, o compilador não embutirá uma função específica por motivos mecânicos. Por exemplo, o compilador não será embutido:

- Uma função se resultaria na mistura de SEH e C++ EH.

- Algumas funções com a cópia de objetos construídos passados por valor Quando-GX/EHs/EHa estão ativadas.

- Funções que retornam um objeto inventor por valor Quando-GX/EHs/EHa está on.

- Funções com assembly embutido durante a compilação sem-Ogon/Ox/O1/O2.

- Funciona com uma lista de argumentos variáveis.

- Uma função com uma **`try`** instrução (manipulação de exceção C++).

O exemplo a seguir gera C4714:

```cpp
// C4714.cpp
// compile with: /Ob1 /GX /W4
__forceinline void func1()
{
   try
   {
   }
   catch (...)
   {
   }
}

void func2()
{
   func1();   // C4714
}

int main()
{
}
```
