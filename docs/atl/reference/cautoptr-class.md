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
ms.openlocfilehash: 2fa6eb26c2e2cd569d74c02d8303768b1aeb4f1c
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81748264"
---
# <a name="cautoptr-class"></a>Classe CAutoPtr

Esta classe representa um objeto de ponteiro inteligente.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template <typename T>
class CAutoPtr
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de ponteiro.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAutoPtr::CAutoPtr](#cautoptr)|O construtor.|
|[CAutoPtr::~CAutoPtr](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAutoPtr::Anexar](#attach)|Chame este método para tomar posse de um ponteiro existente.|
|[CAutoPtr::Detach](#detach)|Chame este método para liberar a propriedade de um ponteiro.|
|[CAutoPtr::Grátis](#free)|Chame este método para excluir um `CAutoPtr`objeto apontado por um .|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAutoPtr::operador T*](#operator_t_star)|O operador de elenco.|
|[CAutoPtr::operador =](#operator_eq)|O operador de atribuição.|
|[CAutoPtr::operador ->](#operator_ptr)|O operador de ponteiro para membro.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CAutoPtr::m_p](#m_p)|A variável membro de dados do ponteiro.|

## <a name="remarks"></a>Comentários

Esta classe fornece métodos para criar e gerenciar um ponteiro inteligente, que ajudará a proteger contra vazamentos de memória, liberando automaticamente recursos quando ele cai fora do escopo.

Além `CAutoPtr`disso, o construtor de cópias e o operador de atribuição transferem a propriedade do ponteiro, copiando o ponteiro de origem para o ponteiro de destino e definindo o ponteiro de origem para NULL. Portanto, é impossível ter `CAutoPtr` dois objetos cada um armazenando o mesmo ponteiro, e isso reduz a possibilidade de excluir o mesmo ponteiro duas vezes.

`CAutoPtr`também simplifica a criação de coleções de ponteiros. Em vez de derivar uma classe de coleção e sobrepor o destruidor, `CAutoPtr` é mais simples fazer uma coleção de objetos. Quando a coleção é `CAutoPtr` excluída, os objetos sairão do escopo e se excluirão automaticamente.

[CHeapPtr](../../atl/reference/cheapptr-class.md) e variantes funcionam da `CAutoPtr`mesma forma que , exceto que eles alocam e memória livre usando diferentes funções de pilha em vez dos operadores **c++ novos** e **exclusão.** [CAutoVectorPtr](../../atl/reference/cautovectorptr-class.md) é `CAutoPtr`semelhante a , a única diferença é que ele usa **vetor novo[]** e **vetores delete[]** para alocar e memória livre.

Veja também [CAutoPtrArray](../../atl/reference/cautoptrarray-class.md) e [CAutoPtrList](../../atl/reference/cautoptrlist-class.md) quando são necessários arrays ou listas de ponteiros inteligentes.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase.h

## <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#74](../../atl/codesnippet/cpp/cautoptr-class_1.cpp)]

## <a name="cautoptrattach"></a><a name="attach"></a>CAutoPtr::Anexar

Chame este método para tomar posse de um ponteiro existente.

```cpp
void Attach(T* p) throw();
```

### <a name="parameters"></a>Parâmetros

*P*<br/>
O `CAutoPtr` objeto tomará posse deste ponteiro.

### <a name="remarks"></a>Comentários

Quando `CAutoPtr` um objeto toma posse de um ponteiro, ele excluirá automaticamente o ponteiro e quaisquer dados alocados quando ele sair do escopo. Se [o CAutoPtr::Detach](#detach) for chamado, o programador será novamente responsabilizado pela liberação de quaisquer recursos alocados.

Nas compilações de depuração, uma falha de afirmação ocorrerá se o membro de dados [CAutoPtr::m_p](#m_p) atualmente aponta para um valor existente; ou seja, não é igual a NULL.

### <a name="example"></a>Exemplo

Veja o exemplo na visão geral do [CAutoPtr](../../atl/reference/cautoptr-class.md).

## <a name="cautoptrcautoptr"></a><a name="cautoptr"></a>CAutoPtr::CAutoPtr

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

*P*<br/>
Um ponteiro existente.

*TSrc*<br/>
O tipo que está `CAutoPtr`sendo gerenciado por outro , usado para inicializar o objeto atual.

### <a name="remarks"></a>Comentários

O `CAutoPtr` objeto pode ser criado usando um ponteiro existente, nesse caso ele transfere a propriedade do ponteiro.

### <a name="example"></a>Exemplo

Veja o exemplo na visão geral do [CAutoPtr](../../atl/reference/cautoptr-class.md).

## <a name="cautoptrcautoptr"></a><a name="dtor"></a>CAutoPtr::~CAutoPtr

O destruidor.

```
~CAutoPtr() throw();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados. Chama [CAutoPtr:::Grátis](#free).

## <a name="cautoptrdetach"></a><a name="detach"></a>CAutoPtr::Detach

Chame este método para liberar a propriedade de um ponteiro.

```
T* Detach() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna uma cópia do ponteiro.

### <a name="remarks"></a>Comentários

Libera a propriedade de um ponteiro, define a variável [CAutoPtr::m_p](#m_p) membro de dados para NULL e retorna uma cópia do ponteiro. Após `Detach`a chamada, cabe ao programador liberar todos os `CAutoPtr` recursos alocados sobre os quais o objeto pode ter assumido anteriormente a reponsibilidade.

### <a name="example"></a>Exemplo

Veja o exemplo na visão geral do [CAutoPtr](../../atl/reference/cautoptr-class.md).

## <a name="cautoptrfree"></a><a name="free"></a>CAutoPtr::Grátis

Chame este método para excluir um `CAutoPtr`objeto apontado por um .

```cpp
void Free() throw();
```

### <a name="remarks"></a>Comentários

O objeto apontado `CAutoPtr` pelo é liberado e a variável membro de dados [CAutoPtr::m_p](#m_p) está definida como NULL.

## <a name="cautoptrm_p"></a><a name="m_p"></a>CAutoPtr::m_p

A variável membro de dados do ponteiro.

```
T* m_p;
```

### <a name="remarks"></a>Comentários

Esta variável de membro contém as informações do ponteiro.

## <a name="cautoptroperator-"></a><a name="operator_eq"></a>CAutoPtr::operador =

O operador de atribuição.

```
template<>
CAutoPtr<T>& operator= (CAutoPtr<T>& p);

template<typename TSrc>
CAutoPtr<T>& operator= (CAutoPtr<TSrc>& p);
```

### <a name="parameters"></a>Parâmetros

*P*<br/>
Um ponteiro.

*TSrc*<br/>
Um tipo de classe.

### <a name="return-value"></a>Valor retornado

Retorna uma referência a um **CAutoPtr\< T >**.

### <a name="remarks"></a>Comentários

O operador de atribuição destaca o `CAutoPtr` objeto de qualquer ponteiro atual e anexa o novo ponteiro, *p*, em seu lugar.

### <a name="example"></a>Exemplo

Veja o exemplo na visão geral do [CAutoPtr](../../atl/reference/cautoptr-class.md).

## <a name="cautoptroperator--gt"></a><a name="operator_ptr"></a>CAutoPtr::operador -&gt;

O operador de ponteiro para membro.

```
T* operator->() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o valor da variável [CAutoPtr::m_p](#m_p) membro de dados.

### <a name="remarks"></a>Comentários

Use este operador para chamar um método `CAutoPtr` em uma classe apontada pelo objeto. Nas compilações de depuração, uma `CAutoPtr` falha de afirmação ocorrerá se os pontos para NULL.

### <a name="example"></a>Exemplo

Veja o exemplo na visão geral do [CAutoPtr](../../atl/reference/cautoptr-class.md).

## <a name="cautoptroperator-t"></a><a name="operator_t_star"></a>CAutoPtr::operador T*

O operador de elenco.

```
operator T* () const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna um ponteiro para o tipo de dados do objeto definido no modelo de classe.

### <a name="example"></a>Exemplo

Veja o exemplo na visão geral do [CAutoPtr](../../atl/reference/cautoptr-class.md).

## <a name="see-also"></a>Confira também

[Classe CHeapPtr](../../atl/reference/cheapptr-class.md)<br/>
[Classe CAutoVectorPtr](../../atl/reference/cautovectorptr-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
