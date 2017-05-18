---
title: Classe IPersistStreamInitImpl | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- IPersistStreamInitImpl
- ATLCOM/ATL::IPersistStreamInitImpl
- ATLCOM/ATL::IPersistStreamInitImpl::GetClassID
- ATLCOM/ATL::IPersistStreamInitImpl::GetSizeMax
- ATLCOM/ATL::IPersistStreamInitImpl::InitNew
- ATLCOM/ATL::IPersistStreamInitImpl::IsDirty
- ATLCOM/ATL::IPersistStreamInitImpl::Load
- ATLCOM/ATL::IPersistStreamInitImpl::Save
dev_langs:
- C++
helpviewer_keywords:
- IPersistStreamInit ATL implementation
- IPersistStreamInitImpl class
- streams, ATL
ms.assetid: ef217c3c-020f-4cf8-871e-ef68e57865b8
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
ms.sourcegitcommit: 604a4bf49490ad2599c857eb3afd527d67e1e25b
ms.openlocfilehash: aa8427a891ac8d8e18ec7794a12e838a55bc23c8
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="ipersiststreaminitimpl-class"></a>Classe IPersistStreamInitImpl
Essa classe implementa **IUnknown** e fornece uma implementação padrão da [IPersistStreamInit](http://msdn.microsoft.com/library/windows/desktop/ms682273) interface.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados a [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class T>  
class ATL_NO_VTABLE IPersistStreamInitImpl 
   : public IPersistStreamInit
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 Sua classe derivada de `IPersistStreamInitImpl`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IPersistStreamInitImpl::GetClassID](#getclassid)|Recupera o CLSID do objeto.|  
|[IPersistStreamInitImpl::GetSizeMax](#getsizemax)|Recupera o tamanho do fluxo necessário para salvar os dados do objeto. Retorna a implementação de ATL **E_NOTIMPL**.|  
|[IPersistStreamInitImpl::InitNew](#initnew)|Inicializa um objeto recém-criado.|  
|[IPersistStreamInitImpl::IsDirty](#isdirty)|Verifica se os dados do objeto foi alterado desde que foi salvo pela última vez.|  
|[IPersistStreamInitImpl::Load](#load)|Carrega as propriedades do objeto do fluxo especificado.|  
|[IPersistStreamInitImpl::Save](#save)|Salva as propriedades do objeto para o fluxo especificado.|  
  
## <a name="remarks"></a>Comentários  
 O [IPersistStreamInit](http://msdn.microsoft.com/library/windows/desktop/ms682273) interface permite que um cliente solicite que seu objeto carrega e salva os dados persistentes em um único fluxo. Classe `IPersistStreamInitImpl` fornece uma implementação padrão dessa interface e implementa **IUnknown** enviando informações para o despejo de compilações de dispositivo no modo de depuração.  
  
 **Artigos relacionados** [Tutorial da ATL](../../atl/active-template-library-atl-tutorial.md), [criando um projeto do ATL](../../atl/reference/creating-an-atl-project.md)  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `IPersistStreamInit`  
  
 `IPersistStreamInitImpl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom.h  
  
##  <a name="getclassid"></a>IPersistStreamInitImpl::GetClassID  
 Recupera o CLSID do objeto.  
  
```
STDMETHOD(GetClassID)(CLSID* pClassID);
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [IPersist::GetClassID](http://msdn.microsoft.com/library/windows/desktop/ms688664) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="getsizemax"></a>IPersistStreamInitImpl::GetSizeMax  
 Recupera o tamanho do fluxo necessário para salvar os dados do objeto.  
  
```
STDMETHOD(GetSizeMax)(ULARGE_INTEGER FAR* pcbSize);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **E_NOTIMPL**.  
  
### <a name="remarks"></a>Comentários  
 Consulte [IPersistStreamInit::GetSizeMax](http://msdn.microsoft.com/library/windows/desktop/ms687287) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="initnew"></a>IPersistStreamInitImpl::InitNew  
 Inicializa um objeto recém-criado.  
  
```
STDMETHOD(InitNew)();
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [IPersistStreamInit::InitNew](http://msdn.microsoft.com/library/windows/desktop/ms690234) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="isdirty"></a>IPersistStreamInitImpl::IsDirty  
 Verifica se os dados do objeto foi alterado desde que foi salvo pela última vez.  
  
```
STDMETHOD(IsDirty)();
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [IPersistStreamInit::IsDirty](http://msdn.microsoft.com/library/windows/desktop/ms680092) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="load"></a>IPersistStreamInitImpl::Load  
 Carrega as propriedades do objeto do fluxo especificado.  
  
```
STDMETHOD(Load)(LPSTREAM pStm);
```  
  
### <a name="remarks"></a>Comentários  
 ATL usa mapa de propriedade do objeto para recuperar essas informações.  
  
 Consulte [IPersistStreamInit::Load](http://msdn.microsoft.com/library/windows/desktop/ms680730) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="save"></a>IPersistStreamInitImpl::Save  
 Salva as propriedades do objeto para o fluxo especificado.  
  
```
STDMETHOD(Save)(LPSTREAM pStm, BOOL fClearDirty);
```  
  
### <a name="remarks"></a>Comentários  
 ATL usa mapa de propriedade do objeto para armazenar essas informações.  
  
 Consulte [IPersistStreamInit::Save](http://msdn.microsoft.com/library/windows/desktop/ms694439) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## <a name="see-also"></a>Consulte também  
 [Fluxos e armazenamentos](http://msdn.microsoft.com/library/windows/desktop/aa380352)   
 [Visão geral da classe](../../atl/atl-class-overview.md)

