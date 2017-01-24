---
title: "Erro D8027 (linha de comando) | Microsoft Docs"
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
  - "D8027"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "D8027"
ms.assetid: f228220f-0c7f-49a6-a6e0-1f7bd4745aa6
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro D8027 (linha de comando)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

não pode executar o componente” “  
  
 O compilador não pôde executar o componente ou o vinculador fornecido do compilador.  
  
### Para corrigir verificando as seguintes causas possíveis  
  
1.  Memória insuficiente para carregar o componente.  Se NMAKE invocou o compilador, execute o compilador fora do makefile.  
  
2.  O sistema operacional atual não foi possível executar o componente.  Verifique os pontos de caminho para os arquivos executáveis apropriadas ao seu sistema operacional.  
  
3.  O componente foi danificado.  Reproduza o componente de discos de distribuição, usando o programa de instalação.  
  
4.  Uma opção for especificada incorretamente.  Por exemplo:  
  
    ```  
    cl /B1 file1.c  
    ```