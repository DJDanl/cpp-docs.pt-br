---
title: C2087 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2087
dev_langs:
- C++
helpviewer_keywords:
- C2087
ms.assetid: 89761e83-415a-4468-a4c6-b6dedfd1dd6a
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
ms.openlocfilehash: 7a40aebeb2566d6b678c9f00f93475b287e9c07b
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2087"></a>C2087 de erro do compilador
'identifier': ausente subscrito  
  
 A definição de uma matriz com vários subscritos está faltando um valor subscrito para uma maior do que uma dimensão.  
  
 O exemplo a seguir gera C2087:  
  
```  
// C2087.cpp  
int main() {  
   char a[10][];   // C2087  
}  
```  
  
 Resolução possível:  
  
```  
// C2087b.cpp  
int main() {  
   char b[4][5];  
}  
```
