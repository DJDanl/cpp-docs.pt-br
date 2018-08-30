---
title: Classe IPersistPropertyBagImpl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- IPersistPropertyBagImpl
- ATLCOM/ATL::IPersistPropertyBagImpl
- ATLCOM/ATL::IPersistPropertyBagImpl::GetClassID
- ATLCOM/ATL::IPersistPropertyBagImpl::InitNew
- ATLCOM/ATL::IPersistPropertyBagImpl::Load
- ATLCOM/ATL::IPersistPropertyBagImpl::Save
dev_langs:
- C++
helpviewer_keywords:
- IPersistPropertyBagImpl class
ms.assetid: 712af24d-99f8-40f2-9811-53b3ff6e5b19
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 09b0acfc1fc1f9147a6acbe8bbfe66016dc0b54b
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43201696"
---
# <a name="ipersistpropertybagimpl-class"></a>Classe IPersistPropertyBagImpl
Essa classe implementa `IUnknown` e permite que um objeto salvar suas propriedades em um conjunto de propriedades fornecido pelo cliente.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class T>  
class ATL_NO_VTABLE IPersistPropertyBagImpl : public IPersistPropertyBag
```  
  
#### <a name="parameters"></a>Parâmetros  
 *T*  
 Sua classe, derivada de `IPersistPropertyBagImpl`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IPersistPropertyBagImpl::GetClassID](#getclassid)|Recupera o CLSID do objeto.|  
|[IPersistPropertyBagImpl::InitNew](#initnew)|Inicializa um objeto recém-criado. A implementação de ATL Retorna S_OK.|  
|[IPersistPropertyBagImpl::Load](#load)|Carrega as propriedades do objeto de um conjunto de propriedades fornecido pelo cliente.|  
|[IPersistPropertyBagImpl::Save](#save)|Salva as propriedades do objeto em um recipiente fornecido pelo cliente.|  
  
## <a name="remarks"></a>Comentários  
 O [IPersistPropertyBag](https://msdn.microsoft.com/library/aa768205.aspx) interface permite que um objeto salvar suas propriedades em um conjunto de propriedades fornecido pelo cliente. Classe `IPersistPropertyBagImpl` fornece uma implementação padrão dessa interface e implementa `IUnknown` enviando informações para o despejo de compilações de dispositivo na depuração.  
  
 `IPersistPropertyBag` funciona em conjunto com [IPropertyBag](https://msdn.microsoft.com/library/aa768196.aspx) e [IErrorLog](https://msdn.microsoft.com/library/aa768231.aspx). Essas duas interfaces último devem ser implementadas pelo cliente. Por meio de `IPropertyBag`, o cliente salva e carrega as propriedades do objeto individual. Por meio de `IErrorLog`, o objeto e o cliente podem relatar os erros encontrados.  
  
 **Artigos relacionados** [Tutorial da ATL](../../atl/active-template-library-atl-tutorial.md), [criando um projeto ATL](../../atl/reference/creating-an-atl-project.md)  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `IPersistPropertyBag`  
  
 `IPersistPropertyBagImpl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom  
  
##  <a name="getclassid"></a>  IPersistPropertyBagImpl::GetClassID  
 Recupera o CLSID do objeto.  
  
```
STDMETHOD(GetClassID)(CLSID* pClassID);
```  
  
### <a name="remarks"></a>Comentários  
 Ver [IPersist::GetClassID](/windows/desktop/api/objidl/nf-objidl-ipersist-getclassid) no Windows SDK.  
  
##  <a name="initnew"></a>  IPersistPropertyBagImpl::InitNew  
 Inicializa um objeto recém-criado.  
  
```
STDMETHOD(InitNew)();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK.  
  
### <a name="remarks"></a>Comentários  
 Ver [IPersistPropertyBag::InitNew](https://msdn.microsoft.com/library/aa768204.aspx) no Windows SDK.  
  
##  <a name="load"></a>  IPersistPropertyBagImpl::Load  
 Carrega as propriedades do objeto de um conjunto de propriedades fornecido pelo cliente.  
  
```
STDMETHOD(Load)(LPPROPERTYBAG pPropBag, LPERRORLOG pErrorLog);
```  
  
### <a name="remarks"></a>Comentários  
 ATL usa o mapa de propriedade do objeto para recuperar essas informações.  
  
 Ver [IPersistPropertyBag::Load](https://msdn.microsoft.com/library/aa768206.aspx) no Windows SDK.  
  
##  <a name="save"></a>  IPersistPropertyBagImpl::Save  
 Salva as propriedades do objeto em um recipiente fornecido pelo cliente.  
  
```
STDMETHOD(Save)(
    LPPROPERTYBAG pPropBag,
    BOOL fClearDirty,
    BOOL fSaveAllProperties);
```  
  
### <a name="remarks"></a>Comentários  
 ATL usa o mapa de propriedade do objeto para armazenar essas informações. Por padrão, esse método salva todas as propriedades, independentemente do valor *fSaveAllProperties*.  
  
 Ver [IPersistPropertyBag::Save](https://msdn.microsoft.com/library/aa768207.aspx) no Windows SDK.  
  
## <a name="see-also"></a>Consulte também  
 [BEGIN_PROP_MAP](property-map-macros.md#begin_prop_map)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
