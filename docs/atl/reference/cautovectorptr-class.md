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
ms.openlocfilehash: 8485f13b91c72d12c2084d2714f2acfa6dda7f01
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50478749"
---
# <a name="cautovectorptr-class"></a>Classe CAutoVectorPtr

Essa classe representa um objeto de ponteiro inteligente usando o vetor novo e excluir operadores.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template<typename T>
class CAutoVectorPtr
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de ponteiro.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CAutoVectorPtr::CAutoVectorPtr](#cautovectorptr)|O construtor.|
|[CAutoVectorPtr:: ~ CAutoVectorPtr](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAutoVectorPtr::Allocate](#allocate)|Chame esse método para alocar a memória necessária para a matriz de objetos apontados por `CAutoVectorPtr`.|
|[CAutoVectorPtr::Attach](#attach)|Chame esse método para apropriar-se de um ponteiro existente.|
|[CAutoVectorPtr::Detach](#detach)|Chame esse método para liberar a propriedade de um ponteiro.|
|[CAutoVectorPtr::Free](#free)|Chame esse método para excluir um objeto apontado por um `CAutoVectorPtr`.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAutoVectorPtr::operator T *](#operator_t__star)|O operador cast.|
|[CAutoVectorPtr::operator =](#operator_eq)|O operador de atribuição.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CAutoVectorPtr::m_p](#m_p)|A variável de membro de dados de ponteiro.|

## <a name="remarks"></a>Comentários

Essa classe fornece métodos para criar e gerenciar um ponteiro inteligente, o que ajudará a proteger contra vazamentos de memória por meio de liberação de recursos automaticamente quando ele sai do escopo. `CAutoVectorPtr` é semelhante à `CAutoPtr`, a única diferença sendo que `CAutoVectorPtr` usa [vetor novo&#91; &#93; ](../../standard-library/new-operators.md#op_new_arr) e [exclusão de vetor&#91; &#93; ](../../standard-library/new-operators.md#op_delete_arr) para alocar e liberar memória em vez do C++ **novos** e **excluir** operadores. Ver [CAutoVectorPtrElementTraits](../../atl/reference/cautovectorptrelementtraits-class.md) se as classes de coleção de `CAutoVectorPtr` são necessários.

Ver [CAutoPtr](../../atl/reference/cautoptr-class.md) para obter um exemplo do uso de uma classe de ponteiro inteligente.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

##  <a name="allocate"></a>  CAutoVectorPtr::Allocate

Chame esse método para alocar a memória necessária para a matriz de objetos apontados por `CAutoVectorPtr`.

```
bool Allocate(size_t nElements) throw();
```

### <a name="parameters"></a>Parâmetros

*nElements*<br/>
O número de elementos na matriz.

### <a name="return-value"></a>Valor de retorno

Retornará true se a memória com êxito é alocado, falso em caso de falha.

### <a name="remarks"></a>Comentários

Em compilações de depuração, uma falha de asserção ocorrerá se o [CAutoVectorPtr::m_p](#m_p) variável de membro atualmente aponta para um valor existente; ou seja, não é igual a NULL.

##  <a name="attach"></a>  CAutoVectorPtr::Attach

Chame esse método para apropriar-se de um ponteiro existente.

```
void Attach(T* p) throw();
```

### <a name="parameters"></a>Parâmetros

*p*<br/>
O `CAutoVectorPtr` objeto assumirá a propriedade do ponteiro this.

### <a name="remarks"></a>Comentários

Quando um `CAutoVectorPtr` objeto assume a propriedade de um ponteiro, ele automaticamente excluirá o ponteiro e todos os dados alocados quando ele sai do escopo. Se [CAutoVectorPtr::Detach](#detach) é chamado, o programador é novamente determinado responsabilidade por liberar quaisquer recursos alocado.

Em compilações de depuração, uma falha de asserção ocorrerá se o [CAutoVectorPtr::m_p](#m_p) variável de membro atualmente aponta para um valor existente; ou seja, não é igual a NULL.

##  <a name="cautovectorptr"></a>  CAutoVectorPtr::CAutoVectorPtr

O construtor.

```
CAutoVectorPtr() throw();
explicit CAutoVectorPtr(T* p) throw();
CAutoVectorPtr(CAutoVectorPtr<T>& p) throw();
```

### <a name="parameters"></a>Parâmetros

*p*<br/>
Um ponteiro existente.

### <a name="remarks"></a>Comentários

O `CAutoVectorPtr` objeto pode ser criado usando um ponteiro existente, caso em que ele transfere a propriedade do ponteiro.

##  <a name="dtor"></a>  CAutoVectorPtr:: ~ CAutoVectorPtr

O destruidor.

```
~CAutoVectorPtr() throw();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados. Chamadas [CAutoVectorPtr::Free](#free).

##  <a name="detach"></a>  CAutoVectorPtr::Detach

Chame esse método para liberar a propriedade de um ponteiro.

```
T* Detach() throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna uma cópia do ponteiro.

### <a name="remarks"></a>Comentários

Libera a propriedade de um ponteiro, define o [CAutoVectorPtr::m_p](#m_p) variável de membro para NULL e retorna uma cópia do ponteiro. Depois de chamar `Detach`, ele é responsabilidade do programador para liberar todos recursos alocado ao longo do qual o `CAutoVectorPtr` objeto pode ter anteriormente assumiram a responsabilidade.

##  <a name="free"></a>  CAutoVectorPtr::Free

Chame esse método para excluir um objeto apontado por um `CAutoVectorPtr`.

```
void Free() throw();
```

### <a name="remarks"></a>Comentários

O objeto apontado pela `CAutoVectorPtr` é liberado e o [CAutoVectorPtr::m_p](#m_p) variável de membro é definido como NULL.

##  <a name="m_p"></a>  CAutoVectorPtr::m_p

A variável de membro de dados de ponteiro.

```
T* m_p;
```

### <a name="remarks"></a>Comentários

Essa variável de membro contém as informações de ponteiro.

##  <a name="operator_eq"></a>  CAutoVectorPtr::operator =

O operador de atribuição.

```
CAutoVectorPtr<T>& operator= (CAutoVectorPtr<T>& p) throw();
```

### <a name="parameters"></a>Parâmetros

*p*<br/>
Um ponteiro.

### <a name="return-value"></a>Valor de retorno

Retorna uma referência a um **CAutoVectorPtr\< T >**.

### <a name="remarks"></a>Comentários

O operador de atribuição desanexa o `CAutoVectorPtr` objeto a partir de qualquer ponteiro atual e anexa o novo ponteiro, *p*, em seu lugar.

##  <a name="operator_t__star"></a>  CAutoVectorPtr::operator T *

O operador cast.

```
operator T*() const throw();
```

### <a name="remarks"></a>Comentários

Retorna um ponteiro para o tipo de dados de objeto definido no modelo de classe.

## <a name="see-also"></a>Consulte também

[Classe CAutoPtr](../../atl/reference/cautoptr-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
