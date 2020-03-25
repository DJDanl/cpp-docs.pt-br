---
title: Aviso do compilador (nível 4) C4710
ms.date: 11/04/2016
f1_keywords:
- C4710
helpviewer_keywords:
- C4710
ms.assetid: 76381ec7-3fc1-4bee-9a0a-c2c8307b92e2
ms.openlocfilehash: c39848b9b3e94e35c4d0c0937a0974b717c6bd8d
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80198170"
---
# <a name="compiler-warning-level-4-c4710"></a>Aviso do compilador (nível 4) C4710

' function ': função não embutida

A função fornecida foi selecionada para expansão embutida, mas o compilador não executou o inalinhamento.

O inlining é executado no critério do compilador. A palavra-chave **inline** , como a palavra-chave **Register** , é usada como uma dica para o compilador. O compilador usa heurística para determinar se deve embutir em linha uma função específica para acelerar o código durante a compilação para velocidade, ou se ele deve embutir uma função específica para tornar o código menor durante a compilação para o espaço. O compilador só embutirá funções muito pequenas ao compilar para espaço.

Em alguns casos, o compilador não embutirá uma função específica por motivos mecânicos. Consulte [C4714](../../error-messages/compiler-warnings/compiler-warning-level-4-c4714.md) para obter uma lista de motivos pelos quais o compilador pode não embutir uma função.

Esse aviso está desativado por padrão. Consulte [os avisos do compilador que estão desativados por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.
