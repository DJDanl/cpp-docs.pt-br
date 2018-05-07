---
title: CXX0015 de erro do avaliador de expressão | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- CXX0015
dev_langs:
- C++
helpviewer_keywords:
- CXX0015
- CAN0015
ms.assetid: 35efaf77-d578-48d8-bfc5-fdeb2a46a8b5
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 945dbda4759fa2989acb0411d1a3216a5e9a036c
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="expression-evaluator-error-cxx0015"></a>Erro CXX0015 (avaliador de expressão)
expressão muito complexa (estouro de pilha)  
  
 A expressão inserida era muito complexa ou aninhadas muito profundamente para a quantidade de armazenamento disponível para o avaliador de expressão C.  
  
 Estouro geralmente ocorre devido a muitos cálculos pendentes.  
  
 Reorganize a expressão para que cada componente da expressão pode ser avaliada como ele é encontrado, em vez de ter que esperar para outras partes da expressão deve ser calculado.  
  
 Divida a expressão em vários comandos.  
  
 Esse erro é idêntico ao CAN0015.