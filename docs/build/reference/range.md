---
title: "/RANGE | Microsoft Docs"
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
  - "/RANGE"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção /RANGE (dumpbin)"
  - "opção dumpbin -RANGE"
ms.assetid: 7eeba266-32be-49cc-a350-96bdf541f98a
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /RANGE
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Modifica a saída de dumpbin quando usado com outras opções de dumpbin, como \/RAWDATA ou \/DISASM.  
  
## Sintaxe  
  
```  
/RANGE:vaMin[,vaMax]  
```  
  
## Sinalizadores  
 **vaMin**  
 O endereço virtual no qual você deseja que a operação de dumpbin para iniciar.  
  
 **vaMax** \(opcional\)  
 O endereço virtual no qual você deseja que a operação de dumpbin para terminar.  Se não for especificado, o dumpbin ao final do arquivo.  
  
## Comentários  
 Para ver os endereços virtuais para uma imagem, use o arquivo de mapa da imagem RVA \+ \(base\), a opção de **\/DISASM** ou de **\/HEADERS** de dumpbin, ou na janela da desmontagem no depurador do Visual Studio.  
  
## Exemplo  
 Neste exemplo, **\/range** é usado para alterar a exibição da opção de **\/disasm** .  Neste exemplo, o valor inicial é expresso como um número decimal e o valor final são especificadas como um número hexadecimal.  
  
```  
dumpbin /disasm /range:4219334,0x004061CD t.exe  
```  
  
## Consulte também  
 [Opções de DUMPBIN](../../build/reference/dumpbin-options.md)