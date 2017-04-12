---
title: "Compilador aviso (nível 1) C4655 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4655
dev_langs:
- C++
helpviewer_keywords:
- C4655
ms.assetid: 540f2c7a-e4a1-49af-84b4-03eeea1bbf41
caps.latest.revision: 6
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
ms.openlocfilehash: 058086bb4617f59f53de706b38477bd868e297d3
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4655"></a>Compilador C4655 de aviso (nível 1)
**'**   
 ***símbolo* ': o tipo de variável é novo desde a última compilação ou é definido de forma diferente em outro lugar**  
  
 Você alterados ou adicionados a um novo tipo de dados desde a última compilação bem-sucedida. Editar e continuar não dá suporte a alterações em tipos de dados existente.  
  
 Esse aviso é seguido por um [C1092 de Erro Fatal](../../error-messages/compiler-errors-1/fatal-error-c1092.md). Para obter mais informações, consulte o [Supported Code Changes](/visualstudio/debugger/supported-code-changes-cpp).  
  
### <a name="to-remove-this-warning-without-ending-the-current-debug-session"></a>Para remover esse aviso sem encerrar a sessão de depuração atual  
  
1.  Altere o tipo de dados a seu estado antes do erro.  
  
2.  Do **depurar** menu, escolha **aplicar alterações de código**.  
  
### <a name="to-remove-this-warning-without-changing-your-source-code"></a>Para remover esse aviso sem alterar o código-fonte  
  
1.  Do **depurar** menu, escolha **parar depuração**.  
  
2.  Do **criar** menu, escolha **criar**.
