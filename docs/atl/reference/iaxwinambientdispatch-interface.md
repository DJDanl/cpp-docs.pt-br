---
title: "Interface de IAxWinAmbientDispatch | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "IAxWinAmbientDispatch"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Interface de IAxWinAmbientDispatch"
ms.assetid: 55ba6f7b-7a3c-4792-ae47-c8a84b683ca9
caps.latest.revision: 24
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Interface de IAxWinAmbientDispatch
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa interface fornece métodos para especificar características de controle ou recipiente hospedado.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
## Sintaxe  
  
```  
  
interface IAxWinAmbientDispatch : IDispatch  
  
```  
  
## Membros  
  
### Métodos  
  
|||  
|-|-|  
|[get\_AllowContextMenu](../Topic/IAxWinAmbientDispatch::get_AllowContextMenu.md)|A propriedade de **AllowContextMenu** especifica se o controle hospedado é permitido exibir seu próprio menu de contexto.|  
|[get\_AllowShowUI](../Topic/IAxWinAmbientDispatch::get_AllowShowUI.md)|A propriedade de **AllowShowUI** especifica se o controle hospedado é permitido exibir sua própria interface de usuário.|  
|[get\_AllowWindowlessActivation](../Topic/IAxWinAmbientDispatch::get_AllowWindowlessActivation.md)|a propriedade de **AllowWindowlessActivation** especifica se o contêiner permitirá a ativação sem janelas.|  
|[get\_BackColor](../Topic/IAxWinAmbientDispatch::get_BackColor.md)|A propriedade de `BackColor` especifica a cor do plano de fundo de ambiente de controles.|  
|[get\_DisplayAsDefault](../Topic/IAxWinAmbientDispatch::get_DisplayAsDefault.md)|**DisplayAsDefault** é uma propriedade de ambiente que permite que um controle localize se é o padrão.|  
|[get\_DocHostDoubleClickFlags](../Topic/IAxWinAmbientDispatch::get_DocHostDoubleClickFlags.md)|A propriedade de **DocHostDoubleClickFlags** especifica a operação que deve ocorrer em resposta a um clique duplo.|  
|[get\_DocHostFlags](../Topic/IAxWinAmbientDispatch::get_DocHostFlags.md)|A propriedade de **DocHostFlags** especifica os recursos de interface de usuário do objeto host.|  
|[get\_Font](../Topic/IAxWinAmbientDispatch::get_Font.md)|A propriedade de **Fonte** especifica a fonte de ambiente de controles.|  
|[get\_ForeColor](../Topic/IAxWinAmbientDispatch::get_ForeColor.md)|A propriedade de `ForeColor` especifica a cor de primeiro plano ambiente do recipiente.|  
|[get\_LocaleID](../Topic/IAxWinAmbientDispatch::get_LocaleID.md)|A propriedade de **LocaleID** especifica a ID local de ambiente de controles.|  
|[get\_MessageReflect](../Topic/IAxWinAmbientDispatch::get_MessageReflect.md)|A propriedade de ambiente de **MessageReflect** especifica se o contêiner refletirá mensagens ao controle hospedado.|  
|[get\_OptionKeyPath](../Topic/IAxWinAmbientDispatch::get_OptionKeyPath.md)|A propriedade de **OptionKeyPath** especifica o caminho da chave do Registro às configurações do usuário.|  
|[get\_ShowGrabHandles](../Topic/IAxWinAmbientDispatch::get_ShowGrabHandles.md)|A propriedade de ambiente de **ShowGrabHandles** permite que o controle localize se desenhar com captura alças.|  
|[get\_ShowHatching](../Topic/IAxWinAmbientDispatch::get_ShowHatching.md)|A propriedade de ambiente de **ShowHatching** permite que o controle localize se desenhar chocou.|  
|[get\_UserMode](../Topic/IAxWinAmbientDispatch::get_UserMode.md)|A propriedade de **UserMode** especifica o modo de usuário de ambiente de controles.|  
|[put\_AllowContextMenu](../Topic/IAxWinAmbientDispatch::put_AllowContextMenu.md)|A propriedade de **AllowContextMenu** especifica se o controle hospedado é permitido exibir seu próprio menu de contexto.|  
|[put\_AllowShowUI](../Topic/IAxWinAmbientDispatch::put_AllowShowUI.md)|A propriedade de **AllowShowUI** especifica se o controle hospedado é permitido exibir sua própria interface de usuário.|  
|[put\_AllowWindowlessActivation](../Topic/IAxWinAmbientDispatch::put_AllowWindowlessActivation.md)|a propriedade de **AllowWindowlessActivation** especifica se o contêiner permitirá a ativação sem janelas.|  
|[put\_BackColor](../Topic/IAxWinAmbientDispatch::put_BackColor.md)|A propriedade de `BackColor` especifica a cor do plano de fundo de ambiente de controles.|  
|[put\_DisplayAsDefault](../Topic/IAxWinAmbientDispatch::put_DisplayAsDefault.md)|**DisplayAsDefault** é uma propriedade de ambiente que permite que um controle localize se é o padrão.|  
|[put\_DocHostDoubleClickFlags](../Topic/IAxWinAmbientDispatch::put_DocHostDoubleClickFlags.md)|A propriedade de **DocHostDoubleClickFlags** especifica a operação que deve ocorrer em resposta a um clique duplo.|  
|[put\_DocHostFlags](../Topic/IAxWinAmbientDispatch::put_DocHostFlags.md)|A propriedade de **DocHostFlags** especifica os recursos de interface de usuário do objeto host.|  
|[put\_Font](../Topic/IAxWinAmbientDispatch::put_Font.md)|A propriedade de **Fonte** especifica a fonte de ambiente de controles.|  
|[put\_ForeColor](../Topic/IAxWinAmbientDispatch::put_ForeColor.md)|A propriedade de `ForeColor` especifica a cor de primeiro plano ambiente do recipiente.|  
|[put\_LocaleID](../Topic/IAxWinAmbientDispatch::put_LocaleID.md)|A propriedade de **LocaleID** especifica a ID local de ambiente de controles.|  
|[put\_MessageReflect](../Topic/IAxWinAmbientDispatch::put_MessageReflect.md)|A propriedade de ambiente de **MessageReflect** especifica se o contêiner refletirá mensagens ao controle hospedado.|  
|[put\_OptionKeyPath](../Topic/IAxWinAmbientDispatch::put_OptionKeyPath.md)|A propriedade de **OptionKeyPath** especifica o caminho da chave do Registro às configurações do usuário.|  
|[put\_UserMode](../Topic/IAxWinAmbientDispatch::put_UserMode.md)|A propriedade de **UserMode** especifica o modo de usuário de ambiente de controles.|  
  
## Comentários  
 Essa interface é exposta pelo controle ActiveX de ATL que hospeda objetos.  Chamar os métodos em esta interface para definir as propriedades de ambiente disponíveis para o controle hospedado ou para especificar outros aspectos de comportamento do contêiner.  Para complementar as propriedades fornecidos por `IAxWinAmbientDispatch`, usa [IAxWinAmbientDispatchEx](../../atl/reference/iaxwinambientdispatchex-interface.md).  
  
 [AXHost](https://msdn.microsoft.com/en-us/library/system.windows.forms.axhost.aspx) tentará carregar digite informações sobre `IAxWinAmbientDispatch` e `IAxWinAmbientDispatchEx` de typelib que contém o código.  
  
 Se você estiver vinculando a ATL90.dll, **AXHost** carregará informações de tipo de typelib no DLL.  
  
 Consulte [Hospedando controles ActiveX usando ATL AXHost](../../atl/hosting-activex-controls-using-atl-axhost.md) para obter mais detalhes.  
  
## Requisitos  
 A definição de essa interface está disponível em um número de formulários, conforme mostrado na tabela abaixo.  
  
|Definição de tipo|File|  
|-----------------------|----------|  
|IDL|atliface.idl|  
|Biblioteca de tipo|ATL.dll|  
|C\+\+|atliface.h \(também incluído em ATLBase.h\)|  
  
## Consulte também  
 [Interface de IAxWinAmbientDispatchEx](../../atl/reference/iaxwinambientdispatchex-interface.md)   
 [Interface de IAxWinHostWindow](../../atl/reference/iaxwinhostwindow-interface.md)   
 [CAxWindow::QueryHost](../Topic/CAxWindow::QueryHost.md)   
 [AtlAxGetHost](../Topic/AtlAxGetHost.md)