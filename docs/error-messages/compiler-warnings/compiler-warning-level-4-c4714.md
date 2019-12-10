---
title: Aviso do compilador (nível 4) C4714
ms.date: 11/04/2016
f1_keywords:
- C4714
helpviewer_keywords:
- C4714
ms.assetid: 22c7fd0c-899d-4e9b-95f3-725b2c49fb46
ms.openlocfilehash: 8ea4212eaddf14546827728b31299063021a959f
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74989643"
---
# <a name="compiler-warning-level-4-c4714"></a>Aviso do compilador (nível 4) C4714

função ' function ' marcada como __forceinline não embutida

A função fornecida foi selecionada para expansão embutida, mas o compilador não executou o inalinhamento.

Embora `__forceinline` seja uma indicação mais forte para o compilador do que `__inline`, o inlining ainda é realizado no critério do compilador, mas nenhuma heurística é usada para determinar os benefícios de inlinear essa função.

Em alguns casos, o compilador não embutirá uma função específica por motivos mecânicos. Por exemplo, o compilador não será embutido:

- Uma função se resultaria em uma combinação de SEH e C++ eh.

- Algumas funções com a cópia de objetos construídos passados por valor Quando-GX/EHs/EHa estão ativadas.

- Funções que retornam um objeto inventor por valor Quando-GX/EHs/EHa está on.

- Funções com assembly embutido durante a compilação sem-Ogon/Ox/O1/O2.

- Funciona com uma lista de argumentos variáveis.

- Uma função com uma instrução tryC++ (manipulação de exceção).

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
