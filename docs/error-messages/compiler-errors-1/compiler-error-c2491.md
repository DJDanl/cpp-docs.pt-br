---
title: C2491 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2491
dev_langs:
- C++
helpviewer_keywords:
- C2491
ms.assetid: 4e5a8f81-124e-402c-a5ec-d35a89b5469e
caps.latest.revision: 10
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
ms.openlocfilehash: d81db246ea10205e5fc1cf533c8eca276f864f71
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2491"></a>C2491 de erro do compilador
"identificador": definição da função dllimport não permitida  
  
 Dados, membros de dados estáticos e funções podem ser declarados como `dllimport`s, mas não definidos como `dllimport`s.  
  
 Para corrigir esse problema, remova o especificador `__declspec(dllimport)` da definição da função.  
  
 O seguinte exemplo gera C2491:  
  
```  
// C2491.cpp  
// compile with: /c  
// function definition  
void __declspec(dllimport) funcB() {}   // C2491  
  
// function declaration  
void __declspec(dllimport) funcB();   // OK  
```
