---
title: "CXX0021 de erro do avaliador de expressão | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- CXX0021
dev_langs:
- C++
helpviewer_keywords:
- CXX0021
- CAN0021
ms.assetid: d6c0c35a-16c2-42c0-a7d2-e910350a47f0
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
ms.openlocfilehash: fd8ffbed24cffcd7d7e0110f3cf7424f58ddf1d8
ms.lasthandoff: 02/25/2017

---
# <a name="expression-evaluator-error-cxx0021"></a>Erro CXX0021 (avaliador de expressão)
estrutura ou união usados como escalar  
  
 Uma estrutura ou união foi usado em uma expressão, mas nenhum elemento foi especificado.  
  
 Ao manipular uma estrutura ou variável de união, o nome da variável pode aparecer por si só, sem um qualificador de campo. Se uma estrutura ou união é usado em uma expressão, ele deve ser qualificado com o elemento específico desejado.  
  
 Especifica o elemento cujo valor deve ser usado na expressão.  
  
 Esse erro é idêntico ao CAN0021.
