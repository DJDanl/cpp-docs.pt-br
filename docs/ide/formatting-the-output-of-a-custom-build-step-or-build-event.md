---
title: "Formatando a sa&#237;da de uma etapa de compila&#231;&#227;o personalizada ou evento de compila&#231;&#227;o | Microsoft Docs"
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
  - "eventos de compilação [C++], formato de saída"
  - "etapas de compilação [C++], formato de saída"
  - "compilações [C++], compilar eventos"
  - "compilações [C++], etapas de compilação personalizada"
  - "etapas de compilação personalizada [C++], formato de saída"
  - "eventos [C++], compilar"
ms.assetid: 92ad3e38-24d7-4b89-90e6-5a16f5f998da
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Formatando a sa&#237;da de uma etapa de compila&#231;&#227;o personalizada ou evento de compila&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Se a saída de uma etapa de criação ou de um evento personalizado de compilação são formatadas corretamente, os usuários acessam os seguintes benefícios:  
  
-   Avisos e erros são contados na janela de **Saída** .  
  
-   As saídas aparecem na janela de **Lista de Tarefas** .  
  
-   Clique na saída na janela de **Saída** exibe o tópico apropriado.  
  
-   As operações de F1 são habilitadas na janela de **Lista de Tarefas** ou na janela de **Saída** .  
  
 O formato de saída deve ser:  
  
 {*filename* \(*line\#* \[, *column\#*\]\) &#124; *toolname*} **:**  
  
 \[*any text*\] {**error** &#124; **warning**} *code\#\#\#\#***:** *localizable string*  
  
 \[ *any text* \]  
  
 Where:  
  
-   {*a* &#124; *b*} é uma opção de *a* ou de *b*.  
  
-   \[\]`ccc`é uma cadeia de caracteres ou um parâmetro opcional.  
  
 Por exemplo:  
  
 C:\\*sourcefile.cpp*\(134\): erro C2143: erro de sintaxe: missing “; ” antes de “}”  
  
 LINK: erro fatal LNK1104: o não pode abrir arquivo '*somelib.lib*'  
  
## Consulte também  
 [Noções básicas de etapas e eventos de compilação personalizados](../ide/understanding-custom-build-steps-and-build-events.md)