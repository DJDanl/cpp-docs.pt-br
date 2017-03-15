---
title: Compilador erro C2912 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2912
dev_langs:
- C++
helpviewer_keywords:
- C2912
ms.assetid: bd55cecd-ab1a-4636-ab8a-a00393fe7b3d
caps.latest.revision: 11
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 39f9a7aacd076e9ddf46da2c9aaf7fc2729d167b
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2912"></a>C2912 de erro do compilador
especialização explícita 'declaração' não é uma especialização de um modelo de função  
  
 Não é possível specialize uma função diferente do modelo.  
  
 O exemplo a seguir gera C2912:  
  
```  
// C2912.cpp  
// compile with: /c  
void f(char);  
template<> void f(char);   // C2912  
template<class T> void f(T);   // OK  
```  
  
 Esse erro também será gerado como resultado do trabalho de conformidade do compilador que foi feito no Visual Studio .NET 2003: para cada especialização explícita, você deve escolher os parâmetros da especialização explícita, modo que eles correspondam aos parâmetros do modelo primário.  
  
```  
// C2912b.cpp  
class CF {  
public:  
   template <class A> CF(const A& a) {}   // primary template  
  
   // attempted explicit specialization  
   template <> CF(const char* p) {}   // C2912  
  
   // try the following line instead  
   // template <> CF(const char& p) {}  
};  
```
