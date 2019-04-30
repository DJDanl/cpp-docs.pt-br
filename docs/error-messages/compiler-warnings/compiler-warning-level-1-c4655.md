---
title: Compilador aviso (nível 1) C4655
ms.date: 08/27/2018
f1_keywords:
- C4655
helpviewer_keywords:
- C4655
ms.assetid: 540f2c7a-e4a1-49af-84b4-03eeea1bbf41
ms.openlocfilehash: aff78dbed217a6d9c5bc2a315ef12a33fe6caf0d
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62374658"
---
# <a name="compiler-warning-level-1-c4655"></a>Compilador aviso (nível 1) C4655

> '*símbolo*': tipo de variável é novo desde a última compilação, ou é definido de forma diferente em outro lugar

## <a name="remarks"></a>Comentários

Você alterou ou adicionado um novo tipo de dados desde a última compilação bem-sucedida. Editar e continuar não suporta alterações em tipos de dados existentes.

Esse aviso é seguido por um [Fatal C1092 de erro](../../error-messages/compiler-errors-1/fatal-error-c1092.md). Para obter mais informações, consulte o [Supported Code Changes](/visualstudio/debugger/supported-code-changes-cpp).

### <a name="to-remove-this-warning-without-ending-the-current-debug-session"></a>Para remover este aviso sem encerrar a sessão de depuração atual

1. Altere o tipo de dados para seu estado antes do erro.

2. Dos **Debug** menu, escolha **aplicar alterações de código**.

### <a name="to-remove-this-warning-without-changing-your-source-code"></a>Para remover este aviso sem alterar seu código-fonte

1. Dos **Debug** menu, escolha **parar depuração**.

2. Dos **Build** menu, escolha **Build**.