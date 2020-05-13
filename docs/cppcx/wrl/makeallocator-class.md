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
ms.openlocfilehash: dc0d83f2550646572a4eff2bec7850037c6dbf6a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371331"
---
# <a name="makeallocator-class"></a>Classe MakeAllocator

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

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

### <a name="parameters"></a>Parâmetros

*T*<br/>
O nome de um tipo.

*hasWeakReferenceSupport*<br/>
**fiel** a alocar memória para um objeto que suporta referências fracas; **falsa** para alocar memória para um objeto que não suporta referências fracas.

## <a name="remarks"></a>Comentários

Aloca memória para uma classe ativa, com ou sem suporte de referência fraco.

Substituir a `MakeAllocator` classe para implementar um modelo de alocação de memória definido pelo usuário.

`MakeAllocator`é normalmente usado para evitar vazamentos de memória se um objeto for arremessado durante a construção.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

Nome                                                  | Descrição
----------------------------------------------------- | ----------------------------------------------------------------
[MakeAllocator::MakeAllocator](#makeallocator)        | Inicia uma nova instância da classe `MakeAllocator`.
[MakeAllocator::~MakeAllocator](#tilde-makeallocator) | Desinicializa a instância `MakeAllocator` atual da classe.

### <a name="public-methods"></a>Métodos públicos

Nome                                 | Descrição
------------------------------------ | -----------------------------------------------------------------------------------------------------------
[MakeAllocateor::Alocar](#allocate) | Aloca a memória e associa-a ao objeto atual. `MakeAllocator`
[MakeAllocator::Detach](#detach)     | Desassocia a memória alocada pelo `MakeAllocator` método [Alocar](#allocate) a partir do objeto atual.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`MakeAllocator`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** implements.h

**Espaço de nome:** Microsoft::WRL::Details

## <a name="makeallocatorallocate"></a><a name="allocate"></a>MakeAllocateor::Alocar

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
__forceinline void* Allocate();
```

### <a name="return-value"></a>Valor retornado

Se for bem sucedido, um ponteiro para a memória alocada; caso contrário, `nullptr`.

### <a name="remarks"></a>Comentários

Aloca a memória e associa-a ao objeto atual. `MakeAllocator`

O tamanho da memória alocada é o tamanho do `MakeAllocator` tipo especificado pelo parâmetro de modelo atual.

Um desenvolvedor precisa substituir `Allocate()` apenas o método para implementar um modelo diferente de alocação de memória.

## <a name="makeallocatordetach"></a><a name="detach"></a>MakeAllocator::Detach

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
__forceinline void Detach();
```

### <a name="remarks"></a>Comentários

Desassocia a memória alocada pelo `MakeAllocator` método [Alocar](#allocate) a partir do objeto atual.

Se você `Detach()`ligar, você é responsável pela exclusão da memória fornecida pelo `Allocate` método.

## <a name="makeallocatormakeallocator"></a><a name="makeallocator"></a>MakeAllocator::MakeAllocator

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
MakeAllocator();
```

### <a name="remarks"></a>Comentários

Inicia uma nova instância da classe `MakeAllocator`.

## <a name="makeallocatormakeallocator"></a><a name="tilde-makeallocator"></a>MakeAllocator::~MakeAllocator

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
~MakeAllocator();
```

### <a name="remarks"></a>Comentários

Desinicializa a instância `MakeAllocator` atual da classe.

Este destruidor também exclui a memória alocada subjacente, se necessário.
