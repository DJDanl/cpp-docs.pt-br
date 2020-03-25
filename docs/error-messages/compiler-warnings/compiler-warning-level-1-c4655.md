---
title: Aviso do compilador (nível 1) C4655
ms.date: 08/27/2018
f1_keywords:
- C4655
helpviewer_keywords:
- C4655
ms.assetid: 540f2c7a-e4a1-49af-84b4-03eeea1bbf41
ms.openlocfilehash: d4c409c2d69099853a872142e05ef0fcda5a7655
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80199525"
---
# <a name="compiler-warning-level-1-c4655"></a>Aviso do compilador (nível 1) C4655

> '*Symbol*': o tipo de variável é novo desde a última compilação ou é definido de forma diferente em outro lugar

## <a name="remarks"></a>Comentários

Você alterou ou adicionou um novo tipo de dados desde a última compilação bem-sucedida. Editar e continuar não oferece suporte a alterações em tipos de dados existentes.

Esse aviso é seguido por um [erro fatal C1092](../../error-messages/compiler-errors-1/fatal-error-c1092.md). Para obter mais informações, consulte as [alterações de código com suporte](/visualstudio/debugger/supported-code-changes-cpp).

### <a name="to-remove-this-warning-without-ending-the-current-debug-session"></a>Para remover este aviso sem encerrar a sessão de depuração atual

1. Altere o tipo de dados de volta para seu estado anterior ao erro.

2. No menu **depurar** , escolha **aplicar alterações de código**.

### <a name="to-remove-this-warning-without-changing-your-source-code"></a>Para remover este aviso sem alterar o código-fonte

1. No menu **depurar** , escolha **parar depuração**.

2. No menu **Compilar** , escolha **Compilar**.
