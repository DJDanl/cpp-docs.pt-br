---
title: Erro do compilador C2720
ms.date: 11/04/2016
f1_keywords:
- C2720
helpviewer_keywords:
- C2720
ms.assetid: 9ee3aab7-711b-4f5a-b2f1-cb62b130f1ce
ms.openlocfilehash: 24f4329ee631eafc7c2670d9ebf28609c22e7592
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80202120"
---
# <a name="compiler-error-c2720"></a>Erro do compilador C2720

> '*Identifier*': especificador de classe de armazenamento '*especificador*' inválido em membros

A classe de armazenamento não pode ser usada em membros de classe fora da declaração. Para corrigir esse erro, remova o especificador de [classe de armazenamento](../../cpp/storage-classes-cpp.md) desnecessário da definição do membro fora da declaração de classe.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2720 e mostra como corrigi-lo:

```cpp
// C2720.cpp
struct S {
   static int i;
};
static S::i;   // C2720 - remove the unneeded 'static' to fix it
```
