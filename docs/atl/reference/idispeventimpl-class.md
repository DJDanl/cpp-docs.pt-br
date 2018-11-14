---
title: Classe IDispEventImpl
ms.date: 11/04/2016
f1_keywords:
- IDispEventImpl
- ATLCOM/ATL::IDispEventImpl
- ATLCOM/ATL::IDispEventImpl::IDispEventImpl
- ATLCOM/ATL::IDispEventImpl::GetFuncInfoFromId
- ATLCOM/ATL::IDispEventImpl::GetIDsOfNames
- ATLCOM/ATL::IDispEventImpl::GetTypeInfo
- ATLCOM/ATL::IDispEventImpl::GetTypeInfoCount
- ATLCOM/ATL::IDispEventImpl::GetUserDefinedType
helpviewer_keywords:
- IDispEventImpl class
ms.assetid: a64b5288-35cb-4638-aad6-2d15b1c7cf7b
ms.openlocfilehash: 75946005acc22874b17ee806cd89ec99095f9c35
ms.sourcegitcommit: afd6fac7c519dbc47a4befaece14a919d4e0a8a2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/10/2018
ms.locfileid: "51524294"
---
# <a name="idispeventimpl-class"></a>Classe IDispEventImpl

Essa classe fornece implementações do `IDispatch` métodos.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template <UINT nID, class T,
    const IID* pdiid = &IID_NULL,
    const GUID* plibid = &GUID_NULL,
    WORD wMajor = 0,
    WORD wMinor = 0,
    class tihclass = CcomTypeInfoHolder>
class ATL_NO_VTABLE IDispEventImpl : public IDispEventSimpleImpl<nID, T, pdiid>
```

#### <a name="parameters"></a>Parâmetros

*nID*<br/>
Um identificador exclusivo para o objeto de origem. Quando `IDispEventImpl` é a classe base para um controle de composição, use a ID de recurso do controle independente desejado para esse parâmetro. Em outros casos, use um inteiro positivo arbitrário.

*T*<br/>
A classe do usuário, que é derivada de `IDispEventImpl`.

*pdiid*<br/>
O ponteiro para o IID da dispinterface de eventos implementada por esta classe. Essa interface deve ser definida na biblioteca de tipos, indicada por *plibid*, *wMajor*, e *wMinor*.

*plibid*<br/>
Um ponteiro para a biblioteca de tipos que define a interface de expedição apontada por *pdiid*. Se **& GUID_NULL**, a biblioteca de tipos será carregada a partir do objeto de fornecimento de eventos.

*wMajor*<br/>
A versão principal da biblioteca de tipos. O valor padrão é 0.

*wMinor*<br/>
A versão secundária da biblioteca de tipos. O valor padrão é 0.

*tihclass*<br/>
A classe usada para gerenciar as informações de tipo de *T*. O valor padrão é uma classe do tipo `CComTypeInfoHolder`; no entanto, você pode substituir esse parâmetro de modelo, fornecendo uma classe de um tipo diferente de `CComTypeInfoHolder`.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|[IDispEventImpl::_tihclass](../../atl/reference/idispeventimpl-class.md)|A classe usada para gerenciar as informações de tipo. Por padrão, `CComTypeInfoHolder`.|

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[IDispEventImpl::IDispEventImpl](#idispeventimpl)|O construtor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[IDispEventImpl::GetFuncInfoFromId](#getfuncinfofromid)|Localiza o índice de função para o identificador de expedição especificado.|
|[IDispEventImpl::GetIDsOfNames](#getidsofnames)|Mapeia um único membro e um conjunto opcional de nomes de argumento para um conjunto correspondente de DISPIDs de inteiro.|
|[IDispEventImpl::GetTypeInfo](#gettypeinfo)|Recupera as informações de tipo para um objeto.|
|[IDispEventImpl::GetTypeInfoCount](#gettypeinfocount)|Recupera o número de interfaces de informações de tipo.|
|[IDispEventImpl::GetUserDefinedType](#getuserdefinedtype)|Recupera o tipo básico de um tipo definido pelo usuário.|

## <a name="remarks"></a>Comentários

`IDispEventImpl` Fornece uma maneira de implementar um dispinterface de eventos sem exigir que você forneça o código de implementação para cada método/evento nessa interface. `IDispEventImpl` fornece implementações do `IDispatch` métodos. Você só precisa fornecer implementações para os eventos que você está interessado na manipulação de.

`IDispEventImpl` funciona em conjunto com o mapa de coletor de eventos em sua classe para eventos de rota para a função de manipulador apropriado. Para usar essa classe:

Adicionar um [SINK_ENTRY](composite-control-macros.md#sink_entry) ou [SINK_ENTRY_EX](composite-control-macros.md#sink_entry_ex) macro para o mapa do coletor de evento para cada evento em cada objeto que você deseja manipular. Ao usar `IDispEventImpl` como uma classe base de um controle composto, você pode chamar [AtlAdviseSinkMap](connection-point-global-functions.md#atladvisesinkmap) para estabelecer e interromper a conexão com as fontes de evento para todas as entradas de mapa do coletor de eventos. Em outros casos, ou para obter maior controle, chame [DispEventAdvise](idispeventsimpleimpl-class.md#dispeventadvise) para estabelecer a conexão entre o objeto de origem e a classe base. Chame [DispEventUnadvise](idispeventsimpleimpl-class.md#dispeventunadvise) para interromper a conexão.

Você deve derivar de `IDispEventImpl` (usando um valor exclusivo para *nID*) para cada objeto para o qual você precisa manipular eventos. Você pode reutilizar a classe base, unadvising no objeto de uma fonte informando, em seguida, em relação a um objeto de fonte diferente, mas o número máximo de objetos de fonte que pode ser tratado por um único objeto simultaneamente é limitado pelo número de `IDispEventImpl` classes base.

`IDispEventImpl` fornece a mesma funcionalidade que [IDispEventSimpleImpl](../../atl/reference/idispeventsimpleimpl-class.md), exceto que ele obtém informações sobre a interface do tipo de uma biblioteca de tipos em vez de ter que ele fornecido como um ponteiro para um [atl_func_info](../../atl/reference/atl-func-info-structure.md) estrutura. Use `IDispEventSimpleImpl` quando você não tiver uma biblioteca de tipos que descreve a interface de eventos ou para evitar a sobrecarga associada usando a biblioteca de tipos.

> [!NOTE]
> `IDispEventImpl` e `IDispEventSimpleImpl` fornecer sua própria implementação de `IUnknown::QueryInterface` habilitando cada `IDispEventImpl` e `IDispEventSimpleImpl` classe para agir como uma identidade COM separada e ainda permitir acesso direto aos membros de classe no objeto principal COM base.

Implementação de ATL CE do ActiveX evento coletores somente dá suporte a valores de retorno do tipo HRESULT ou void de seus métodos de manipulador de eventos; Não há suporte para qualquer outro valor de retorno e seu comportamento é indefinido.

Para obter mais informações, consulte [que dão suporte a IDispEventImpl](../../atl/supporting-idispeventimpl.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`_IDispEvent`

`_IDispEventLocator`

[IDispEventSimpleImpl](../../atl/reference/idispeventsimpleimpl-class.md)

`IDispEventImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom

##  <a name="getfuncinfofromid"></a>  IDispEventImpl::GetFuncInfoFromId

Localiza o índice de função para o identificador de expedição especificado.

```
HRESULT GetFuncInfoFromId(
    const IID& iid,
    DISPID dispidMember,
    LCID lcid,
    _ATL_FUNC_INFO& info);
```

### <a name="parameters"></a>Parâmetros

*IID*<br/>
[in] Uma referência para a ID da função.

*dispidMember*<br/>
[in] A ID de expedição da função.

*lcid*<br/>
[in] O contexto de localidade da ID da função.

*Informações de*<br/>
[in] A estrutura que indica como a função é chamada.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

##  <a name="getidsofnames"></a>  IDispEventImpl::GetIDsOfNames

Mapeia um único membro e um conjunto opcional de nomes de argumento para um conjunto correspondente de inteiro DISPIDs, que pode ser usado em chamadas subsequentes para [IDispatch:: Invoke](/windows/desktop/api/oaidl/nf-oaidl-idispatch-invoke).

```
STDMETHOD(GetIDsOfNames)(
    REFIID riid,
    LPOLESTR* rgszNames,
    UINT cNames,
    LCID lcid,
    DISPID* rgdispid);
```

### <a name="remarks"></a>Comentários

Ver [IDispatch::GetIDsOfNames](/windows/desktop/api/oaidl/nf-oaidl-idispatch-getidsofnames) no Windows SDK.

##  <a name="gettypeinfo"></a>  IDispEventImpl::GetTypeInfo

Recupera as informações do tipo de um objeto, que podem ser usadas para obter informações de tipo para uma interface.

```
STDMETHOD(GetTypeInfo)(
    UINT itinfo,
    LCID lcid,
    ITypeInfo** pptinfo);
```

### <a name="remarks"></a>Comentários

##  <a name="gettypeinfocount"></a>  IDispEventImpl::GetTypeInfoCount

Retorna o número de interfaces de informações do tipo que um objeto fornece (0 ou 1).

```
STDMETHOD(GetTypeInfoCount)(UINT* pctinfo);
```

### <a name="remarks"></a>Comentários

Ver [IDispatch::GetTypeInfoCount](/windows/desktop/api/oaidl/nf-oaidl-idispatch-gettypeinfocount) no Windows SDK.

##  <a name="getuserdefinedtype"></a>  IDispEventImpl::GetUserDefinedType

Recupera o tipo básico de um tipo definido pelo usuário.

```
VARTYPE GetUserDefinedType(
    ITypeInfo* pTI,
    HREFTYPE hrt);
```

### <a name="parameters"></a>Parâmetros

*pTI*<br/>
[in] Um ponteiro para o [ITypeInfo](/windows/desktop/api/oaidl/nn-oaidl-itypeinfo) interface que contém o tipo definido pelo usuário.

*hrt*<br/>
[in] Um identificador para a descrição do tipo a ser recuperado.

### <a name="return-value"></a>Valor de retorno

O tipo de variante.

### <a name="remarks"></a>Comentários

Ver [ITypeInfo:: GetRefTypeInfo](/windows/desktop/api/oaidl/nf-oaidl-itypeinfo-getreftypeinfo).

##  <a name="idispeventimpl"></a>  IDispEventImpl::IDispEventImpl

O construtor. Armazena os valores dos parâmetros de modelo de classe *plibid*, *pdiid*, *wMajor*, e *wMinor*.

```
IDispEventImpl();
```

##  <a name="tihclass"></a>  IDispEventImpl::tihclass

Este typedef é uma instância de parâmetro do modelo de classe *tihclass*.

```
typedef tihclass _tihclass;
```

### <a name="remarks"></a>Comentários

Por padrão, a classe é `CComTypeInfoHolder`. `CComTypeInfoHolder` gerencia as informações de tipo para a classe.

## <a name="see-also"></a>Consulte também

[Estrutura _ATL_FUNC_INFO](../../atl/reference/atl-func-info-structure.md)<br/>
[Classe IDispatchImpl](../../atl/reference/idispatchimpl-class.md)<br/>
[Classe IDispEventSimpleImpl](../../atl/reference/idispeventsimpleimpl-class.md)<br/>
[SINK_ENTRY](composite-control-macros.md#sink_entry)<br/>
[SINK_ENTRY_EX](composite-control-macros.md#sink_entry_ex)<br/>
[SINK_ENTRY_INFO](composite-control-macros.md#sink_entry_info)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)