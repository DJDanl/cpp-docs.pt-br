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
ms.openlocfilehash: 1e20a991c8f32027aeea6a17df0534aa6e1c2c43
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79418317"
---
# <a name="comptr-class"></a>Classe ComPtr

Cria um tipo de *ponteiro inteligente* que representa a interface especificada pelo parâmetro de modelo. `ComPtr` mantém automaticamente uma contagem de referência para o ponteiro de interface subjacente e libera a interface quando a contagem de referência chega a zero.

## <a name="syntax"></a>Sintaxe

```cpp
template <typename T>
class ComPtr;

template<class T>
friend class ComPtr;
```

### <a name="parameters"></a>parâmetros

*T*<br/>
A interface que o `ComPtr` representa.

*U*<br/>
Uma classe à qual a `ComPtr` atual é um amigo. (O modelo que usa esse parâmetro é protegido.)

## <a name="remarks"></a>Comentários

`ComPtr<>` declara um tipo que representa o ponteiro de interface subjacente. Use `ComPtr<>` para declarar uma variável e, em seguida, use o operador de acesso para membro de seta (`->`) para acessar uma função de membro de interface.

Para obter mais informações sobre os apontadores inteligentes, consulte a subseção "ponteiros inteligentes COM" do tópico [práticas de codificação com](/windows/win32/LearnWin32/com-coding-practices) na biblioteca MSDN.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs Públicos

Nome            | DESCRIÇÃO
--------------- | ---------------------------------------------------------------
`InterfaceType` | Um sinônimo para o tipo especificado pelo parâmetro *T* template.

### <a name="public-constructors"></a>Construtores públicos

Nome                             | DESCRIÇÃO
-------------------------------- | --------------------------------------------------------------------------------------------------------------------
[ComPtr:: ComPtr](#comptr)        | Intializes uma nova instância da classe `ComPtr`. Sobrecargas fornecem construtores padrão, copiar, mover e conversão.
[ComPtr:: ~ ComPtr](#tilde-comptr) | Desinicializa uma instância do `ComPtr`.

### <a name="public-methods"></a>Métodos públicos

Nome                                                      | DESCRIÇÃO
--------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
[ComPtr:: as](#as)                                         | Retorna um objeto `ComPtr` que representa a interface identificada pelo parâmetro de modelo especificado.
[ComPtr:: AsIID](#asiid)                                   | Retorna um objeto `ComPtr` que representa a interface identificada pela ID de interface especificada.
[ComPtr:: asfraca](#asweak)                                 | Recupera uma referência fraca para o objeto atual.
[ComPtr:: Attach](#attach)                                 | Associa esse `ComPtr` ao tipo de interface especificado pelo parâmetro de tipo de modelo atual.
[ComPtr:: CopyTo](#copyto)                                 | Copia a interface atual ou especificada associada a este `ComPtr` para o ponteiro de saída especificado.
[ComPtr::D Etach](#detach)                                 | Desassocia esse `ComPtr` da interface que ele representa.
[ComPtr:: Get](#get)                                       | Recupera um ponteiro para a interface que está associada a este `ComPtr`.
[ComPtr:: getaddressof](#getaddressof)                     | Recupera o endereço do membro de dados [ptr_](#ptr) , que contém um ponteiro para a interface representada por esse `ComPtr`.
[ComPtr:: ReleaseAndGetAddressOf](#releaseandgetaddressof) | Libera a interface associada a este `ComPtr` e, em seguida, recupera o endereço do membro de dados [ptr_](#ptr) , que contém um ponteiro para a interface que foi lançada.
[ComPtr::Reset](#reset)                                   | Libera Todas as referências para o ponteiro para a interface que está associada a esse `ComPtr`.
[ComPtr:: swap](#swap)                                     | Troca a interface gerenciada pelo `ComPtr` atual com a interface gerenciada pelo `ComPtr`especificado.

### <a name="protected-methods"></a>Métodos protegidos

Nome                                        | DESCRIÇÃO
------------------------------------------- | --------------------------------------------------------------------------------
[ComPtr:: InternalAddRef](#internaladdref)   | Incrementa a contagem de referência da interface associada a este `ComPtr`.
[ComPtr:: InternalRelease](#internalrelease) | Executa uma operação de liberação COM na interface associada a este `ComPtr`.

### <a name="public-operators"></a>Operadores públicos

Nome                                                                                           | DESCRIÇÃO
---------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------
[Operador ComPtr:: operator &](#operator-ampersand)                                                       | Recupera o endereço do `ComPtr`atual.
[ComPtr:: operator->](#operator-arrow)                                                          | Recupera um ponteiro para o tipo especificado pelo parâmetro de modelo atual.
[ComPtr:: Operator =](#operator-assign)                                                          | Atribui um valor ao `ComPtr`atual.
[ComPtr:: Operator = =](#operator-equality)                                                       | Indica se dois objetos `ComPtr` são iguais.
[ComPtr:: Operator! =](#operator-inequality)                                                     | Indica se dois objetos `ComPtr` não são iguais.
[ComPtr:: Operator Microsoft:: WRL::D etalhes:: Booltype](#operator-microsoft-wrl-details-booltype) | Indica se um `ComPtr` está gerenciando o tempo de vida do objeto de uma interface.

### <a name="protected-data-members"></a>Membros de Dados Protegidos

Nome                 | DESCRIÇÃO
-------------------- | ------------------------------------------------------------------------------------------
[ComPtr::p tr_](#ptr) | Contém um ponteiro para a interface que está associada e gerenciada por este `ComPtr`.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ComPtr`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Client. h

**Namespace:** Microsoft:: WRL

## <a name="tilde-comptr"></a>ComPtr:: ~ ComPtr

Desinicializa uma instância do `ComPtr`.

```cpp
WRL_NOTHROW ~ComPtr();
```

## <a name="as"></a>ComPtr:: as

Retorna um objeto `ComPtr` que representa a interface identificada pelo parâmetro de modelo especificado.

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

### <a name="parameters"></a>parâmetros

*U*<br/>
A interface a ser representada pelo parâmetro *p*.

*p*<br/>
Um objeto `ComPtr` que representa a interface especificada pelo parâmetro *U*. O parâmetro *p* não deve fazer referência ao objeto de `ComPtr` atual.

### <a name="remarks"></a>Comentários

O primeiro modelo é o formulário que você deve usar em seu código. O segundo modelo é uma especialização interna e auxiliar que C++ dá suporte a recursos de idioma, como a palavra-chave auto-dedução de tipo [automático](../../cpp/auto-cpp.md) .

### <a name="return-value"></a>Valor retornado

S_OK se for bem-sucedido; caso contrário, um HRESULT que indica o erro.

## <a name="asiid"></a>ComPtr:: AsIID

Retorna um objeto `ComPtr` que representa a interface identificada pela ID de interface especificada.

```cpp
WRL_NOTHROW HRESULT AsIID(
   REFIID riid,
   _Out_ ComPtr<IUnknown>* p
) const;
```

### <a name="parameters"></a>parâmetros

*riid*<br/>
Uma ID de interface.

*p*<br/>
Se o objeto tiver uma interface cuja ID é igual a *riid*, um ponteiro de indireto duplo para a interface especificado pelo parâmetro *riid* ; caso contrário, um ponteiro para `IUnknown`.

### <a name="return-value"></a>Valor retornado

S_OK se for bem-sucedido; caso contrário, um HRESULT que indica o erro.

## <a name="asweak"></a>ComPtr:: asfraca

Recupera uma referência fraca para o objeto atual.

```cpp
HRESULT AsWeak(
   _Out_ WeakRef* pWeakRef
);
```

### <a name="parameters"></a>parâmetros

*pWeakRef*<br/>
Quando essa operação é concluída, um ponteiro para um objeto de referência fraca.

### <a name="return-value"></a>Valor retornado

S_OK se for bem-sucedido; caso contrário, um HRESULT que indica o erro.

## <a name="attach"></a>ComPtr:: Attach

Associa esse `ComPtr` ao tipo de interface especificado pelo parâmetro de tipo de modelo atual.

```cpp
void Attach(
   _In_opt_ InterfaceType* other
);
```

### <a name="parameters"></a>parâmetros

*other*<br/>
Um tipo de interface.

## <a name="comptr"></a>ComPtr:: ComPtr

Intializes uma nova instância da classe `ComPtr`. Sobrecargas fornecem construtores padrão, copiar, mover e conversão.

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

### <a name="parameters"></a>parâmetros

*U*<br/>
O tipo do *outro* parâmetro.

*other*<br/>
Um objeto do tipo *U*.

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

O primeiro construtor é o construtor padrão, que especificada implícita cria um objeto vazio. O segundo construtor Especifica [__nullptr](../../extensions/nullptr-cpp-component-extensions.md), que cria explicitamente um objeto vazio.

O terceiro construtor cria um objeto do objeto especificado por um ponteiro. O ComPtr agora possui a memória apontada para e mantém uma contagem de referência para ele.

Os quarto e quinto construtores são construtores de cópia. O quinto Construtor copiará um objeto se ele for convertido para o tipo atual.

O sexto e o sétimo construtores são construtores de movimentação. O sétimo Construtor moverá um objeto se ele for convertido para o tipo atual.

## <a name="copyto"></a>ComPtr:: CopyTo

Copia a interface atual ou especificada associada a este `ComPtr` para o ponteiro especificado.

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

### <a name="parameters"></a>parâmetros

*U*<br/>
O nome de um tipo.

*ptr*<br/>
Quando essa operação for concluída, um ponteiro para a interface solicitada.

*riid*<br/>
Uma ID de interface.

### <a name="return-value"></a>Valor retornado

S_OK se for bem-sucedido; caso contrário, um HRESULT que indica por que a operação de `QueryInterface` implícita falhou.

### <a name="remarks"></a>Comentários

A primeira função retorna uma cópia de um ponteiro para a interface associada a esse `ComPtr`. Essa função sempre retorna S_OK.

A segunda função executa uma operação `QueryInterface` na interface associada a esse `ComPtr` para a interface especificada pelo parâmetro *riid* .

A terceira função executa uma operação `QueryInterface` na interface associada a esse `ComPtr` para a interface subjacente do parâmetro *U* .

## <a name="detach"></a>ComPtr::D Etach

Desassocia esse `ComPtr` objeto da interface que ele representa.

```cpp
T* Detach();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para a interface que foi representada por esse objeto de `ComPtr`.

## <a name="get"></a>ComPtr:: Get

Recupera um ponteiro para a interface que está associada a este `ComPtr`.

```cpp
T* Get() const;
```

### <a name="return-value"></a>Valor retornado

Ponteiro para a interface que está associada a este `ComPtr`.

## <a name="getaddressof"></a>ComPtr:: getaddressof

Recupera o endereço do membro de dados [ptr_](#ptr) , que contém um ponteiro para a interface representada por esse `ComPtr`.

```cpp
T* const* GetAddressOf() const;
T** GetAddressOf();
```

### <a name="return-value"></a>Valor retornado

O endereço de uma variável.

## <a name="internaladdref"></a>ComPtr:: InternalAddRef

Incrementa a contagem de referência da interface associada a este `ComPtr`.

```cpp
void InternalAddRef() const;
```

### <a name="remarks"></a>Comentários

Esse método é protegido.

## <a name="internalrelease"></a>ComPtr:: InternalRelease

Executa uma operação de liberação COM na interface associada a este `ComPtr`.

```cpp
void InternalRelease();
```

### <a name="remarks"></a>Comentários

Esse método é protegido.

## <a name="operator-ampersand"></a>Operador ComPtr:: Operator&amp;

Libera a interface associada a este objeto `ComPtr` e, em seguida, recupera o endereço do objeto `ComPtr`.

```cpp
Details::ComPtrRef<WeakRef> operator&()

const Details::ComPtrRef<const WeakRef> operator&() const
```

### <a name="return-value"></a>Valor retornado

Uma referência fraca para o `ComPtr`atual.

### <a name="remarks"></a>Comentários

Esse método difere de [ComPtr:: Getaddressof](#getaddressof) , pois esse método libera uma referência ao ponteiro da interface. Use `ComPtr::GetAddressOf` quando você precisar do endereço do ponteiro da interface, mas não quiser liberar essa interface.

## <a name="operator-arrow"></a>ComPtr:: Operator-&gt;

Recupera um ponteiro para o tipo especificado pelo parâmetro de modelo atual.

```cpp
WRL_NOTHROW Microsoft::WRL::Details::RemoveIUnknown<InterfaceType>* operator->() const;
```

### <a name="return-value"></a>Valor retornado

Ponteiro para o tipo especificado pelo nome do tipo de modelo atual.

### <a name="remarks"></a>Comentários

Essa função auxiliar remove a sobrecarga desnecessária causada pelo uso da macro STDMETHOD. Essa função faz com que os tipos de `IUnknown` `private` em vez de `virtual`.

## <a name="operator-assign"></a>ComPtr:: Operator =

Atribui um valor ao `ComPtr`atual.

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

### <a name="parameters"></a>parâmetros

*U*<br/>
Uma classe.

*other*<br/>
Uma referência de ponteiro, referência ou rvalue para um tipo ou outro `ComPtr`.

### <a name="return-value"></a>Valor retornado

Uma referência à `ComPtr`atual.

### <a name="remarks"></a>Comentários

A primeira versão desse operador atribui um valor vazio ao `ComPtr`atual.

Na segunda versão, se o ponteiro de interface de atribuição não for o mesmo que o ponteiro de interface de `ComPtr` atual, o segundo ponteiro de interface será atribuído à `ComPtr`atual.

Na terceira versão, o ponteiro de interface de atribuição é atribuído à `ComPtr`atual.

Na quarta versão, se o ponteiro de interface do valor de atribuição não for igual ao ponteiro de interface de `ComPtr` atual, o segundo ponteiro de interface será atribuído à `ComPtr`atual.

A quinta versão é um operador de cópia; uma referência a um `ComPtr` é atribuída ao `ComPtr`atual.

A sexta versão é um operador de cópia que usa semântica de movimentação; uma referência rvalue a uma `ComPtr` se qualquer tipo for conversão estática e, em seguida, atribuído à `ComPtr`atual.

A sétima versão é um operador de cópia que usa semântica de movimentação; uma referência rvalue a um `ComPtr` do tipo *U* é uma conversão estática e atribuída ao `ComPtr`atual.

## <a name="operator-equality"></a>ComPtr:: Operator = =

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

### <a name="parameters"></a>parâmetros

*a*<br/>
Uma referência a um objeto `ComPtr`.

*b*<br/>
Uma referência a outro objeto de `ComPtr`.

### <a name="return-value"></a>Valor retornado

O primeiro operador produz `true` se o objeto *a* é igual ao objeto *b*; caso contrário, `false`.

O segundo e o terceiro operadores produzem `true` se *o objeto a* é igual a `nullptr`; caso contrário, `false`.

## <a name="operator-inequality"></a>ComPtr:: Operator! =

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

### <a name="parameters"></a>parâmetros

*a*<br/>
Uma referência a um objeto `ComPtr`.

*b*<br/>
Uma referência a outro objeto de `ComPtr`.

### <a name="return-value"></a>Valor retornado

O primeiro operador produz `true` se o objeto *a* não for igual ao objeto *b*; caso contrário, `false`.

O segundo e o terceiro operadores produzem `true` se *o objeto a* não for igual a `nullptr`; caso contrário, `false`.

## <a name="operator-microsoft-wrl-details-booltype"></a>ComPtr:: Operator Microsoft:: WRL::D etalhes:: Booltype

Indica se um `ComPtr` está gerenciando o tempo de vida do objeto de uma interface.

```cpp
WRL_NOTHROW operator Microsoft::WRL::Details::BoolType() const;
```

### <a name="return-value"></a>Valor retornado

Se uma interface estiver associada a esse `ComPtr`, o endereço do membro de dados [BoolStruct:: member](boolstruct-structure.md#member) ; caso contrário, `nullptr`.

## <a name="ptr"></a>ComPtr::p tr_

Contém um ponteiro para a interface que está associada e gerenciada por este `ComPtr`.

```cpp
InterfaceType *ptr_;
```

### <a name="remarks"></a>Comentários

`ptr_` é um membro de dados interno e protegido.

## <a name="releaseandgetaddressof"></a>ComPtr:: ReleaseAndGetAddressOf

Libera a interface associada a este `ComPtr` e, em seguida, recupera o endereço do membro de dados [ptr_](#ptr) , que contém um ponteiro para a interface que foi lançada.

```cpp
T** ReleaseAndGetAddressOf();
```

### <a name="return-value"></a>Valor retornado

O endereço do membro de dados [ptr_](#ptr) deste `ComPtr`.

## <a name="reset"></a>ComPtr:: Reset

Libera Todas as referências para o ponteiro para a interface que está associada a esse `ComPtr`.

```cpp
unsigned long Reset();
```

### <a name="return-value"></a>Valor retornado

O número de referências liberadas, se houver.

## <a name="swap"></a>ComPtr:: swap

Troca a interface gerenciada pelo `ComPtr` atual com a interface gerenciada pelo `ComPtr`especificado.

```cpp
void Swap(
   _Inout_ ComPtr&& r
);

void Swap(
   _Inout_ ComPtr& r
);
```

### <a name="parameters"></a>parâmetros

*r*<br/>
Um `ComPtr`.

