---
title: CXX0021 de erro do avaliador de expressão | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- CXX0021
dev_langs:
- C++
helpviewer_keywords:
- CXX0021
- CAN0021
ms.assetid: d6c0c35a-16c2-42c0-a7d2-e910350a47f0
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 996fc46982d809da5e0b37b83f2940102892167e
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33299361"
---
# <a name="expression-evaluator-error-cxx0021"></a>Erro CXX0021 (avaliador de expressão)
struct ou união usados como escalar  
  
 Uma estrutura ou união foi usada em uma expressão, mas nenhum elemento foi especificado.  
  
 Ao manipular uma estrutura ou união variável, o nome da variável pode aparecer por si só, sem um qualificador de campo. Se uma estrutura ou união é usado em uma expressão, ele deve ser qualificado com o elemento específico desejado.  
  
 Especifique o elemento cujo valor é a ser usado na expressão.  
  
 Esse erro é idêntico ao CAN0021.