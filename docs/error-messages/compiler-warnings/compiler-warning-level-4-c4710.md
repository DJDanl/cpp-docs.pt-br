---
title: Aviso do compilador (nível 4) C4710
ms.date: 11/04/2016
f1_keywords:
- C4710
helpviewer_keywords:
- C4710
ms.assetid: 76381ec7-3fc1-4bee-9a0a-c2c8307b92e2
ms.openlocfilehash: c30b98204f447f4d9d0ab8d687602a361d909363
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87218059"
---
# <a name="compiler-warning-level-4-c4710"></a>Aviso do compilador (nível 4) C4710

' function ': função não embutida

A função fornecida foi selecionada para expansão embutida, mas o compilador não executou o inalinhamento.

O inlining é executado no critério do compilador. A **`inline`** palavra-chave, como a **`register`** palavra-chave, é usada como uma dica para o compilador. O compilador usa heurística para determinar se deve embutir em linha uma função específica para acelerar o código durante a compilação para velocidade, ou se ele deve embutir uma função específica para tornar o código menor durante a compilação para o espaço. O compilador só embutirá funções muito pequenas ao compilar para espaço.

Em alguns casos, o compilador não embutirá uma função específica por motivos mecânicos. Consulte [C4714](../../error-messages/compiler-warnings/compiler-warning-level-4-c4714.md) para obter uma lista de motivos pelos quais o compilador pode não embutir uma função.

Esse aviso está desativado por padrão. Consulte [os avisos do compilador que estão desativados por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.
