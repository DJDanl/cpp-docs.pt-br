---
title: "SDI e MDI | Microsoft Docs"
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
  - "janelas com moldura, aplicativos MDI"
  - "janelas com moldura, Aplicativos SDI"
  - "MDI, vs. SDI"
  - "MFC, janelas"
  - "single document interface (SDI), aplicativos"
ms.assetid: bb7239d9-4759-4f63-bfff-44a04b48c067
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# SDI e MDI
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

MFC O facilita o trabalho com aplicativos de \(MDI\) da interface \(SDI\) e interface de documentos em um único documento.  
  
 Os aplicativos de SDI permitem apenas uma janela do quadro do documento aberto de cada vez.  Os aplicativos MDI permitem que as várias janelas do quadro do documento estão abertas na mesma instância de um aplicativo.  Um aplicativo MDI tem uma janela no de que as várias janelas filho MDI, que são as janelas próprias do quadro, podem ser abertas, cada uma contendo um documento separado.  Em alguns aplicativos, as janelas filho podem ser de tipos diferentes, como o windows do gráfico e janelas da planilha.  Nesse caso, a barra de menus pode ser alterada conforme as janelas filho MDI de tipos diferentes são ativadas.  
  
> [!NOTE]
>  No Windows 95 e versões posteriores, os aplicativos geralmente são SDI como o sistema operacional adotou uma exibição “documento centralizado”.  
  
 Para obter mais informações, consulte [Documentos, exibições, e a estrutura](../mfc/documents-views-and-the-framework.md).  
  
## Consulte também  
 [Usando as classes para escrever aplicativos para Windows](../Topic/Using%20the%20Classes%20to%20Write%20Applications%20for%20Windows.md)