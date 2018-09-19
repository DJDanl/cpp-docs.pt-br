---
title: Erro do compilador C2834 | Microsoft Docs
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
ms.openlocfilehash: b94e1a3fba9bc3589af020340651b4546347cf1a
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46089332"
---
# <a name="compiler-error-c2834"></a>Erro do compilador C2834

'operador operator' deve ser qualificado globalmente

O `new` e `delete` operadores estão vinculados à classe onde eles residem. Resolução de escopo não pode ser usada para selecionar uma versão do `new` ou `delete` de uma classe diferente. Para implementar várias formas dos `new` ou `delete` operador, crie uma versão do operador com parâmetros formais extra.