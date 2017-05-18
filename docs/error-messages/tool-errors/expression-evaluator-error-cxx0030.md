---
title: "CXX0030 de erro do avaliador de expressão | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- CXX0030
dev_langs:
- C++
helpviewer_keywords:
- CAN0030
- CXX0030
ms.assetid: ada8b48c-09c8-49bf-ae23-313ed663c4fe
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
ms.openlocfilehash: 4a4e82e51943db988805f1ba76495218e8188d2e
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="expression-evaluator-error-cxx0030"></a>Erro CXX0030 (avaliador de expressão)
expressão não evaluatable  
  
 Avaliador de expressão do depurador não pôde obter um valor para a expressão como escrito. Uma causa provável é que a expressão se refere a memória que está fora do espaço de endereço do programa (um ponteiro nulo de referência é um exemplo). O Windows não permite acesso à memória que está fora do espaço de endereço do programa.  
  
 Você talvez queira reescreva a expressão usando parênteses para controlar a ordem de avaliação.  
  
 Esse erro é idêntico ao CAN0030.
