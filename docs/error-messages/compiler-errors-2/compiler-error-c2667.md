---
title: C2667 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2667
dev_langs:
- C++
helpviewer_keywords:
- C2667
ms.assetid: 3c91d9d1-18fa-4e0d-a9ba-984d38980ca3
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: c00e469b2c89c0fa7c3966ec31410324bf6c2ff1
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2667"></a>C2667 de erro do compilador
'function': nenhuma das sobrecargas número tem uma conversão melhor  
  
 Uma chamada de função sobrecarregada é ambígua e não pode ser resolvida.  
  
 A conversão necessária para corresponder aos parâmetros reais na chamada de função para uma das funções sobrecarregadas deve ser estritamente melhor do que as conversões necessárias por todas as outras funções sobrecarregadas.  
  
 Consulte o artigo da Base de dados de Conhecimento Q240869 para obter mais informações sobre a ordenação parcial de modelos de função.