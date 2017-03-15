---
title: "CXX0025 de erro do avaliador de expressão | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- CXX0025
dev_langs:
- C++
helpviewer_keywords:
- CAN0025
- CXX0025
ms.assetid: 3e2fb541-63b3-46ac-9f93-3dadb253bcf6
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
ms.openlocfilehash: 2a651538dd0c5e1e4d003b58d1989e5c0e83b80f
ms.lasthandoff: 02/25/2017

---
# <a name="expression-evaluator-error-cxx0025"></a>Erro CXX0025 (avaliador de expressão)
o operador precisa de estrutura/união  
  
 Um operador que usa uma expressão de `struct` ou **união** tipo foi aplicado a uma expressão que não seja um `struct` ou **união**.  
  
 Componentes de classe, estrutura ou união variáveis devem ter um nome totalmente qualificado. Componentes não podem ser inseridos sem a especificação completa.  
  
 Esse erro é idêntico ao CAN0025.
