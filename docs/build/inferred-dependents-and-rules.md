---
title: "Dependentes inferidos e regras | Microsoft Docs"
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
  - "dependentes, inferido"
  - "dependentes inferidos em NMAKE"
  - "regras inferidas em NMAKE"
  - "regras, inferido"
ms.assetid: 9381e74a-53d9-445c-836d-0ff7ef6112d9
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Dependentes inferidos e regras
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

NMAKE assume um dependente inferido para um destino se uma regra de inferência aplicável existe.  Uma regra se aplica se:  
  
-   *o toext* corresponde a extensão de destino.  
  
-   *o fromext* corresponde a extensão de um arquivo que tenham o nome de base de destino e que existe no escopo atual ou no diretório especificado.  
  
-   *o fromext* está em [.SUFFIXES](../build/dot-directives.md); nenhum outro *fromext* em uma regra de correspondência tem uma prioridade mais alta de **.SUFFIXES** .  
  
-   Nenhum dependente explícito tem uma prioridade mais alta de **.SUFFIXES** .  
  
 Os dependentes deduzidos podem causar efeitos colaterais inesperados.  Se o bloco da descrição de destino contém comandos, NMAKE executa esses comandos em vez de comandos na regra.  
  
## Consulte também  
 [Regras de inferência](../build/inference-rules.md)