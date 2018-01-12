---
title: "CXX0024 de erro do avaliador de expressão | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: CXX0024
dev_langs: C++
helpviewer_keywords:
- CXX0024
- CAN0024
ms.assetid: eca6adbd-8ff2-4f51-a1cc-a2e9d5d0a47d
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: c96bd943719afb0d974a5c4386742bea24396fd4
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="expression-evaluator-error-cxx0024"></a>Erro CXX0024 (avaliador de expressão)
operação precisa de valor de l  
  
 Foi especificada uma expressão que não é avaliada como um l-value de uma operação que requer um l-value.  
  
 Um l-value (assim chamado porque ele aparece no lado esquerdo de uma instrução de atribuição) é uma expressão que se refere a um local de memória.  
  
 Por exemplo, `buffer[count]` é um l-value válido que aponta para um local de memória específica. A comparação lógica `zed != 0` não é um l-value válido porque ela é avaliada como TRUE ou FALSE, não para um endereço de memória.  
  
 Esse erro é idêntico ao CAN0024.