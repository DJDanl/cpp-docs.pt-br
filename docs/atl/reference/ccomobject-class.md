---
title: Classe CComObject | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ATL.CComObject<Base>
- ATL::CComObject
- ATL::CComObject<Base>
- ATL.CComObject
- CComObject
dev_langs:
- C++
helpviewer_keywords:
- CComObject class
ms.assetid: e2b6433b-6349-4749-b4bc-acbd7a22c8b0
caps.latest.revision: 19
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
ms.openlocfilehash: 5f752b96d4a722fbddfcc9e5be3a82b8b12a86a1
ms.lasthandoff: 02/25/2017

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
 Sua classe derivada de [CComObjectRoot](../../atl/reference/ccomobjectroot-class.md) ou [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md), bem como de outras interfaces que você deseja dar suporte no objeto.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
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
  
 Para obter mais informações sobre como usar o `CComObject`, consulte o artigo [conceitos básicos de ATL COM objetos](../../atl/fundamentals-of-atl-com-objects.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `Base`  
  
 `CComObject`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom.h  
  
##  <a name="a-nameaddrefa--ccomobjectaddref"></a><a name="addref"></a>CComObject::AddRef  
 Incrementa a contagem de referência no objeto.  
  
```
STDMETHOD_(ULONG, AddRef)();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Esta função retorna a nova contagem de referência incrementado no objeto. Esse valor pode ser útil para teste ou de diagnóstico.  
  
##  <a name="a-nameccomobjecta--ccomobjectccomobject"></a><a name="ccomobject"></a>CComObject::CComObject  
 O construtor incrementa a contagem de bloqueio do módulo.  
  
```
CComObject(void* = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 **void\***  
 [in] Esse parâmetro sem nome não é usado. Ele existe para obter simetria com outros **CCom***XXX*`Object`*XXX* construtores.  
  
### <a name="remarks"></a>Comentários  
 Decrementa o destruidor-lo.  
  
 Se um `CComObject`-objeto derivado é criada com êxito usando o **novo** operador, a contagem de referência inicial é 0. Para definir a contagem de referência para o valor adequado (1), fazer uma chamada para o [AddRef](#addref) função.  
  
##  <a name="a-namedtora--ccomobjectccomobject"></a><a name="dtor"></a>CComObject:: ~ CComObject  
 O destruidor.  
  
```
CComObject();
```  
  
### <a name="remarks"></a>Comentários  
 Libera todos os recursos alocados, chamadas [FinalRelease](ccomobjectrootex-class.md#finalrelease), e diminui o bloqueio de módulo contar.  

  
##  <a name="a-namecreateinstancea--ccomobjectcreateinstance"></a><a name="createinstance"></a>CComObject::CreateInstance  
 A função estática permite que você crie um novo **CComObject** `Base` ** > ** objeto, sem a sobrecarga de [CoCreateInstance](http://msdn.microsoft.com/library/windows/desktop/ms686615).  
  
```
static HRESULT WINAPI CreateInstance(CComObject<Base>** pp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pp`  
 [out] Um ponteiro para um **CComObject** `Base` ** > ** ponteiro. Se `CreateInstance` não for bem-sucedida, `pp` é definido como **nulo**.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 O objeto retornado tem uma contagem de referência igual a zero, então, chamar `AddRef` imediatamente, em seguida, use **versão** para liberar a referência para o ponteiro de objeto quando terminar.  
  
 Se você não precisa de acesso direto ao objeto, mas ainda deseja criar um novo objeto sem a sobrecarga de `CoCreateInstance`, use [CComCoClass::CreateInstance](../../atl/reference/ccomcoclass-class.md#createinstance) em vez disso.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_COM&38;](../../atl/codesnippet/cpp/ccomobject-class_1.h)]  
  
 [!code-cpp[NVC_ATL_COM&#39;](../../atl/codesnippet/cpp/ccomobject-class_2.cpp)]  
  
##  <a name="a-namequeryinterfacea--ccomobjectqueryinterface"></a><a name="queryinterface"></a>CComObject::QueryInterface  
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
 [out] Um ponteiro para o ponteiro de interface identificado pelo `iid`. Se o objeto não oferece suporte a essa interface, `ppvObject` é definido como **nulo**.  
  
 `pp`  
 [out] Um ponteiro para o ponteiro de interface identificado pelo tipo `Q`. Se o objeto não oferece suporte a essa interface, `pp` é definido como **nulo**.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
##  <a name="a-namereleasea--ccomobjectrelease"></a><a name="release"></a>CComObject::Release  
 Diminui a contagem de referência no objeto.  
  
```
STDMETHOD_(ULONG, Release)();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Esta função retorna a nova contagem de referência diminuído no objeto. Em compilações de depuração, o valor de retorno pode ser útil para o diagnóstico e teste. Em compilações de depuração não **versão** sempre retorna 0.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CComAggObject](../../atl/reference/ccomaggobject-class.md)   
 [Classe CComPolyObject](../../atl/reference/ccompolyobject-class.md)   
 [DECLARE_AGGREGATABLE](http://msdn.microsoft.com/library/e7e568d7-04e0-4226-b5dc-224deed229ab)   
 [DECLARE_NOT_AGGREGATABLE](http://msdn.microsoft.com/library/2a116c7c-bab8-4f2a-a9ad-03d7aba0f762)   
 [Visão geral da classe](../../atl/atl-class-overview.md)

