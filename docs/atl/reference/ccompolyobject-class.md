---
title: Classe CComPolyObject | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CComPolyObject
- ATLCOM/ATL::CComPolyObject
- ATLCOM/ATL::CComPolyObject::CComPolyObject
- ATLCOM/ATL::CComPolyObject::AddRef
- ATLCOM/ATL::CComPolyObject::CreateInstance
- ATLCOM/ATL::CComPolyObject::FinalConstruct
- ATLCOM/ATL::CComPolyObject::FinalRelease
- ATLCOM/ATL::CComPolyObject::QueryInterface
- ATLCOM/ATL::CComPolyObject::Release
- ATLCOM/ATL::CComPolyObject::m_contained
dev_langs:
- C++
helpviewer_keywords:
- aggregate objects [C++], in ATL
- aggregation [C++], ATL objects
- CComPolyObject class
ms.assetid: eaf67c18-e855-48ca-9b15-f1df3106121b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ec995026b0142fc30470836b29697457be91937e
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43764804"
---
# <a name="ccompolyobject-class"></a>Classe CComPolyObject

Essa classe implementa `IUnknown` para um objeto agregado ou agregado.

## <a name="syntax"></a>Sintaxe

```
template<class contained>  
class CComPolyObject : public IUnknown,
      public CComObjectRootEx<contained::_ThreadModel::ThreadModelNoCS>
```

#### <a name="parameters"></a>Parâmetros

*contido*  
Sua classe, derivada de [CComObjectRoot](../../atl/reference/ccomobjectroot-class.md) ou [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md), como bem como de outras interfaces que você deseja oferecer suporte no objeto.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComPolyObject::CComPolyObject](#ccompolyobject)|O construtor.|
|[CComPolyObject:: ~ CComPolyObject](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComPolyObject::AddRef](#addref)|Incrementa a contagem de referência do objeto.|
|[CComPolyObject::CreateInstance](#createinstance)|(Estático) Permite que você crie uma nova **CComPolyObject <** `contained` **>** objeto sem a sobrecarga de [CoCreateInstance](/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance).|
|[CComPolyObject::FinalConstruct](#finalconstruct)|Executa a inicialização final de `m_contained`.|
|[CComPolyObject::FinalRelease](#finalrelease)|Executa a destruição de final de `m_contained`.|
|[CComPolyObject::QueryInterface](#queryinterface)|Recupera um ponteiro para a interface solicitada.|
|[CComPolyObject::Release](#release)|Diminui contagem de referência do objeto.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComPolyObject::m_contained](#m_contained)|Delegados `IUnknown` chamadas para o externo desconhecido se o objeto for agregado ou para o `IUnknown` do objeto, se o objeto não é agregado.|

## <a name="remarks"></a>Comentários

`CComPolyObject` implementa [IUnknown](/windows/desktop/api/unknwn/nn-unknwn-iunknown) para um objeto agregado ou agregado.

Quando uma instância do `CComPolyObject` é criado, o valor de externo desconhecido é verificado. Se for NULL, `IUnknown` é implementada para um objeto não agregado. Se o externo desconhecido não for nulo, `IUnknown` é implementada para um objeto agregado.

A vantagem de usar `CComPolyObject` é que você evite ter dois [CComAggObject](../../atl/reference/ccomaggobject-class.md) e [CComObject](../../atl/reference/ccomobject-class.md) em seu módulo para tratar de casos agregados e não agregados. Um único `CComPolyObject` objeto lida com ambos os casos. Isso significa que apenas uma cópia de vtable e uma cópia das funções existem em seu módulo. Se seu vtable for grande, isso pode diminuir substancialmente o tamanho do módulo. No entanto, se seu vtable for pequeno, usando `CComPolyObject` pode resultar em um tamanho de módulo ligeiramente maior porque ele não é otimizado para um objeto agregado ou não agregado, que estejam `CComAggObject` e `CComObject`.

Se a macro DECLARE_POLY_AGGREGATABLE for especificada na definição de classe do objeto, `CComPolyObject` será usado para criar o objeto. DECLARE_POLY_AGGREGATABLE será declarada automaticamente se você usar a ATL Project Wizard para criar um controle de Internet Explorer ou controle total.

Se agregado, o `CComPolyObject` objeto tem seu próprio `IUnknown`separada do objeto externo `IUnknown`e mantém seu próprio contagem de referência. `CComPolyObject` usa [CComContainedObject](../../atl/reference/ccomcontainedobject-class.md) para delegar para o externo desconhecido.

Para obter mais informações sobre agregação, consulte o artigo [conceitos básicos de objetos COM de ATL](../../atl/fundamentals-of-atl-com-objects.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CComObjectRootBase`

[CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)

`IUnknown`

`CComPolyObject`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom

##  <a name="addref"></a>  CComPolyObject::AddRef

Incrementa a contagem de referência no objeto.

```
STDMETHOD_(ULONG, AddRef)();
```

### <a name="return-value"></a>Valor de retorno

Um valor que pode ser útil para diagnóstico ou teste.

##  <a name="ccompolyobject"></a>  CComPolyObject::CComPolyObject

O construtor.

```
CComPolyObject(void* pv);
```

### <a name="parameters"></a>Parâmetros

*VP*  
[in] Um ponteiro para o externo desconhecido se o objeto deve ser agregada ou nulo se o objeto se o objeto não é agregado.

### <a name="remarks"></a>Comentários

Inicializa o `CComContainedObject` membro de dados [m_contained](#m_contained)e incrementa a contagem de bloqueios do módulo.

O destruidor decrementa a módulo contagem de bloqueio.

##  <a name="dtor"></a>  CComPolyObject:: ~ CComPolyObject

O destruidor.

```
~CComPolyObject();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados, chamadas [FinalRelease](#finalrelease), e diminui a contagem de bloqueio de módulo.

##  <a name="createinstance"></a>  CComPolyObject::CreateInstance

Permite que você crie uma nova **CComPolyObject <** `contained` **>** objeto sem a sobrecarga de [CoCreateInstance](/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance).

```
static HRESULT WINAPI CreateInstance(  
    LPUNKNOWN pUnkOuter, 
    CComPolyObject<contained>** pp);
```

### <a name="parameters"></a>Parâmetros

*PP*  
[out] Um ponteiro para um **CComPolyObject <** `contained` **>** ponteiro. Se `CreateInstance` não for bem-sucedida, *pp* é definido como NULL.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

O objeto retornado tem uma contagem de referência de zero, portanto, chame `AddRef` imediatamente, em seguida, use `Release` para liberar a referência no ponteiro de objeto quando você terminar.

Se você não precisa de acesso ao objeto direto, mas ainda quiser criar um novo objeto sem a sobrecarga de `CoCreateInstance`, use [CComCoClass::CreateInstance](../../atl/reference/ccomcoclass-class.md#createinstance) em vez disso.

##  <a name="finalconstruct"></a>  CComPolyObject::FinalConstruct

Chamado durante os estágios finais da construção do objeto, este método executa qualquer inicialização final sobre o [m_contained](#m_contained) membro de dados.

```
HRESULT FinalConstruct();
```

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

##  <a name="finalrelease"></a>  CComPolyObject::FinalRelease

Chamado durante a destruição de objeto, esse método libera o [m_contained](#m_contained) membro de dados.

```
void FinalRelease();
```

##  <a name="m_contained"></a>  CComPolyObject::m_contained

Um [CComContainedObject](../../atl/reference/ccomcontainedobject-class.md) objeto derivado da sua classe.

```
CComContainedObject<contained> m_contained;
```

### <a name="parameters"></a>Parâmetros

*contido*  
[in] Sua classe, derivada de [CComObjectRoot](../../atl/reference/ccomobjectroot-class.md) ou [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md), como bem como de outras interfaces que você deseja oferecer suporte no objeto.

### <a name="remarks"></a>Comentários

`IUnknown` chama por meio `m_contained` são delegadas ao externo desconhecido se o objeto for agregado, ou para o `IUnknown` deste objeto se o objeto não é agregado.

##  <a name="queryinterface"></a>  CComPolyObject::QueryInterface

Recupera um ponteiro para a interface solicitada.

```
STDMETHOD(QueryInterface)(REFIID iid, void** ppvObject);
template <class Q>  
HRESULT QueryInterface(Q** pp);
```

### <a name="parameters"></a>Parâmetros

*Q*  
A interface COM.

*IID*  
[in] O identificador da interface que está sendo solicitado.

*ppvObject*  
[out] Um ponteiro para o ponteiro de interface identificado pelo *iid*. Se o objeto não dá suporte a essa interface, *ppvObject* é definido como NULL.

*PP*  
[out] Um ponteiro para a interface identificada pelo `__uuidof(Q)`.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

Para um objeto agregado, se for a interface solicitada `IUnknown`, `QueryInterface` retorna um ponteiro para o objeto agregado próprio `IUnknown` e incrementa a contagem de referência. Caso contrário, este método consulta para a interface por meio de `CComContainedObject` membro de dados [m_contained](#m_contained).

##  <a name="release"></a>  CComPolyObject::Release

Diminui a contagem de referência no objeto.

```
STDMETHOD_(ULONG, Release)();
```

### <a name="return-value"></a>Valor de retorno

Em compilações de depuração, `Release` retorna um valor que pode ser útil para diagnóstico ou teste. Em compilações de nondebug `Release` sempre retorna 0.

## <a name="see-also"></a>Consulte também

[Classe CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)   
[DECLARE_POLY_AGGREGATABLE](aggregation-and-class-factory-macros.md#declare_poly_aggregatable)   
[Visão geral da classe](../../atl/atl-class-overview.md)
