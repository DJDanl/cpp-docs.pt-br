---
title: "Operadores pós-fixados | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- operators [C], postfix
- postfix operators
ms.assetid: 76260011-1624-484e-8bef-72ae7ab556cc
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 5aa82ded9bf53a00efe33f589c832550da967c96
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="postfix-operators"></a>Operadores pós-fixados
Os operadores pós-fixados tem a precedência mais alta (a associação mais estreita) na avaliação da expressão.  
  
## <a name="syntax"></a>Sintaxe  
 *postfix-expression*:  
 *primary-expression*  
  
 *postfix-expression*  **[**  *expression*  **]**  
  
 *postfix-expression*  **(**  *argument-expression-list* opt**)**  
  
 *postfix-expression*  **.**  *identifier*  
  
 *postfix-expression*  **->**  *identifier*  
  
 *postfix-expression*  **++**  
  
 *postfix-expression*  **--**  
  
 Os operadores nesse nível de precedência são: subscritos de matriz, chamadas de função, membros de estrutura e união, e operadores de incremento e decremento pós-fixados.  
  
## <a name="see-also"></a>Consulte também  
 [Operadores C](../c-language/c-operators.md)