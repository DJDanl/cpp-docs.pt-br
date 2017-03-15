---
title: "2.6.2 Construto critical | Microsoft Docs"
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
ms.assetid: c46ecd00-b4a2-4a5e-ba92-288c329e773a
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# 2.6.2 Construto critical
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O **crítico** diretiva identifica uma construção que restringe a execução do bloco estruturado associado a um único thread por vez. A sintaxe do **crítico** diretiva é o seguinte:  
  
```  
#pragma omp critical [(name)]  new-linestructured-block  
```  
  
 Um recurso opcional *nome* pode ser usado para identificar a região crítica. Usado para identificar uma região crítica de identificadores têm vinculação externa e estão em um espaço para nome que é separado dos espaços de nome usados pelo rótulos, marcas, membros e identificadores comuns.  
  
 No início de uma região crítica que um thread aguarda até que nenhum outro segmento esteja executando uma região crítica \(em qualquer lugar no programa\) com o mesmo nome. Todas as capturas sem nome **crítico** diretivas são mapeados para o mesmo nome não especificado.