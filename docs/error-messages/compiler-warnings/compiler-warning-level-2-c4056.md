---
title: "Compilador aviso (nível 2) C4056 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4056
dev_langs:
- C++
helpviewer_keywords:
- C4056
ms.assetid: a3c3a9b8-ec30-452d-96cb-3694adcce789
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
ms.openlocfilehash: c1e5423eb775b451aae57421ddcdd5658f9940eb
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-2-c4056"></a>Compilador C4056 de aviso (nível 2)
Estouro em aritmético constante de ponto flutuante  
  
 Aritmética de ponto flutuante de constante gera um resultado que excede o valor máximo permitido.  
  
 Esse aviso pode ser causado pelas otimizações do compilador executadas durante a aritmética constante. Você pode ignorar com segurança esse aviso se ele desaparece quando você desativa a otimização ([/Od](../../build/reference/od-disable-debug.md)).  
  
 O exemplo a seguir gera C4056:  
  
```  
// C4056.cpp  
// compile with: /W2 /LD  
#pragma warning (default : 4056)  
float fp_val = 1.0e300 * 1.0e300;   // C4056  
```
