---
title: Classe CAutoPtr
ms.date: 11/04/2016
f1_keywords:
- CAutoPtr
- ATLBASE/ATL::CAutoPtr
- ATLBASE/ATL::CAutoPtr::CAutoPtr
- ATLBASE/ATL::CAutoPtr::Attach
- ATLBASE/ATL::CAutoPtr::Detach
- ATLBASE/ATL::CAutoPtr::Free
- ATLBASE/ATL::CAutoPtr::m_p
helpviewer_keywords:
- CAutoPtr class
ms.assetid: 08988d53-4fb0-4711-bdfc-8ac29c63f410
ms.openlocfilehash: 7f15e16b075b9a5327723a7f081100313f14ea77
ms.sourcegitcommit: 2bc15c5b36372ab01fa21e9bcf718fa22705814f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/27/2020
ms.locfileid: "82167715"
---
# <a name="cautoptr-class"></a>Classe CAutoPtr

Essa classe representa um objeto de ponteiro inteligente.

> [!IMPORTANT]
> Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```cpp
template <typename T>
class CAutoPtr
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de ponteiro.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAutoPtr::CAutoPtr](#cautoptr)|O construtor.|
|[CAutoPtr:: ~ CAutoPtr](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAutoPtr:: Attach](#attach)|Chame esse método para apropriar-se de um ponteiro existente.|
|[CAutoPtr::D Etach](#detach)|Chame esse método para liberar a propriedade de um ponteiro.|
|[CAutoPtr:: Free](#free)|Chame esse método para excluir um objeto apontado por um `CAutoPtr`.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAutoPtr:: Operator T *](#operator_t_star)|O operador cast.|
|[CAutoPtr:: Operator =](#operator_eq)|O operador de atribuição.|
|[CAutoPtr:: Operator->](#operator_ptr)|O operador ponteiro-para-membro.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CAutoPtr:: m_p](#m_p)|A variável de membro de dados do ponteiro.|

## <a name="remarks"></a>Comentários

Essa classe fornece métodos para criar e gerenciar um ponteiro inteligente, o que ajudará a proteger contra vazamentos de memória liberando automaticamente os recursos quando ele estiver fora do escopo.

Além disso `CAutoPtr`, o construtor de cópia e a propriedade de transferência do operador de atribuição do ponteiro, copiando o ponteiro de origem para o ponteiro de destino e definindo o ponteiro de origem como nulo. Portanto, é impossível ter dois `CAutoPtr` objetos cada um armazenando o mesmo ponteiro, e isso reduz a possibilidade de excluir o mesmo ponteiro duas vezes.

`CAutoPtr`também simplifica a criação de coleções de ponteiros. Em vez de derivar uma classe de coleção e substituir o destruidor, é mais simples criar uma coleção de `CAutoPtr` objetos. Quando a coleção é excluída, `CAutoPtr` os objetos saem do escopo e são excluídos automaticamente.

[CHeapPtr](../../atl/reference/cheapptr-class.md) e variantes funcionam da mesma maneira `CAutoPtr`, exceto pelo fato de alocar e liberar memória usando diferentes funções de heap em vez dos operadores **New** e **delete** do C++. [CAutoVectorPtr](../../atl/reference/cautovectorptr-class.md) é semelhante a `CAutoPtr`, a única diferença é que ele usa o **vetor New []** e a **exclusão de vetor []** para alocar e liberar memória.

Consulte também [CAutoPtrArray](../../atl/reference/cautoptrarray-class.md) e [CAutoPtrList](../../atl/reference/cautoptrlist-class.md) quando forem necessárias matrizes ou listas de ponteiros inteligentes.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

## <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#74](../../atl/codesnippet/cpp/cautoptr-class_1.cpp)]

## <a name="cautoptrattach"></a><a name="attach"></a>CAutoPtr:: Attach

Chame esse método para apropriar-se de um ponteiro existente.

```cpp
void Attach(T* p) throw();
```

### <a name="parameters"></a>Parâmetros

*DTI*<br/>
O `CAutoPtr` objeto assumirá a propriedade desse ponteiro.

### <a name="remarks"></a>Comentários

Quando um `CAutoPtr` objeto apropria-se de um ponteiro, ele excluirá automaticamente o ponteiro e todos os dados alocados quando sair do escopo. Se [CAutoPtr::D Etach](#detach) for chamado, o programador receberá novamente a responsabilidade de liberar todos os recursos alocados.

Em compilações de depuração, ocorrerá uma falha de asserção se o membro de dados [CAutoPtr:: m_p](#m_p) apontar para um valor existente, no momento. ou seja, não é igual a NULL.

### <a name="example"></a>Exemplo

Consulte o exemplo na [visão geral do CAutoPtr](../../atl/reference/cautoptr-class.md).

## <a name="cautoptrcautoptr"></a><a name="cautoptr"></a>CAutoPtr::CAutoPtr

O construtor.

```cpp
CAutoPtr() throw();
explicit CAutoPtr(T* p) throw();

template<typename TSrc>
CAutoPtr(CAutoPtr<TSrc>& p) throw();

template<>
CAutoPtr(CAutoPtr<T>& p) throw();
```

### <a name="parameters"></a>Parâmetros

*DTI*<br/>
Um ponteiro existente.

*TSrc*<br/>
O tipo que está sendo gerenciado `CAutoPtr`por outro, usado para inicializar o objeto atual.

### <a name="remarks"></a>Comentários

O `CAutoPtr` objeto pode ser criado usando um ponteiro existente; nesse caso, ele transfere a propriedade do ponteiro.

### <a name="example"></a>Exemplo

Consulte o exemplo na [visão geral do CAutoPtr](../../atl/reference/cautoptr-class.md).

## <a name="cautoptrcautoptr"></a><a name="dtor"></a>CAutoPtr:: ~ CAutoPtr

O destruidor.

```cpp
~CAutoPtr() throw();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados. Chama [CAutoPtr:: Free](#free).

## <a name="cautoptrdetach"></a><a name="detach"></a>CAutoPtr::D Etach

Chame esse método para liberar a propriedade de um ponteiro.

```cpp
T* Detach() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna uma cópia do ponteiro.

### <a name="remarks"></a>Comentários

Libera a propriedade de um ponteiro, define a variável de membro de dados [CAutoPtr:: m_p](#m_p) como NULL e retorna uma cópia do ponteiro. Depois de `Detach`chamar, cabe ao programador liberar todos os recursos alocados sobre os quais o `CAutoPtr` objeto pode ter assumido reponsibility anteriormente.

### <a name="example"></a>Exemplo

Consulte o exemplo na [visão geral do CAutoPtr](../../atl/reference/cautoptr-class.md).

## <a name="cautoptrfree"></a><a name="free"></a>CAutoPtr:: Free

Chame esse método para excluir um objeto apontado por um `CAutoPtr`.

```cpp
void Free() throw();
```

### <a name="remarks"></a>Comentários

O objeto apontado pelo `CAutoPtr` é liberado e a variável de membro de dados [CAutoPtr:: m_p](#m_p) é definida como NULL.

## <a name="cautoptrm_p"></a><a name="m_p"></a>CAutoPtr:: m_p

A variável de membro de dados do ponteiro.

```cpp
T* m_p;
```

### <a name="remarks"></a>Comentários

Essa variável de membro contém as informações do ponteiro.

## <a name="cautoptroperator-"></a><a name="operator_eq"></a>CAutoPtr:: Operator =

O operador de atribuição.

```cpp
template<>
CAutoPtr<T>& operator= (CAutoPtr<T>& p);

template<typename TSrc>
CAutoPtr<T>& operator= (CAutoPtr<TSrc>& p);
```

### <a name="parameters"></a>Parâmetros

*DTI*<br/>
Um ponteiro.

*TSrc*<br/>
Um tipo de classe.

### <a name="return-value"></a>Valor retornado

Retorna uma referência a um **>\< T CAutoPtr **.

### <a name="remarks"></a>Comentários

O operador de atribuição desanexa o `CAutoPtr` objeto de qualquer ponteiro atual e anexa o novo ponteiro, *p*, em seu lugar.

### <a name="example"></a>Exemplo

Consulte o exemplo na [visão geral do CAutoPtr](../../atl/reference/cautoptr-class.md).

## <a name="cautoptroperator--gt"></a><a name="operator_ptr"></a>Operador CAutoPtr:: Operator&gt;

O operador ponteiro-para-membro.

```cpp
T* operator->() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o valor da variável de membro de dados [CAutoPtr:: m_p](#m_p) .

### <a name="remarks"></a>Comentários

Use este operador para chamar um método em uma classe apontada pelo `CAutoPtr` objeto. Em compilações de depuração, ocorrerá uma falha de `CAutoPtr` asserção se os pontos forem nulos.

### <a name="example"></a>Exemplo

Consulte o exemplo na [visão geral do CAutoPtr](../../atl/reference/cautoptr-class.md).

## <a name="cautoptroperator-t"></a><a name="operator_t_star"></a>CAutoPtr:: Operator T *

O operador cast.

```cpp
operator T* () const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna um ponteiro para o tipo de dados Object definido no modelo de classe.

### <a name="example"></a>Exemplo

Consulte o exemplo na [visão geral do CAutoPtr](../../atl/reference/cautoptr-class.md).

## <a name="see-also"></a>Confira também

[Classe CHeapPtr](../../atl/reference/cheapptr-class.md)<br/>
[Classe CAutoVectorPtr](../../atl/reference/cautovectorptr-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
