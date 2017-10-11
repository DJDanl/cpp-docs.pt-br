---
title: Erro fatal C1092 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C1092
dev_langs:
- C++
helpviewer_keywords:
- C1092
ms.assetid: bcaa87f0-fbfc-4a33-844b-3b9f5d67f279
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: fac0a5218e1faf16d3db459567c36775acd9bb12
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="fatal-error-c1092"></a>Erro fatal C1092
Editar e continuar não dá suporte a alterações em tipos de dados; compilação necessária  
  
 Você alterados ou adicionados a um tipo de dados desde a última compilação bem-sucedida.  
  
-   Editar e continuar não oferece suporte a alterações em tipos de dados existentes, incluindo definições de class, struct ou enum. Você deve parar a depuração e compile o aplicativo.  
  
-   Editar e continuar não oferece suporte à adição de novos tipos de dados se um arquivo de banco de dados do programa, como o vc*x*0. pdb (onde *x* é a versão principal do Visual C++ em uso) é somente leitura. Para adicionar tipos de dados, o compilador deve abrir o arquivo. PDB no modo de gravação.  
  
### <a name="to-remove-this-error-without-ending-the-current-debug-session"></a>Para remover esse erro sem encerrar a sessão de depuração atual  
  
1.  Altere o tipo de dados para seu estado antes do erro.  
  
2.  Do **depurar** menu, escolha **aplicar alterações de código**.  
  
### <a name="to-remove-this-error-without-changing-your-source-code"></a>Para remover esse erro sem alterar seu código-fonte  
  
1.  Do **depurar** menu, escolha **parar depuração**.  
  
2.  Do **criar** menu, escolha **criar**.  
  
 Para obter mais informações, consulte o [suporte para alterações de código](/visualstudio/debugger/supported-code-changes-cpp).
