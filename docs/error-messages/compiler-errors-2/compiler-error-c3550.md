---
title: Erro do compilador C3550
ms.date: 11/04/2016
f1_keywords:
- C3550
helpviewer_keywords:
- C3550
ms.assetid: 9f2d5ffc-e429-41a1-89e3-7acc4fd47e14
ms.openlocfilehash: 106ac93496eebb25ee603251d84680053e1310b7
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62375906"
---
# <a name="compiler-error-c3550"></a>Erro do compilador C3550

somente simples 'decltype (Auto)' é permitido neste contexto

Se `decltype(auto)` é usado como um espaço reservado para o tipo de retorno de uma função, ele deve ser usado por si só. Ele não pode ser usado como parte de uma declaração de ponteiro (`decltype(auto*)`), uma declaração de referência (`decltype(auto&)`), ou qualquer outra tal habilitação.

## <a name="see-also"></a>Consulte também

[auto](../../cpp/auto-cpp.md)