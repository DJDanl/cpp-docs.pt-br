---
title: Classe unique_ptr
ms.date: 11/04/2016
f1_keywords:
- memory/std::unique_ptr
- memory/std::unique_ptr::deleter_type
- memory/std::unique_ptr::element_type
- memory/std::unique_ptr::pointer
- memory/std::unique_ptr::get
- memory/std::unique_ptr::get_deleter
- memory/std::unique_ptr::release
- memory/std::unique_ptr::reset
- memory/std::unique_ptr::swap
helpviewer_keywords:
- std::unique_ptr [C++]
- std::unique_ptr [C++], deleter_type
- std::unique_ptr [C++], element_type
- std::unique_ptr [C++], pointer
- std::unique_ptr [C++], get
- std::unique_ptr [C++], get_deleter
- std::unique_ptr [C++], release
- std::unique_ptr [C++], reset
- std::unique_ptr [C++], swap
ms.assetid: acdf046b-831e-4a4a-83aa-6d4ee467db9a
ms.openlocfilehash: 4e6c7d8dd9835545c4aaa677a39f5e3149743d14
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88835669"
---
# <a name="unique_ptr-class"></a>Classe unique_ptr

Armazena um ponteiro para um objeto ou matriz possuído. O objeto/matriz não pertence a nenhum outro `unique_ptr`. O objeto/matriz é destruído quando `unique_ptr` é destruído.

## <a name="syntax"></a>Sintaxe

```cpp
class unique_ptr {
public:
    unique_ptr();
    unique_ptr(nullptr_t Nptr);
    explicit unique_ptr(pointer Ptr);
    unique_ptr(pointer Ptr,
        typename conditional<is_reference<Del>::value, Del,
        typename add_reference<const Del>::type>::type Deleter);
    unique_ptr(pointer Ptr,
        typename remove_reference<Del>::type&& Deleter);
    unique_ptr(unique_ptr&& Right);
    template <class T2, Class Del2>
    unique_ptr(unique_ptr<T2, Del2>&& Right);
    unique_ptr(const unique_ptr& Right) = delete;
    unique_ptr& operator=(const unique_ptr& Right) = delete;
};

//Specialization for arrays:
template <class T, class D>
class unique_ptr<T[], D> {
public:
    typedef pointer;
    typedef T element_type;
    typedef D deleter_type;
    constexpr unique_ptr() noexcept;
    template <class U>
    explicit unique_ptr(U p) noexcept;
    template <class U>
    unique_ptr(U p, see below d) noexcept;
    template <class U>
    unique_ptr(U p, see below d) noexcept;
    unique_ptr(unique_ptr&& u) noexcept;
    constexpr unique_ptr(nullptr_t) noexcept : unique_ptr() { }     template <class U, class E>
        unique_ptr(unique_ptr<U, E>&& u) noexcept;
    ~unique_ptr();
    unique_ptr& operator=(unique_ptr&& u) noexcept;
    template <class U, class E>
    unique_ptr& operator=(unique_ptr<U, E>&& u) noexcept;
    unique_ptr& operator=(nullptr_t) noexcept;
    T& operator[](size_t i) const;

    pointer get() const noexcept;
    deleter_type& get_deleter() noexcept;
    const deleter_type& get_deleter() const noexcept;
    explicit operator bool() const noexcept;
    pointer release() noexcept;
    void reset(pointer p = pointer()) noexcept;
    void reset(nullptr_t = nullptr) noexcept;
    template <class U>
    void reset(U p) noexcept = delete;
    void swap(unique_ptr& u) noexcept;  // disable copy from lvalue unique_ptr(const unique_ptr&) = delete;
    unique_ptr& operator=(const unique_ptr&) = delete;
};
```

### <a name="parameters"></a>parâmetros

*Certo*\
Um `unique_ptr`.

*Nptr*\
Um `rvalue` do tipo `std::nullptr_t`.

*PTR*\
Um `pointer`.

*Excluidor*\
Uma função `deleter` que é associada a `unique_ptr`.

## <a name="exceptions"></a>Exceções

Nenhuma exceção é gerada por `unique_ptr`.

## <a name="remarks"></a>Comentários

A classe `unique_ptr` substitui `auto_ptr` e pode ser usada como um elemento dos contêineres da Biblioteca Padrão C++.

Use a função auxiliar [make_unique](../standard-library/memory-functions.md#make_unique) para criar de modo eficiente novas instâncias de `unique_ptr`.

`unique_ptr` gerencia exclusivamente um recurso. Cada objeto `unique_ptr` armazena um ponteiro para o objeto que possui ou armazena um ponteiro nulo. Um recurso pode ser possuído apenas por um objeto `unique_ptr`; quando um objeto `unique_ptr` que possui um recurso específico é destruído, o recurso é liberado. Um objeto `unique_ptr` pode ser movido, mas não copiado; para obter mais informações, consulte [Declarador de Referência de Valor R: &&](../cpp/rvalue-reference-declarator-amp-amp.md).

O recurso é liberado chamando um objeto `deleter` armazenado do tipo `Del` que sabe como os recursos são alocados para um determinado `unique_ptr`. O padrão `deleter` `default_delete<T>` pressupõe que o recurso apontado pelo `ptr` é alocado com **`new`** e que pode ser liberado chamando `delete _Ptr` . (Uma especialização parcial `unique_ptr<T[]>`gerencia objetos de matriz alocados com `new[]` e tem o `deleter` `default_delete<T[]>` padrão, especializado para chamar delete[] `ptr`.)

O ponteiro armazenado para um recurso possuído, `stored_ptr` tem o tipo `pointer`. Ele será `Del::pointer` se definido e `T *`, se não. O objeto `deleter` armazenado `stored_deleter` não ocupará nenhum espaço no objeto se `deleter` não tiver estado. Observe que `Del` pode ser um tipo de referência.

## <a name="members"></a>Membros

### <a name="constructors"></a>Construtores

|Nome|Descrição|
|-|-|
|[unique_ptr](#unique_ptr)|Há sete construtores para `unique_ptr`.|

### <a name="typedefs"></a>Typedefs

|Nome|Descrição|
|-|-|
|[deleter_type](#deleter_type)|Um sinônimo para o parâmetro de modelo `Del`.|
|[element_type](#element_type)|Um sinônimo para o parâmetro de modelo `T`.|
|[refere](#pointer)|Um sinônimo para `Del::pointer` se definido, caso contrário `T *`.|

### <a name="functions"></a>Funções

|Nome|Descrição|
|-|-|
|[get](#get)|Retorna `stored_ptr`.|
|[get_deleter](#get_deleter)|Retorna uma referência para `stored_deleter`.|
|[liberar](#release)|Armazena `pointer()` em `stored_ptr` e retorna seu conteúdo anterior.|
|[reset](#reset)|Libera o recurso possuído atualmente e aceita um novo recurso.|
|[permuta](#swap)|Troca o recurso e `deleter` pelo `unique_ptr` fornecido.|

### <a name="operators"></a>Operadores

|Nome|Descrição|
|-|-|
|**booliano de operador**|O operador retorna um valor de um tipo que é conversível para **`bool`** . O resultado da conversão em **`bool`** é **`true`** quando `get() != pointer()` , caso contrário, **`false`** .|
|`operator->`|A função membro retorna `stored_ptr`.|
|`operator*`|A função membro retorna `*stored_ptr`.|
|[operador =](#unique_ptr_operator_eq)|Atribui o valor de um `unique_ptr`(ou um `pointer-type`) para o `unique_ptr` atual.|

### <a name="deleter_type"></a><a name="deleter_type"></a> deleter_type

O tipo é um sinônimo do parâmetro de modelo `Del`.

```cpp
typedef Del deleter_type;
```

#### <a name="remarks"></a>Comentários

O tipo é um sinônimo do parâmetro de modelo `Del`.

### <a name="element_type"></a><a name="element_type"></a> element_type

O tipo é um sinônimo do parâmetro de modelo `Type`.

```cpp
typedef Type element_type;
```

#### <a name="remarks"></a>Comentários

O tipo é um sinônimo do parâmetro de modelo `Ty`.

### <a name="get"></a><a name="get"></a> Obter

Retorna `stored_ptr`.

```cpp
pointer get() const;
```

#### <a name="remarks"></a>Comentários

A função membro retorna `stored_ptr`.

### <a name="get_deleter"></a><a name="get_deleter"></a> get_deleter

Retorna uma referência para `stored_deleter`.

```cpp
Del& get_deleter();

const Del& get_deleter() const;
```

#### <a name="remarks"></a>Comentários

A função membro retorna a referência para `stored_deleter`.

### <a name="operator"></a><a name="unique_ptr_operator_eq"></a> operador =

Atribui o endereço das `unique_ptr` fornecidas para a atual.

```cpp
unique_ptr& operator=(unique_ptr&& right);
template <class U, Class Del2>
unique_ptr& operator=(unique_ptr<Type, Del>&& right);
unique_ptr& operator=(pointer-type);
```

#### <a name="parameters"></a>parâmetros

A referência `unique_ptr` usada para atribuir a `unique_ptr` atual.

#### <a name="remarks"></a>Comentários

As funções de membro chamam `reset(right.release())` e `right.stored_deleter` se movem para e `stored_deleter` retornam **`*this`** .

### <a name="pointer"></a>Ponteiro <a name="pointer"></a>

Um sinônimo para `Del::pointer` se definido, caso contrário `Type *`.

```cpp
typedef T1 pointer;
```

#### <a name="remarks"></a>Comentários

O tipo de sinônimo para `Del::pointer` se definido, caso contrário `Type *`.

### <a name="release"></a><a name="release"></a> liberar

Libera a propriedade do ponteiro armazenado retornado para o chamador e define o valor do ponteiro armazenado para **`nullptr`** .

```cpp
pointer release();
```

#### <a name="remarks"></a>Comentários

Use `release` para assumir a propriedade do ponteiro bruto armazenado pelo `unique_ptr`. O chamador é responsável pela exclusão do ponteiro retornado. O `unique-ptr` é definido como o estado vazio criado por padrão. Você pode atribuir outro ponteiro de tipo compatível para o `unique_ptr` após a chamada para `release`.

#### <a name="example"></a>Exemplo

Este exemplo mostra como o chamador da versão é responsável pelo objeto retornado:

```cpp
// stl_release_unique.cpp
// Compile by using: cl /W4 /EHsc stl_release_unique.cpp
#include <iostream>
#include <memory>

struct Sample {
   int content_;
   Sample(int content) : content_(content) {
      std::cout << "Constructing Sample(" << content_ << ")" << std::endl;
   }
   ~Sample() {
      std::cout << "Deleting Sample(" << content_ << ")" << std::endl;
   }
};

void ReleaseUniquePointer() {
   // Use make_unique function when possible.
   auto up1 = std::make_unique<Sample>(3);
   auto up2 = std::make_unique<Sample>(42);

   // Take over ownership from the unique_ptr up2 by using release
   auto ptr = up2.release();
   if (up2) {
      // This statement does not execute, because up2 is empty.
      std::cout << "up2 is not empty." << std::endl;
   }
   // We are now responsible for deletion of ptr.
   delete ptr;
   // up1 deletes its stored pointer when it goes out of scope.
}

int main() {
   ReleaseUniquePointer();
}
```

```Output
Constructing Sample(3)
Constructing Sample(42)
Deleting Sample(42)
Deleting Sample(3)
```

### <a name="reset"></a><a name="reset"></a> definido

Apropria-se do parâmetro de ponteiro e, em seguida, exclui o ponteiro armazenado original. Se o novo ponteiro for o mesmo que o ponteiro armazenado original, o `reset` excluirá o ponteiro e definirá o ponteiro armazenado para **`nullptr`** .

```cpp
void reset(pointer ptr = pointer());
void reset(nullptr_t ptr);
```

#### <a name="parameters"></a>parâmetros

*PTR*\
Um ponteiro para o recurso se apropriar.

#### <a name="remarks"></a>Comentários

Use `reset` para alterar o [ponteiro](#pointer) armazenado de propriedade de `unique_ptr` para *PTR* e, em seguida, exclua o ponteiro armazenado original. Se `unique_ptr` não estava vazia, `reset` invoca a função deleter retornada por [get_deleter](#get_deleter) no ponteiro armazenado original.

Como o `reset` primeiro armazena o novo ponteiro *PTR*e, em seguida, exclui o ponteiro armazenado original, é possível `reset` excluir imediatamente o *PTR* se for o mesmo que o ponteiro armazenado original.

### <a name="swap"></a><a name="swap"></a> permuta

Troca os valores de dois objetos de `unique_ptr`.

```cpp
void swap(unique_ptr& right);
```

#### <a name="parameters"></a>parâmetros

*Certo*\
Um `unique_ptr` usado para a troca de ponteiros.

#### <a name="remarks"></a>Comentários

A função membro alterna `stored_ptr` com `right.stored_ptr` e `stored_deleter` com `right.stored_deleter`.

### <a name="unique_ptr"></a><a name="unique_ptr"></a> unique_ptr

Há sete construtores para `unique_ptr`.

```cpp
unique_ptr();

unique_ptr(nullptr_t);
explicit unique_ptr(pointer ptr);

unique_ptr(
    Type* ptr,
    typename conditional<
    is_reference<Del>::value,
    Del,
    typename add_reference<const Del>::type>::type _Deleter);

unique_ptr(pointer ptr, typename remove_reference<Del>::type&& _Deleter);
unique_ptr(unique_ptr&& right);
template <class Ty2, Class Del2>
    unique_ptr(unique_ptr<Ty2, Del2>&& right);
```

#### <a name="parameters"></a>parâmetros

*PTR*\
Um ponteiro para o recurso a ser atribuído a um `unique_ptr` .

*_Deleter*\
Um `deleter` a ser atribuído a um `unique_ptr`.

*Certo*\
Um `rvalue reference` para um `unique_ptr` do qual `unique_ptr` campos são atribuídos ao `unique_ptr` recentemente construído.

#### <a name="remarks"></a>Comentários

Os primeiros dois construtores constroem um objeto que não gerencia nenhum recurso. O terceiro Construtor armazena *PTR* in `stored_ptr` . O quarto Construtor armazena *PTR* in `stored_ptr` e `deleter` in `stored_deleter` .

O quinto Construtor armazena *PTR* in `stored_ptr` e passa `deleter` para `stored_deleter` . O sexto e sétimo construtores armazenam `right.release()` em `stored_ptr` e move `right.get_deleter()` em `stored_deleter`.

### <a name="unique_ptr"></a><a name="dtorunique_ptr"></a> ~ unique_ptr

O destruidor de `unique_ptr`, destrói um objeto `unique_ptr`.

```cpp
~unique_ptr();
```

#### <a name="remarks"></a>Comentários

O destruidor chama `get_deleter()(stored_ptr)`.
