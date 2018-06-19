---
title: C2679 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2679
dev_langs:
- C++
helpviewer_keywords:
- C2679
ms.assetid: 1a5f9d00-9190-4aa6-bc72-949f68ec136f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 24a304d88ccc6044c5358759efffa2a38dfeaf67
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33231807"
---
# <a name="compiler-error-c2679"></a>C2679 de erro do compilador
binário 'operator': Nenhum operador encontrado que receba um operando à direita do tipo 'type' (ou não há nenhuma conversão aceitável)  
  
 Para usar o operador, você deve sobrecarregá-lo para o tipo especificado ou definir uma conversão para um tipo para o qual o operador está definido.  
  
 O exemplo a seguir gera C2679:  
  
```  
// C2679.cpp  
class C {  
public:  
   C();   // no constructor with an int argument  
} c;  
  
class D {  
public:  
   D(int) {}  
   D(){}  
} d;  
  
int main() {  
   c = 10;   // C2679  
   d = 10;   // OK  
}  
```