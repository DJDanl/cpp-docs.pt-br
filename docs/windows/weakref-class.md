---
title: Classe WeakRef | Microsoft Docs
ms.custom: ''
ms.date: 10/03/2018
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- client/Microsoft::WRL::WeakRef
- client/Microsoft::WRL::WeakRef::~WeakRef
- client/Microsoft::WRL::WeakRef::As
- client/Microsoft::WRL::WeakRef::AsIID
- client/Microsoft::WRL::WeakRef::CopyTo
- client/Microsoft::WRL::WeakRef::operator&
- client/Microsoft::WRL::WeakRef::WeakRef
dev_langs:
- C++
helpviewer_keywords:
- Microsoft::WRL::WeakRef class
- Microsoft::WRL::WeakRef::~WeakRef, destructor
- Microsoft::WRL::WeakRef::As method
- Microsoft::WRL::WeakRef::AsIID method
- Microsoft::WRL::WeakRef::CopyTo method
- Microsoft::WRL::WeakRef::operator& operator
- Microsoft::WRL::WeakRef::WeakRef, constructor
ms.assetid: 572be703-c641-496c-8af5-ad6164670ba1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: adbd47e8aeeb777b9a5e077429d74ef542abb85d
ms.sourcegitcommit: 955ef0f9d966e7c9c65e040f1e28fa83abe102a5
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/04/2018
ms.locfileid: "48788806"
---
# <a name="weakref-class"></a>Classe WeakRef

Representa uma *referência fraca* que pode ser usado pelo apenas Windows Runtime, com clássico não. Uma referência fraca representa um objeto que pode ou não ser acessível.

## <a name="syntax"></a>Sintaxe

```cpp
class WeakRef : public ComPtr<IWeakReference>;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[Construtor WeakRef::WeakRef](#weakref)|Inicializa uma nova instância da classe `WeakRef`.|
|[Destruidor WeakRef::~WeakRef](#tilde-weakref)|A instância atual do realiza o desligamento de `WeakRef` classe.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[Método WeakRef::As](#as)|Define especificado `ComPtr` parâmetro de ponteiro para representar a interface especificada.|
|[Método WeakRef::AsIID](#asiid)|Define especificado `ComPtr` parâmetro de ponteiro para representar a ID de interface especificado.|
|[Método WeakRef::CopyTo](#copyto)|Atribui um ponteiro para uma interface, se disponível, para a variável de ponteiro especificado.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[Operador WeakRef::operator&](#operator-ampersand-operator)|Retorna um `ComPtrRef` objeto que representa o atual `WeakRef` objeto.|

## <a name="remarks"></a>Comentários

Um `WeakRef` objeto mantém uma *referência forte*, que é associado um objeto e pode ser válido ou inválido. Chame o `As()` ou `AsIID()` método para obter uma referência forte. Quando a referência forte é válida, ele pode acessar o objeto associado. Quando a referência forte é inválida (`nullptr`), o objeto associado está inacessível.

Um `WeakRef` objeto normalmente é usado para representar um objeto cuja existência é controlada por um aplicativo ou thread externo. Por exemplo, construir uma `WeakRef` objeto a partir de uma referência a um objeto de arquivo. Enquanto o arquivo estiver aberto, a referência forte é válida. Mas, se o arquivo é fechado, a referência forte se torna inválida.

Observe que há uma alteração de comportamento na [como](#as), [AsIID](#asiid) e [CopyTo](#copyto) métodos no SDK do Windows 10. Anteriormente, depois de chamar qualquer um desses métodos, você pode verificar a `WeakRef` para `nullptr` para determinar se uma referência forte foi obtida de com êxito, como no código a seguir:

```cpp
WeakRef wr;
strongComptrRef.AsWeak(&wr);

// Now suppose that the object strongComPtrRef points to no longer exists
// and the following code tries to get a strong ref from the weak ref:
ComPtr<ISomeInterface> strongRef;
HRESULT hr = wr.As(&strongRef);

// This check won't work with the Windows 10 SDK version of the library.
// Check the input pointer instead.
if(wr == nullptr)  
{
    wprintf(L"Couldn’t get strong ref!");
}
```

O código acima não funciona ao usar o SDK do Windows 10 (ou posterior). Em vez disso, verifique o ponteiro que foi passado para `nullptr`.

```cpp
if (strongRef == nullptr)  
{
    wprintf(L"Couldn't get strong ref!");
}
```

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ComPtr`

`WeakRef`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** client.h

**Namespace:** Microsoft::WRL

## <a name="tilde-weakref"></a>WeakRef:: ~ WeakRef destruidor

A instância atual do realiza o desligamento de `WeakRef` classe.

```cpp
~WeakRef();
```

## <a name="as"></a>Método weakref:: as

Define especificado `ComPtr` parâmetro de ponteiro para representar a interface especificada.

```cpp
template<typename U>
HRESULT As(
   _Out_ ComPtr<U>* ptr
);

template<typename U>
HRESULT As(
   _Out_ Details::ComPtrRef<ComPtr<U>> ptr
);
```

### <a name="parameters"></a>Parâmetros

*U*<br/>
Uma ID de interface.

*ptr*<br/>
Quando essa operação for concluída, um objeto que representa o parâmetro *U*.

### <a name="return-value"></a>Valor de retorno

- S_OK se essa operação for bem-sucedida; Caso contrário, um HRESULT que indica o motivo pelo qual a operação falhou, e *ptr* é definido como `nullptr`.

- S_OK se essa operação for bem-sucedida, mas atual `WeakRef` o objeto já foi liberado. Parâmetro *ptr* é definido como `nullptr`.

- S_OK se essa operação for bem-sucedida, mas atual `WeakRef` objeto não é derivado do parâmetro *U*. Parâmetro *ptr* é definido como `nullptr`.

### <a name="remarks"></a>Comentários

Um erro será emitido se parâmetro *U* é `IWeakReference`, ou não é derivado de `IInspectable`.

O primeiro modelo é a forma que você deve usar em seu código. O segundo modelo é uma especialização de auxiliar interno, que dá suporte a recursos da linguagem C++, como o [automática](../cpp/auto-cpp.md) palavra-chave de dedução de tipo.

A partir do SDK do Windows 10, esse método não define o `WeakRef` instância para a `nullptr` se não foi possível obter a referência fraca, portanto, você deve evitar a verificação de erros de código que verifica a `WeakRef` para `nullptr`. Em vez disso, verifique *ptr* para `nullptr`.

## <a name="asiid"></a>Método weakref:: Asiid

Define especificado `ComPtr` parâmetro de ponteiro para representar a ID de interface especificado.

```cpp
HRESULT AsIID(
   REFIID riid,
   _Out_ ComPtr<IInspectable>* ptr
);
```

### <a name="parameters"></a>Parâmetros

*riid*<br/>
Uma ID de interface.

*ptr*<br/>
Quando essa operação for concluída, um objeto que representa o parâmetro *riid*.

### <a name="return-value"></a>Valor de retorno

- S_OK se essa operação for bem-sucedida; Caso contrário, um HRESULT que indica o motivo pelo qual a operação falhou, e *ptr* é definido como `nullptr`.

- S_OK se essa operação for bem-sucedida, mas atual `WeakRef` o objeto já foi liberado. Parâmetro *ptr* é definido como `nullptr`.

- S_OK se essa operação for bem-sucedida, mas atual `WeakRef` objeto não é derivado do parâmetro *riid*. Parâmetro *ptr* é definido como `nullptr`. (Para obter mais informações, consulte comentários).

### <a name="remarks"></a>Comentários

Um erro será emitido se parâmetro *riid* não é derivado de `IInspectable`. Esse erro substitui o valor de retorno.

O primeiro modelo é a forma que você deve usar em seu código. O segundo modelo (não mostrados aqui, mas declarados no arquivo de cabeçalho) é uma especialização de auxiliar interno, que dá suporte a recursos da linguagem C++, como o [automática](../cpp/auto-cpp.md) palavra-chave de dedução de tipo.

A partir do SDK do Windows 10, esse método não define o `WeakRef` instância para a `nullptr` se não foi possível obter a referência fraca, portanto, você deve evitar a verificação de erros de código que verifica a `WeakRef` para `nullptr`. Em vez disso, verifique *ptr* para `nullptr`.

## <a name="copyto"></a>Método weakref:: CopyTo

Atribui um ponteiro para uma interface, se disponível, para a variável de ponteiro especificado.

```cpp
HRESULT CopyTo(
   REFIID riid,
   _Deref_out_ IInspectable** ptr
);

template<typename U>
HRESULT CopyTo(
   _Deref_out_ U** ptr
);

HRESULT CopyTo(
   _Deref_out_ IWeakReference** ptr
);
```

### <a name="parameters"></a>Parâmetros

*U*<br/>
Ponteiro um `IInspectable` interface. Um erro será emitido se *U* não é derivado de `IInspectable`.

*riid*<br/>
Uma ID de interface. Um erro será emitido se *riid* não é derivado de `IWeakReference`.

*ptr*<br/>
Um ponteiro indireto duplamente para `IInspectable` ou `IWeakReference`.

### <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, um HRESULT que descreve a falha. Para obter mais informações, consulte **Comentários**.

### <a name="remarks"></a>Comentários

Um valor de retorno de S_OK significa que essa operação foi bem-sucedida, mas não indica se a referência fraca foi resolvida para uma referência forte. Se for retornado S_OK, esse parâmetro de teste *p* é uma ótima referência; ou seja, o parâmetro *p* não for igual a `nullptr`.

A partir do SDK do Windows 10, esse método não define o `WeakRef` instância para a `nullptr` se não foi possível obter a referência fraca, portanto, você deve evitar erro ao verificar o código que verifica a `WeakRef` para `nullptr`. Em vez disso, verifique *ptr* para `nullptr`.

## <a name="operator-ampersand-operator"></a>Weakref:: Operator&amp; operador

Retorna um `ComPtrRef` objeto que representa o atual `WeakRef` objeto.

```cpp
Details::ComPtrRef<WeakRef> operator&() throw()  
```

### <a name="return-value"></a>Valor de retorno

Um `ComPtrRef` objeto que representa o atual `WeakRef` objeto.

### <a name="remarks"></a>Comentários

Este é um operador auxiliar interno que não se destina a ser usado em seu código.

## <a name="weakref"></a>Construtor weakref:: Weakref

Inicializa uma nova instância da classe `WeakRef`.

```cpp
WeakRef();
WeakRef(
   decltype(__nullptr)  
);

WeakRef(
   _In_opt_ IWeakReference* ptr
);

WeakRef(
   const ComPtr<IWeakReference>& ptr
);

WeakRef(
   const WeakRef& ptr
);

WeakRef(
   _Inout_ WeakRef&& ptr
);
```

### <a name="parameters"></a>Parâmetros

*ptr*<br/>
Um ponteiro, referência ou referência rvalue a um objeto existente que inicializa atual `WeakRef` objeto.

### <a name="remarks"></a>Comentários

O primeiro construtor inicializa vazio `WeakRef` objeto. O segundo construtor inicializa um `WeakRef` objeto de um ponteiro para o `IWeakReference` interface. O terceiro construtor inicializa um `WeakRef` objeto a partir de uma referência a um `ComPtr<IWeakReference>` objeto. O quartos e quintas construtores inicializam um `WeakRef` objeto de outro `WeakRef` objeto.
