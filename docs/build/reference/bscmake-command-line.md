---
title: "Linha de comando BSCMAKE | Microsoft Docs"
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
  - "BSCMAKE, linha de comando"
ms.assetid: 8006e8cf-8bfe-4c23-868a-b0a25e6bbf0f
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Linha de comando BSCMAKE
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Para executar BSCMAKE, use a seguinte sintaxe de linha de comando:  
  
```  
BSCMAKE [options] sbrfiles  
```  
  
 As opções podem aparecer somente no campo de `options` na linha de comando.  
  
 O campo *de sbrfiles* especifica um ou mais arquivos de .sbr criados por um compilador ou por um assembler.  Separe os nomes de arquivos de .sbr com espaços ou guias.  Você deve especificar a extensão; não há nenhum padrão.  Você pode especificar um caminho com o nome do arquivo, e você pode usar curingas do sistema operacional \(\* e?\).  
  
 Durante a criação incremental, você pode especificar novos arquivos de .sbr que não foram parte de compilação original.  Se você deseja que todas as contribuições a permanecer no arquivo de informações de navegação, você deve especificar todos os arquivos de .sbr \(inclusive truncados arquivos\) que foram usados originalmente para criar o arquivo de .bsc.  Se você omitir um arquivo de .sbr, a contribuição desse arquivo para o arquivo de informações de navegação é removida.  
  
 Não especificar um arquivo de .sbr truncado para uma compilação completa.  Uma compilação completa requer contribuições de todos os arquivos especificados de .sbr.  Antes de executar uma compilação completa, recompile o projeto e criar um novo arquivo de .sbr para cada arquivo vazio.  
  
 O comando a seguir executa BSCMAKE para criar um arquivo chamado MAIN.bsc de três arquivos de .sbr:  
  
```  
BSCMAKE main.sbr file1.sbr file2.sbr  
```  
  
 Para obter informações relacionadas, consulte [Comando Arquivo de BSCMAKE](../../build/reference/bscmake-command-file-response-file.md) e [Opções de BSCMAKE](../Topic/BSCMAKE%20Options.md).  
  
## Consulte também  
 [Referência de BSCMAKE](../../build/reference/bscmake-reference.md)