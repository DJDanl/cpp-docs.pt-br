---
title: C2021 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2021
dev_langs:
- C++
helpviewer_keywords:
- C2021
ms.assetid: 064f32e2-3794-48d5-9767-991003dcb36a
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
ms.openlocfilehash: 18b1bd01ad3c570360f267555be895231b124ba8
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2021"></a>C2021 de erro do compilador
expoente valor, não 'character' esperado  
  
 O caractere usado como o expoente de uma constante de ponto flutuante não é um número válido. Certifique-se de usar um expoente que está no intervalo.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C2021:  
  
```  
// C2021.cpp  
float test1=1.175494351E;   // C2021  
```  
  
## <a name="example"></a>Exemplo  
 Resolução possível:  
  
```  
// C2021b.cpp  
// compile with: /c  
float test2=1.175494351E8;  
```
