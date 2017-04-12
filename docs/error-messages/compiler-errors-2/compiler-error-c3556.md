---
title: C3556 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C3556
dev_langs:
- C++
helpviewer_keywords:
- C3556
ms.assetid: 9b002dcc-494e-414f-9587-20c2a0a39333
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 6bb39630cd62895d855b466eefce80d70a2a30bc
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3556"></a>C3556 de erro do compilador
'expression': argumento incorreto para 'decltype'  
  
 O compilador não pode deduzir o tipo da expressão que é o argumento para o `decltype(``expression``)` especificador de tipo. No exemplo de código a seguir, o compilador não é possível deduzir o tipo do `myFunction` argumento porque `myFunction` está sobrecarregado.  
  
```  
void myFunction();  
void myFunction(int);  
decltype(myFunction); // C3556  
```
