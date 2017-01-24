---
title: "Caracteres especiais em um makefile | Microsoft Docs"
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
  - "Macros , caracteres especiais"
  - "makefiles, caracteres especiais"
  - "programa NMAKE, caracteres especiais"
  - "caracteres especiais, em macros NMAKE"
ms.assetid: 92c34ab5-ca6b-4fc0-bcf4-3172eaeda9f0
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Caracteres especiais em um makefile
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Para usar um caractere especial de NMAKE como um caractere literal, coloque um acento circunflexo \(^\) na frente deles.  NMAKE ignora os sinais de intercalação que precedem outros caracteres.  Os caracteres especiais são:  
  
 `:  ;  #  (  )  $  ^  \  {  }  !  @  —`  
  
 Um acento circunflexo \(^\) em uma cadeia de caracteres entre aspas é tratado como um caractere literal do ponto de intercalação.  Um sinal de intercalação no final de uma linha insere um caractere de nova linha literal em uma cadeia de caracteres ou em uma macro.  
  
 Em macros, uma barra invertida \(\\\) seguida por um caractere de nova linha é substituída por um espaço.  
  
 Em comandos, um símbolo de porcentagem \(%\) é um especificador do arquivo.  Para representar literalmente % em um comando, especifique um sinal de porcentagem \(%%\) em vez de um único.  Em outras situações, NMAKE interpreta um único % literal, mas interpreta sempre %% um duplo como um único %.  Em virtude disso, para representar um %% literal, especifique três sinais de sinais de porcentagem %%%, ou quatro de porcentagem, %%%%.  
  
 Para usar o cifrão \($\) como um caractere literal em um comando, especifique dois cifrões \($$\).  Este método também pode ser usado em outras situações em que ^$ funciona.  
  
## Consulte também  
 [Conteúdo de um makefile](../build/contents-of-a-makefile.md)