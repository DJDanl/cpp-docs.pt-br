---
title: Erro fatal C1509 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C1509
dev_langs: C++
helpviewer_keywords: C1509
ms.assetid: 40dd100d-c6ba-451c-bd26-2c99ec1c36d6
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 22cb22ea2186b16fd98d2714779b2475c51d15bc
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="fatal-error-c1509"></a>Erro fatal C1509
limite do compilador: muitos estados de manipulador de exceção na função 'function'. Simplifique a função  
  
 O código excede um limite interno nos Estados de manipulador de exceção (32.768 estados).  
  
 A causa mais comum é que a função contém uma expressão complexa de operadores aritméticos e variáveis de classe definida pelo usuário.  
  
### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir usando as seguintes soluções possíveis  
  
1.  Simplifique expressões atribuindo subexpressões comuns para variáveis temporárias.  
  
2.  Divida a função em funções menores.