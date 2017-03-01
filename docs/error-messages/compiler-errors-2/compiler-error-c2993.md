---
title: C2993 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2993
dev_langs:
- C++
helpviewer_keywords:
- C2993
ms.assetid: 4ffd2b78-654b-46aa-95a6-b62101cf91c8
caps.latest.revision: 8
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
ms.openlocfilehash: 83d1c0b2c4da8b419c94afa359a8961e616b0dec
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2993"></a>C2993 de erro do compilador
'identifier': tipo inválido para parâmetro de modelo sem tipo 'parameter'  
  
 Você não pode declarar um modelo com uma estrutura ou união argumento. Use ponteiros para passar estruturas e uniões como parâmetros de modelo.  
  
 O exemplo a seguir gera C2993:  
  
```  
// C2993.cpp  
// compile with: /c  
// C2993 expected  
struct MyStruct {  
   int a;char b;  
};  
  
template <class T, struct MyStruct S>   // C2993  
  
// try the following line instead  
// template <class T, struct MyStruct * S>  
class CMyClass {};  
```  
  
 Esse erro também será gerado como resultado do trabalho de conformidade do compilador que foi feito no Visual Studio .NET 2003: parâmetros de modelo sem tipo não pode mais de ponto flutuante. O padrão C++ não permitir ponto flutuante parâmetros de modelo sem tipo.  
  
 Se for um modelo de função, use um argumento de função para passar o flutuante ponto de parâmetro de modelo sem tipo (esse código será válido nas versões Visual Studio .NET 2003 e Visual Studio .NET do Visual C++). Se for um modelo de classe, não há nenhuma solução alternativa mais simples.  
  
```  
// C2993b.cpp  
// compile with: /c  
template<class T, float f> void func(T) {}   // C2993  
  
// OK  
template<class T>   void func2(T, float) {}  
```
