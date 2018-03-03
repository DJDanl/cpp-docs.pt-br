---
title: "Compilador (nível 1) de aviso C4657 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4657
dev_langs:
- C++
helpviewer_keywords:
- C4657
ms.assetid: eb750050-cea6-4ead-b80c-d5dcd4971cfc
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 9ea95a34b66efef13f38eb160584452947699817
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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