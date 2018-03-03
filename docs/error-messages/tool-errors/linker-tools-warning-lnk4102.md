---
title: Aviso LNK4102 das ferramentas de vinculador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK4102
dev_langs:
- C++
helpviewer_keywords:
- LNK4102
ms.assetid: bfd1b17e-05c7-4bc2-80d6-2888b1a425b2
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 80efad60da9f6742110811a5cf4c12f07c7def67
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="linker-tools-warning-lnk4102"></a>Aviso LNK4102 (Ferramentas de Vinculador)
exportação de exclusão de destrutor 'name'; imagem pode não ser executada corretamente  
  
 O programa tentou exportar um destruidor de exclusão. A exclusão resultante pode ocorrer em um limite de DLL, de forma que um processo pode liberar a memória que não possui. Certifique-se de que o símbolo em questão não está listado no arquivo. def e se o símbolo não está listado como um argumento do **/importação** ou **/exportação** opção na linha de comando do vinculador.  
  
 Se você estiver recriando a biblioteca de tempo de execução C, você pode ignorar essa mensagem.