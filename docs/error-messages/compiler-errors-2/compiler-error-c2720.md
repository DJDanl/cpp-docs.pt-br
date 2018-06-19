---
title: C2720 de erro do compilador | Microsoft Docs
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
ms.openlocfilehash: 8c6215cd2e83f1fa3a48c3cbd4970cd2d3466fc0
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33233519"
---
# <a name="compiler-error-c2720"></a>C2720 de erro do compilador  
  
> '*identificador*': '*especificador*' inválido em membros de especificador de classe de armazenamento  
  
A classe de armazenamento não pode ser usada em membros de classe fora da declaração. Para corrigir esse erro, remova o desnecessária [classe de armazenamento](../../cpp/storage-classes-cpp.md) especificador da definição do membro fora da declaração de classe.  
  
## <a name="example"></a>Exemplo  
  
O exemplo a seguir gera C2720 e mostra como corrigi-lo:  
  
```cpp  
// C2720.cpp  
struct S {  
   static int i;  
};  
static S::i;   // C2720 - remove the unneeded 'static' to fix it  
```