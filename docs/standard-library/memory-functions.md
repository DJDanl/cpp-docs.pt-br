---
title: Funções &lt;memory&gt;
ms.date: 08/05/2019
f1_keywords:
- memory/std::addressof
- memory/std::align
- memory/std::allocate_shared
- memory/std::const_pointer_cast
- memory/std::declare_no_pointers
- memory/std::declare_reachable
- memory/std::default_delete
- memory/std::dynamic_pointer_cast
- memory/std::get_deleter
- memory/std::get_pointer_safety
- memory/std::get_temporary_buffer
- xmemory/std::get_temporary_buffer
- memory/std::make_shared
- memory/std::make_unique
- memory/std::owner_less
- memory/std::reinterpret_pointer_cast
- memory/std::return_temporary_buffer
- xmemory/std::return_temporary_buffer
- memory/std::static_pointer_cast
- memory/std::swap
- memory/std::undeclare_no_pointers
- memory/std::undeclare_reachable
- memory/std::uninitialized_copy
- memory/std::uninitialized_copy_n
- memory/std::uninitialized_fill
- memory/std::uninitialized_fill_n
- memory/std::get_temporary_buffer
- memory/std::return_temporary_buffer
ms.assetid: 3e1898c2-44b7-4626-87ce-84962e4c6f1a
helpviewer_keywords:
- std::addressof [C++]
- std::align [C++]
- std::allocate_shared [C++]
- std::const_pointer_cast [C++]
- std::declare_no_pointers [C++]
- std::declare_reachable [C++]
- std::default_delete [C++]
- std::dynamic_pointer_cast [C++]
- std::get_deleter [C++]
- std::get_pointer_safety [C++]
- std::get_temporary_buffer [C++]
- std::make_shared [C++]
- std::make_unique [C++]
- std::owner_less [C++]
- std::return_temporary_buffer [C++]
- std::static_pointer_cast [C++]
- std::swap [C++]
- std::undeclare_no_pointers [C++]
- std::undeclare_reachable [C++]
- std::uninitialized_copy [C++]
- std::uninitialized_copy_n [C++]
- std::uninitialized_fill [C++]
- std::uninitialized_fill_n [C++]
- std::addressof [C++]
- std::align [C++]
- std::allocate_shared [C++]
- std::const_pointer_cast [C++]
- std::declare_no_pointers [C++]
- std::declare_reachable [C++]
- std::default_delete [C++]
- std::dynamic_pointer_cast [C++]
- std::get_deleter [C++]
- std::get_pointer_safety [C++]
- std::get_temporary_buffer [C++]
- std::make_shared [C++]
- std::make_unique [C++]
- std::owner_less [C++]
- std::return_temporary_buffer [C++]
- std::static_pointer_cast [C++]
- std::undeclare_no_pointers [C++]
- std::undeclare_reachable [C++]
- std::uninitialized_copy [C++]
- std::uninitialized_copy_n [C++]
- std::uninitialized_fill [C++]
- std::uninitialized_fill_n [C++]
ms.openlocfilehash: 2aceb96fcda49df8a1fd40a1bd8011170dccd8ef
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79419934"
---
# <a name="ltmemorygt-functions"></a>Funções &lt;memory&gt;

## <a name="addressof"></a>AddressOf

Obtém o endereço verdadeiro de um objeto.

```cpp
template <class T>
T* addressof(
    T& value) noexcept;    // before C++17

template <class T>
constexpr T* addressof(
    T& value) noexcept;    // C++17

template <class T>
const T* addressof(
    const T&& value) = delete;   // C++17
```

### <a name="parameters"></a>parâmetros

*value*\
O objeto ou a função para o qual obter o endereço verdadeiro.

### <a name="return-value"></a>Valor retornado

O endereço real do objeto ou da função referenciado por *valor*, mesmo se houver um `operator&()` sobrecarregado.

### <a name="remarks"></a>Comentários

## <a name="align"></a>alinha

Ajusta o armazenamento do tamanho determinado, alinhado pela especificação de alinhamento fornecida, ao primeiro endereço possível do armazenamento especificado.

```cpp
void* align(
    size_t alignment, // input
    size_t size,      // input
    void*& ptr,       // input/output
    size_t& space     // input/output
);
```

### <a name="parameters"></a>parâmetros

\ de *alinhamento*
O limite de alinhamento ser tentado.

*size*\
O tamanho em bytes para o armazenamento alinhado.

\ *PTR*
O endereço inicial do pool de armazenamento contíguo disponível a ser usado. Esse parâmetro também é um parâmetro de saída e é definido para conter o novo endereço inicial se o alinhamento for bem-sucedido. Se `align()` não for bem-sucedida, esse parâmetro não será modificado.

\ de *espaço*
O espaço total disponível para `align()` a ser usado ao criar o armazenamento alinhado. Esse parâmetro também é um parâmetro de saída e contém o espaço ajustado deixado no buffer de armazenamento após o armazenamento alinhado e qualquer sobrecarga associada é subtraída.

Se `align()` não for bem-sucedida, esse parâmetro não será modificado.

### <a name="return-value"></a>Valor retornado

Um ponteiro nulo se o buffer alinhado solicitado não couber no espaço disponível; caso contrário, o novo valor de *PTR*.

### <a name="remarks"></a>Comentários

Os parâmetros de *espaço* e *PTR* modificados permitem que você chame `align()` repetidamente no mesmo buffer, possivelmente com valores diferentes para *alinhamento* e *tamanho*. O snippet de código a seguir mostra um uso de `align()`.

```cpp
#include <type_traits> // std::alignment_of()
#include <memory>
//...
char buffer[256]; // for simplicity
size_t alignment = std::alignment_of<int>::value;
void * ptr = buffer;
std::size_t space = sizeof(buffer); // Be sure this results in the true size of your buffer

while (std::align(alignment, sizeof(MyObj), ptr, space)) {
    // You now have storage the size of MyObj, starting at ptr, aligned on
    // int boundary. Use it here if you like, or save off the starting address
    // contained in ptr for later use.
    // ...
    // Last, move starting pointer and decrease available space before
    // the while loop restarts.
    ptr = reinterpret_cast<char*>(ptr) + sizeof(MyObj);
    space -= sizeof(MyObj);
}
// At this point, align() has returned a null pointer, signaling it is not
// possible to allow more aligned storage in this buffer.
```

## <a name="allocate_shared"></a>allocate_shared

Cria um [shared_ptr](shared-ptr-class.md) a objetos que são alocados e construídos para um determinado tipo usando um alocador especificado. Retorna o `shared_ptr`.

```cpp
template <class T, class Allocator, class... Args>
shared_ptr<T> allocate_shared(
    Allocator alloc,
    Args&&... args);
```

### <a name="parameters"></a>parâmetros

\ de *alocação*
O alocador usado para criar objetos.

*args*\
O zero ou mais argumentos que se tornam os objetos.

### <a name="remarks"></a>Comentários

A função cria o objeto `shared_ptr<T>`, um ponteiro para `T(args...)` como alocado e construído por *Alloc*.

## <a name="atomic_compare_exchange_strong"></a>atomic_compare_exchange_strong

```cpp
template<class T>
bool atomic_compare_exchange_strong(
    shared_ptr<T>* u,
    shared_ptr<T>* v,
    shared_ptr<T> w);
```

## <a name="atomic_compare_exchange_weak"></a>atomic_compare_exchange_weak

```cpp
template<class T>
bool atomic_compare_exchange_weak(
    shared_ptr<T>* u,
    shared_ptr<T>* v,
    shared_ptr<T> w);
```

## <a name="atomic_compare_exchange_strong_explicit"></a>atomic_compare_exchange_strong_explicit

```cpp
template<class T>
bool atomic_compare_exchange_strong_explicit(
    shared_ptr<T>* u,
    shared_ptr<T>* v,
    shared_ptr<T> w,
    memory_order success,
    memory_order failure);
```

## <a name="atomic_compare_exchange_weak_explicit"></a>atomic_compare_exchange_weak_explicit

```cpp
template<class T>
bool atomic_compare_exchange_weak_explicit(
    shared_ptr<T>* u,
    shared_ptr<T>* v,
    shared_ptr<T> w,
    memory_order success,
    memory_order failure);
```

## <a name="atomic_exchange"></a>atomic_exchange

```cpp
template<class T>
shared_ptr<T> atomic_exchange(
    shared_ptr<T>* u,
    shared_ptr<T> r);
```

## <a name="atomic_exchange_explicit"></a>atomic_exchange_explicit

```cpp
template<class T>
shared_ptr<T> atomic_exchange_explicit(
    shared_ptr<T>* u,
    shared_ptr<T> r,
    memory_order mo);
```

## <a name="atomic_is_lock_free"></a>atomic_is_lock_free

```cpp
template<class T>
bool atomic_is_lock_free(
    const shared_ptr<T>* u);
```

## <a name="atomic_load"></a>atomic_load

```cpp
template<class T>
shared_ptr<T> atomic_load(
    const shared_ptr<T>* u);
```

## <a name="atomic_load_explicit"></a>atomic_load_explicit

```cpp
template<class T>
shared_ptr<T> atomic_load_explicit(
    const shared_ptr<T>* u,
    memory_order mo);
```

## <a name="atomic_store"></a>atomic_store

```cpp
template<class T>
void atomic_store(
    shared_ptr<T>* u,
    shared_ptr<T> r);
```

## <a name="atomic_store_explicit"></a>atomic_store_explicit

```cpp
template<class T>
void atomic_store_explicit(
    shared_ptr<T>* u,
    shared_ptr<T> r,
    memory_order mo);
```

## <a name="const_pointer_cast"></a>const_pointer_cast

Conversão const em [shared_ptr](shared-ptr-class.md).

```cpp
template <class T, class Other>
shared_ptr<T> const_pointer_cast(
    const shared_ptr<Other>& sp) noexcept;

template <class T, class Other>
shared_ptr<T> const_pointer_cast(
    shared_ptr<Other>&& sp) noexcept;
```

### <a name="parameters"></a>parâmetros

*T*\
O tipo controlado pelo ponteiro compartilhado retornado.

*Outros*\
O tipo controlado pelo ponteiro compartilhado de argumento.

\ *SP*
O ponteiro compartilhado de argumento.

### <a name="remarks"></a>Comentários

A função de modelo retornará um objeto `shared_ptr` vazio se `const_cast<T*>(sp.get())` retornar um ponteiro nulo; caso contrário, ele retorna um objeto `shared_ptr<T>` que possui o recurso que pertence ao *SP*. A expressão `const_cast<T*>(sp.get())` deve ser válida.

### <a name="example"></a>Exemplo

```cpp
// std__memory__const_pointer_cast.cpp
// compile with: /EHsc
#include <memory>
#include <iostream>

int main()
{
    std::shared_ptr<int> sp0(new int);
    std::shared_ptr<const int> sp1 =
        std::const_pointer_cast<const int>(sp0);

    *sp0 = 3;
    std::cout << "sp1 == " << *sp1 << std::endl;

    return (0);
}
```

```Output
sp1 == 3
```

## <a name="declare_no_pointers"></a>declare_no_pointers

Informa um coletor de lixo que os caracteres no bloco de memória definido por um ponteiro de endereço básico e o tamanho de bloco não contêm ponteiros rastreáveis.

```cpp
void declare_no_pointers(
    char* ptr,
    size_t size);
```

### <a name="parameters"></a>parâmetros

\ *PTR*
O endereço do primeiro caractere que não contém mais ponteiros rastreáveis.

*size*\
Tamanho do bloco que começa em *PTR* que não contém ponteiros rastreáveis.

### <a name="remarks"></a>Comentários

A função informa qualquer coletor de lixo que os endereços no intervalo `[ ptr, ptr + size)` não contêm mais ponteiros rastreáveis. (Os ponteiros para armazenamento alocado não devem ser desreferenciados, a menos que tenham sido acessíveis.)

## <a name="declare_reachable"></a>declare_reachable

Informa a coleta de lixo que o endereço indicado é para armazenamento alocado e é alcançável.

```cpp
void declare_reachable(
    void* ptr);
```

### <a name="parameters"></a>parâmetros

\ *PTR*
Um ponteiro para uma área de armazenamento acessível, alocada e válida.

### <a name="remarks"></a>Comentários

Se *PTR* não for nulo, a função informará a qualquer coletor de lixo que o *PTR* agora está acessível, ou seja, ele aponta para um armazenamento alocado válido.

## <a name="default_delete"></a>default_delete

Exclui objetos alocados com o **operador novo**. Adequado para uso com [unique_ptr](unique-ptr-class.md).

```cpp
struct default_delete
{
    constexpr default_delete() noexcept = default;

    template <class Other, class = typename enable_if<is_convertible<Other*, T*>::value, void>::type>>
    default_delete(const default_delete<Other>&) noexcept;

    void operator()(T* ptr) const noexcept;
};
```

### <a name="parameters"></a>parâmetros

\ *PTR*
Ponteiro para o objeto a ser excluído.

*Outros*\
O tipo dos elementos na matriz a ser excluída.

### <a name="remarks"></a>Comentários

O modelo de classe descreve um excluidor que exclui objetos escalares alocados com o **operador novo**, adequado para uso com o modelo de classe `unique_ptr`. Ela também tem a especialização explícita `default_delete<T[]>`.

## <a name="destroy_at"></a>destroy_at

```cpp
template <class T>
void destroy_at(
    T* location);
```

Igual a `location->~T()`.

## <a name="destroy"></a>destruir

```cpp
template <class ForwardIterator>
void destroy(
    ForwardIterator first,
    ForwardIterator last);
```

O mesmo que:

```cpp
for (; first != last; ++first)
    destroy_at(addressof(*first));
```

## <a name="destroy_n"></a>destroy_n

```cpp
template <class ForwardIterator, class Size>
ForwardIterator destroy_n(
    ForwardIterator first,
    Size count);
```

O mesmo que:

```cpp
for (; count > 0; (void)++first, --count)
    destroy_at(addressof(*first));
return first;
```

## <a name="dynamic_pointer_cast"></a>dynamic_pointer_cast

Conversão dinâmica para [shared_ptr](shared-ptr-class.md).

```cpp
template <class T, class Other>
shared_ptr<T> dynamic_pointer_cast(
    const shared_ptr<Other>& sp) noexcept;

template <class T, class Other>
shared_ptr<T> dynamic_pointer_cast(
    shared_ptr<Other>&& sp) noexcept;
```

### <a name="parameters"></a>parâmetros

*T*\
O tipo controlado pelo ponteiro compartilhado retornado.

*Outros*\
O tipo controlado pelo ponteiro compartilhado de argumento.

\ *SP*
O ponteiro compartilhado de argumento.

### <a name="remarks"></a>Comentários

A função de modelo retornará um objeto `shared_ptr` vazio se `dynamic_cast<T*>(sp.get())` retornar um ponteiro nulo; caso contrário, ele retorna um objeto `shared_ptr<T>` que possui o recurso que pertence ao *SP*. A expressão `dynamic_cast<T*>(sp.get())` deve ser válida.

### <a name="example"></a>Exemplo

```cpp
// std__memory__dynamic_pointer_cast.cpp
// compile with: /EHsc
#include <memory>
#include <iostream>

struct base
{
    virtual ~base() {}
    int value;
};

struct derived
    : public base
{
};

int main()
{
    std::shared_ptr<base> sp0(new derived);
    std::shared_ptr<derived> sp1 =
        std::dynamic_pointer_cast<derived>(sp0);

    sp0->value = 3;
    std::cout << "sp1->value == " << sp1->value << std::endl;

    return (0);
}
```

```Output
sp1->value == 3
```

## <a name="get_deleter"></a>get_deleter

Obtenha o excluidor de um [shared_ptr](shared-ptr-class.md).

```cpp
template <class Deleter, class T>
Deleter* get_deleter(
    const shared_ptr<T>& sp) noexcept;
```

### <a name="parameters"></a>parâmetros

\ *excluidor*
O tipo do agente de exclusão.

*T*\
O tipo controlado pelo ponteiro compartilhado.

\ *SP*
O ponteiro compartilhado.

### <a name="remarks"></a>Comentários

A função template retorna um ponteiro para o excluidor do tipo *excluidor* que pertence ao *controlador*de `shared_ptr` do objeto. Se o *SP* não tiver nenhum excluidor ou se seu excluidor não for do tipo *excluidor*, a função retornará 0.

### <a name="example"></a>Exemplo

```cpp
// std__memory__get_deleter.cpp
// compile with: /EHsc
#include <memory>
#include <iostream>

struct base
{
    int value;
};

struct deleter
{
    void operator()(base *pb)
    {
        delete pb;
    }
};

int main()
{
    std::shared_ptr<base> sp0(new base);

    sp0->value = 3;
    std::cout << "get_deleter(sp0) != 0 == " << std::boolalpha
        << (std::get_deleter<deleter>(sp0) != 0) << std::endl;

    std::shared_ptr<base> sp1(new base, deleter());

    sp0->value = 3;
    std::cout << "get_deleter(sp1) != 0 == " << std::boolalpha
        << (std::get_deleter<deleter>(sp1) != 0) << std::endl;

    return (0);
}
```

```Output
get_deleter(sp0) != 0 == false
get_deleter(sp1) != 0 == true
```

## <a name="get_pointer_safety"></a>get_pointer_safety

Retorna o tipo de segurança do ponteiro pressuposto por qualquer coletor de lixo.

```cpp
pointer_safety get_pointer_safety() noexcept;
```

### <a name="remarks"></a>Comentários

A função retorna o tipo de segurança do ponteiro assumida por qualquer coletor de lixo automático.

## <a name="get_temporary_buffer"></a>get_temporary_buffer

Aloca armazenamento temporário para uma sequência de elementos que não exceda um número especificado de elementos.

```cpp
template <class T>
pair<T *, ptrdiff_t> get_temporary_buffer(
    ptrdiff_t count);
```

### <a name="parameters"></a>parâmetros

*contagem*\
O número máximo de elementos solicitados para o qual a memória deve ser alocada.

### <a name="return-value"></a>Valor retornado

Um `pair` cujo primeiro componente é um ponteiro para a memória que foi alocada e cujo segundo componente retorna o tamanho do buffer, indicando o maior número de elementos que ele pode armazenar.

### <a name="remarks"></a>Comentários

A função faz uma solicitação de memória e ela pode não ser bem-sucedida. Se nenhum é for alocado, a função retornará um par, com o segundo componente igual a zero e o primeiro componente igual ao ponteiro nulo.

Use essa função somente para a memória temporária.

### <a name="example"></a>Exemplo

```cpp
// memory_get_temp_buf.cpp
// compile with: /EHsc
#include <memory>
#include <iostream>

using namespace std;

int main( )
{
    // Create an array of ints
    int intArray [] = { 10, 20, 30, 40, 100, 200, 300, 1000, 2000 };
    int count = sizeof ( intArray ) / sizeof ( int );
    cout << "The number of integers in the array is: "
        << count << "." << endl;

    pair<int *, ptrdiff_t> resultPair;
    resultPair = get_temporary_buffer<int>( count );

    cout << "The number of elements that the allocated memory\n"
        << "could store is given by: resultPair.second = "
        << resultPair.second << "." << endl;
}
```

```Output
The number of integers in the array is: 9.
The number of elements that the allocated memory
could store is given by: resultPair.second = 9.
```

## <a name="make_shared"></a>make_shared

Cria e retorna um [shared_ptr](shared-ptr-class.md) que aponta para os objetos alocados que são construídos a partir de zero ou mais argumentos usando o alocador padrão. Aloca e constrói um objeto do tipo especificado e um `shared_ptr` para gerenciar a propriedade compartilhada do objeto e retorna o `shared_ptr`.

```cpp
template <class T, class... Args>
shared_ptr<T> make_shared(
    Args&&... args);
```

### <a name="parameters"></a>parâmetros

*args*\
Zero ou mais argumentos de construtor. A função infere qual sobrecarga de construtor deve ser invocada com base nos argumentos fornecidos.

### <a name="remarks"></a>Comentários

Use `make_shared` como uma forma simples e mais eficiente de criar um objeto e um `shared_ptr` para gerenciar o acesso compartilhado para o objeto ao mesmo tempo. Semanticamente, essas duas instruções são equivalentes:

```cpp
auto sp = std::shared_ptr<Example>(new Example(argument));
auto msp = std::make_shared<Example>(argument);
```

No entanto, a primeira instrução faz duas alocações e se a alocação do `shared_ptr` falhar após a alocação do objeto `Example` ter sido bem sucedida, o objeto `Example` sem nome será vazado. A instrução que usa `make_shared` é mais simples porque há apenas uma chamada de função envolvida. Ela é mais eficiente porque a biblioteca pode fazer uma única alocação do objeto e do ponteiro inteligente. Essa função é mais rápida e leva a menos fragmentação de memória, e não há nenhuma chance de uma exceção em uma alocação, mas não na outra. O desempenho é melhorado pela melhor localidade para o código que faz referência ao objeto e atualiza as contagens de referência no ponteiro inteligente.

Considere o uso de [make_unique](memory-functions.md#make_unique) se você não precisar de acesso compartilhado ao objeto. Use [allocate_shared](memory-functions.md#allocate_shared) se você precisar especificar um alocador personalizado para o objeto. Você não poderá usar `make_shared` se o objeto exigir um excluidor personalizado, porque não há como passar o excluidor como um argumento.

O exemplo a seguir mostra como criar ponteiros compartilhados para um tipo invocando as sobrecargas do construtor específicas.

### <a name="example"></a>Exemplo

```cpp
// stl_make_shared.cpp
// Compile by using: cl /W4 /EHsc stl_make_shared.cpp
#include <iostream>
#include <string>
#include <memory>
#include <vector>

class Song {
public:
    std::wstring title_;
    std::wstring artist_;

    Song(std::wstring title, std::wstring artist) : title_(title), artist_(artist) {}
    Song(std::wstring title) : title_(title), artist_(L"Unknown") {}
};

void CreateSharedPointers()
{
    // Okay, but less efficient to have separate allocations for
    // Song object and shared_ptr control block.
    auto song = new Song(L"Ode to Joy", L"Beethoven");
    std::shared_ptr<Song> sp0(song);

    // Use make_shared function when possible. Memory for control block
    // and Song object are allocated in the same call:
    auto sp1 = std::make_shared<Song>(L"Yesterday", L"The Beatles");
    auto sp2 = std::make_shared<Song>(L"Blackbird", L"The Beatles");

    // make_shared infers which constructor to use based on the arguments.
    auto sp3 = std::make_shared<Song>(L"Greensleeves");

    // The playlist vector makes copies of the shared_ptr pointers.
    std::vector<std::shared_ptr<Song>> playlist;
    playlist.push_back(sp0);
    playlist.push_back(sp1);
    playlist.push_back(sp2);
    playlist.push_back(sp3);
    playlist.push_back(sp1);
    playlist.push_back(sp2);
    for (auto&& sp : playlist)
    {
        std::wcout << L"Playing " << sp->title_ <<
            L" by " << sp->artist_ << L", use count: " <<
            sp.use_count() << std::endl;
    }
}

int main()
{
    CreateSharedPointers();
}
```

O exemplo produz essa saída:

```Output
Playing Ode to Joy by Beethoven, use count: 2
Playing Yesterday by The Beatles, use count: 3
Playing Blackbird by The Beatles, use count: 3
Playing Greensleeves by Unknown, use count: 2
Playing Yesterday by The Beatles, use count: 3
Playing Blackbird by The Beatles, use count: 3
```

## <a name="make_unique"></a>make_unique

Cria e retorna um [unique_ptr](unique-ptr-class.md) para um objeto do tipo especificado, que é construído usando os argumentos especificados.

```cpp
// make_unique<T>
template <class T, class... Args>
unique_ptr<T> make_unique(Args&&... args);

// make_unique<T[]>
template <class T>
unique_ptr<T> make_unique(size_t size);

// make_unique<T[N]> disallowed
template <class T, class... Args>
/* unspecified */ make_unique(Args&&...) = delete;
```

### <a name="parameters"></a>parâmetros

*T*\
O tipo do objeto para o qual o `unique_ptr` apontará.

*Args*\
Os tipos dos argumentos do Construtor especificados por *args*.

*args*\
Os argumentos a serem passados para o construtor do objeto do tipo *T*.

*elementos*\
Uma matriz de elementos do tipo *T*.

*size*\
O número de elementos para os quais alocar espaço na nova matriz.

### <a name="remarks"></a>Comentários

A primeira sobrecarga é usada para objetos únicos. A segunda sobrecarga é invocada para matrizes. A terceira sobrecarga impede que você especifique um tamanho de matriz no argumento de tipo (make_unique\<T [N] >); Essa construção não tem suporte no padrão atual. Quando você usa `make_unique` para criar um `unique_ptr` para uma matriz, é necessário inicializar os elementos da matriz separadamente. Em vez de usar essa sobrecarga, talvez uma opção melhor seja usar um [std:: vector](vector-class.md).

Como `make_unique` é cuidadosamente implementado para a segurança de exceção, é recomendável usar `make_unique` em vez de chamar diretamente os construtores `unique_ptr`.

### <a name="example"></a>Exemplo

O exemplo a seguir mostra como usar `make_unique`. Para mais exemplos, consulte [Como criar e usar instâncias unique_ptr](../cpp/how-to-create-and-use-unique-ptr-instances.md).

[!code-cpp[stl_smart_pointers#214](../cpp/codesnippet/CPP/memory-functions_1.cpp)]

Quando você vir o erro C2280 em conexão com um `unique_ptr`, provavelmente é porque você está tentando invocar o construtor de cópia, o que é uma função excluída.

## <a name="owner_less"></a>owner_less

Permite comparações mistas baseadas em propriedade de ponteiros compartilhados e fracos. Retorna **true** se o parâmetro da esquerda é ordenado antes do parâmetro Right pela função membro `owner_before`.

```cpp
template <class T>
    struct owner_less; // not defined

template <class T>
struct owner_less<shared_ptr<T>>
{
    bool operator()(
        const shared_ptr<T>& left,
        const shared_ptr<T>& right) const noexcept;

    bool operator()(
        const shared_ptr<T>& left,
        const weak_ptr<T>& right) const noexcept;

    bool operator()(
        const weak_ptr<T>& left,
        const shared_ptr<T>& right) const noexcept;
};

template <class T>
struct owner_less<weak_ptr<T>>
    bool operator()(
        const weak_ptr<T>& left,
        const weak_ptr<T>& right) const noexcept;

    bool operator()(
        const weak_ptr<T>& left,
        const shared_ptr<T>& right) const noexcept;

    bool operator()(
        const shared_ptr<T>& left,
        const weak_ptr<T>& right) const noexcept;
};

template<> struct owner_less<void>
{
    template<class T, class U>
    bool operator()(
        const shared_ptr<T>& left,
        const shared_ptr<U>& right) const noexcept;

    template<class T, class U>
    bool operator()(
        const shared_ptr<T>& left,
        const weak_ptr<U>& right) const noexcept;

    template<class T, class U>
    bool operator()(
        const weak_ptr<T>& left,
        const shared_ptr<U>& right) const noexcept;

    template<class T, class U>
    bool operator()(
        const weak_ptr<T>& left,
        const weak_ptr<U>& right) const noexcept;
};
```

### <a name="parameters"></a>parâmetros

\ *à esquerda*
Um ponteiro compartilhado ou fraco.

\ *à direita*
Um ponteiro compartilhado ou fraco.

### <a name="remarks"></a>Comentários

Os modelos de classe definem todos os seus operadores de membro como retornando `left.owner_before(right)`.

## <a name="reinterpret_pointer_cast"></a>reinterpret_pointer_cast

Cria um novo `shared_ptr` a partir de um ponteiro compartilhado existente usando uma conversão.

```cpp
template<class T, class U>
shared_ptr<T> reinterpret_pointer_cast(
    const shared_ptr<U>& ptr) noexcept;

template<class T, class U>
shared_ptr<T> reinterpret_pointer_cast(
    shared_ptr<U>&& ptr) noexcept;
```

### <a name="parameters"></a>parâmetros

\ *PTR*
Uma referência a um `shared_ptr<U>`.

### <a name="remarks"></a>Comentários

Se *PTR* estiver vazio, o novo `shared_ptr` também estará vazio, caso contrário, compartilhará a propriedade com *PTR*. O novo ponteiro compartilhado é o resultado da avaliação de `reinterpret_cast<Y*>(ptr.get())`, em que `Y` é `typename std::shared_ptr<T>::element_type`. O comportamento será indefinido se `reinterpret_cast<T*>((U*)nullptr)` não estiver bem formado.

A função de modelo que usa uma referência lvalue é nova no C++ 17. A função de modelo que usa uma referência rvalue é nova no C++ 20.

## <a name="return_temporary_buffer"></a>return_temporary_buffer

Desaloca a memória temporária que foi alocada usando a função de modelo `get_temporary_buffer`.

```cpp
template <class T>
void return_temporary_buffer(
    T* buffer);
```

### <a name="parameters"></a>parâmetros

\ de *buffer*
Um ponteiro para a memória a ser desalocada.

### <a name="remarks"></a>Comentários

Use essa função somente para a memória temporária.

### <a name="example"></a>Exemplo

```cpp
// memory_ret_temp_buf.cpp
// compile with: /EHsc
#include <memory>
#include <iostream>

using namespace std;

int main( )
{
    // Create an array of ints
    int intArray [] = { 10, 20, 30, 40, 100, 200, 300 };
    int count = sizeof ( intArray ) / sizeof ( int );
    cout << "The number of integers in the array is: "
         << count << "." << endl;

    pair<int *, ptrdiff_t> resultPair;
    resultPair = get_temporary_buffer<int>( count );

    cout << "The number of elements that the allocated memory\n"
         << " could store is given by: resultPair.second = "
         << resultPair.second << "." << endl;

    int* tempBuffer = resultPair.first;

    // Deallocates memory allocated with get_temporary_buffer
    return_temporary_buffer( tempBuffer );
}
```

```Output
The number of integers in the array is: 7.
The number of elements that the allocated memory
could store is given by: resultPair.second = 7.
```

## <a name="static_pointer_cast"></a>static_pointer_cast

Conversão estática para [shared_ptr](shared-ptr-class.md).

```cpp
template <class T, class Other>
shared_ptr<T> static_pointer_cast(
    const shared_ptr<Other>& sp) noexcept;

template <class T, class Other>
shared_ptr<T> static_pointer_cast(
    shared_ptr<Other>&& sp) noexcept;
```

### <a name="parameters"></a>parâmetros

*T*\
O tipo controlado pelo ponteiro compartilhado retornado.

*Outros*\
O tipo controlado pelo ponteiro compartilhado de argumento.

\ *SP*
O ponteiro compartilhado de argumento.

### <a name="remarks"></a>Comentários

A função de modelo retorna um objeto de `shared_ptr` vazio se o *SP* for um objeto de `shared_ptr` vazio; caso contrário, ele retorna um objeto `shared_ptr<T>` que possui o recurso que pertence ao *SP*. A expressão `static_cast<T*>(sp.get())` deve ser válida.

### <a name="example"></a>Exemplo

```cpp
// std__memory__static_pointer_cast.cpp
// compile with: /EHsc
#include <memory>
#include <iostream>

struct base
{
    int value;
};

struct derived
    : public base
{
};

int main()
{
    std::shared_ptr<base> sp0(new derived);
    std::shared_ptr<derived> sp1 =
        std::static_pointer_cast<derived>(sp0);

    sp0->value = 3;
    std::cout << "sp1->value == " << sp1->value << std::endl;

    return (0);
}
```

```Output
sp1->value == 3
```

## <a name="swap"></a>permuta

Alternar dois objetos [shared_ptr](shared-ptr-class.md), [unique_ptr](unique-ptr-class.md)ou [weak_ptr](weak-ptr-class.md) .

```cpp
template <class T>
void swap(
    shared_ptr<T>& left,
    shared_ptr<T>& right) noexcept;

template <class T, class Deleter>
void swap(
    unique_ptr<T, Deleter>& left,
    unique_ptr<T, Deleter>& right) noexcept;

template <class T>
void swap(
    weak_ptr<T>& left,
    weak_ptr<T>& right) noexcept;

```

### <a name="parameters"></a>parâmetros

*T*\
O tipo controlado pelo ponteiro de argumento.

\ *excluidor*
O excluidor do tipo de ponteiro exclusivo.

\ *à esquerda*
O ponteiro à esquerda.

\ *à direita*
O ponteiro à direita.

### <a name="remarks"></a>Comentários

As funções de modelo chamam `left.swap(right)`.

### <a name="example"></a>Exemplo

```cpp
// std__memory__swap.cpp
// compile with: /EHsc
#include <memory>
#include <iostream>

int main()
{
    std::shared_ptr<int> sp1(new int(5));
    std::shared_ptr<int> sp2(new int(10));
    std::cout << "*sp1 == " << *sp1 << std::endl;

    sp1.swap(sp2);
    std::cout << "*sp1 == " << *sp1 << std::endl;

    swap(sp1, sp2);
    std::cout << "*sp1 == " << *sp1 << std::endl;
    std::cout << std::endl;

    std::weak_ptr<int> wp1(sp1);
    std::weak_ptr<int> wp2(sp2);
    std::cout << "*wp1 == " << *wp1.lock() << std::endl;

    wp1.swap(wp2);
    std::cout << "*wp1 == " << *wp1.lock() << std::endl;

    swap(wp1, wp2);
    std::cout << "*wp1 == " << *wp1.lock() << std::endl;

    return (0);
}
```

```Output
*sp1 == 5
*sp1 == 10
*sp1 == 5

*wp1 == 5
*wp1 == 10
*wp1 == 5
```

## <a name="undeclare_no_pointers"></a>undeclare_no_pointers

Informa um coletor de lixo que os caracteres no bloco de memória definido por um ponteiro de endereço básico e o tamanho de bloco agora podem conter ponteiros rastreáveis.

```cpp
void undeclare_no_pointers(
    char* ptr,
    size_t size);
```

### <a name="parameters"></a>parâmetros

\ *PTR*
Um ponteiro para o endereço de memória marcado anteriormente usando [declare_no_pointers](#declare_no_pointers).

*size*\
O número de bytes no intervalo de memória. Esse valor deve ser igual ao número usado na chamada `declare_no_pointers`.

### <a name="remarks"></a>Comentários

A função informa qualquer coletor de lixo que o intervalo de endereços `[ptr, ptr + size)` pode agora conter ponteiros rastreáveis.

## <a name="undeclare_reachable"></a>undeclare_reachable

Revoga uma declaração de acessibilidade para um local de memória especificado.

```cpp
template <class T>
T *undeclare_reachable(
    T* ptr);
```

### <a name="parameters"></a>parâmetros

\ *PTR*
Um ponteiro para o endereço de memória marcado anteriormente usando [declare_reachable](#declare_reachable).

### <a name="remarks"></a>Comentários

Se *PTR* não for **nullptr**, a função informará qualquer coletor de lixo que o *PTR* não possa mais ser acessado. Ele retorna um ponteiro derivado com segurança que compara igual a *PTR*.

## <a name="uninitialized_copy"></a>uninitialized_copy

Copia objetos de um intervalo de origem especificado em um intervalo de destino não inicializado.

```cpp
template <class InputIterator, class ForwardIterator>
ForwardIterator uninitialized_copy(
    InputIterator first,
    InputIterator last,
    ForwardIterator dest);

template <class ExecutionPolicy, class InputIterator, class ForwardIterator>
ForwardIterator uninitialized_copy(
    ExecutionPolicy&& policy,
    InputIterator first,
    InputIterator last,
    ForwardIterator dest);
```

### <a name="parameters"></a>parâmetros

\ de *política*
A política de execução a ser usada.

*primeiro*\
Um iterador de entrada que trata o primeiro elemento no intervalo de origem.

*última*\
Um iterador de entrada que trata o último elemento no intervalo de origem.

\ de *dest*
Um iterador de avanço que trata o primeiro elemento no intervalo de destino.

### <a name="return-value"></a>Valor retornado

Um iterador posterior que aborda a primeira posição além do intervalo de destino, a menos que o intervalo de origem esteja vazio.

### <a name="remarks"></a>Comentários

Esse algoritmo permite dissociar a alocação da memória da construção do objeto.

A função de modelo é executada efetivamente:

```cpp
while (first != last)
{
    new (static_cast<void*>(&* dest++))
        typename iterator_traits<InputIterator>::value_type(*first++);
}
return dest;
```

a menos que o código lance uma exceção. Nesse caso, todos os objetos construídos são destruídos e a exceção é relançada.

A sobrecarga com uma política de execução é nova no C++ 17.

### <a name="example"></a>Exemplo

```cpp
// memory_uninit_copy.cpp
// compile with: /EHsc /W3
#include <memory>
#include <iostream>

using namespace std;

class Integer
{
public:
    Integer(int x) : value(x) {}
    int get() { return value; }
private:
    int value;
};

int main()
{
    int Array[] = { 10, 20, 30, 40 };
    const int N = sizeof(Array) / sizeof(int);

    cout << "The initialized Array contains " << N << " elements: ";
    for (int i = 0; i < N; i++)
    {
        cout << " " << Array[i];
    }
    cout << endl;

    Integer* ArrayPtr = (Integer*)malloc(N * sizeof(int));
    Integer* LArrayPtr = uninitialized_copy(
        Array, Array + N, ArrayPtr);  // C4996

    cout << "Address of position after the last element in the array is: "
        << &Array[0] + N << endl;
    cout << "The iterator returned by uninitialized_copy addresses: "
        << (void*)LArrayPtr << endl;
    cout << "The address just beyond the last copied element is: "
        << (void*)(ArrayPtr + N) << endl;

    if ((&Array[0] + N) == (void*)LArrayPtr)
        cout << "The return value is an iterator "
        << "pointing just beyond the original array." << endl;
    else
        cout << "The return value is an iterator "
        << "not pointing just beyond the original array." << endl;

    if ((void*)LArrayPtr == (void*)(ArrayPtr + N))
        cout << "The return value is an iterator "
        << "pointing just beyond the copied array." << endl;
    else
        cout << "The return value is an iterator "
        << "not pointing just beyond the copied array." << endl;

    free(ArrayPtr);

    cout << "Note that the exact addresses returned will vary\n"
        << "with the memory allocation in individual computers."
        << endl;
}
```

## <a name="uninitialized_copy_n"></a>uninitialized_copy_n

Cria uma cópia de um número especificado de elementos de um iterador de entrada. As cópias são colocadas em um iterador de avanço.

```cpp
template <class InputIterator, class Size, class ForwardIterator>
ForwardIterator uninitialized_copy_n(
    InputIterator first,
    Size count,
    ForwardIterator dest);

template <class ExecutionPolicy, class InputIterator, class Size, class ForwardIterator>
ForwardIterator uninitialized_copy_n(
    ExecutionPolicy&& policy,
    InputIterator first,
    Size count,
    ForwardIterator dest);
```

### <a name="parameters"></a>parâmetros

\ de *política*
A política de execução a ser usada.

*primeiro*\
Um iterador de entrada que faz referência ao objeto a ser copiado.

*contagem*\
Um tipo de inteiro com sinal e sem sinal que especifica o número de vezes que o objeto deve ser copiado.

\ de *dest*
Um iterador de avanço que faz referência ao local das novas cópias.

### <a name="return-value"></a>Valor retornado

Um iterador de avanço que atende à primeira posição além do destino. Se o intervalo de origem estava vazio, os endereços do iterador *primeiro*.

### <a name="remarks"></a>Comentários

A função de modelo executa efetivamente o seguinte código:

```cpp
    for (; 0 < count; --count)
        new (static_cast<void*>(&* dest++))
            typename iterator_traits<InputIterator>::value_type(*first++);
    return dest;
```

a menos que o código lance uma exceção. Nesse caso, todos os objetos construídos são destruídos e a exceção é relançada.

A sobrecarga com uma política de execução é nova no C++ 17.

## <a name="uninitialized_default_construct"></a>uninitialized_default_construct

O padrão constrói objetos dos iteradores ' `value_type` no intervalo especificado.

```cpp
template <class ForwardIterator>
void uninitialized_default_construct(
    ForwardIterator first,
    ForwardIterator last);

template <class ExecutionPolicy, class ForwardIterator>
void uninitialized_default_construct(
    ExecutionPolicy&& policy,
    ForwardIterator first,
    ForwardIterator last);
```

### <a name="parameters"></a>parâmetros

\ de *política*
A política de execução a ser usada.

*primeiro*\
Um iterador que aborda o primeiro elemento no intervalo a ser construído.

*última*\
Um iterador que aborda um último elemento no intervalo a ser construído.

### <a name="remarks"></a>Comentários

A versão sem uma política de execução é efetivamente a mesma:

```cpp
for (; first != last; ++first)
    ::new (static_cast<void*>(addressof(*first)))
        typename iterator_traits<ForwardIterator>::value_type;
```

Se uma exceção for lançada, os objetos construídos anteriormente serão destruídos na ordem não especificada.

A versão com uma política de execução tem o mesmo resultado, mas é executada de acordo com a *política*especificada.

Essas funções são novas no C++ 17.

## <a name="uninitialized_default_construct_n"></a>uninitialized_default_construct_n

O padrão constrói um número especificado de objetos do `value_type`do iterador, começando no local especificado.

```cpp
template <class ForwardIterator, class Size>
ForwardIterator uninitialized_default_construct_n(
    ForwardIterator first,
    Size count);

template <class ExecutionPolicy, class ForwardIterator, class Size>
ForwardIterator uninitialized_default_construct_n(
    ExecutionPolicy&& policy,
    ForwardIterator first,
    Size count);
```

### <a name="parameters"></a>parâmetros

\ de *política*
A política de execução a ser usada.

*primeiro*\
Um iterador que aborda o primeiro elemento no intervalo de destino a ser construído.

*contagem*\
A contagem de elementos no intervalo de destino a ser construído.

### <a name="return-value"></a>Valor retornado

Um iterador posterior que aborda a primeira posição além do intervalo de destino, a menos que o intervalo de origem esteja vazio.

### <a name="remarks"></a>Comentários

A versão sem uma política de execução é efetivamente a mesma:

```cpp
for (; count>0; (void)++first, --count)
    ::new (static_cast<void*>(addressof(*first)))
        typename iterator_traits<ForwardIterator>::value_type;
return first;
```

Se uma exceção for lançada, os objetos construídos anteriormente serão destruídos na ordem não especificada.

A versão com uma política de execução tem o mesmo resultado, mas é executada de acordo com a *política*especificada.

Essas funções são novas no C++ 17.

## <a name="uninitialized_fill"></a>uninitialized_fill

Copia objetos de um valor especificado em um intervalo de destino não inicializado.

```cpp
template <class ForwardIterator, class T>
void uninitialized_fill(
    ForwardIterator first,
    ForwardIterator last,
    const T& value);

template <class ExecutionPolicy, class ForwardIterator, class T>
void uninitialized_fill(
    ExecutionPolicy&& policy,
    ForwardIterator first,
    ForwardIterator last,
    const T& value);
```

### <a name="parameters"></a>parâmetros

\ de *política*
A política de execução a ser usada.

*primeiro*\
Um iterador posterior que aborda o primeiro elemento no intervalo de destino a ser inicializado.

*última*\
Um iterador posterior que aborda o último elemento no intervalo de destino a ser inicializado.

*value*\
O valor a ser usado para inicializar o intervalo de destino.

### <a name="remarks"></a>Comentários

Esse algoritmo permite dissociar a alocação da memória da construção do objeto.

A função de modelo é executada efetivamente:

```cpp
while (first != last)
    new (static_cast<void*>(&* first ++))
        typename iterator_traits<ForwardIterator>::value_type (value);
```

a menos que o código lance uma exceção. Nesse caso, todos os objetos construídos são destruídos e a exceção é relançada.

A sobrecarga com uma política de execução é nova no C++ 17.

### <a name="example"></a>Exemplo

```cpp
// memory_uninit_fill.cpp
// compile with: /EHsc
#include <memory>
#include <iostream>

using namespace std;

class Integer
{
public:
    // No default constructor
    Integer( int x ) : value( x ) {}
    int get() { return value; }
private:
    int value;
};

int main()
{
    const int N = 10;
    Integer value ( 25 );
    Integer* Array = ( Integer* ) malloc( N * sizeof( int ) );
    uninitialized_fill( Array, Array + N, value );
    cout << "The initialized Array contains: ";
    for ( int i = 0; i < N; i++ )
        {
            cout << Array[ i ].get() << " ";
        }
    cout << endl;
}
```

```Output
The initialized Array contains: 25 25 25 25 25 25 25 25 25 25
```

## <a name="uninitialized_fill_n"></a>uninitialized_fill_n

Copia objetos de um valor especificado para o número especificado de elementos de um intervalo de destino não inicializado.

```cpp
template <class ForwardIterator, class Size, class T>
ForwardIterator uninitialized_fill_n(
    ForwardIterator first,
    Size count,
    const T& value);

template <class ExecutionPolicy, class ForwardIterator, class Size, class T>
ForwardIterator uninitialized_fill_n(
    ExecutionPolicy&& policy,
    ForwardIterator first,
    Size count,
    const T& value);
```

### <a name="parameters"></a>parâmetros

\ de *política*
A política de execução a ser usada.

*primeiro*\
Um iterador posterior que aborda o primeiro elemento no intervalo de destino a ser inicializado.

*contagem*\
O número de elementos a serem inicializados.

*value*\
O valor a ser usado para inicializar o intervalo de destino.

### <a name="remarks"></a>Comentários

Esse algoritmo permite dissociar a alocação da memória da construção do objeto.

A função de modelo é executada efetivamente:

```cpp
while (0 < count--)
    new (static_cast<void*>(&* first++))
        typename iterator_traits<ForwardIterator>::value_type(value);
return first;
```

a menos que o código lance uma exceção. Nesse caso, todos os objetos construídos são destruídos e a exceção é relançada.

A sobrecarga com uma política de execução é nova no C++ 17.

### <a name="example"></a>Exemplo

```cpp
// memory_uninit_fill_n.cpp
// compile with: /EHsc /W3
#include <memory>
#include <iostream>

using namespace std;

class Integer
{
public:
    // No default constructor
    Integer( int x ) : value( x ) {}
    int get() { return value; }
private:
    int value;
};

int main()
{
    const int N = 10;
    Integer value( 60 );
    Integer* Array = ( Integer* ) malloc( N * sizeof( int ) );
    uninitialized_fill_n( Array, N, value );  // C4996
    cout << "The uninitialized Array contains: ";
    for ( int i = 0; i < N; i++ )
        cout << Array[ i ].get() <<  " ";
}
```

## <a name="uninitialized_move"></a>uninitialized_move

Move os elementos de um intervalo de origem para uma área de memória de destino não inicializada.

```cpp
template <class InputIterator, class ForwardIterator>
ForwardIterator uninitialized_move(
    InputIterator first,
    InputIterator last,
    ForwardIterator dest);

template <class ExecutionPolicy, class InputIterator, class ForwardIterator>
ForwardIterator uninitialized_move(
    ExecutionPolicy&& policy,
    InputIterator first,
    InputIterator last,
    ForwardIterator dest);
```

### <a name="parameters"></a>parâmetros

\ de *política*
A política de execução a ser usada.

*primeiro*\
Um iterador de entrada que aborda o primeiro elemento no intervalo de origem a ser movido.

*última*\
Um iterador de entrada que aborda um anterior ao último elemento no intervalo de origem a ser movido.

\ de *dest*
O início do intervalo de destino.

### <a name="remarks"></a>Comentários

A versão sem uma política de execução é efetivamente a mesma:

```cpp
for (; first != last; (void)++dest, ++first)
    ::new (static_cast<void*>(addressof(*dest)))
        typename iterator_traits<ForwardIterator>::value_type(std::move(*first));
return dest;
```

Se uma exceção for lançada, alguns objetos no intervalo de origem poderão ser deixados em um estado válido, mas não especificado. Os objetos construídos anteriormente são destruídos na ordem não especificada.

A versão com uma política de execução tem o mesmo resultado, mas é executada de acordo com a *política*especificada.

Essas funções são novas no C++ 17.

## <a name="uninitialized_move_n"></a>uninitialized_move_n

Move um número especificado de elementos de um intervalo de origem para uma área de memória de destino não inicializada.

```cpp
template <class InputIterator, class Size, class ForwardIterator>
pair<InputIterator, ForwardIterator> uninitialized_move_n(
    InputIterator first,
    Size count,
    ForwardIterator dest);

template <class ExecutionPolicy, class InputIterator, class Size, class ForwardIterator>
pair<InputIterator, ForwardIterator> uninitialized_move_n(
    ExecutionPolicy&& policy,
    InputIterator first,
    Size count,
    ForwardIterator dest);
```

### <a name="parameters"></a>parâmetros

\ de *política*
A política de execução a ser usada.

*primeiro*\
Um iterador de entrada que aborda o primeiro elemento no intervalo de origem a ser movido.

*contagem*\
A contagem de elementos no intervalo de origem a serem movidos.

\ de *dest*
O início do intervalo de destino.

### <a name="remarks"></a>Comentários

A versão sem uma política de execução é efetivamente a mesma:

```cpp
for (; count > 0; ++dest, (void) ++first, --count)
    ::new (static_cast<void*>(addressof(*dest)))
        typename iterator_traits<ForwardIterator>::value_type(std::move(*first));
return {first, dest};
```

Se uma exceção for lançada, alguns objetos no intervalo de origem poderão ser deixados em um estado válido, mas não especificado. Os objetos construídos anteriormente são destruídos na ordem não especificada.

A versão com uma política de execução tem o mesmo resultado, mas é executada de acordo com a *política*especificada.

Essas funções são novas no C++ 17.

## <a name="uninitialized_value_construct"></a>uninitialized_value_construct

Constrói objetos do `value_type` do iteradores por inicialização de valor, no intervalo especificado.

```cpp
template <class ForwardIterator>
void uninitialized_value_construct(
    ForwardIterator first,
    ForwardIterator last);

template <class ExecutionPolicy, class ForwardIterator>
void uninitialized_value_construct(
    ExecutionPolicy&& policy,
    ForwardIterator first,
    ForwardIterator last);
```

### <a name="parameters"></a>parâmetros

\ de *política*
A política de execução a ser usada.

*primeiro*\
Um iterador que aborda o primeiro elemento no constructo de intervalo para valor.

*última*\
Um iterador que aborda um último elemento no constructo de intervalo para valor.

### <a name="remarks"></a>Comentários

A versão sem uma política de execução é efetivamente a mesma:

```cpp
for (; first != last; ++first)
    ::new (static_cast<void*>(addressof(*first)))
        typename iterator_traits<ForwardIterator>::value_type();
```

Se uma exceção for lançada, os objetos construídos anteriormente serão destruídos na ordem não especificada.

A versão com uma política de execução tem o mesmo resultado, mas é executada de acordo com a *política*especificada.

Se ocorrer uma falha de alocação de memória, uma exceção de `std::bad_alloc` será lançada.

Essas funções são novas no C++ 17.

## <a name="uninitialized_value_construct_n"></a>uninitialized_value_construct_n

Constrói um número especificado de objetos do `value_type` do iterador por inicialização de valor, começando no local especificado.

```cpp
template <class ForwardIterator, class Size>
ForwardIterator uninitialized_value_construct_n(
    ForwardIterator first,
    Size count);

template <class ExecutionPolicy, class ForwardIterator, class Size>
ForwardIterator uninitialized_value_construct_n(
    ExecutionPolicy&& policy,
    ForwardIterator first,
    Size count);
```

### <a name="parameters"></a>parâmetros

\ de *política*
A política de execução a ser usada.

*primeiro*\
Um iterador que aborda o primeiro elemento no intervalo de destino a ser construído.

*contagem*\
A contagem de elementos no intervalo de destino a ser construído.

### <a name="remarks"></a>Comentários

A versão sem uma política de execução é efetivamente a mesma:

```cpp
for (; count > 0; (void)++first, --count)
    ::new (static_cast<void*>(addressof(*first)))
        typename iterator_traits<ForwardIterator>::value_type();
return first;
```

Se uma exceção for lançada, os objetos construídos anteriormente serão destruídos na ordem não especificada.

A versão com uma política de execução tem o mesmo resultado, mas é executada de acordo com a *política*especificada.

Se ocorrer uma falha de alocação de memória, uma exceção de `std::bad_alloc` será lançada.

Essas funções são novas no C++ 17.

## <a name="uses_allocator_v"></a>uses_allocator_v

Um modelo de variável auxiliar para acessar o valor do modelo de `uses_allocator`.

```cpp
template <class T, class Alloc>
inline constexpr bool uses_allocator_v = uses_allocator<T, Alloc>::value;
```

## <a name="see-also"></a>Confira também

[\<memory>](memory.md)
