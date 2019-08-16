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
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69498408"
---
# <a name="comptr-class"></a>Classe ComPtr

Cria um tipo de *ponteiro inteligente* que representa a interface especificada pelo parâmetro de modelo. `ComPtr`mantém automaticamente uma contagem de referência para o ponteiro de interface subjacente e libera a interface quando a contagem de referência chega a zero.

## <a name="syntax"></a>Sintaxe

```cpp
template <typename T>
class ComPtr;

template<class T>
friend class ComPtr;
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
A interface que o `ComPtr` representa.

*U*<br/>
Uma classe à qual o atual `ComPtr` é um amigo. (O modelo que usa esse parâmetro é protegido.)

## <a name="remarks"></a>Comentários

`ComPtr<>`declara um tipo que representa o ponteiro de interface subjacente. Use `ComPtr<>` para declarar uma variável e, em seguida, use a seta member-`->`Access Operator () para acessar uma função de membro de interface.

Para obter mais informações sobre os apontadores inteligentes, consulte a subseção "ponteiros inteligentes COM" do tópico [práticas de codificação com](/windows/win32/LearnWin32/com-coding-practices) na biblioteca MSDN.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

Nome            | Descrição
--------------- | ---------------------------------------------------------------
`InterfaceType` | Um sinônimo para o tipo especificado pelo parâmetro *T* template.

### <a name="public-constructors"></a>Construtores públicos

Nome                             | Descrição
-------------------------------- | --------------------------------------------------------------------------------------------------------------------
[ComPtr::ComPtr](#comptr)        | Intializes uma nova instância da `ComPtr` classe. Sobrecargas fornecem construtores padrão, copiar, mover e conversão.
[ComPtr:: ~ ComPtr](#tilde-comptr) | Desinicializa uma instância do `ComPtr`.

### <a name="public-methods"></a>Métodos públicos

Nome                                                      | Descrição
--------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
[ComPtr:: as](#as)                                         | Retorna um `ComPtr` objeto que representa a interface identificada pelo parâmetro de modelo especificado.
[ComPtr::AsIID](#asiid)                                   | Retorna um `ComPtr` objeto que representa a interface identificada pela ID de interface especificada.
[ComPtr:: asfraca](#asweak)                                 | Recupera uma referência fraca para o objeto atual.
[ComPtr:: Attach](#attach)                                 | Associa isso `ComPtr` ao tipo de interface especificado pelo parâmetro de tipo de modelo atual.
[ComPtr::CopyTo](#copyto)                                 | Copia a interface atual ou especificada associada a isso `ComPtr` para o ponteiro de saída especificado.
[ComPtr::Detach](#detach)                                 | Desassocia isso `ComPtr` da interface que ele representa.
[ComPtr:: Get](#get)                                       | Recupera um ponteiro para a interface que está associada a isso `ComPtr`.
[ComPtr::GetAddressOf](#getaddressof)                     | Recupera o endereço do membro de dados [ptr_](#ptr) , que contém um ponteiro para a interface representada por isso `ComPtr`.
[ComPtr::ReleaseAndGetAddressOf](#releaseandgetaddressof) | Libera a interface associada a essa `ComPtr` e, em seguida, recupera o endereço do membro de dados [ptr_](#ptr) , que contém um ponteiro para a interface que foi lançada.
[ComPtr::Reset](#reset)                                   | Libera Todas as referências para o ponteiro para a interface que está associada a `ComPtr`isso.
[ComPtr:: swap](#swap)                                     | Troca a interface gerenciada pelo atual `ComPtr` com a interface gerenciada pelo especificado. `ComPtr`

### <a name="protected-methods"></a>Métodos Protegidos

Nome                                        | Descrição
------------------------------------------- | --------------------------------------------------------------------------------
[ComPtr::InternalAddRef](#internaladdref)   | Incrementa a contagem de referência da interface associada a isso `ComPtr`.
[ComPtr:: InternalRelease](#internalrelease) | Executa uma operação de liberação COM na interface associada a isso `ComPtr`.

### <a name="public-operators"></a>Operadores públicos

Nome                                                                                           | Descrição
---------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------
[Operador ComPtr:: operator &](#operator-ampersand)                                                       | Recupera o endereço do atual `ComPtr`.
[ComPtr::operator->](#operator-arrow)                                                          | Recupera um ponteiro para o tipo especificado pelo parâmetro de modelo atual.
[ComPtr::operator=](#operator-assign)                                                          | Atribui um valor ao atual `ComPtr`.
[ComPtr::operator==](#operator-equality)                                                       | Indica se dois objetos `ComPtr` são iguais.
[ComPtr::operator!=](#operator-inequality)                                                     | Indica se dois objetos `ComPtr` não são iguais.
[ComPtr:: Operator Microsoft:: WRL::D etalhes:: Booltype](#operator-microsoft-wrl-details-booltype) | Indica se um `ComPtr` está gerenciando o tempo de vida do objeto de uma interface.

### <a name="protected-data-members"></a>Membros de dados protegidos

Nome                 | Descrição
-------------------- | ------------------------------------------------------------------------------------------
[ComPtr::ptr_](#ptr) | Contém um ponteiro para a interface que está associada e gerenciada por isso `ComPtr`.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ComPtr`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Client. h

**Namespace:** Microsoft::WRL

## <a name="tilde-comptr"></a>ComPtr:: ~ ComPtr

Desinicializa uma instância do `ComPtr`.

```cpp
WRL_NOTHROW ~ComPtr();
```

## <a name="as"></a>ComPtr:: as

Retorna um `ComPtr` objeto que representa a interface identificada pelo parâmetro de modelo especificado.

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

*p*<br/>
Um `ComPtr` objeto que representa a interface especificada pelo parâmetro *U*. O parâmetro *p* não deve se referir `ComPtr` ao objeto atual.

### <a name="remarks"></a>Comentários

O primeiro modelo é o formulário que você deve usar em seu código. O segundo modelo é uma especialização interna e auxiliar que C++ dá suporte a recursos de idioma, como a palavra-chave auto-dedução de tipo [automático](../../cpp/auto-cpp.md) .

### <a name="return-value"></a>Valor de retorno

S_OK se for bem-sucedido; caso contrário, um HRESULT que indica o erro.

## <a name="asiid"></a>ComPtr::AsIID

Retorna um `ComPtr` objeto que representa a interface identificada pela ID de interface especificada.

```cpp
WRL_NOTHROW HRESULT AsIID(
   REFIID riid,
   _Out_ ComPtr<IUnknown>* p
) const;
```

### <a name="parameters"></a>Parâmetros

*riid*<br/>
Uma ID de interface.

*p*<br/>
Se o objeto tiver uma interface cuja ID é igual a *riid*, um ponteiro de indireto duplo para a interface especificado pelo parâmetro *riid* ; caso contrário, um ponteiro `IUnknown`para.

### <a name="return-value"></a>Valor de retorno

S_OK se for bem-sucedido; caso contrário, um HRESULT que indica o erro.

## <a name="asweak"></a>ComPtr:: asfraca

Recupera uma referência fraca para o objeto atual.

```cpp
HRESULT AsWeak(
   _Out_ WeakRef* pWeakRef
);
```

### <a name="parameters"></a>Parâmetros

*pWeakRef*<br/>
Quando essa operação é concluída, um ponteiro para um objeto de referência fraca.

### <a name="return-value"></a>Valor de retorno

S_OK se for bem-sucedido; caso contrário, um HRESULT que indica o erro.

## <a name="attach"></a>ComPtr:: Attach

Associa isso `ComPtr` ao tipo de interface especificado pelo parâmetro de tipo de modelo atual.

```cpp
void Attach(
   _In_opt_ InterfaceType* other
);
```

### <a name="parameters"></a>Parâmetros

*other*<br/>
Um tipo de interface.

## <a name="comptr"></a>ComPtr:: ComPtr

Intializes uma nova instância da `ComPtr` classe. Sobrecargas fornecem construtores padrão, copiar, mover e conversão.

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

*other*<br/>
Um objeto do tipo *U*.

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

O primeiro construtor é o construtor padrão, que especificada implícita cria um objeto vazio. O segundo construtor Especifica [__nullptr](../../extensions/nullptr-cpp-component-extensions.md), que cria explicitamente um objeto vazio.

O terceiro construtor cria um objeto do objeto especificado por um ponteiro. O ComPtr agora possui a memória apontada para e mantém uma contagem de referência para ele.

Os quarto e quinto construtores são construtores de cópia. O quinto Construtor copiará um objeto se ele for convertido para o tipo atual.

O sexto e o sétimo construtores são construtores de movimentação. O sétimo Construtor moverá um objeto se ele for convertido para o tipo atual.

## <a name="copyto"></a>ComPtr:: CopyTo

Copia a interface atual ou especificada associada a ela `ComPtr` para o ponteiro especificado.

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

*ptr*<br/>
Quando essa operação for concluída, um ponteiro para a interface solicitada.

*riid*<br/>
Uma ID de interface.

### <a name="return-value"></a>Valor de retorno

S_OK se for bem-sucedido; caso contrário, um HRESULT que indica por que `QueryInterface` a operação implícita falhou.

### <a name="remarks"></a>Comentários

A primeira função retorna uma cópia de um ponteiro para a interface associada a isso `ComPtr`. Essa função sempre retorna S_OK.

A segunda função executa uma `QueryInterface` operação na interface associada a ela `ComPtr` para a interface especificada pelo parâmetro *riid* .

A terceira função executa uma `QueryInterface` operação na interface associada a ela `ComPtr` para a interface subjacente do parâmetro *U* .

## <a name="detach"></a>ComPtr::Detach

Desassocia esse `ComPtr` objeto da interface que ele representa.

```cpp
T* Detach();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para a interface que foi representada por esse `ComPtr` objeto.

## <a name="get"></a>ComPtr:: Get

Recupera um ponteiro para a interface que está associada a isso `ComPtr`.

```cpp
T* Get() const;
```

### <a name="return-value"></a>Valor de retorno

Ponteiro para a interface que está associada a isso `ComPtr`.

## <a name="getaddressof"></a>ComPtr::GetAddressOf

Recupera o endereço do membro de dados [ptr_](#ptr) , que contém um ponteiro para a interface representada por isso `ComPtr`.

```cpp
T* const* GetAddressOf() const;
T** GetAddressOf();
```

### <a name="return-value"></a>Valor de retorno

O endereço de uma variável.

## <a name="internaladdref"></a>ComPtr::InternalAddRef

Incrementa a contagem de referência da interface associada a isso `ComPtr`.

```cpp
void InternalAddRef() const;
```

### <a name="remarks"></a>Comentários

Esse método é protegido.

## <a name="internalrelease"></a>ComPtr:: InternalRelease

Executa uma operação de liberação COM na interface associada a isso `ComPtr`.

```cpp
void InternalRelease();
```

### <a name="remarks"></a>Comentários

Esse método é protegido.

## <a name="operator-ampersand"></a>ComPtr::operator&amp;

Libera a interface associada a esse `ComPtr` objeto e, em seguida, recupera o `ComPtr` endereço do objeto.

```cpp
Details::ComPtrRef<WeakRef> operator&()

const Details::ComPtrRef<const WeakRef> operator&() const
```

### <a name="return-value"></a>Valor de retorno

Uma referência fraca para a atual `ComPtr`.

### <a name="remarks"></a>Comentários

Esse método difere de [ComPtr:: Getaddressof](#getaddressof) , pois esse método libera uma referência ao ponteiro da interface. Use `ComPtr::GetAddressOf` quando você precisar do endereço do ponteiro da interface, mas não quiser liberar essa interface.

## <a name="operator-arrow"></a>ComPtr::operator-&gt;

Recupera um ponteiro para o tipo especificado pelo parâmetro de modelo atual.

```cpp
WRL_NOTHROW Microsoft::WRL::Details::RemoveIUnknown<InterfaceType>* operator->() const;
```

### <a name="return-value"></a>Valor de retorno

Ponteiro para o tipo especificado pelo nome do tipo de modelo atual.

### <a name="remarks"></a>Comentários

Essa função auxiliar remove a sobrecarga desnecessária causada pelo uso da macro STDMETHOD. Essa função faz `IUnknown` tipos `private` em vez `virtual`de.

## <a name="operator-assign"></a>ComPtr:: Operator =

Atribui um valor ao atual `ComPtr`.

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
Uma classe.

*other*<br/>
Uma referência de ponteiro, referência ou rvalue para um tipo ou outro `ComPtr`.

### <a name="return-value"></a>Valor de retorno

Uma referência ao atual `ComPtr`.

### <a name="remarks"></a>Comentários

A primeira versão desse operador atribui um valor vazio ao atual `ComPtr`.

Na segunda versão, se o ponteiro de interface de atribuição não for o mesmo que o ponteiro de `ComPtr` interface atual, o segundo ponteiro de interface será atribuído ao atual `ComPtr`.

Na terceira versão, o ponteiro de interface de atribuição é atribuído ao atual `ComPtr`.

Na quarta versão, se o ponteiro de interface do valor de atribuição não for igual ao ponteiro de interface atual `ComPtr` , o segundo ponteiro de interface será atribuído ao atual. `ComPtr`

A quinta versão é um operador de cópia; uma referência a um `ComPtr` é atribuída ao atual. `ComPtr`

A sexta versão é um operador de cópia que usa semântica de movimentação; uma referência rvalue a um `ComPtr` se qualquer tipo é uma conversão estática e, em seguida, `ComPtr`atribuída ao atual.

A sétima versão é um operador de cópia que usa semântica de movimentação; uma referência rvalue a um `ComPtr` do tipo *U* é uma conversão estática e atribuída ao atual `ComPtr`.

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

### <a name="parameters"></a>Parâmetros

*a*<br/>
Uma referência a um objeto `ComPtr`.

*b*<br/>
Uma referência a outro `ComPtr` objeto.

### <a name="return-value"></a>Valor de retorno

O primeiro operador `true` produz se o objeto *a* é igual a Object *b*; caso contrário `false`,.

O segundo e o terceiro operadores `true` produzem se *o objeto a* é `nullptr`igual a; `false`caso contrário,.

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

### <a name="parameters"></a>Parâmetros

*a*<br/>
Uma referência a um objeto `ComPtr`.

*b*<br/>
Uma referência a outro `ComPtr` objeto.

### <a name="return-value"></a>Valor de retorno

O primeiro operador `true` produz se o objeto *a* não é igual a Object *b*; caso contrário `false`,.

O segundo e o terceiro operadores `true` produzem se *o objeto a* não for `nullptr`igual a; `false`caso contrário,.

## <a name="operator-microsoft-wrl-details-booltype"></a>ComPtr:: Operator Microsoft:: WRL::D etalhes:: Booltype

Indica se um `ComPtr` está gerenciando o tempo de vida do objeto de uma interface.

```cpp
WRL_NOTHROW operator Microsoft::WRL::Details::BoolType() const;
```

### <a name="return-value"></a>Valor de retorno

Se uma interface estiver associada a isso `ComPtr`, o endereço do membro de dados [BoolStruct:: member](boolstruct-structure.md#member) ; caso contrário `nullptr`,.

## <a name="ptr"></a>ComPtr::ptr_

Contém um ponteiro para a interface que está associada e gerenciada por isso `ComPtr`.

```cpp
InterfaceType *ptr_;
```

### <a name="remarks"></a>Comentários

`ptr_`é um membro de dados interno e protegido.

## <a name="releaseandgetaddressof"></a>ComPtr::ReleaseAndGetAddressOf

Libera a interface associada a essa `ComPtr` e, em seguida, recupera o endereço do membro de dados [ptr_](#ptr) , que contém um ponteiro para a interface que foi lançada.

```cpp
T** ReleaseAndGetAddressOf();
```

### <a name="return-value"></a>Valor de retorno

O endereço do membro de dados [ptr_](#ptr) deste `ComPtr`.

## <a name="reset"></a>ComPtr::Reset

Libera Todas as referências para o ponteiro para a interface que está associada a `ComPtr`isso.

```cpp
unsigned long Reset();
```

### <a name="return-value"></a>Valor de retorno

O número de referências liberadas, se houver.

## <a name="swap"></a>ComPtr:: swap

Troca a interface gerenciada pelo atual `ComPtr` com a interface gerenciada pelo especificado. `ComPtr`

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

