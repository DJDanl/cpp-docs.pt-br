---
title: "Despejando importa&#231;&#245;es carregadas com atraso | Microsoft Docs"
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
  - "importações carregadas com atraso"
  - "importações carregadas com atraso, despejando"
  - "importações (carregadas com atraso)"
ms.assetid: f766acf4-9df8-4b85-8cf6-0be3ffc4c124
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Despejando importa&#231;&#245;es carregadas com atraso
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

As importações Atraso\- podem ser carregadas despejadas usando [dumpbin \/imports](../../build/reference/imports-dumpbin.md) e exibida com informações ligeiramente diferente do que importa o padrão.  São segregados em sua própria seção de \/imports que for e rotulados explicitamente como importações atraso\- carregadas.  Se houver descarregar as informações atuais na imagem, que é observado.  Se houver um presentes de informações de associação, o carimbo de data\/hora da DLL de destino é observado junto com os endereços associados das importações.  
  
## Consulte também  
 [Suporte de vinculador para DLLs carregadas com atraso](../../build/reference/linker-support-for-delay-loaded-dlls.md)