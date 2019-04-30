---
title: Erro M6108 (Math)
ms.date: 11/04/2016
f1_keywords:
- M6108
helpviewer_keywords:
- M6108
ms.assetid: 054893b4-49bc-45d9-882f-7cb50ba387c0
ms.openlocfilehash: d60e9b6284c79828fda1f7af542fcf197f189ad0
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62393266"
---
# <a name="math-error-m6108"></a>Erro M6108 (Math)

raiz quadrada

O operando em uma operação de raiz quadrada era negativo.

Programa é encerrado com código de saída 136.

> [!NOTE]
>  O `sqrt` função na biblioteca em tempo de execução C e a função intrínseca do FORTRAN **SQRT** não geram esse erro. O C `sqrt` função verifica se o argumento antes de executar a operação e retorna um valor de erro se o operando for negativo. O FORTRAN **SQRT** função gera o erro de domínio [M6201](../../error-messages/tool-errors/math-error-m6201.md) em vez desse erro.