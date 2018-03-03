---
title: "Compilador (nível 1) de aviso C4182 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4182
dev_langs:
- C++
helpviewer_keywords:
- C4182
ms.assetid: 8970f3c6-e2dd-407e-b2ec-964360eb8b43
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 3ef78cebafcb07977611f92ad9f49a3d5b2c3dde
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-1-c4182"></a>Compilador C4182 de aviso (nível 1)
\#incluir o nível de aninhamento é 'number' profundidade; possível recursão infinita  
  
 O compilador ficou sem espaço suficiente na pilha devido ao número de aninhada incluem arquivos. Um arquivo de inclusão é aninhado quando ele está incluído em outro arquivo de inclusão.  
  
 Essa mensagem é informativa e precede erro [C1076](../../error-messages/compiler-errors-1/fatal-error-c1076.md).