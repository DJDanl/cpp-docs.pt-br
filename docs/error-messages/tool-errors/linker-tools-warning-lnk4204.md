---
title: "Aviso LNK4204 (Ferramentas de Vinculador) | Microsoft Docs"
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
  - "LNK4204"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LNK4204"
ms.assetid: 14adda20-0cbe-407b-90f6-9f81c93530e2
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso LNK4204 (Ferramentas de Vinculador)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“nome de arquivo” é informações de depuração ausente para referenciar o módulo; vinculando o objeto como se nenhuma informação de depuração  
  
 O arquivo .pdb tem uma assinatura errônea.  O vinculador continuará vincular o objeto sem informações de depuração.  Talvez você queira recompilar o arquivo do objeto usando a opção de [\/Zi](../Topic/-Z7,%20-Zi,%20-ZI%20\(Debug%20Information%20Format\).md) .  
  
 LNK4204 pode ocorrer se algum dos objetos na biblioteca faz referência a um arquivo que não existe mais.  Isso pode ocorrer ao recriar a solução, por exemplo; um arquivo de objeto não pode ser excluído e recriado devido a um erro de compilação.  Nesse caso, compile com **\/Z7**, ou **\/Fd**, para atualizar os objetos para fazer referência a por uma biblioteca de arquivo único \(que não é o nome de arquivo da opção .pdb\).  Para obter mais informações, consulte [\/Fd \(nome do arquivo de banco de dados do programa\)](../../build/reference/fd-program-database-file-name.md).  Certifique\-se de que o .pdb ser salvo com a biblioteca é atualizada sempre que no sistema de controle do código\-fonte.