---
title: "Compilador aviso (nível 1) C4172 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4172
dev_langs:
- C++
helpviewer_keywords:
- C4172
ms.assetid: a8d2bf65-d8b1-4fe3-8340-a223d7e7fde6
caps.latest.revision: 6
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
ms.openlocfilehash: fdd327750abe0e1f1e67f3848aeb91213b48d457
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4172"></a>Compilador C4172 de aviso (nível 1)
retornando endereço de variável local ou temporária  
  
 Uma função retorna o endereço de um objeto temporário ou variável local. Variáveis locais e objetos temporários são destruídos quando uma função retorna, portanto o endereço retornado não é válido.  
  
 Recrie a função para que ela não retorna o endereço de um objeto local.  
  
 O exemplo a seguir gera C4172:  
  
```  
// C4172.cpp  
// compile with: /W1 /LD  
float f = 10;  
  
const double& bar() {  
// try the following line instead  
// const float& bar() {  
   return f;   // C4172  
}  
```
