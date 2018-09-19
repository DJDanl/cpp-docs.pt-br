---
title: Erro do compilador C3550 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3550
dev_langs:
- C++
helpviewer_keywords:
- C3550
ms.assetid: 9f2d5ffc-e429-41a1-89e3-7acc4fd47e14
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 08c22d7e371fda7a229b541f78d4385f2943ee54
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46047779"
---
# <a name="compiler-error-c3550"></a>Erro do compilador C3550

somente simples 'decltype (Auto)' é permitido neste contexto

Se `decltype(auto)` é usado como um espaço reservado para o tipo de retorno de uma função, ele deve ser usado por si só. Ele não pode ser usado como parte de uma declaração de ponteiro (`decltype(auto*)`), uma declaração de referência (`decltype(auto&)`), ou qualquer outra tal habilitação.

## <a name="see-also"></a>Consulte também

[auto](../../cpp/auto-cpp.md)