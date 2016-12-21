---
title: "Aviso LNK4096 (Ferramentas de Vinculador) | Microsoft Docs"
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
  - "LNK4096"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LNK4096"
ms.assetid: ef6fba38-59a1-4d86-bcac-cadf44d87a36
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso LNK4096 (Ferramentas de Vinculador)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

o valor “número de \/BASE” não é válido para o Windows 95 e Windows 98; a imagem não pode executar  
  
 O endereço de base é especificado não é válido.  Os arquivos executáveis do Windows 95 e Windows 98 devem ter um endereço base maior do que 0x400000.  Para obter mais informações sobre os endereços de base, consulte a opção do vinculador de [\/BASE](../../build/reference/base-base-address.md) .