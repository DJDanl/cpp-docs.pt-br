---
title: "Compilador aviso (nível 1) C4182 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4182
dev_langs:
- C++
helpviewer_keywords:
- C4182
ms.assetid: 8970f3c6-e2dd-407e-b2ec-964360eb8b43
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 8d64e2f0eab71bbdf0f5f7750313a6d4c50b1fc0
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4182"></a>Compilador C4182 de aviso (nível 1)
\#incluir é o nível de aninhamento 'número' profundidade; recursão infinita possíveis  
  
 O compilador ficou sem espaço na pilha devido ao número de aninhada incluem arquivos. Um arquivo de inclusão é aninhado quando ele está incluído em outro arquivo de inclusão.  
  
 Essa mensagem é informativa e precede erro [C1076](../../error-messages/compiler-errors-1/fatal-error-c1076.md).
