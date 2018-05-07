---
title: C3244 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3244
dev_langs:
- C++
helpviewer_keywords:
- C3244
ms.assetid: dae6c49b-5212-4206-8f61-d4010c0b9969
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 24a652e94345b7c615b3181d088186eb80113848
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c3244"></a>C3244 de erro do compilador
'method': este método foi introduzido por 'interface', não por 'interface'  
  
 Você tentou [substituir explicitamente](../../cpp/explicit-overrides-cpp.md) um membro que existe em outra classe base, mas não existe na interface especificada.  
  
 O exemplo a seguir gera C3244:  
  
```  
// C3244.cpp  
#pragma warning(disable:4199)  
  
__interface IX15A {  
   void f();  
};  
  
__interface IX15B {  
   void g();  
};  
  
class CX15 : public IX15A, public IX15B {  
public:        
   void IX15A::f();  
   void IX15B::g();  
};  
  
void CX15::IX15A::g()   // C3244 occurs here  
{  
}  
```