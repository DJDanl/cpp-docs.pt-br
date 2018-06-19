---
title: C2863 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2863
dev_langs:
- C++
helpviewer_keywords:
- C2863
ms.assetid: 32561d67-a795-486b-b3b6-4b90a1acb176
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 272697a43f99993565fe9af13cde7de29289a93d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33262407"
---
# <a name="compiler-error-c2863"></a>C2863 de erro do compilador
'interface': uma interface não pode possuir friends  
  
 Declarar amigos em uma interface não é permitido.  
  
 O exemplo a seguir gera C2863:  
  
```  
// C2863.cpp  
// compile with: /c  
#include <unknwn.h>  
  
class CMyClass {  
   void *f();  
};   
  
__interface IMyInterface {  
   void g();  
  
   friend int h();   // 2863  
   friend interface IMyInterface1;  // C2863  
   friend void *CMyClass::f();  // C2863  
};  
```