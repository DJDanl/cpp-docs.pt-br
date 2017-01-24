---
title: "Classe de IOleObjectImpl | Microsoft Docs"
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
  - "ATL.IOleObjectImpl"
  - "ATL.IOleObjectImpl<T>"
  - "ATL::IOleObjectImpl"
  - "ATL::IOleObjectImpl<T>"
  - "IOleObjectImpl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Controles ActiveX [C++], comunicação entre o contêiner e o controle"
  - "IOleObject, Implementação de ATL"
  - "Classe de IOleObjectImpl"
ms.assetid: 59750b2d-1633-4a51-a4c2-6455b6b90c45
caps.latest.revision: 20
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de IOleObjectImpl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe implementa **IUnknown** e é a interface principal através de um contêiner que se comunica com um controle.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
## Sintaxe  
  
```  
  
      template<  
class T   
>  
class ATL_NO_VTABLE IOleObjectImpl :  
public IOleObject  
```  
  
#### Parâmetros  
 `T`  
 Sua classe, derivada de `IOleObjectImpl`.  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[IOleObjectImpl::Advise](../Topic/IOleObjectImpl::Advise.md)|Estabelece uma conexão consultiva com o controle.|  
|[IOleObjectImpl::Close](../Topic/IOleObjectImpl::Close.md)|Altera o estado de controle de execução quando carregado.|  
|[IOleObjectImpl::DoVerb](../Topic/IOleObjectImpl::DoVerb.md)|Com o controle para executar uma de suas ações enumeradas.|  
|[IOleObjectImpl::DoVerbDiscardUndo](../Topic/IOleObjectImpl::DoVerbDiscardUndo.md)|Com o controle para descartar qualquer desfazem o estado que está mantendo.|  
|[IOleObjectImpl::DoVerbHide](../Topic/IOleObjectImpl::DoVerbHide.md)|Com o controle para remover a interface do usuário de exibição.|  
|[IOleObjectImpl::DoVerbInPlaceActivate](../Topic/IOleObjectImpl::DoVerbInPlaceActivate.md)|Executa o controle e instala a janela, mas não instala a interface do usuário.|  
|[IOleObjectImpl::DoVerbOpen](../Topic/IOleObjectImpl::DoVerbOpen.md)|Faz com que o controle aberto na ser editado uma janela separada.|  
|[IOleObjectImpl::DoVerbPrimary](../Topic/IOleObjectImpl::DoVerbPrimary.md)|Executa a ação específica quando o usuário clica duas vezes no controle.  O controle define a ação em geral, active o controle no lugar.|  
|[IOleObjectImpl::DoVerbShow](../Topic/IOleObjectImpl::DoVerbShow.md)|Mostra um controle mais recentemente inserido para o usuário.|  
|[IOleObjectImpl::DoVerbUIActivate](../Topic/IOleObjectImpl::DoVerbUIActivate.md)|Alterna o controle no lugar e mostra a interface do usuário do controle, como menus e barras de ferramentas.|  
|[IOleObjectImpl::EnumAdvise](../Topic/IOleObjectImpl::EnumAdvise.md)|Enumera as conexões consultivas do controle.|  
|[IOleObjectImpl::EnumVerbs](../Topic/IOleObjectImpl::EnumVerbs.md)|Enumera ações para o controle.|  
|[IOleObjectImpl::GetClientSite](../Topic/IOleObjectImpl::GetClientSite.md)|Recupera o site cliente do controle.|  
|[IOleObjectImpl::GetClipboardData](../Topic/IOleObjectImpl::GetClipboardData.md)|Recupera dados da área de transferência.  a implementação de ATL retorna **E\_NOTIMPL**.|  
|[IOleObjectImpl::GetExtent](../Topic/IOleObjectImpl::GetExtent.md)|Recupera a extensão da área de exibição do controle.|  
|[IOleObjectImpl::GetMiscStatus](../Topic/IOleObjectImpl::GetMiscStatus.md)|Recupera o status do controle.|  
|[IOleObjectImpl::GetMoniker](../Topic/IOleObjectImpl::GetMoniker.md)|Recupera um apelido do controle.  a implementação de ATL retorna **E\_NOTIMPL**.|  
|[IOleObjectImpl::GetUserClassID](../Topic/IOleObjectImpl::GetUserClassID.md)|Recupera o identificador da classe do controle.|  
|[IOleObjectImpl::GetUserType](../Topic/IOleObjectImpl::GetUserType.md)|Recupera o nome do tipo de controle.|  
|[IOleObjectImpl::InitFromData](../Topic/IOleObjectImpl::InitFromData.md)|Inicializa o controle de dados selecionados.  a implementação de ATL retorna **E\_NOTIMPL**.|  
|[IOleObjectImpl::IsUpToDate](../Topic/IOleObjectImpl::IsUpToDate.md)|Verifica se o controle é atualizado.  a implementação de ATL retorna `S_OK`.|  
|[IOleObjectImpl::OnPostVerbDiscardUndo](../Topic/IOleObjectImpl::OnPostVerbDiscardUndo.md)|Chamado por [DoVerbDiscardUndo](../Topic/IOleObjectImpl::DoVerbDiscardUndo.md) após o estado desfazer é descartado.|  
|[IOleObjectImpl::OnPostVerbHide](../Topic/IOleObjectImpl::OnPostVerbHide.md)|Chamado por [DoVerbHide](../Topic/IOleObjectImpl::DoVerbHide.md) após o controle está oculto.|  
|[IOleObjectImpl::OnPostVerbInPlaceActivate](../Topic/IOleObjectImpl::OnPostVerbInPlaceActivate.md)|Chamado por [DoVerbInPlaceActivate](../Topic/IOleObjectImpl::DoVerbInPlaceActivate.md) após o controle é ativado no lugar.|  
|[IOleObjectImpl::OnPostVerbOpen](../Topic/IOleObjectImpl::OnPostVerbOpen.md)|Por [DoVerbOpen](../Topic/IOleObjectImpl::DoVerbOpen.md) chamado depois que o controle foi aberto editando em uma janela separada.|  
|[IOleObjectImpl::OnPostVerbShow](../Topic/IOleObjectImpl::OnPostVerbShow.md)|Por [DoVerbShow](../Topic/IOleObjectImpl::DoVerbShow.md) chamado depois que o controle foi feito visível.|  
|[IOleObjectImpl::OnPostVerbUIActivate](../Topic/IOleObjectImpl::OnPostVerbUIActivate.md)|Chamado por [DoVerbUIActivate](../Topic/IOleObjectImpl::DoVerbUIActivate.md) após a interface do usuário do controle foi ativado.|  
|[IOleObjectImpl::OnPreVerbDiscardUndo](../Topic/IOleObjectImpl::OnPreVerbDiscardUndo.md)|Chamado por [DoVerbDiscardUndo](../Topic/IOleObjectImpl::DoVerbDiscardUndo.md) antes de estado desfazer é descartado.|  
|[IOleObjectImpl::OnPreVerbHide](../Topic/IOleObjectImpl::OnPreVerbHide.md)|Chamado por [DoVerbHide](../Topic/IOleObjectImpl::DoVerbHide.md) antes do controle está oculto.|  
|[IOleObjectImpl::OnPreVerbInPlaceActivate](../Topic/IOleObjectImpl::OnPreVerbInPlaceActivate.md)|Chamado por [DoVerbInPlaceActivate](../Topic/IOleObjectImpl::DoVerbInPlaceActivate.md) antes do controle é ativado no lugar.|  
|[IOleObjectImpl::OnPreVerbOpen](../Topic/IOleObjectImpl::OnPreVerbOpen.md)|Por [DoVerbOpen](../Topic/IOleObjectImpl::DoVerbOpen.md) chamado antes que o controle é aberto editando em uma janela separada.|  
|[IOleObjectImpl::OnPreVerbShow](../Topic/IOleObjectImpl::OnPreVerbShow.md)|Por [DoVerbShow](../Topic/IOleObjectImpl::DoVerbShow.md) chamado antes que o controle é feito visível.|  
|[IOleObjectImpl::OnPreVerbUIActivate](../Topic/IOleObjectImpl::OnPreVerbUIActivate.md)|Chamado por [DoVerbUIActivate](../Topic/IOleObjectImpl::DoVerbUIActivate.md) antes da interface do usuário do controle está ativado.|  
|[IOleObjectImpl::SetClientSite](../Topic/IOleObjectImpl::SetClientSite.md)|Com o controle sobre seu site de cliente no recipiente.|  
|[IOleObjectImpl::SetColorScheme](../Topic/IOleObjectImpl::SetColorScheme.md)|Recomendável um esquema de cores para o aplicativo do controle, se houver.  a implementação de ATL retorna **E\_NOTIMPL**.|  
|[IOleObjectImpl::SetExtent](../Topic/IOleObjectImpl::SetExtent.md)|Define a extensão da área de exibição do controle.|  
|[IOleObjectImpl::SetHostNames](../Topic/IOleObjectImpl::SetHostNames.md)|Informa ao controle os nomes do aplicativo e do documento recipiente de controles.|  
|[IOleObjectImpl::SetMoniker](../Topic/IOleObjectImpl::SetMoniker.md)|Informa ao controle que o apelido é.  a implementação de ATL retorna **E\_NOTIMPL**.|  
|[IOleObjectImpl::Unadvise](../Topic/IOleObjectImpl::Unadvise.md)|Exclui uma conexão consultiva com o controle.|  
|[IOleObjectImpl::Update](../Topic/IOleObjectImpl::Update.md)|Atualiza o controle.  a implementação de ATL retorna `S_OK`.|  
  
## Comentários  
 A interface de [IOleObject](http://msdn.microsoft.com/library/windows/desktop/dd542709) é a interface principal através de um contêiner que se comunica com um controle.  A classe `IOleObjectImpl` fornece uma implementação padrão de esta interface e implementa **IUnknown** enviar informações para o dispositivo de despejo em compilações de depuração.  
  
 **Artigos relacionados** [tutorial de ATL](../Topic/Active%20Template%20Library%20\(ATL\)%20Tutorial.md), [criando um projeto de ATL](../../atl/reference/creating-an-atl-project.md)  
  
## Hierarquia de herança  
 `IOleObject`  
  
 `IOleObjectImpl`  
  
## Requisitos  
 **Cabeçalho:** atlctl.h  
  
## Consulte também  
 [Classe de CComControl](../../atl/reference/ccomcontrol-class.md)   
 [ActiveX Controls Interfaces](http://msdn.microsoft.com/library/windows/desktop/ms692724)   
 [Visão geral de classe](../../atl/atl-class-overview.md)