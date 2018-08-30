---
title: Compilador aviso (nível 1) C4655 | Microsoft Docs
ms.custom: ''
ms.date: 08/27/2018
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4655
dev_langs:
- C++
helpviewer_keywords:
- C4655
ms.assetid: 540f2c7a-e4a1-49af-84b4-03eeea1bbf41
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9600c0fb9b4f03112ebd9cf430e3f833899c5f3c
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43209095"
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