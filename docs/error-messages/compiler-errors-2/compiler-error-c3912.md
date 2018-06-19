---
title: C3912 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3912
dev_langs:
- C++
helpviewer_keywords:
- C3912
ms.assetid: 674e050c-11fb-4db1-8bdf-a3e95b41161d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f9a5f392500b47771c6f19cc38d2fa2b5e679935
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33272689"
---
# <a name="compiler-error-c3912"></a>C3912 de erro do compilador
'event': tipo de evento deve ser um tipo delegate  
  
 Um evento foi declarado mas não era do tipo correto.  
  
 Para obter mais informações, consulte [evento](../../windows/event-cpp-component-extensions.md).  
  
 O exemplo a seguir gera C3912:  
  
```  
// C3912.cpp  
// compile with: /clr  
delegate void H();  
ref class X {  
   event int Ev;   // C3912  
   event H^ Ev2;   // OK  
};  
```