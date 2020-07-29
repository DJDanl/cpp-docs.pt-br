---
title: Classe CAutoVectorPtr
ms.date: 11/04/2016
f1_keywords:
- CAutoVectorPtr
- ATLBASE/ATL::CAutoVectorPtr
- ATLBASE/ATL::CAutoVectorPtr::CAutoVectorPtr
- ATLBASE/ATL::CAutoVectorPtr::Allocate
- ATLBASE/ATL::CAutoVectorPtr::Attach
- ATLBASE/ATL::CAutoVectorPtr::Detach
- ATLBASE/ATL::CAutoVectorPtr::Free
- ATLBASE/ATL::CAutoVectorPtr::m_p
helpviewer_keywords:
- CAutoVectorPtr class
ms.assetid: 0030362b-6bc4-4a47-9b5b-3c3899dceab4
ms.openlocfilehash: 65d37396b02d2c11c758915b201eef09cf1935b5
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87226640"
---
# <a name="cautovectorptr-class"></a>Classe CAutoVectorPtr

Essa classe representa um objeto de ponteiro inteligente usando operadores New e Delete de vetor.

> [!IMPORTANT]
> Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```
template<typename T>
class CAutoVectorPtr
```

#### <a name="parameters"></a>parâmetros

*T*<br/>
O tipo de ponteiro.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAutoVectorPtr::CAutoVectorPtr](#cautovectorptr)|O construtor.|
|[CAutoVectorPtr:: ~ CAutoVectorPtr](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAutoVectorPtr:: Allocate](#allocate)|Chame esse método para alocar a memória exigida pela matriz de objetos apontada pelo `CAutoVectorPtr` .|
|[CAutoVectorPtr:: Attach](#attach)|Chame esse método para apropriar-se de um ponteiro existente.|
|[CAutoVectorPtr::D Etach](#detach)|Chame esse método para liberar a propriedade de um ponteiro.|
|[CAutoVectorPtr:: Free](#free)|Chame esse método para excluir um objeto apontado por um `CAutoVectorPtr` .|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAutoVectorPtr:: Operator T *](#operator_t__star)|O operador cast.|
|[CAutoVectorPtr:: Operator =](#operator_eq)|O operador de atribuição.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CAutoVectorPtr:: m_p](#m_p)|A variável de membro de dados do ponteiro.|

## <a name="remarks"></a>Comentários

Essa classe fornece métodos para criar e gerenciar um ponteiro inteligente, o que ajudará a proteger contra vazamentos de memória liberando automaticamente os recursos quando ele estiver fora do escopo. `CAutoVectorPtr`é semelhante a `CAutoPtr` , a única diferença que `CAutoVectorPtr` usa [vetor New&#91;&#93;](../../standard-library/new-operators.md#op_new_arr) e [vetor Delete&#91;&#93;](../../standard-library/new-operators.md#op_delete_arr) para alocar e liberar memória em vez de C++ **`new`** e **`delete`** operadores. Consulte [CAutoVectorPtrElementTraits](../../atl/reference/cautovectorptrelementtraits-class.md) se as classes de coleção de `CAutoVectorPtr` forem necessárias.

Consulte [CAutoPtr](../../atl/reference/cautoptr-class.md) para obter um exemplo de como usar uma classe de ponteiro inteligente.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

## <a name="cautovectorptrallocate"></a><a name="allocate"></a>CAutoVectorPtr:: Allocate

Chame esse método para alocar a memória exigida pela matriz de objetos apontada pelo `CAutoVectorPtr` .

```
bool Allocate(size_t nElements) throw();
```

### <a name="parameters"></a>parâmetros

*nElements*<br/>
O número de elementos na matriz.

### <a name="return-value"></a>Valor retornado

Retornará true se a memória for alocada com êxito, false em caso de falha.

### <a name="remarks"></a>Comentários

Em compilações de depuração, ocorrerá uma falha de asserção se a variável de membro [CAutoVectorPtr:: m_p](#m_p) apontar para um valor existente; ou seja, não é igual a NULL.

## <a name="cautovectorptrattach"></a><a name="attach"></a>CAutoVectorPtr:: Attach

Chame esse método para apropriar-se de um ponteiro existente.

```cpp
void Attach(T* p) throw();
```

### <a name="parameters"></a>parâmetros

*DTI*<br/>
O `CAutoVectorPtr` objeto assumirá a propriedade desse ponteiro.

### <a name="remarks"></a>Comentários

Quando um `CAutoVectorPtr` objeto apropria-se de um ponteiro, ele excluirá automaticamente o ponteiro e todos os dados alocados quando sair do escopo. Se [CAutoVectorPtr::D Etach](#detach) for chamado, o programador receberá novamente a responsabilidade de liberar todos os recursos alocados.

Em compilações de depuração, ocorrerá uma falha de asserção se a variável de membro [CAutoVectorPtr:: m_p](#m_p) apontar para um valor existente; ou seja, não é igual a NULL.

## <a name="cautovectorptrcautovectorptr"></a><a name="cautovectorptr"></a>CAutoVectorPtr::CAutoVectorPtr

O construtor.

```
CAutoVectorPtr() throw();
explicit CAutoVectorPtr(T* p) throw();
CAutoVectorPtr(CAutoVectorPtr<T>& p) throw();
```

### <a name="parameters"></a>parâmetros

*DTI*<br/>
Um ponteiro existente.

### <a name="remarks"></a>Comentários

O `CAutoVectorPtr` objeto pode ser criado usando um ponteiro existente; nesse caso, ele transfere a propriedade do ponteiro.

## <a name="cautovectorptrcautovectorptr"></a><a name="dtor"></a>CAutoVectorPtr:: ~ CAutoVectorPtr

O destruidor.

```
~CAutoVectorPtr() throw();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados. Chama [CAutoVectorPtr:: Free](#free).

## <a name="cautovectorptrdetach"></a><a name="detach"></a>CAutoVectorPtr::D Etach

Chame esse método para liberar a propriedade de um ponteiro.

```
T* Detach() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna uma cópia do ponteiro.

### <a name="remarks"></a>Comentários

Libera a propriedade de um ponteiro, define a variável de membro [CAutoVectorPtr:: m_p](#m_p) como NULL e retorna uma cópia do ponteiro. Depois `Detach` de chamar, cabe ao programador liberar todos os recursos alocados sobre os quais o `CAutoVectorPtr` objeto pode ter assumido a responsabilidade anteriormente.

## <a name="cautovectorptrfree"></a><a name="free"></a>CAutoVectorPtr:: Free

Chame esse método para excluir um objeto apontado por um `CAutoVectorPtr` .

```cpp
void Free() throw();
```

### <a name="remarks"></a>Comentários

O objeto apontado pelo `CAutoVectorPtr` é liberado e a variável de membro [CAutoVectorPtr:: m_p](#m_p) é definida como NULL.

## <a name="cautovectorptrm_p"></a><a name="m_p"></a>CAutoVectorPtr:: m_p

A variável de membro de dados do ponteiro.

```
T* m_p;
```

### <a name="remarks"></a>Comentários

Essa variável de membro contém as informações do ponteiro.

## <a name="cautovectorptroperator-"></a><a name="operator_eq"></a>CAutoVectorPtr:: Operator =

O operador de atribuição.

```
CAutoVectorPtr<T>& operator= (CAutoVectorPtr<T>& p) throw();
```

### <a name="parameters"></a>parâmetros

*DTI*<br/>
Um ponteiro.

### <a name="return-value"></a>Valor retornado

Retorna uma referência a um **CAutoVectorPtr \< T > **.

### <a name="remarks"></a>Comentários

O operador de atribuição desanexa o `CAutoVectorPtr` objeto de qualquer ponteiro atual e anexa o novo ponteiro, *p*, em seu lugar.

## <a name="cautovectorptroperator-t-"></a><a name="operator_t__star"></a>CAutoVectorPtr:: Operator T *

O operador cast.

```
operator T*() const throw();
```

### <a name="remarks"></a>Comentários

Retorna um ponteiro para o tipo de dados Object definido no modelo de classe.

## <a name="see-also"></a>Confira também

[Classe CAutoPtr](../../atl/reference/cautoptr-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
