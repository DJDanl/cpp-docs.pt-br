---
title: "/RAWDATA | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "/rawdata"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção /RAWDATA (dumpbin)"
  - "dados brutos"
  - "opção dumpbin RAWDATA"
  - "opção dumpbin -RAWDATA"
ms.assetid: 41cba845-5e1f-415e-9fe4-604a52235983
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /RAWDATA
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/RAWDATA[:{1|2|4|8|NONE[,number]]  
```  
  
## Comentários  
 Esta opção exibe o conteúdo de cada seção brutos no arquivo.  Os argumentos controlam o formato de exibição, conforme mostrado abaixo:  
  
|Argumento|Resultado|  
|---------------|---------------|  
|1|A opção.  Os conteúdos serão exibidos em bytes hexadecimais, e também como caracteres ASCII se tiverem uma representação impressa.|  
|2|Os conteúdos são exibidos como 2 valores hexadecimais de byte.|  
|4|Os conteúdos são exibidos como 4 valores hexadecimais de byte.|  
|8|Os conteúdos são exibidos como 8 valores hexadecimais de byte.|  
|NONE|Os dados brutos serão suprimidos.  Esse argumento é útil para controlar a saída do \/ALL.|  
|*Número*|As linhas exibidas são definidas para uma largura que contém valores de `number` por linha.|  
  
 Somente a opção de DUMPBIN de [\/HEADERS](../../build/reference/headers.md) está disponível para uso em arquivos gerados com a opção do compilador de [\/GL](../../build/reference/gl-whole-program-optimization.md) .  
  
## Consulte também  
 [Opções de DUMPBIN](../../build/reference/dumpbin-options.md)