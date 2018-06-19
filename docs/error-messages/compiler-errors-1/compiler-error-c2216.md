---
title: C2216 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2216
dev_langs:
- C++
helpviewer_keywords:
- C2216
ms.assetid: 250f6bdc-a5e1-495f-a1e8-6e8e7021ad9d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6514908a0c238b7f8bf1180f860d30448043a7a9
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33171553"
---
# <a name="compiler-error-c2216"></a>C2216 de erro do compilador
'keyword1' não pode ser usado com 'keyword2'  
  
 Duas palavras-chave que são mutuamente exclusivas foram usadas juntos.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C2216.  
  
```  
// C2216.cpp  
// compile with: /clr /c  
ref struct Y1 {  
   literal  
   static int staticConst2 = 10;   // C2216  
};  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C2216.  
  
```  
// C2216b.cpp  
// compile with: /clr /c  
public ref class X {  
   extern property int i { int get(); }   // C2216 extern not allowed on property  
   typedef property int i2;   // C2216 typedef not allowed on property  
};  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C2216.  
  
```  
// C2216c.cpp  
// compile with: /clr /c  
public interface struct I {  
   double f();  
   double g();  
   double h();  
};  
  
public ref struct R : I {  
   virtual double f() new override { return 0.0; }   // C2216  
   virtual double g() new { return 0.0; }   // OK  
   virtual double h() override { return 0.0; }   // OK  
};  
```