---
title: Erro do compilador c3550
ms.date: 11/04/2016
f1_keywords:
- C3550
helpviewer_keywords:
- C3550
ms.assetid: 9f2d5ffc-e429-41a1-89e3-7acc4fd47e14
ms.openlocfilehash: 17c90aa68b29c9490deb8d49895162e8a6bdefec
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80200766"
---
# <a name="compiler-error-c3550"></a>Erro do compilador c3550

somente ' decltype (auto) ' simples é permitido neste contexto

Se `decltype(auto)` for usado como um espaço reservado para o tipo de retorno de uma função, ele deverá ser usado por si só. Ele não pode ser usado como parte de uma declaração de ponteiro (`decltype(auto*)`), uma declaração de referência (`decltype(auto&)`) ou qualquer outra qualificação desse tipo.

## <a name="see-also"></a>Confira também

[auto](../../cpp/auto-cpp.md)
