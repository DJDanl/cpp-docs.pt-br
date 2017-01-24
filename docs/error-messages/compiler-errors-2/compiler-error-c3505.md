---
title: "Erro do Compilador C3505 | Microsoft Docs"
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
  - "C3505"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3505"
ms.assetid: ed73c99e-93a1-4f3a-bac7-ba7ed5d836e4
caps.latest.revision: 4
caps.handback.revision: 4
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3505
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

não pode carregar a biblioteca “GUID do tipo”  
  
 C3505 pode ser causado se você estiver executando \(32 bits\) ao compilador cruzado de 64 bits em um computador de 64 bits porque o compilador está executando sob WOW64 e pode ler apenas o hive de 32 bits do Registro.  
  
 Você pode resolver esse C3505 criando versões de 32 bits e de 64 bits da biblioteca de tipo você está tentando as importar e registre ambos.  Ou você pode usar o compilador nativo de 64 bits, mas isso exigiria altere os diretórios de VC\+\+ no IDE para apontar para o compilador de 64 bits.  
  
 Para obter mais informações, consulte,  
  
-   [Como habilitar um Conjunto de Ferramentas Visual C\+\+ de 64 bits na linha de comando](../../build/how-to-enable-a-64-bit-visual-cpp-toolset-on-the-command-line.md)  
  
-   [Como habilitar um Conjunto de Ferramentas Visual C\+\+ de 64 bits na linha de comando](../../build/how-to-enable-a-64-bit-visual-cpp-toolset-on-the-command-line.md)  
  
-   [Como configurar projetos do Visual C\+\+ para destinar plataformas de 64 bits](../../build/how-to-configure-visual-cpp-projects-to-target-64-bit-platforms.md)