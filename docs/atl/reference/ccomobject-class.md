---
title: Classe CComObject | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CComObject
- ATLCOM/ATL::CComObject
- ATLCOM/ATL::CComObject::CComObject
- ATLCOM/ATL::CComObject::AddRef
- ATLCOM/ATL::CComObject::CreateInstance
- ATLCOM/ATL::CComObject::QueryInterface
- ATLCOM/ATL::CComObject::Release
dev_langs:
- C++
helpviewer_keywords:
- CComObject class
ms.assetid: e2b6433b-6349-4749-b4bc-acbd7a22c8b0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 89a909b715633488cff37fa87ea5950681e208cd
ms.sourcegitcommit: 7d68f8303e021e27dc8f4d36e764ed836e93d24f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/06/2018
ms.locfileid: "37881835"
---
# <a name="ccomobject-class"></a>Classe CComObject
Essa classe implementa `IUnknown` para um objeto não agregado.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class Base>  
class CComObject : public Base
```  
  
#### <a name="parameters"></a>Parâmetros  
 *Base de dados de*  
 Sua classe, derivada de [CComObjectRoot](../../atl/reference/ccomobjectroot-class.md) ou [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md), como bem como de outras interfaces que você deseja oferecer suporte no objeto.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComObject::CComObject](#ccomobject)|O construtor.|  
|[CComObject::~CComObject](#dtor)|O destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComObject::AddRef](#addref)|Incrementa a contagem de referência no objeto.|  
|[CComObject::CreateInstance](#createinstance)|(Estático) Cria um novo `CComObject` objeto.|  
|[CComObject::QueryInterface](#queryinterface)|Recupera um ponteiro para a interface solicitada.|  
|[CComObject::Release](#release)|Diminui a contagem de referência no objeto.|  
  
## <a name="remarks"></a>Comentários  
 `CComObject` implementa [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) para um objeto não agregado. No entanto, chamadas para `QueryInterface`, `AddRef`, e `Release` são delegadas a `CComObjectRootEx`.  
  
 Para obter mais informações sobre como usar `CComObject`, consulte o artigo [conceitos básicos de objetos COM de ATL](../../atl/fundamentals-of-atl-com-objects.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `Base`  
  
 `CComObject`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom  
  
##  <a name="addref"></a>  CComObject::AddRef  
 Incrementa a contagem de referência no objeto.  
  
```
STDMETHOD_(ULONG, AddRef)();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Essa função retorna a nova contagem de referência incrementado no objeto. Esse valor pode ser útil para teste ou de diagnóstico.  
  
##  <a name="ccomobject"></a>  CComObject::CComObject  
 O construtor incrementa a contagem de bloqueios do módulo.  
  
```
CComObject(void* = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 **void\***  
 [in] Esse parâmetro sem nome não é usado. Ele existe para obter simetria com os outros **CCom * * * XXX*`Object`*XXX* construtores.  
  
### <a name="remarks"></a>Comentários  
 O destruidor decrementa-lo.  
  
 Se um `CComObject`-objeto derivado com êxito é construído usando o **nova** operador, a contagem de referência inicial é 0. Para definir a contagem de referência para o valor correto (1), fazer uma chamada para o [AddRef](#addref) função.  
  
##  <a name="dtor"></a>  CComObject:: ~ CComObject  
 O destruidor.  
  
```
CComObject();
```  
  
### <a name="remarks"></a>Comentários  
 Libera todos os recursos alocados, chamadas [FinalRelease](ccomobjectrootex-class.md#finalrelease), e diminui a contagem de bloqueio de módulo.  

  
##  <a name="createinstance"></a>  CComObject::CreateInstance  
 A função estática permite que você crie uma nova **CComObject <** `Base` **>** objeto, sem a sobrecarga de [CoCreateInstance](http://msdn.microsoft.com/library/windows/desktop/ms686615).  
  
```
static HRESULT WINAPI CreateInstance(CComObject<Base>** pp);
```  
  
### <a name="parameters"></a>Parâmetros  
 *PP*  
 [out] Um ponteiro para um **CComObject <** `Base` **>** ponteiro. Se `CreateInstance` não for bem-sucedida, *pp* é definido como NULL.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor padrão de HRESULT.  
  
### <a name="remarks"></a>Comentários  
 O objeto retornado tem uma contagem de referência de zero, portanto, chame `AddRef` imediatamente, em seguida, use `Release` para liberar a referência no ponteiro de objeto quando você terminar.  
  
 Se você não precisa de acesso direto ao objeto, mas ainda quiser criar um novo objeto sem a sobrecarga de `CoCreateInstance`, use [CComCoClass::CreateInstance](../../atl/reference/ccomcoclass-class.md#createinstance) em vez disso.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_COM#38](../../atl/codesnippet/cpp/ccomobject-class_1.h)]  
  
 [!code-cpp[NVC_ATL_COM#39](../../atl/codesnippet/cpp/ccomobject-class_2.cpp)]  
  
##  <a name="queryinterface"></a>  CComObject::QueryInterface  
 Recupera um ponteiro para a interface solicitada.  
  
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
  
##  <a name="release"></a>  CComObject::Release  
 Diminui a contagem de referência no objeto.  
  
```
STDMETHOD_(ULONG, Release)();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Essa função retorna a nova contagem de referência decrementado no objeto. Em compilações de depuração, o valor de retorno pode ser útil para diagnóstico ou teste. Em compilações sem depuração, `Release` sempre retorna 0.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CComAggObject](../../atl/reference/ccomaggobject-class.md)   
 [Classe CComPolyObject](../../atl/reference/ccompolyobject-class.md)   
 [DECLARE_AGGREGATABLE](aggregation-and-class-factory-macros.md#declare_aggregatable)   
 [DECLARE_NOT_AGGREGATABLE](aggregation-and-class-factory-macros.md#declare_not_aggregatable)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
