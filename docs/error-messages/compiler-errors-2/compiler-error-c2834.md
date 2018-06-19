---
title: C2834 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2834
dev_langs:
- C++
helpviewer_keywords:
- C2834
ms.assetid: 28f9f6eb-ab2a-4e64-aaaa-9d14f955de41
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4eb4fb992f9213c4a4b456f786fd8f81308cec12
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33244778"
---
# <a name="compiler-error-c2834"></a>C2834 de erro do compilador
'operador operator' deve ser qualificado globalmente  
  
 O `new` e `delete` operadores são associados à classe onde elas residam. Resolução do escopo não pode ser usada para selecionar uma versão de `new` ou `delete` de uma classe diferente. Para implementar várias formas da `new` ou `delete` operador, crie uma versão do operador com parâmetros formais extra.