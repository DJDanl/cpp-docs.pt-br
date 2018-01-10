---
title: C3913 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C3913
dev_langs: C++
helpviewer_keywords: C3913
ms.assetid: a678bfce-9524-470d-9f23-7d08ecb972c8
caps.latest.revision: "9"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 76cb4b094cdc1dddf6a33d0325a0f77d36d5b173
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c3913"></a>C3913 de erro do compilador
propriedade padrão deve ser indexada.  
  
 Uma propriedade padrão foi definida incorretamente.  
  
 Para obter mais informações, consulte [propriedade](../../windows/property-cpp-component-extensions.md).  
  
 O exemplo a seguir gera C3913:  
  
```  
// C3913.cpp  
// compile with: /clr /c  
ref struct X {  
   property int default {   // C3913  
   // try the following line instead  
   // property int default[int] {  
      int get(int) { return 0; }  
      void set(int, int) {}  
   }  
};  
```