---
title: C2667 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2667
dev_langs:
- C++
helpviewer_keywords:
- C2667
ms.assetid: 3c91d9d1-18fa-4e0d-a9ba-984d38980ca3
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f5458bc5dc9500ea7850833b073d40d66bfc6e2a
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c2667"></a>C2667 de erro do compilador
'function': nenhuma das sobrecargas número tem uma conversão melhor  
  
 Uma chamada de função sobrecarregada é ambígua e não pode ser resolvida.  
  
 A conversão necessária para corresponder aos parâmetros reais na chamada de função para uma das funções sobrecarregadas deve ser estritamente melhor do que as conversões necessárias por todas as outras funções sobrecarregadas.  
  
 Consulte o artigo da Base de dados de Conhecimento Q240869 para obter mais informações sobre a ordenação parcial de modelos de função.