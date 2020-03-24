---
title: Erro do compilador C2834
ms.date: 11/04/2016
f1_keywords:
- C2834
helpviewer_keywords:
- C2834
ms.assetid: 28f9f6eb-ab2a-4e64-aaaa-9d14f955de41
ms.openlocfilehash: a6a7bc0591fd51c808c303e94eeaaffd6111ffcd
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80201863"
---
# <a name="compiler-error-c2834"></a>Erro do compilador C2834

' operator Operator ' deve ser qualificado globalmente

Os operadores de `new` e `delete` estão vinculados à classe em que residem. A resolução de escopo não pode ser usada para selecionar uma versão de `new` ou `delete` de uma classe diferente. Para implementar várias formas do operador `new` ou `delete`, crie uma versão do operador com parâmetros formais extras.
