---
title: Classe IQuickActivateImpl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 9131a1cc1f8d0c66f2eb3616f4903db74ea4bdf0
ms.sourcegitcommit: 7d68f8303e021e27dc8f4d36e764ed836e93d24f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/06/2018
ms.locfileid: "37881367"
---
# <a name="iquickactivateimpl-class"></a>Classe IQuickActivateImpl
Essa classe combina a inicialização dos contêineres de controle em uma única chamada.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class T>  
class ATL_NO_VTABLE IQuickActivateImpl : public IQuickActivate
```  
  
#### <a name="parameters"></a>Parâmetros  
 *T*  
 Sua classe, derivada de `IQuickActivateImpl`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IQuickActivateImpl::GetContentExtent](#getcontentextent)|Recupera o tamanho de exibição atual para um controle em execução.|  
|[IQuickActivateImpl::QuickActivate](#quickactivate)|Executa a inicialização rápida de controles que está sendo carregado.|  
|[IQuickActivateImpl::SetContentExtent](#setcontentextent)|Informa o controle de quanto espaço de exibição, o contêiner foi atribuído a ele.|  
  
## <a name="remarks"></a>Comentários  
 O [IQuickActivate](http://msdn.microsoft.com/library/windows/desktop/ms690146) interface o ajuda a contêineres evitar atrasos ao carregar controles pela combinação de inicialização em uma única chamada. O `QuickActivate` método permite que o contêiner passar um ponteiro para uma [QACONTAINER](http://msdn.microsoft.com/library/windows/desktop/ms688630) precisa de estrutura que contém ponteiros para todas as interfaces de controle. No retorno, o controle passa de volta de um ponteiro para um [QACONTROL](http://msdn.microsoft.com/library/windows/desktop/ms693721) estrutura que contém ponteiros para suas próprias interfaces, que são usadas pelo contêiner. Classe `IQuickActivateImpl` fornece uma implementação padrão de `IQuickActivate` e implementa `IUnknown` enviando informações para o despejo de compilações de dispositivo na depuração.  
  
 **Artigos relacionados** [Tutorial da ATL](../../atl/active-template-library-atl-tutorial.md), [criando um projeto ATL](../../atl/reference/creating-an-atl-project.md)  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `IQuickActivate`  
  
 `IQuickActivateImpl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlctl.h  
  
##  <a name="getcontentextent"></a>  IQuickActivateImpl::GetContentExtent  
 Recupera o tamanho de exibição atual para um controle em execução.  
  
```
STDMETHOD(GetContentExtent)(LPSIZEL pSize);
```  
  
### <a name="remarks"></a>Comentários  
 O tamanho é para um processamento completo do controle e é especificado em unidades HIMETRIC.  
  
 Ver [IQuickActivate::GetContentExtent](http://msdn.microsoft.com/library/windows/desktop/ms693792) no Windows SDK.  
  
##  <a name="quickactivate"></a>  IQuickActivateImpl::QuickActivate  
 Executa a inicialização rápida de controles que está sendo carregado.  
  
```
STDMETHOD(QuickActivate)(
    QACONTAINER* pQACont,
    QACONTROL* pQACtrl);
```  
  
### <a name="remarks"></a>Comentários  
 A estrutura contém ponteiros para as interfaces necessárias para o controle e os valores de algumas propriedades de ambiente. Após o retorno, o controle passa um ponteiro para um [QACONTROL](http://msdn.microsoft.com/library/windows/desktop/ms693721) estrutura que contém ponteiros para suas próprias interfaces que requer que o contêiner e informações de status adicionais.  
  
 Ver [IQuickActivate::QuickActivate](http://msdn.microsoft.com/library/windows/desktop/ms682421) no Windows SDK.  
  
##  <a name="setcontentextent"></a>  IQuickActivateImpl::SetContentExtent  
 Informa o controle de quanto espaço de exibição, o contêiner foi atribuído a ele.  
  
```
STDMETHOD(SetContentExtent)(LPSIZEL pSize);
```  
  
### <a name="remarks"></a>Comentários  
 O tamanho é especificado em unidades HIMETRIC.  
  
 Ver [IQuickActivate::SetContentExtent](http://msdn.microsoft.com/library/windows/desktop/ms678806) no Windows SDK.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CComControl](../../atl/reference/ccomcontrol-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
