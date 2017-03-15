---
title: C2758 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2758
dev_langs:
- C++
helpviewer_keywords:
- C2758
ms.assetid: 1d273034-194c-4926-9869-142d1b219cbe
caps.latest.revision: 9
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
ms.openlocfilehash: 381f659400965f2f13c757bfe22114ee132f24dd
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2758"></a>C2758 de erro do compilador
'member': um membro de tipo de referência deve ser inicializado  
  
 Erro do compilador C2758 é causado quando o construtor não inicializar um membro de tipo de referência em uma lista de inicializadores. O compilador deixa o membro indefinido. Membro de referência devem variáveis inicializado quando declaradas ou receberá um valor na lista de inicialização do construtor.  
  
 O exemplo a seguir gera C2758:  
  
```  
// C2758.cpp  
// Compile by using: cl /W3 /c C2758.cpp  
struct A {  
   const int i;  
  
   A(int n) { };   // C2758  
   // try the following line instead  
   // A(int n) : i{n} {};  
};  
```
