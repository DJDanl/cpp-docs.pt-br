---
title: "CXX0030 de erro do avaliador de expressão | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: CXX0030
dev_langs: C++
helpviewer_keywords:
- CAN0030
- CXX0030
ms.assetid: ada8b48c-09c8-49bf-ae23-313ed663c4fe
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: ffa1dd85419943ede6a13d61cb82924c32b5e80a
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="expression-evaluator-error-cxx0030"></a>Erro CXX0030 (avaliador de expressão)
expressão não evaluatable  
  
 O avaliador de expressão do depurador não pôde obter um valor para a expressão como escrito. Uma causa provável é que a expressão se refere a memória que está fora do espaço de endereço do programa (referência de um ponteiro nulo é um exemplo). O Windows não permite acesso à memória que está fora do espaço de endereço do programa.  
  
 Talvez você queira reescreva a expressão usar parênteses para controlar a ordem de avaliação.  
  
 Esse erro é idêntico ao CAN0030.