---
title: Classe IOleInPlaceObjectWindowlessImpl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- IOleInPlaceObjectWindowlessImpl
- ATLCTL/ATL::IOleInPlaceObjectWindowlessImpl
- ATLCTL/ATL::IOleInPlaceObjectWindowlessImpl::ContextSensitiveHelp
- ATLCTL/ATL::IOleInPlaceObjectWindowlessImpl::GetDropTarget
- ATLCTL/ATL::IOleInPlaceObjectWindowlessImpl::GetWindow
- ATLCTL/ATL::IOleInPlaceObjectWindowlessImpl::InPlaceDeactivate
- ATLCTL/ATL::IOleInPlaceObjectWindowlessImpl::OnWindowMessage
- ATLCTL/ATL::IOleInPlaceObjectWindowlessImpl::ReactivateAndUndo
- ATLCTL/ATL::IOleInPlaceObjectWindowlessImpl::SetObjectRects
- ATLCTL/ATL::IOleInPlaceObjectWindowlessImpl::UIDeactivate
dev_langs:
- C++
helpviewer_keywords:
- IOleInPlaceObjectWindowless, ATL implementation
- activation [C++], ATL
- IOleInPlaceObjectWindowlessImpl class
- ActiveX controls [C++], communication between container and control
- controls [ATL], windowless
- deactivating ATL
ms.assetid: a2e0feb4-bc59-4adf-aab2-105457bbdbb4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f5616258405eb8346132d32b8f7fd71d0b4794d6
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32364996"
---
# <a name="ioleinplaceobjectwindowlessimpl-class"></a>Classe IOleInPlaceObjectWindowlessImpl
Essa classe implementa **IUnknown** e fornece métodos que permitem um controle sem janelas para receber mensagens de janela e participar de operações de arrastar e soltar.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class T>
class IOleInPlaceObjectWindowlessImpl
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 A classe derivada de `IOleInPlaceObjectWindowlessImpl`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IOleInPlaceObjectWindowlessImpl::ContextSensitiveHelp](#contextsensitivehelp)|Habilita a Ajuda contextual. Retorna a implementação de ATL **E_NOTIMPL**.|  
|[IOleInPlaceObjectWindowlessImpl::GetDropTarget](#getdroptarget)|Fornece o `IDropTarget` interface para um objeto local ativo, sem janelas que dá suporte a arrastar e soltar. Retorna a implementação de ATL **E_NOTIMPL**.|  
|[IOleInPlaceObjectWindowlessImpl::GetWindow](#getwindow)|Obtém um identificador de janela.|  
|[IOleInPlaceObjectWindowlessImpl::InPlaceDeactivate](#inplacedeactivate)|Desativa um controle ativo do local.|  
|[IOleInPlaceObjectWindowlessImpl::OnWindowMessage](#onwindowmessage)|Envia uma mensagem de contêiner para um controle sem janelas que está ativo no local.|  
|[IOleInPlaceObjectWindowlessImpl::ReactivateAndUndo](#reactivateandundo)|Reativa um controle desativado anteriormente. Retorna a implementação de ATL **E_NOTIMPL**.|  
|[IOleInPlaceObjectWindowlessImpl::SetObjectRects](#setobjectrects)|Indica qual parte do controle no local é visível.|  
|[IOleInPlaceObjectWindowlessImpl::UIDeactivate](#uideactivate)|Desativa e remove a interface do usuário que oferece suporte à ativação no local.|  
  
## <a name="remarks"></a>Comentários  
 O [IOleInPlaceObject](http://msdn.microsoft.com/library/windows/desktop/ms692646) interface gerencia a reativação e desativação do local controla e determina o quanto do controle deve ser visível. O [IOleInPlaceObjectWindowless](http://msdn.microsoft.com/library/windows/desktop/ms687304) interface permite que um controle sem janelas para receber mensagens de janela e participar de operações de arrastar e soltar. Classe `IOleInPlaceObjectWindowlessImpl` fornece uma implementação padrão de `IOleInPlaceObject` e `IOleInPlaceObjectWindowless` e implementa **IUnknown** enviando informações para o despejo compilações dispositivo na depuração.  
  
 **Artigos relacionados** [Tutorial da ATL](../../atl/active-template-library-atl-tutorial.md), [criando um projeto ATL](../../atl/reference/creating-an-atl-project.md)  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `IOleInPlaceObjectWindowless`  
  
 `IOleInPlaceObjectWindowlessImpl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlctl.h  
  
##  <a name="contextsensitivehelp"></a>  IOleInPlaceObjectWindowlessImpl::ContextSensitiveHelp  
 Retorna **E_NOTIMPL**.  
  
```
HRESULT ContextSensitiveHelp(BOOL fEnterMode);
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [IOleWindow::ContextSensitiveHelp](http://msdn.microsoft.com/library/windows/desktop/ms680059) no SDK do Windows.  
  
##  <a name="getdroptarget"></a>  IOleInPlaceObjectWindowlessImpl::GetDropTarget  
 Retorna **E_NOTIMPL**.  
  
```
HRESULT GetDropTarget(IDropTarget** ppDropTarget);
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [IOleInPlaceObjectWindowless::GetDropTarget](http://msdn.microsoft.com/library/windows/desktop/ms678535) no SDK do Windows.  
  
##  <a name="getwindow"></a>  IOleInPlaceObjectWindowlessImpl::GetWindow  
 O contêiner chama esta função para obter o identificador de janela do controle.  
  
```
HRESULT GetWindow(HWND* phwnd);
```  
  
### <a name="remarks"></a>Comentários  
 Alguns contêineres não funcionará com um controle que tenha sido sem janelas, mesmo se estiver atualmente em janelas. Na implementação do ATL, se o membro de dados da classe de controle `m_bWasOnceWindowless` é **TRUE**, a função retorna **E_FAIL**. Caso contrário, se *phwnd* não é **nulo**, `GetWindow` define \* *phwnd* para membro de dados da classe de controle `m_hWnd` e retorna `S_OK`.  
  
 Consulte [IOleWindow::GetWindow](http://msdn.microsoft.com/library/windows/desktop/ms687282) no SDK do Windows.  
  
##  <a name="inplacedeactivate"></a>  IOleInPlaceObjectWindowlessImpl::InPlaceDeactivate  
 Chamado pelo contêiner para desativar um controle ativo no local.  
  
```
HRESULT InPlaceDeactivate(HWND* phwnd);
```  
  
### <a name="remarks"></a>Comentários  
 Esse método executa uma desativação completa ou parcial, dependendo do estado do controle. Se necessário, interface do usuário do controle é desativado e a janela do controle, se houver, é destruída. O contêiner é notificado de que o controle não está mais ativo em vigor. O **IOleInPlaceUIWindow** interface usada pelo contêiner para negociar menus e espaço da borda é liberado.  
  
 Consulte [IOleInPlaceObject::InPlaceDeactivate](http://msdn.microsoft.com/library/windows/desktop/ms679700) no SDK do Windows.  
  
##  <a name="onwindowmessage"></a>  IOleInPlaceObjectWindowlessImpl::OnWindowMessage  
 Envia uma mensagem de um contêiner para um controle sem janelas que está ativo no local.  
  
```
HRESULT OnWindowMessage(
    UINT msg,
    WPARAM WParam,
    LPARAM LParam,
    LRESULT plResultParam);
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [IOleInPlaceObjectWindowless::OnWindowMessage](http://msdn.microsoft.com/library/windows/desktop/ms693783) no SDK do Windows.  
  
##  <a name="reactivateandundo"></a>  IOleInPlaceObjectWindowlessImpl::ReactivateAndUndo  
 Retorna **E_NOTIMPL**.  
  
```
HRESULT ReactivateAndUndo();
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [IOleInPlaceObject::ReactivateAndUndo](http://msdn.microsoft.com/library/windows/desktop/ms691372) no SDK do Windows.  
  
##  <a name="setobjectrects"></a>  IOleInPlaceObjectWindowlessImpl::SetObjectRects  
 Chamado pelo contêiner para informar o controle que seu tamanho e/ou a posição foi alterada.  
  
```
HRESULT SetObjectRects(LPCRECT prcPos, LPCRECT prcClip);
```  
  
### <a name="remarks"></a>Comentários  
 Atualiza o controle `m_rcPos` membro de dados e a exibição de controle. Somente a parte do controle que faz interseção com a região de clip é exibida. Se a exibição do controle foi recortada anteriormente, mas o recorte foi removido, essa função pode ser chamada para redesenhar uma exibição completa do controle.  
  
 Consulte [IOleInPlaceObject::SetObjectRects](http://msdn.microsoft.com/library/windows/desktop/ms683767) no SDK do Windows.  
  
##  <a name="uideactivate"></a>  IOleInPlaceObjectWindowlessImpl::UIDeactivate  
 Desativa e remove a interface do usuário do controle que dá suporte à ativação no local.  
  
```
HRESULT UIDeactivate();
```  
  
### <a name="remarks"></a>Comentários  
 Define o membro de dados da classe de controle `m_bUIActive` para **FALSE**. A implementação de ATL desta função sempre retorna `S_OK`.  
  
 Consulte [IOleInPlaceObject::UIDeactivate](http://msdn.microsoft.com/library/windows/desktop/ms693348) no SDK do Windows.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CComControl](../../atl/reference/ccomcontrol-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
