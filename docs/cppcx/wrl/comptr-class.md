---
title: Classe ComPtr
ms.date: 10/01/2018
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
ms.openlocfilehash: 9e5b2419f070ead17e72b1642f510f74bad8260e
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "58783781"
---
# <a name="comptr-class"></a>Classe ComPtr

Cria uma *ponteiro inteligente* tipo que representa a interface especificada pelo parâmetro de modelo. `ComPtr` automaticamente mantém uma contagem de referência para o ponteiro de interface subjacente e libera a interface quando a contagem de referência chega a zero.

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
Uma classe à qual atual `ComPtr` é um amigo. (O modelo que usa esse parâmetro é protegido).

## <a name="remarks"></a>Comentários

`ComPtr<>` declara um tipo que representa o ponteiro de interface subjacente. Use `ComPtr<>` para declarar uma variável e, em seguida, use o operador de acesso de membro de seta (`->`) para acessar uma função de membro de interface.

Para obter mais informações sobre ponteiros inteligentes, consulte a subseção "Ponteiros inteligentes COM" a [práticas recomendadas de codificação COM](/windows/desktop/LearnWin32/com-coding-practices) tópico na biblioteca MSDN.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

Nome            | Descrição
--------------- | ---------------------------------------------------------------
`InterfaceType` | Um sinônimo para o tipo especificado o *T* parâmetro de modelo.

### <a name="public-constructors"></a>Construtores públicos

Nome                             | Descrição
-------------------------------- | --------------------------------------------------------------------------------------------------------------------
[ComPtr::ComPtr](#comptr)        | Inicializa uma nova instância do `ComPtr` classe. Sobrecargas fornecem construtores padrão, copiar, mover e conversão.
[ComPtr::~ComPtr](#tilde-comptr) | Realiza o desligamento de uma instância de `ComPtr`.

### <a name="public-methods"></a>Métodos públicos

Nome                                                      | Descrição
--------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
[ComPtr::As](#as)                                         | Retorna um `ComPtr` objeto que representa a interface identificada pelo parâmetro de modelo especificado.
[ComPtr::AsIID](#asiid)                                   | Retorna um `ComPtr` objeto que representa a interface identificada pela ID da interface especificada.
[ComPtr::AsWeak](#asweak)                                 | Recupera uma referência fraca ao objeto atual.
[ComPtr::Attach](#attach)                                 | Associa isso `ComPtr` com o tipo de interface especificado pelo parâmetro de tipo de modelo atual.
[ComPtr::CopyTo](#copyto)                                 | Copia a interface atual ou especificada associada a este `ComPtr` para o ponteiro de saída especificado.
[ComPtr::Detach](#detach)                                 | Desassocia isso `ComPtr` da interface que ele representa.
[ComPtr::Get](#get)                                       | Recupera um ponteiro para a interface que está associado a este `ComPtr`.
[ComPtr::GetAddressOf](#getaddressof)                     | Recupera o endereço do [PTR _](#ptr) membro de dados, que contém um ponteiro para a interface representado por este `ComPtr`.
[ComPtr::ReleaseAndGetAddressOf](#releaseandgetaddressof) | Libera a interface associada a este `ComPtr` e, em seguida, recupera o endereço do [PTR _](#ptr) membro de dados, que contém um ponteiro para a interface que foi lançado.
[ComPtr::Reset](#reset)                                   | Libera todas as referências para o ponteiro para a interface que está associado a este `ComPtr`.
[ComPtr::Swap](#swap)                                     | Troca a interface gerenciada pelo atual `ComPtr` com a interface gerenciada pelo especificado `ComPtr`.

### <a name="protected-methods"></a>Métodos Protegidos

Nome                                        | Descrição
------------------------------------------- | --------------------------------------------------------------------------------
[ComPtr::InternalAddRef](#internaladdref)   | Incrementa a contagem de referência da interface associada a este `ComPtr`.
[ComPtr::InternalRelease](#internalrelease) | Executa uma operação de lançamento COM na interface associado a este `ComPtr`.

### <a name="public-operators"></a>Operadores públicos

Nome                                                                                           | Descrição
---------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------
[ComPtr::operator&](#operator-ampersand)                                                       | Recupera o endereço da atual `ComPtr`.
[ComPtr::operator->](#operator-arrow)                                                          | Recupera um ponteiro para o tipo especificado pelo parâmetro de modelo atual.
[ComPtr::operator=](#operator-assign)                                                          | Atribui um valor para a atual `ComPtr`.
[ComPtr::operator==](#operator-equality)                                                       | Indica se dois objetos `ComPtr` são iguais.
[ComPtr::operator!=](#operator-inequality)                                                     | Indica se dois objetos `ComPtr` não são iguais.
[Comptr:: Operator booltype](#operator-microsoft-wrl-details-booltype) | Indica se um `ComPtr` está gerenciando o tempo de vida do objeto de uma interface.

### <a name="protected-data-members"></a>Membros de dados protegidos

Nome                 | Descrição
-------------------- | ------------------------------------------------------------------------------------------
[ComPtr::ptr_](#ptr) | Contém um ponteiro para a interface que está associado e gerenciada por esse `ComPtr`.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ComPtr`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** client.h

**Namespace:** Microsoft::WRL

## <a name="tilde-comptr"></a>ComPtr::~ComPtr

Realiza o desligamento de uma instância de `ComPtr`.

```cpp
WRL_NOTHROW ~ComPtr();
```

## <a name="as"></a>ComPtr::As

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
A interface a ser representado pelo parâmetro *p*.

*p*<br/>
Um `ComPtr` objeto que representa a interface especificada pelo parâmetro *U*. Parâmetro *p* não deve se referir a atual `ComPtr` objeto.

### <a name="remarks"></a>Comentários

O primeiro modelo é a forma que você deve usar em seu código. O segundo modelo é uma especialização de auxiliar interno, que dá suporte a recursos da linguagem C++, como o [automática](../../cpp/auto-cpp.md) palavra-chave de dedução de tipo.

### <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, um HRESULT que indica o erro.

## <a name="asiid"></a>ComPtr::AsIID

Retorna um `ComPtr` objeto que representa a interface identificada pela ID da interface especificada.

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
Se o objeto tem uma interface cuja ID é igual a *riid*, um ponteiro indireto duplamente para a interface especificada pelo *riid* parâmetro; caso contrário, um ponteiro para `IUnknown`.

### <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, um HRESULT que indica o erro.

## <a name="asweak"></a>ComPtr::AsWeak

Recupera uma referência fraca ao objeto atual.

```cpp
HRESULT AsWeak(
   _Out_ WeakRef* pWeakRef
);
```

### <a name="parameters"></a>Parâmetros

*pWeakRef*<br/>
Quando essa operação for concluída, um ponteiro para um objeto de referência fraca.

### <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, um HRESULT que indica o erro.

## <a name="attach"></a>ComPtr::Attach

Associa isso `ComPtr` com o tipo de interface especificado pelo parâmetro de tipo de modelo atual.

```cpp
void Attach(
   _In_opt_ InterfaceType* other
);
```

### <a name="parameters"></a>Parâmetros

*other*<br/>
Um tipo de interface.

## <a name="comptr"></a>ComPtr::ComPtr

Inicializa uma nova instância do `ComPtr` classe. Sobrecargas fornecem construtores padrão, copiar, mover e conversão.

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
   typename ENABLE_IF<__is_convertible_to(U*,
   T*),
   void *>;
WRL_NOTHROW ComPtr(
   _Inout_ ComPtr &&other
);
template<class U>
WRL_NOTHROW ComPtr(
   _Inout_ ComPtr<U>&& other,
   typename ENABLE_IF<__is_convertible_to(U*,
   T*),
   void *>;
```

### <a name="parameters"></a>Parâmetros

*U*<br/>
O tipo dos *outros* parâmetro.

*other*<br/>
Um objeto do tipo *U*.

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

O primeiro construtor é o construtor padrão, quais implícita cria um objeto vazio. Especifica o segundo construtor [nullptr](../../extensions/nullptr-cpp-component-extensions.md), que cria explicitamente um objeto vazio.

O terceiro construtor cria um objeto do objeto especificado por um ponteiro.

Os construtores quarto e quintas são construtores de cópia. O quinto construtor copia um objeto se ele for conversível para o tipo atual.

Os sexto e sétimo construtores são construtores de movimentação. O sétimo construtor move um objeto se ele for conversível para o tipo atual.

## <a name="copyto"></a>ComPtr::CopyTo

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

### <a name="parameters"></a>Parâmetros

*U*<br/>
O nome de um tipo.

*ptr*<br/>
Quando essa operação for concluída, um ponteiro para a interface solicitada.

*riid*<br/>
Uma ID de interface.

### <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, um HRESULT que indica por que o implícita `QueryInterface` Falha na operação.

### <a name="remarks"></a>Comentários

A primeira função retorna uma cópia de um ponteiro para a interface associada a este `ComPtr`. Esta função sempre retorna S_OK.

A segunda função executa um `QueryInterface` operação na interface associado a este `ComPtr` para a interface especificada pelo *riid* parâmetro.

A terceira função executa um `QueryInterface` operação na interface associado a este `ComPtr` para a interface subjacente dos *U* parâmetro.

## <a name="detach"></a>ComPtr::Detach

Desassocia isso `ComPtr` objeto da interface que ele representa.

```cpp
T* Detach();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para a interface que fosse representado por este `ComPtr` objeto.

## <a name="get"></a>ComPtr::Get

Recupera um ponteiro para a interface que está associado a este `ComPtr`.

```cpp
T* Get() const;
```

### <a name="return-value"></a>Valor de retorno

Ponteiro para a interface que está associado a este `ComPtr`.

## <a name="getaddressof"></a>ComPtr::GetAddressOf

Recupera o endereço do [PTR _](#ptr) membro de dados, que contém um ponteiro para a interface representado por este `ComPtr`.

```cpp
T* const* GetAddressOf() const;
T** GetAddressOf();
```

### <a name="return-value"></a>Valor de retorno

O endereço de uma variável.

## <a name="internaladdref"></a>ComPtr::InternalAddRef

Incrementa a contagem de referência da interface associada a este `ComPtr`.

```cpp
void InternalAddRef() const;
```

### <a name="remarks"></a>Comentários

Esse método é protegido.

## <a name="internalrelease"></a>ComPtr::InternalRelease

Executa uma operação de lançamento COM na interface associado a este `ComPtr`.

```cpp
void InternalRelease();
```

### <a name="remarks"></a>Comentários

Esse método é protegido.

## <a name="operator-ampersand"></a>ComPtr::operator&amp;

Libera a interface associada a este `ComPtr` do objeto e, em seguida, recupera o endereço do `ComPtr` objeto.

```cpp
Details::ComPtrRef<WeakRef> operator&()

const Details::ComPtrRef<const WeakRef> operator&() const
```

### <a name="return-value"></a>Valor de retorno

Uma referência fraca para a atual `ComPtr`.

### <a name="remarks"></a>Comentários

Esse método difere [comptr:: Getaddressof](#getaddressof) em que esse método libera uma referência para o ponteiro de interface. Use `ComPtr::GetAddressOf` quando você exigir o endereço do ponteiro da interface, mas não deseja liberar essa interface.

## <a name="operator-arrow"></a>ComPtr::operator-&gt;

Recupera um ponteiro para o tipo especificado pelo parâmetro de modelo atual.

```cpp
WRL_NOTHROW Microsoft::WRL::Details::RemoveIUnknown<InterfaceType>* operator->() const;
```

### <a name="return-value"></a>Valor de retorno

Ponteiro para o tipo especificado pelo nome do tipo de modelo atual.

### <a name="remarks"></a>Comentários

Essa função auxiliar remove causada pelo uso a macro STDMETHOD uma sobrecarga desnecessária. Essa função faz `IUnknown` tipos `private` em vez de `virtual`.

## <a name="operator-assign"></a>ComPtr::operator=

Atribui um valor para a atual `ComPtr`.

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
Um ponteiro, referência ou referência rvalue para um tipo ou outro `ComPtr`.

### <a name="return-value"></a>Valor de retorno

Uma referência ao atual `ComPtr`.

### <a name="remarks"></a>Comentários

A primeira versão deste operador atribui um valor vazio para a atual `ComPtr`.

Na segunda versão, se o ponteiro de interface de atribuição não é o mesmo que o atual `ComPtr` ponteiro de interface, o segundo ponteiro de interface é atribuído ao atual `ComPtr`.

A terceira versão, o ponteiro de interface de atribuição é atribuído a atual `ComPtr`.

Na quarta versão, se o ponteiro de interface do valor de atribuição não é o mesmo que o atual `ComPtr` ponteiro de interface, o segundo ponteiro de interface é atribuído ao atual `ComPtr`.

A quinta versão é um operador de cópia; uma referência a um `ComPtr` for atribuído a atual `ComPtr`.

A versão do sexta é um operador de cópia que usa semântica; uma referência rvalue para um `ComPtr` se qualquer tipo for estático, converter e, em seguida, é atribuído ao atual `ComPtr`.

A versão do sétima é um operador de cópia que usa semântica; uma referência rvalue para um `ComPtr` do tipo *U* é estático convertido, em seguida e atribuído a atual `ComPtr`.

## <a name="operator-equality"></a>ComPtr::operator==

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

A primeira produz do operador `true` se objeto *um* é igual ao objeto *b*; caso contrário, `false`.

Os operadores de segundo e terceiro yield `true` se objeto *um* é igual a `nullptr`; caso contrário, `false`.

## <a name="operator-inequality"></a>ComPtr::operator!=

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

A primeira produz do operador `true` se objeto *um* não é igual ao objeto *b*; caso contrário, `false`.

Os operadores de segundo e terceiro yield `true` se objeto *um* não é igual a `nullptr`; caso contrário, `false`.

## <a name="operator-microsoft-wrl-details-booltype"></a>Comptr:: Operator booltype

Indica se um `ComPtr` está gerenciando o tempo de vida do objeto de uma interface.

```cpp
WRL_NOTHROW operator Microsoft::WRL::Details::BoolType() const;
```

### <a name="return-value"></a>Valor de retorno

Se uma interface é associada a este `ComPtr`, o endereço do [boolstruct::](boolstruct-structure.md#member) membro de dados; caso contrário, `nullptr`.

## <a name="ptr"></a>ComPtr::ptr_

Contém um ponteiro para a interface que está associado e gerenciada por esse `ComPtr`.

```cpp
InterfaceType *ptr_;
```

### <a name="remarks"></a>Comentários

`ptr_` é um membro de dados interno, protegido.

## <a name="releaseandgetaddressof"></a>ComPtr::ReleaseAndGetAddressOf

Libera a interface associada a este `ComPtr` e, em seguida, recupera o endereço do [PTR _](#ptr) membro de dados, que contém um ponteiro para a interface que foi lançado.

```cpp
T** ReleaseAndGetAddressOf();
```

### <a name="return-value"></a>Valor de retorno

O endereço do [PTR _](#ptr) membro de dados desta `ComPtr`.

## <a name="reset"></a>ComPtr::Reset

Libera todas as referências para o ponteiro para a interface que está associado a este `ComPtr`.

```cpp
unsigned long Reset();
```

### <a name="return-value"></a>Valor de retorno

O número de referências liberado, se houver.

## <a name="swap"></a>ComPtr::Swap

Troca a interface gerenciada pelo atual `ComPtr` com a interface gerenciada pelo especificado `ComPtr`.

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

