---
title: Macros de entrada de interface COM
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
ms.openlocfilehash: bb7498f639f463290a4a6593ef7c0fbac09b539b
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81326684"
---
# <a name="com_interface_entry-macros"></a>COM_INTERFACE_ENTRY Macros

Essas macros inserem as interfaces de um objeto em seu `QueryInterface`mapa COM para que possam ser acessadas por . A ordem das entradas no mapa COM é que as interfaces `QueryInterface`de ordem serão verificadas para um IID correspondente durante .

|||
|-|-|
|[Com_interface_entry](#com_interface_entry)|Insere interfaces no mapa de interface COM.|
|[COM_INTERFACE_ENTRY2](#com_interface_entry2)|Use esta macro para desambiguar dois ramos de herança.|
|[Com_interface_entry_iid](#com_interface_entry_iid)|Use esta macro para inserir a interface no mapa COM e especificar seu IID.|
|[COM_INTERFACE_ENTRY2_IID](#com_interface_entry2_iid)|O mesmo [que COM_INTERFACE_ENTRY2,](#com_interface_entry2)exceto que você pode especificar um IID diferente.|
|[Com_interface_entry_aggregate](#com_interface_entry_aggregate)|Quando a interface identificada pelo *iid* `COM_INTERFACE_ENTRY_AGGREGATE` é consultada, encaminha para `punk`.|
|[COM_INTERFACE_ENTRY_AGGREGATE_BLIND](#com_interface_entry_aggregate_blind)|O mesmo [que COM_INTERFACE_ENTRY_AGGREGATE,](#com_interface_entry_aggregate)exceto que a consulta para qualquer IID resulta no encaminhamento da consulta para *o punk*.|
|[COM_INTERFACE_ENTRY_AUTOAGGREGATE](#com_interface_entry_autoaggregate)|O mesmo [que COM_INTERFACE_ENTRY_AGGREGATE,](#com_interface_entry_aggregate)exceto se *o punk* é NULO, cria automaticamente o agregado descrito pelos *clísos*.|
|[COM_INTERFACE_ENTRY_AUTOAGGREGATE_BLIND](#com_interface_entry_autoaggregate_blind)|O mesmo [que COM_INTERFACE_ENTRY_AUTOAGGREGATE,](#com_interface_entry_autoaggregate)exceto que a consulta para qualquer IID resulta no encaminhamento da consulta para o *punk,* e se o *punk* é NULO, criando automaticamente o agregado descrito pelos *clsid*.|
|[COM_INTERFACE_ENTRY_BREAK](#com_interface_entry_break)|Faz com que seu programa ligue para [DebugBreak](/windows/win32/api/debugapi/nf-debugapi-debugbreak) quando a interface especificada for consultada.|
|[COM_INTERFACE_ENTRY_CACHED_TEAR_OFF](#com_interface_entry_cached_tear_off)|Salva os dados específicos da interface para cada instância.|
|[COM_INTERFACE_ENTRY_TEAR_OFF](#com_interface_entry_tear_off)|Expõe suas interfaces de ruptura.|
|[Com_interface_entry_chain](#com_interface_entry_chain)|Processa o mapa COM da classe base quando o processamento atinge esta entrada no mapa COM.|
|[COM_INTERFACE_ENTRY_FUNC](#com_interface_entry_func)|Um mecanismo geral para se conectar `QueryInterface` à lógica da ATL.|
|[COM_INTERFACE_ENTRY_FUNC_BLIND](#com_interface_entry_func_blind)|O mesmo que [COM_INTERFACE_ENTRY_FUNC,](#com_interface_entry_func)exceto que a consulta para qualquer IID resulta em uma chamada para *func*.|
|[COM_INTERFACE_ENTRY_NOINTERFACE](#com_interface_entry_nointerface)|Retorna E_NOINTERFACE e encerra o processamento do mapa COM quando a interface especificada é consultada.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom.h

## <a name="com_interface_entry"></a><a name="com_interface_entry"></a>Com_interface_entry

Insere interfaces no mapa de interface COM.

### <a name="syntax"></a>Sintaxe

```
COM_INTERFACE_ENTRY( x )
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
[em] O nome de uma interface de seu objeto de classe deriva diretamente.

### <a name="remarks"></a>Comentários

Normalmente, este é o tipo de entrada que você usa com mais frequência.

### <a name="example"></a>Exemplo

```cpp
BEGIN_COM_MAP(CThisExample)
   COM_INTERFACE_ENTRY(IThisExample)
   COM_INTERFACE_ENTRY(IDispatch)
   COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom.h

## <a name="com_interface_entry2"></a><a name="com_interface_entry2"></a>COM_INTERFACE_ENTRY2

Use esta macro para desambiguar dois ramos de herança.

```
COM_INTERFACE_ENTRY2(x, x2)
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
[em] O nome de uma interface que você deseja expor a partir de seu objeto.

*x2*<br/>
[em] O nome do ramo de herança do qual *x* é exposto.

### <a name="remarks"></a>Comentários

Por exemplo, se você derivar seu objeto de `IDispatch` classe `IDispatch` a partir de duas interfaces duplas, você expõe usando COM_INTERFACE_ENTRY2, uma vez que pode ser obtido de qualquer uma das interfaces.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#118](../../atl/codesnippet/cpp/com-map-macros_2.h)]

## <a name="com_interface_entry_iid"></a><a name="com_interface_entry_iid"></a>Com_interface_entry_iid

Use esta macro para inserir a interface no mapa COM e especificar seu IID.

```
COM_INTERFACE_ENTRY_IID(iid, x)
```

### <a name="parameters"></a>Parâmetros

*Iid*<br/>
[em] O GUID da interface exposta.

*x*<br/>
[em] O nome da classe cujo vtable será exposto como a interface identificada pelo *iid*.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#117](../../atl/codesnippet/cpp/com-map-macros_3.h)]

## <a name="com_interface_entry2_iid"></a><a name="com_interface_entry2_iid"></a>COM_INTERFACE_ENTRY2_IID

O mesmo [que COM_INTERFACE_ENTRY2,](#com_interface_entry2)exceto que você pode especificar um IID diferente.

```
COM_INTERFACE_ENTRY2_IID(iid, x, x2)
```

### <a name="parameters"></a>Parâmetros

*Iid*<br/>
[em] O GUID que você está especificando para a interface.

*x*<br/>
[em] O nome de uma interface da que seu objeto de classe deriva diretamente.

*x2*<br/>
[em] O nome de uma segunda interface da que seu objeto de classe deriva diretamente.

## <a name="com_interface_entry_aggregate"></a><a name="com_interface_entry_aggregate"></a>Com_interface_entry_aggregate

Quando a interface identificada pelo *Iid* é questionada, COM_INTERFACE_ENTRY_AGGREGATE para o *punk*.

```
COM_INTERFACE_ENTRY_AGGREGATE(iid, punk)
```

### <a name="parameters"></a>Parâmetros

*Iid*<br/>
[em] O GUID da interface perguntado para.

*Punk*<br/>
[em] O nome `IUnknown` de um ponteiro.

### <a name="remarks"></a>Comentários

O parâmetro *punk* é assumido para apontar para o desconhecido interno de um agregado ou para NULL, nesse caso a entrada é ignorada. Normalmente, você `CoCreate` seria `FinalConstruct`o agregado em .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#112](../../atl/codesnippet/cpp/com-map-macros_4.h)]

## <a name="com_interface_entry_aggregate_blind"></a><a name="com_interface_entry_aggregate_blind"></a>COM_INTERFACE_ENTRY_AGGREGATE_BLIND

O mesmo [que COM_INTERFACE_ENTRY_AGGREGATE,](#com_interface_entry_aggregate)exceto que a consulta para qualquer IID resulta no encaminhamento da consulta para *o punk*.

```
COM_INTERFACE_ENTRY_AGGREGATE_BLIND(punk)
```

### <a name="parameters"></a>Parâmetros

*Punk*<br/>
[em] O nome `IUnknown` de um ponteiro.

### <a name="remarks"></a>Comentários

Se a consulta de interface falhar, o processamento do mapa COM continuará.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#113](../../atl/codesnippet/cpp/com-map-macros_5.h)]

## <a name="com_interface_entry_autoaggregate"></a><a name="com_interface_entry_autoaggregate"></a>COM_INTERFACE_ENTRY_AUTOAGGREGATE

O mesmo [que COM_INTERFACE_ENTRY_AGGREGATE,](#com_interface_entry_aggregate)exceto se *o punk* é NULO, cria automaticamente o agregado descrito pelos *clísos*.

```
COM_INTERFACE_ENTRY_AUTOAGGREGATE(iid, punk, clsid)
```

### <a name="parameters"></a>Parâmetros

*Iid*<br/>
[em] O GUID da interface perguntado para.

*Punk*<br/>
[em] O nome `IUnknown` de um ponteiro. Deve ser um membro da classe que contém o mapa COM.

*clsid*<br/>
[em] O identificador do agregado que será criado se *o punk* for NULL.

### <a name="remarks"></a>Comentários

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#114](../../atl/codesnippet/cpp/com-map-macros_6.h)]

## <a name="com_interface_entry_autoaggregate_blind"></a><a name="com_interface_entry_autoaggregate_blind"></a>COM_INTERFACE_ENTRY_AUTOAGGREGATE_BLIND

O mesmo [que COM_INTERFACE_ENTRY_AUTOAGGREGATE,](#com_interface_entry_autoaggregate)exceto que a consulta para qualquer IID resulta no encaminhamento da consulta para o *punk,* e se o *punk* é NULO, criando automaticamente o agregado descrito pelos *clsid*.

```
COM_INTERFACE_ENTRY_AUTOAGGREGATE_BLIND(punk, clsid)
```

### <a name="parameters"></a>Parâmetros

*Punk*<br/>
[em] O nome `IUnknown` de um ponteiro. Deve ser um membro da classe que contém o mapa COM.

*clsid*<br/>
[em] O identificador do agregado que será criado se *o punk* for NULL.

### <a name="remarks"></a>Comentários

Se a consulta de interface falhar, o processamento do mapa COM continuará.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Windowing#115](../../atl/codesnippet/cpp/com-map-macros_7.h)]

## <a name="com_interface_entry_break"></a><a name="com_interface_entry_break"></a>COM_INTERFACE_ENTRY_BREAK

Faz com que seu programa ligue para [DebugBreak](/windows/win32/api/debugapi/nf-debugapi-debugbreak) quando a interface especificada for consultada.

```
COM_INTERFACE_ENTRY_BREAK(x)
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
[em] Texto usado para construir o identificador de interface.

### <a name="remarks"></a>Comentários

A interface IID será construída *x* anexando `IID_`x a . Por exemplo, *x* se `IPersistStorage`x é , `IID_IPersistStorage`o IID será .

## <a name="com_interface_entry_cached_tear_off"></a><a name="com_interface_entry_cached_tear_off"></a>COM_INTERFACE_ENTRY_CACHED_TEAR_OFF

Salva os dados específicos da interface para cada instância.

```
COM_INTERFACE_ENTRY_CACHED_TEAR_OFF(iid, x, punk)
```

### <a name="parameters"></a>Parâmetros

*Iid*<br/>
[em] O GUID da interface de tear-off.

*x*<br/>
[em] O nome da classe que implementa a interface.

*Punk*<br/>
[em] O nome `IUnknown` de um ponteiro. Deve ser um membro da classe que contém o mapa COM. Deve ser inicializado para NULL no construtor do objeto de classe.

### <a name="remarks"></a>Comentários

Se a interface não for usada, isso reduz o tamanho geral da ocorrência do objeto.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#54](../../atl/codesnippet/cpp/com-map-macros_8.h)]

## <a name="com_interface_entry_tear_off"></a><a name="com_interface_entry_tear_off"></a>COM_INTERFACE_ENTRY_TEAR_OFF

Expõe suas interfaces de ruptura.

```
COM_INTERFACE_ENTRY_TEAR_OFF(iid, x)
```

### <a name="parameters"></a>Parâmetros

*Iid*<br/>
[em] O GUID da interface de tear-off.

*x*<br/>
[em] O nome da classe que implementa a interface.

### <a name="remarks"></a>Comentários

Uma interface tear-off é implementada como um objeto separado que é instanciado toda vez que a interface que ela representa é consultada. Normalmente, você constrói sua interface como um tear-off se a interface raramente for usada, uma vez que isso salva um ponteiro vtable em cada instância do seu objeto principal. O tear-off é excluído quando sua contagem de referência se torna zero. A classe que implementa o tear-off deve ser derivada `CComTearOffObjectBase` e ter seu próprio mapa COM.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#1](../../atl/codesnippet/cpp/com-map-macros_1.h)]

## <a name="com_interface_entry_chain"></a><a name="com_interface_entry_chain"></a>Com_interface_entry_chain

Processa o mapa COM da classe base quando o processamento atinge esta entrada no mapa COM.

```
COM_INTERFACE_ENTRY_CHAIN(classname)
```

### <a name="parameters"></a>Parâmetros

*Classname*<br/>
[em] Uma classe base do objeto atual.

### <a name="remarks"></a>Comentários

Por exemplo, no seguinte código:

[!code-cpp[NVC_ATL_Windowing#116](../../atl/codesnippet/cpp/com-map-macros_9.h)]

Observe que a primeira entrada no mapa COM deve ser uma interface no objeto que contém o mapa COM. Assim, você não pode iniciar suas entradas de mapa COM com COM_INTERFACE_ENTRY_CHAIN, o que faz com que o mapa COM de um objeto diferente seja pesquisado no ponto em que **COM_INTERFACE_ENTRY_CHAIN**`COtherObject`**aparece** no mapa COM do seu objeto. Se você quiser pesquisar o mapa COM de outro `IUnknown` objeto primeiro, adicione uma entrada de interface para o seu mapa COM e, em seguida, acorrente o mapa COM do outro objeto. Por exemplo:

[!code-cpp[NVC_ATL_Windowing#111](../../atl/codesnippet/cpp/com-map-macros_10.h)]

## <a name="com_interface_entry_func"></a><a name="com_interface_entry_func"></a>COM_INTERFACE_ENTRY_FUNC

Um mecanismo geral para se conectar `QueryInterface` à lógica da ATL.

```
COM_INTERFACE_ENTRY_FUNC(iid, dw, func)
```

### <a name="parameters"></a>Parâmetros

*Iid*<br/>
[em] O GUID da interface exposta.

*dw*<br/>
[em] Um parâmetro passou para o *func.*

*func*<br/>
[em] O ponteiro de função que retornará *iid*.

### <a name="remarks"></a>Comentários

Se *o iid* corresponder ao IID da interface consultada, então a função especificada pelo *func* é chamada. A declaração para a função deve ser:

`HRESULT WINAPI func(void* pv, REFIID riid, LPVOID* ppv, DWORD_PTR dw);`

Quando sua função `pv` é chamada, aponte para o objeto da sua classe. O parâmetro *riid* refere-se à interface que `ppv` está sendo consultada, é o ponteiro para o local onde a função deve armazenar o ponteiro para a interface, e *dw* é o parâmetro que você especificou na entrada. A função \* `ppv` deve ser definida como NULL e retornar E_NOINTERFACE ou S_FALSE se optar por não retornar uma interface. Com E_NOINTERFACE, o processamento do mapa COM termina. Com S_FALSE, o processamento do mapa COM continua, mesmo que nenhum ponteiro de interface tenha sido devolvido. Se a função retornar um ponteiro de interface, ela deve retornar S_OK.

## <a name="com_interface_entry_func_blind"></a><a name="com_interface_entry_func_blind"></a>COM_INTERFACE_ENTRY_FUNC_BLIND

O mesmo que [COM_INTERFACE_ENTRY_FUNC,](#com_interface_entry_func)exceto que a consulta para qualquer IID resulta em uma chamada para *func*.

```
COM_INTERFACE_ENTRY_FUNC_BLIND(dw, func)
```

### <a name="parameters"></a>Parâmetros

*dw*<br/>
[em] Um parâmetro passou para o *func.*

*func*<br/>
[em] A função que é chamada quando esta entrada no mapa COM é processada.

### <a name="remarks"></a>Comentários

Qualquer falha fará com que o processamento continue no mapa COM. Se a função retornar um ponteiro de interface, ela deve retornar S_OK.

## <a name="com_interface_entry_nointerface"></a><a name="com_interface_entry_nointerface"></a>COM_INTERFACE_ENTRY_NOINTERFACE

Retorna E_NOINTERFACE e encerra o processamento do mapa COM quando a interface especificada é consultada.

```
COM_INTERFACE_ENTRY_NOINTERFACE(x)
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
[em] Texto usado para construir o identificador de interface.

### <a name="remarks"></a>Comentários

Você pode usar esta macro para evitar que uma interface seja usada em um caso específico. Por exemplo, você pode inserir essa macro no seu mapa COM antes de COM_INTERFACE_ENTRY_AGGREGATE_BLIND para impedir que uma consulta para a interface seja encaminhada para o desconhecido interno do agregado.

A interface IID será construída *x* anexando `IID_`x a . Por exemplo, *x* se `IPersistStorage`x é , `IID_IPersistStorage`o IID será .
