---
title: C2919 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2919
dev_langs:
- C++
helpviewer_keywords:
- C2919
ms.assetid: 140a6db9-eb48-4c5e-84a7-a09d2653605b
caps.latest.revision: 13
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
ms.openlocfilehash: 4ca9fb301b3fbd684379e743daf81009663f405c
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2919"></a>C2919 de erro do compilador
'type': operadores não podem ser usados na superfície de publicada de um tipo WinRT  
  
 O sistema de tipo de tempo de execução do Windows não oferece suporte a funções de membro do operador na superfície de publicada de um tipo. Isso ocorre porque nem todas as linguagens podem consumir funções de membro de operador. Você pode criar funções de membro que podem ser chamadas de código C++ na mesma unidade de compilação ou de classe do operador particular ou interno.  
  
 Para corrigir esse problema, remova a função de membro do operador da interface pública ou alterá-la para uma função de membro nomeado. Por exemplo, em vez de `operator==`, nomeie a função de membro `Equals`.
