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
ms.openlocfilehash: fc4bd4ba7a2f41a25679f1da718671f525519708
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81748221"
---
# <a name="cautovectorptr-class"></a>Classe CAutoVectorPtr

Esta classe representa um objeto de ponteiro inteligente usando operadores vetoriais novos e exclua.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template<typename T>
class CAutoVectorPtr
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de ponteiro.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAutoVectorPtr::CAutoVectorPtr](#cautovectorptr)|O construtor.|
|[CAutoVectorPtr::~CAutoVectorPtr](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAutoVectorTr::Alocar](#allocate)|Chame este método para alocar a memória necessária `CAutoVectorPtr`pela matriz de objetos apontados por .|
|[CAutoVectorPtr::Anexar](#attach)|Chame este método para tomar posse de um ponteiro existente.|
|[CAutoVectorPtr::Detach](#detach)|Chame este método para liberar a propriedade de um ponteiro.|
|[CAutoVectorPtr::Grátis](#free)|Chame este método para excluir um `CAutoVectorPtr`objeto apontado por um .|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAutoVectorPtr::operador T *](#operator_t__star)|O operador de elenco.|
|[CAutoVectorPtr::operador =](#operator_eq)|O operador de atribuição.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CAutoVectorPtr::m_p](#m_p)|A variável membro de dados do ponteiro.|

## <a name="remarks"></a>Comentários

Esta classe fornece métodos para criar e gerenciar um ponteiro inteligente, que ajudará a proteger contra vazamentos de memória, liberando automaticamente recursos quando ele cai fora do escopo. `CAutoVectorPtr`é semelhante, `CAutoPtr`a única `CAutoVectorPtr` diferença é que usa [novo vetor&#91;&#93;](../../standard-library/new-operators.md#op_new_arr) e [vetores excluem&#91;&#93;](../../standard-library/new-operators.md#op_delete_arr) para alocar e liberar a memória em vez dos operadores **c++ novos** e **exclusão.** Consulte [CAutoVectorPtrElementTraits](../../atl/reference/cautovectorptrelementtraits-class.md) se `CAutoVectorPtr` forem necessárias classes de coleta.

Consulte [CAutoPtr](../../atl/reference/cautoptr-class.md) para obter um exemplo de uso de uma classe de ponteiro inteligente.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase.h

## <a name="cautovectorptrallocate"></a><a name="allocate"></a>CAutoVectorTr::Alocar

Chame este método para alocar a memória necessária `CAutoVectorPtr`pela matriz de objetos apontados por .

```
bool Allocate(size_t nElements) throw();
```

### <a name="parameters"></a>Parâmetros

*nElementos*<br/>
O número de elementos na matriz.

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro se a memória for alocada com sucesso, falsa na falha.

### <a name="remarks"></a>Comentários

Nas compilações de depuração, uma falha de afirmação ocorrerá se a variável de membro [CAutoVectorPtr::m_p](#m_p) atualmente aponta para um valor existente; ou seja, não é igual a NULL.

## <a name="cautovectorptrattach"></a><a name="attach"></a>CAutoVectorPtr::Anexar

Chame este método para tomar posse de um ponteiro existente.

```cpp
void Attach(T* p) throw();
```

### <a name="parameters"></a>Parâmetros

*P*<br/>
O `CAutoVectorPtr` objeto tomará posse deste ponteiro.

### <a name="remarks"></a>Comentários

Quando `CAutoVectorPtr` um objeto toma posse de um ponteiro, ele excluirá automaticamente o ponteiro e quaisquer dados alocados quando ele sair do escopo. Se [o CAutoVectorPtr::Detach](#detach) for chamado, o programador será novamente responsável pela liberação de quaisquer recursos alocados.

Nas compilações de depuração, uma falha de afirmação ocorrerá se a variável de membro [CAutoVectorPtr::m_p](#m_p) atualmente aponta para um valor existente; ou seja, não é igual a NULL.

## <a name="cautovectorptrcautovectorptr"></a><a name="cautovectorptr"></a>CAutoVectorPtr::CAutoVectorPtr

O construtor.

```
CAutoVectorPtr() throw();
explicit CAutoVectorPtr(T* p) throw();
CAutoVectorPtr(CAutoVectorPtr<T>& p) throw();
```

### <a name="parameters"></a>Parâmetros

*P*<br/>
Um ponteiro existente.

### <a name="remarks"></a>Comentários

O `CAutoVectorPtr` objeto pode ser criado usando um ponteiro existente, nesse caso ele transfere a propriedade do ponteiro.

## <a name="cautovectorptrcautovectorptr"></a><a name="dtor"></a>CAutoVectorPtr::~CAutoVectorPtr

O destruidor.

```
~CAutoVectorPtr() throw();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados. Chama [CAutoVectorPtr::Grátis](#free).

## <a name="cautovectorptrdetach"></a><a name="detach"></a>CAutoVectorPtr::Detach

Chame este método para liberar a propriedade de um ponteiro.

```
T* Detach() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna uma cópia do ponteiro.

### <a name="remarks"></a>Comentários

Libera a propriedade de um ponteiro, define a variável de membro [CAutoVectorPtr::m_p](#m_p) para NULL e retorna uma cópia do ponteiro. Após `Detach`a chamada, cabe ao programador liberar todos os `CAutoVectorPtr` recursos alocados sobre os quais o objeto pode ter assumido anteriormente a responsabilidade.

## <a name="cautovectorptrfree"></a><a name="free"></a>CAutoVectorPtr::Grátis

Chame este método para excluir um `CAutoVectorPtr`objeto apontado por um .

```cpp
void Free() throw();
```

### <a name="remarks"></a>Comentários

O objeto apontado `CAutoVectorPtr` pelo é liberado e a variável de membro [CAutoVectorPtr::m_p](#m_p) está definida como NULL.

## <a name="cautovectorptrm_p"></a><a name="m_p"></a>CAutoVectorPtr::m_p

A variável membro de dados do ponteiro.

```
T* m_p;
```

### <a name="remarks"></a>Comentários

Esta variável de membro contém as informações do ponteiro.

## <a name="cautovectorptroperator-"></a><a name="operator_eq"></a>CAutoVectorPtr::operador =

O operador de atribuição.

```
CAutoVectorPtr<T>& operator= (CAutoVectorPtr<T>& p) throw();
```

### <a name="parameters"></a>Parâmetros

*P*<br/>
Um ponteiro.

### <a name="return-value"></a>Valor retornado

Retorna uma referência a um **>\< CAutoVectorPtr T **.

### <a name="remarks"></a>Comentários

O operador de atribuição destaca o `CAutoVectorPtr` objeto de qualquer ponteiro atual e anexa o novo ponteiro, *p*, em seu lugar.

## <a name="cautovectorptroperator-t-"></a><a name="operator_t__star"></a>CAutoVectorPtr::operador T *

O operador de elenco.

```
operator T*() const throw();
```

### <a name="remarks"></a>Comentários

Retorna um ponteiro para o tipo de dados do objeto definido no modelo de classe.

## <a name="see-also"></a>Confira também

[Classe CAutoPtr](../../atl/reference/cautoptr-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
