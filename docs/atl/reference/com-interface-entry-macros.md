---
title: Macros de entrada da Interface COM
ms.date: 03/28/2017
f1_keywords:
- atlcom/ATL::COM_INTERFACE_ENTRY
- atlcom/ATL::COM_INTERFACE_ENTRY_IID
- atlcom/ATL::COM_INTERFACE_ENTRY_AGGREGATE
- atlcom/ATL::COM_INTERFACE_ENTRY_AGGREGATE_BLIND
- atlcom/ATL::COM_INTERFACE_ENTRY_AUTOAGGREGATE
- atlcom/ATL::COM_INTERFACE_ENTRY_AUTOAGGREGATE_BLIND
- atlcom/ATL::COM_INTERFACE_ENTRY_BREAK
- atlcom/ATL::COM_INTERFACE_ENTRY_CACHED_TEAR_OFF
- atlcom/ATL::COM_INTERFACE_ENTRY_TEAR_OFF
- atlcom/ATL::COM_INTERFACE_ENTRY_CHAIN
- atlcom/ATL::COM_INTERFACE_ENTRY_FUNC
- atlcom/ATL::COM_INTERFACE_ENTRY_FUNC_BLIND
- atlcom/ATL::COM_INTERFACE_ENTRY_NOINTERFACE
helpviewer_keywords:
- COM interfaces, COM interface entry macros
ms.assetid: 19dcb768-2e1f-4b8d-a618-453a01a4bd00
ms.openlocfilehash: f8439e973c935108d645076bb7e2bfae7207e65d
ms.sourcegitcommit: ecf274bcfe3a977c48745aaa243e5e731f1fdc5f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/04/2019
ms.locfileid: "66503339"
---
# <a name="cominterfaceentry-macros"></a>COM_INTERFACE_ENTRY Macros

Essas macros inserir interfaces de um objeto em seu mapa COM, para que eles possam ser acessados por `QueryInterface`. A ordem das entradas no mapa de COM é que as interfaces de ordem serão verificadas para um IID correspondente durante `QueryInterface`.

|||
|-|-|
|[COM_INTERFACE_ENTRY](#com_interface_entry)|Fecha o mapa de interface COM interfaces.|
|[COM_INTERFACE_ENTRY2](#com_interface_entry2)|Use esta macro para resolver a ambiguidade de duas ramificações de herança.|
|[COM_INTERFACE_ENTRY_IID](#com_interface_entry_iid)|Use esta macro para entrar na interface do mapa COM e especificar seu IID.|
|[COM_INTERFACE_ENTRY2_IID](#com_interface_entry2_iid)|Mesmo que [COM_INTERFACE_ENTRY2](#com_interface_entry2), exceto que você pode especificar um IID diferente.|
|[COM_INTERFACE_ENTRY_AGGREGATE](#com_interface_entry_aggregate)|Quando a interface identificada por *iid* é consultado para, `COM_INTERFACE_ENTRY_AGGREGATE` encaminha para `punk`.|
|[COM_INTERFACE_ENTRY_AGGREGATE_BLIND](#com_interface_entry_aggregate_blind)|Mesmo que [COM_INTERFACE_ENTRY_AGGREGATE](#com_interface_entry_aggregate), exceto que consultar qualquer IID resulta na consulta de encaminhamento *punk*.|
|[COM_INTERFACE_ENTRY_AUTOAGGREGATE](#com_interface_entry_autoaggregate)|Mesmo que [COM_INTERFACE_ENTRY_AGGREGATE](#com_interface_entry_aggregate), exceto se *punk* for NULL, ele cria automaticamente a agregação descrita pelo *clsid*.|
|[COM_INTERFACE_ENTRY_AUTOAGGREGATE_BLIND](#com_interface_entry_autoaggregate_blind)|Mesmo que [COM_INTERFACE_ENTRY_AUTOAGGREGATE](#com_interface_entry_autoaggregate), exceto que consultar qualquer IID resulta na consulta de encaminhamento *punk*e se *punk* for NULL, a criação automática a agregação descrita pelo *clsid*.|
|[COM_INTERFACE_ENTRY_BREAK](#com_interface_entry_break)|Faz com que o programa chamar [DebugBreak](/windows/desktop/api/debugapi/nf-debugapi-debugbreak) quando a interface especificada é consultada para.|
|[COM_INTERFACE_ENTRY_CACHED_TEAR_OFF](#com_interface_entry_cached_tear_off)|Salva os dados específicos à interface para todas as instâncias.|
|[COM_INTERFACE_ENTRY_TEAR_OFF](#com_interface_entry_tear_off)|Expõe as interfaces destacáveis.|
|[COM_INTERFACE_ENTRY_CHAIN](#com_interface_entry_chain)|Processa o mapa COM da classe base quando o processamento atinge essa entrada no mapa COM.|
|[COM_INTERFACE_ENTRY_FUNC](#com_interface_entry_func)|Um mecanismo geral para vinculando do ATL `QueryInterface` lógica.|
|[COM_INTERFACE_ENTRY_FUNC_BLIND](#com_interface_entry_func_blind)|Mesmo que [COM_INTERFACE_ENTRY_FUNC](#com_interface_entry_func), exceto que consultar qualquer IID resulta em uma chamada para *func*.|
|[COM_INTERFACE_ENTRY_NOINTERFACE](#com_interface_entry_nointerface)|Retorna E_NOINTERFACE e termina COM o mapa processamento quando a interface especificada é consultada para.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom

## <a name="com_interface_entry"></a> COM_INTERFACE_ENTRY

Fecha o mapa de interface COM interfaces.

### <a name="syntax"></a>Sintaxe

```
COM_INTERFACE_ENTRY( x )
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
[in] O nome de uma interface que seu objeto de classe deriva diretamente.

### <a name="remarks"></a>Comentários

Normalmente, esse é o tipo de entrada usados com mais frequência.

### <a name="example"></a>Exemplo

```cpp
BEGIN_COM_MAP(CThisExample)
   COM_INTERFACE_ENTRY(IThisExample)
   COM_INTERFACE_ENTRY(IDispatch)
   COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom

##  <a name="com_interface_entry2"></a>  COM_INTERFACE_ENTRY2

Use esta macro para resolver a ambiguidade de duas ramificações de herança.

```
COM_INTERFACE_ENTRY2(x, x2)
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
[in] O nome de uma interface que você deseja expor de seu objeto.

*x2*<br/>
[in] O nome do branch de herança do qual *x* é exposto.

### <a name="remarks"></a>Comentários

Por exemplo, se você derivar seu objeto de classe de duas interfaces duplas, expor `IDispatch` usando COM_INTERFACE_ENTRY2 desde `IDispatch` pode ser obtida de qualquer uma das interfaces.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#118](../../atl/codesnippet/cpp/com-map-macros_2.h)]

##  <a name="com_interface_entry_iid"></a>  COM_INTERFACE_ENTRY_IID

Use esta macro para entrar na interface do mapa COM e especificar seu IID.

```
COM_INTERFACE_ENTRY_IID(iid, x)
```

### <a name="parameters"></a>Parâmetros

*iid*<br/>
[in] O GUID da interface exposta.

*x*<br/>
[in] O nome da classe cuja vtable será exposta como a interface identificada pelo *iid*.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#117](../../atl/codesnippet/cpp/com-map-macros_3.h)]

##  <a name="com_interface_entry2_iid"></a>  COM_INTERFACE_ENTRY2_IID

Mesmo que [COM_INTERFACE_ENTRY2](#com_interface_entry2), exceto que você pode especificar um IID diferente.

```
COM_INTERFACE_ENTRY2_IID(iid, x, x2)
```

### <a name="parameters"></a>Parâmetros

*iid*<br/>
[in] O GUID que você está especificando para a interface.

*x*<br/>
[in] O nome de uma interface que seu objeto de classe deriva diretamente.

*x2*<br/>
[in] O nome de uma segunda interface que seu objeto de classe deriva diretamente.

##  <a name="com_interface_entry_aggregate"></a>  COM_INTERFACE_ENTRY_AGGREGATE

Quando a interface identificada por *iid* é consultado para, COM_INTERFACE_ENTRY_AGGREGATE encaminha para o *punk*.

```
COM_INTERFACE_ENTRY_AGGREGATE(iid, punk)
```

### <a name="parameters"></a>Parâmetros

*iid*<br/>
[in] O GUID da interface consultado.

*punk*<br/>
[in] O nome de um `IUnknown` ponteiro.

### <a name="remarks"></a>Comentários

O *punk* parâmetro é considerado apontar para o desconhecido interno de uma agregação ou como NULL, caso em que a entrada será ignorada. Normalmente, você teria `CoCreate` a agregação em `FinalConstruct`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#112](../../atl/codesnippet/cpp/com-map-macros_4.h)]

##  <a name="com_interface_entry_aggregate_blind"></a>  COM_INTERFACE_ENTRY_AGGREGATE_BLIND

Mesmo que [COM_INTERFACE_ENTRY_AGGREGATE](#com_interface_entry_aggregate), exceto que consultar qualquer IID resulta na consulta de encaminhamento *punk*.

```
COM_INTERFACE_ENTRY_AGGREGATE_BLIND(punk)
```

### <a name="parameters"></a>Parâmetros

*punk*<br/>
[in] O nome de um `IUnknown` ponteiro.

### <a name="remarks"></a>Comentários

Se a consulta de interface falhar, o processamento do mapa COM continuará.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#113](../../atl/codesnippet/cpp/com-map-macros_5.h)]

##  <a name="com_interface_entry_autoaggregate"></a>  COM_INTERFACE_ENTRY_AUTOAGGREGATE

Mesmo que [COM_INTERFACE_ENTRY_AGGREGATE](#com_interface_entry_aggregate), exceto se *punk* for NULL, ele cria automaticamente a agregação descrita pelo *clsid*.

```
COM_INTERFACE_ENTRY_AUTOAGGREGATE(iid, punk, clsid)
```

### <a name="parameters"></a>Parâmetros

*iid*<br/>
[in] O GUID da interface consultado.

*punk*<br/>
[in] O nome de um `IUnknown` ponteiro. Deve ser um membro da classe que contém o mapa COM.

*clsid*<br/>
[in] O identificador de agregação que será criado se *punk* é NULL.

### <a name="remarks"></a>Comentários

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#114](../../atl/codesnippet/cpp/com-map-macros_6.h)]

##  <a name="com_interface_entry_autoaggregate_blind"></a>  COM_INTERFACE_ENTRY_AUTOAGGREGATE_BLIND

Mesmo que [COM_INTERFACE_ENTRY_AUTOAGGREGATE](#com_interface_entry_autoaggregate), exceto que consultar qualquer IID resulta na consulta de encaminhamento *punk*e se *punk* for NULL, a criação automática a agregação descrita pelo *clsid*.

```
COM_INTERFACE_ENTRY_AUTOAGGREGATE_BLIND(punk, clsid)
```

### <a name="parameters"></a>Parâmetros

*punk*<br/>
[in] O nome de um `IUnknown` ponteiro. Deve ser um membro da classe que contém o mapa COM.

*clsid*<br/>
[in] O identificador de agregação que será criado se *punk* é NULL.

### <a name="remarks"></a>Comentários

Se a consulta de interface falhar, o processamento do mapa COM continuará.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#115](../../atl/codesnippet/cpp/com-map-macros_7.h)]

##  <a name="com_interface_entry_break"></a>  COM_INTERFACE_ENTRY_BREAK

Faz com que o programa chamar [DebugBreak](/windows/desktop/api/debugapi/nf-debugapi-debugbreak) quando a interface especificada é consultada para.

```
COM_INTERFACE_ENTRY_BREAK(x)
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
[in] Texto usado para construir o identificador de interface.

### <a name="remarks"></a>Comentários

A interface IID será construída por meio do acréscimo *x* para `IID_`. Por exemplo, se *x* é `IPersistStorage`, será o IID `IID_IPersistStorage`.

##  <a name="com_interface_entry_cached_tear_off"></a>  COM_INTERFACE_ENTRY_CACHED_TEAR_OFF

Salva os dados específicos à interface para todas as instâncias.

```
COM_INTERFACE_ENTRY_CACHED_TEAR_OFF(iid, x, punk)
```

### <a name="parameters"></a>Parâmetros

*iid*<br/>
[in] O GUID da interface destacáveis.

*x*<br/>
[in] O nome da classe que implementa a interface.

*punk*<br/>
[in] O nome de um `IUnknown` ponteiro. Deve ser um membro da classe que contém o mapa COM. Devem ser inicializadas como NULL no construtor do objeto de classe.

### <a name="remarks"></a>Comentários

Se a interface não for usada, isso reduz o tamanho geral da instância do objeto.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#54](../../atl/codesnippet/cpp/com-map-macros_8.h)]

##  <a name="com_interface_entry_tear_off"></a>  COM_INTERFACE_ENTRY_TEAR_OFF

Expõe as interfaces destacáveis.

```
COM_INTERFACE_ENTRY_TEAR_OFF(iid, x)
```

### <a name="parameters"></a>Parâmetros

*iid*<br/>
[in] O GUID da interface destacáveis.

*x*<br/>
[in] O nome da classe que implementa a interface.

### <a name="remarks"></a>Comentários

Uma interface destacável é implementada como um objeto separado que é instanciado sempre que a interface representa é consultado para. Normalmente, é criar sua interface como um destacáveis se a interface é usada raramente, uma vez que isso economiza um ponteiro vtable em cada instância do objeto principal. O destacável é excluído quando sua contagem de referência se torna zero. A classe que implementa o destacáveis deve ser derivada de `CComTearOffObjectBase` e têm seu próprio mapa COM.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#1](../../atl/codesnippet/cpp/com-map-macros_1.h)]

##  <a name="com_interface_entry_chain"></a>  COM_INTERFACE_ENTRY_CHAIN

Processa o mapa COM da classe base quando o processamento atinge essa entrada no mapa COM.

```
COM_INTERFACE_ENTRY_CHAIN(classname)
```

### <a name="parameters"></a>Parâmetros

*classname*<br/>
[in] Uma classe base do objeto atual.

### <a name="remarks"></a>Comentários

Por exemplo, no código a seguir:

[!code-cpp[NVC_ATL_Windowing#116](../../atl/codesnippet/cpp/com-map-macros_9.h)]

Observe que a primeira entrada no mapa COM deve ser uma interface no objeto que contém o mapa COM. Assim, você não pode iniciar suas entradas de mapa COM COM_INTERFACE_ENTRY_CHAIN, que faz com que o mapa de COM de um objeto diferente a ser pesquisado no ponto em que **COM_INTERFACE_ENTRY_CHAIN (** `COtherObject` **)** aparece no mapa de COM do objeto. Se você desejar pesquisar o mapa de COM de outro objeto pela primeira vez, adicione uma entrada de interface para `IUnknown` no mapa de COM, em seguida, encadear mapa de COM do outro objeto. Por exemplo:

[!code-cpp[NVC_ATL_Windowing#111](../../atl/codesnippet/cpp/com-map-macros_10.h)]

##  <a name="com_interface_entry_func"></a>  COM_INTERFACE_ENTRY_FUNC

Um mecanismo geral para vinculando do ATL `QueryInterface` lógica.

```
COM_INTERFACE_ENTRY_FUNC(iid, dw, func)
```

### <a name="parameters"></a>Parâmetros

*iid*<br/>
[in] O GUID da interface exposta.

*dw*<br/>
[in] Um parâmetro passado para o *func*.

*func*<br/>
[in] O ponteiro de função que retornará *iid*.

### <a name="remarks"></a>Comentários

Se *iid* coincide com o IID da interface consultado para, em seguida, a função especificada por *func* é chamado. A declaração de função deve ser:

`HRESULT WINAPI func(void* pv, REFIID riid, LPVOID* ppv, DWORD_PTR dw);`

Quando sua função é chamada, `pv` aponta para o objeto de classe. O *riid* parâmetro refere-se à interface que está sendo consultada, `ppv` é o ponteiro para o local em que a função deve armazenar o ponteiro para a interface, e *dw* é o parâmetro você especificado na entrada. A função deve ser definido \* `ppv` como nulo e retorno S_FALSE se ele optar por não retornar uma interface ou E_NOINTERFACE. Com E_NOINTERFACE, processamento de mapa de COM é encerrado. Com S_FALSE, COM mapa o processamento continuará, embora nenhum ponteiro de interface foi retornado. Se a função retorna um ponteiro de interface, ele deverá retornar S_OK.

##  <a name="com_interface_entry_func_blind"></a>  COM_INTERFACE_ENTRY_FUNC_BLIND

Mesmo que [COM_INTERFACE_ENTRY_FUNC](#com_interface_entry_func), exceto que consultar qualquer IID resulta em uma chamada para *func*.

```
COM_INTERFACE_ENTRY_FUNC_BLIND(dw, func)
```

### <a name="parameters"></a>Parâmetros

*dw*<br/>
[in] Um parâmetro passado para o *func*.

*func*<br/>
[in] A função que é chamada quando esta entrada no mapa de COM é processada.

### <a name="remarks"></a>Comentários

Qualquer falha fará com que o processamento continue no mapa COM. Se a função retorna um ponteiro de interface, ele deverá retornar S_OK.

##  <a name="com_interface_entry_nointerface"></a>  COM_INTERFACE_ENTRY_NOINTERFACE

Retorna E_NOINTERFACE e termina COM o mapa processamento quando a interface especificada é consultada para.

```
COM_INTERFACE_ENTRY_NOINTERFACE(x)
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
[in] Texto usado para construir o identificador de interface.

### <a name="remarks"></a>Comentários

Você pode usar essa macro para impedir que uma interface que está sendo usado em um caso específico. Por exemplo, você pode inserir esta macro em seu mapa COM logo antes COM_INTERFACE_ENTRY_AGGREGATE_BLIND para impedir que uma consulta para a interface que está sendo encaminhado para desconhecido de interna da agregação.

A interface IID será construída por meio do acréscimo *x* para `IID_`. Por exemplo, se *x* é `IPersistStorage`, será o IID `IID_IPersistStorage`.
