---
title: "Controle de cabe&#231;alho e de lista | Microsoft Docs"
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
  - "Classe CHeaderCtrl, com CListCtrl"
  - "Classe CListCtrl, controles de cabeçalho"
  - "Classe CListCtrl, com CHeaderCtrl"
  - "controles [MFC], cabeçalho"
  - "controles de cabeçalho"
  - "controles de cabeçalho, controles de lista usados com"
ms.assetid: b20194b1-1a6b-4e2f-b890-1b3cca6650bc
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Controle de cabe&#231;alho e de lista
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Na maioria dos casos, você usará o controle de cabeçalho que é inserida em um objeto de [CListCtrl](../Topic/CListCtrl%20Class.md) ou de [CListView](../mfc/reference/clistview-class.md) .  Entretanto, há casos em que um objeto separado de controle do cabeçalho é desejável, como os dados de manipulação, organizados em colunas ou linhas, em [CView](../Topic/CView%20Class.md)\- objeto derivada.  Nesses casos, você precisa maior controle sobre o comportamento de aparência e a opção de um controle de cabeçalho inserido.  
  
 Em casos comuns que você deseja um controle de cabeçalho para fornecer padrão, o comportamento padrão, você pode usar em vez [CListCtrl](../Topic/CListCtrl%20Class.md) ou [CListView](../mfc/reference/clistview-class.md) .  Use `CListCtrl` quando você deseja que a funcionalidade de um controle de cabeçalho padrão, inserido em um controle comuns da exibição de lista.  Use [CListView](../mfc/reference/clistview-class.md) quando você deseja que a funcionalidade de um controle de cabeçalho padrão, inserido em um objeto.  
  
> [!NOTE]
>  Esses controles incluem apenas um controle de cabeçalho interno se o controle de exibição de lista é criado usando o estilo de `LVS_REPORT` .  
  
 Na maioria dos casos, a aparência do controle de cabeçalho inserido pode ser alterada alterando os estilos de controle de que contém a exibição de lista.  Além disso, as informações sobre controle de cabeçalho pode ser obtida com as funções de membro do controle pai da exibição de lista.  No entanto, para controle total, e, o acesso a atributos e os estilos de controle de cabeçalho inserido, é recomendável que um ponteiro para o objeto de controle de cabeçalho seja obtido.  
  
 O objeto inserido de controle de cabeçalho pode ser acessado de **CListCtrl** ou de `CListView` com uma chamada à função de membro de `GetHeaderCtrl` respectiva da classe.  O código a seguir demonstra isso:  
  
 [!code-cpp[NVC_MFCControlLadenDialog#14](../mfc/codesnippet/CPP/header-control-and-list-control_1.cpp)]  
  
## Que você deseja saber mais?  
  
-   [Usando listas da imagem com controles de cabeçalho](../mfc/using-image-lists-with-header-controls.md)  
  
## Consulte também  
 [Usando CHeaderCtrl](../mfc/using-cheaderctrl.md)   
 [Controles](../mfc/controls-mfc.md)