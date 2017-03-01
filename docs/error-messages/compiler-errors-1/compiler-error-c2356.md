---
title: C2356 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2356
dev_langs:
- C++
helpviewer_keywords:
- C2356
ms.assetid: 84d5a816-9a61-4d45-9978-38e485bbf767
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
ms.openlocfilehash: 3ab566a2bba63b3e37d7cd266f35aa1b29902b2e
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2356"></a>C2356 de erro do compilador
segmento de inicialização não deve mudar durante unidade de tradução  
  
 Possíveis causas:  
  
-   `#pragma init_seg`precedido pelo código de inicialização de segmento  
  
-   `#pragma init_seg`precedido por outro`#pragma init_seg`  
  
 Para resolver, mova o código de inicialização de segmento até o início do módulo. Se várias áreas devem ser inicializadas, mova-os para separar os módulos.  
  
 O exemplo a seguir gera C2356:  
  
```  
// C2356.cpp  
#pragma warning(disable : 4075)  
  
int __cdecl myexit(void (__cdecl *)());  
int __cdecl myexit2(void (__cdecl *)());  
  
#pragma init_seg(".mine$m",myexit)  
#pragma init_seg(".mine$m",myexit2)   // C2356  
```
