---
title: "Classe de COleControlSite | Microsoft Docs"
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
  - "COleControlSite"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de COleControlSite"
ms.assetid: 43970644-5eab-434a-8ba6-56d144ff1e3f
caps.latest.revision: 24
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de COleControlSite
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Fornece suporte a interfaces de controle do lado do cliente personalizados.  
  
## Sintaxe  
  
```  
class COleControlSite : public CCmdTarget  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleControlSite::COleControlSite](../Topic/COleControlSite::COleControlSite.md)|Constrói um objeto de `COleControlSite` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleControlSite::BindDefaultProperty](../Topic/COleControlSite::BindDefaultProperty.md)|Associa a propriedade padrão de controle hospedado a uma fonte de dados.|  
|[COleControlSite::BindProperty](../Topic/COleControlSite::BindProperty.md)|Associa uma propriedade do controle hospedado a uma fonte de dados.|  
|[COleControlSite::CreateControl](../Topic/COleControlSite::CreateControl.md)|Cria um controle ActiveX hospedado.|  
|[COleControlSite::DestroyControl](../Topic/COleControlSite::DestroyControl.md)|Destrói o controle hospedado.|  
|[COleControlSite::DoVerb](../Topic/COleControlSite::DoVerb.md)|Executa um comando específico do controle hospedado.|  
|[COleControlSite::EnableDSC](../Topic/COleControlSite::EnableDSC.md)|Permite que a fonte de dados para um site do controle.|  
|[COleControlSite::EnableWindow](../Topic/COleControlSite::EnableWindow.md)|Permite que o site do controle.|  
|[COleControlSite::FreezeEvents](../Topic/COleControlSite::FreezeEvents.md)|Especifica se o site do controle estiver retornando eventos.|  
|[COleControlSite::GetDefBtnCode](../Topic/COleControlSite::GetDefBtnCode.md)|Recupera o código do botão padrão para o controle hospedado.|  
|[COleControlSite::GetDlgCtrlID](../Topic/COleControlSite::GetDlgCtrlID.md)|Recupera o identificador do controle.|  
|[COleControlSite::GetEventIID](../Topic/COleControlSite::GetEventIID.md)|Recupera o ID da interface de evento para um controle hospedado.|  
|[COleControlSite::GetExStyle](../Topic/COleControlSite::GetExStyle.md)|Recupera os estilos estendidos do site do controle.|  
|[COleControlSite::GetProperty](../Topic/COleControlSite::GetProperty.md)|Recupera uma propriedade específica do controle hospedado.|  
|[COleControlSite::GetStyle](../Topic/COleControlSite::GetStyle.md)|Recupera os estilos de site do controle.|  
|[COleControlSite::GetWindowText](../Topic/COleControlSite::GetWindowText.md)|Recupera o texto do controle hospedado.|  
|[COleControlSite::InvokeHelper](../Topic/COleControlSite::InvokeHelper.md)|Chamar um método particular do controle hospedado.|  
|[COleControlSite::InvokeHelperV](../Topic/COleControlSite::InvokeHelperV.md)|Chamar um método particular do controle hospedado variável com uma lista de argumentos.|  
|[COleControlSite::IsDefaultButton](../Topic/COleControlSite::IsDefaultButton.md)|Determina se o controle é o botão padrão na janela.|  
|[COleControlSite::IsWindowEnabled](../Topic/COleControlSite::IsWindowEnabled.md)|Verifica o estado visível do site do controle.|  
|[COleControlSite::ModifyStyle](../Topic/COleControlSite::ModifyStyle.md)|Altera os estilos estendidos atuais do site do controle.|  
|[COleControlSite::ModifyStyleEx](../Topic/COleControlSite::ModifyStyleEx.md)|Altera os estilos atuais do site do controle.|  
|[COleControlSite::MoveWindow](../Topic/COleControlSite::MoveWindow.md)|Altera a posição do site do controle.|  
|[COleControlSite::QuickActivate](../Topic/COleControlSite::QuickActivate.md)|Rápido ativa o controle hospedado.|  
|[COleControlSite::SafeSetProperty](../Topic/COleControlSite::SafeSetProperty.md)|Define uma propriedade ou método do controle sem possibilidade de lançar uma exceção.|  
|[COleControlSite::SetDefaultButton](../Topic/COleControlSite::SetDefaultButton.md)|Define o botão padrão na janela.|  
|[COleControlSite::SetDlgCtrlID](../Topic/COleControlSite::SetDlgCtrlID.md)|Recupera o identificador do controle.|  
|[COleControlSite::SetFocus](../Topic/COleControlSite::SetFocus.md)|Defina o foco para o site do controle.|  
|[COleControlSite::SetProperty](../Topic/COleControlSite::SetProperty.md)|Define uma propriedade específica do controle hospedado.|  
|[COleControlSite::SetPropertyV](../Topic/COleControlSite::SetPropertyV.md)|Define uma propriedade específica do controle hospedado variável com uma lista de argumentos.|  
|[COleControlSite::SetWindowPos](../Topic/COleControlSite::SetWindowPos.md)|Define a posição do site do controle.|  
|[COleControlSite::SetWindowText](../Topic/COleControlSite::SetWindowText.md)|Define o texto do controle hospedado.|  
|[COleControlSite::ShowWindow](../Topic/COleControlSite::ShowWindow.md)|Mostra ou oculta o site do controle.|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleControlSite::GetControlInfo](../Topic/COleControlSite::GetControlInfo.md)|Recupera informações e mnemônicos do teclado para o controle hospedado.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleControlSite::m\_bIsWindowless](../Topic/COleControlSite::m_bIsWindowless.md)|Determina se o controle hospedado é um controle sem janelas.|  
|[COleControlSite::m\_ctlInfo](../Topic/COleControlSite::m_ctlInfo.md)|Contém informações sobre tratamento de teclado para o controle.|  
|[COleControlSite::m\_dwEventSink](../Topic/COleControlSite::m_dwEventSink.md)|O cookie de ponto de conexão do controle.|  
|[COleControlSite::m\_dwMiscStatus](../Topic/COleControlSite::m_dwMiscStatus.md)|Os diversos estados para o controle hospedado.|  
|[COleControlSite::m\_dwPropNotifySink](../Topic/COleControlSite::m_dwPropNotifySink.md)|O cookie de `IPropertyNotifySink` do controle.|  
|[COleControlSite::m\_dwStyle](../Topic/COleControlSite::m_dwStyle.md)|Os estilos de controle hospedado.|  
|[COleControlSite::m\_hWnd](../Topic/COleControlSite::m_hWnd.md)|O identificador do site do controle.|  
|[COleControlSite::m\_iidEvents](../Topic/COleControlSite::m_iidEvents.md)|O interface identificação do controle hospedado.|  
|[COleControlSite::m\_nID](../Topic/COleControlSite::m_nID.md)|A identificação de O controle hospedado.|  
|[COleControlSite::m\_pActiveObject](../Topic/COleControlSite::m_pActiveObject.md)|Um ponteiro para o objeto de `IOleInPlaceActiveObject` do controle hospedado.|  
|[COleControlSite::m\_pCtrlCont](../Topic/COleControlSite::m_pCtrlCont.md)|O contêiner do controle hospedado.|  
|[COleControlSite::m\_pInPlaceObject](../Topic/COleControlSite::m_pInPlaceObject.md)|Um ponteiro para o objeto de `IOleInPlaceObject` do controle hospedado.|  
|[COleControlSite::m\_pObject](../Topic/COleControlSite::m_pObject.md)|Um ponteiro para a interface de `IOleObjectInterface` do controle.|  
|[COleControlSite::m\_pWindowlessObject](../Topic/COleControlSite::m_pWindowlessObject.md)|Um ponteiro para a interface de `IOleInPlaceObjectWindowless` do controle.|  
|[COleControlSite::m\_pWndCtrl](../Topic/COleControlSite::m_pWndCtrl.md)|Um ponteiro para o objeto da janela para o controle hospedado.|  
|[COleControlSite::m\_rect](../Topic/COleControlSite::m_rect.md)|As dimensões do site do controle.|  
  
## Comentários  
 Este suporte é principais por significa que um controle ActiveX inserido obtém informações sobre o local e a extensão do seu site de exibição, do apelido, de sua interface do usuário, de suas propriedades de ambiente, e outros recursos fornecidos pelo recipiente.  `COleControlSite` implementa totalmente [IOleControlSite](http://msdn.microsoft.com/library/windows/desktop/ms688502), [IOleInPlaceSite](http://msdn.microsoft.com/library/windows/desktop/ms686586), [IOleClientSite](http://msdn.microsoft.com/library/windows/desktop/ms693706), [IPropertyNotifySink](http://msdn.microsoft.com/library/windows/desktop/ms692638), **IBoundObjectSite**, **INotifyDBEvents**, interfaces de [IRowSetNotify](https://msdn.microsoft.com/en-us/library/ms712959.aspx) .  Além de isso, a interface de IDispatch \(fornecendo suporte para propriedades e coletores de eventos de ambiente\) é implementada também.  
  
 Para criar um site do controle ActiveX usando `COleControlSite`, derive uma classe de `COleControlSite`.  Em o `CWnd`\- classe derivada do recipiente \(por exemplo, para a caixa de diálogo\) a substituição a função de **CWnd::CreateControlSite** .  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 `COleControlSite`  
  
## Requisitos  
 **Cabeçalho:** afxocc.h  
  
## Consulte também  
 [Classe de CCmdTarget](../Topic/CCmdTarget%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de COleControlContainer](../../mfc/reference/colecontrolcontainer-class.md)