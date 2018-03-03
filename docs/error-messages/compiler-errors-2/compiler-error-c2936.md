---
title: C2936 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C2936
dev_langs:
- C++
helpviewer_keywords:
- C2936
ms.assetid: 5d1ba0fc-0c78-4a37-a83b-1ef8527763be
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: b6c8c8661d4f1c1ecaf80ed35ec2153616e03b87
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2936"></a>C2936 de erro do compilador
'class': tipo de id de classe redefinido como uma variável de dados globais  
  
 Você não pode usar uma classe genérica ou modelo como uma variável de dados globais.  
  
 Esse erro pode ocorrer se as chaves são combinadas incorretamente.  
  
 O exemplo a seguir gera C2936:  
  
```  
// C2936.cpp  
// compile with: /c  
template<class T> struct TC { };   
int TC<int>;   // C2936  
  
// OK  
struct TC2 { };   
int TC2;  
```  
  
 C2936 também pode ocorrer ao usar genéricos:  
  
```  
// C2936b.cpp  
// compile with: /clr /c  
generic<class T>  
ref struct GC {};  
int GC<int>;   // C2936  
  
// OK  
ref struct GC2 {};  
int GC2;  
```