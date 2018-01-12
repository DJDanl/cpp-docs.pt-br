---
title: C4867 de aviso do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4867
dev_langs: C++
helpviewer_keywords: C4867
ms.assetid: 8a257d70-c3a7-462d-b285-e57c952a8bf7
caps.latest.revision: "16"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: a412080d05e570711fcc65926459f9d2fcc45ed3
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-c4867"></a>C4867 de aviso do compilador
'function': chamada de função faltando lista de argumentos; Use 'chamar' para criar um ponteiro para membro  
  
 Um ponteiro para função de membro foi inicializado incorretamente.  
  
 Esse aviso pode ser gerado como resultado do trabalho de conformidade do compilador que foi feito para o Visual C++ 2005: conformidade aprimorada de ponteiro-para-membro.  Código compilado antes do Visual C++ 2005 agora irá gerar C4867.  
  
 Esse aviso é emitido sempre como um erro. Use o [aviso](../../preprocessor/warning.md) pragma para desabilitar esse aviso. Para obter mais informações sobre C4867 e MFC/ATL, consulte [_ATL_ENABLE_PTM_WARNING](../../atl/reference/compiler-options-macros.md#_atl_enable_ptm_warning).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4867.  
  
```  
// C4867.cpp  
// compile with: /c  
class A {  
public:  
   void f(int) {}  
  
   typedef void (A::*TAmtd)(int);  
  
   struct B {  
      TAmtd p;  
   };  
  
   void g() {  
      B b = {f};   // C4867  
      B b2 = {&A::f};   // OK  
   }  
};  
```