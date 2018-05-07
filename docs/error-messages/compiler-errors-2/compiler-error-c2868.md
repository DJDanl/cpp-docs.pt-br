---
title: C2868 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2868
dev_langs:
- C++
helpviewer_keywords:
- C2868
ms.assetid: 6ff5837b-e66d-44d1-9d17-80af35e08d08
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 84465453ca7a1d76a9dd6b199232384c2ef9124b
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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