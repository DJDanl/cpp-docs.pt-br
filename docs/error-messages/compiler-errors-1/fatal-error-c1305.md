---
title: "Erro fatal C1305 | Microsoft Docs"
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
  - "C1305"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C1305"
ms.assetid: 1629c850-e2db-4678-83d8-9bfc85323bc5
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro fatal C1305
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

o base de dados do perfil “pgd\_file” é para outra arquitetura  
  
 Um arquivo de .pgd que foi gerado da operação de \/LTCG:PGINSTRUMENT para outra plataforma foi passado a [\/LTCG: PGOPTIMIZE](../../build/reference/ltcg-link-time-code-generation.md) .  [otimizações Perfil\-guiadas](../../build/reference/profile-guided-optimizations.md) está disponível para de plataformas x86 e de [!INCLUDE[vcprx64](../Token/vcprx64_md.md)] .  Porém, um arquivo de .pgd gerado com uma operação de \/LTCG:PGINSTRUMENT para uma plataforma não é válido como entrada para \/LTCG:PGOPTIMIZE para uma plataforma diferente.  
  
 Para resolver este erro, transmita apenas um arquivo de .pgd criado com \/LTCG:PGINSTRUMENT a \/LTCG:PGOPTIMIZE na mesma plataforma.