---
title: Aviso LNK4102 das ferramentas de vinculador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK4102
dev_langs:
- C++
helpviewer_keywords:
- LNK4102
ms.assetid: bfd1b17e-05c7-4bc2-80d6-2888b1a425b2
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 16d13dcbc6d15efd7cf3a7ea0a310de4ab7b0c93
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33302640"
---
# <a name="linker-tools-warning-lnk4102"></a>Aviso LNK4102 (Ferramentas de Vinculador)
exportação de exclusão de destrutor 'name'; imagem pode não ser executada corretamente  
  
 O programa tentou exportar um destruidor de exclusão. A exclusão resultante pode ocorrer em um limite de DLL, de forma que um processo pode liberar a memória que não possui. Certifique-se de que o símbolo em questão não está listado no arquivo. def e se o símbolo não está listado como um argumento do **/importação** ou **/exportação** opção na linha de comando do vinculador.  
  
 Se você estiver recriando a biblioteca de tempo de execução C, você pode ignorar essa mensagem.