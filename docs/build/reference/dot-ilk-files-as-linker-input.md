---
title: "Arquivos .Ilk como entrada de vinculador | Microsoft Docs"
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
  - "Arquivos .ilk"
  - "arquivos ILK"
ms.assetid: 7324c104-9e5d-423d-b268-b59f92607bf2
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Arquivos .Ilk como entrada de vinculador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Ao vincular incremental, o LINK atualiza o arquivo de status de .ilk que criou durante o primeiro link incremental.  Este arquivo tem o mesmo nome de base que o arquivo ou o arquivo .dll, e tem a extensão .ilk.  Durante os links incrementais subsequentes, o LINK atualizar o arquivo de .ilk.  Se o arquivo de .ilk está ausente, VINCULAR executa um link completo e cria um novo arquivo de .ilk.  Se o arquivo de .ilk estiver inutilizado, o LINK executa um link nonincremental.  Para obter detalhes sobre como vincular incremental, consulte a opção de [Link incremental \(\/INCREMENTAL\)](../../build/reference/incremental-link-incrementally.md) .  
  
## Consulte também  
 [Arquivos de entrada LINK](../../build/reference/link-input-files.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)