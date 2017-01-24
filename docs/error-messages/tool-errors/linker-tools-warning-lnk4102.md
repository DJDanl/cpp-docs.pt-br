---
title: "Aviso LNK4102 (Ferramentas de Vinculador) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "LNK4102"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LNK4102"
ms.assetid: bfd1b17e-05c7-4bc2-80d6-2888b1a425b2
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso LNK4102 (Ferramentas de Vinculador)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

exportação de excluir o destruidor “name”; a imagem não pode ser executado corretamente  
  
 O programa tentou exportar um destruidor excluindo.  A exclusão resultante pode ocorrer por meio de um limite de DLL de modo que um processo pode liberar a memória que não possui.  Certifique\-se de que o símbolo fornecido não está listado em seu arquivo .def, e que o símbolo não estiver listado como um argumento da opção de **\/IMPORT** ou de **\/EXPORT** na linha de comando do vinculador.  
  
 Se você estiver recompilando a biblioteca de tempo de execução C, você pode ignorar essa mensagem.