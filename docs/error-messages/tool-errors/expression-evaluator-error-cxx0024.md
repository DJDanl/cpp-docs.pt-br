---
title: "CXX0024 de erro do avaliador de expressão | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- CXX0024
dev_langs:
- C++
helpviewer_keywords:
- CXX0024
- CAN0024
ms.assetid: eca6adbd-8ff2-4f51-a1cc-a2e9d5d0a47d
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
ms.openlocfilehash: be05862ff83f0700e1599adfc0973ba427812b8f
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="expression-evaluator-error-cxx0024"></a>Erro CXX0024 (avaliador de expressão)
a operação necessita de l-value  
  
 Foi especificada uma expressão que seja avaliada para um l-value de uma operação que requer um l-value.  
  
 Um l-value (assim chamado porque ele aparece no lado esquerdo de uma instrução de atribuição) é uma expressão que se refere a um local de memória.  
  
 Por exemplo, `buffer[count]` é um l-value válido que aponta para um local específico da memória. A comparação lógica `zed != 0` não é um l-value válido porque ela é avaliada como TRUE ou FALSE, não como um endereço de memória.  
  
 Esse erro é idêntico ao CAN0024.
