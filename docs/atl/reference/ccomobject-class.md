---
title: Classe CComObject | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
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
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 27da00e09ca88cc06b8bafed8f8601dac756fd34
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ccomobject-class"></a>Classe CComObject
Essa classe implementa **IUnknown** para um objeto agregado.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class Base>  
class CComObject : public Base
```  
  
#### <a name="parameters"></a>Parâmetros  
 `Base`  
 A classe derivada de [CComObjectRoot](../../atl/reference/ccomobjectroot-class.md) ou [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md), bem como qualquer outra interface desejar dar suporte ao objeto.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComObject::CComObject](#ccomobject)|O construtor.|  
|[CComObject:: ~ CComObject](#dtor)|O destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComObject::AddRef](#addref)|Incrementa a contagem de referência no objeto.|  
|[CComObject::CreateInstance](#createinstance)|(Estático) Cria um novo `CComObject` objeto.|  
|[CComObject::QueryInterface](#queryinterface)|Recupera um ponteiro para a interface solicitada.|  
|[CComObject::Release](#release)|Diminui a contagem de referência no objeto.|  
  
## <a name="remarks"></a>Comentários  
 `CComObject`implementa [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) para um objeto agregado. No entanto, chamadas para `QueryInterface`, `AddRef`, e **versão** são delegadas a `CComObjectRootEx`.  
  
 Para obter mais informações sobre como usar `CComObject`, consulte o artigo [Fundamentals de ATL COM objetos](../../atl/fundamentals-of-atl-com-objects.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `Base`  
  
 `CComObject`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom.h  
  
##  <a name="addref"></a>CComObject::AddRef  
 Incrementa a contagem de referência no objeto.  
  
```
STDMETHOD_(ULONG, AddRef)();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Esta função retorna a nova contagem de referência incrementado no objeto. Esse valor pode ser útil para teste ou de diagnóstico.  
  
##  <a name="ccomobject"></a>CComObject::CComObject  
 O construtor incrementa a contagem de bloqueios do módulo.  
  
```
CComObject(void* = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 **void\***  
 [in] Esse parâmetro sem nome não é usado. Ela existe para simetria com outros **CCom***XXX*`Object`*XXX* construtores.  
  
### <a name="remarks"></a>Comentários  
 Decrementa o destruidor-lo.  
  
 Se um `CComObject`-objeto derivado é criada com êxito usando o **novo** operador, a contagem de referência inicial é 0. Para definir a contagem de referência para o valor adequado (1), fazer uma chamada para o [AddRef](#addref) função.  
  
##  <a name="dtor"></a>CComObject:: ~ CComObject  
 O destruidor.  
  
```
CComObject();
```  
  
### <a name="remarks"></a>Comentários  
 Libera todos os recursos alocados, chamadas [FinalRelease](ccomobjectrootex-class.md#finalrelease), e diminui a módulo contagem de bloqueio.  

  
##  <a name="createinstance"></a>CComObject::CreateInstance  
 Função estática permite que você crie um novo **CComObject <** `Base`  **>**  objeto, sem a sobrecarga de [CoCreateInstance](http://msdn.microsoft.com/library/windows/desktop/ms686615).  
  
```
static HRESULT WINAPI CreateInstance(CComObject<Base>** pp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pp`  
 [out] Um ponteiro para um **CComObject <** `Base`  **>**  ponteiro. Se `CreateInstance` for bem-sucedido, `pp` é definido como **nulo**.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 O objeto retornado tem uma contagem de referência igual a zero, portanto, chame `AddRef` imediatamente, em seguida, use **versão** para liberar a referência no ponteiro de objeto quando estiver pronto.  
  
 Se você não precisa de acesso direto ao objeto, mas ainda deseja criar um novo objeto sem a sobrecarga de `CoCreateInstance`, use [CComCoClass::CreateInstance](../../atl/reference/ccomcoclass-class.md#createinstance) em vez disso.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_COM#38](../../atl/codesnippet/cpp/ccomobject-class_1.h)]  
  
 [!code-cpp[NVC_ATL_COM#39](../../atl/codesnippet/cpp/ccomobject-class_2.cpp)]  
  
##  <a name="queryinterface"></a>CComObject::QueryInterface  
 Recupera um ponteiro para a interface solicitada.  
  
```
STDMETHOD(QueryInterface)(REFIID iid, void** ppvObject);
template <class Q>  
HRESULT STDMETHODCALLTYPE QueryInterface(Q** pp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `iid`  
 [in] O identificador da interface que está sendo solicitado.  
  
 `ppvObject`  
 [out] Um ponteiro para o ponteiro de interface identificado por `iid`. Se o objeto não oferece suporte a essa interface, `ppvObject` é definido como **nulo**.  
  
 `pp`  
 [out] Um ponteiro para o ponteiro de interface identificado pelo tipo `Q`. Se o objeto não oferece suporte a essa interface, `pp` é definido como **nulo**.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
##  <a name="release"></a>CComObject::Release  
 Diminui a contagem de referência no objeto.  
  
```
STDMETHOD_(ULONG, Release)();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Esta função retorna a nova contagem de referência do diminuída no objeto. Em compilações de depuração, o valor de retorno pode ser útil para um diagnóstico ou teste. Em compilações de depuração não **versão** sempre retorna 0.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CComAggObject](../../atl/reference/ccomaggobject-class.md)   
 [Classe CComPolyObject](../../atl/reference/ccompolyobject-class.md)   
 [DECLARE_AGGREGATABLE](aggregation-and-class-factory-macros.md#declare_aggregatable)   
 [DECLARE_NOT_AGGREGATABLE](aggregation-and-class-factory-macros.md#declare_not_aggregatable)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
