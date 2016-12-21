---
title: "Aviso PRJ0041 (compila&#231;&#227;o de projeto) | Microsoft Docs"
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
  - "PRJ0041"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "PRJ0041"
ms.assetid: dc9f4cf9-6bd5-4222-89e8-7802a59bb96b
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso PRJ0041 (compila&#231;&#227;o de projeto)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Não é possível encontrar a dependência ausente “dependência” para o arquivo “arquivo”.O seu projeto ainda pode ser compilado, mas talvez continue aparecendo desatualizado até que esse arquivo seja encontrado.  
  
 Um arquivo \(o arquivo de recurso ou o arquivo de .idl\/.odl, por exemplo, continha uma instrução que incluir o sistema de projeto não pôde resolver.  
  
 Como o sistema de projeto não processa instruções de pré\-processador \(\#if, por exemplo\), a instrução de incorretos não pode ser realmente parte da compilação.  
  
 Para resolver esse aviso, exclua todo o código desnecessário em arquivos de .rc ou adicionar arquivos do espaço reservado do nome apropriado.