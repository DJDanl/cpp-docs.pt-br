---
title: "Inicializando as partes de um objeto CStatusBarCtrl | Microsoft Docs"
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
  - "CStatusBarCtrl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CStatusBarCtrl, declarando partes de"
  - "Classe CStatusBarCtrl, modo simples"
  - "ícones, usando em barras de status"
  - "barras de status simples"
  - "barras de status, declarando partes de"
  - "barras de status, ícones"
  - "barras de status, modo simples"
ms.assetid: 60e8f285-d2d8-424a-a6ea-2fc548370303
caps.latest.revision: 12
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Inicializando as partes de um objeto CStatusBarCtrl
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Por padrão, uma barra de status exibe informações de status usando os painéis separados.  Esses painéis \(também conhecidos como as partes\) podem conter uma cadeia de caracteres de texto, um ícone, ou ambos.  
  
 Use [SetParts](../Topic/CStatusBarCtrl::SetParts.md) para definir as partes, e o comprimento, a barra de status terá.  Depois que você criou as partes da barra de status, crie chamadas a [SetText](../Topic/CStatusBarCtrl::SetText.md) e a [SetIcon](../Topic/CStatusBarCtrl::SetIcon.md) para definir o texto ou no ícone para uma parte específica da barra de status.  Uma vez que a solicitação foi definida com êxito, o controle é redesenhado automaticamente.  
  
 O exemplo a seguir inicializa um objeto existente de `CStatusBarCtrl` \(`m_StatusBarCtrl`\) com quatro painéis e defina um ícone \(IDI\_ICON1\) e qualquer texto na segunda parte.  
  
 [!code-cpp[NVC_MFCControlLadenDialog#31](../mfc/codesnippet/CPP/initializing-the-parts-of-a-cstatusbarctrl-object_1.cpp)]  
  
 Para obter mais informações sobre como definir o modo de um objeto da `CStatusBarCtrl` simples, consulte [Definindo o modo de um objeto de CStatusBarCtrl](../mfc/setting-the-mode-of-a-cstatusbarctrl-object.md).  
  
## Consulte também  
 [Usando CStatusBarCtrl](../mfc/using-cstatusbarctrl.md)   
 [Controles](../mfc/controls-mfc.md)