---
title: "Benef&#237;cios e troca do m&#233;todo usado para vincular ao CRT | Microsoft Docs"
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
  - "Macro de _ATL_MIN_CRT"
ms.assetid: 49b485f7-9487-49e4-b12a-0f710b620e2b
caps.latest.revision: 12
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Benef&#237;cios e troca do m&#233;todo usado para vincular ao CRT
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Seu projeto pode vincular com o CRT dinamicamente ou estaticamente.  A tabela abaixo dos contornos os benefícios e as troca envolveu sobre como escolher qual método usar.  
  
|Método|Benefício|Troca|  
|------------|---------------|-----------|  
|Estaticamente vinculando ao CRT<br /><br /> \(**Biblioteca de Tempo de Execução** definido como **Single\-threaded**\)|O DLL do CRT não é necessário no sistema onde a imagem será executado.|Sobre 25K de código de inicialização é adicionado à imagem, aumentar substancialmente seu tamanho.|  
|Vinculando ao CRT dinamicamente<br /><br /> \(**Biblioteca de Tempo de Execução** definido como **Com Multithread**\)|A imagem não requer o código de inicialização do CRT, portanto é muito menor.|O DLL do CRT deve estar no sistema que executa a imagem.|  
  
 O [vincular ao CRT em seu projeto de ATL](../atl/linking-to-the-crt-in-your-atl-project.md) tópico discute como selecionar a maneira como para vincular ao CRT.  
  
## Consulte também  
 [Programando com código de tempo de execução ATL e C](../atl/programming-with-atl-and-c-run-time-code.md)   
 [Comportamento da biblioteca em tempo de execução](../build/run-time-library-behavior.md)   
 [Recursos da biblioteca CRT](../c-runtime-library/crt-library-features.md)