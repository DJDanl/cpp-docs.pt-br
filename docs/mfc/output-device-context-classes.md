---
title: "Saída (contexto do dispositivo) Classes | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: vc.classes.output
dev_langs: C++
helpviewer_keywords:
- device contexts [MFC], classes
- screen output classes [MFC]
- printing classes [MFC]
- window drawing classes [MFC]
- painting classes [MFC]
- output classes [MFC]
ms.assetid: 35fd6435-a38e-42c6-a3fa-cd6f39370fc3
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: db7080c263ee6e98d458381d59446263490dfd7a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="output-device-context-classes"></a>Classes de saída (contexto do dispositivo)
Essas classes encapsulam os diferentes tipos de contextos de dispositivo disponíveis no Windows.  
  
 A maioria das seguintes classes encapsula um identificador para um contexto de dispositivo do Windows. Um contexto de dispositivo é um objeto do Windows que contém informações sobre os atributos de desenho de um dispositivo, como uma exibição ou uma impressora. Todas as chamadas de desenho são feitas por meio de um objeto de contexto de dispositivo. Classes adicionais derivadas de `CDC` encapsulam funcionalidades especializadas de contexto de dispositivo, incluindo suporte para metarquivos do Windows.  
  
 [CDC](../mfc/reference/cdc-class.md)  
 A classe base para contextos de dispositivo. Usadas diretamente para acessar a tela inteira e para acessar os contextos de nondisplay como impressoras.  
  
 [CPaintDC](../mfc/reference/cpaintdc-class.md)  
 Um contexto de exibição usado em `OnPaint` funções de membro do windows. Chama automaticamente `BeginPaint` na construção e `EndPaint` em destruição.  
  
 [CClientDC](../mfc/reference/cclientdc-class.md)  
 Um contexto de exibição para as áreas de cliente do windows. Usado, por exemplo, para desenhar em uma resposta imediata para eventos de mouse.  
  
 [CWindowDC](../mfc/reference/cwindowdc-class.md)  
 Um contexto de exibição para windows inteiras, incluindo áreas cliente e não cliente.  
  
 [CMetaFileDC](../mfc/reference/cmetafiledc-class.md)  
 Um contexto de dispositivo para metarquivos do Windows. Um metarquivo do Windows contém uma sequência de comandos de interface (GDI) do dispositivo de gráficos que podem ser reproduzidos para criar uma imagem. Chamadas feitas a funções de membro de um `CMetaFileDC` são registradas em um metarquivo.  
  
## <a name="related-classes"></a>Classes relacionadas  
 [CPoint](../atl-mfc-shared/reference/cpoint-class.md)  
 Contém pares de coordenadas (x, y).  
  
 [CSize](../atl-mfc-shared/reference/csize-class.md)  
 Mantém a distância, posições relativas ou pares de valores.  
  
 [CRect](../atl-mfc-shared/reference/crect-class.md)  
 Contém as coordenadas das áreas retangulares.  
  
 [CRgn](../mfc/reference/crgn-class.md)  
 Encapsula uma região GDI para manipular uma área irregular, elíptica ou poligonal dentro de uma janela. Usado em conjunto com as funções de membro de recorte na classe `CDC`.  
  
 [CRectTracker](../mfc/reference/crecttracker-class.md)  
 Exibe e gerencia a interface do usuário para redimensionar e mover objetos retangulares.  
  
 [CColorDialog](../mfc/reference/ccolordialog-class.md)  
 Fornece uma caixa de diálogo padrão para selecionar uma cor.  
  
 [CFontDialog](../mfc/reference/cfontdialog-class.md)  
 Fornece uma caixa de diálogo padrão para selecionar uma fonte.  
  
 [CPrintDialog](../mfc/reference/cprintdialog-class.md)  
 Fornece uma caixa de diálogo padrão para imprimir um arquivo.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../mfc/class-library-overview.md)

