---
title: Erro fatal C1509
ms.date: 11/04/2016
f1_keywords:
- C1509
helpviewer_keywords:
- C1509
ms.assetid: 40dd100d-c6ba-451c-bd26-2c99ec1c36d6
ms.openlocfilehash: 0d1d7255dd64239a6a76bb15a1f309b43eac0d4b
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80202950"
---
# <a name="fatal-error-c1509"></a>Erro fatal C1509

limite do compilador: muitos Estados de manipulador de exceção na função ' function '. simplificar a função

O código excede um limite interno nos Estados do manipulador de exceção (32.768 Estados).

A causa mais comum é que a função contém uma expressão complexa de variáveis de classe definidas pelo usuário e operadores aritméticos.

### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir usando as seguintes soluções possíveis

1. Simplifique as expressões atribuindo subexpressões comuns a variáveis temporárias.

1. Divida a função em funções menores.
