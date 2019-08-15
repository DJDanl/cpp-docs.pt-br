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
ms.openlocfilehash: e82a397b6d2abb66f773908c72a287c979e5ae1d
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69495928"
---
# <a name="idispeventimpl-class"></a>Classe IDispEventImpl

Essa classe fornece implementações dos `IDispatch` métodos.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

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
Um identificador exclusivo para o objeto de origem. Quando `IDispEventImpl` é a classe base para um controle composto, use a ID de recurso do controle contido desejado para esse parâmetro. Em outros casos, use um número inteiro positivo arbitrário.

*T*<br/>
A classe do usuário, que é derivada de `IDispEventImpl`.

*pdiid*<br/>
O ponteiro para a IID da dispinterface do evento implementada por essa classe. Essa interface deve ser definida na biblioteca de tipos denotada por *plibid*, *wMajor*e *wMinor*.

*plibid*<br/>
Um ponteiro para a biblioteca de tipos que define a interface de expedição apontada por *pdiid*. Se **&AMP; GUID_NULL**, a biblioteca de tipos será carregada a partir do objeto que fornece os eventos.

*wMajor*<br/>
A versão principal da biblioteca de tipos. O valor padrão é 0.

*wMinor*<br/>
A versão secundária da biblioteca de tipos. O valor padrão é 0.

*tihclass*<br/>
A classe usada para gerenciar as informações de tipo para *T*. O valor padrão é uma classe de tipo `CComTypeInfoHolder`; no entanto, você pode substituir esse parâmetro de modelo fornecendo uma classe de um tipo `CComTypeInfoHolder`diferente de.

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
|[IDispEventImpl::GetIDsOfNames](#getidsofnames)|Mapeia um único membro e um conjunto opcional de nomes de argumentos para um conjunto correspondente de DISPIDs inteiros.|
|[IDispEventImpl::GetTypeInfo](#gettypeinfo)|Recupera as informações de tipo de um objeto.|
|[IDispEventImpl::GetTypeInfoCount](#gettypeinfocount)|Recupera o número de interfaces de informações de tipo.|
|[IDispEventImpl::GetUserDefinedType](#getuserdefinedtype)|Recupera o tipo básico de um tipo definido pelo usuário.|

## <a name="remarks"></a>Comentários

`IDispEventImpl`fornece uma maneira de implementar um dispinterface de evento sem exigir que você forneça o código de implementação para cada método/evento nessa interface. `IDispEventImpl`fornece implementações dos `IDispatch` métodos. Você só precisa fornecer implementações para os eventos que você está interessado em manipular.

`IDispEventImpl`funciona em conjunto com o mapa do coletor de eventos em sua classe para rotear eventos para a função de manipulador apropriada. Para usar esta classe:

Adicione uma macro [SINK_ENTRY](composite-control-macros.md#sink_entry) ou [SINK_ENTRY_EX](composite-control-macros.md#sink_entry_ex) ao mapa do coletor de eventos para cada evento em cada objeto que você deseja manipular. Ao usar `IDispEventImpl` como uma classe base de um controle composto, você pode chamar [AtlAdviseSinkMap](connection-point-global-functions.md#atladvisesinkmap) para estabelecer e interromper a conexão com as origens do evento para todas as entradas no mapa do coletor de eventos. Em outros casos, ou para maior controle, chame [DispEventAdvise](idispeventsimpleimpl-class.md#dispeventadvise) para estabelecer a conexão entre o objeto de origem e a classe base. Chame [DispEventUnadvise](idispeventsimpleimpl-class.md#dispeventunadvise) para interromper a conexão.

Você deve derivar `IDispEventImpl` de (usando um valor exclusivo para *NID*) para cada objeto para o qual você precisa manipular eventos. Você pode reutilizar a classe base ao se desaconselhar em um objeto de origem, aconselhando em um objeto de origem diferente, mas o número máximo de objetos de origem que podem ser manipulados por um único objeto ao mesmo tempo `IDispEventImpl` é limitado pelo número de classes base.

`IDispEventImpl`fornece a mesma funcionalidade que [IDispEventSimpleImpl](../../atl/reference/idispeventsimpleimpl-class.md), exceto que ele obtém informações de tipo sobre a interface de uma biblioteca de tipos em vez de ter fornecido como um ponteiro para uma estrutura [_ATL_FUNC_INFO](../../atl/reference/atl-func-info-structure.md) . Use `IDispEventSimpleImpl` quando você não tiver uma biblioteca de tipos que descreva a interface de evento ou queira evitar a sobrecarga associada ao uso da biblioteca de tipos.

> [!NOTE]
> `IDispEventImpl`e `IDispEventSimpleImpl` fornecem sua própria implementação de `IUnknown::QueryInterface` habilitar cada `IDispEventImpl` `IDispEventSimpleImpl` classe base para atuar como uma identidade com separada e ainda permitir acesso direto a membros de classe em seu objeto com principal.

A implementação da ATL CE dos coletores de eventos ActiveX dá suporte apenas a valores de retorno do tipo HRESULT ou void dos métodos do manipulador de eventos; qualquer outro valor de retorno não tem suporte e seu comportamento é indefinido.

Para obter mais informações, consulte [Supporting IDispEventImpl](../../atl/supporting-idispeventimpl.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`_IDispEvent`

`_IDispEventLocator`

[IDispEventSimpleImpl](../../atl/reference/idispeventsimpleimpl-class.md)

`IDispEventImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom. h

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

*iid*<br/>
no Uma referência à ID da função.

*dispidMember*<br/>
no A ID de expedição da função.

*lcid*<br/>
no O contexto de localidade da ID da função.

*info*<br/>
no A estrutura que indica como a função é chamada.

### <a name="return-value"></a>Valor de retorno

Um valor HRESULT padrão.

##  <a name="getidsofnames"></a>  IDispEventImpl::GetIDsOfNames

Mapeia um único membro e um conjunto opcional de nomes de argumentos para um conjunto correspondente de DISPIDs inteiros, que podem ser usados em chamadas subsequentes para [IDispatch:: Invoke](/windows/win32/api/oaidl/nf-oaidl-idispatch-invoke).

```
STDMETHOD(GetIDsOfNames)(
    REFIID riid,
    LPOLESTR* rgszNames,
    UINT cNames,
    LCID lcid,
    DISPID* rgdispid);
```

### <a name="remarks"></a>Comentários

Consulte [IDispatch:: GetIDsOfNames](/windows/win32/api/oaidl/nf-oaidl-idispatch-getidsofnames) na SDK do Windows.

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

Consulte [IDispatch:: GetTypeInfoCount](/windows/win32/api/oaidl/nf-oaidl-idispatch-gettypeinfocount) na SDK do Windows.

##  <a name="getuserdefinedtype"></a>  IDispEventImpl::GetUserDefinedType

Recupera o tipo básico de um tipo definido pelo usuário.

```
VARTYPE GetUserDefinedType(
    ITypeInfo* pTI,
    HREFTYPE hrt);
```

### <a name="parameters"></a>Parâmetros

*pTI*<br/>
no Um ponteiro para a interface [ITypeInfo](/windows/win32/api/oaidl/nn-oaidl-itypeinfo) que contém o tipo definido pelo usuário.

*hrt*<br/>
no Um identificador para a descrição de tipo a ser recuperada.

### <a name="return-value"></a>Valor de retorno

O tipo de variante.

### <a name="remarks"></a>Comentários

Consulte [ITypeInfo:: GetRefTypeInfo](/windows/win32/api/oaidl/nf-oaidl-itypeinfo-getreftypeinfo).

##  <a name="idispeventimpl"></a>  IDispEventImpl::IDispEventImpl

O construtor. Armazena os valores dos parâmetros de template de classe *plibid*, *pdiid*, *wMajor*e *wMinor*.

```
IDispEventImpl();
```

##  <a name="tihclass"></a>  IDispEventImpl::tihclass

Este typedef é uma instância do parâmetro de modelo de classe *tihclass*.

```
typedef tihclass _tihclass;
```

### <a name="remarks"></a>Comentários

Por padrão, a classe é `CComTypeInfoHolder`. `CComTypeInfoHolder`gerencia as informações de tipo da classe.

## <a name="see-also"></a>Consulte também

[Estrutura _ATL_FUNC_INFO](../../atl/reference/atl-func-info-structure.md)<br/>
[Classe IDispatchImpl](../../atl/reference/idispatchimpl-class.md)<br/>
[Classe IDispEventSimpleImpl](../../atl/reference/idispeventsimpleimpl-class.md)<br/>
[SINK_ENTRY](composite-control-macros.md#sink_entry)<br/>
[SINK_ENTRY_EX](composite-control-macros.md#sink_entry_ex)<br/>
[SINK_ENTRY_INFO](composite-control-macros.md#sink_entry_info)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
