---
title: "Pseudodestinos | Microsoft Docs"
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
  - "makefiles, pseudodestinos"
  - "programa NMAKE, pseudodestinos"
  - "programa NMAKE, destinos"
  - "pseudodestinos e NMAKE"
  - "carimbos de data/hora, pseudodestinos de makefile"
ms.assetid: c8c479dc-0129-4186-8366-bc6251f2b494
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Pseudodestinos
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um pseudotarget é um rótulo usado no lugar de um nome de arquivo em uma linha de dependência.  É interpretado como um arquivo que não existe, e assim que é esgotado.  NMAKE assume um carimbo de data\/hora de pseudotarget é o mais recente de todos os dependentes.  Se não tiver nenhum dependente, a hora atual será presumido.  Se um pseudotarget é usado como um destino, os comandos serão executados sempre.  Um pseudotarget usado como um dependente também deve aparecer como um destino em outra dependência.  Porém, essa dependência não precisa ter um bloco de comandos.  
  
 Os nomes de Pseudotarget seguem as regras de sintaxe o nome de arquivo para destinos.  No entanto, se o nome não tem uma extensão \(isto é, não contém um ponto\), pode exceder o limite de 8 caracteres para nomes de arquivo e pode ter até 256 caracteres por muito tempo.  
  
## Consulte também  
 [Destinos](../build/targets.md)