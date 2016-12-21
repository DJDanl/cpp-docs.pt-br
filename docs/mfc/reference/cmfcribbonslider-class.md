---
title: "Classe de CMFCRibbonSlider | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "CMFCRibbonSlider"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCRibbonSlider"
ms.assetid: 9351ac34-f234-4e42-91e2-763f1989c8ff
caps.latest.revision: 43
caps.handback.revision: 31
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCRibbonSlider
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A classe de `CMFCRibbonSlider` implementa um controle deslizante que você pode adicionar a barra de fita ou a uma barra de status de fita.  O controle deslizante de fita é semelhante aos controles slider de zoom que aparecem em aplicativos do Office 2007.  
  
## Sintaxe  
  
```  
class CMFCRibbonSlider : public CMFCRibbonBaseElement  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCRibbonSlider::CMFCRibbonSlider](../Topic/CMFCRibbonSlider::CMFCRibbonSlider.md)|As compilações e inicializam um controle deslizante de fita.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCRibbonSlider::GetPos](../Topic/CMFCRibbonSlider::GetPos.md)|Retorna a posição atual de controle slider.|  
|[CMFCRibbonSlider::GetRangeMax](../Topic/CMFCRibbonSlider::GetRangeMax.md)|Retorna o valor médio de controle slider.|  
|[CMFCRibbonSlider::GetRangeMin](../Topic/CMFCRibbonSlider::GetRangeMin.md)|Retorna o valor médio de controle slider.|  
|[CMFCRibbonSlider::GetRegularSize](../Topic/CMFCRibbonSlider::GetRegularSize.md)|Retorna o tamanho normal do elemento de fita.  Overrides \( [CMFCRibbonBaseElement::GetRegularSize](../Topic/CMFCRibbonBaseElement::GetRegularSize.md).\)|  
|[CMFCRibbonSlider::GetZoomIncrement](../Topic/CMFCRibbonSlider::GetZoomIncrement.md)|Retorna o tamanho de incremento de zoom para o controle deslizante.|  
|[CMFCRibbonSlider::HasZoomButtons](../Topic/CMFCRibbonSlider::HasZoomButtons.md)|Especifica se o controle deslizante tem botões de zoom.|  
|[CMFCRibbonSlider::OnDraw](../Topic/CMFCRibbonSlider::OnDraw.md)|Chamado pela estrutura para desenhar o elemento de fita.  Overrides \( [CMFCRibbonBaseElement::OnDraw](../Topic/CMFCRibbonBaseElement::OnDraw.md).\)|  
|[CMFCRibbonSlider::SetPos](../Topic/CMFCRibbonSlider::SetPos.md)|Define a posição atual de controle slider.|  
|[CMFCRibbonSlider::SetRange](../Topic/CMFCRibbonSlider::SetRange.md)|Especifica o intervalo de controle slider definindo os valores mínimo e máximo.|  
|[CMFCRibbonSlider::SetZoomButtons](../Topic/CMFCRibbonSlider::SetZoomButtons.md)|Mostra ou oculta os botões de zoom.|  
|[CMFCRibbonSlider::SetZoomIncrement](../Topic/CMFCRibbonSlider::SetZoomIncrement.md)|Tamanho dos conjuntos de incremento de zoom para o controle deslizante.|  
  
## Comentários  
 Você pode usar o método de `SetRange` para configurar o intervalo de incrementos de zoom para o controle deslizante.  Você pode definir a posição atual do controle deslizante usando o método de `SetPos` .  
  
 Você pode exibir os botões circulares de zoom na esquerda e no lado direito de controle deslizante usando o método de `SetZoomButtons` .  Por padrão, o controle deslizante é horizontal, o botão esquerdo do zoom exibe um sinal de subtração e o botão direito do zoom exibe um sinal de adição.  
  
 O método de `SetZoomIncrement` define o incremento para adicionar ou subtrair da posição atual quando um usuário clica nos botões de zoom.  
  
## Exemplo  
 O exemplo a seguir demonstra como usar vários métodos na classe de `CMFCRibbonSlider` para definir propriedades de controle slider.  O exemplo a seguir mostra como criar um objeto de `CMFCRibbonSlider` , exibe botões de zoom, define a posição atual do controle deslizante, e defina o intervalo de valores para o controle deslizante.  
  
 [!code-cpp[NVC_MFC_RibbonApp#12](../../mfc/reference/codesnippet/CPP/cmfcribbonslider-class_1.cpp)]  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CMFCRibbonBaseElement](../../mfc/reference/cmfcribbonbaseelement-class.md)  
  
 [CMFCRibbonSlider](../../mfc/reference/cmfcribbonslider-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxribbonslider.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CMFCRibbonBaseElement](../../mfc/reference/cmfcribbonbaseelement-class.md)