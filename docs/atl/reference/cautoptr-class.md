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
ms.openlocfilehash: 7f4f446aa97f2bf3843b830bd7fb4c4a5d74ffdb
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57259783"
---
# <a name="cautoptr-class"></a>Classe CAutoPtr

Essa classe representa um objeto de ponteiro inteligente.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template <typename T>
class CAutoPtr
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de ponteiro.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CAutoPtr::CAutoPtr](#cautoptr)|O construtor.|
|[CAutoPtr::~CAutoPtr](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAutoPtr::Attach](#attach)|Chame esse método para apropriar-se de um ponteiro existente.|
|[CAutoPtr::Detach](#detach)|Chame esse método para liberar a propriedade de um ponteiro.|
|[CAutoPtr::Free](#free)|Chame esse método para excluir um objeto apontado por um `CAutoPtr`.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAutoPtr::operator T *](#operator_t_star)|O operador cast.|
|[CAutoPtr::operator =](#operator_eq)|O operador de atribuição.|
|[CAutoPtr::operator ->](#operator_ptr)|O operador de ponteiro para membro.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CAutoPtr::m_p](#m_p)|A variável de membro de dados de ponteiro.|

## <a name="remarks"></a>Comentários

Essa classe fornece métodos para criar e gerenciar um ponteiro inteligente, o que ajudará a proteger contra vazamentos de memória por meio de liberação de recursos automaticamente quando ele sai do escopo.

Além disso, `CAutoPtr`do construtor de cópia e a propriedade de transferência de operador de atribuição do ponteiro, copiando o ponteiro de origem para o ponteiro de destino e definir o ponteiro de origem como NULL. Portanto, é impossível ter dois `CAutoPtr` objetos cada armazenar o mesmo ponteiro, e isso reduz a possibilidade de excluir o mesmo ponteiro duas vezes.

`CAutoPtr` também simplifica a criação de coleções de ponteiros. Em vez de derivar uma classe de coleção e o destruidor de substituição, é mais simples de fazer uma coleção de `CAutoPtr` objetos. Quando a coleção é excluída, o `CAutoPtr` objetos serão saem do escopo e excluir automaticamente a próprio.

[CHeapPtr](../../atl/reference/cheapptr-class.md) e variantes funcionam da mesma forma como `CAutoPtr`, exceto que eles alocar e liberar memória usando funções diferentes de heap em vez do C++ **novos** e **excluir** operadores. [CAutoVectorPtr](../../atl/reference/cautovectorptr-class.md) é semelhante ao `CAutoPtr`, a única diferença é que ele usa **new [] de vetor** e **vetor delete []** para alocar e liberar memória.

Consulte também [CAutoPtrArray](../../atl/reference/cautoptrarray-class.md) e [CAutoPtrList](../../atl/reference/cautoptrlist-class.md) quando matrizes ou listas de ponteiros inteligentes são necessárias.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

## <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#74](../../atl/codesnippet/cpp/cautoptr-class_1.cpp)]

##  <a name="attach"></a>  CAutoPtr::Attach

Chame esse método para apropriar-se de um ponteiro existente.

```
void Attach(T* p) throw();
```

### <a name="parameters"></a>Parâmetros

*p*<br/>
O `CAutoPtr` objeto assumirá a propriedade do ponteiro this.

### <a name="remarks"></a>Comentários

Quando um `CAutoPtr` objeto assume a propriedade de um ponteiro, ele automaticamente excluirá o ponteiro e todos os dados alocados quando ele sai do escopo. Se [CAutoPtr::Detach](#detach) é chamado, o programador é novamente determinado responsabilidade por liberar quaisquer recursos alocado.

Em compilações de depuração, uma falha de asserção ocorrerá se o [CAutoPtr::m_p](#m_p) membro de dados atualmente aponta para um valor existente; ou seja, não é igual a NULL.

### <a name="example"></a>Exemplo

Consulte o exemplo a [visão geral de CAutoPtr](../../atl/reference/cautoptr-class.md).

##  <a name="cautoptr"></a>  CAutoPtr::CAutoPtr

O construtor.

```
CAutoPtr() throw();
explicit CAutoPtr(T* p) throw();

template<typename TSrc>
CAutoPtr(CAutoPtr<TSrc>& p) throw();

template<>
CAutoPtr(CAutoPtr<T>& p) throw();
```

### <a name="parameters"></a>Parâmetros

*p*<br/>
Um ponteiro existente.

*TSrc*<br/>
O tipo que está sendo gerenciado por outro `CAutoPtr`, usado para inicializar o objeto atual.

### <a name="remarks"></a>Comentários

O `CAutoPtr` objeto pode ser criado usando um ponteiro existente, caso em que ele transfere a propriedade do ponteiro.

### <a name="example"></a>Exemplo

Consulte o exemplo a [visão geral de CAutoPtr](../../atl/reference/cautoptr-class.md).

##  <a name="dtor"></a>  CAutoPtr::~CAutoPtr

O destruidor.

```
~CAutoPtr() throw();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados. Chamadas [CAutoPtr::Free](#free).

##  <a name="detach"></a>  CAutoPtr::Detach

Chame esse método para liberar a propriedade de um ponteiro.

```
T* Detach() throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna uma cópia do ponteiro.

### <a name="remarks"></a>Comentários

Libera a propriedade de um ponteiro, define o [CAutoPtr::m_p](#m_p) variável de membro de dados como NULL e retorna uma cópia do ponteiro. Depois de chamar `Detach`, ele é responsabilidade do programador para liberar todos recursos alocado ao longo do qual o `CAutoPtr` objeto pode ter anteriormente achado reponsibility.

### <a name="example"></a>Exemplo

Consulte o exemplo a [visão geral de CAutoPtr](../../atl/reference/cautoptr-class.md).

##  <a name="free"></a>  CAutoPtr::Free

Chame esse método para excluir um objeto apontado por um `CAutoPtr`.

```
void Free() throw();
```

### <a name="remarks"></a>Comentários

O objeto apontado pela `CAutoPtr` é liberado e o [CAutoPtr::m_p](#m_p) variável de membro de dados é definido como NULL.

##  <a name="m_p"></a>  CAutoPtr::m_p

A variável de membro de dados de ponteiro.

```
T* m_p;
```

### <a name="remarks"></a>Comentários

Essa variável de membro contém as informações de ponteiro.

##  <a name="operator_eq"></a>  CAutoPtr::operator =

O operador de atribuição.

```
template<>
CAutoPtr<T>& operator= (CAutoPtr<T>& p);

template<typename TSrc>
CAutoPtr<T>& operator= (CAutoPtr<TSrc>& p);
```

### <a name="parameters"></a>Parâmetros

*p*<br/>
Um ponteiro.

*TSrc*<br/>
Um tipo de classe.

### <a name="return-value"></a>Valor de retorno

Retorna uma referência a um **CAutoPtr\< T >**.

### <a name="remarks"></a>Comentários

O operador de atribuição desanexa o `CAutoPtr` objeto a partir de qualquer ponteiro atual e anexa o novo ponteiro, *p*, em seu lugar.

### <a name="example"></a>Exemplo

Consulte o exemplo a [visão geral de CAutoPtr](../../atl/reference/cautoptr-class.md).

##  <a name="operator_ptr"></a>  CAutoPtr::operator-&gt;

O operador de ponteiro para membro.

```
T* operator->() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna o valor da [CAutoPtr::m_p](#m_p) variável de membro de dados.

### <a name="remarks"></a>Comentários

Use este operador para chamar um método em uma classe apontada pelo `CAutoPtr` objeto. Em compilações de depuração, uma falha de asserção ocorrerá se o `CAutoPtr` aponta para NULL.

### <a name="example"></a>Exemplo

Consulte o exemplo a [visão geral de CAutoPtr](../../atl/reference/cautoptr-class.md).

##  <a name="operator_t_star"></a>  CAutoPtr::operator T *

O operador cast.

```
operator T* () const throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna um ponteiro para o tipo de dados de objeto definido no modelo de classe.

### <a name="example"></a>Exemplo

Consulte o exemplo a [visão geral de CAutoPtr](../../atl/reference/cautoptr-class.md).

## <a name="see-also"></a>Consulte também

[Classe CHeapPtr](../../atl/reference/cheapptr-class.md)<br/>
[Classe CAutoVectorPtr](../../atl/reference/cautovectorptr-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
