---
title: "Folhas de propriedades e p&#225;ginas de propriedade em MFC | Microsoft Docs"
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
  - "controles [MFC], folhas de propriedade"
  - "páginas de propriedade, MFC"
  - "folhas de propriedade, MFC"
  - "caixas de diálogo de guia"
ms.assetid: e1bede2b-0285-4b88-a052-0f8a372807a2
caps.latest.revision: 13
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Folhas de propriedades e p&#225;ginas de propriedade em MFC
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma folha de propriedade, também conhecida como uma caixa de diálogo da guia, é uma caixa de diálogo que contém páginas de propriedades.  Cada página de propriedades é baseada em um recurso do modelo da caixa de diálogo e contém controles.  É incluída em uma página com um guia na parte superior.  A guia da página e indica sua finalidade.  Os usuários clicam na guia da folha de propriedades para selecionar um conjunto de controles.  
  
 Use as páginas para agrupar os controles na folha de propriedade em conjuntos significativos.  A folha de propriedades contidas geralmente tem vários controles de seus próprios.  Esses se aplicam a todas as páginas.  
  
 As folhas de propriedades são baseadas na classe [CPropertySheet](../mfc/reference/cpropertysheet-class.md).  As páginas de propriedades são baseadas na classe [CPropertyPage](../mfc/reference/cpropertypage-class.md).  
  
 Uma folha de propriedade é um tipo especial da caixa de diálogo que normalmente é usada para alterar os atributos de qualquer objeto externo, como a seleção atual em uma exibição.  A folha de propriedade tem três partes principais: a caixa de diálogo contentor, uma ou mais páginas de propriedades mostradas um de cada vez, e um guia na parte superior de cada página que o usuário clica em para selecionar essa página.  As folhas de propriedades são úteis em situações em que você tem vários grupos semelhantes de configurações de opções ou alterar.  Uma folha de propriedade agrupa informações de uma maneira explicativos.  
  
> [!NOTE]
>  Quando você está tentando mostrar uma folha de propriedade usando `CPropertySheet::DoModal`, o sistema pode gerar uma exceção de \(possibilidade.  Esta exceção ocorre porque o sistema está tentando alterar [Estilos de janela](../Topic/Window%20Styles.md) do objeto antes que o objeto foi criado.  Para obter mais informações sobre essa exceção, e também como evitar ou tratá\-los, consulte [CPropertySheet::DoModal](../Topic/CPropertySheet::DoModal.md).  
  
## Consulte também  
 [Folhas de propriedade](../mfc/property-sheets-mfc.md)