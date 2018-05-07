---
title: C2244 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2244
dev_langs:
- C++
helpviewer_keywords:
- C2244
ms.assetid: d9911c12-ceb5-4f93-ac47-b44a485215c2
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4c5822a2e7fc2bc33f7c42f1ec2478899d69ca78
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c2244"></a>C2244 de erro do compilador
'Identificador': não é possível corresponder a definição de função a uma declaração existente  
  
 Um uso comum do operador + unário foi usado na frente de uma chamada de função que não tinham o parêntese.  
  
 Esse erro ocorre apenas em projetos do C++.  
  
 O exemplo a seguir gera C2244:  
  
```  
// C2244.cpp  
int func(char) {  
   return 0;  
}   
  
int func(int) {  
   return 0;  
}  
  
int main() {  
   +func;   // C2244  
}  
```  
  
 C2244 também pode ocorrer quando uma assinatura de função incorreta é usada para uma função de membro de um modelo de classe.  
  
```  
// C2244b.cpp  
// compile with: /c  
template<class T>   
class XYZ {  
   void func(T t);  
};  
  
template<class T>  
void XYZ<T>::func(int i) {}   // C2244 wrong function signature  
// try the following line instead  
// void XYZ<T>::func(T t) {}  
```  
  
 C2244 também pode ocorrer quando uma assinatura de função incorreta é usada para um modelo de função de membro.  
  
```  
// C2244c.cpp  
// compile with: /c  
class ABC {  
   template<class T>   
   void func(int i, T t);  
};  
  
template<class T>  
void ABC::func(int i) {}   // C2244 wrong signature  
// try the following line instead  
// void ABC::func(int i, T t) {}  
```  
  
 Você não pode parcialmente especializados um modelo de função.  
  
```  
// C2244d.cpp  
template<class T, class U>  
class QRS {  
   void func(T t, U u);  
};  
  
template<class T>  
void QRS<T,int>::func(T t, int u) {}   // C2244  
```