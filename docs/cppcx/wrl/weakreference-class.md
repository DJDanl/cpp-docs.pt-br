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
ms.openlocfilehash: 9a367a61a029abe1be599b1e262e279402149ccd
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87220451"
---
# <a name="weakreference-class"></a>Classe WeakReference

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
class WeakReference;
```

## <a name="remarks"></a>Comentários

Representa uma *referência fraca* que pode ser usada com o Windows Runtime ou o com clássico. Uma referência fraca representa um objeto que pode ou não estar acessível.

Um `WeakReference` objeto mantém uma *referência forte*, que é um ponteiro para um objeto e uma *contagem de referência forte*, que é o número de cópias da referência forte que foram distribuídas pelo `Resolve()` método. Embora a contagem de referência forte seja diferente de zero, a referência forte é válida e o objeto está acessível. Quando a contagem de referência forte se torna zero, a referência forte é inválida e o objeto está inacessível.

`WeakReference`Normalmente, um objeto é usado para representar um objeto cuja existência é controlada por um thread ou aplicativo externo. Por exemplo, construa um `WeakReference` objeto de uma referência a um objeto de arquivo. Enquanto o arquivo está aberto, a referência forte é válida. Mas se o arquivo for fechado, a referência forte se tornará inválida.

Os `WeakReference` métodos são thread-safe.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

Nome                                                  | Descrição
----------------------------------------------------- | ---------------------------------------------------------------------------
[WeakReference:: WeakReference](#weakreference)        | Inicializa uma nova instância da classe `WeakReference`.
[WeakReference:: ~ WeakReference](#tilde-weakreference) | Desinicializa (destrói) a instância atual da `WeakReference` classe.

### <a name="public-methods"></a>Métodos públicos

Nome                                                                 | Descrição
-------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------
[WeakReference::D ecrementStrongReference](#decrementstrongreference) | Decrementa a contagem de referência forte do objeto atual `WeakReference` .
[WeakReference:: IncrementStrongReference](#incrementstrongreference) | Incrementa a contagem de referência forte do objeto atual `WeakReference` .
[WeakReference:: resolve](#resolve)                                   | Define o ponteiro especificado para o valor de referência forte atual se a contagem de referência forte for diferente de zero.
[WeakReference:: setunknown](#setunknown)                             | Define a referência forte do objeto atual `WeakReference` com o ponteiro de interface especificado.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`WeakReference`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft:: WRL::D etalhes

## <a name="weakreferenceweakreference"></a><a name="tilde-weakreference"></a>WeakReference:: ~ WeakReference

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
virtual ~WeakReference();
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

Desinicializa a instância atual da `WeakReference` classe.

## <a name="weakreferencedecrementstrongreference"></a><a name="decrementstrongreference"></a>WeakReference::D ecrementStrongReference

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
ULONG DecrementStrongReference();
```

### <a name="remarks"></a>Comentários

Decrementa a contagem de referência forte do objeto atual `WeakReference` .

Quando a contagem de referência forte se tornar zero, a referência forte será definida como **`nullptr`** .

### <a name="return-value"></a>Valor retornado

A contagem de referência forte reduzida.

## <a name="weakreferenceincrementstrongreference"></a><a name="incrementstrongreference"></a>WeakReference:: IncrementStrongReference

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
ULONG IncrementStrongReference();
```

### <a name="return-value"></a>Valor retornado

A contagem de referência forte incrementada.

### <a name="remarks"></a>Comentários

Incrementa a contagem de referência forte do objeto atual `WeakReference` .

## <a name="weakreferenceresolve"></a><a name="resolve"></a>WeakReference:: resolve

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
STDMETHOD(Resolve)
   (REFIID riid,
   _Deref_out_opt_ IInspectable **ppvObject
);
```

### <a name="parameters"></a>parâmetros

*riid*<br/>
Uma ID de interface.

*ppvObject*<br/>
Quando essa operação for concluída, uma cópia da referência forte atual se a contagem de referência forte for diferente de zero.

### <a name="return-value"></a>Valor retornado

- S_OK se essa operação for bem-sucedida e a contagem de referência forte for zero. O parâmetro *ppvObject* é definido como **`nullptr`** .

- S_OK se essa operação for bem-sucedida e a contagem de referência forte for diferente de zero. O parâmetro *ppvObject* é definido como a referência forte.

- Caso contrário, um HRESULT que indica o motivo pelo qual essa operação falhou.

### <a name="remarks"></a>Comentários

Define o ponteiro especificado para o valor de referência forte atual se a contagem de referência forte for diferente de zero.

## <a name="weakreferencesetunknown"></a><a name="setunknown"></a>WeakReference:: setunknown

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
void SetUnknown(
   _In_ IUnknown* unk
);
```

### <a name="parameters"></a>parâmetros

*unk*<br/>
Um ponteiro para a `IUnknown` interface de um objeto.

### <a name="remarks"></a>Comentários

Define a referência forte do objeto atual `WeakReference` com o ponteiro de interface especificado.

## <a name="weakreferenceweakreference"></a><a name="weakreference"></a>WeakReference:: WeakReference

O oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente do seu código.

```cpp
WeakReference();
```

### <a name="remarks"></a>Comentários

Inicializa uma nova instância da classe `WeakReference`.

O ponteiro de referência forte para o `WeakReference` objeto é inicializado para **`nullptr`** , e a contagem de referência forte é inicializada como 1.
