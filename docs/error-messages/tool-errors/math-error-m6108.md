---
title: Erro M6108 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- M6108
dev_langs:
- C++
helpviewer_keywords:
- M6108
ms.assetid: 054893b4-49bc-45d9-882f-7cb50ba387c0
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e1624a89b472733b4adb5563c8ba52e0b03dcaa2
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46048611"
---
# <a name="math-error-m6108"></a>Erro M6108 (Math)

raiz quadrada

O operando em uma operação de raiz quadrada era negativo.

Programa é encerrado com código de saída 136.

> [!NOTE]
>  O `sqrt` função na biblioteca em tempo de execução C e a função intrínseca do FORTRAN **SQRT** não geram esse erro. O C `sqrt` função verifica se o argumento antes de executar a operação e retorna um valor de erro se o operando for negativo. O FORTRAN **SQRT** função gera o erro de domínio [M6201](../../error-messages/tool-errors/math-error-m6201.md) em vez desse erro.