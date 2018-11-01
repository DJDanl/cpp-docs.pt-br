---
title: Compilador aviso (nível 4) C4710
ms.date: 11/04/2016
f1_keywords:
- C4710
helpviewer_keywords:
- C4710
ms.assetid: 76381ec7-3fc1-4bee-9a0a-c2c8307b92e2
ms.openlocfilehash: 0f8e66982192f8af6498c9151d32a44226e0560a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50487770"
---
# <a name="compiler-warning-level-4-c4710"></a>Compilador aviso (nível 4) C4710

'function': função não embutida

A função fornecida foi selecionada para expansão embutida, mas o compilador não executou o inlining.

Inlining é executada, a critério do compilador. O **embutido** palavra-chave, como o **registrar** palavra-chave, é usado como uma dica para o compilador. O compilador usa heurística para determinar se deveria embutir uma função específica para acelerar o código durante a compilação para velocidade, ou se ele deve embutir uma função específica para diminuir o código durante a compilação para o espaço. O compilador criará somente embutido muito pequenas funções durante a compilação para o espaço.

Em alguns casos, o compilador não embutirá uma função específica por motivos de mecânicos. Ver [C4714](../../error-messages/compiler-warnings/compiler-warning-level-4-c4714.md) para obter uma lista dos motivos, o compilador pode embutir uma função.

Esse aviso é desativado por padrão. Ver [compilador avisos que são desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.