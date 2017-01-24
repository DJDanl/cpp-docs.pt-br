---
title: "Associando importa&#231;&#245;es | Microsoft Docs"
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
  - "Opção de vinculador /DELAY:NOBIND"
  - "Opção de vinculador DELAY:NOBIND"
ms.assetid: bb766038-deb1-41b1-bcbc-29a30e8c1e2a
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Associando importa&#231;&#245;es
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O comportamento padrão do vinculador é criar uma tabela de endereço bindable de importação para a DLL atraso\- carregado.  Se a DLL está associado, a função auxiliar tentará usar as informações associadas em vez de chamar **GetProcAddress** em cada uma das importações referenciadas.  Se o carimbo de data\/hora ou o endereço preferido não corresponderem aos da DLL carregados, o auxiliar que a função assumirá a tabela de endereço associado de importação está esgotado e continuará como se não existir.  
  
 Se você nunca pretende associar as importações atraso\- carregadas da DLL, especificando [\/delay](../../build/reference/delay-delay-load-import-settings.md): o nobind na linha de comando do vinculador impedirá que a tabela de endereço associado de importação é gerada e consome espaço no arquivo de imagem.  
  
## Consulte também  
 [Suporte de vinculador para DLLs carregadas com atraso](../../build/reference/linker-support-for-delay-loaded-dlls.md)