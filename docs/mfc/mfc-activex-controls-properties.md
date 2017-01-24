---
title: "Controles ActiveX MFC: propriedades | Microsoft Docs"
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
  - "Controles ActiveX MFC, propriedades"
  - "propriedades [MFC]"
  - "propriedades [MFC], Controles ActiveX"
ms.assetid: b678a53c-0d9e-476f-8aa0-23b80baaba46
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Controles ActiveX MFC: propriedades
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um controle ActiveX será acionado eventos para se comunicar com o contêiner do controle.  O contêiner, em retorno, usa métodos e propriedades para se comunicar com o controle.  Os métodos e as propriedades são semelhantes em uso e purpose, respectivamente, funções de membro e as variáveis de membro c criando classe.  As propriedades são os membros de dados de controle ActiveX que são expostos a qualquer contêiner.  As propriedades fornecem uma interface para aplicativos que contêm controles ActiveX, como clientes de automação e contêiner do controle ActiveX.  
  
 As propriedades também são chamadas de atributos.  
  
 Para obter mais informações sobre os métodos de controle ActiveX, consulte o artigo [Controles ActiveX MFC: Métodos](../mfc/mfc-activex-controls-methods.md).  
  
 Os controles ActiveX podem implementar os métodos e propriedades de estoque e personalizados.  A classe `COleControl` fornece uma implementação das propriedades de estoque. \(Para obter uma lista completa das propriedades de estoque, consulte o artigo [Controles ActiveX MFC: Adicionando as propriedades de estoque](../Topic/MFC%20ActiveX%20Controls:%20Adding%20Stock%20Properties.md).\) As propriedades personalizadas, definidas pelo desenvolvedor, adicionam recursos especializados a um controle ActiveX.  Para obter mais informações, consulte [Controles ActiveX MFC: Adicionando propriedades personalizadas](../mfc/mfc-activex-controls-adding-custom-properties.md).  
  
 As propriedades personalizadas e de estoque, como métodos, têm suporte por um mecanismo que consiste em um mapa de distribuição que trata propriedades e os métodos e as funções de membro existente de `COleControl` a serem classificados.  Além disso, essas propriedades podem ter parâmetros que o desenvolvedor usa para transmitir informações adicionais para o controle.  
  
 Os artigos a seguir discutem propriedades do controle ActiveX com mais detalhes:  
  
-   [Controles ActiveX MFC: Adicionando as propriedades de estoque](../Topic/MFC%20ActiveX%20Controls:%20Adding%20Stock%20Properties.md)  
  
-   [Controles ActiveX MFC: Adicionando propriedades personalizadas](../mfc/mfc-activex-controls-adding-custom-properties.md)  
  
-   [Controles ActiveX MFC: Implementação de propriedade avançada](../mfc/mfc-activex-controls-advanced-property-implementation.md)  
  
-   [Controles ActiveX MFC: Acessando propriedades de ambiente](../mfc/mfc-activex-controls-accessing-ambient-properties.md)  
  
## Consulte também  
 [Controles ActiveX MFC](../mfc/mfc-activex-controls.md)