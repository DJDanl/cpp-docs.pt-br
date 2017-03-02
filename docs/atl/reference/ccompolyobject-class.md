---
title: Classe CComPolyObject | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CComPolyObject
- ATL.CComPolyObject<contained>
- ATL::CComPolyObject
- ATL::CComPolyObject<contained>
- ATL.CComPolyObject
dev_langs:
- C++
helpviewer_keywords:
- aggregate objects [C++], in ATL
- aggregation [C++], ATL objects
- CComPolyObject class
ms.assetid: eaf67c18-e855-48ca-9b15-f1df3106121b
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
ms.openlocfilehash: 37be4c985983cb760246a4a2450c27d175d1f440
ms.lasthandoff: 02/25/2017

---
# <a name="ccompolyobject-class"></a>Classe CComPolyObject
Essa classe implementa **IUnknown** para um objeto agregado ou agregado.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class contained>  
class CComPolyObject : public IUnknown,
      public CComObjectRootEx<contained::_ThreadModel::ThreadModelNoCS>
```  
  
#### <a name="parameters"></a>Parâmetros  
 `contained`  
 Sua classe derivada de [CComObjectRoot](../../atl/reference/ccomobjectroot-class.md) ou [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md), bem como de outras interfaces que você deseja dar suporte no objeto.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComPolyObject::CComPolyObject](#ccompolyobject)|O construtor.|  
|[CComPolyObject:: ~ CComPolyObject](#dtor)|O destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComPolyObject::AddRef](#addref)|Incrementa a contagem de referência do objeto.|  
|[CComPolyObject::CreateInstance](#createinstance)|(Estático) Permite que você crie um novo **CComPolyObject** `contained` ** > ** objeto sem a sobrecarga de [CoCreateInstance](http://msdn.microsoft.com/library/windows/desktop/ms686615).|  
|[CComPolyObject::FinalConstruct](#finalconstruct)|Executa a inicialização final de `m_contained`.|  
|[CComPolyObject::FinalRelease](#finalrelease)|Executa a destruição de final de `m_contained`.|  
|[CComPolyObject::QueryInterface](#queryinterface)|Recupera um ponteiro para a interface solicitada.|  
|[CComPolyObject::Release](#release)|Contagem de referência do objeto diminui.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComPolyObject::m_contained](#m_contained)|Delegados **IUnknown** chama o externo desconhecido se o objeto é agregado ou para o **IUnknown** do objeto se o objeto não é agregado.|  
  
## <a name="remarks"></a>Comentários  
 `CComPolyObject`implementa [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) para um objeto agregado ou agregado.  
  
 Quando uma instância de `CComPolyObject` é criado, o valor de externo desconhecido é verificado. Se for **nulo**, **IUnknown** é implementada por um objeto agregado. Se o externo desconhecido não é **nulo**, **IUnknown** é implementada por um objeto agregado.  
  
 A vantagem de usar `CComPolyObject` é evitar ter que ambos [CComAggObject](../../atl/reference/ccomaggobject-class.md) e [CComObject](../../atl/reference/ccomobject-class.md) no módulo para tratar de casos agregados e agregados. Um único `CComPolyObject` ambos os casos alças do objeto. Isso significa que somente uma cópia do vtable e uma cópia das funções existem em seu módulo. Se seu vtable for grande, isso poderá diminuir substancialmente o tamanho do módulo. No entanto, se seu vtable for pequeno, usando `CComPolyObject` pode resultar em um tamanho ligeiramente maior do módulo porque ele não é otimizado para um objeto agregado ou agregado, como são `CComAggObject` e `CComObject`.  
  
 Se o `DECLARE_POLY_AGGREGATABLE` macro é especificada na definição de classe do objeto, `CComPolyObject` será usado para criar o objeto. `DECLARE_POLY_AGGREGATABLE`serão automaticamente declarados se você usar a ATL Project Wizard para criar um controle de Internet Explorer ou controle total.  
  
 Se agregados, o `CComPolyObject` objeto tem seu próprio **IUnknown**separado do objeto externo **IUnknown**e mantém seu próprio contagem de referência. `CComPolyObject`usa [CComContainedObject](../../atl/reference/ccomcontainedobject-class.md) delegar o externo desconhecido.  
  
 Para obter mais informações sobre a agregação, consulte o artigo [conceitos básicos de ATL COM objetos](../../atl/fundamentals-of-atl-com-objects.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `CComObjectRootBase`  
  
 [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)  
  
 `IUnknown`  
  
 `CComPolyObject`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom.h  
  
##  <a name="a-nameaddrefa--ccompolyobjectaddref"></a><a name="addref"></a>CComPolyObject::AddRef  
 Incrementa a contagem de referência no objeto.  
  
```
STDMETHOD_(ULONG, AddRef)();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor que pode ser útil para o diagnóstico ou teste.  
  
##  <a name="a-nameccompolyobjecta--ccompolyobjectccompolyobject"></a><a name="ccompolyobject"></a>CComPolyObject::CComPolyObject  
 O construtor.  
  
```
CComPolyObject(void* pv);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pv`  
 [in] Um ponteiro para o externo desconhecido se o objeto é agregada, ou **nulo** se o objeto se o objeto não é agregado.  
  
### <a name="remarks"></a>Comentários  
 Inicializa o `CComContainedObject` membro de dados, [m_contained](#m_contained)e incrementa a contagem de bloqueio do módulo.  
  
 Contagem de bloqueio do módulo diminui o destruidor.  
  
##  <a name="a-namedtora--ccompolyobjectccompolyobject"></a><a name="dtor"></a>CComPolyObject:: ~ CComPolyObject  
 O destruidor.  
  
```
~CComPolyObject();
```  
  
### <a name="remarks"></a>Comentários  
 Libera todos os recursos alocados, chamadas [FinalRelease](#finalrelease), e diminui o bloqueio de módulo contar.  
  
##  <a name="a-namecreateinstancea--ccompolyobjectcreateinstance"></a><a name="createinstance"></a>CComPolyObject::CreateInstance  
 Permite que você crie um novo **CComPolyObject** `contained` ** > ** objeto sem a sobrecarga de [CoCreateInstance](http://msdn.microsoft.com/library/windows/desktop/ms686615).  
  
```
static HRESULT WINAPI CreateInstance(  
    LPUNKNOWN pUnkOuter, 
    CComPolyObject<contained>** pp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pp`  
 [out] Um ponteiro para um **CComPolyObject** `contained` ** > ** ponteiro. Se `CreateInstance` não for bem-sucedida, `pp` é definido como **nulo**.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 O objeto retornado tem uma contagem de referência igual a zero, então, chamar `AddRef` imediatamente, em seguida, use **versão** para liberar a referência para o ponteiro de objeto quando terminar.  
  
 Se você não precisa de acesso ao objeto direto, mas ainda deseja criar um novo objeto sem a sobrecarga de `CoCreateInstance`, use [CComCoClass::CreateInstance](../../atl/reference/ccomcoclass-class.md#createinstance) em vez disso.  
  
##  <a name="a-namefinalconstructa--ccompolyobjectfinalconstruct"></a><a name="finalconstruct"></a>CComPolyObject::FinalConstruct  
 Chamado durante os estágios finais da construção do objeto, este método executa qualquer inicialização final sobre o [m_contained](#m_contained) membro de dados.  
  
```
HRESULT FinalConstruct();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
##  <a name="a-namefinalreleasea--ccompolyobjectfinalrelease"></a><a name="finalrelease"></a>CComPolyObject::FinalRelease  
 Chamado durante a destruição de objeto, esse método libera o [m_contained](#m_contained) membro de dados.  
  
```
void FinalRelease();
```  
  
##  <a name="a-namemcontaineda--ccompolyobjectmcontained"></a><a name="m_contained"></a>CComPolyObject::m_contained  
 A [CComContainedObject](../../atl/reference/ccomcontainedobject-class.md) objeto derivado da classe.  
  
```
CComContainedObject<contained> m_contained;
```  
  
### <a name="parameters"></a>Parâmetros  
 `contained`  
 [in] Sua classe derivada de [CComObjectRoot](../../atl/reference/ccomobjectroot-class.md) ou [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md), bem como de outras interfaces que você deseja dar suporte no objeto.  
  
### <a name="remarks"></a>Comentários  
 **IUnknown** chamada por meio de `m_contained` são delegadas externo desconhecido se o objeto é agregado ou para o **IUnknown** deste objeto se o objeto não é agregado.  
  
##  <a name="a-namequeryinterfacea--ccompolyobjectqueryinterface"></a><a name="queryinterface"></a>CComPolyObject::QueryInterface  
 Recupera um ponteiro para a interface solicitada.  
  
```
STDMETHOD(QueryInterface)(REFIID iid, void** ppvObject);
template <class Q>  
HRESULT QueryInterface(Q** pp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `Q`  
 A interface COM.  
  
 `iid`  
 [in] O identificador da interface que está sendo solicitado.  
  
 `ppvObject`  
 [out] Um ponteiro para o ponteiro de interface identificado pelo `iid`. Se o objeto não oferece suporte a essa interface, `ppvObject` é definido como **nulo**.  
  
 `pp`  
 [out] Um ponteiro para a interface identificada pelo **__uuidof(Q)**.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 Para um objeto agregado, se a interface solicitada é **IUnknown**, `QueryInterface` retorna um ponteiro para agregados do objeto próprio **IUnknown** e incrementa a contagem de referência. Caso contrário, esse método de consulta para a interface por meio de `CComContainedObject` membro de dados, [m_contained](#m_contained).  
  
##  <a name="a-namereleasea--ccompolyobjectrelease"></a><a name="release"></a>CComPolyObject::Release  
 Diminui a contagem de referência no objeto.  
  
```
STDMETHOD_(ULONG, Release)();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Em compilações de depuração, **versão** retorna um valor que pode ser útil para o diagnóstico ou teste. Em compilações de nondebug **versão** sempre retorna 0.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)   
 [DECLARE_POLY_AGGREGATABLE](http://msdn.microsoft.com/library/7569e738-cfbc-4404-ba1d-78dcefa3bdb3)   
 [Visão geral da classe](../../atl/atl-class-overview.md)

