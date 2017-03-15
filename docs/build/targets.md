---
title: "Destinos | Microsoft Docs"
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
  - "destinos, especificando em NMAKE"
ms.assetid: 826ee849-4278-4c6e-97c3-79a2b5fe6463
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Destinos
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Em uma linha de dependência, especifique um ou mais destinos, usando qualquer nome de arquivo, um nome de diretório, ou [pseudotarget](../build/pseudotargets.md)válido.  Separe vários destinos com um ou mais espaços ou guias.  Os destinos não diferenciam maiúsculas de minúsculas.  Os caminhos são permitidas com nomes de arquivo.  Um destino não pode exceder 256 caracteres.  Se o destino que precede o dois pontos é um único caractere, use um espaço separando\-se; caso contrário, NMAKE interpreta a combinação de letra\- dois\-pontos como um especificador da unidade.  
  
## Que você deseja saber mais?  
 [Pseudotargets](../build/pseudotargets.md)  
  
 [Vários destinos](../build/multiple-targets.md)  
  
 [Dependências cumulativas](../build/cumulative-dependencies.md)  
  
 [Destinos em vários blocos de descrição](../build/targets-in-multiple-description-blocks.md)  
  
 [Efeitos colaterais de dependência](../build/dependency-side-effects.md)  
  
## Consulte também  
 [Blocos de descrição](../build/description-blocks.md)