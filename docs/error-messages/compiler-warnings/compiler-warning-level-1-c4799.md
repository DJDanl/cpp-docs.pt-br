---
title: "Compilador aviso (nível 1) C4799 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4799
dev_langs:
- C++
helpviewer_keywords:
- C4799
ms.assetid: 8ecbd06f-c778-4371-a2fb-c690b6743ec8
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 617a6b2d009744adb0a53685976ee07266cf4490
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4799"></a>Compilador C4799 de aviso (nível 1)
Nenhum EMMS no final da função 'function'  
  
 A função tem pelo menos uma instrução MMX, mas não tem uma instrução EMMS. Quando uma instrução de multimídia é usada, uma instrução EMMS também deve ser usada para limpar o word marca multimídia no final do código MMX. Para obter mais informações sobre instruções EMMS, consulte [diretrizes quando para uso EMMS](http://msdn.microsoft.com/en-us/a0c3b1e4-01a4-419c-a58f-ff1e97dea7d3).  
  
 Você pode obter C4799 quando usando ivec.h, indicando que o código não usa corretamente execute a instrução EMMS antes de retornar. Este é um aviso falso para esses cabeçalhos. Você pode desativá-los definindo _SILENCE_IVEC_C4799 ivec.h. No entanto, lembre-se de que isso evitará que o compilador também seja dar avisos corretos desse tipo.  
  
 Para obter informações relacionadas, consulte o [do conjunto de instruções MMX da Intel](../../assembler/inline/intel-s-mmx-instruction-set.md).
