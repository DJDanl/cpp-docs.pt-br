---
title: Aviso do compilador (nível 1) C4656
ms.date: 11/04/2016
f1_keywords:
- C4656
helpviewer_keywords:
- C4656
ms.assetid: b5aaef74-2320-4345-a6ae-b813881a491c
ms.openlocfilehash: a78da51a99aa924eadbf5c9f458ceb0a75889141
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80175643"
---
# <a name="compiler-warning-level-1-c4656"></a>Aviso do compilador (nível 1) C4656

' Symbol ': tipo de dados é novo ou foi alterado desde a última compilação, ou é definido de forma diferente em outro lugar

Você adicionou ou alterou um tipo de dados, tornando-o novo no código-fonte desde a última compilação bem-sucedida. Editar e continuar não oferece suporte a alterações em tipos de dados existentes.

Esse aviso sempre será seguido pelo [erro fatal C1092](../../error-messages/compiler-errors-1/fatal-error-c1092.md). Para obter mais informações, consulte as [alterações de código com suporte](/visualstudio/debugger/supported-code-changes-cpp).

### <a name="to-remove-this-warning-without-ending-the-current-debug-session"></a>Para remover este aviso sem encerrar a sessão de depuração atual

1. Altere o tipo de dados de volta para seu estado anterior ao erro.

1. No menu **depurar** , escolha **aplicar alterações de código**.

### <a name="to-remove-this-error-without-changing-your-source-code"></a>Para remover esse erro sem alterar o código-fonte

1. No menu **depurar** , escolha **parar depuração**.

1. No menu **Compilar** , escolha **Compilar**.
