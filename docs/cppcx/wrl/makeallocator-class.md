---
title: Classe MakeAllocator
ms.date: 10/03/2018
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::MakeAllocator
- implements/Microsoft::WRL::Details::MakeAllocator::Allocate
- implements/Microsoft::WRL::Details::MakeAllocator::Detach
- implements/Microsoft::WRL::Details::MakeAllocator::MakeAllocator
- implements/Microsoft::WRL::Details::MakeAllocator::~MakeAllocator
helpviewer_keywords:
- Microsoft::WRL::Details::MakeAllocator class
- Microsoft::WRL::Details::MakeAllocator::Allocate method
- Microsoft::WRL::Details::MakeAllocator::Detach method
- Microsoft::WRL::Details::MakeAllocator::MakeAllocator, constructor
- Microsoft::WRL::Details::MakeAllocator::~MakeAllocator, destructor
ms.assetid: a1114615-abd7-4a56-9bc3-750c118f0fa1
ms.openlocfilehash: 19d3ab294df8adc059424c97e5733ae9ebb75c9c
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87218371"
---
# <a name="makeallocator-class"></a>Classe MakeAllocator

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
template<
    typename T,
    bool hasWeakReferenceSupport =
          !__is_base_of(RuntimeClassFlags<InhibitWeakReference>,
                        T)
>
class MakeAllocator;

template<typename T>
class MakeAllocator<T, false>;

template<typename T>
class MakeAllocator<T, true>;
```

### <a name="parameters"></a>parâmetros

*T*<br/>
O nome de um tipo.

*hasWeakReferenceSupport*<br/>
**`true`** para alocar memória para um objeto que dá suporte a referências fracas; **`false`** para alocar memória para um objeto que não dá suporte a referências fracas.

## <a name="remarks"></a>Comentários

Aloca memória para uma classe ativável, com ou sem suporte de referência fraca.

Substitua a `MakeAllocator` classe para implementar um modelo de alocação de memória definido pelo usuário.

`MakeAllocator`normalmente é usado para evitar vazamentos de memória se um objeto for acionado durante a construção.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

Nome                                                  | Descrição
----------------------------------------------------- | ----------------------------------------------------------------
[MakeAllocator::MakeAllocator](#makeallocator)        | Inicializa uma nova instância da classe `MakeAllocator`.
[MakeAllocator:: ~ MakeAllocator](#tilde-makeallocator) | Desinicializa a instância atual da `MakeAllocator` classe.

### <a name="public-methods"></a>Métodos públicos

Nome                                 | Descrição
------------------------------------ | -----------------------------------------------------------------------------------------------------------
[MakeAllocator:: Allocate](#allocate) | Aloca memória e a associa ao `MakeAllocator` objeto atual.
[MakeAllocator::D Etach](#detach)     | Desassocia a memória alocada pelo método [ALLOCATE](#allocate) do objeto atual `MakeAllocator` .

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`MakeAllocator`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft:: WRL::D etalhes

## <a name="makeallocatorallocate"></a><a name="allocate"></a>MakeAllocator:: Allocate

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
__forceinline void* Allocate();
```

### <a name="return-value"></a>Valor retornado

Se for bem-sucedido, um ponteiro para a memória alocada; caso contrário, **`nullptr`** .

### <a name="remarks"></a>Comentários

Aloca memória e a associa ao `MakeAllocator` objeto atual.

O tamanho da memória alocada é o tamanho do tipo especificado pelo `MakeAllocator` parâmetro de modelo atual.

Um desenvolvedor precisa substituir apenas o `Allocate()` método para implementar um modelo de alocação de memória diferente.

## <a name="makeallocatordetach"></a><a name="detach"></a>MakeAllocator::D Etach

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
__forceinline void Detach();
```

### <a name="remarks"></a>Comentários

Desassocia a memória alocada pelo método [ALLOCATE](#allocate) do objeto atual `MakeAllocator` .

Se você chamar `Detach()` , será responsável por excluir a memória fornecida pelo `Allocate` método.

## <a name="makeallocatormakeallocator"></a><a name="makeallocator"></a>MakeAllocator::MakeAllocator

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
MakeAllocator();
```

### <a name="remarks"></a>Comentários

Inicializa uma nova instância da classe `MakeAllocator`.

## <a name="makeallocatormakeallocator"></a><a name="tilde-makeallocator"></a>MakeAllocator:: ~ MakeAllocator

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
~MakeAllocator();
```

### <a name="remarks"></a>Comentários

Desinicializa a instância atual da `MakeAllocator` classe.

Esse destruidor também exclui a memória alocada subjacente, se necessário.
