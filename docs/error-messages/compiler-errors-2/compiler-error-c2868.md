---
title: C2868 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C2868
dev_langs: C++
helpviewer_keywords: C2868
ms.assetid: 6ff5837b-e66d-44d1-9d17-80af35e08d08
caps.latest.revision: "11"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 62c8ea961db2547976e39a8873542a9f85dc4be7
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-error-c2868"></a>C2868 de erro do compilador  
  
> '*identificador*': sintaxe inválida para declaração de using; esperado nome qualificado  
  
Um [usando declaração](../../cpp/using-declaration.md) requer um *nome qualificado*, um operador de escopo (`::`) separados de sequência de nomes de namespace, classe ou enumeração que termina com o nome do identificador. Um operador de resolução do escopo único pode ser usado para introduzir um nome do namespace global.  
  
## <a name="example"></a>Exemplo  
  
O exemplo a seguir gera C2868 e também mostra o uso correto:  
  
```cpp  
// C2868.cpp  
class X {  
public:  
   int i;  
};  
  
class Y : X {  
public:  
   using X::i;   // OK  
};  
  
int main() {  
   using X;   // C2868  
}  
```