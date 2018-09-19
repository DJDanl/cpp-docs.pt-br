---
title: Erro do compilador C2720 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2720
dev_langs:
- C++
helpviewer_keywords:
- C2720
ms.assetid: 9ee3aab7-711b-4f5a-b2f1-cb62b130f1ce
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c2d75c9847016102d4ae8609fb0a0a78726e4c67
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46084010"
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