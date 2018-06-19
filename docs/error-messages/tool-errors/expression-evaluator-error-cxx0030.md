---
title: CXX0030 de erro do avaliador de expressão | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- CXX0030
dev_langs:
- C++
helpviewer_keywords:
- CAN0030
- CXX0030
ms.assetid: ada8b48c-09c8-49bf-ae23-313ed663c4fe
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 669c585c637129c1fb6a480d91b31e5a1264fd22
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33298110"
---
# <a name="expression-evaluator-error-cxx0030"></a>Erro CXX0030 (avaliador de expressão)
expressão não evaluatable  
  
 O avaliador de expressão do depurador não pôde obter um valor para a expressão como escrito. Uma causa provável é que a expressão se refere a memória que está fora do espaço de endereço do programa (referência de um ponteiro nulo é um exemplo). O Windows não permite acesso à memória que está fora do espaço de endereço do programa.  
  
 Talvez você queira reescreva a expressão usar parênteses para controlar a ordem de avaliação.  
  
 Esse erro é idêntico ao CAN0030.