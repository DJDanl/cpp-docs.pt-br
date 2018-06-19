---
title: C2585 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2585
dev_langs:
- C++
helpviewer_keywords:
- C2585
ms.assetid: 05bb1a9c-28fb-4a88-a1b5-aea85ebdee1c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 2ab812a4b6621acb28a4df636056598047f5c21e
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33230155"
---
# <a name="compiler-error-c2585"></a>C2585 de erro do compilador
conversão explícita para 'type' é ambíguo  
  
 A conversão de tipo pode produzir mais de um resultado.  
  
### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir  
  
1.  Conversão de um tipo de classe ou estrutura com base em várias heranças. Se o tipo herda a mesma classe base mais de uma vez, o operador ou função de conversão deve usar resolução de escopo (`::`) para especificar que as classes herdadas para usar na conversão.  
  
2.  Um operador de conversão e um construtor foram definidas fazer a mesma conversão.