---
title: C3740 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C3740
dev_langs: C++
helpviewer_keywords: C3740
ms.assetid: edb17a90-2307-4df6-943d-580460d26d2b
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 4e6e55276d3627bd4482d1b581d44b6e161f5ec4
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c3740"></a>C3740 de erro do compilador
modelos não é possível gerar ou receber eventos  
  
 Uma classe de modelo ou estrutura não pode conter [eventos](../../cpp/event-handling.md).  
  
 O exemplo a seguir gera C3740:  
  
```  
// C3740.cpp  
template <typename T>   // Delete the template specification  
struct E {  
   __event void f();   // C3740  
};  
  
int main() {  
}  
```