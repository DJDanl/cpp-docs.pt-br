---
title: Compilador (nível 1) de aviso C4182 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4182
dev_langs:
- C++
helpviewer_keywords:
- C4182
ms.assetid: 8970f3c6-e2dd-407e-b2ec-964360eb8b43
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 79e86076a9d8218d08bd7437e2a06878b6ee91ff
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33278175"
---
# <a name="compiler-warning-level-1-c4182"></a>Compilador C4182 de aviso (nível 1)
\#incluir o nível de aninhamento é 'number' profundidade; possível recursão infinita  
  
 O compilador ficou sem espaço suficiente na pilha devido ao número de aninhada incluem arquivos. Um arquivo de inclusão é aninhado quando ele está incluído em outro arquivo de inclusão.  
  
 Essa mensagem é informativa e precede erro [C1076](../../error-messages/compiler-errors-1/fatal-error-c1076.md).