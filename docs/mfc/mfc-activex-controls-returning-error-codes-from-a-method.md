---
title: "Controles ActiveX MFC: retornando c&#243;digos de erro a partir de um m&#233;todo | Microsoft Docs"
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
  - "erros [C++], códigos de erro de controle ActiveX"
  - "Método FireError"
  - "Método GetNotSupported"
  - "Controles ActiveX MFC, códigos de erro"
  - "SCODE, Controles ActiveX MFC"
  - "Método SetNotSupported, usando"
  - "Método ThrowError"
ms.assetid: 771fb9c9-2413-4dcc-b386-7bc4c4adeafd
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Controles ActiveX MFC: retornando c&#243;digos de erro a partir de um m&#233;todo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo descreve como retornar códigos de erro de um método de controle ActiveX.  
  
 Para indicar que um erro ocorreu dentro de um método, você deve usar a função de membro de [COleControl::ThrowError](../Topic/COleControl::ThrowError.md) , que usa `SCODE` \(código de status\) como um parâmetro.  Você pode usar `SCODE` predefinido ou definir um de seus próprios.  
  
> [!NOTE]
>  `ThrowError` parece ser usado apenas como meio de retornar um erro de uma propriedade obtém ou define a função ou um método de automação.  Esses são os únicos hora em que o manipulador de exceção apropriada estiver presente na pilha.  
  
 As funções auxiliares existem para a maioria de `SCODE`predefinido comum s, como [COleControl::SetNotSupported](../Topic/COleControl::SetNotSupported.md), [COleControl::GetNotSupported](../Topic/COleControl::GetNotSupported.md), e [COleControl::SetNotPermitted](../Topic/COleControl::SetNotPermitted.md).  
  
 Para obter uma lista de `SCODE`predefinido s e instruções sobre como definir `SCODE`personalizado s, consulte a seção [Tratar erros no controle ActiveX](../mfc/mfc-activex-controls-advanced-topics.md) em controles ActiveX: Tópicos avançados.  
  
 Para obter mais informações sobre as exceções de relatório em outras áreas em seu código, consulte [COleControl::FireError](../Topic/COleControl::FireError.md) e a seção [Tratar erros no controle ActiveX](../mfc/mfc-activex-controls-advanced-topics.md) em controles ActiveX: Tópicos avançados.  
  
## Consulte também  
 [Controles ActiveX MFC](../mfc/mfc-activex-controls.md)