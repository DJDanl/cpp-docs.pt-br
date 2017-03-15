---
title: "Compilador aviso (nível 4) C4295 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4295
dev_langs:
- C++
helpviewer_keywords:
- C4295
ms.assetid: 20dbff85-9f62-4ca3-8fe9-079d4512006d
caps.latest.revision: 5
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
ms.openlocfilehash: 8afa9526c2a16c6a4062fd17480bd1d04bf51911
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-4-c4295"></a>Compilador C4295 de aviso (nível 4)
**'**   
 ***matriz* ': matriz é muito pequena para incluir um caractere nulo de terminação**  
  
 Uma matriz foi inicializada, mas o último caractere na matriz não é nulo; acessando a matriz pode produzir resultados inesperados.  
  
 O exemplo a seguir gera C4295:  
  
```  
// C4295.c  
// compile with: /W4  
  
int main() {  
   char a[3] = "abc";   // C4295  
}  
```
