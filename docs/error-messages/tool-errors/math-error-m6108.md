---
title: Erro M6108 (Math)
ms.date: 11/04/2016
f1_keywords:
- M6108
helpviewer_keywords:
- M6108
ms.assetid: 054893b4-49bc-45d9-882f-7cb50ba387c0
ms.openlocfilehash: c6bd403437ee5e55eaf4add288995d0e4aa76c3b
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81361965"
---
# <a name="math-error-m6108"></a>Erro M6108 (Math)

raiz quadrada

O operato em uma operação de raiz quadrada foi negativo.

O programa termina com o código de saída 136.

> [!NOTE]
> A `sqrt` função na biblioteca de tempo de execução C e na função intrínseca **FORTRAN SQRT** não geram esse erro. A `sqrt` função C verifica o argumento antes de realizar a operação e retorna um valor de erro se o operand for negativo. A função FORTRAN **SQRT** gera o erro DOMÍNIO [M6201](../../error-messages/tool-errors/math-error-m6201.md) em vez deste erro.
