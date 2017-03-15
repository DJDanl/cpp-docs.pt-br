---
title: C4746 de aviso do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
dev_langs:
- C++
ms.assetid: 5e79ab46-6031-499a-a986-716c866b6c0e
caps.latest.revision: 2
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
ms.openlocfilehash: efd41f60cc1690c2694c1b3c94c16ef6b35bd56b
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-c4746"></a>C4746 de aviso do compilador
acesso volátil de '\<expressão >' está sujeito a /volatile: [iso | ms] definindo; considere o uso de funções intrínsecas __iso_volatile_load/armazenamento.  
  
 C4746 é emitido sempre que uma variável volátil é acessada diretamente. Ele é destinado para ajudar os desenvolvedores a identificar os locais de código que são afetados pelo modelo volátil específico no momento especificado (que pode ser controlado com o [/volátil](../../build/reference/volatile-volatile-keyword-interpretation.md) opção de compilador). Em particular, pode ser útil localizar as barreiras de memória de hardware gerados pelo compilador quando /volatile: MS é usado.  
  
 Intrínsecos __iso_volatile_load/armazenamento podem ser usados para acessar explicitamente a memória volátil sem ser afetado pelo modelo volátil. Usar esses intrínsecos não dispararão C4746.  
  
 Esse aviso é desativada por padrão. Consulte [compilador avisos que está desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.
