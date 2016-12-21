---
title: "Chamando fun&#231;&#245;es C++ em assembly embutido | Microsoft Docs"
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
  - "Palavra-chave __asm [C++], chamando funções"
  - "chamadas de função, funções C++"
  - "chamadas de função, em assembly embutido"
  - "funções [C++], chamando em assembly embutido"
  - "assembly embutido, chamando funções"
  - "Visual C++, Funções "
ms.assetid: 1f0d1eb3-54cf-45d5-838d-958188616b38
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Chamando fun&#231;&#245;es C++ em assembly embutido
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

## Específico da Microsoft  
 Um bloco de `__asm` pode chamar apenas as funções globais C\+\+ que não sejam sobrecarregadas.  Se você chamar uma função global sobrecarregada C\+\+ ou a função de membro c criando, o compilador emite um erro.  
  
 Você também pode chamar todas as funções declaradas com vínculo de **extern "C"** .  Isso permite que um bloco de `__asm` no programa c criando chama as funções da biblioteca de C, pois todos os arquivos de cabeçalho padrão declaram funções da biblioteca para que o vínculo de **extern "C"** .  
  
 **FINALIZAR Específico da Microsoft**  
  
## Consulte também  
 [Assembler embutido](../../assembler/inline/inline-assembler.md)