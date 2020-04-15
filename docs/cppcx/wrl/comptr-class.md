---
title: Classe ComPtr
ms.date: 07/26/2019
ms.topic: reference
f1_keywords:
- client/Microsoft::WRL::ComPtr
- client/Microsoft::WRL::ComPtr::As
- client/Microsoft::WRL::ComPtr::AsIID
- client/Microsoft::WRL::ComPtr::AsWeak
- client/Microsoft::WRL::ComPtr::Attach
- client/Microsoft::WRL::ComPtr::ComPtr
- client/Microsoft::WRL::ComPtr::CopyTo
- client/Microsoft::WRL::ComPtr::Detach
- client/Microsoft::WRL::ComPtr::Get
- client/Microsoft::WRL::ComPtr::GetAddressOf
- client/Microsoft::WRL::ComPtr::InternalAddRef
- client/Microsoft::WRL::ComPtr::InternalRelease
- client/Microsoft::WRL::ComPtr::operator&
- client/Microsoft::WRL::ComPtr::operator->
- client/Microsoft::WRL::ComPtr::operator=
- client/Microsoft::WRL::ComPtr::operator==
- client/Microsoft::WRL::ComPtr::operator!=
- client/Microsoft::WRL::ComPtr::operator Microsoft::WRL::Details::BoolType
- client/Microsoft::WRL::ComPtr::ptr_
- client/Microsoft::WRL::ComPtr::ReleaseAndGetAddressOf
- client/Microsoft::WRL::ComPtr::Reset
- client/Microsoft::WRL::ComPtr::Swap
- client/Microsoft::WRL::ComPtr::~ComPtr
helpviewer_keywords:
- Microsoft::WRL::ComPtr class
- Microsoft::WRL::ComPtr::As method
- Microsoft::WRL::ComPtr::AsIID method
- Microsoft::WRL::ComPtr::AsWeak method
- Microsoft::WRL::ComPtr::Attach method
- Microsoft::WRL::ComPtr::ComPtr, constructor
- Microsoft::WRL::ComPtr::CopyTo method
- Microsoft::WRL::ComPtr::Detach method
- Microsoft::WRL::ComPtr::Get method
- Microsoft::WRL::ComPtr::GetAddressOf method
- Microsoft::WRL::ComPtr::InternalAddRef method
- Microsoft::WRL::ComPtr::InternalRelease method
- Microsoft::WRL::ComPtr::operator& operator
- Microsoft::WRL::ComPtr::operator-> operator
- Microsoft::WRL::ComPtr::operator= operator
- Microsoft::WRL::ComPtr::operator== operator
- Microsoft::WRL::ComPtr::operator!= operator
- Microsoft::WRL::ComPtr::operator Microsoft::WRL::Details::BoolType operator
- Microsoft::WRL::ComPtr::ptr_ data member
- Microsoft::WRL::ComPtr::ReleaseAndGetAddressOf method
- Microsoft::WRL::ComPtr::Reset method
- Microsoft::WRL::ComPtr::Swap method
- Microsoft::WRL::ComPtr::~ComPtr, destructor
ms.assetid: a6551902-6819-478a-8df7-b6f312ab1fb0
ms.openlocfilehash: 89c09ede972f5bdd5da1dde810cad31733bdf338
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372647"
---
# <a name="comptr-class"></a>Classe ComPtr

Cria um tipo *de ponteiro inteligente* que representa a interface especificada pelo parâmetro de modelo. `ComPtr`mantém automaticamente uma contagem de referência para o ponteiro de interface subjacente e libera a interface quando a contagem de referência vai para zero.

## <a name="syntax"></a>Sintaxe

```cpp
template <typename T>
class ComPtr;

template<class T>
friend class ComPtr;
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
A interface `ComPtr` que o representa.

*U*<br/>
Uma classe para `ComPtr` a qual a corrente é amiga. (O modelo que usa este parâmetro está protegido.)

## <a name="remarks"></a>Comentários

`ComPtr<>`declara um tipo que representa o ponteiro de interface subjacente. Use `ComPtr<>` para declarar uma variável e, em`->`seguida, use o operador de acesso a membros de seta ( ) para acessar uma função de membro da interface.

Para obter mais informações sobre ponteiros inteligentes, consulte a subseção "COM Smart Pointers" do tópico Práticas de [codificação COM](/windows/win32/LearnWin32/com-coding-practices) na Biblioteca MSDN.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

Nome            | Descrição
--------------- | ---------------------------------------------------------------
`InterfaceType` | Um sinônimo para o tipo especificado pelo parâmetro de modelo *T.*

### <a name="public-constructors"></a>Construtores públicos

Nome                             | Descrição
-------------------------------- | --------------------------------------------------------------------------------------------------------------------
[Comptr::ComPtr](#comptr)        | Intializa uma nova `ComPtr` instância da classe. As sobrecargas fornecem construtores padrão, copiar, mover e conversão.
[Comptr::~ComPtr](#tilde-comptr) | Desinicializa uma `ComPtr`instância de .

### <a name="public-methods"></a>Métodos públicos

Nome                                                      | Descrição
--------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
[ComPtr::Como](#as)                                         | Retorna `ComPtr` um objeto que representa a interface identificada pelo parâmetro de modelo especificado.
[Comptr::AsIID](#asiid)                                   | Retorna `ComPtr` um objeto que representa a interface identificada pelo ID de interface especificado.
[Comptr::AsWeak](#asweak)                                 | Recupera uma referência fraca ao objeto atual.
[ComPtr::Anexar](#attach)                                 | Associa `ComPtr` isso ao tipo de interface especificado pelo parâmetro de tipo de modelo atual.
[ComPtr::CopyTo](#copyto)                                 | Copia a interface atual ou `ComPtr` especificada associada a isso no ponteiro de saída especificado.
[ComPtr::Detach](#detach)                                 | Desassocia `ComPtr` isso da interface que ele representa.
[ComPtr::Get](#get)                                       | Recupera um ponteiro para a interface `ComPtr`associada a isso .
[Comptr::GetAddressOf](#getaddressof)                     | Recupera o endereço do membro de dados [ptr_,](#ptr) que contém `ComPtr`um ponteiro para a interface representada por este .
[Comptr::releaseAndGetAddressOf](#releaseandgetaddressof) | Libera a interface associada `ComPtr` a isso e, em seguida, recupera o endereço do membro de dados [ptr_,](#ptr) que contém um ponteiro para a interface que foi lançada.
[ComPtr::Reset](#reset)                                   | Libera todas as referências para o ponteiro para `ComPtr`a interface associada a isso .
[ComPtr::Swap](#swap)                                     | Troca a interface gerenciada `ComPtr` pela corrente com a `ComPtr`interface gerenciada pelo especificado .

### <a name="protected-methods"></a>Métodos Protegidos

Nome                                        | Descrição
------------------------------------------- | --------------------------------------------------------------------------------
[Comptr::InternalAddRef](#internaladdref)   | Incrementa a contagem de referência `ComPtr`da interface associada a isso .
[Comptr::Liberação interna](#internalrelease) | Executa uma operação de liberação `ComPtr`COM na interface associada a isso .

### <a name="public-operators"></a>Operadores públicos

Nome                                                                                           | Descrição
---------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------
[ComPtr::&do operador](#operator-ampersand)                                                       | Recupera o endereço da `ComPtr`corrente .
[ComPtr::operator->](#operator-arrow)                                                          | Recupera um ponteiro para o tipo especificado pelo parâmetro de modelo atual.
[ComPtr::operador=](#operator-assign)                                                          | Atribui um valor à `ComPtr`corrente .
[ComPtr::operador==](#operator-equality)                                                       | Indica se dois objetos `ComPtr` são iguais.
[ComPtr::operador!=](#operator-inequality)                                                     | Indica se dois objetos `ComPtr` não são iguais.
[ComPtr::operador Microsoft::WRL::Details::BoolType](#operator-microsoft-wrl-details-booltype) | Indica se um `ComPtr` está ou não gerenciando a vida útil do objeto de uma interface.

### <a name="protected-data-members"></a>Membros de Dados Protegidos

Nome                 | Descrição
-------------------- | ------------------------------------------------------------------------------------------
[ComPtr::ptr_](#ptr) | Contém um ponteiro para a interface que está `ComPtr`associado e gerenciado por isso .

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ComPtr`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** client.h

**Espaço de nome:** Microsoft::WRL

## <a name="comptrcomptr"></a><a name="tilde-comptr"></a>Comptr::~ComPtr

Desinicializa uma `ComPtr`instância de .

```cpp
WRL_NOTHROW ~ComPtr();
```

## <a name="comptras"></a><a name="as"></a>ComPtr::Como

Retorna `ComPtr` um objeto que representa a interface identificada pelo parâmetro de modelo especificado.

```cpp
template<typename U>
HRESULT As(
   _Out_ ComPtr<U>* p
) const;

template<typename U>
HRESULT As(
   _Out_ Details::ComPtrRef<ComPtr<U>> p
) const;
```

### <a name="parameters"></a>Parâmetros

*U*<br/>
A interface a ser representada pelo parâmetro *p*.

*P*<br/>
Um `ComPtr` objeto que representa a interface especificada pelo parâmetro *U*. O parâmetro *p* não deve `ComPtr` se referir ao objeto atual.

### <a name="remarks"></a>Comentários

O primeiro modelo é o formulário que você deve usar em seu código. O segundo modelo é uma especialização interna e auxiliar que suporta recursos de linguagem C++, como a palavra-chave de dedução de tipo [automático.](../../cpp/auto-cpp.md)

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; caso contrário, um HRESULT que indica o erro.

## <a name="comptrasiid"></a><a name="asiid"></a>Comptr::AsIID

Retorna `ComPtr` um objeto que representa a interface identificada pelo ID de interface especificado.

```cpp
WRL_NOTHROW HRESULT AsIID(
   REFIID riid,
   _Out_ ComPtr<IUnknown>* p
) const;
```

### <a name="parameters"></a>Parâmetros

*riid*<br/>
Um ID de interface.

*P*<br/>
Se o objeto tiver uma interface cujo ID seja igual *a riid,* um ponteiro duplamente indireto para a interface especificada pelo parâmetro *riid;* caso contrário, um `IUnknown`ponteiro para .

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; caso contrário, um HRESULT que indica o erro.

## <a name="comptrasweak"></a><a name="asweak"></a>Comptr::AsWeak

Recupera uma referência fraca ao objeto atual.

```cpp
HRESULT AsWeak(
   _Out_ WeakRef* pWeakRef
);
```

### <a name="parameters"></a>Parâmetros

*pWeakRef*<br/>
Quando esta operação for concluída, um ponteiro para um objeto de referência fraco.

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; caso contrário, um HRESULT que indica o erro.

## <a name="comptrattach"></a><a name="attach"></a>ComPtr::Anexar

Associa `ComPtr` isso ao tipo de interface especificado pelo parâmetro de tipo de modelo atual.

```cpp
void Attach(
   _In_opt_ InterfaceType* other
);
```

### <a name="parameters"></a>Parâmetros

*Outros*<br/>
Um tipo de interface.

## <a name="comptrcomptr"></a><a name="comptr"></a>Comptr::ComPtr

Intializa uma nova `ComPtr` instância da classe. As sobrecargas fornecem construtores padrão, copiar, mover e conversão.

```cpp
WRL_NOTHROW ComPtr();

WRL_NOTHROW ComPtr(
   decltype(__nullptr)
);

template<class U>
WRL_NOTHROW ComPtr(
   _In_opt_ U *other
);

WRL_NOTHROW ComPtr(
   const ComPtr& other
);

template<class U>
WRL_NOTHROW ComPtr(
   const ComPtr<U> &other,
   typename ENABLE_IF<__is_convertible_to(U*, T*), void *>
);

WRL_NOTHROW ComPtr(
   _Inout_ ComPtr &&other
);

template<class U>
WRL_NOTHROW ComPtr(
   _Inout_ ComPtr<U>&& other, typename ENABLE_IF<__is_convertible_to(U*, T*), void *>
);
```

### <a name="parameters"></a>Parâmetros

*U*<br/>
O tipo do *outro* parâmetro.

*Outros*<br/>
Um objeto do tipo *U.*

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

O primeiro construtor é o construtor padrão, que implicamente cria um objeto vazio. O segundo construtor especifica [__nullptr,](../../extensions/nullptr-cpp-component-extensions.md)que cria explicitamente um objeto vazio.

O terceiro construtor cria um objeto a partir do objeto especificado por um ponteiro. O ComPtr agora possui a memória apontada para a ponta e mantém uma contagem de referência para ela.

O quarto e quinto construtores são construtores de cópias. O quinto construtor copia um objeto se for conversível para o tipo atual.

O sexto e sétimo construtores são construtores movedores. O sétimo construtor move um objeto se for conversível para o tipo atual.

## <a name="comptrcopyto"></a><a name="copyto"></a>ComPtr::CopyTo

Copia a interface atual ou `ComPtr` especificada associada a isso ao ponteiro especificado.

```cpp
HRESULT CopyTo(
   _Deref_out_ InterfaceType** ptr
);

HRESULT CopyTo(
   REFIID riid,
   _Deref_out_ void** ptr
) const;

template<typename U>
HRESULT CopyTo(
   _Deref_out_ U** ptr
) const;
```

### <a name="parameters"></a>Parâmetros

*U*<br/>
O nome de um tipo.

*Ptr*<br/>
Quando esta operação for concluída, um ponteiro para a interface solicitada.

*riid*<br/>
Um ID de interface.

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; caso contrário, um HRESULT que `QueryInterface` indica por que a operação implícita falhou.

### <a name="remarks"></a>Comentários

A primeira função retorna uma cópia de um `ComPtr`ponteiro para a interface associada a isso . Esta função sempre retorna S_OK.

A segunda função `QueryInterface` executa uma operação `ComPtr` na interface associada a esta para a interface especificada pelo parâmetro *riid.*

A terceira função `QueryInterface` executa uma operação `ComPtr` na interface associada a isso para a interface subjacente do parâmetro *U.*

## <a name="comptrdetach"></a><a name="detach"></a>ComPtr::Detach

Desassocia `ComPtr` este objeto da interface que ele representa.

```cpp
T* Detach();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para a interface `ComPtr` que foi representada por este objeto.

## <a name="comptrget"></a><a name="get"></a>ComPtr::Get

Recupera um ponteiro para a interface `ComPtr`associada a isso .

```cpp
T* Get() const;
```

### <a name="return-value"></a>Valor retornado

Ponteiro para a interface que `ComPtr`está associada a isso .

## <a name="comptrgetaddressof"></a><a name="getaddressof"></a>Comptr::GetAddressOf

Recupera o endereço do membro de dados [ptr_,](#ptr) que contém `ComPtr`um ponteiro para a interface representada por este .

```cpp
T* const* GetAddressOf() const;
T** GetAddressOf();
```

### <a name="return-value"></a>Valor retornado

O endereço de uma variável.

## <a name="comptrinternaladdref"></a><a name="internaladdref"></a>Comptr::InternalAddRef

Incrementa a contagem de referência `ComPtr`da interface associada a isso .

```cpp
void InternalAddRef() const;
```

### <a name="remarks"></a>Comentários

Este método está protegido.

## <a name="comptrinternalrelease"></a><a name="internalrelease"></a>Comptr::Liberação interna

Executa uma operação de liberação `ComPtr`COM na interface associada a isso .

```cpp
void InternalRelease();
```

### <a name="remarks"></a>Comentários

Este método está protegido.

## <a name="comptroperatoramp"></a><a name="operator-ampersand"></a>ComPtr::operador&amp;

Libera a interface associada `ComPtr` a este objeto e, `ComPtr` em seguida, recupera o endereço do objeto.

```cpp
Details::ComPtrRef<WeakRef> operator&()

const Details::ComPtrRef<const WeakRef> operator&() const
```

### <a name="return-value"></a>Valor retornado

Uma referência fraca `ComPtr`à corrente.

### <a name="remarks"></a>Comentários

Este método difere do [ComPtr::GetAddressOf](#getaddressof) na que este método libera uma referência ao ponteiro da interface. Use `ComPtr::GetAddressOf` quando precisar do endereço do ponteiro da interface, mas não quiser liberar essa interface.

## <a name="comptroperator-gt"></a><a name="operator-arrow"></a>ComPtr::operador-&gt;

Recupera um ponteiro para o tipo especificado pelo parâmetro de modelo atual.

```cpp
WRL_NOTHROW Microsoft::WRL::Details::RemoveIUnknown<InterfaceType>* operator->() const;
```

### <a name="return-value"></a>Valor retornado

Ponteiro para o tipo especificado pelo nome do tipo de modelo atual.

### <a name="remarks"></a>Comentários

Esta função auxiliar remove sobrecargas desnecessárias causadas pelo uso da macro STDMETHOD. Esta função `IUnknown` `private` faz `virtual`tipos em vez de .

## <a name="comptroperator"></a><a name="operator-assign"></a>ComPtr::operador=

Atribui um valor à `ComPtr`corrente .

```cpp
WRL_NOTHROW ComPtr& operator=(
   decltype(__nullptr)
);
WRL_NOTHROW ComPtr& operator=(
   _In_opt_ T *other
);
template <typename U>
WRL_NOTHROW ComPtr& operator=(
   _In_opt_ U *other
);
WRL_NOTHROW ComPtr& operator=(
   const ComPtr &other
);
template<class U>
WRL_NOTHROW ComPtr& operator=(
   const ComPtr<U>& other
);
WRL_NOTHROW ComPtr& operator=(
   _Inout_ ComPtr &&other
);
template<class U>
WRL_NOTHROW ComPtr& operator=(
   _Inout_ ComPtr<U>&& other
);
```

### <a name="parameters"></a>Parâmetros

*U*<br/>
Uma aula.

*Outros*<br/>
Um ponteiro, referência ou referência de valor `ComPtr`a um tipo ou outro .

### <a name="return-value"></a>Valor retornado

Uma referência à `ComPtr`corrente.

### <a name="remarks"></a>Comentários

A primeira versão deste operador atribui um `ComPtr`valor vazio à corrente .

Na segunda versão, se o ponteiro de interface atribuir `ComPtr` não for o mesmo que o `ComPtr`ponteiro de interface atual, o segundo ponteiro de interface será atribuído à corrente .

Na terceira versão, o ponteiro de interface de `ComPtr`atribuição é atribuído à corrente .

Na quarta versão, se o ponteiro de interface do valor `ComPtr` de atribuição não for o mesmo `ComPtr`que o ponteiro de interface atual, o segundo ponteiro de interface será atribuído à corrente .

A quinta versão é um operador de cópia; uma referência `ComPtr` a a é `ComPtr`atribuída à corrente .

A sexta versão é um operador de cópia que usa semântica de movimento; uma referência de `ComPtr` valor a um se qualquer tipo for `ComPtr`lançado estático e, em seguida, atribuído à corrente .

A sétima versão é um operador de cópia que usa semântica de movimento; uma referência de `ComPtr` valor a um tipo *U* é elenco `ComPtr`estático em seguida e atribuído à corrente .

## <a name="comptroperator"></a><a name="operator-equality"></a>ComPtr::operador==

Indica se dois objetos `ComPtr` são iguais.

```cpp
bool operator==(
   const ComPtr<T>& a,
   const ComPtr<U>& b
);

bool operator==(
   const ComPtr<T>& a,
   decltype(__nullptr)
);

bool operator==(
   decltype(__nullptr),
   const ComPtr<T>& a
);
```

### <a name="parameters"></a>Parâmetros

*Um*<br/>
Uma referência a um objeto `ComPtr`.

*B*<br/>
Uma referência `ComPtr` a outro objeto.

### <a name="return-value"></a>Valor retornado

O primeiro `true` operador cede se o objeto *a* for igual ao objeto *b;* caso contrário, `false`.

O segundo e terceiro `true` operadores cedem se o objeto *a* for igual a `nullptr`; caso contrário, `false`.

## <a name="comptroperator"></a><a name="operator-inequality"></a>ComPtr::operador!=

Indica se dois objetos `ComPtr` não são iguais.

```cpp
bool operator!=(
   const ComPtr<T>& a,
   const ComPtr<U>& b
);

bool operator!=(
   const ComPtr<T>& a,
   decltype(__nullptr)
);

bool operator!=(
   decltype(__nullptr),
   const ComPtr<T>& a
);
```

### <a name="parameters"></a>Parâmetros

*Um*<br/>
Uma referência a um objeto `ComPtr`.

*B*<br/>
Uma referência `ComPtr` a outro objeto.

### <a name="return-value"></a>Valor retornado

O primeiro `true` operador cede se o objeto *a* não for igual ao objeto *b;* caso contrário, `false`.

O segundo e terceiro `true` operadores cedem `nullptr`se o objeto *a* não for igual a; caso contrário, `false`.

## <a name="comptroperator-microsoftwrldetailsbooltype"></a><a name="operator-microsoft-wrl-details-booltype"></a>ComPtr::operador Microsoft::WRL::Details::BoolType

Indica se um `ComPtr` está ou não gerenciando a vida útil do objeto de uma interface.

```cpp
WRL_NOTHROW operator Microsoft::WRL::Details::BoolType() const;
```

### <a name="return-value"></a>Valor retornado

Se uma interface estiver `ComPtr`associada a isso, o endereço do [BoolStruct:::Membro](boolstruct-structure.md#member) de dados; caso contrário, `nullptr`.

## <a name="comptrptr_"></a><a name="ptr"></a>ComPtr::ptr_

Contém um ponteiro para a interface que está `ComPtr`associado e gerenciado por isso .

```cpp
InterfaceType *ptr_;
```

### <a name="remarks"></a>Comentários

`ptr_`é um membro de dados interno e protegido.

## <a name="comptrreleaseandgetaddressof"></a><a name="releaseandgetaddressof"></a>Comptr::releaseAndGetAddressOf

Libera a interface associada `ComPtr` a isso e, em seguida, recupera o endereço do membro de dados [ptr_,](#ptr) que contém um ponteiro para a interface que foi lançada.

```cpp
T** ReleaseAndGetAddressOf();
```

### <a name="return-value"></a>Valor retornado

O endereço do [ptr_](#ptr) membro `ComPtr`de dados deste .

## <a name="comptrreset"></a><a name="reset"></a>ComPtr::Reset

Libera todas as referências para o ponteiro para `ComPtr`a interface associada a isso .

```cpp
unsigned long Reset();
```

### <a name="return-value"></a>Valor retornado

O número de referências liberadas, se houver.

## <a name="comptrswap"></a><a name="swap"></a>ComPtr::Swap

Troca a interface gerenciada `ComPtr` pela corrente com a `ComPtr`interface gerenciada pelo especificado .

```cpp
void Swap(
   _Inout_ ComPtr&& r
);

void Swap(
   _Inout_ ComPtr& r
);
```

### <a name="parameters"></a>Parâmetros

*r*<br/>
Um `ComPtr`.
