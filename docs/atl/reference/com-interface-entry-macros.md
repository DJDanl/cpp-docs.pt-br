---
title: Macros de entrada da interface COM
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
ms.openlocfilehash: 1e1674bad1164e640939d430a860beac7a6e4208
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78855660"
---
# <a name="com_interface_entry-macros"></a>COM_INTERFACE_ENTRY macros

Essas macros inserem as interfaces de um objeto em seu mapa de COM para que possam ser acessadas pelo `QueryInterface`. A ordem das entradas no mapa COM é que as interfaces de ordem serão verificadas em busca de um IID correspondente durante a `QueryInterface`.

|||
|-|-|
|[COM_INTERFACE_ENTRY](#com_interface_entry)|Insere interfaces no mapa de interface COM.|
|[COM_INTERFACE_ENTRY2](#com_interface_entry2)|Use esta macro para desambiguar duas ramificações de herança.|
|[COM_INTERFACE_ENTRY_IID](#com_interface_entry_iid)|Use essa macro para inserir a interface no mapa COM e especificar seu IID.|
|[COM_INTERFACE_ENTRY2_IID](#com_interface_entry2_iid)|O mesmo que [COM_INTERFACE_ENTRY2](#com_interface_entry2), exceto que você pode especificar um IID diferente.|
|[COM_INTERFACE_ENTRY_AGGREGATE](#com_interface_entry_aggregate)|Quando a interface identificada por *IID* é consultada, `COM_INTERFACE_ENTRY_AGGREGATE` encaminha para `punk`.|
|[COM_INTERFACE_ENTRY_AGGREGATE_BLIND](#com_interface_entry_aggregate_blind)|O mesmo que [COM_INTERFACE_ENTRY_AGGREGATE](#com_interface_entry_aggregate), exceto que a consulta de qualquer IID resulta no encaminhamento da consulta para *punk*.|
|[COM_INTERFACE_ENTRY_AUTOAGGREGATE](#com_interface_entry_autoaggregate)|O mesmo que [COM_INTERFACE_ENTRY_AGGREGATE](#com_interface_entry_aggregate), exceto se *punk* for NULL, ele criará automaticamente a agregação descrita pelo *CLSID*.|
|[COM_INTERFACE_ENTRY_AUTOAGGREGATE_BLIND](#com_interface_entry_autoaggregate_blind)|O mesmo que [COM_INTERFACE_ENTRY_AUTOAGGREGATE](#com_interface_entry_autoaggregate), exceto que a consulta de qualquer IID resulta em encaminhar a consulta para *punk*e, se *punk* for NULL, criar automaticamente a agregação descrita pelo *CLSID*.|
|[COM_INTERFACE_ENTRY_BREAK](#com_interface_entry_break)|Faz com que o seu programa chame [DebugBreak](/windows/win32/api/debugapi/nf-debugapi-debugbreak) quando a interface especificada for consultada.|
|[COM_INTERFACE_ENTRY_CACHED_TEAR_OFF](#com_interface_entry_cached_tear_off)|Salva os dados específicos da interface para cada instância.|
|[COM_INTERFACE_ENTRY_TEAR_OFF](#com_interface_entry_tear_off)|Expõe suas interfaces destacáveis.|
|[COM_INTERFACE_ENTRY_CHAIN](#com_interface_entry_chain)|Processa o mapa COM da classe base quando o processamento atinge essa entrada no mapa COM.|
|[COM_INTERFACE_ENTRY_FUNC](#com_interface_entry_func)|Um mecanismo geral para conectar-se à lógica de `QueryInterface` da ATL.|
|[COM_INTERFACE_ENTRY_FUNC_BLIND](#com_interface_entry_func_blind)|O mesmo que [COM_INTERFACE_ENTRY_FUNC](#com_interface_entry_func), exceto que a consulta de qualquer IID resulta em uma chamada para *Func*.|
|[COM_INTERFACE_ENTRY_NOINTERFACE](#com_interface_entry_nointerface)|Retorna E_NOINTERFACE e termina o processamento de mapa COM quando a interface especificada é consultada.|

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** atlcom. h

## <a name="com_interface_entry"></a>COM_INTERFACE_ENTRY

Insere interfaces no mapa de interface COM.

### <a name="syntax"></a>Sintaxe

```
COM_INTERFACE_ENTRY( x )
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
no O nome de uma interface à qual seu objeto de classe deriva diretamente.

### <a name="remarks"></a>Comentários

Normalmente, esse é o tipo de entrada usado com mais frequência.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

```cpp
BEGIN_COM_MAP(CThisExample)
   COM_INTERFACE_ENTRY(IThisExample)
   COM_INTERFACE_ENTRY(IDispatch)
   COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()
```

### <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** atlcom. h

##  <a name="com_interface_entry2"></a>COM_INTERFACE_ENTRY2

Use esta macro para desambiguar duas ramificações de herança.

```
COM_INTERFACE_ENTRY2(x, x2)
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
no O nome de uma interface que você deseja expor do seu objeto.

*X2*<br/>
no O nome da ramificação de herança da qual *x* é exposto.

### <a name="remarks"></a>Comentários

Por exemplo, se você derivar o objeto de classe de duas interfaces duplas, exporá `IDispatch` usando COM_INTERFACE_ENTRY2, já que `IDispatch` pode ser obtido em qualquer uma das interfaces.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_ATL_Windowing#118](../../atl/codesnippet/cpp/com-map-macros_2.h)]

##  <a name="com_interface_entry_iid"></a>COM_INTERFACE_ENTRY_IID

Use essa macro para inserir a interface no mapa COM e especificar seu IID.

```
COM_INTERFACE_ENTRY_IID(iid, x)
```

### <a name="parameters"></a>Parâmetros

*IID*<br/>
no O GUID da interface exposta.

*x*<br/>
no O nome da classe cujo vtable será exposto como a interface identificada por *IID*.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_ATL_Windowing#117](../../atl/codesnippet/cpp/com-map-macros_3.h)]

##  <a name="com_interface_entry2_iid"></a>COM_INTERFACE_ENTRY2_IID

O mesmo que [COM_INTERFACE_ENTRY2](#com_interface_entry2), exceto que você pode especificar um IID diferente.

```
COM_INTERFACE_ENTRY2_IID(iid, x, x2)
```

### <a name="parameters"></a>Parâmetros

*IID*<br/>
no O GUID que você está especificando para a interface.

*x*<br/>
no O nome de uma interface da qual seu objeto de classe deriva diretamente.

*X2*<br/>
no O nome de uma segunda interface da qual seu objeto de classe deriva diretamente.

##  <a name="com_interface_entry_aggregate"></a>COM_INTERFACE_ENTRY_AGGREGATE

Quando a interface identificada por *IID* é consultada, COM_INTERFACE_ENTRY_AGGREGATE encaminha para *punk*.

```
COM_INTERFACE_ENTRY_AGGREGATE(iid, punk)
```

### <a name="parameters"></a>Parâmetros

*IID*<br/>
no O GUID da interface consultada.

*punk*<br/>
no O nome de um ponteiro de `IUnknown`.

### <a name="remarks"></a>Comentários

O parâmetro *punk* é considerado para apontar para o desconhecido interno de uma agregação ou para NULL; nesse caso, a entrada é ignorada. Normalmente, você `CoCreate` a agregação em `FinalConstruct`.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_ATL_Windowing#112](../../atl/codesnippet/cpp/com-map-macros_4.h)]

##  <a name="com_interface_entry_aggregate_blind"></a>COM_INTERFACE_ENTRY_AGGREGATE_BLIND

O mesmo que [COM_INTERFACE_ENTRY_AGGREGATE](#com_interface_entry_aggregate), exceto que a consulta de qualquer IID resulta no encaminhamento da consulta para *punk*.

```
COM_INTERFACE_ENTRY_AGGREGATE_BLIND(punk)
```

### <a name="parameters"></a>Parâmetros

*punk*<br/>
no O nome de um ponteiro de `IUnknown`.

### <a name="remarks"></a>Comentários

Se a consulta de interface falhar, o processamento do mapa COM continuará.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_ATL_Windowing#113](../../atl/codesnippet/cpp/com-map-macros_5.h)]

##  <a name="com_interface_entry_autoaggregate"></a>COM_INTERFACE_ENTRY_AUTOAGGREGATE

O mesmo que [COM_INTERFACE_ENTRY_AGGREGATE](#com_interface_entry_aggregate), exceto se *punk* for NULL, ele criará automaticamente a agregação descrita pelo *CLSID*.

```
COM_INTERFACE_ENTRY_AUTOAGGREGATE(iid, punk, clsid)
```

### <a name="parameters"></a>Parâmetros

*IID*<br/>
no O GUID da interface consultada.

*punk*<br/>
no O nome de um ponteiro de `IUnknown`. Deve ser um membro da classe que contém o mapa COM.

*CLSID*<br/>
no O identificador da agregação que será criada se *punk* for NULL.

### <a name="remarks"></a>Comentários

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_ATL_Windowing#114](../../atl/codesnippet/cpp/com-map-macros_6.h)]

##  <a name="com_interface_entry_autoaggregate_blind"></a>COM_INTERFACE_ENTRY_AUTOAGGREGATE_BLIND

O mesmo que [COM_INTERFACE_ENTRY_AUTOAGGREGATE](#com_interface_entry_autoaggregate), exceto que a consulta de qualquer IID resulta em encaminhar a consulta para *punk*e, se *punk* for NULL, criar automaticamente a agregação descrita pelo *CLSID*.

```
COM_INTERFACE_ENTRY_AUTOAGGREGATE_BLIND(punk, clsid)
```

### <a name="parameters"></a>Parâmetros

*punk*<br/>
no O nome de um ponteiro de `IUnknown`. Deve ser um membro da classe que contém o mapa COM.

*CLSID*<br/>
no O identificador da agregação que será criada se *punk* for NULL.

### <a name="remarks"></a>Comentários

Se a consulta de interface falhar, o processamento do mapa COM continuará.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_ATL_Windowing#115](../../atl/codesnippet/cpp/com-map-macros_7.h)]

##  <a name="com_interface_entry_break"></a>COM_INTERFACE_ENTRY_BREAK

Faz com que o seu programa chame [DebugBreak](/windows/win32/api/debugapi/nf-debugapi-debugbreak) quando a interface especificada for consultada.

```
COM_INTERFACE_ENTRY_BREAK(x)
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
no Texto usado para construir o identificador de interface.

### <a name="remarks"></a>Comentários

A interface IID será construída acrescentando *x* ao `IID_`. Por exemplo, se *x* for `IPersistStorage`, o IID será `IID_IPersistStorage`.

##  <a name="com_interface_entry_cached_tear_off"></a>COM_INTERFACE_ENTRY_CACHED_TEAR_OFF

Salva os dados específicos da interface para cada instância.

```
COM_INTERFACE_ENTRY_CACHED_TEAR_OFF(iid, x, punk)
```

### <a name="parameters"></a>Parâmetros

*IID*<br/>
no O GUID da interface de divisão.

*x*<br/>
no O nome da classe que implementa a interface.

*punk*<br/>
no O nome de um ponteiro de `IUnknown`. Deve ser um membro da classe que contém o mapa COM. Deve ser inicializado como nulo no construtor do objeto de classe.

### <a name="remarks"></a>Comentários

Se a interface não for usada, isso reduzirá o tamanho geral da instância do objeto.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_ATL_COM#54](../../atl/codesnippet/cpp/com-map-macros_8.h)]

##  <a name="com_interface_entry_tear_off"></a>COM_INTERFACE_ENTRY_TEAR_OFF

Expõe suas interfaces destacáveis.

```
COM_INTERFACE_ENTRY_TEAR_OFF(iid, x)
```

### <a name="parameters"></a>Parâmetros

*IID*<br/>
no O GUID da interface de divisão.

*x*<br/>
no O nome da classe que implementa a interface.

### <a name="remarks"></a>Comentários

Uma interface retirada é implementada como um objeto separado que é instanciado toda vez que a interface que ela representa é consultada. Normalmente, você cria sua interface como uma remontagem se a interface raramente é usada, pois isso salva um ponteiro vtable em cada instância do seu objeto principal. A redivisão é excluída quando sua contagem de referência se torna zero. A classe que implementa a divisão deve ser derivada de `CComTearOffObjectBase` e ter seu próprio mapa COM.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_ATL_COM#1](../../atl/codesnippet/cpp/com-map-macros_1.h)]

##  <a name="com_interface_entry_chain"></a>COM_INTERFACE_ENTRY_CHAIN

Processa o mapa COM da classe base quando o processamento atinge essa entrada no mapa COM.

```
COM_INTERFACE_ENTRY_CHAIN(classname)
```

### <a name="parameters"></a>Parâmetros

*classname*<br/>
no Uma classe base do objeto atual.

### <a name="remarks"></a>Comentários

Por exemplo, no código a seguir:

[!code-cpp[NVC_ATL_Windowing#116](../../atl/codesnippet/cpp/com-map-macros_9.h)]

Observe que a primeira entrada no mapa COM deve ser uma interface no objeto que contém o mapa COM. Portanto, você não pode iniciar suas entradas de mapa com COM_INTERFACE_ENTRY_CHAIN, o que faz com que o mapa COM de um objeto diferente seja pesquisado no ponto em que **COM_INTERFACE_ENTRY_CHAIN (** `COtherObject` **)** aparece no mapa com do objeto. Se você quiser pesquisar o mapa COM de outro objeto primeiro, adicione uma entrada de interface para `IUnknown` ao seu mapa de COM e, em seguida, associe o mapa COM do outro objeto. Por exemplo:

[!code-cpp[NVC_ATL_Windowing#111](../../atl/codesnippet/cpp/com-map-macros_10.h)]

##  <a name="com_interface_entry_func"></a>COM_INTERFACE_ENTRY_FUNC

Um mecanismo geral para conectar-se à lógica de `QueryInterface` da ATL.

```
COM_INTERFACE_ENTRY_FUNC(iid, dw, func)
```

### <a name="parameters"></a>Parâmetros

*IID*<br/>
no O GUID da interface exposta.

*dw*<br/>
no Um parâmetro passado para o *Func*.

*func*<br/>
no O ponteiro de função que retornará *IID*.

### <a name="remarks"></a>Comentários

Se *IID* corresponder ao IID da interface consultada, a função especificada por *Func* será chamada. A declaração para a função deve ser:

`HRESULT WINAPI func(void* pv, REFIID riid, LPVOID* ppv, DWORD_PTR dw);`

Quando sua função é chamada, `pv` aponta para o seu objeto de classe. O parâmetro *riid* refere-se à interface que está sendo consultada, `ppv` é o ponteiro para o local em que a função deve armazenar o ponteiro para a interface e o *DW* é o parâmetro especificado na entrada. A função deve definir \* `ppv` como nulo e retornar E_NOINTERFACE ou S_FALSE se optar por não retornar uma interface. Com E_NOINTERFACE, o processamento de mapa COM é encerrado. Com S_FALSE, o processamento de mapa COM continua, embora nenhum ponteiro de interface seja retornado. Se a função retornar um ponteiro de interface, ela deverá retornar S_OK.

##  <a name="com_interface_entry_func_blind"></a>COM_INTERFACE_ENTRY_FUNC_BLIND

O mesmo que [COM_INTERFACE_ENTRY_FUNC](#com_interface_entry_func), exceto que a consulta de qualquer IID resulta em uma chamada para *Func*.

```
COM_INTERFACE_ENTRY_FUNC_BLIND(dw, func)
```

### <a name="parameters"></a>Parâmetros

*dw*<br/>
no Um parâmetro passado para o *Func*.

*func*<br/>
no A função que é chamada quando essa entrada no mapa COM é processada.

### <a name="remarks"></a>Comentários

Qualquer falha fará com que o processamento continue no mapa COM. Se a função retornar um ponteiro de interface, ela deverá retornar S_OK.

##  <a name="com_interface_entry_nointerface"></a>COM_INTERFACE_ENTRY_NOINTERFACE

Retorna E_NOINTERFACE e termina o processamento de mapa COM quando a interface especificada é consultada.

```
COM_INTERFACE_ENTRY_NOINTERFACE(x)
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
no Texto usado para construir o identificador de interface.

### <a name="remarks"></a>Comentários

Você pode usar essa macro para impedir que uma interface seja usada em um caso específico. Por exemplo, você pode inserir essa macro em seu mapa de COM logo antes de COM_INTERFACE_ENTRY_AGGREGATE_BLIND para impedir que uma consulta para a interface seja encaminhada para o desconhecido interno da agregação.

A interface IID será construída acrescentando *x* ao `IID_`. Por exemplo, se *x* for `IPersistStorage`, o IID será `IID_IPersistStorage`.
