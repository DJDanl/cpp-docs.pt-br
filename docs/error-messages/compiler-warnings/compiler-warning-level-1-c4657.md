---
title: Compilador (nível 1) de aviso C4657 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4657
dev_langs:
- C++
helpviewer_keywords:
- C4657
ms.assetid: eb750050-cea6-4ead-b80c-d5dcd4971cfc
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 270cfb458b43d72ca1102cee128ed5998d74f665
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33284359"
---
# <a name="compiler-warning-level-1-c4657"></a>Compilador C4657 de aviso (nível 1)
expressão envolve um tipo de dados é novo desde a última compilação  
  
 Você adicionou ou alterou um tipo de dados, tornando-o novo no código-fonte desde a última compilação bem-sucedida. Editar e continuar não dá suporte a alterações em tipos de dados existente.  
  
 Esse aviso sempre será seguido por [C1092 de Erro Fatal](../../error-messages/compiler-errors-1/fatal-error-c1092.md). Para obter mais informações, consulte o [suporte para alterações de código](/visualstudio/debugger/supported-code-changes-cpp).  
  
### <a name="to-remove-this-warning-without-ending-the-current-debug-session"></a>Para remover este aviso sem encerrar a sessão de depuração atual  
  
1.  Altere o tipo de dados para seu estado antes do erro.  
  
2.  Do **depurar** menu, escolha **aplicar alterações de código**.  
  
### <a name="to-remove-this-error-without-changing-your-source-code"></a>Para remover esse erro sem alterar seu código-fonte  
  
1.  Do **depurar** menu, escolha **parar depuração**.  
  
2.  Do **criar** menu, escolha **criar**.