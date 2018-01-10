---
title: Erro fatal C1092 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C1092
dev_langs: C++
helpviewer_keywords: C1092
ms.assetid: bcaa87f0-fbfc-4a33-844b-3b9f5d67f279
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 92309c9299303429c61f84911e180468f6354475
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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