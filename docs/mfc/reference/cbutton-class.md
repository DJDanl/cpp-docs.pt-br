---
title: "Classe de CButton | Microsoft Docs"
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
  - "CButton"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "controle de botão [MFC]"
  - "o botão objetos (CButton)"
  - "Classe de CButton"
  - "caixas de seleção, controles de botão"
  - "botões da caixa de seleção"
  - "teclas"
  - "botões de opção, Classe de CButton"
ms.assetid: cdc76d5b-31da-43c5-bc43-fde4cb39de5b
caps.latest.revision: 19
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CButton
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Fornece a funcionalidade dos controles de botão do windows.  
  
## Sintaxe  
  
```  
class CButton : public CWnd  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CButton::CButton](../Topic/CButton::CButton.md)|Constrói um objeto de `CButton` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CButton::Create](../Topic/CButton::Create.md)|Cria as janelas um controle e os anexa ele para o objeto de `CButton` .|  
|[CButton::DrawItem](../Topic/CButton::DrawItem.md)|Substituição para desenhar um objeto proprietário desenhado de `CButton` .|  
|[CButton::GetBitmap](../Topic/CButton::GetBitmap.md)|Recupera a alça de bitmap anteriormente definido com [SetBitmap](../Topic/CButton::SetBitmap.md).|  
|[CButton::GetButtonStyle](../Topic/CButton::GetButtonStyle.md)|Recupera informações sobre o estilo de controle button.|  
|[CButton::GetCheck](../Topic/CButton::GetCheck.md)|Recupera o estado de verificação de um controle de botão.|  
|[CButton::GetCursor](../Topic/CButton::GetCursor.md)|Recupera o identificador de imagem do cursor definida anteriormente com [SetCursor](../Topic/CButton::SetCursor.md).|  
|[CButton::GetIcon](../Topic/CButton::GetIcon.md)|Recupera a alça de ícone anteriormente definido com [SetIcon](../Topic/CButton::SetIcon.md).|  
|[CButton::GetIdealSize](../Topic/CButton::GetIdealSize.md)|Retorna o tamanho ideal de controle button.|  
|[CButton::GetImageList](../Topic/CButton::GetImageList.md)|Recupera a lista de imagem de controle button.|  
|[CButton::GetNote](../Topic/CButton::GetNote.md)|Recupera o componente de nota de controle de link de comando atual.|  
|[CButton::GetNoteLength](../Topic/CButton::GetNoteLength.md)|Retorna o tamanho do texto do nó para o controle de link de comando atual.|  
|[CButton::GetSplitGlyph](../Topic/CButton::GetSplitGlyph.md)|Recupera o glifo associado ao controle de botão split atual.|  
|[CButton::GetSplitImageList](../Topic/CButton::GetSplitImageList.md)|Recupera a lista de imagem para o controle de botão split atual.|  
|[CButton::GetSplitInfo](../Topic/CButton::GetSplitInfo.md)|Recupera informações que define o controle de botão split atual.|  
|[CButton::GetSplitSize](../Topic/CButton::GetSplitSize.md)|Recupera o retângulo delimitador do componente lista suspensa do controle de botão split atual.|  
|[CButton::GetSplitStyle](../Topic/CButton::GetSplitStyle.md)|Recupera os estilos de botão split que definem o controle de botão split atual.|  
|[CButton::GetState](../Topic/CButton::GetState.md)|Recupera o estado de verificação, o estado de realce, e o estado de foco de um controle de botão.|  
|[CButton::GetTextMargin](../Topic/CButton::GetTextMargin.md)|Recupera a margem do texto do controle de botão.|  
|[CButton::SetBitmap](../Topic/CButton::SetBitmap.md)|Especifica um bitmap a ser exibido no botão.|  
|[CButton::SetButtonStyle](../Topic/CButton::SetButtonStyle.md)|Altera o estilo de um botão.|  
|[CButton::SetCheck](../Topic/CButton::SetCheck.md)|Define o estado de verificação de um controle de botão.|  
|[CButton::SetCursor](../Topic/CButton::SetCursor.md)|Especifica uma imagem do cursor a ser exibida no botão.|  
|[CButton::SetDropDownState](../Topic/CButton::SetDropDownState.md)|Define o estado da lista suspensa do controle de botão split atual.|  
|[CButton::SetIcon](../Topic/CButton::SetIcon.md)|Especifica um ícone a ser exibido no botão.|  
|[CButton::SetImageList](../Topic/CButton::SetImageList.md)|Define a lista de imagem de controle button.|  
|[CButton::SetNote](../Topic/CButton::SetNote.md)|Define a observação no controle de link de comando atual.|  
|[CButton::SetSplitGlyph](../Topic/CButton::SetSplitGlyph.md)|Associa um glifo especificado com o controle de botão split atual.|  
|[CButton::SetSplitImageList](../Topic/CButton::SetSplitImageList.md)|Associa uma lista de imagem com o controle de botão split atual.|  
|[CButton::SetSplitInfo](../Topic/CButton::SetSplitInfo.md)|Especifica a informação que define o controle de botão split atual.|  
|[CButton::SetSplitSize](../Topic/CButton::SetSplitSize.md)|Define o retângulo delimitador do componente lista suspensa do controle de botão split atual.|  
|[CButton::SetSplitStyle](../Topic/CButton::SetSplitStyle.md)|Defina o estilo de controle de botão split atual.|  
|[CButton::SetState](../Topic/CButton::SetState.md)|Define o estado para realçar de um controle de botão.|  
|[CButton::SetTextMargin](../Topic/CButton::SetTextMargin.md)|Define a margem do texto do controle de botão.|  
  
## Comentários  
 Um controle de botão é uma janela filho, pequena retangular que pode ser clicado sobre e desativado.  Os botões podem ser usados apenas ou em grupos e podem ser rotuladas ou aparecido sem texto.  Normalmente um botão altera a aparência quando o usuário clica em ele.  
  
 Os botões são típicos a caixa de seleção, o botão de opção, e a tecla.  Um objeto de `CButton` pode se tornar qualquer pessoa, de acordo com [estilo de botão](../../mfc/reference/button-styles.md) especificado na inicialização pela função de membro de [Criar](../Topic/CButton::Create.md) .  
  
 Além de isso, a classe de [CBitmapButton](../../mfc/reference/cbitmapbutton-class.md) derivada de criação de suporte de `CButton` dos controles de botão rotulados com imagens bitmap em vez de texto.  `CBitmapButton` pode ter bitmaps separados para um botão para cima, para baixo, focalizado, e estados desativados.  
  
 Você pode criar um controle de botão de um modelo na caixa de diálogo ou diretamente no seu código.  Em ambos os casos, primeiro chamar o construtor `CButton` para construir o objeto de `CButton` ; chame a função de membro de **Criar** para criar o controle de botão do windows para e anexá\-la ao objeto de `CButton` .  
  
 A compilação pode ser um processo de uma etapa em uma classe derivada de `CButton`.  Escreva um construtor para a classe derivada e chamar **Criar** de dentro do construtor.  
  
 Se você desejar manipular as notificações do windows enviadas por um controle de botão ao seu pai \(geralmente uma classe derivada de [CDialog](../../mfc/reference/cdialog-class.md)\), adicionar uma função de membro de entrada e de mensagem\- manipulador de mensagem\- mapa para a classe pai para cada mensagem.  
  
 Cada entrada de mapa mensagem\- tem a seguinte forma:  
  
 Notificação**\(**`id`de**ON\_**, `memberFxn`**\)**  
  
 onde `id` especifica a identificação da janela filho do controle que envia a notificação e são `memberFxn` o nome da função de membro que você escreveu pai para trate a notificação.  
  
 O protótipo de função do pai é o seguinte:  
  
 **afx\_msg** `void` `memberFxn` **\( \);**  
  
 As possíveis entradas de mapa mensagem\- são:  
  
|Entrada de mapa|Enviado ao pai quando…|  
|---------------------|----------------------------|  
|**ON\_BN\_CLICKED**|O usuário clica em um botão.|  
|**ON\_BN\_DOUBLECLICKED**|O usuário clica duas vezes em um botão.|  
  
 Se você criar um objeto de `CButton` de um recurso da caixa de diálogo, o objeto de `CButton` é destruído automaticamente quando o usuário fecha a caixa de diálogo.  
  
 Se você criar um objeto de `CButton` em uma janela, você pode precisar destrui\-la.  Se você criar o objeto de `CButton` no heap usando a função de **new** , você deve chamar **delete** no objeto para destrui\-lo quando o usuário fecha o botão o controle.  Se você criar o objeto de `CButton` na pilha, ou é inserida no objeto pai da caixa de diálogo, é automaticamente destruída.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 `CButton`  
  
## Requisitos  
 **Cabeçalho:** afxwin.h  
  
## Consulte também  
 [CWnd Class](../Topic/CWnd%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [CWnd Class](../Topic/CWnd%20Class.md)   
 [Classe de CComboBox](../../mfc/reference/ccombobox-class.md)   
 [Classe de CEdit](../Topic/CEdit%20Class.md)   
 [Classe de CListBox](../Topic/CListBox%20Class.md)   
 [Classe de CScrollBar](../../mfc/reference/cscrollbar-class.md)   
 [Classe de CStatic](../Topic/CStatic%20Class.md)   
 [Classe de CBitmapButton](../../mfc/reference/cbitmapbutton-class.md)   
 [Classe de CDialog](../../mfc/reference/cdialog-class.md)