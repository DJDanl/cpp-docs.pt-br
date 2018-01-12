---
title: C2935 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: C2935
dev_langs: C++
helpviewer_keywords: C2935
ms.assetid: e11ef90d-0756-4e43-8a09-4974c6aa72a3
caps.latest.revision: "9"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: bf3e24aef4cb1111ca6018498a09c28a703aa531
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2935"></a>C2935 de erro do compilador
'class': tipo de id de classe redefinido como uma função global  
  
 Você não pode usar uma classe genérica ou modelo como uma função global.  
  
 Esse erro pode ocorrer se as chaves são combinadas incorretamente.  
  
 O exemplo a seguir gera C2935:  
  
```  
// C2935.cpp  
// compile with: /c  
template<class T>  
struct TC {};   
void TC<int>() {}   // C2935  
  
// OK  
struct TC2 {};   
void TC2() {}  
```  
  
 C2935 também pode ocorrer ao usar genéricos:  
  
```  
// C2935b.cpp  
// compile with: /clr /c  
generic<class T>   
ref struct GC { };  
void GC<int>() {}   // C2935  
void GC() {}   // OK  
```