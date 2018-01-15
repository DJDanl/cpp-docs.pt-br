---
title: inline_recursion | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- inline_recursion_CPP
- vc-pragma.inline_recursion
dev_langs: C++
helpviewer_keywords:
- pragmas, inline_recursion
- inline_recursion pragma
ms.assetid: cfef5791-63b7-45ac-9574-623747b9b9c9
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: d749753e7eaf81284de72314f5f940fd2790962c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="inlinerecursion"></a>inline_recursion
Controla a expansão embutida das chamadas de função diretas ou mutuamente recursivas.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
#pragma inline_recursion( [{on | off}] )  
```  
  
## <a name="remarks"></a>Comentários  
 Usar este pragma para funções de controle marcada como [embutido](../cpp/inline-functions-cpp.md) e [inline](../cpp/inline-functions-cpp.md) ou funções que o compilador é automaticamente expandido na opção /Ob2. Esse pragma uso requer uma [/Ob](../build/reference/ob-inline-function-expansion.md) configuração de opção de compilador de 1 ou 2. O estado padrão para `inline_recursion` é desativado. Este pragma entra em vigor na primeira chamada de função após o pragma ser percebido e não afeta a definição da função.  
  
 O pragma `inline_recursion` controla como as funções recursivas são expandidas. Se `inline_recursion` está desativado e se uma chamada de função embutida chama a si mesma (direta ou indiretamente), a função será expandida apenas uma vez. Se `inline_recursion` está ativada, a função é expandida várias vezes até atingir o valor definido com o [inline_depth](../preprocessor/inline-depth.md) pragma, o valor padrão para funções recursivas que é definido pelo `inline_depth` pragma ou uma capacidade de limite .  
  
## <a name="see-also"></a>Consulte também  
 [Diretivas pragma e a palavra-chave pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)   
 [inline_depth](../preprocessor/inline-depth.md)   
 [/OB (expansão de função embutida)](../build/reference/ob-inline-function-expansion.md)