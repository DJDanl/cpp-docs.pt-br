---
title: Erro fatal C1509 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C1509
dev_langs:
- C++
helpviewer_keywords:
- C1509
ms.assetid: 40dd100d-c6ba-451c-bd26-2c99ec1c36d6
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 3d3fc7a7be867a7137dab4155984cf1844b661ea
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="fatal-error-c1509"></a>Erro fatal C1509
limite do compilador: muitos estados de manipulador de exceção na função 'function'. Simplifique a função  
  
 O código excede um limite interno nos Estados de manipulador de exceção (32.768 estados).  
  
 A causa mais comum é que a função contém uma expressão complexa de operadores aritméticos e variáveis de classe definida pelo usuário.  
  
### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir usando as seguintes soluções possíveis  
  
1.  Simplifique expressões atribuindo subexpressões comuns para variáveis temporárias.  
  
2.  Divida a função em funções menores.
