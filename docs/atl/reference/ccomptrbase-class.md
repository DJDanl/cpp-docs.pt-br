---
title: Classe CComPtrBase
ms.date: 11/04/2016
f1_keywords:
- CComPtrBase
- ATLCOMCLI/ATL::CComPtrBase
- ATLCOMCLI/ATL::CComPtrBase::Advise
- ATLCOMCLI/ATL::CComPtrBase::Attach
- ATLCOMCLI/ATL::CComPtrBase::CoCreateInstance
- ATLCOMCLI/ATL::CComPtrBase::CopyTo
- ATLCOMCLI/ATL::CComPtrBase::Detach
- ATLCOMCLI/ATL::CComPtrBase::IsEqualObject
- ATLCOMCLI/ATL::CComPtrBase::QueryInterface
- ATLCOMCLI/ATL::CComPtrBase::Release
- ATLCOMCLI/ATL::CComPtrBase::SetSite
- ATLCOMCLI/ATL::CComPtrBase::p
helpviewer_keywords:
- CComPtrBase class
ms.assetid: 6dbe9543-dee8-4a97-b02f-dd3a25f4a1a0
ms.openlocfilehash: 9c62cc912b3fea3ea68390882bdda37cbfb25a7e
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81747764"
---
# <a name="ccomptrbase-class"></a>Classe CComPtrBase

Esta classe fornece uma base para classes de ponteirointeligentes usando rotinas de memória baseadas em COM.

## <a name="syntax"></a>Sintaxe

```
template <class T>
class CComPtrBase
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de objeto a ser referenciado pelo ponteiro inteligente.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CComPtrBase::~CComPtrBase](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComPtrBase::Aconselhar](#advise)|Chame esse método para criar `CComPtrBase`uma conexão entre o ponto de conexão e a pia de um cliente.|
|[CComPtrBase::Anexar](#attach)|Chame este método para tomar posse de um ponteiro existente.|
|[CComPtrBase::CoCreateInstance](#cocreateinstance)|Chame este método para criar um objeto da classe associado a um ID de classe ou ID do programa especificado.|
|[CComPtrBase::CopyTo](#copyto)|Chame este método `CComPtrBase` para copiar o ponteiro para outra variável de ponteiro.|
|[CComPtrBase::Detach](#detach)|Chame este método para liberar a propriedade de um ponteiro.|
|[CComPtrBase::IsEqualObject](#isequalobject)|Chame este método para verificar `IUnknown` se os pontos especificados apontam para o mesmo objeto associado ao `CComPtrBase` objeto.|
|[CComPtrBase::QueryInterface](#queryinterface)|Chame este método para retornar um ponteiro para uma interface especificada.|
|[CComPtrBase::Lançamento](#release)|Chame este método para liberar a interface.|
|[CComPtrBase::SetSite](#setsite)|Chame este método para definir `CComPtrBase` o `IUnknown` local do objeto para o objeto pai.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CComPtrBase::operador T*](#operator_t_star)|O operador de elenco.|
|[CComPtrBase::operador !](#operator_not)|O operador NOT.|
|[CComPtrBase::&do operador](#operator_amp)|O operador &.|
|[CComPtrBase::operador *](#operator_star)|O operador \*.|
|[CComPtrBase::<do operador](#ccomptrbase__operator lt)|O operador menos que o operador.|
|[CComPtrBase::operador ==](#operator_eq_eq)|O operador da igualdade.|
|[CComPtrBase::>](#operator_ptr)|O operador de ponteiro para membros.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComPtrBase::p](#p)|A variável membro de dados do ponteiro.|

## <a name="remarks"></a>Comentários

Esta classe fornece a base para outros ponteiros inteligentes que usam rotinas de gerenciamento de memória COM, como [CComQIPtr](../../atl/reference/ccomqiptr-class.md) e [CComPtr](../../atl/reference/ccomptr-class.md). As classes derivadas adicionam seus próprios construtores e operadores, `CComPtrBase`mas dependem dos métodos fornecidos por .

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcomcli.h

## <a name="ccomptrbaseadvise"></a><a name="advise"></a>CComPtrBase::Aconselhar

Chame esse método para criar `CComPtrBase`uma conexão entre o ponto de conexão e a pia de um cliente.

```
HRESULT Advise(
    IUnknown* pUnk,
    const IID& iid,
    LPDWORD pdw) throw();
```

### <a name="parameters"></a>Parâmetros

*Punk*<br/>
Um ponteiro para o `IUnknown`cliente.

*Iid*<br/>
O GUID do ponto de conexão. Normalmente, isso é o mesmo que a interface de saída gerenciada pelo ponto de conexão.

*Pdw*<br/>
Um ponteiro para o cookie que identifica exclusivamente a conexão.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Consulte [AtlAdvise](connection-point-global-functions.md#atladvise) para obter mais informações.

## <a name="ccomptrbaseattach"></a><a name="attach"></a>CComPtrBase::Anexar

Chame este método para tomar posse de um ponteiro existente.

```cpp
void Attach(T* p2) throw();
```

### <a name="parameters"></a>Parâmetros

*p2*<br/>
O `CComPtrBase` objeto tomará posse deste ponteiro.

### <a name="remarks"></a>Comentários

`Attach`chama [CComPtrBase::Lançamento](#release) na variável de membro [CComPtrBase::p](#p) existente `CComPtrBase::p`e, em seguida, atribui *p2* a . Quando `CComPtrBase` um objeto toma posse de um `Release` ponteiro, ele chamará automaticamente o ponteiro que excluirá o ponteiro e quaisquer dados alocados se a contagem de referência no objeto for para 0.

## <a name="ccomptrbaseccomptrbase"></a><a name="dtor"></a>CComPtrBase::~CComPtrBase

O destruidor.

```
~CComPtrBase() throw();
```

### <a name="remarks"></a>Comentários

Libera a interface apontada `CComPtrBase`por .

## <a name="ccomptrbasecocreateinstance"></a><a name="cocreateinstance"></a>CComPtrBase::CoCreateInstance

Chame este método para criar um objeto da classe associado a um ID de classe ou ID do programa especificado.

```
HRESULT CoCreateInstance(
    LPCOLESTR szProgID,
    LPUNKNOWN pUnkOuter = NULL,
    DWORD dwClsContext = CLSCTX_ALL) throw();

HRESULT CoCreateInstance(
    REFCLSID rclsid,
    LPUNKNOWN pUnkOuter = NULL,
    DWORD dwClsContext = CLSCTX_ALL) throw();
```

### <a name="parameters"></a>Parâmetros

*szProgID*<br/>
Ponteiro para um ProgID, usado para recuperar o CLSID.

*Punkouter*<br/>
Se NULL, indica que o objeto não está sendo criado como parte de um agregado. Se não-NULO, é um ponteiro `IUnknown` para a interface `IUnknown`do objeto agregado (o controle ).

*Dwclscontext*<br/>
Contexto em que o código que gerencia o objeto recém-criado será executado.

*Rclsid*<br/>
CLSID associado aos dados e códigos que serão usados para criar o objeto.

### <a name="return-value"></a>Valor retornado

O retorno S_OK no sucesso, ou REGDB_E_CLASSNOTREG, CLASS_E_NOAGGREGATION, CO_E_CLASSSTRING ou E_NOINTERFACE no fracasso. Consulte [CoCreateClassInstance](/windows/win32/api/combaseapi/nf-combaseapi-cocreateinstance) e [CLSIDFromProgID](/windows/win32/api/combaseapi/nf-combaseapi-clsidfromprogid) para obter uma descrição desses erros.

### <a name="remarks"></a>Comentários

Se a primeira forma do método for chamada, [CLSIDFromProgID](/windows/win32/api/combaseapi/nf-combaseapi-clsidfromprogid) é usado para recuperar o CLSID. Ambos os formulários então chamam [CoCreateClassInstance](/windows/win32/api/combaseapi/nf-combaseapi-cocreateinstance).

Nas compilações de depuração, um erro de afirmação ocorrerá se [CComPtrBase::p](#p) não for igual a NULL.

## <a name="ccomptrbasecopyto"></a><a name="copyto"></a>CComPtrBase::CopyTo

Chame este método `CComPtrBase` para copiar o ponteiro para outra variável de ponteiro.

```
HRESULT CopyTo(T** ppT) throw();
```

### <a name="parameters"></a>Parâmetros

*Ppt*<br/>
Endereço da variável que `CComPtrBase` receberá o ponteiro.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, E_POINTER no fracasso.

### <a name="remarks"></a>Comentários

Copia `CComPtrBase` o ponteiro para *ppT*. A contagem de referência na variável [membro CComPtrBase::p](#p) é incrementada.

Um erro HRESULT será devolvido se *ppT* for igual a NULL. Nas compilações de depuração, um erro de afirmação ocorrerá se *o ppT* for igual a NULL.

## <a name="ccomptrbasedetach"></a><a name="detach"></a>CComPtrBase::Detach

Chame este método para liberar a propriedade de um ponteiro.

```
T* Detach() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna uma cópia do ponteiro.

### <a name="remarks"></a>Comentários

Libera a propriedade de um ponteiro, define a variável [ccomptrBase::p](#p) membro de dados para NULL e retorna uma cópia do ponteiro.

## <a name="ccomptrbaseisequalobject"></a><a name="isequalobject"></a>CComPtrBase::IsEqualObject

Chame este método para verificar `IUnknown` se os pontos especificados apontam para o mesmo objeto associado ao `CComPtrBase` objeto.

```
bool IsEqualObject(IUnknown* pOther) throw();
```

### <a name="parameters"></a>Parâmetros

*Pother*<br/>
O `IUnknown *` a ser comparado.

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro se os objetos são idênticos, falso sé falso de outra forma.

## <a name="ccomptrbaseoperator-"></a><a name="operator_not"></a>CComPtrBase::operador !

O operador NOT.

```
bool operator!() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro `CComHeapPtr` se o ponteiro for igual a NULL, falso de outra forma.

## <a name="ccomptrbaseoperator-amp"></a><a name="operator_amp"></a>CComPtrBase::operador&amp;

O operador &.

```
T** operator&() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o endereço do objeto `CComPtrBase` apontado pelo objeto.

## <a name="ccomptrbaseoperator-"></a><a name="operator_star"></a>CComPtrBase::operador\*

O operador \*.

```
T& operator*() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o valor de [CComPtrBase::p;](#p) ou seja, um ponteiro para o `CComPtrBase` objeto referenciado pelo objeto.

Se a compilação de depuração ocorrer, um erro de afirmação ocorrerá se [CComPtrBase::p](#p) não for igual a NULL.

## <a name="ccomptrbaseoperator-"></a><a name="operator_eq_eq"></a>CComPtrBase::operador ==

O operador da igualdade.

```
bool operator== (T* pT) const throw();
```

### <a name="parameters"></a>Parâmetros

*pT*<br/>
Um ponteiro para um objeto.

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro `CComPtrBase` se e *pT* apontar para o mesmo objeto, falso de outra forma.

## <a name="ccomptrbaseoperator--gt"></a><a name="operator_ptr"></a>CComPtrBase::operador -&gt;

O operador de ponteiro para membro.

```
_NoAddRefReleaseOnCComPtr<T>* operator->() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o valor da variável [CComPtrBase::p](#p) membro de dados.

### <a name="remarks"></a>Comentários

Use este operador para chamar um método `CComPtrBase` em uma classe apontada pelo objeto. Nas compilações de depuração, uma `CComPtrBase` falha de afirmação ocorrerá se o membro de dados apontapara NULL.

## <a name="ccomptrbaseoperator-lt"></a><a name="operator_lt"></a>CComPtrBase::operador&lt;

O operador menos que o operador.

```
bool operator<(T* pT) const throw();
```

### <a name="parameters"></a>Parâmetros

*pT*<br/>
Um ponteiro para um objeto.

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro se o ponteiro gerenciado pelo objeto atual for menor do que o ponteiro ao qual está sendo comparado.

## <a name="ccomptrbaseoperator-t"></a><a name="operator_t_star"></a>CComPtrBase::operador T\*

O operador de elenco.

```
operator T*() const throw();
```

### <a name="remarks"></a>Comentários

Retorna um ponteiro para o tipo de dados do objeto definido no modelo de classe.

## <a name="ccomptrbasep"></a><a name="p"></a>CComPtrBase::p

A variável membro de dados do ponteiro.

```
T* p;
```

### <a name="remarks"></a>Comentários

Esta variável de membro contém as informações do ponteiro.

## <a name="ccomptrbasequeryinterface"></a><a name="queryinterface"></a>CComPtrBase::QueryInterface

Chame este método para retornar um ponteiro para uma interface especificada.

```
template <class Q> HRESULT QueryInterface(Q
** pp) const throw();
```

### <a name="parameters"></a>Parâmetros

*Q*<br/>
O tipo de objeto cujo ponteiro de interface é necessário.

*Pp*<br/>
Endereço da variável de saída que recebe o ponteiro de interface solicitado.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou E_NOINTERFACE no fracasso.

### <a name="remarks"></a>Comentários

Este método chama [iUnknown::QueryInterface](/windows/win32/api/unknwn/nf-unknwn-iunknown-queryinterface(q)).

Nas compilações de depuração, um erro de afirmação ocorrerá se *pp* não for igual a NULL.

## <a name="ccomptrbaserelease"></a><a name="release"></a>CComPtrBase::Lançamento

Chame este método para liberar a interface.

```cpp
void Release() throw();
```

### <a name="remarks"></a>Comentários

A interface foi liberada e [cComPtrBase::p](#p) está definida como NULL.

## <a name="ccomptrbasesetsite"></a><a name="setsite"></a>CComPtrBase::SetSite

Chame este método para definir `CComPtrBase` o `IUnknown` local do objeto para o objeto pai.

```
HRESULT SetSite(IUnknown* punkParent) throw();
```

### <a name="parameters"></a>Parâmetros

*punkParent*<br/>
Um ponteiro `IUnknown` para a interface do pai.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Este método chama [AtlSetChildSite](composite-control-global-functions.md#atlsetchildsite).

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)
