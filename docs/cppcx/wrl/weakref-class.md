---
title: Classe WeakRef
ms.date: 10/03/2018
ms.topic: reference
f1_keywords:
- client/Microsoft::WRL::WeakRef
- client/Microsoft::WRL::WeakRef::~WeakRef
- client/Microsoft::WRL::WeakRef::As
- client/Microsoft::WRL::WeakRef::AsIID
- client/Microsoft::WRL::WeakRef::CopyTo
- client/Microsoft::WRL::WeakRef::operator&
- client/Microsoft::WRL::WeakRef::WeakRef
helpviewer_keywords:
- Microsoft::WRL::WeakRef class
- Microsoft::WRL::WeakRef::~WeakRef, destructor
- Microsoft::WRL::WeakRef::As method
- Microsoft::WRL::WeakRef::AsIID method
- Microsoft::WRL::WeakRef::CopyTo method
- Microsoft::WRL::WeakRef::operator& operator
- Microsoft::WRL::WeakRef::WeakRef, constructor
ms.assetid: 572be703-c641-496c-8af5-ad6164670ba1
ms.openlocfilehash: 715a823784aaa75f9abe349ef0a7ddc9e5d607d1
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87218345"
---
# <a name="weakref-class"></a>Classe WeakRef

Representa uma *referência fraca* que pode ser usada apenas pelo Windows Runtime, não pelo com clássico. Uma referência fraca representa um objeto que pode ou não estar acessível.

## <a name="syntax"></a>Sintaxe

```cpp
class WeakRef : public ComPtr<IWeakReference>;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Construtor WeakRef::WeakRef](#weakref)|Inicializa uma nova instância da classe `WeakRef`.|
|[Destruidor WeakRef::~WeakRef](#tilde-weakref)|Desinicializa a instância atual da `WeakRef` classe.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[Método WeakRef::As](#as)|Define o `ComPtr` parâmetro de ponteiro especificado para representar a interface especificada.|
|[Método WeakRef::AsIID](#asiid)|Define o `ComPtr` parâmetro de ponteiro especificado para representar a ID de interface especificada.|
|[Método WeakRef::CopyTo](#copyto)|Atribui um ponteiro para uma interface, se disponível, à variável de ponteiro especificada.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[Operador WeakRef::operator&](#operator-ampersand-operator)|Retorna um `ComPtrRef` objeto que representa o `WeakRef` objeto atual.|

## <a name="remarks"></a>Comentários

Um `WeakRef` objeto mantém uma *referência forte*, que está associada a um objeto e pode ser válida ou inválida. Chame o `As()` `AsIID()` método ou para obter uma referência forte. Quando a referência forte é válida, ela pode acessar o objeto associado. Quando a referência forte é inválida ( **`nullptr`** ), o objeto associado é inacessível.

`WeakRef`Normalmente, um objeto é usado para representar um objeto cuja existência é controlada por um thread ou aplicativo externo. Por exemplo, construa um `WeakRef` objeto de uma referência a um objeto de arquivo. Enquanto o arquivo está aberto, a referência forte é válida. Mas se o arquivo for fechado, a referência forte se tornará inválida.

Observe que há uma [alteração de comportamento](#as)nos métodos as, [AsIID](#asiid) e [CopyTo](#copyto) no SDK do Windows 10. Anteriormente, depois de chamar qualquer um desses métodos, você poderia verificar o `WeakRef` para **`nullptr`** para determinar se uma referência forte foi obtida com êxito, como no código a seguir:

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

O código acima não funciona ao usar o SDK do Windows 10 (ou posterior). Em vez disso, verifique o ponteiro que foi passado para **`nullptr`** .

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

**Cabeçalho:** Client. h

**Namespace:** Microsoft:: WRL

## <a name="weakrefweakref-destructor"></a><a name="tilde-weakref"></a>Destruidor WeakRef:: ~ WeakRef

Desinicializa a instância atual da `WeakRef` classe.

```cpp
~WeakRef();
```

## <a name="weakrefas-method"></a><a name="as"></a>Método WeakRef:: as

Define o `ComPtr` parâmetro de ponteiro especificado para representar a interface especificada.

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

### <a name="parameters"></a>parâmetros

*U*<br/>
Uma ID de interface.

*ptr*<br/>
Quando essa operação é concluída, um objeto que representa o parâmetro *U*.

### <a name="return-value"></a>Valor retornado

- S_OK se essa operação for concluída com sucesso; caso contrário, um HRESULT que indica o motivo da falha da operação e *PTR* é definido como **`nullptr`** .

- S_OK se essa operação for realizada com sucesso, mas o `WeakRef` objeto atual já foi liberado. O parâmetro *PTR* está definido como **`nullptr`** .

- S_OK se essa operação tiver sucesso, mas o `WeakRef` objeto atual não for derivado do parâmetro *U*. O parâmetro *PTR* está definido como **`nullptr`** .

### <a name="remarks"></a>Comentários

Um erro será emitido se o parâmetro *U* for `IWeakReference` ou não for derivado de `IInspectable` .

O primeiro modelo é o formulário que você deve usar em seu código. O segundo modelo é uma especialização interna e auxiliar que dá suporte a recursos de linguagem C++, como a palavra-chave auto-dedução de tipo [automático](../../cpp/auto-cpp.md) .

A partir do SDK do Windows 10, esse método não definirá a `WeakRef` instância como **`nullptr`** se a referência fraca não puder ser obtida, portanto, você deve evitar o código de verificação de erros que verifica o `WeakRef` para **`nullptr`** . Em vez disso, marque *PTR* para **`nullptr`** .

## <a name="weakrefasiid-method"></a><a name="asiid"></a>Método WeakRef:: AsIID

Define o `ComPtr` parâmetro de ponteiro especificado para representar a ID de interface especificada.

```cpp
HRESULT AsIID(
   REFIID riid,
   _Out_ ComPtr<IInspectable>* ptr
);
```

### <a name="parameters"></a>parâmetros

*riid*<br/>
Uma ID de interface.

*ptr*<br/>
Quando essa operação é concluída, um objeto que representa o parâmetro *riid*.

### <a name="return-value"></a>Valor retornado

- S_OK se essa operação for concluída com sucesso; caso contrário, um HRESULT que indica o motivo da falha da operação e *PTR* é definido como **`nullptr`** .

- S_OK se essa operação for realizada com sucesso, mas o `WeakRef` objeto atual já foi liberado. O parâmetro *PTR* está definido como **`nullptr`** .

- S_OK se essa operação tiver sucesso, mas o `WeakRef` objeto atual não for derivado do parâmetro *riid*. O parâmetro *PTR* está definido como **`nullptr`** . (Para obter mais informações, consulte comentários.)

### <a name="remarks"></a>Comentários

Um erro será emitido se o parâmetro *riid* não for derivado de `IInspectable` . Esse erro substitui o valor de retorno.

O primeiro modelo é o formulário que você deve usar em seu código. O segundo modelo (não mostrado aqui, mas declarado no arquivo de cabeçalho) é uma especialização interna e auxiliar que dá suporte a recursos de linguagem C++, como a palavra-chave de dedução de tipo [automático](../../cpp/auto-cpp.md) .

A partir do SDK do Windows 10, esse método não definirá a `WeakRef` instância como **`nullptr`** se a referência fraca não puder ser obtida, portanto, você deve evitar o código de verificação de erros que verifica o `WeakRef` para **`nullptr`** . Em vez disso, marque *PTR* para **`nullptr`** .

## <a name="weakrefcopyto-method"></a><a name="copyto"></a>Método WeakRef:: CopyTo

Atribui um ponteiro para uma interface, se disponível, à variável de ponteiro especificada.

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

### <a name="parameters"></a>parâmetros

*U*<br/>
Ponteiro de uma `IInspectable` interface. Um erro será emitido se *U* não for derivado de `IInspectable` .

*riid*<br/>
Uma ID de interface. Um erro será emitido se o *riid* não for derivado de `IWeakReference` .

*ptr*<br/>
Um ponteiro de indireto duplo para `IInspectable` ou `IWeakReference` .

### <a name="return-value"></a>Valor retornado

S_OK se for bem-sucedido; caso contrário, um HRESULT que descreve a falha. Para obter mais informações, consulte **comentários**.

### <a name="remarks"></a>Comentários

Um valor de retorno de S_OK significa que essa operação foi bem-sucedida, mas não indica se a referência fraca foi resolvida para uma referência forte. Se S_OK for retornado, teste se o parâmetro *p* é uma referência forte; ou seja, o parâmetro *p* não é igual a **`nullptr`** .

A partir do SDK do Windows 10, esse método não definirá a `WeakRef` instância como **`nullptr`** se a referência fraca não puder ser obtida, portanto, você deve evitar o código de verificação de erro que verifica o `WeakRef` para **`nullptr`** . Em vez disso, marque *PTR* para **`nullptr`** .

## <a name="weakrefoperatoramp-operator"></a><a name="operator-ampersand-operator"></a>Operador WeakRef:: Operator &amp;

Retorna um `ComPtrRef` objeto que representa o `WeakRef` objeto atual.

```cpp
Details::ComPtrRef<WeakRef> operator&() throw()
```

### <a name="return-value"></a>Valor retornado

Um `ComPtrRef` objeto que representa o `WeakRef` objeto atual.

### <a name="remarks"></a>Comentários

Esse é um operador de ajuda interno que não deve ser usado em seu código.

## <a name="weakrefweakref-constructor"></a><a name="weakref"></a>Construtor WeakRef:: WeakRef

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

### <a name="parameters"></a>parâmetros

*ptr*<br/>
Uma referência de ponteiro, referência ou rvalue a um objeto existente que inicializa o objeto atual `WeakRef` .

### <a name="remarks"></a>Comentários

O primeiro construtor inicializa um `WeakRef` objeto vazio. O segundo construtor inicializa um `WeakRef` objeto de um ponteiro para a `IWeakReference` interface. O terceiro construtor inicializa um `WeakRef` objeto de uma referência a um `ComPtr<IWeakReference>` objeto. O quarto e o quinto construtores inicializam um `WeakRef` objeto de outro `WeakRef` objeto.
