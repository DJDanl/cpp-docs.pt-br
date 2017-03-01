---
title: C2803 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2803
dev_langs:
- C++
helpviewer_keywords:
- C2803
ms.assetid: 2cdbe374-8cc4-4c4e-ba15-062a7479e937
caps.latest.revision: 7
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
ms.openlocfilehash: bf6e622332f43ce90a1b71e4916b4b55fb8ca5cd
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2803"></a>C2803 de erro do compilador
'operador' deve ter pelo menos um parâmetro formal do tipo de classe  
  
 O operador sobrecarregado não tem um parâmetro de tipo de classe.  
  
 Você precisa passar pelo menos um parâmetro por referência (sem usar ponteiros e referências) ou valor para ser capaz de gravar "um< b" (a and b being of type class A). b"="" (a="" and="" b="" being="" of="" type="" class=""></ b" (a and b being of type class A).>  
  
 Se ambos os parâmetros forem ponteiros, ela será uma comparação pura de endereços de ponteiro e não usará a conversão definida pelo usuário.  
  
 O exemplo a seguir gera C2803:  
  
```  
// C2803.cpp  
// compile with: /c  
class A{};  
bool operator< (const A *left, const A *right);   // C2803  
// try the following line instead  
// bool operator< (const A& left, const A& right);  
```
