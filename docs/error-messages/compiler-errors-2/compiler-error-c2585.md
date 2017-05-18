---
title: C2585 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2585
dev_langs:
- C++
helpviewer_keywords:
- C2585
ms.assetid: 05bb1a9c-28fb-4a88-a1b5-aea85ebdee1c
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: ec9787e04d5c3539bf671a575a9487af94c3910d
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2585"></a>C2585 de erro do compilador
conversão explícita 'type' é ambíguo  
  
 A conversão de tipo pode produzir mais de um resultado.  
  
### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir  
  
1.  Convertendo de um tipo de classe ou estrutura com base na herança múltipla. Se o tipo herda a mesma classe base mais de uma vez, o operador ou uma função de conversão deve usar a resolução de escopo (`::`) para especificar que as classes herdadas para usar na conversão.  
  
2.  Um operador de conversão e um construtor foram definidos fazendo a mesma conversão.
