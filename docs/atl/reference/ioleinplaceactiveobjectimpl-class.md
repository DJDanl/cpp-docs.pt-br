---
title: Classe IOleInPlaceActiveObjectImpl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- IOleInPlaceActiveObjectImpl
- ATLCTL/ATL::IOleInPlaceActiveObjectImpl
- ATLCTL/ATL::IOleInPlaceActiveObjectImpl::ContextSensitiveHelp
- ATLCTL/ATL::IOleInPlaceActiveObjectImpl::EnableModeless
- ATLCTL/ATL::IOleInPlaceActiveObjectImpl::GetWindow
- ATLCTL/ATL::IOleInPlaceActiveObjectImpl::OnDocWindowActivate
- ATLCTL/ATL::IOleInPlaceActiveObjectImpl::OnFrameWindowActivate
- ATLCTL/ATL::IOleInPlaceActiveObjectImpl::ResizeBorder
- ATLCTL/ATL::IOleInPlaceActiveObjectImpl::TranslateAccelerator
dev_langs:
- C++
helpviewer_keywords:
- IOleInPlaceActiveObjectImpl class
- ActiveX controls [C++], communication between container and control
- IOleInPlaceActiveObject, ATL implementation
ms.assetid: 44e6cc6d-a2dc-4187-98e3-73cf0320dea9
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1339f41a0764e44f46bed7ad24181ce406998c22
ms.sourcegitcommit: 7d68f8303e021e27dc8f4d36e764ed836e93d24f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/06/2018
ms.locfileid: "37885595"
---
# <a name="ioleinplaceactiveobjectimpl-class"></a>Classe IOleInPlaceActiveObjectImpl
Essa classe fornece métodos para ajudar a comunicação entre um controle no local e seu contêiner.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class T>
class IOleInPlaceActiveObjectImpl
```  
  
#### <a name="parameters"></a>Parâmetros  
 *T*  
 Sua classe, derivada de `IOleInPlaceActiveObjectImpl`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IOleInPlaceActiveObjectImpl::ContextSensitiveHelp](#contextsensitivehelp)|Permite que a Ajuda contextual. A implementação de ATL retornará E_NOTIMPL.|  
|[IOleInPlaceActiveObjectImpl::EnableModeless](#enablemodeless)|Habilita as caixas de diálogo sem janela restrita. A implementação de ATL Retorna S_OK.|  
|[IOleInPlaceActiveObjectImpl::GetWindow](#getwindow)|Obtém um identificador de janela.|  
|[IOleInPlaceActiveObjectImpl::OnDocWindowActivate](#ondocwindowactivate)|Notifica o controle quando a janela de documento do contêiner é ativada ou desativada. A implementação de ATL Retorna S_OK.|  
|[IOleInPlaceActiveObjectImpl::OnFrameWindowActivate](#onframewindowactivate)|Notifica o controle quando a janela de quadro de nível superior do contêiner é ativada ou desativada. Retorna a implementação do ATL|  
|[IOleInPlaceActiveObjectImpl::ResizeBorder](#resizeborder)|Informa o controle precisa redimensionar suas bordas. A implementação de ATL Retorna S_OK.|  
|[IOleInPlaceActiveObjectImpl::TranslateAccelerator](#translateaccelerator)|Processa as mensagens de tecla de atalho do menu do contêiner. A implementação de ATL retornará E_NOTIMPL.|  
  
  
## <a name="remarks"></a>Comentários  
 O [IOleInPlaceActiveObject](http://msdn.microsoft.com/library/windows/desktop/ms691299) interface auxilia a comunicação entre um controle no local e seu contêiner; por exemplo, se comunicando o estado ativo do controle e o contêiner e informar o controle precisa redimensionar em si. Classe `IOleInPlaceActiveObjectImpl` fornece uma implementação padrão de `IOleInPlaceActiveObject` e dá suporte a `IUnknown` enviando informações para o despejo de compilações de dispositivo na depuração.  
  
 **Artigos relacionados** [Tutorial da ATL](../../atl/active-template-library-atl-tutorial.md), [criando um projeto ATL](../../atl/reference/creating-an-atl-project.md)  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `IOleInPlaceActiveObject`  
  
 `IOleInPlaceActiveObjectImpl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlctl.h  
  
##  <a name="contextsensitivehelp"></a>  IOleInPlaceActiveObjectImpl::ContextSensitiveHelp  
 Permite que a Ajuda contextual.  
  
```
HRESULT ContextSensitiveHelp(BOOL fEnterMode);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retornará E_NOTIMPL.  
  
### <a name="remarks"></a>Comentários  
 Ver [IOleWindow::ContextSensitiveHelp](http://msdn.microsoft.com/library/windows/desktop/ms680059) no Windows SDK.  
  
##  <a name="enablemodeless"></a>  IOleInPlaceActiveObjectImpl::EnableModeless  
 Habilita as caixas de diálogo sem janela restrita.  
  
```
HRESULT EnableModeless(BOOL fEnable);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK.  
  
### <a name="remarks"></a>Comentários  
 Ver [IOleInPlaceActiveObject::EnableModeless](http://msdn.microsoft.com/library/windows/desktop/ms680115) no Windows SDK.  
  
##  <a name="getwindow"></a>  IOleInPlaceActiveObjectImpl::GetWindow  
 O contêiner chama essa função para obter o identificador de janela do controle.  
  
```
HRESULT GetWindow(HWND* phwnd);
```  
  
### <a name="remarks"></a>Comentários  
 Alguns contêineres não funcionará com um controle que tenha sido sem janelas, mesmo se ele está atualmente em janelas. Na implementação da ATL, se o `CComControl::m_bWasOnceWindowless` membro de dados for TRUE, a função retornará E_FAIL. Caso contrário, se \* *phwnd* não for nulo, `GetWindow` atribui *phwnd* ao membro de dados da classe de controle `m_hWnd` e retorna S_OK.  
  
 Ver [IOleWindow::GetWindow](http://msdn.microsoft.com/library/windows/desktop/ms687282) no Windows SDK.  
  
##  <a name="ondocwindowactivate"></a>  IOleInPlaceActiveObjectImpl::OnDocWindowActivate  
 Notifica o controle quando a janela de documento do contêiner é ativada ou desativada.  
  
```
HRESULT OnDocWindowActivate(BOOL fActivate);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK.  
  
### <a name="remarks"></a>Comentários  
 Ver [IOleInPlaceActiveObject::OnDocWindowActivate](http://msdn.microsoft.com/library/windows/desktop/ms687281) no Windows SDK.  
  
##  <a name="onframewindowactivate"></a>  IOleInPlaceActiveObjectImpl::OnFrameWindowActivate  
 Notifica o controle quando a janela de quadro de nível superior do contêiner é ativada ou desativada.  
  
```
HRESULT OnFrameWindowActivate(BOOL fActivate);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK.  
  
### <a name="remarks"></a>Comentários  
 Ver [IOleInPlaceActiveObject::OnFrameWindowActivate](http://msdn.microsoft.com/library/windows/desktop/ms683969) no Windows SDK.  
  
##  <a name="resizeborder"></a>  IOleInPlaceActiveObjectImpl::ResizeBorder  
 Informa o controle precisa redimensionar suas bordas.  
  
```
HRESULT ResizeBorder(
    LPRECT prcBorder,
    IOleInPlaceUIWindow* pUIWindow,
    BOOL fFrameWindow);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK.  
  
### <a name="remarks"></a>Comentários  
 Ver [IOleInPlaceActiveObject::ResizeBorder](http://msdn.microsoft.com/library/windows/desktop/ms680053) no Windows SDK.  
  
##  <a name="translateaccelerator"></a>  IOleInPlaceActiveObjectImpl::TranslateAccelerator  
 Processa as mensagens de tecla de atalho do menu do contêiner.  
  
```
HRESULT TranslateAccelerator(LPMSG lpmsg);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Esse método aceita os seguintes valores de retornados:  
  
 S_OK se a mensagem foi convertida com êxito.  
  
 S_FALSE se a mensagem não foi convertida.  
  
### <a name="remarks"></a>Comentários  
 Ver [IOleInPlaceActiveObject::TranslateAccelerator](http://msdn.microsoft.com/library/windows/desktop/ms693360) no Windows SDK.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CComControl](../../atl/reference/ccomcontrol-class.md)  
 [Interfaces de controles ActiveX](http://msdn.microsoft.com/library/windows/desktop/ms692724)  
 [Visão geral da classe](../../atl/atl-class-overview.md)
