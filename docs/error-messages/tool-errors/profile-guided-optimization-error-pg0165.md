---
title: "Erro de otimiza&#231;&#227;o orientada a perfil PG0165 | Microsoft Docs"
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
  - "PG0165"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "PG0165"
ms.assetid: e98122e7-ddee-4a2c-96b2-d232e4c65f3e
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro de otimiza&#231;&#227;o orientada a perfil PG0165
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Leia “Filename.pgd”: “Da versão PGD não tem suporte \(incompatibilidade de versão\)”.  
  
 Os arquivos de PGD são específicos a um conjunto de ferramentas do compilador específica.  Esse erro é gerado quando você estiver usando um compilador diferente de aquele usado para *Filename*.pgd.  Este erro indica que o conjunto de ferramentas do compilador não pode usar os dados de *Filename*.pgd para otimizar o programa atual.  
  
 Para resolver esse problema, *Filename*regenerada .pgd usando o conjunto de ferramentas atual do compilador.