---
title: "Incluindo nomes de arquivo entre colchetes | Microsoft Docs"
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
  - "C"
ms.assetid: 6a4e5411-c35e-48b8-90ef-b37ac324ed94
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Incluindo nomes de arquivo entre colchetes
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**ANSI 3.8.2** O método para localizar arquivos de origem incluíveis  
  
 Para as especificações de arquivo colocadas entre colchetes angulares, o pré\-processador não pesquisa diretórios dos arquivos pai.  Um arquivo "pai" é o arquivo que contém a política [\#include](../preprocessor/hash-include-directive-c-cpp.md).  Em vez disso, ele começa procurando o arquivo nos diretórios especificados na linha de comando do compilador depois de \/I.  Se a opção \/I não estiver presente ou falhar, o pré\-processador usará a variável de ambiente INCLUDE para localizar os arquivos de inclusão entre colchetes angulares.  A variável de ambiente INCLUDE pode conter vários caminhos separados por ponto e vírgula \(**;**\).  Se mais de um diretório aparecer como parte da opção \/I ou dentro da variável de ambiente INCLUDE, o pré\-processador procurará por eles na ordem em que aparecem.  
  
## Consulte também  
 [Pré\-processando diretivas](../Topic/Preprocessing%20Directives.md)