---
title: "Classe de CMFCDesktopAlertWnd | Microsoft Docs"
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
  - "CMFCDesktopAlertWnd"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCDesktopAlertWnd"
ms.assetid: 73a2dd7b-ea84-4ae2-9830-7cf6e8dd2425
caps.latest.revision: 33
caps.handback.revision: 21
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCDesktopAlertWnd
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A classe de `CMFCDesktopAlertWnd` implementa a funcionalidade de uma caixa de diálogo sem\-modo que ele na tela para informar ao usuário sobre um evento.  
  
## Sintaxe  
  
```  
class CMFCDesktopAlertWnd : public CWnd  
```  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMFCDesktopAlertWnd::Create](../Topic/CMFCDesktopAlertWnd::Create.md)|Cria e inicializa a janela de alerta da área de trabalho.|  
|[CMFCDesktopAlertWnd::GetAnimationSpeed](../Topic/CMFCDesktopAlertWnd::GetAnimationSpeed.md)|Retorna a velocidade da animação.|  
|[CMFCDesktopAlertWnd::GetAnimationType](../Topic/CMFCDesktopAlertWnd::GetAnimationType.md)|Retorna o tipo de animação.|  
|[CMFCDesktopAlertWnd::GetAutoCloseTime](../Topic/CMFCDesktopAlertWnd::GetAutoCloseTime.md)|Retorna o tempo limite de fechamento automático.|  
|[CMFCDesktopAlertWnd::GetCaptionHeight](../Topic/CMFCDesktopAlertWnd::GetCaptionHeight.md)|Retorna a altura da barra de título.|  
|[CMFCDesktopAlertWnd::GetDialogSize](../Topic/CMFCDesktopAlertWnd::GetDialogSize.md)||  
|[CMFCDesktopAlertWnd::GetLastPos](../Topic/CMFCDesktopAlertWnd::GetLastPos.md)|Retorna a posição válido da última da janela de alerta da área de trabalho na tela.|  
|[CMFCDesktopAlertWnd::GetTransparency](../Topic/CMFCDesktopAlertWnd::GetTransparency.md)|Retorna o nível de transparência.|  
|[CMFCDesktopAlertWnd::HasSmallCaption](../Topic/CMFCDesktopAlertWnd::HasSmallCaption.md)|Determina se a janela de alerta da área de trabalho é exibida com a legenda pequena.|  
|[CMFCDesktopAlertWnd::OnBeforeShow](../Topic/CMFCDesktopAlertWnd::OnBeforeShow.md)||  
|[CMFCDesktopAlertWnd::OnClickLinkButton](../Topic/CMFCDesktopAlertWnd::OnClickLinkButton.md)|Chamado pela estrutura quando o usuário clica em um botão de link posicionado no menu alerta da área de trabalho.|  
|[CMFCDesktopAlertWnd::OnCommand](../Topic/CMFCDesktopAlertWnd::OnCommand.md)|A estrutura chama essa função de membro quando o usuário seleciona um item do menu, quando um controle filho envia uma notificação, ou quando um pressionamento de teclas de aceleração ele é convertido.  Overrides \( [CWnd::OnCommand](../Topic/CWnd::OnCommand.md).\)|  
|[CMFCDesktopAlertWnd::OnDraw](../Topic/CMFCDesktopAlertWnd::OnDraw.md)||  
|[CMFCDesktopAlertWnd::ProcessCommand](../Topic/CMFCDesktopAlertWnd::ProcessCommand.md)||  
|[CMFCDesktopAlertWnd::SetAnimationSpeed](../Topic/CMFCDesktopAlertWnd::SetAnimationSpeed.md)|Define a nova velocidade da animação.|  
|[CMFCDesktopAlertWnd::SetAnimationType](../Topic/CMFCDesktopAlertWnd::SetAnimationType.md)|Define o tipo de animação.|  
|[CMFCDesktopAlertWnd::SetAutoCloseTime](../Topic/CMFCDesktopAlertWnd::SetAutoCloseTime.md)|Define o tempo limite de fechamento automático.|  
|[CMFCDesktopAlertWnd::SetSmallCaption](../Topic/CMFCDesktopAlertWnd::SetSmallCaption.md)|Alterna entre e legendas pequenas normal.|  
|[CMFCDesktopAlertWnd::SetTransparency](../Topic/CMFCDesktopAlertWnd::SetTransparency.md)|Define o nível de transparência.|  
  
## Comentários  
 Uma janela de alerta da área de trabalho pode ser transparente, pode aparecer com efeitos de animação, e pode desaparecer \(após um atraso especificado ou quando o usuário demite clicando no botão fechar.\)  
  
 Uma janela de alerta da área de trabalho também pode conter uma caixa de diálogo padrão que por sua vez contém um ícone, o texto da mensagem \(um rótulo\), e um link.  Como alternativa, uma janela de alerta da área de trabalho pode conter uma caixa de diálogo personalizada os recursos do aplicativo.  
  
 Você cria uma janela de alerta da área de trabalho em duas etapas.  Primeiro, o construtor para construir o objeto de `CMFCDesktopAlertWnd` .  Segundo, chame a função de membro de [CMFCDesktopAlertWnd::Create](../Topic/CMFCDesktopAlertWnd::Create.md) para criar a janela para e anexá\-la ao objeto de `CMFCDesktopAlertWnd` .  
  
 O objeto de `CMFCDesktopAlertWnd` cria uma caixa de diálogo filho especial que preenche a área cliente da janela de alerta da área de trabalho.  A caixa de diálogo possui todos os controles que são posicionados em ele.  
  
 Para exibir uma caixa de diálogo personalizado na janela pop\-up, siga estas etapas:  
  
1.  Derive uma classe de `CMFCDesktopAlertDialog`.  
  
2.  Crie um modelo filho da caixa de diálogo em recursos.  
  
3.  Chame [CMFCDesktopAlertWnd::Create](../Topic/CMFCDesktopAlertWnd::Create.md) usando a ID de recurso do modelo da caixa de diálogo e um ponteiro para informações da classe de tempo de execução da classe derivada.  
  
4.  Programar a caixa de diálogo personalizada para tratar todas as notificações que vêm de controles hospedados, ou programar os controles hospedados diretamente para tratar essas notificações.  
  
 Use as seguintes funções para controlar o comportamento da janela de alerta da área de trabalho:  
  
-   Defina o tipo de animação chamando [CMFCDesktopAlertWnd::SetAnimationType](../Topic/CMFCDesktopAlertWnd::SetAnimationType.md).  As opções válidos incluem desdobram\-se, deslizam\-se, e desvanecem\-se.  
  
-   Defina a velocidade de animação de quadro [CMFCDesktopAlertWnd::SetAnimationSpeed](../Topic/CMFCDesktopAlertWnd::SetAnimationSpeed.md)chamando.  
  
-   Defina a transparência em nível [CMFCDesktopAlertWnd::SetTransparency](../Topic/CMFCDesktopAlertWnd::SetTransparency.md)chamando.  
  
-   Alterar o tamanho da legenda pequena chamando [CMFCDesktopAlertWnd::SetSmallCaption](../Topic/CMFCDesktopAlertWnd::SetSmallCaption.md).  A legenda pequena é 7 pixels.  
  
## Exemplo  
 O exemplo a seguir ilustra como usar vários métodos na classe de `CMFCDesktopAlertWnd` para configurar um objeto de `CMFCDesktopAlertWnd` .  O exemplo a seguir mostra como definir um tipo de animação, defina a transparência de janela pop\-up, especifica que a janela alerta exibe uma legenda pequena, e defina a hora que passa antes da janela alerta se encerra automaticamente.  O exemplo também demonstra como criar e inicializar a janela de alerta da área de trabalho.  Este trecho de código é parte de [Alerta exemplo de demonstração da área de trabalho](../../top/visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_DesktopAlertDemo#1](../../mfc/reference/codesnippet/CPP/cmfcdesktopalertwnd-class_1.cpp)]  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [CWnd](../Topic/CWnd%20Class.md)  
  
 [CMFCDesktopAlertWnd](../../mfc/reference/cmfcdesktopalertwnd-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxDesktopAlertWnd.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CMFCDesktopAlertWndInfo](../../mfc/reference/cmfcdesktopalertwndinfo-class.md)   
 [Classe de CMFCDesktopAlertDialog](../../mfc/reference/cmfcdesktopalertdialog-class.md)   
 [CWnd Class](../Topic/CWnd%20Class.md)