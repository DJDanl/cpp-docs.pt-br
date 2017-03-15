---
title: Classe IOleInPlaceActiveObjectImpl | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- IOleInPlaceActiveObjectImpl
dev_langs:
- C++
helpviewer_keywords:
- IOleInPlaceActiveObjectImpl class
- ActiveX controls [C++], communication between container and control
- IOleInPlaceActiveObject, ATL implementation
ms.assetid: 44e6cc6d-a2dc-4187-98e3-73cf0320dea9
caps.latest.revision: 22
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 766ac40bb0a09902914feab1acc54a960261a768
ms.lasthandoff: 02/25/2017

---
# <a name="ioleinplaceactiveobjectimpl-class"></a>Classe IOleInPlaceActiveObjectImpl
Essa classe fornece métodos para ajudar a comunicação entre um controle no local e o contêiner.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados a [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class T>
class IOleInPlaceActiveObjectImpl
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 Sua classe derivada de `IOleInPlaceActiveObjectImpl`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IOleInPlaceActiveObjectImpl::ContextSensitiveHelp](#contextsensitivehelp)|Habilita a Ajuda contextual. Retorna a implementação de ATL **E_NOTIMPL**.|  
|[IOleInPlaceActiveObjectImpl::EnableModeless](#enablemodeless)|Habilita as caixas de diálogo sem janela restrita. Retorna a implementação de ATL `S_OK`.|  
|[IOleInPlaceActiveObjectImpl::GetWindow](#getwindow)|Obtém um identificador de janela.|  
|[IOleInPlaceActiveObjectImpl::OnDocWindowActivate](#ondocwindowactivate)|Notifica o controle quando a janela de documento do contêiner é ativada ou desativada. Retorna a implementação de ATL `S_OK`.|  
|[IOleInPlaceActiveObjectImpl::OnFrameWindowActivate](#onframewindowactivate)|Notifica o controle quando a janela de quadro de nível superior do contêiner é ativada ou desativada. Retorna a implementação do ATL|  
|[IOleInPlaceActiveObjectImpl::ResizeBorder](#resizeborder)|Informa o controle precisa redimensionar suas bordas. Retorna a implementação de ATL `S_OK`.|  
|[IOleInPlaceActiveObjectImpl::TranslateAccelerator](#translateaccelerator)|Processa mensagens de tecla aceleradora do menu do contêiner. Retorna a implementação de ATL **E_NOTIMPL**.|  
  
  
## <a name="remarks"></a>Comentários  
 O [IOleInPlaceActiveObject](http://msdn.microsoft.com/library/windows/desktop/ms691299) interface ajuda a comunicação entre um controle no local e o contêiner, por exemplo, se comunicar o estado ativo do controle e recipiente e informar o controle ele precisa se redimensiona. Classe `IOleInPlaceActiveObjectImpl` fornece uma implementação padrão de `IOleInPlaceActiveObject` e oferece suporte a **IUnknown** enviando informações para o despejo de compilações de dispositivo no modo de depuração.  
  
 **Artigos relacionados** [Tutorial da ATL](../../atl/active-template-library-atl-tutorial.md), [criando um projeto do ATL](../../atl/reference/creating-an-atl-project.md)  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `IOleInPlaceActiveObject`  
  
 `IOleInPlaceActiveObjectImpl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlctl.h  
  
##  <a name="a-namecontextsensitivehelpa--ioleinplaceactiveobjectimplcontextsensitivehelp"></a><a name="contextsensitivehelp"></a>IOleInPlaceActiveObjectImpl::ContextSensitiveHelp  
 Habilita a Ajuda contextual.  
  
```
HRESULT ContextSensitiveHelp(BOOL fEnterMode);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **E_NOTIMPL**.  
  
### <a name="remarks"></a>Comentários  
 Consulte [IOleWindow::ContextSensitiveHelp](http://msdn.microsoft.com/library/windows/desktop/ms680059) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-nameenablemodelessa--ioleinplaceactiveobjectimplenablemodeless"></a><a name="enablemodeless"></a>IOleInPlaceActiveObjectImpl::EnableModeless  
 Habilita as caixas de diálogo sem janela restrita.  
  
```
HRESULT EnableModeless(BOOL fEnable);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `S_OK`.  
  
### <a name="remarks"></a>Comentários  
 Consulte [IOleInPlaceActiveObject::EnableModeless](http://msdn.microsoft.com/library/windows/desktop/ms680115) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namegetwindowa--ioleinplaceactiveobjectimplgetwindow"></a><a name="getwindow"></a>IOleInPlaceActiveObjectImpl::GetWindow  
 O contêiner chama essa função para obter o identificador de janela do controle.  
  
```
HRESULT GetWindow(HWND* phwnd);
```  
  
### <a name="remarks"></a>Comentários  
 Alguns contêineres não funcionará com um controle que tenha sido sem janelas, mesmo que esteja atualmente em janelas. Na implementação da ATL, se o **CComControl::m_bWasOnceWindowless** é membro de dados **TRUE**, a função retorna **E_FAIL**. Caso contrário, se \* *phwnd* não é **nulo**, `GetWindow` atribui *phwnd* ao membro de dados da classe de controle `m_hWnd` e retorna `S_OK`.  
  
 Consulte [IOleWindow::GetWindow](http://msdn.microsoft.com/library/windows/desktop/ms687282) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-nameondocwindowactivatea--ioleinplaceactiveobjectimplondocwindowactivate"></a><a name="ondocwindowactivate"></a>IOleInPlaceActiveObjectImpl::OnDocWindowActivate  
 Notifica o controle quando a janela de documento do contêiner é ativada ou desativada.  
  
```
HRESULT OnDocWindowActivate(BOOL fActivate);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `S_OK`.  
  
### <a name="remarks"></a>Comentários  
 Consulte [IOleInPlaceActiveObject::OnDocWindowActivate](http://msdn.microsoft.com/library/windows/desktop/ms687281) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-nameonframewindowactivatea--ioleinplaceactiveobjectimplonframewindowactivate"></a><a name="onframewindowactivate"></a>IOleInPlaceActiveObjectImpl::OnFrameWindowActivate  
 Notifica o controle quando a janela de quadro de nível superior do contêiner é ativada ou desativada.  
  
```
HRESULT OnFrameWindowActivate(BOOL fActivate);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `S_OK`.  
  
### <a name="remarks"></a>Comentários  
 Consulte [IOleInPlaceActiveObject::OnFrameWindowActivate](http://msdn.microsoft.com/library/windows/desktop/ms683969) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-nameresizebordera--ioleinplaceactiveobjectimplresizeborder"></a><a name="resizeborder"></a>IOleInPlaceActiveObjectImpl::ResizeBorder  
 Informa o controle precisa redimensionar suas bordas.  
  
```
HRESULT ResizeBorder(
    LPRECT prcBorder,
    IOleInPlaceUIWindow* pUIWindow,
    BOOL fFrameWindow);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `S_OK`.  
  
### <a name="remarks"></a>Comentários  
 Consulte [IOleInPlaceActiveObject::ResizeBorder](http://msdn.microsoft.com/library/windows/desktop/ms680053) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-nametranslateacceleratora--ioleinplaceactiveobjectimpltranslateaccelerator"></a><a name="translateaccelerator"></a>IOleInPlaceActiveObjectImpl::TranslateAccelerator  
 Processa mensagens de tecla aceleradora do menu do contêiner.  
  
```
HRESULT TranslateAccelerator(LPMSG lpmsg);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Esse método aceita os seguintes valores de retornos:  
  
 `S_OK`Se a mensagem foi convertida com êxito.  
  
 **S_FALSE** se a mensagem não foi convertida.  
  
### <a name="remarks"></a>Comentários  
 Consulte [IOleInPlaceActiveObject::TranslateAccelerator](http://msdn.microsoft.com/library/windows/desktop/ms693360) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## <a name="see-also"></a>Consulte também  
 [Classe CComControl](../../atl/reference/ccomcontrol-class.md)  
 [Interfaces de controles ActiveX](http://msdn.microsoft.com/library/windows/desktop/ms692724)  
 [Visão geral da classe](../../atl/atl-class-overview.md)

