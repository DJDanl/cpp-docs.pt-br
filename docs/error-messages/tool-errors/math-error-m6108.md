---
title: Erro M6108 (Math)
ms.date: 11/04/2016
f1_keywords:
- M6108
helpviewer_keywords:
- M6108
ms.assetid: 054893b4-49bc-45d9-882f-7cb50ba387c0
ms.openlocfilehash: 68e6ae823613d87eb01c443b564b46746259cd7b
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80173719"
---
# <a name="math-error-m6108"></a>Erro M6108 (Math)

raiz quadrada

O operando em uma operação de raiz quadrada era negativo.

O programa é encerrado com o código de saída 136.

> [!NOTE]
>  A função `sqrt` na biblioteca de tempo de execução do C e a função intrínseca do FORTRAN **sqrt** não geram esse erro. A função C `sqrt` verifica o argumento antes de executar a operação e retorna um valor de erro se o operando for negativo. A função FORTRAN **sqrt** gera o erro de domínio [M6201](../../error-messages/tool-errors/math-error-m6201.md) em vez desse erro.
