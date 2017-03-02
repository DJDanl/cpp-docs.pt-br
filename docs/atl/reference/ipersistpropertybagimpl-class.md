---
title: Classe IPersistPropertyBagImpl | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- IPersistPropertyBagImpl
- ATL.IPersistPropertyBagImpl<T>
- ATL::IPersistPropertyBagImpl
- ATL::IPersistPropertyBagImpl<T>
- ATL.IPersistPropertyBagImpl
dev_langs:
- C++
helpviewer_keywords:
- IPersistPropertyBagImpl class
ms.assetid: 712af24d-99f8-40f2-9811-53b3ff6e5b19
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
translationtype: Machine Translation
ms.sourcegitcommit: 604a4bf49490ad2599c857eb3afd527d67e1e25b
ms.openlocfilehash: 901a6a6bf4097b6aa78a898254766f122bb2f959
ms.lasthandoff: 02/25/2017

---
# <a name="ipersistpropertybagimpl-class"></a>Classe IPersistPropertyBagImpl
Essa classe implementa **IUnknown** e permite que um objeto salvar suas propriedades em um recipiente de propriedades fornecido pelo cliente.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados a [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class T>  
class ATL_NO_VTABLE IPersistPropertyBagImpl : public IPersistPropertyBag
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 Sua classe derivada de `IPersistPropertyBagImpl`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IPersistPropertyBagImpl::GetClassID](#getclassid)|Recupera o CLSID do objeto.|  
|[IPersistPropertyBagImpl::InitNew](#initnew)|Inicializa um objeto recém-criado. Retorna a implementação de ATL `S_OK`.|  
|[IPersistPropertyBagImpl::Load](#load)|Carrega as propriedades do objeto de um recipiente de propriedades fornecido pelo cliente.|  
|[IPersistPropertyBagImpl::Save](#save)|Salva as propriedades do objeto em um recipiente de propriedades fornecido pelo cliente.|  
  
## <a name="remarks"></a>Comentários  
 O [IPersistPropertyBag](https://msdn.microsoft.com/library/aa768205.aspx) interface permite que um objeto salvar suas propriedades em um recipiente de propriedades fornecido pelo cliente. Classe `IPersistPropertyBagImpl` fornece uma implementação padrão dessa interface e implementa **IUnknown** enviando informações para o despejo de compilações de dispositivo no modo de depuração.  
  
 **IPersistPropertyBag** funciona em conjunto com [IPropertyBag](https://msdn.microsoft.com/library/aa768196.aspx) e [IErrorLog](https://msdn.microsoft.com/library/aa768231.aspx). Essas duas interfaces a última opção devem ser implementadas pelo cliente. Por meio de `IPropertyBag`, o cliente salva e carrega as propriedades do objeto individual. Por meio de **IErrorLog**, o objeto e o cliente podem relatar os erros encontrados.  
  
 **Artigos relacionados** [Tutorial da ATL](../../atl/active-template-library-atl-tutorial.md), [criando um projeto do ATL](../../atl/reference/creating-an-atl-project.md)  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `IPersistPropertyBag`  
  
 `IPersistPropertyBagImpl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom.h  
  
##  <a name="a-namegetclassida--ipersistpropertybagimplgetclassid"></a><a name="getclassid"></a>IPersistPropertyBagImpl::GetClassID  
 Recupera o CLSID do objeto.  
  
```
STDMETHOD(GetClassID)(CLSID* pClassID);
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [IPersist::GetClassID](http://msdn.microsoft.com/library/windows/desktop/ms688664) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-nameinitnewa--ipersistpropertybagimplinitnew"></a><a name="initnew"></a>IPersistPropertyBagImpl::InitNew  
 Inicializa um objeto recém-criado.  
  
```
STDMETHOD(InitNew)();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `S_OK`.  
  
### <a name="remarks"></a>Comentários  
 Consulte [IPersistPropertyBag::InitNew](https://msdn.microsoft.com/library/aa768204.aspx) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-nameloada--ipersistpropertybagimplload"></a><a name="load"></a>IPersistPropertyBagImpl::Load  
 Carrega as propriedades do objeto de um recipiente de propriedades fornecido pelo cliente.  
  
```
STDMETHOD(Load)(LPPROPERTYBAG pPropBag, LPERRORLOG pErrorLog);
```  
  
### <a name="remarks"></a>Comentários  
 ATL usa mapa de propriedade do objeto para recuperar essas informações.  
  
 Consulte [IPersistPropertyBag::Load](https://msdn.microsoft.com/library/aa768206.aspx) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namesavea--ipersistpropertybagimplsave"></a><a name="save"></a>IPersistPropertyBagImpl::Save  
 Salva as propriedades do objeto em um recipiente de propriedades fornecido pelo cliente.  
  
```
STDMETHOD(Save)(
    LPPROPERTYBAG pPropBag,
    BOOL fClearDirty,
    BOOL fSaveAllProperties);
```  
  
### <a name="remarks"></a>Comentários  
 ATL usa mapa de propriedade do objeto para armazenar essas informações. Por padrão, esse método salva todas as propriedades, independentemente do valor *fSaveAllProperties*.  
  
 Consulte [IPersistPropertyBag::Save](https://msdn.microsoft.com/library/aa768207.aspx) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## <a name="see-also"></a>Consulte também  
 [BEGIN_PROP_MAP](http://msdn.microsoft.com/library/bfe30be6-62c3-4dc2-bd49-21ef96f15427)   
 [Visão geral da classe](../../atl/atl-class-overview.md)

