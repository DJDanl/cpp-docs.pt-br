---
title: "Compilador (nível 1) de aviso C4655 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: C4655
dev_langs: C++
helpviewer_keywords: C4655
ms.assetid: 540f2c7a-e4a1-49af-84b4-03eeea1bbf41
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 891fe3c68e93defba011d4ad4c90daf25fe3a799
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-warning-level-1-c4655"></a>Compilador C4655 de aviso (nível 1)
**'**   
 ***símbolo* ': tipo de variável é novo desde a última compilação, ou é definido de forma diferente em outro lugar**  
  
 Você alterados ou adicionados a um novo tipo de dados desde a última compilação bem-sucedida. Editar e continuar não dá suporte a alterações em tipos de dados existente.  
  
 Esse aviso é seguido por um [C1092 de Erro Fatal](../../error-messages/compiler-errors-1/fatal-error-c1092.md). Para obter mais informações, consulte o [suporte para alterações de código](/visualstudio/debugger/supported-code-changes-cpp).  
  
### <a name="to-remove-this-warning-without-ending-the-current-debug-session"></a>Para remover este aviso sem encerrar a sessão de depuração atual  
  
1.  Altere o tipo de dados para seu estado antes do erro.  
  
2.  Do **depurar** menu, escolha **aplicar alterações de código**.  
  
### <a name="to-remove-this-warning-without-changing-your-source-code"></a>Para remover este aviso sem alterar seu código-fonte  
  
1.  Do **depurar** menu, escolha **parar depuração**.  
  
2.  Do **criar** menu, escolha **criar**.