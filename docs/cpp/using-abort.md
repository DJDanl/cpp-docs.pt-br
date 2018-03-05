---
title: Usando abort | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- Abort
dev_langs:
- C++
helpviewer_keywords:
- abort function
ms.assetid: 3ba39b78-ef74-4a8d-8dee-2d62442de174
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 88f7d2319fd238fbc7bf573d304245ca74696720
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="using-abort"></a>Usando abort
Chamando o [anular](../c-runtime-library/reference/abort.md) função causa o encerramento imediato. Ignora o processo normal de destruição para objetos estáticos globais inicializados. Também ignora o processamento especial que foi especificado usando a função `atexit`.  
  
## <a name="see-also"></a>Consulte também  
 [Considerações de término adicionais](../cpp/additional-termination-considerations.md)