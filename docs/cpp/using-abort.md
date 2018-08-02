---
title: Usando abort | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- Abort
dev_langs:
- C++
helpviewer_keywords:
- abort function
ms.assetid: 3ba39b78-ef74-4a8d-8dee-2d62442de174
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: e63c3134dee6c316519dfcc34cff30b591b56460
ms.sourcegitcommit: 51f804005b8d921468775a0316de52ad39b77c3e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/02/2018
ms.locfileid: "39465390"
---
# <a name="using-abort"></a>Usando abort
Chamar o [anular](../c-runtime-library/reference/abort.md) função causa o encerramento imediato. Ignora o processo normal de destruição para objetos estáticos globais inicializados. Também ignora o processamento especial que foi especificado usando a função `atexit`.  
  
## <a name="see-also"></a>Consulte também  
 [Considerações de término adicionais](../cpp/additional-termination-considerations.md)