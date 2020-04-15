---
title: Classe WeakReference
ms.date: 09/24/2018
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::WeakReference
- implements/Microsoft::WRL::Details::WeakReference::DecrementStrongReference
- implements/Microsoft::WRL::Details::WeakReference::IncrementStrongReference
- implements/Microsoft::WRL::Details::WeakReference::Resolve
- implements/Microsoft::WRL::Details::WeakReference::SetUnknown
- implements/Microsoft::WRL::Details::WeakReference::~WeakReference
- implements/Microsoft::WRL::Details::WeakReference::WeakReference
helpviewer_keywords:
- Microsoft::WRL::Details::WeakReference class
- Microsoft::WRL::Details::WeakReference::DecrementStrongReference method
- Microsoft::WRL::Details::WeakReference::IncrementStrongReference method
- Microsoft::WRL::Details::WeakReference::Resolve method
- Microsoft::WRL::Details::WeakReference::SetUnknown method
- Microsoft::WRL::Details::WeakReference::~WeakReference, destructor
- Microsoft::WRL::Details::WeakReference::WeakReference, constructor
ms.assetid: 3f4c956b-dbbd-49b1-8cfa-9509a9956c97
ms.openlocfilehash: a80c0ec14da2a955a95ac84dd3975212ef20ae04
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81374215"
---
# <a name="weakreference-class"></a>Classe WeakReference

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
class WeakReference;
```

## <a name="remarks"></a>Comentários

Representa uma *referência fraca* que pode ser usada com o Windows Runtime ou com clássico. Uma referência fraca representa um objeto que pode ou não ser acessível.

Um `WeakReference` objeto mantém uma *forte referência*, que é um ponteiro para um objeto, e uma *forte contagem*de referência , que é o número de cópias da forte referência que foram distribuídas pelo `Resolve()` método. Embora a forte contagem de referências não seja zero, a forte referência é válida e o objeto é acessível. Quando a forte contagem de referênciase zero, a forte referência é inválida e o objeto é inacessível.

Um `WeakReference` objeto é normalmente usado para representar um objeto cuja existência é controlada por um segmento ou aplicativo externo. Por exemplo, `WeakReference` construa um objeto a partir de uma referência a um objeto de arquivo. Enquanto o arquivo estiver aberto, a referência forte é válida. Mas se o arquivo for fechado, a forte referência se torna inválida.

Os `WeakReference` métodos são seguros para rosca.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

Nome                                                  | Descrição
----------------------------------------------------- | ---------------------------------------------------------------------------
[Referência fraca::Referência fraca](#weakreference)        | Inicia uma nova instância da classe `WeakReference`.
[Referência fraca::~Referência fraca](#tilde-weakreference) | Desinicializa (destrói) a instância `WeakReference` atual da classe.

### <a name="public-methods"></a>Métodos públicos

Nome                                                                 | Descrição
-------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------
[Referência fraca::DecrementStrongReference](#decrementstrongreference) | Decreta a forte contagem de `WeakReference` referência do objeto atual.
[Referência fraca::IncrementStrongReference](#incrementstrongreference) | Incrementa a forte contagem `WeakReference` de referência do objeto atual.
[Referência fraca::Resolver](#resolve)                                   | Define o ponteiro especificado para o valor de referência forte atual se a contagem de referência forte não for zero.
[Referência fraca::setUnknown](#setunknown)                             | Define a referência forte `WeakReference` do objeto atual ao ponteiro de interface especificado.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`WeakReference`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** implements.h

**Espaço de nome:** Microsoft::WRL::Details

## <a name="weakreferenceweakreference"></a><a name="tilde-weakreference"></a>Referência fraca::~Referência fraca

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
virtual ~WeakReference();
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

Desinicializa a instância `WeakReference` atual da classe.

## <a name="weakreferencedecrementstrongreference"></a><a name="decrementstrongreference"></a>Referência fraca::DecrementStrongReference

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
ULONG DecrementStrongReference();
```

### <a name="remarks"></a>Comentários

Decreta a forte contagem de `WeakReference` referência do objeto atual.

Quando a forte contagem de referênciase `nullptr`zero, a forte referência é definida como .

### <a name="return-value"></a>Valor retornado

A forte contagem de referências decretadas.

## <a name="weakreferenceincrementstrongreference"></a><a name="incrementstrongreference"></a>Referência fraca::IncrementStrongReference

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
ULONG IncrementStrongReference();
```

### <a name="return-value"></a>Valor retornado

A contagem de referências incrementada.

### <a name="remarks"></a>Comentários

Incrementa a forte contagem `WeakReference` de referência do objeto atual.

## <a name="weakreferenceresolve"></a><a name="resolve"></a>Referência fraca::Resolver

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
STDMETHOD(Resolve)
   (REFIID riid,
   _Deref_out_opt_ IInspectable **ppvObject
);
```

### <a name="parameters"></a>Parâmetros

*riid*<br/>
Um ID de interface.

*Ppvobject*<br/>
Quando esta operação for concluída, uma cópia da referência forte atual se a forte contagem de referência não for zero.

### <a name="return-value"></a>Valor retornado

- S_OK se esta operação for bem sucedida e a forte contagem de referências for zero. O parâmetro *ppvObject* está `nullptr`definido como .

- S_OK se esta operação for bem sucedida e a forte contagem de referências não for zero. O parâmetro *ppvObject* é definido como uma referência forte.

- Caso contrário, um HRESULT que indica a razão pela qual esta operação falhou.

### <a name="remarks"></a>Comentários

Define o ponteiro especificado para o valor de referência forte atual se a contagem de referência forte não for zero.

## <a name="weakreferencesetunknown"></a><a name="setunknown"></a>Referência fraca::setUnknown

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
void SetUnknown(
   _In_ IUnknown* unk
);
```

### <a name="parameters"></a>Parâmetros

*unk*<br/>
Um ponteiro `IUnknown` para a interface de um objeto.

### <a name="remarks"></a>Comentários

Define a referência forte `WeakReference` do objeto atual ao ponteiro de interface especificado.

## <a name="weakreferenceweakreference"></a><a name="weakreference"></a>Referência fraca::Referência fraca

Suporta a infra-estrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
WeakReference();
```

### <a name="remarks"></a>Comentários

Inicia uma nova instância da classe `WeakReference`.

O ponteiro de `WeakReference` referência forte para `nullptr`o objeto é inicializado para , e a forte contagem de referência é inicializada para 1.
