---
title: CXX0024 de erro do avaliador de expressão | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- CXX0024
dev_langs:
- C++
helpviewer_keywords:
- CXX0024
- CAN0024
ms.assetid: eca6adbd-8ff2-4f51-a1cc-a2e9d5d0a47d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 50a07297ddabf269b003a1f14d967d1187fea96d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33302455"
---
# <a name="expression-evaluator-error-cxx0024"></a>Erro CXX0024 (avaliador de expressão)
operação precisa de valor de l  
  
 Foi especificada uma expressão que não é avaliada como um l-value de uma operação que requer um l-value.  
  
 Um l-value (assim chamado porque ele aparece no lado esquerdo de uma instrução de atribuição) é uma expressão que se refere a um local de memória.  
  
 Por exemplo, `buffer[count]` é um l-value válido que aponta para um local de memória específica. A comparação lógica `zed != 0` não é um l-value válido porque ela é avaliada como TRUE ou FALSE, não para um endereço de memória.  
  
 Esse erro é idêntico ao CAN0024.