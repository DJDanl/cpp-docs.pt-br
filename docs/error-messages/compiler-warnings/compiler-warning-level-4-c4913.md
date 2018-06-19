---
title: Compilador (nível 4) de aviso C4913 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4913
dev_langs:
- C++
helpviewer_keywords:
- C4913
ms.assetid: b94aa52e-6029-4170-9134-017714931546
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: dbac505559f07e2c58b76970ba33b11a109d90b7
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33294616"
---
# <a name="compiler-warning-level-4-c4913"></a>Compilador C4913 de aviso (nível 4)
**usuário operador binário definido pelo ',' existe mas nenhuma sobrecarga pôde converter todos os operando, operador binário interno padrão ',' usado**  
  
 Uma chamada para o operador de vírgula interno ocorreu em um programa que tinha também um operador de vírgula sobrecarregados; não especificou uma conversão que você pensamento pode ter ocorrido.  
  
 O exemplo de código a seguir gera C4913:  
  
```  
// C4913.cpp  
// compile with: /W4  
struct A  
{  
};  
  
struct S  
{  
};  
  
struct B  
{  
   // B() { }  
   // B(S &s) { s; }  
};  
  
B operator , (A a, B b)     
{  
   a;  
   return b;  
}  
  
int main()  
{  
   A a;  
   B b;  
   S s;  
  
   a, b;   // OK calls user defined operator  
   a, s;   // C4913 uses builtin comma operator  
           // uncomment the conversion code in B to resolve.  
}  
```