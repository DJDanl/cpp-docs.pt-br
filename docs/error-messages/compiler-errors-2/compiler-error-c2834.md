---
title: Erro do compilador C2834
ms.date: 11/04/2016
f1_keywords:
- C2834
helpviewer_keywords:
- C2834
ms.assetid: 28f9f6eb-ab2a-4e64-aaaa-9d14f955de41
ms.openlocfilehash: fb4a0e6f3f6ec227b978ae0b7d3864b2134de986
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50677598"
---
# <a name="compiler-error-c2834"></a>Erro do compilador C2834

'operador operator' deve ser qualificado globalmente

O `new` e `delete` operadores estão vinculados à classe onde eles residem. Resolução de escopo não pode ser usada para selecionar uma versão do `new` ou `delete` de uma classe diferente. Para implementar várias formas dos `new` ou `delete` operador, crie uma versão do operador com parâmetros formais extra.