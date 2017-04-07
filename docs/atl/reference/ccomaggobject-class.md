---
title: Classe CComAggObject | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CComAggObject
- ATLCOM/ATL::CComAggObject
- ATLCOM/ATL::CComAggObject::CComAggObject
- ATLCOM/ATL::CComAggObject::AddRef
- ATLCOM/ATL::CComAggObject::CreateInstance
- ATLCOM/ATL::CComAggObject::FinalConstruct
- ATLCOM/ATL::CComAggObject::FinalRelease
- ATLCOM/ATL::CComAggObject::QueryInterface
- ATLCOM/ATL::CComAggObject::Release
- ATLCOM/ATL::CComAggObject::m_contained
dev_langs:
- C++
helpviewer_keywords:
- aggregate objects [C++], in ATL
- aggregation [C++], ATL objects
- CComAggObject class
ms.assetid: 7aa90d69-d399-477b-880d-e2cdf0ef7881
caps.latest.revision: 29
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
ms.openlocfilehash: 386ab09418c879c0de0d82d729a3de1b2e270016
ms.lasthandoff: 02/25/2017

---
# <a name="ccomaggobject-class"></a>Classe CComAggObject
Essa classe implementa o [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) interface para um objeto agregado. Por definição, um objeto agregado está contido dentro de um objeto externo. O `CComAggObject` classe é semelhante do [CComObject classe](../../atl/reference/ccomobject-class.md), exceto que ele expõe uma interface que é diretamente acessível para clientes externos.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class contained>  
class CComAggObject : public IUnknown, 
   public CComObjectRootEx<contained::_ThreadModel::ThreadModelNoCS>
```  
  
#### <a name="parameters"></a>Parâmetros  
 `contained`  
 Sua classe derivada de [CComObjectRoot](../../atl/reference/ccomobjectroot-class.md) ou [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md), bem como de outras interfaces que você deseja dar suporte no objeto.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComAggObject::CComAggObject](#ccomaggobject)|O construtor.|  
|[CComAggObject:: ~ CComAggObject](#dtor)|O destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComAggObject::AddRef](#addref)|Incrementa a contagem de referência no objeto agregado.|  
|[CComAggObject::CreateInstance](#createinstance)|A função estática permite que você crie um novo **CComAggObject** `contained` ** > ** objeto sem a sobrecarga de [CoCreateInstance](http://msdn.microsoft.com/library/windows/desktop/ms686615).|  
|[CComAggObject::FinalConstruct](#finalconstruct)|Executa a inicialização final de `m_contained`.|  
|[CComAggObject::FinalRelease](#finalrelease)|Executa a destruição de final de `m_contained`.|  
|[CComAggObject::QueryInterface](#queryinterface)|Recupera um ponteiro para a interface solicitada.|  
|[CComAggObject::Release](#release)|Diminui a contagem de referência no objeto agregado.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComAggObject::m_contained](#m_contained)|Delegados `IUnknown` chamadas para o externo desconhecido.|  
  
## <a name="remarks"></a>Comentários  
 `CComAggObject`implementa [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) para um objeto agregado. `CComAggObject`tem seu próprio **IUnknown** interface, separado do objeto externo **IUnknown** interface e mantém seu próprio contagem de referência.  
  
 Para obter mais informações sobre a agregação, consulte o artigo [conceitos básicos de ATL COM objetos](../../atl/fundamentals-of-atl-com-objects.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `CComObjectRootBase`  
  
 [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)  
  
 `IUnknown`  
  
 `CComAggObject`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom.h  
  
##  <a name="addref"></a>CComAggObject::AddRef  
 Incrementa a contagem de referência no objeto agregado.  
  
```
STDMETHOD_(ULONG, AddRef)();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor que pode ser útil para o diagnóstico ou teste.  
  
##  <a name="ccomaggobject"></a>CComAggObject::CComAggObject  
 O construtor.  
  
```
CComAggObject(void* pv);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pv`  
 [in] O externo desconhecido.  
  
### <a name="remarks"></a>Comentários  
 Inicializa o `CComContainedObject` membro, [m_contained](#m_contained)e incrementa a contagem de bloqueio do módulo.  
  
 Contagem de bloqueio do módulo diminui o destruidor.  
  
##  <a name="dtor"></a>CComAggObject:: ~ CComAggObject  
 O destruidor.  
  
```
~CComAggObject();
```  
  
### <a name="remarks"></a>Comentários  
 Libera todos os recursos alocados, chamadas [FinalRelease](#finalrelease), e diminui o bloqueio de módulo contar.  
  
##  <a name="createinstance"></a>CComAggObject::CreateInstance  
 A função estática permite que você crie um novo **CComAggObject** `contained` ** > ** objeto sem a sobrecarga de [CoCreateInstance](http://msdn.microsoft.com/library/windows/desktop/ms686615).  
  
```
static HRESULT WINAPI CreateInstance(
    LPUNKNOWN pUnkOuter,
    CComAggObject<contained>** pp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pp`  
 [out] Um ponteiro para um **CComAggObject\<***contido* ** > ** ponteiro. Se `CreateInstance` não for bem-sucedida, `pp` é definido como **nulo**.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 O objeto retornado tem uma contagem de referência igual a zero, então, chamar `AddRef` imediatamente, em seguida, use **versão** para liberar a referência para o ponteiro de objeto quando terminar.  
  
 Se você não precisa de acesso direto ao objeto, mas ainda deseja criar um novo objeto sem a sobrecarga de `CoCreateInstance`, use [CComCoClass::CreateInstance](../../atl/reference/ccomcoclass-class.md#createinstance) em vez disso.  
  
##  <a name="finalconstruct"></a>CComAggObject::FinalConstruct  
 Chamado durante os estágios finais da construção do objeto, este método executa qualquer inicialização final sobre o [m_contained](#m_contained) membro.  
  
```
HRESULT FinalConstruct();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
##  <a name="finalrelease"></a>CComAggObject::FinalRelease  
 Chamado durante a destruição de objeto, esse método libera o [m_contained](#m_contained) membro.  
  
```
void FinalRelease();
```  
  
##  <a name="m_contained"></a>CComAggObject::m_contained  
 A [CComContainedObject](../../atl/reference/ccomcontainedobject-class.md) objeto derivado da classe.  
  
```
CComContainedObject<contained> m_contained;
```  
  
### <a name="parameters"></a>Parâmetros  
 `contained`  
 [in] Sua classe derivada de [CComObjectRoot](../../atl/reference/ccomobjectroot-class.md) ou [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md), bem como de outras interfaces que você deseja dar suporte no objeto.  
  
### <a name="remarks"></a>Comentários  
 Todos os **IUnknown** chamada por meio de `m_contained` são delegadas externo desconhecido.  
  
##  <a name="queryinterface"></a>CComAggObject::QueryInterface  
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
  
### <a name="remarks"></a>Comentários  
 Se a interface solicitada é **IUnknown**, `QueryInterface` retorna um ponteiro para agregados do objeto próprio **IUnknown** e incrementa a contagem de referência. Caso contrário, esse método de consulta para a interface por meio de `CComContainedObject` membro, [m_contained](#m_contained).  
  
##  <a name="release"></a>CComAggObject::Release  
 Diminui a contagem de referência no objeto agregado.  
  
```
STDMETHOD_(ULONG, Release)();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Em compilações de depuração, **versão** retorna um valor que pode ser útil para o diagnóstico ou teste. Em compilações de depuração não **versão** sempre retorna 0.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CComObject](../../atl/reference/ccomobject-class.md)   
 [Classe CComPolyObject](../../atl/reference/ccompolyobject-class.md)   
 [DECLARE_AGGREGATABLE](http://msdn.microsoft.com/library/e7e568d7-04e0-4226-b5dc-224deed229ab)   
 [DECLARE_ONLY_AGGREGATABLE](http://msdn.microsoft.com/library/a54220df-4330-4e4d-b7fb-8b63dd62d337)   
 [DECLARE_NOT_AGGREGATABLE](http://msdn.microsoft.com/library/2a116c7c-bab8-4f2a-a9ad-03d7aba0f762)   
 [Visão geral da classe](../../atl/atl-class-overview.md)

