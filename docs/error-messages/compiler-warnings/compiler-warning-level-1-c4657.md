---
title: Compilador aviso (nível 1) C4657
ms.date: 11/04/2016
f1_keywords:
- C4657
helpviewer_keywords:
- C4657
ms.assetid: eb750050-cea6-4ead-b80c-d5dcd4971cfc
ms.openlocfilehash: 92415d1d17c3342dbb721aa850f37f4dfabd1406
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62375685"
---
# <a name="compiler-warning-level-1-c4657"></a>Compilador aviso (nível 1) C4657

expressão envolve um tipo de dados que forem novo desde a última compilação

Você adicionou ou alterou um tipo de dados, tornando-o novo no seu código-fonte desde a última compilação bem-sucedida. Editar e continuar não suporta alterações em tipos de dados existentes.

Esse aviso será sempre ser seguido [Fatal C1092 de erro](../../error-messages/compiler-errors-1/fatal-error-c1092.md). Para obter mais informações, consulte o [Supported Code Changes](/visualstudio/debugger/supported-code-changes-cpp).

### <a name="to-remove-this-warning-without-ending-the-current-debug-session"></a>Para remover este aviso sem encerrar a sessão de depuração atual

1. Altere o tipo de dados para seu estado antes do erro.

1. Dos **Debug** menu, escolha **aplicar alterações de código**.

### <a name="to-remove-this-error-without-changing-your-source-code"></a>Para remover esse erro sem alterar seu código-fonte

1. Dos **Debug** menu, escolha **parar depuração**.

1. Dos **Build** menu, escolha **Build**.