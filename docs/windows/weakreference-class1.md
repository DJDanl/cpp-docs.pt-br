---
title: WeakReference Class1 | Microsoft Docs
ms.custom: ''
ms.date: 09/24/2018
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::WeakReference
- implements/Microsoft::WRL::Details::WeakReference::DecrementStrongReference
- implements/Microsoft::WRL::Details::WeakReference::IncrementStrongReference
- implements/Microsoft::WRL::Details::WeakReference::Resolve
- implements/Microsoft::WRL::Details::WeakReference::SetUnknown
- implements/Microsoft::WRL::Details::WeakReference::~WeakReference
- implements/Microsoft::WRL::Details::WeakReference::WeakReference
dev_langs:
- C++
helpviewer_keywords:
- Microsoft::WRL::Details::WeakReference class
- Microsoft::WRL::Details::WeakReference::DecrementStrongReference method
- Microsoft::WRL::Details::WeakReference::IncrementStrongReference method
- Microsoft::WRL::Details::WeakReference::Resolve method
- Microsoft::WRL::Details::WeakReference::SetUnknown method
- Microsoft::WRL::Details::WeakReference::~WeakReference, destructor
- Microsoft::WRL::Details::WeakReference::WeakReference, constructor
ms.assetid: 3f4c956b-dbbd-49b1-8cfa-9509a9956c97
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 4d82dbffee5b686c6d8923f395c74fedfac54816
ms.sourcegitcommit: edb46b0239a0e616af4ec58906e12338c3e8d2c6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/25/2018
ms.locfileid: "47169665"
---
# <a name="weakreference-class1"></a>WeakReference Class1

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
class WeakReference;
```

## <a name="remarks"></a>Comentários

Representa uma *referência fraca* que pode ser usado com o tempo de execução do Windows ou o com clássico. Uma referência fraca representa um objeto que pode ou não ser acessível.

Um `WeakReference` objeto mantém uma *referência forte*, que é um ponteiro para um objeto e uma *contagem de referência forte*, que é o número de cópias da referência forte que foram distribuídas por o `Resolve()` método. Embora a contagem de referência forte é diferente de zero, a referência forte é válida e o objeto está acessível. Quando a contagem de referência forte se torna zero, a referência forte é inválida e o objeto está inacessível.

Um `WeakReference` objeto normalmente é usado para representar um objeto cuja existência é controlada por um aplicativo ou thread externo. Por exemplo, construir uma `WeakReference` objeto a partir de uma referência a um objeto de arquivo. Enquanto o arquivo estiver aberto, a referência forte é válida. Mas, se o arquivo é fechado, a referência forte se torna inválida.

O `WeakReference` métodos são thread-safe.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

Nome                                                  | Descrição
----------------------------------------------------- | ---------------------------------------------------------------------------
[WeakReference::WeakReference](#weakreference)        | Inicializa uma nova instância da classe `WeakReference`.
[WeakReference:: ~ WeakReference](#tilde-weakreference) | Realiza o desligamento (destrói) a instância atual do `WeakReference` classe.

### <a name="public-methods"></a>Métodos públicos

Nome                                                                 | Descrição
-------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------
[WeakReference:: Decrementstrongreference](#decrementstrongreference) | Diminui a contagem de referência forte da atual `WeakReference` objeto.
[WeakReference:: Incrementstrongreference](#incrementstrongreference) | Incrementa a contagem de referência forte da atual `WeakReference` objeto.
[WeakReference::Resolve](#resolve)                                   | Define o ponteiro especificado para o valor atual de referência forte se a contagem de referência forte for diferente de zero.
[WeakReference:: Setunknown](#setunknown)                             | Define a referência forte da atual `WeakReference` objeto para o ponteiro de interface especificado.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`WeakReference`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft::WRL::Details

## <a name="tilde-weakreference"></a>WeakReference:: ~ WeakReference

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
virtual ~WeakReference();
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

A instância atual do realiza o desligamento de `WeakReference` classe.

## <a name="decrementstrongreference"></a>WeakReference:: Decrementstrongreference

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
ULONG DecrementStrongReference();
```

### <a name="remarks"></a>Comentários

Diminui a contagem de referência forte da atual `WeakReference` objeto.

Quando a contagem de referência forte se torna zero, a referência forte é definida como `nullptr`.

### <a name="return-value"></a>Valor de retorno

A contagem de referência forte decrementado.

## <a name="incrementstrongreference"></a>WeakReference:: Incrementstrongreference

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
ULONG IncrementStrongReference();
```

### <a name="return-value"></a>Valor de retorno

A contagem de referência forte incrementado.

### <a name="remarks"></a>Comentários

Incrementa a contagem de referência forte da atual `WeakReference` objeto.

## <a name="resolve"></a>WeakReference:: resolve

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
STDMETHOD(Resolve)  
   (REFIID riid,
   _Deref_out_opt_ IInspectable **ppvObject
);
```

### <a name="parameters"></a>Parâmetros

*riid*<br/>
Uma ID de interface.

*ppvObject*<br/>
Quando essa operação for concluída, uma cópia da referência forte atual se a contagem de referência forte for diferente de zero.

### <a name="return-value"></a>Valor de retorno

- S_OK se essa operação for bem-sucedida e a contagem de referência forte é zero. O *ppvObject* parâmetro for definido como `nullptr`.

- S_OK se essa operação for bem-sucedida e a contagem de referência forte é diferente de zero. O *ppvObject* parâmetro for definido como a referência forte.

- Caso contrário, um HRESULT que indica o motivo pelo qual esta operação falhou.

### <a name="remarks"></a>Comentários

Define o ponteiro especificado para o valor atual de referência forte se a contagem de referência forte for diferente de zero.

## <a name="setunknown"></a>WeakReference:: Setunknown

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
void SetUnknown(
   _In_ IUnknown* unk
);
```

### <a name="parameters"></a>Parâmetros

*UNK*<br/>
Um ponteiro para o `IUnknown` interface de um objeto.

### <a name="remarks"></a>Comentários

Define a referência forte da atual `WeakReference` objeto para o ponteiro de interface especificado.

## <a name="weakreference"></a>WeakReference:: WeakReference

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

```cpp
WeakReference();
```

### <a name="remarks"></a>Comentários

Inicializa uma nova instância da classe `WeakReference`.

O ponteiro de referência forte para o `WeakReference` objeto é inicializado como `nullptr`, e a contagem de referência forte é inicializada como 1.
