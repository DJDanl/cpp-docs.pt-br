---
title: "Compilador aviso (nível 1) C4657 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4657
dev_langs:
- C++
helpviewer_keywords:
- C4657
ms.assetid: eb750050-cea6-4ead-b80c-d5dcd4971cfc
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 6cad5222fb0d97594d5b13b5cf8903eb2934ee88
ms.openlocfilehash: 2ac407b6e2ed17eb7a9c1f1232756e9977ed7511
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4657"></a>Compilador C4657 de aviso (nível 1)
expressão envolve um tipo de dados é novo desde a última compilação  
  
 Você adicionou ou alterou um tipo de dados, tornando-o novo ao código-fonte desde a última compilação bem-sucedida. Editar e continuar não dá suporte a alterações em tipos de dados existente.  
  
 Esse aviso sempre será seguido por [C1092 de Erro Fatal](../../error-messages/compiler-errors-1/fatal-error-c1092.md). Para obter mais informações, consulte o [Supported Code Changes](/visualstudio/debugger/supported-code-changes-cpp).  
  
### <a name="to-remove-this-warning-without-ending-the-current-debug-session"></a>Para remover esse aviso sem encerrar a sessão de depuração atual  
  
1.  Altere o tipo de dados a seu estado antes do erro.  
  
2.  Do **depurar** menu, escolha **aplicar alterações de código**.  
  
### <a name="to-remove-this-error-without-changing-your-source-code"></a>Para remover este erro sem alterar o código-fonte  
  
1.  Do **depurar** menu, escolha **parar depuração**.  
  
2.  Do **criar** menu, escolha **criar**.
