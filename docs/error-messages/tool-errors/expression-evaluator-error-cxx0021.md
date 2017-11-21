---
title: "CXX0021 de erro do avaliador de expressão | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: CXX0021
dev_langs: C++
helpviewer_keywords:
- CXX0021
- CAN0021
ms.assetid: d6c0c35a-16c2-42c0-a7d2-e910350a47f0
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: f14a0494ed580f5b9b76c8bf96e55866fc28f654
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="expression-evaluator-error-cxx0021"></a>Erro CXX0021 (avaliador de expressão)
struct ou união usados como escalar  
  
 Uma estrutura ou união foi usada em uma expressão, mas nenhum elemento foi especificado.  
  
 Ao manipular uma estrutura ou união variável, o nome da variável pode aparecer por si só, sem um qualificador de campo. Se uma estrutura ou união é usado em uma expressão, ele deve ser qualificado com o elemento específico desejado.  
  
 Especifique o elemento cujo valor é a ser usado na expressão.  
  
 Esse erro é idêntico ao CAN0021.