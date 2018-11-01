---
title: Erro fatal C1509
ms.date: 11/04/2016
f1_keywords:
- C1509
helpviewer_keywords:
- C1509
ms.assetid: 40dd100d-c6ba-451c-bd26-2c99ec1c36d6
ms.openlocfilehash: efd5b9dd5cdd7ee174bc786c38d9dd841e2ad6ce
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50619994"
---
# <a name="fatal-error-c1509"></a>Erro fatal C1509

limite do compilador: muitos estados de manipulador de exceção na função 'function'. Simplifique a função

O código excede um limite interno em estados de manipulador de exceção (32.768 estados).

A causa mais comum é que a função contém uma expressão complexa de operadores aritméticos e variáveis de classe definida pelo usuário.

### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir usando as seguintes soluções possíveis

1. Simplificar expressões atribuindo subexpressões comuns para variáveis temporárias.

1. Divida a função em funções menores.