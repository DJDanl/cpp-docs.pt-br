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
ms.openlocfilehash: fa6e9f972accd0115d9f1e3248bd97ddde0c3c63
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81329764"
---
# <a name="idispeventimpl-class"></a>Classe IDispEventImpl

Esta classe fornece implementações dos `IDispatch` métodos.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

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
Um identificador único para o objeto de origem. Quando `IDispEventImpl` for a classe base para um controle composto, use o ID de recurso do controle contido desejado para este parâmetro. Em outros casos, use um inteiro positivo arbitrário.

*T*<br/>
A classe do usuário, que `IDispEventImpl`é derivada de .

*Pdiid*<br/>
O ponteiro para o IID da disinterface de evento implementado por esta classe. Esta interface deve ser definida na biblioteca do tipo denotada por *plibid*, *wMajor*e *wMinor*.

*plibid*<br/>
Um ponteiro para a biblioteca de tipos que define a interface de despacho apontada por *pdiid*. Se **&GUID_NULL,** a biblioteca do tipo será carregada a partir do objeto que alimenta os eventos.

*wMajor*<br/>
A versão principal da biblioteca de tipos. O valor padrão é 0.

*wMenor*<br/>
A versão secundária da biblioteca de tipos. O valor padrão é 0.

*tihclass*<br/>
A classe usada para gerenciar as informações do tipo para *T*. O valor padrão é `CComTypeInfoHolder`uma classe de tipo; no entanto, você pode substituir este parâmetro de modelo `CComTypeInfoHolder`fornecendo uma classe de um tipo diferente de .

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|[IDispEventImpl::_tihclass](../../atl/reference/idispeventimpl-class.md)|A classe costumava gerenciar as informações do tipo. Por padrão, `CComTypeInfoHolder`.|

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[IDispEventImpl::IDispEventImpl](#idispeventimpl)|O construtor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[IDispEventImpl::GetFuncInfoFromId](#getfuncinfofromid)|Localiza o índice de função do identificador de despacho especificado.|
|[IDispEventImpl::GetIDsOfNames](#getidsofnames)|Mapeia um único membro e um conjunto opcional de nomes de argumentos para um conjunto correspondente de DISPIDs inteiros.|
|[IDispEventImpl::GetTypeInfo](#gettypeinfo)|Recupera as informações do tipo para um objeto.|
|[IDispEventImpl::GetTypeInfoCount](#gettypeinfocount)|Recupera o número de interfaces de informações de tipo.|
|[IDispEventImpl::GetUserDefinedType](#getuserdefinedtype)|Recupera o tipo básico de um tipo definido pelo usuário.|

## <a name="remarks"></a>Comentários

`IDispEventImpl`fornece uma maneira de implementar uma dispinterface de evento sem exigir que você forneça código de implementação para cada método/evento nessa interface. `IDispEventImpl`fornece implementações `IDispatch` dos métodos. Você só precisa fornecer implementações para os eventos que você está interessado em lidar.

`IDispEventImpl`trabalha em conjunto com o mapa do dissipador de eventos em sua classe para encaminhar eventos para a função de manipulador apropriado. Para usar esta classe:

Adicione uma [SINK_ENTRY](composite-control-macros.md#sink_entry) ou [SINK_ENTRY_EX](composite-control-macros.md#sink_entry_ex) macro ao mapa do dissipador de eventos para cada evento em cada objeto que você deseja manusear. Ao `IDispEventImpl` usar como uma classe base de um controle composto, você pode ligar para [o AtlAdviseSinkMap](connection-point-global-functions.md#atladvisesinkmap) para estabelecer e quebrar a conexão com as fontes de evento para todas as entradas no mapa do dissipador de eventos. Em outros casos, ou para maior controle, ligue para [o DispEventAdvise](idispeventsimpleimpl-class.md#dispeventadvise) para estabelecer a conexão entre o objeto de origem e a classe base. Ligue para [o DispEventUnadvise](idispeventsimpleimpl-class.md#dispeventunadvise) para interromper a conexão.

Você deve `IDispEventImpl` derivar de (usando um valor único para *nID*) para cada objeto para o qual você precisa lidar com eventos. Você pode reutilizar a classe base desaconselhando contra um objeto de origem e aconselhando contra um objeto de origem diferente, mas o `IDispEventImpl` número máximo de objetos de origem que podem ser manuseados por um único objeto de uma só vez é limitado pelo número de classes base.

`IDispEventImpl`fornece a mesma funcionalidade que [o IDispEventSimpleImpl,](../../atl/reference/idispeventsimpleimpl-class.md)exceto que obtém informações de tipo sobre a interface de uma biblioteca de tipos em vez de tê-la fornecida como ponteiro para uma estrutura [_ATL_FUNC_INFO.](../../atl/reference/atl-func-info-structure.md) Use `IDispEventSimpleImpl` quando você não tiver uma biblioteca de tipos descrevendo a interface do evento ou quiser evitar a sobrecarga associada ao uso da biblioteca do tipo.

> [!NOTE]
> `IDispEventImpl`e `IDispEventSimpleImpl` fornecer sua `IUnknown::QueryInterface` própria implementação de permitir que cada `IDispEventImpl` classe e `IDispEventSimpleImpl` a classe base atuem como uma identidade COM separada, permitindo ainda acesso direto aos membros da classe em seu objeto COM principal.

A implementação do evento ACTIVEX no CE ATL só suporta valores de retorno do tipo HRESULT ou vazios de seus métodos de manipulador de eventos; qualquer outro valor de retorno não é suportado e seu comportamento é indefinido.

Para obter mais informações, consulte [Suporte IDispEventImpl](../../atl/supporting-idispeventimpl.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`_IDispEvent`

`_IDispEventLocator`

[Idispeventsimpleimpl](../../atl/reference/idispeventsimpleimpl-class.md)

`IDispEventImpl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom.h

## <a name="idispeventimplgetfuncinfofromid"></a><a name="getfuncinfofromid"></a>IDispEventImpl::GetFuncInfoFromId

Localiza o índice de função do identificador de despacho especificado.

```
HRESULT GetFuncInfoFromId(
    const IID& iid,
    DISPID dispidMember,
    LCID lcid,
    _ATL_FUNC_INFO& info);
```

### <a name="parameters"></a>Parâmetros

*Iid*<br/>
[em] Uma referência ao ID da função.

*dispidMember*<br/>
[em] A id de despacho da função.

*Lcid*<br/>
[em] O contexto local da função ID.

*Informação*<br/>
[em] A estrutura indicando como a função é chamada.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

## <a name="idispeventimplgetidsofnames"></a><a name="getidsofnames"></a>IDispEventImpl::GetIDsOfNames

Mapeia um único membro e um conjunto opcional de nomes de argumentos para um conjunto correspondente de DISPIDs inteiros, que podem ser usados em chamadas subseqüentes para [IDispatch::Invoke](/windows/win32/api/oaidl/nf-oaidl-idispatch-invoke).

```
STDMETHOD(GetIDsOfNames)(
    REFIID riid,
    LPOLESTR* rgszNames,
    UINT cNames,
    LCID lcid,
    DISPID* rgdispid);
```

### <a name="remarks"></a>Comentários

Consulte [IDispatch::GetIDsOfNames](/windows/win32/api/oaidl/nf-oaidl-idispatch-getidsofnames) no Windows SDK.

## <a name="idispeventimplgettypeinfo"></a><a name="gettypeinfo"></a>IDispEventImpl::GetTypeInfo

Recupera as informações do tipo de um objeto, que podem ser usadas para obter informações de tipo para uma interface.

```
STDMETHOD(GetTypeInfo)(
    UINT itinfo,
    LCID lcid,
    ITypeInfo** pptinfo);
```

### <a name="remarks"></a>Comentários

## <a name="idispeventimplgettypeinfocount"></a><a name="gettypeinfocount"></a>IDispEventImpl::GetTypeInfoCount

Retorna o número de interfaces de informações do tipo que um objeto fornece (0 ou 1).

```
STDMETHOD(GetTypeInfoCount)(UINT* pctinfo);
```

### <a name="remarks"></a>Comentários

Consulte [IDispatch::GetTypeInfoCount](/windows/win32/api/oaidl/nf-oaidl-idispatch-gettypeinfocount) no Windows SDK.

## <a name="idispeventimplgetuserdefinedtype"></a><a name="getuserdefinedtype"></a>IDispEventImpl::GetUserDefinedType

Recupera o tipo básico de um tipo definido pelo usuário.

```
VARTYPE GetUserDefinedType(
    ITypeInfo* pTI,
    HREFTYPE hrt);
```

### <a name="parameters"></a>Parâmetros

*Pti*<br/>
[em] Um ponteiro para a interface [ITypeInfo](/windows/win32/api/oaidl/nn-oaidl-itypeinfo) contendo o tipo definido pelo usuário.

*Hrt*<br/>
[em] Uma alça para a descrição do tipo a ser recuperada.

### <a name="return-value"></a>Valor retornado

O tipo de variante.

### <a name="remarks"></a>Comentários

Consulte [iTypeinfo::getrefTypeinfo](/windows/win32/api/oaidl/nf-oaidl-itypeinfo-getreftypeinfo).

## <a name="idispeventimplidispeventimpl"></a><a name="idispeventimpl"></a>IDispEventImpl::IDispEventImpl

O construtor. Armazena os valores dos parâmetros do modelo de classe *plibid,* *pdiid,* *wMajor*e *wMinor*.

```
IDispEventImpl();
```

## <a name="idispeventimpltihclass"></a><a name="tihclass"></a>IDispEventImpl::tihclass

Este typedef é uma instância do parâmetro de modelo de classe *tihclass*.

```
typedef tihclass _tihclass;
```

### <a name="remarks"></a>Comentários

Por padrão, a `CComTypeInfoHolder`classe é . `CComTypeInfoHolder`gerencia as informações do tipo para a classe.

## <a name="see-also"></a>Confira também

[Estrutura _ATL_FUNC_INFO](../../atl/reference/atl-func-info-structure.md)<br/>
[Classe IDispatchImpl](../../atl/reference/idispatchimpl-class.md)<br/>
[Classe IDispEventSimpleImpl](../../atl/reference/idispeventsimpleimpl-class.md)<br/>
[SINK_ENTRY](composite-control-macros.md#sink_entry)<br/>
[Sink_entry_ex](composite-control-macros.md#sink_entry_ex)<br/>
[Sink_entry_info](composite-control-macros.md#sink_entry_info)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
