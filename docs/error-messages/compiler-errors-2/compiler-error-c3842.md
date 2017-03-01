---
title: C3842 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3842
dev_langs:
- C++
helpviewer_keywords:
- C3842
ms.assetid: 41a1a44a-c618-40a2-8d26-7da27d14095d
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
ms.openlocfilehash: bbed0840025d7db60aed4cffd15d6defbf2d04c0
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3842"></a>C3842 de erro do compilador
'function': não há suporte para 'const' e 'volátil' qualificadores em funções de membro do WinRT ou tipos gerenciados  
  
 [Const](../../cpp/const-cpp.md) e [volátil](../../cpp/volatile-cpp.md) não têm suporte em funções de membro de tempo de execução do Windows ou tipos gerenciados.  
  
 O exemplo a seguir gera C3842:  
  
```  
// C3842a.cpp  
// compile with: /clr /c  
public ref struct A {  
   void f() const {}   // C3842  
   void f() volatile {}   // C3842  
  
   void f() {}  
};  
```
