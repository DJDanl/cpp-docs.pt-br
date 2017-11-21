---
title: C2720 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C2720
dev_langs: C++
helpviewer_keywords: C2720
ms.assetid: 9ee3aab7-711b-4f5a-b2f1-cb62b130f1ce
caps.latest.revision: "9"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 10c273d2c39d81397584ce674187057131542e89
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
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