---
title: Compilador aviso (nível 4) C4710 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4710
dev_langs:
- C++
helpviewer_keywords:
- C4710
ms.assetid: 76381ec7-3fc1-4bee-9a0a-c2c8307b92e2
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 1f6de17f7005db3834bfcfc93aff03f12f0293ce
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46046089"
---
# <a name="compiler-warning-level-4-c4710"></a>Compilador aviso (nível 4) C4710

'function': função não embutida

A função fornecida foi selecionada para expansão embutida, mas o compilador não executou o inlining.

Inlining é executada, a critério do compilador. O **embutido** palavra-chave, como o **registrar** palavra-chave, é usado como uma dica para o compilador. O compilador usa heurística para determinar se deveria embutir uma função específica para acelerar o código durante a compilação para velocidade, ou se ele deve embutir uma função específica para diminuir o código durante a compilação para o espaço. O compilador criará somente embutido muito pequenas funções durante a compilação para o espaço.

Em alguns casos, o compilador não embutirá uma função específica por motivos de mecânicos. Ver [C4714](../../error-messages/compiler-warnings/compiler-warning-level-4-c4714.md) para obter uma lista dos motivos, o compilador pode embutir uma função.

Esse aviso é desativado por padrão. Ver [compilador avisos que são desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.