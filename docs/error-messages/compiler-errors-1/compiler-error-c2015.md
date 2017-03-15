---
title: C2015 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2015
dev_langs:
- C++
helpviewer_keywords:
- C2015
ms.assetid: 8f40af0a-3a5a-4d6a-8ed7-125966e6bfed
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
ms.openlocfilehash: a050f782398751c60c9131af714dacd11e8f05b1
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2015"></a>C2015 de erro do compilador
muitos caracteres na constante  
  
 Uma constante de caractere contém mais de dois caracteres. O limite é um caractere para constantes de caractere padrão e dois caracteres para constantes de caracteres longa.  
  
 Uma sequência de escape, como \t, é convertida em um único caractere.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C2015:  
  
```  
// C2015.cpp  
// compile with: /c  
  
char test1 = 'error';   // C2015  
char test2 = 'e';   // OK  
```  
  
## <a name="example"></a>Exemplo  
 C2015 também pode ocorrer ao usar uma extensão da Microsoft, constantes de caractere convertidas em inteiros.  O exemplo a seguir gera C2015:  
  
```  
// C2015b.cpp  
#include <stdio.h>  
  
int main()   
{  
    int a = 'abcde';   // C2015  
  
    int b = 'a';   // 'a' = ascii 0x61  
    printf_s("%x\n", b);  
}  
```
