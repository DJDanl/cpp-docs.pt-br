---
title: "CXX0015 de erro do avaliador de expressão | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: CXX0015
dev_langs: C++
helpviewer_keywords:
- CXX0015
- CAN0015
ms.assetid: 35efaf77-d578-48d8-bfc5-fdeb2a46a8b5
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 6f671b39fcc0027fdad5308192c5cbd8b8973717
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="expression-evaluator-error-cxx0015"></a>Erro CXX0015 (avaliador de expressão)
expressão muito complexa (estouro de pilha)  
  
 A expressão inserida era muito complexa ou aninhadas muito profundamente para a quantidade de armazenamento disponível para o avaliador de expressão C.  
  
 Estouro geralmente ocorre devido a muitos cálculos pendentes.  
  
 Reorganize a expressão para que cada componente da expressão pode ser avaliada como ele é encontrado, em vez de ter que esperar para outras partes da expressão deve ser calculado.  
  
 Divida a expressão em vários comandos.  
  
 Esse erro é idêntico ao CAN0015.