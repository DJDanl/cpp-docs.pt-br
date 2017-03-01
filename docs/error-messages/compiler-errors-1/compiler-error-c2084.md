---
title: C2084 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2084
dev_langs:
- C++
helpviewer_keywords:
- C2084
ms.assetid: 990b107f-3721-4851-ae8b-4b69a8c149ed
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
ms.openlocfilehash: 0ecd2db7dc5ac207d8257b725be83cdce983d5c8
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2084"></a>C2084 de erro do compilador
função 'função' já tem um corpo  
  
 A função já foi definida.  
  
 Nas versões anteriores do Visual C++  
  
-   O compilador aceite vários especializações de modelo que é resolvido para o mesmo tipo real, embora as definições adicionais nunca estarão disponíveis. O compilador agora irá detectar essas várias definições  
  
-   Int32 e int foram tratados como tipos separados. O compilador trata agora \__int32 como um sinônimo para int. Isso significa que o compilador detectará várias definições se uma função estiver sobrecarregada em ambos \__int32 e int e apresentar um erro.  
  
 O exemplo a seguir gera C2084:  
  
```  
// C2084.cpp  
void Func(int);  
void Func(int) {}   // define function  
void Func(int) {}   // C2084 second definition  
```  
  
 Resolução possível:  
  
```  
// C2084b.cpp  
// compile with: /c  
void Func(int);  
void Func(int) {}  
```
