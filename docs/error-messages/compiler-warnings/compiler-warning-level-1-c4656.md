---
title: Compilador aviso (nível 1) C4656 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4656
dev_langs:
- C++
helpviewer_keywords:
- C4656
ms.assetid: b5aaef74-2320-4345-a6ae-b813881a491c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 3334b9448dd6e9d47ed0b3ee3e4dfb9dfc57b57f
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46032400"
---
# <a name="compiler-warning-level-1-c4656"></a>Compilador aviso (nível 1) C4656

'symbol': tipo de dados é novo ou foi alterado desde a última compilação ou é definido de forma diferente em outro lugar

Você adicionou ou alterou um tipo de dados, tornando-o novo no seu código-fonte desde a última compilação bem-sucedida. Editar e continuar não suporta alterações em tipos de dados existentes.

Esse aviso será sempre ser seguido [Fatal C1092 de erro](../../error-messages/compiler-errors-1/fatal-error-c1092.md). Para obter mais informações, consulte o [Supported Code Changes](/visualstudio/debugger/supported-code-changes-cpp).

### <a name="to-remove-this-warning-without-ending-the-current-debug-session"></a>Para remover este aviso sem encerrar a sessão de depuração atual

1. Altere o tipo de dados para seu estado antes do erro.

1. Dos **Debug** menu, escolha **aplicar alterações de código**.

### <a name="to-remove-this-error-without-changing-your-source-code"></a>Para remover esse erro sem alterar seu código-fonte

1. Dos **Debug** menu, escolha **parar depuração**.

1. Dos **Build** menu, escolha **Build**.