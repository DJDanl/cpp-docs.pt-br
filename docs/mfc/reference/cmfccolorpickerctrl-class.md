---
title: "Classe de CMFCColorPickerCtrl | Microsoft Docs"
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
  - "CMFCColorPickerCtrl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCColorPickerCtrl"
ms.assetid: b9bbd03c-beb0-4b55-9765-9985fd05e5dc
caps.latest.revision: 33
caps.handback.revision: 21
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCColorPickerCtrl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A classe de `CMFCColorPickerCtrl` fornece funcionalidade para um controle que é usado para selecionar cores.  
  
## Sintaxe  
  
```  
class CMFCColorPickerCtrl : public CButton  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCColorPickerCtrl::CMFCColorPickerCtrl](../Topic/CMFCColorPickerCtrl::CMFCColorPickerCtrl.md)|Constrói um objeto de `CMFCColorPickerCtrl` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCColorPickerCtrl::GetColor](../Topic/CMFCColorPickerCtrl::GetColor.md)|Recupera a cor que o usuário seleciona.|  
|[CMFCColorPickerCtrl::GetHLS](../Topic/CMFCColorPickerCtrl::GetHLS.md)|Recupera os valores de matiz, de luminância e de saturação de cor que o usuário seleciona.|  
|[CMFCColorPickerCtrl::GetHue](../Topic/CMFCColorPickerCtrl::GetHue.md)|Recupera o componente de matiz de cor que o usuário seleciona.|  
|[CMFCColorPickerCtrl::GetLuminance](../Topic/CMFCColorPickerCtrl::GetLuminance.md)|Recupera o componente de luminância de cor que o usuário seleciona.|  
|[CMFCColorPickerCtrl::GetSaturation](../Topic/CMFCColorPickerCtrl::GetSaturation.md)|Recupera o componente de saturação de cor que o usuário seleciona.|  
|[CMFCColorPickerCtrl::SelectCellHexagon](../Topic/CMFCColorPickerCtrl::SelectCellHexagon.md)|Define a cor atual para a cor definida por componentes especificados de cor RGB ou por hexágono especificado da célula.|  
|[CMFCColorPickerCtrl::SetColor](../Topic/CMFCColorPickerCtrl::SetColor.md)|Define a cor atual para o valor especificado de cor RGB.|  
|[CMFCColorPickerCtrl::SetHLS](../Topic/CMFCColorPickerCtrl::SetHLS.md)|Define a cor atual para o valor de cor especificada de HLS.|  
|[CMFCColorPickerCtrl::SetHue](../Topic/CMFCColorPickerCtrl::SetHue.md)|Altera o componente de matiz de cor selecionada.|  
|[CMFCColorPickerCtrl::SetLuminance](../Topic/CMFCColorPickerCtrl::SetLuminance.md)|Altera o componente de luminância de cor selecionada.|  
|[CMFCColorPickerCtrl::SetLuminanceBarWidth](../Topic/CMFCColorPickerCtrl::SetLuminanceBarWidth.md)|Defina a largura de barra luminância no controle do selecionador de cores.|  
|[CMFCColorPickerCtrl::SetOriginalColor](../Topic/CMFCColorPickerCtrl::SetOriginalColor.md)|Define a cor selecionada inicial.|  
|[CMFCColorPickerCtrl::SetPalette](../Topic/CMFCColorPickerCtrl::SetPalette.md)|Defina a paleta de cores atual.|  
|[CMFCColorPickerCtrl::SetSaturation](../Topic/CMFCColorPickerCtrl::SetSaturation.md)|Altera o componente de saturação de cor selecionada.|  
|[CMFCColorPickerCtrl::SetType](../Topic/CMFCColorPickerCtrl::SetType.md)|Define o tipo de controle do selecionador de cores para exibir.|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCColorPickerCtrl::DrawCursor](../Topic/CMFCColorPickerCtrl::DrawCursor.md)|Chamado pela estrutura antes de um cursor que aponta para a cor selecionada é exibido.|  
  
## Comentários  
 As cores padrão são selecionadas de uma paleta de cores sextavada, e as cores personalizados são selecionadas de uma barra de luminância onde as cores é especificada usando vermelha\/verde\/notação azul ou notação de matiz\/satuaration\/luminância.  
  
 A ilustração a seguir descreve vários objetos de `CMFCColorPickerCtrl` .  
  
 ![Caixa de diálogo de CMFCColorPickerCtrl](../../mfc/reference/media/colorpicker.png "ColorPicker")  
  
 `CMFCColorPickerCtrl` suporta dois pares de estilos.  Os estilos e ENCANTAR de HEX\_GREYSCALE são apropriadas para a seleção de cores padrão.  Os estilos de MÁQUINA DESBASTADORA e de LUMINÂNCIA são apropriadas para a seleção de cores personalizado.  
  
 Execute as seguintes etapas para inserir o controle de `CMFCColorPickerCtrl` na caixa de diálogo:  
  
1.  Se você usar **ClassWizard**, inserir um novo controle de botão no modelo da caixa de diálogo \(porque a classe de `CMFCColorPickerCtrl` é herdada da classe de `CButton` \).  
  
2.  Inserir um variável de membro que está associado com o novo controle de botão em sua classe da caixa de diálogo.  Altere o tipo de variável `CButton` a `CMFCColorPickerCtrl`.  
  
3.  Inserir o manipulador de mensagem de `WM_INITDIALOG` para a classe da caixa de diálogo.  Em o manipulador, defina o tipo, a paleta, e a cor selecionada inicial do controle de `CMFCColorPickerCtrl` .  
  
## Exemplo  
 O exemplo a seguir demonstra como configurar um objeto de `CMFCColorPickerCtrl` usando vários métodos na classe de `CMFCColorPickerCtrl` .  O exemplo demonstra como definir o tipo de controle seletor, e como definir as cores, matiz, luminância, e saturação.  o exemplo é parte de [novo exemplo de controles](../../top/visual-cpp-samples.md).  
  
 [!CODE [NVC_MFC_NewControls#4](../CodeSnippet/VS_Snippets_Misc/NVC_MFC_NewControls#4)]  
[!CODE [NVC_MFC_NewControls#5](../CodeSnippet/VS_Snippets_Misc/NVC_MFC_NewControls#5)]  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CButton](../../mfc/reference/cbutton-class.md)  
  
 [CMFCColorPickerCtrl](../../mfc/reference/cmfccolorpickerctrl-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxcolorpickerctrl.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CMFCColorDialog](../../mfc/reference/cmfccolordialog-class.md)