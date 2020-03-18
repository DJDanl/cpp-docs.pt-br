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
ms.openlocfilehash: 740920225fc513a869b4a92344f87004831e4768
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79417876"
---
# <a name="ccomptrbase-class"></a>Classe CComPtrBase

Essa classe fornece uma base para classes de ponteiro inteligente usando rotinas de memória com base em COM.

## <a name="syntax"></a>Sintaxe

```
template <class T>
class CComPtrBase
```

#### <a name="parameters"></a>parâmetros

*T*<br/>
O tipo de objeto a ser referenciado pelo ponteiro inteligente.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CComPtrBase:: ~ CComPtrBase](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CComPtrBase:: Advise](#advise)|Chame esse método para criar uma conexão entre o ponto de conexão do `CComPtrBase`e o coletor de um cliente.|
|[CComPtrBase:: Attach](#attach)|Chame esse método para apropriar-se de um ponteiro existente.|
|[CComPtrBase:: CoCreateInstance](#cocreateinstance)|Chame esse método para criar um objeto da classe associada a uma ID de classe ou ID de programa especificada.|
|[CComPtrBase:: CopyTo](#copyto)|Chame esse método para copiar o ponteiro de `CComPtrBase` para outra variável de ponteiro.|
|[CComPtrBase::D Etach](#detach)|Chame esse método para liberar a propriedade de um ponteiro.|
|[CComPtrBase:: isequalobject](#isequalobject)|Chame esse método para verificar se o `IUnknown` especificado aponta para o mesmo objeto associado ao objeto `CComPtrBase`.|
|[CComPtrBase:: QueryInterface](#queryinterface)|Chame esse método para retornar um ponteiro para uma interface especificada.|
|[CComPtrBase:: versão](#release)|Chame esse método para liberar a interface.|
|[CComPtrBase:: SetSite](#setsite)|Chame esse método para definir o site do `CComPtrBase` objeto para a `IUnknown` do objeto pai.|

### <a name="public-operators"></a>Operadores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CComPtrBase:: Operator T *](#operator_t_star)|O operador cast.|
|[CComPtrBase:: Operator!](#operator_not)|O operador NOT.|
|[Operador CComPtrBase:: operator &](#operator_amp)|O operador de &.|
|[CComPtrBase:: Operator *](#operator_star)|O operador \*.|
|[Operador CComPtrBase:: Operator <](#ccomptrbase__operator lt)|O operador menor que.|
|[CComPtrBase:: Operator = =](#operator_eq_eq)|O operador de igualdade.|
|[CComPtrBase:: operator->](#operator_ptr)|O operador ponteiro-para-membros.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CComPtrBase::p](#p)|A variável de membro de dados do ponteiro.|

## <a name="remarks"></a>Comentários

Essa classe fornece a base para outros apontadores inteligentes que usam rotinas de gerenciamento de memória COM, como [CComQIPtr](../../atl/reference/ccomqiptr-class.md) e [CComPtr](../../atl/reference/ccomptr-class.md). As classes derivadas adicionam seus próprios construtores e operadores, mas contam com os métodos fornecidos pelo `CComPtrBase`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcomcli. h

##  <a name="advise"></a>CComPtrBase:: Advise

Chame esse método para criar uma conexão entre o ponto de conexão do `CComPtrBase`e o coletor de um cliente.

```
HRESULT Advise(
    IUnknown* pUnk,
    const IID& iid,
    LPDWORD pdw) throw();
```

### <a name="parameters"></a>parâmetros

*pUnk*<br/>
Um ponteiro para a `IUnknown`do cliente.

*IID*<br/>
O GUID do ponto de conexão. Normalmente, isso é o mesmo que a interface de saída gerenciada pelo ponto de conexão.

*PDW*<br/>
Um ponteiro para o cookie que identifica exclusivamente a conexão.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Consulte [AtlAdvise](connection-point-global-functions.md#atladvise) para obter mais informações.

##  <a name="attach"></a>CComPtrBase:: Attach

Chame esse método para apropriar-se de um ponteiro existente.

```
void Attach(T* p2) throw();
```

### <a name="parameters"></a>parâmetros

*P2*<br/>
O objeto `CComPtrBase` se apropriará desse ponteiro.

### <a name="remarks"></a>Comentários

`Attach` chama [CComPtrBase:: Release](#release) na variável de membro [CComPtrBase::p](#p) existente e, em seguida, atribui *P2* a `CComPtrBase::p`. Quando um objeto `CComPtrBase` apropria-se de um ponteiro, ele automaticamente chamará `Release` no ponteiro que excluirá o ponteiro e todos os dados alocados se a contagem de referência no objeto for para 0.

##  <a name="dtor"></a>CComPtrBase:: ~ CComPtrBase

O destruidor.

```
~CComPtrBase() throw();
```

### <a name="remarks"></a>Comentários

Libera a interface apontada por `CComPtrBase`.

##  <a name="cocreateinstance"></a>CComPtrBase:: CoCreateInstance

Chame esse método para criar um objeto da classe associada a uma ID de classe ou ID de programa especificada.

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

### <a name="parameters"></a>parâmetros

*szProgID*<br/>
Ponteiro para um ProgID, usado para recuperar o CLSID.

*pUnkOuter*<br/>
Se NULL, indica que o objeto não está sendo criado como parte de uma agregação. Se não for NULL, é um ponteiro para a interface de `IUnknown` do objeto de agregação (o `IUnknown`de controle).

*dwClsContext*<br/>
Contexto no qual o código que gerencia o objeto recém-criado será executado.

*rclsid*<br/>
CLSID associado aos dados e ao código que será usado para criar o objeto.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou REGDB_E_CLASSNOTREG, CLASS_E_NOAGGREGATION, CO_E_CLASSSTRING ou E_NOINTERFACE em caso de falha. Consulte [CoCreateClassInstance](/windows/win32/api/combaseapi/nf-combaseapi-cocreateinstance) e [CLSIDFromProgID](/windows/win32/api/combaseapi/nf-combaseapi-clsidfromprogid) para obter uma descrição desses erros.

### <a name="remarks"></a>Comentários

Se a primeira forma do método for chamada, [CLSIDFromProgID](/windows/win32/api/combaseapi/nf-combaseapi-clsidfromprogid) será usado para recuperar o CLSID. Em seguida, os dois formulários chamam [CoCreateClassInstance](/windows/win32/api/combaseapi/nf-combaseapi-cocreateinstance).

Em compilações de depuração, ocorrerá um erro de asserção se [CComPtrBase::p](#p) não for igual a NULL.

##  <a name="copyto"></a>CComPtrBase:: CopyTo

Chame esse método para copiar o ponteiro de `CComPtrBase` para outra variável de ponteiro.

```
HRESULT CopyTo(T** ppT) throw();
```

### <a name="parameters"></a>parâmetros

*Apresentação*<br/>
Endereço da variável que receberá o ponteiro de `CComPtrBase`.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito, E_POINTER em caso de falha.

### <a name="remarks"></a>Comentários

Copia o ponteiro de `CComPtrBase` para o *ppt*. A contagem de referência na variável de membro [CComPtrBase::p](#p) é incrementada.

Um erro HRESULT será retornado se o *ppt* for igual a NULL. Em compilações de depuração, ocorrerá um erro de asserção se o *ppt* for igual a nulo.

##  <a name="detach"></a>CComPtrBase::D Etach

Chame esse método para liberar a propriedade de um ponteiro.

```
T* Detach() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna uma cópia do ponteiro.

### <a name="remarks"></a>Comentários

Libera a propriedade de um ponteiro, define a variável de membro de dados [CComPtrBase::p](#p) como NULL e retorna uma cópia do ponteiro.

##  <a name="isequalobject"></a>CComPtrBase:: isequalobject

Chame esse método para verificar se o `IUnknown` especificado aponta para o mesmo objeto associado ao objeto `CComPtrBase`.

```
bool IsEqualObject(IUnknown* pOther) throw();
```

### <a name="parameters"></a>parâmetros

*pOther*<br/>
O `IUnknown *` a ser comparado.

### <a name="return-value"></a>Valor retornado

Retornará true se os objetos forem idênticos; caso contrário, false.

##  <a name="operator_not"></a>CComPtrBase:: Operator!

O operador NOT.

```
bool operator!() const throw();
```

### <a name="return-value"></a>Valor retornado

Retornará true se o ponteiro de `CComHeapPtr` for igual a NULL; caso contrário, false.

##  <a name="operator_amp"></a>Operador CComPtrBase:: Operator &amp;

O operador de &.

```
T** operator&() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o endereço do objeto apontado pelo objeto `CComPtrBase`.

##  <a name="operator_star"></a>Operador CComPtrBase:: Operator \*

O operador \*.

```
T& operator*() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o valor de [CComPtrBase::p](#p); ou seja, um ponteiro para o objeto referenciado pelo objeto `CComPtrBase`.

Se a depuração for compilada, ocorrerá um erro de asserção se [CComPtrBase::p](#p) não for igual a NULL.

##  <a name="operator_eq_eq"></a>CComPtrBase:: Operator = =

O operador de igualdade.

```
bool operator== (T* pT) const throw();
```

### <a name="parameters"></a>parâmetros

*pT*<br/>
Um ponteiro para um objeto.

### <a name="return-value"></a>Valor retornado

Retorna true se `CComPtrBase` e *pt* apontam para o mesmo objeto; caso contrário, false.

##  <a name="operator_ptr"></a>CComPtrBase:: Operator-&gt;

O operador ponteiro-para-membro.

```
_NoAddRefReleaseOnCComPtr<T>* operator->() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o valor da variável de membro de dados [CComPtrBase::p](#p) .

### <a name="remarks"></a>Comentários

Use este operador para chamar um método em uma classe apontada pelo objeto `CComPtrBase`. Em compilações de depuração, ocorrerá uma falha de asserção se o membro de dados `CComPtrBase` apontar para NULL.

##  <a name="operator_lt"></a>Operador CComPtrBase:: Operator &lt;

O operador menor que.

```
bool operator<(T* pT) const throw();
```

### <a name="parameters"></a>parâmetros

*pT*<br/>
Um ponteiro para um objeto.

### <a name="return-value"></a>Valor retornado

Retornará true se o ponteiro gerenciado pelo objeto atual for menor que o ponteiro ao qual ele está sendo comparado.

##  <a name="operator_t_star"></a>Operador CComPtrBase:: Operator T\*

O operador cast.

```
operator T*() const throw();
```

### <a name="remarks"></a>Comentários

Retorna um ponteiro para o tipo de dados Object definido no modelo de classe.

##  <a name="p"></a>CComPtrBase::p

A variável de membro de dados do ponteiro.

```
T* p;
```

### <a name="remarks"></a>Comentários

Essa variável de membro contém as informações do ponteiro.

##  <a name="queryinterface"></a>CComPtrBase:: QueryInterface

Chame esse método para retornar um ponteiro para uma interface especificada.

```
template <class Q> HRESULT QueryInterface(Q
** pp) const throw();
```

### <a name="parameters"></a>parâmetros

*Q*<br/>
O tipo de objeto cujo ponteiro de interface é necessário.

*PP*<br/>
Endereço da variável de saída que recebe o ponteiro de interface solicitado.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou E_NOINTERFACE em caso de falha.

### <a name="remarks"></a>Comentários

Este método chama [IUnknown:: QueryInterface](/windows/win32/api/unknwn/nf-unknwn-iunknown-queryinterface(q)).

Em compilações de depuração, ocorrerá um erro de asserção se *PP* não for igual a NULL.

##  <a name="release"></a>CComPtrBase:: versão

Chame esse método para liberar a interface.

```
void Release() throw();
```

### <a name="remarks"></a>Comentários

A interface é liberada e [CComPtrBase::p](#p) é definido como nulo.

##  <a name="setsite"></a>CComPtrBase:: SetSite

Chame esse método para definir o site do `CComPtrBase` objeto para a `IUnknown` do objeto pai.

```
HRESULT SetSite(IUnknown* punkParent) throw();
```

### <a name="parameters"></a>parâmetros

*punkParent*<br/>
Um ponteiro para a interface de `IUnknown` do pai.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Esse método chama [AtlSetChildSite](composite-control-global-functions.md#atlsetchildsite).

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)
