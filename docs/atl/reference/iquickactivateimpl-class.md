---
title: Classe IQuickActivateImpl | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- IQuickActivateImpl
- ATLCTL/ATL::IQuickActivateImpl
- ATLCTL/ATL::IQuickActivateImpl::GetContentExtent
- ATLCTL/ATL::IQuickActivateImpl::QuickActivate
- ATLCTL/ATL::IQuickActivateImpl::SetContentExtent
dev_langs:
- C++
helpviewer_keywords:
- activating ATL controls
- controls [ATL], activating
- IQuickActivateImpl class
- IQuickActivate ATL implementation
ms.assetid: aa80c056-1041-494e-b21d-2acca7dc27ea
caps.latest.revision: 20
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 4f6b75da64efa12e43fa160c57da4291acae03ca
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="iquickactivateimpl-class"></a>Classe IQuickActivateImpl
Essa classe combina a inicialização do controle dos contêineres em uma única chamada.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados a [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class T>  
class ATL_NO_VTABLE IQuickActivateImpl : public IQuickActivate
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 Sua classe derivada de `IQuickActivateImpl`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IQuickActivateImpl::GetContentExtent](#getcontentextent)|Recupera o tamanho atual da exibição para um controle em execução.|  
|[IQuickActivateImpl::QuickActivate](#quickactivate)|Executa a inicialização rápida dos controles que está sendo carregado.|  
|[IQuickActivateImpl::SetContentExtent](#setcontentextent)|Informa o controle de quanto espaço de exibição o contêiner foi atribuído a ele.|  
  
## <a name="remarks"></a>Comentários  
 O [IQuickActivate](http://msdn.microsoft.com/library/windows/desktop/ms690146) interface ajuda contêineres evitar atrasos ao carregar controles pela combinação de inicialização em uma única chamada. O `QuickActivate` método permite que o contêiner passar um ponteiro para um [QACONTAINER](http://msdn.microsoft.com/library/windows/desktop/ms688630) precisa de estrutura que contém ponteiros para todas as interfaces de controle. No retorno, o controle passa de volta de um ponteiro para um [QACONTROL](http://msdn.microsoft.com/library/windows/desktop/ms693721) estrutura que contém ponteiros para suas próprias interfaces, que são usadas pelo contêiner. Classe `IQuickActivateImpl` fornece uma implementação padrão de **IQuickActivate** e implementa **IUnknown** enviando informações para o despejo de compilações de dispositivo no modo de depuração.  
  
 **Artigos relacionados** [Tutorial da ATL](../../atl/active-template-library-atl-tutorial.md), [criando um projeto do ATL](../../atl/reference/creating-an-atl-project.md)  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `IQuickActivate`  
  
 `IQuickActivateImpl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlctl.h  
  
##  <a name="getcontentextent"></a>IQuickActivateImpl::GetContentExtent  
 Recupera o tamanho atual da exibição para um controle em execução.  
  
```
STDMETHOD(GetContentExtent)(LPSIZEL pSize);
```  
  
### <a name="remarks"></a>Comentários  
 O tamanho é para um processamento completo do controle e é especificado em unidades HIMETRIC.  
  
 Consulte [IQuickActivate::GetContentExtent](http://msdn.microsoft.com/library/windows/desktop/ms693792) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="quickactivate"></a>IQuickActivateImpl::QuickActivate  
 Executa a inicialização rápida dos controles que está sendo carregado.  
  
```
STDMETHOD(QuickActivate)(
    QACONTAINER* pQACont,
    QACONTROL* pQACtrl);
```  
  
### <a name="remarks"></a>Comentários  
 A estrutura contém ponteiros para as interfaces necessárias para o controle e os valores de algumas propriedades de ambiente. Ao retornar, o controle passa um ponteiro para um [QACONTROL](http://msdn.microsoft.com/library/windows/desktop/ms693721) estrutura que contém ponteiros para suas próprias interfaces que requer que o contêiner e informações de status adicionais.  
  
 Consulte [IQuickActivate::QuickActivate](http://msdn.microsoft.com/library/windows/desktop/ms682421) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="setcontentextent"></a>IQuickActivateImpl::SetContentExtent  
 Informa o controle de quanto espaço de exibição o contêiner foi atribuído a ele.  
  
```
STDMETHOD(SetContentExtent)(LPSIZEL pSize);
```  
  
### <a name="remarks"></a>Comentários  
 O tamanho é especificado em unidades HIMETRIC.  
  
 Consulte [IQuickActivate::SetContentExtent](http://msdn.microsoft.com/library/windows/desktop/ms678806) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## <a name="see-also"></a>Consulte também  
 [Classe CComControl](../../atl/reference/ccomcontrol-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)

