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
ms.openlocfilehash: 41d26b84fd4c113120afefd572caed8ab27214c8
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32363425"
---
# <a name="ipersistpropertybagimpl-class"></a>Classe IPersistPropertyBagImpl
Essa classe implementa **IUnknown** e permite que um objeto salvar suas propriedades em um recipiente de propriedades fornecido pelo cliente.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class T>  
class ATL_NO_VTABLE IPersistPropertyBagImpl : public IPersistPropertyBag
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 A classe derivada de `IPersistPropertyBagImpl`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IPersistPropertyBagImpl::GetClassID](#getclassid)|Recupera o CLSID do objeto.|  
|[IPersistPropertyBagImpl::InitNew](#initnew)|Inicializa um objeto recém-criado. Retorna a implementação de ATL `S_OK`.|  
|[IPersistPropertyBagImpl::Load](#load)|Carrega as propriedades do objeto de um recipiente de propriedades fornecido pelo cliente.|  
|[IPersistPropertyBagImpl::Save](#save)|Salva as propriedades do objeto em um recipiente de propriedades fornecido pelo cliente.|  
  
## <a name="remarks"></a>Comentários  
 O [IPersistPropertyBag](https://msdn.microsoft.com/library/aa768205.aspx) interface permite que um objeto salvar suas propriedades em um recipiente de propriedades fornecido pelo cliente. Classe `IPersistPropertyBagImpl` fornece uma implementação padrão dessa interface e implementa **IUnknown** enviando informações para o despejo compilações dispositivo na depuração.  
  
 **IPersistPropertyBag** funciona em conjunto com [IPropertyBag](https://msdn.microsoft.com/library/aa768196.aspx) e [IErrorLog](https://msdn.microsoft.com/library/aa768231.aspx). Essas duas interfaces último devem ser implementados pelo cliente. Por meio de `IPropertyBag`, o cliente salva e carrega as propriedades do objeto individual. Por meio de **IErrorLog**, o objeto e o cliente podem relatar os erros encontrados.  
  
 **Artigos relacionados** [Tutorial da ATL](../../atl/active-template-library-atl-tutorial.md), [criando um projeto ATL](../../atl/reference/creating-an-atl-project.md)  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `IPersistPropertyBag`  
  
 `IPersistPropertyBagImpl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom.h  
  
##  <a name="getclassid"></a>  IPersistPropertyBagImpl::GetClassID  
 Recupera o CLSID do objeto.  
  
```
STDMETHOD(GetClassID)(CLSID* pClassID);
```  
  
### <a name="remarks"></a>Comentários  
 Consulte [ipersist:: GetClassID](http://msdn.microsoft.com/library/windows/desktop/ms688664) no SDK do Windows.  
  
##  <a name="initnew"></a>  IPersistPropertyBagImpl::InitNew  
 Inicializa um objeto recém-criado.  
  
```
STDMETHOD(InitNew)();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `S_OK`.  
  
### <a name="remarks"></a>Comentários  
 Consulte [IPersistPropertyBag::InitNew](https://msdn.microsoft.com/library/aa768204.aspx) no SDK do Windows.  
  
##  <a name="load"></a>  IPersistPropertyBagImpl::Load  
 Carrega as propriedades do objeto de um recipiente de propriedades fornecido pelo cliente.  
  
```
STDMETHOD(Load)(LPPROPERTYBAG pPropBag, LPERRORLOG pErrorLog);
```  
  
### <a name="remarks"></a>Comentários  
 ATL usa mapa de propriedade do objeto para recuperar essas informações.  
  
 Consulte [IPersistPropertyBag::Load](https://msdn.microsoft.com/library/aa768206.aspx) no SDK do Windows.  
  
##  <a name="save"></a>  IPersistPropertyBagImpl::Save  
 Salva as propriedades do objeto em um recipiente de propriedades fornecido pelo cliente.  
  
```
STDMETHOD(Save)(
    LPPROPERTYBAG pPropBag,
    BOOL fClearDirty,
    BOOL fSaveAllProperties);
```  
  
### <a name="remarks"></a>Comentários  
 ATL usa mapa de propriedade do objeto para armazenar essas informações. Por padrão, esse método salva todas as propriedades, independentemente do valor *fSaveAllProperties*.  
  
 Consulte [IPersistPropertyBag::Save](https://msdn.microsoft.com/library/aa768207.aspx) no SDK do Windows.  
  
## <a name="see-also"></a>Consulte também  
 [BEGIN_PROP_MAP](property-map-macros.md#begin_prop_map)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
