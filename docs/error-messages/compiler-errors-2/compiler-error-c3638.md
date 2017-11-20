---
title: C3638 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C3638
dev_langs: C++
helpviewer_keywords: C3638
ms.assetid: 8d8bc5ca-75aa-480e-b6b6-3178fab51b1d
caps.latest.revision: "9"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 51048bb46dde49f432699e620b94d62fb8f6c131
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-error-c3638"></a>C3638 de erro do compilador
'operator': a conversão boxing padrão e os operadores de conversão unboxing não podem ser redefinidos  
  
 O compilador define um operador de conversão para cada classe gerenciada para dar suporte à conversão boxing implícita. Este operador não pode ser redefinido.  
  
 Para obter mais informações, consulte [conversão Boxing implícita](../../windows/boxing-cpp-component-extensions.md).  
  
 O exemplo a seguir gera C3638:  
  
```  
// C3638.cpp  
// compile with: /clr  
value struct V {  
   V(){}  
   static operator V^(V);   // C3638  
};  
  
int main() {  
   V myV;  
   V ^ pmyV = myV;   // operator supports implicit boxing  
}  
```