---
title: Erro do compilador C2722
ms.date: 11/04/2016
f1_keywords:
- C2722
helpviewer_keywords:
- C2722
ms.assetid: 4cc2c7fa-cb12-4bcf-9df1-6d627ef62973
ms.openlocfilehash: 7426df1970dee58cd4363ee345e2286165e375b6
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80202146"
---
# <a name="compiler-error-c2722"></a>Erro do compilador C2722

':: operator ': inválido após comando de operador; Use ' operator Operator '

Uma instrução `operator` redefine `::new` ou `::delete`. Os operadores de `new` e `delete` são globais, portanto, o operador de resolução de escopo (`::`) não faz sentido. Remova o operador de `::`.
