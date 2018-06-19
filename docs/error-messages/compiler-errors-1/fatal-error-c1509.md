---
title: Erro fatal C1509 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C1509
dev_langs:
- C++
helpviewer_keywords:
- C1509
ms.assetid: 40dd100d-c6ba-451c-bd26-2c99ec1c36d6
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: fec83f6b6138eacc613e560b9da4557079d6677d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33198788"
---
# <a name="fatal-error-c1509"></a>Erro fatal C1509
limite do compilador: muitos estados de manipulador de exceção na função 'function'. Simplifique a função  
  
 O código excede um limite interno nos Estados de manipulador de exceção (32.768 estados).  
  
 A causa mais comum é que a função contém uma expressão complexa de operadores aritméticos e variáveis de classe definida pelo usuário.  
  
### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir usando as seguintes soluções possíveis  
  
1.  Simplifique expressões atribuindo subexpressões comuns para variáveis temporárias.  
  
2.  Divida a função em funções menores.