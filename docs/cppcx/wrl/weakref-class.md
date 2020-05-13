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
ms.openlocfilehash: 681f5a64c3e2902c66facbd4f0ac3a3663a7e79d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81374250"
---
# <a name="weakref-class"></a>Classe WeakRef

Representa uma *referência fraca* que pode ser usada apenas pelo Windows Runtime, não pelo COM clássico. Uma referência fraca representa um objeto que pode ou não ser acessível.

## <a name="syntax"></a>Sintaxe

```cpp
class WeakRef : public ComPtr<IWeakReference>;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Construtor WeakRef::WeakRef](#weakref)|Inicia uma nova instância da classe `WeakRef`.|
|[Destruidor WeakRef::~WeakRef](#tilde-weakref)|Desinicializa a instância `WeakRef` atual da classe.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[Método WeakRef::As](#as)|Define o `ComPtr` parâmetro de ponteiro especificado para representar a interface especificada.|
|[Método WeakRef::AsIID](#asiid)|Define o `ComPtr` parâmetro de ponteiro especificado para representar o ID de interface especificado.|
|[Método WeakRef::CopyTo](#copyto)|Atribui um ponteiro a uma interface, se disponível, à variável ponteiro especificada.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[Operador WeakRef::operator&](#operator-ampersand-operator)|Retorna `ComPtrRef` um objeto que `WeakRef` representa o objeto atual.|

## <a name="remarks"></a>Comentários

Um `WeakRef` objeto mantém uma *forte referência,* que está associada a um objeto, e pode ser válida ou inválida. Ligue `As()` para `AsIID()` o método ou para obter uma referência forte. Quando a referência forte é válida, ela pode acessar o objeto associado. Quando a referência forte`nullptr`é inválida (), o objeto associado é inacessível.

Um `WeakRef` objeto é normalmente usado para representar um objeto cuja existência é controlada por um segmento ou aplicativo externo. Por exemplo, `WeakRef` construa um objeto a partir de uma referência a um objeto de arquivo. Enquanto o arquivo estiver aberto, a referência forte é válida. Mas se o arquivo for fechado, a forte referência se torna inválida.

Observe que há uma mudança de comportamento nos métodos [As](#as), [AsIID](#asiid) e [CopyTo](#copyto) no SDK do Windows 10. Anteriormente, depois de chamar qualquer um desses `WeakRef` `nullptr` métodos, você poderia verificar se uma referência forte foi obtida com sucesso, como no seguinte código:

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

O código acima não funciona ao usar o SDK do Windows 10 (ou posterior). Em vez disso, verifique o `nullptr`ponteiro que foi passado para .

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

**Espaço de nome:** Microsoft::WRL

## <a name="weakrefweakref-destructor"></a><a name="tilde-weakref"></a>WeakRef::~WeakRef Destructor

Desinicializa a instância `WeakRef` atual da classe.

```cpp
~WeakRef();
```

## <a name="weakrefas-method"></a><a name="as"></a>WeakRef::Como método

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

### <a name="parameters"></a>Parâmetros

*U*<br/>
Um ID de interface.

*Ptr*<br/>
Quando esta operação é concluída, um objeto que representa o parâmetro *U*.

### <a name="return-value"></a>Valor retornado

- S_OK se esta operação for bem sucedida; caso contrário, um HRESULT que indica a razão pela `nullptr`qual a operação falhou, e *ptr* está definido para .

- S_OK se esta operação for `WeakRef` bem sucedida, mas o objeto atual já foi liberado. Parâmetro *ptr* é `nullptr`definido para .

- S_OK se esta operação for `WeakRef` bem sucedida, mas o objeto atual não é derivado do parâmetro *U*. Parâmetro *ptr* é `nullptr`definido para .

### <a name="remarks"></a>Comentários

Um erro é emitido *U* se `IWeakReference`o parâmetro U é `IInspectable`, ou não é derivado de .

O primeiro modelo é o formulário que você deve usar em seu código. O segundo modelo é uma especialização interna e auxiliar que suporta recursos de linguagem C++, como a palavra-chave de dedução de tipo [automático.](../../cpp/auto-cpp.md)

A partir do SDK do Windows 10, `WeakRef` `nullptr` este método não define a instância para se a referência fraca não `WeakRef` `nullptr`pôde ser obtida, então você deve evitar o código de verificação de erros que verifica o . Em vez disso, `nullptr`verifique *ptr* para .

## <a name="weakrefasiid-method"></a><a name="asiid"></a>Weakref::Método Asiid

Define o `ComPtr` parâmetro de ponteiro especificado para representar o ID de interface especificado.

```cpp
HRESULT AsIID(
   REFIID riid,
   _Out_ ComPtr<IInspectable>* ptr
);
```

### <a name="parameters"></a>Parâmetros

*riid*<br/>
Um ID de interface.

*Ptr*<br/>
Quando esta operação é concluída, um objeto que representa o parâmetro *riid*.

### <a name="return-value"></a>Valor retornado

- S_OK se esta operação for bem sucedida; caso contrário, um HRESULT que indica a razão pela `nullptr`qual a operação falhou, e *ptr* está definido para .

- S_OK se esta operação for `WeakRef` bem sucedida, mas o objeto atual já foi liberado. Parâmetro *ptr* é `nullptr`definido para .

- S_OK se esta operação for `WeakRef` bem sucedida, mas o objeto atual não é derivado de parâmetro *sítero*. Parâmetro *ptr* é `nullptr`definido para . (Para obter mais informações, consulte Observações.)

### <a name="remarks"></a>Comentários

Um erro é emitido se o parâmetro *riid* não for derivado de `IInspectable`. Este erro substitui o valor de retorno.

O primeiro modelo é o formulário que você deve usar em seu código. O segundo modelo (não mostrado aqui, mas declarado no arquivo de cabeçalho) é uma especialização interna e auxiliar que suporta recursos de linguagem C++, como a palavra-chave de dedução do tipo [automático.](../../cpp/auto-cpp.md)

A partir do SDK do Windows 10, `WeakRef` `nullptr` este método não define a instância para se a referência fraca não `WeakRef` `nullptr`pôde ser obtida, então você deve evitar o código de verificação de erros que verifica o . Em vez disso, `nullptr`verifique *ptr* para .

## <a name="weakrefcopyto-method"></a><a name="copyto"></a>WeakRef::CopyTo Method

Atribui um ponteiro a uma interface, se disponível, à variável ponteiro especificada.

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
Ponteiro `IInspectable` uma interface. Um erro é emitido se *U* `IInspectable`não for derivado de .

*riid*<br/>
Um ID de interface. Um erro é emitido se *riid* `IWeakReference`não for derivado de .

*Ptr*<br/>
Um ponteiro duplamente indireto `IInspectable` `IWeakReference`para ou .

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; caso contrário, um HRESULT que descreve a falha. Para obter mais informações, consulte **Observações**.

### <a name="remarks"></a>Comentários

Um valor de retorno de S_OK significa que esta operação foi bem sucedida, mas não indica se a referência fraca foi resolvida para uma forte referência. Se S_OK for devolvido, teste que o parâmetro *p* é uma forte referência; ou seja, o parâmetro *p* `nullptr`não é igual a .

A partir do SDK do Windows 10, `WeakRef` `nullptr` este método não define a instância para se a referência fraca `WeakRef` não `nullptr`pôde ser obtida, então você deve evitar o código de verificação de erro que verifica o . Em vez disso, `nullptr`verifique *ptr* para .

## <a name="weakrefoperatoramp-operator"></a><a name="operator-ampersand-operator"></a>WeakRef::operador&amp; operador

Retorna `ComPtrRef` um objeto que `WeakRef` representa o objeto atual.

```cpp
Details::ComPtrRef<WeakRef> operator&() throw()
```

### <a name="return-value"></a>Valor retornado

Um `ComPtrRef` objeto que representa `WeakRef` o objeto atual.

### <a name="remarks"></a>Comentários

Este é um operador auxiliar interno que não deve ser usado em seu código.

## <a name="weakrefweakref-constructor"></a><a name="weakref"></a>WeakRef::Construtor WeakRef

Inicia uma nova instância da classe `WeakRef`.

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

*Ptr*<br/>
Um ponteiro, referência ou referência de valor a um objeto `WeakRef` existente que inicializa o objeto atual.

### <a name="remarks"></a>Comentários

O primeiro construtor inicializa `WeakRef` um objeto vazio. O segundo construtor inicializa `WeakRef` um objeto de `IWeakReference` um ponteiro para a interface. O terceiro construtor inicializa `WeakRef` um objeto a `ComPtr<IWeakReference>` partir de uma referência a um objeto. O quarto e quinto construtores `WeakRef` inicializam `WeakRef` um objeto de outro objeto.
