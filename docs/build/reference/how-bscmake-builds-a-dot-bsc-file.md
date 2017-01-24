---
title: "Como BSCMAKE compila um arquivo .Bsc | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "arquivos de informações de pesquisa (.bsc), compilando"
ms.assetid: 8512b33e-c856-44a2-87bd-01ab10b52a95
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Como BSCMAKE compila um arquivo .Bsc
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

BSCMAKE cria ou recria um arquivo de .bsc da maneira mais eficiente que possa.  Para evitar problemas potenciais, é importante compreender o processo de compilação.  
  
 Quando BSCMAKE cria um arquivo de informações de navegação, trunca os arquivos de .sbr ao comprimento zero.  Durante a criação subsequente do mesmo arquivo, \(vazio\) ou um arquivo de comprimento zero de .sbr informa a BSCMAKE que o arquivo de .sbr não tem nenhuma nova contribuição para executar.  Permite que BSCMAKE saber que uma atualização dessa parte do arquivo não é necessária e uma construção incremental será suficiente.  Durante cada construção \(a menos que a opção \/n é especificado\), BSCMAKE tenta primeiro atualização incremental do arquivo usando somente aqueles arquivos de .sbr que foram alterados.  
  
 BSCMAKE procura um arquivo de .bsc que tem o nome especificado com a opção do \/o.  \/o Se não for especificado, BSCMAKE procura um arquivo que tem o nome de base do primeiro arquivo de .sbr e uma extensão de .bsc.  Se o arquivo já existir, BSCMAKE executa uma construção incremental do arquivo de informações de busca usando apenas os arquivos de contribuição de .sbr.  Se o arquivo não existir, BSCMAKE executa uma compilação completa usando todos os arquivos de .sbr.  As regras para construções são os seguintes:  
  
-   Para que uma compilação completa seja bem\-sucedida, todos os arquivos especificados de .sbr devem existir e não devem ser truncados.  Se um arquivo de .sbr é truncado, você deverá recriá\-lo \(recompilando ou montando\) antes de executar BSCMAKE.  
  
-   Para que uma construção incremental seja bem\-sucedida, o arquivo de .bsc deve existir.  Todos os arquivos de contribuição de .sbr, mesmo os arquivos vazios, devem existir e devem ser especificados na linha de comando de BSCMAKE.  Se você omitir um arquivo de .sbr de linha de comando, BSCMAKE cancela sua contribuição do arquivo.  
  
## Consulte também  
 [Compilando um arquivo .Bsc](../../build/reference/building-a-dot-bsc-file.md)