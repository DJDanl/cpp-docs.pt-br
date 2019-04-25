---
title: Erro do compilador C2720
ms.date: 11/04/2016
f1_keywords:
- C2720
helpviewer_keywords:
- C2720
ms.assetid: 9ee3aab7-711b-4f5a-b2f1-cb62b130f1ce
ms.openlocfilehash: c6499fd3f279099ea7c5b31860e70bdaa285e3f9
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62383042"
---
# <a name="compiler-error-c2720"></a>Erro do compilador C2720

> '*identificador*': '*especificador*' inválido em membros de especificador de classe de armazenamento

A classe de armazenamento não pode ser usada em membros de classe fora da declaração. Para corrigir esse erro, remova o desnecessários [classe de armazenamento](../../cpp/storage-classes-cpp.md) especificador da definição do membro fora da declaração de classe.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2720 e mostra como corrigi-lo:

```cpp
// C2720.cpp
struct S {
   static int i;
};
static S::i;   // C2720 - remove the unneeded 'static' to fix it
```