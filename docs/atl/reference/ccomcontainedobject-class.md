---
title: Classe CComContainedObject | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CComContainedObject
- ATLCOM/ATL::CComContainedObject
- ATLCOM/ATL::CComContainedObject::CComContainedObject
- ATLCOM/ATL::CComContainedObject::AddRef
- ATLCOM/ATL::CComContainedObject::GetControllingUnknown
- ATLCOM/ATL::CComContainedObject::QueryInterface
- ATLCOM/ATL::CComContainedObject::Release
dev_langs:
- C++
helpviewer_keywords:
- aggregate objects [C++], in ATL
- aggregation [C++], ATL objects
- CComContainedObject class
ms.assetid: e8616b41-c200-47b8-bf2c-fb9f713ebdad
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ba67a990b027ff4cd770a0583f6d857a0ee7c725
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43201035"
---
# <a name="ccomcontainedobject-class"></a>Classe CComContainedObject
Essa classe implementa [IUnknown](/windows/desktop/api/unknwn/nn-unknwn-iunknown) delegando para o objeto de proprietário `IUnknown`.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class Base>  
class CComContainedObject : public Base
```  
  
#### <a name="parameters"></a>Parâmetros  
 *Base de dados de*  
 Sua classe, derivada de [CComObjectRoot](../../atl/reference/ccomobjectroot-class.md) ou [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md).  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComContainedObject::CComContainedObject](#ccomcontainedobject)|O construtor. Inicializa o ponteiro de membro para o objeto de proprietário `IUnknown`.|  
|[CComContainedObject:: ~ CComContainedObject](#dtor)|O destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComContainedObject::AddRef](#addref)|Incrementa a contagem de referência no objeto do proprietário.|  
|[CComContainedObject::GetControllingUnknown](#getcontrollingunknown)|Recupera o objeto de proprietário `IUnknown`.|  
|[CComContainedObject::QueryInterface](#queryinterface)|Recupera um ponteiro para a interface solicitada no objeto do proprietário.|  
|[CComContainedObject::Release](#release)|Diminui a contagem de referência no objeto do proprietário.|  
  
## <a name="remarks"></a>Comentários  
 Usa o ATL `CComContainedObject` nas classes [CComAggObject](../../atl/reference/ccomaggobject-class.md), [CComPolyObject](../../atl/reference/ccompolyobject-class.md), e [CComCachedTearOffObject](../../atl/reference/ccomcachedtearoffobject-class.md). `CComContainedObject` implementa [IUnknown](/windows/desktop/api/unknwn/nn-unknwn-iunknown) delegando para o objeto de proprietário `IUnknown`. (O proprietário é o objeto externo de uma agregação ou o objeto para o qual uma interface destacável está sendo criada.) `CComContainedObject` chamadas `CComObjectRootEx`do `OuterQueryInterface`, `OuterAddRef`, e `OuterRelease`, todas as herdadas por meio de `Base`.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `Base`  
  
 `CComContainedObject`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom  
  
##  <a name="addref"></a>  CComContainedObject::AddRef  
 Incrementa a contagem de referência no objeto do proprietário.  
  
```
STDMETHOD_(ULONG, AddRef)();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor que pode ser útil para diagnóstico ou teste.  
  
##  <a name="ccomcontainedobject"></a>  CComContainedObject::CComContainedObject  
 O construtor.  
  
```
CComContainedObject(void* pv);
```  
  
### <a name="parameters"></a>Parâmetros  
 *VP*  
 [in] O objeto de proprietário `IUnknown`.  
  
### <a name="remarks"></a>Comentários  
 Conjuntos a `m_pOuterUnknown` ponteiro de membro (herdadas por meio de `Base` classe) para *pv*.  
  
##  <a name="dtor"></a>  CComContainedObject:: ~ CComContainedObject  
 O destruidor.  
  
```
~CComContainedObject();
```  
  
### <a name="remarks"></a>Comentários  
 Libera todos os recursos alocados.  
  
##  <a name="getcontrollingunknown"></a>  CComContainedObject::GetControllingUnknown  
 Retorna o `m_pOuterUnknown` ponteiro de membro (herdadas por meio de *Base* classe) que contém o objeto de proprietário `IUnknown`.  
  
```
IUnknown* GetControllingUnknown();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O objeto de proprietário `IUnknown`.  
  
### <a name="remarks"></a>Comentários  
 Esse método pode ser virtual se `Base` declarou o [DECLARE_GET_CONTROLLING_UNKNOWN](aggregation-and-class-factory-macros.md#declare_get_controlling_unknown) macro.  
  
##  <a name="queryinterface"></a>  CComContainedObject::QueryInterface  
 Recupera um ponteiro para a interface solicitada no objeto do proprietário.  
  
```
STDMETHOD(QueryInterface)(REFIID iid, void** ppvObject);
template <class Q>
HRESULT STDMETHODCALLTYPE QueryInterface(Q** pp);
```  
  
### <a name="parameters"></a>Parâmetros  
 *IID*  
 [in] O identificador da interface que está sendo solicitado.  
  
 *ppvObject*  
 [out] Um ponteiro para o ponteiro de interface identificado pelo *iid*. Se o objeto não dá suporte a essa interface, *ppvObject* é definido como NULL.  
  
 *PP*  
 [out] Um ponteiro para o ponteiro de interface identificado pelo tipo `Q`. Se o objeto não dá suporte a essa interface, *pp* é definido como NULL.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor padrão de HRESULT.  
  
##  <a name="release"></a>  CComContainedObject::Release  
 Diminui a contagem de referência no objeto do proprietário.  
  
```
STDMETHOD_(ULONG, Release)();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Em compilações de depuração, `Release` retorna um valor que pode ser útil para diagnóstico ou teste. Em compilações sem depuração, `Release` sempre retorna 0.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)
