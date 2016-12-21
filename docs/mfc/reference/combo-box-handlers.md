---
title: "Manipuladores da caixa de combina&#231;&#227;o | Microsoft Docs"
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
  - "ON_CBN_KILLFOCUS"
  - "ON_CBN_ERRSPACE"
  - "ON_CBN_EDITCHANGE"
  - "ON_CBN_CLOSEUP"
  - "ON_CBN_DBLCLK"
  - "ON_CBN_EDITUPDATE"
  - "ON_CBN_DROPDOWN"
  - "ON_CBN_SELENDOK"
  - "ON_CBN_SELCHANGE"
  - "ON_CBN_SETFOCUS"
  - "ON_CBN_SELENDCANCEL"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "caixas de combinação, manipuladores"
  - "ON_CBN_CLOSEUP"
  - "ON_CBN_DBLCLK"
  - "ON_CBN_DROPDOWN"
  - "ON_CBN_EDITCHANGE"
  - "ON_CBN_EDITUPDATE"
  - "ON_CBN_ERRSPACE"
  - "ON_CBN_KILLFOCUS"
  - "ON_CBN_SELCHANGE"
  - "ON_CBN_SELENDCANCEL"
  - "ON_CBN_SELENDOK"
  - "ON_CBN_SETFOCUS"
ms.assetid: 7f092412-01b7-4242-95ec-41ba506b9d71
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Manipuladores da caixa de combina&#231;&#227;o
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

As entradas de mapa correspondem a seguir protótipos de função.  
  
|Entrada do mapa|Protótipo de função|  
|---------------------|-------------------------|  
|ON\_CBN\_CLOSEUP \( \<ID\>, \<memberFxn\> \)|memberFxn void de afx\_msg \(\)|  
|ON\_CBN\_DBLCLK \( \<ID\>, \<memberFxn\> \)|memberFxn void de afx\_msg \(\);|  
|ON\_CBN\_DROPDOWN \( \<ID\>, \<memberFxn\> \)|memberFxn void de afx\_msg \(\);|  
|ON\_CBN\_EDITCHANGE \( \<ID\>, \<memberFxn\> \)|memberFxn void de afx\_msg \(\);|  
|ON\_CBN\_EDITUPDATE \( \<ID\>, \<memberFxn\> \)|memberFxn void de afx\_msg \(\);|  
|ON\_CBN\_ERRSPACE \( \<ID\>, \<memberFxn\> \)|memberFxn void de afx\_msg \(\);|  
|ON\_CBN\_KILLFOCUS \( \<ID\>, \<memberFxn\> \)|memberFxn void de afx\_msg \(\);|  
|ON\_CBN\_SELCHANGE \( \<ID\>, \<memberFxn\> \)|memberFxn void de afx\_msg \(\);|  
|ON\_CBN\_SELENDCANCEL \( \<ID\>, \<memberFxn\> \)|memberFxn void de afx\_msg \(\);|  
|ON\_CBN\_SELENDOK \( \<ID\>, \<memberFxn\> \)|memberFxn void de afx\_msg \(\);|  
|ON\_CBN\_SETFOCUS \( \<ID\>, \<memberFxn\> \)|memberFxn void de afx\_msg \(\);|  
  
## Consulte também  
 [Mapas de mensagem](../../mfc/reference/message-maps-mfc.md)