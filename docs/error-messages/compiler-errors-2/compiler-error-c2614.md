---
title: C2614 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2614
dev_langs:
- C++
helpviewer_keywords:
- C2614
ms.assetid: a550c1d5-8718-4e17-a888-b2619e00fe11
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a5783abd96e356affb8537f6fec278e368c692a3
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33229760"
---
# <a name="compiler-error-c2614"></a>C2614 de erro do compilador
'class1': inicialização de membro inválida: 'class2' não é uma base ou membro  
  
 Apenas classes base ou membro podem aparecer na lista de inicialização para uma classe ou estrutura.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C2614.  
  
```  
// C2614.cpp  
// compile with: /c  
struct A {  
   int i;  
   A( int ia ) : B( i ) {};   // C2614 B is not a member of A  
};  
  
struct A2 {  
   int B;  
   int i;  
   A2( int ia ) : B( i ) {};   // OK  
};  
```