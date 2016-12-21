---
title: "Classe de CMFCColorDialog | Microsoft Docs"
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
  - "CMFCColorDialog"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCColorDialog"
  - "Membro de dados de CMFCColorDialog::m_bIsMyPalette"
  - "Membro de dados de CMFCColorDialog::m_bPickerMode"
  - "Membro de dados de CMFCColorDialog::m_btnColorSelect"
  - "Membro de dados de CMFCColorDialog::m_CurrentColor"
  - "Membro de dados de CMFCColorDialog::m_hcurPicker"
  - "Membro de dados de CMFCColorDialog::m_NewColor"
  - "Membro de dados de CMFCColorDialog::m_pColourSheetOne"
  - "Membro de dados de CMFCColorDialog::m_pColourSheetTwo"
  - "Membro de dados de CMFCColorDialog::m_pPalette"
  - "Membro de dados de CMFCColorDialog::m_pPropSheet"
  - "Membro de dados de CMFCColorDialog::m_wndColors"
  - "Membro de dados de CMFCColorDialog::m_wndStaticPlaceHolder"
  - "Método de CMFCColorDialog::PreTranslateMessage"
ms.assetid: 235bbbbc-a3b1-46e0-801b-fb55093ec579
caps.latest.revision: 30
caps.handback.revision: 18
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCColorDialog
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A classe de `CMFCColorDialog` representa uma caixa de diálogo de seleção de cor.  
  
## Sintaxe  
  
```  
class CMFCColorDialog : public CDialogEx  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCColorDialog::CMFCColorDialog](../Topic/CMFCColorDialog::CMFCColorDialog.md)|Constrói um objeto de `CMFCColorDialog` .|  
|`CMFCColorDialog::~CMFCColorDialog`|Destruidor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCColorDialog::GetColor](../Topic/CMFCColorDialog::GetColor.md)|Retorna a cor selecionada atual.|  
|[CMFCColorDialog::GetPalette](../Topic/CMFCColorDialog::GetPalette.md)|Retorna a paleta de cor.|  
|`CMFCColorDialog::PreTranslateMessage`|Converte mensagens de janela antes que são distribuídos funções do windows de [TranslateMessage](http://msdn.microsoft.com/library/windows/desktop/ms644955) e de [DispatchMessage](http://msdn.microsoft.com/library/windows/desktop/ms644934) .  Para a sintaxe e mais informações, consulte [CWnd::PreTranslateMessage](../Topic/CWnd::PreTranslateMessage.md).  Overrides \( `CDialogEx::PreTranslateMessage`.\)|  
|[CMFCColorDialog::RebuildPalette](../Topic/CMFCColorDialog::RebuildPalette.md)|Deriva de uma paleta paleta do sistema.|  
|[CMFCColorDialog::SetCurrentColor](../Topic/CMFCColorDialog::SetCurrentColor.md)|Define a cor selecionada atual.|  
|[CMFCColorDialog::SetNewColor](../Topic/CMFCColorDialog::SetNewColor.md)|Define a cor a maioria de equivalente a um valor específico de RGB.|  
|[CMFCColorDialog::SetPageOne](../Topic/CMFCColorDialog::SetPageOne.md)|Seleciona um valor de RGB para a primeira página de propriedades.|  
|[CMFCColorDialog::SetPageTwo](../Topic/CMFCColorDialog::SetPageTwo.md)|Seleciona um valor de RGB para a segunda página de propriedades.|  
  
### Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|`m_bIsMyPalette`|`TRUE` se a caixa de diálogo de seleção de cores usa sua própria paleta de cores, ou `FALSE` se a caixa de diálogo usa uma paleta que é especificada no construtor de `CMFCColorDialog` .|  
|`m_bPickerMode`|`TRUE` quando o usuário selecione uma cor da caixa de diálogo de seleção; caso contrário, `FALSE`.|  
|`m_btnColorSelect`|O botão de cor que o usuário selecionou.|  
|`m_CurrentColor`|A cor selecionada.|  
|`m_hcurPicker`|o cursor que é usado para escolher uma cor.|  
|`m_NewColor`|A cor selecionada em potencial, que pode ser selecionada permanentemente ou revertido para a cor original.|  
|`m_pColourSheetOne`|Um ponteiro para a primeira página de propriedades da folha de propriedades de seleção de cor.|  
|`m_pColourSheetTwo`|Um ponteiro para a segunda página de propriedades da folha de propriedades de seleção de cor.|  
|`m_pPalette`|A lógica paleta atual.|  
|`m_pPropSheet`|Um ponteiro para a folha de propriedades para a caixa de diálogo de seleção de cor.|  
|`m_wndColors`|Um objeto de controle do selecionador de cores.|  
|`m_wndStaticPlaceHolder`|Um controle estático que é um espaço reservado para a folha de propriedades do selecionador de cores.|  
  
## Comentários  
 A caixa de diálogo de seleção de cores é exibido como uma folha de propriedades com duas páginas.  Em a primeira página, você selecionar uma cor padrão de paleta do sistema; na segunda página, você selecionar uma cor personalizado.  
  
 Você pode criar um objeto de `CMFCColorDialog` na pilha e chamar `DoModal`, passando a cor inicial como um parâmetro para o construtor de `CMFCColorDialog` .  A caixa de diálogo de seleção de cores cria vários objetos de [Classe de CMFCColorPickerCtrl](../../mfc/reference/cmfccolorpickerctrl-class.md) trate cada paleta de cores.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CDialog](../../mfc/reference/cdialog-class.md)  
  
 [CDialogEx](../../mfc/reference/cdialogex-class.md)  
  
 [CMFCColorDialog](../../mfc/reference/cmfccolordialog-class.md)  
  
## Exemplo  
 O exemplo a seguir demonstra como configurar um caixa de diálogo de cor usando vários métodos na classe de `CMFCColorDialog` .  O exemplo a seguir mostra como definir a atual e as novas cores da caixa de diálogo, e como definir os componentes vermelho, verde e azul, de uma cor selecionada nas duas páginas de propriedades da caixa de diálogo de cor.  Este exemplo é parte de [novo exemplo de controles](../../top/visual-cpp-samples.md).  
  
 [!CODE [NVC_MFC_NewControls#3](../CodeSnippet/VS_Snippets_Misc/NVC_MFC_NewControls#3)]  
  
## Requisitos  
 **Cabeçalho:** afxcolordialog.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CMFCColorPickerCtrl](../../mfc/reference/cmfccolorpickerctrl-class.md)