---
title: Classe allocator_base
ms.date: 11/04/2016
f1_keywords:
- allocators/stdext::allocator_base
- allocators/stdext::allocators::allocator_base
- allocators/stdext::allocator_base::const_pointer
- allocators/stdext::allocator_base::const_reference
- allocators/stdext::allocator_base::difference_type
- allocators/stdext::allocator_base::pointer
- allocators/stdext::allocator_base::reference
- allocators/stdext::allocator_base::size_type
- allocators/stdext::allocator_base::value_type
- allocators/stdext::allocator_base::_Charalloc
- allocators/stdext::allocator_base::_Chardealloc
- allocators/stdext::allocator_base::address
- allocators/stdext::allocator_base::allocate
- allocators/stdext::allocator_base::construct
- allocators/stdext::allocator_base::deallocate
- allocators/stdext::allocator_base::destroy
- allocators/stdext::allocator_base::max_size
helpviewer_keywords:
- stdext::allocator_base [C++]
- stdext::allocators [C++], allocator_base
- stdext::allocator_base [C++], const_pointer
- stdext::allocator_base [C++], const_reference
- stdext::allocator_base [C++], difference_type
- stdext::allocator_base [C++], pointer
- stdext::allocator_base [C++], reference
- stdext::allocator_base [C++], size_type
- stdext::allocator_base [C++], value_type
- stdext::allocator_base [C++], _Charalloc
- stdext::allocator_base [C++], _Chardealloc
- stdext::allocator_base [C++], address
- stdext::allocator_base [C++], allocate
- stdext::allocator_base [C++], construct
- stdext::allocator_base [C++], deallocate
- stdext::allocator_base [C++], destroy
- stdext::allocator_base [C++], max_size
ms.assetid: f920b45f-2a88-4bb0-8ead-b6126b426ed4
ms.openlocfilehash: f93c8ff53452fc98415e194966960254e7b44143
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81364989"
---
# <a name="allocator_base-class"></a>Classe allocator_base

Define a classe base e as funções comuns necessárias para criar um alocador definido pelo usuário de um filtro de sincronização.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Type, class Sync>
class allocator_base
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Tipo*|O tipo dos elementos alocados pelo alocador.|
|*Sincronização*|A política de sincronização do alocador, que é [Classe sync_none](../standard-library/sync-none-class.md), [Classe sync_per_container](../standard-library/sync-per-container-class.md), [Classe sync_per_thread](../standard-library/sync-per-thread-class.md) ou [Classe sync_shared](../standard-library/sync-shared-class.md).|

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[allocator_base](#allocator_base)|Constrói um objeto do tipo `allocator_base`.|

### <a name="typedefs"></a>Typedefs

|Nome do tipo|Descrição|
|-|-|
|[const_pointer](#const_pointer)|Um tipo que fornece um ponteiro constante para o tipo de objeto gerenciado pelo alocador.|
|[const_reference](#const_reference)|Um tipo que fornece uma referência constante ao tipo de objeto gerenciado pelo alocador.|
|[difference_type](#difference_type)|Um tipo integral com sinal que pode representar a diferença entre os valores de ponteiros para o tipo de objeto gerenciado pelo alocador.|
|[ponteiro](#pointer)|Um tipo que fornece um ponteiro para o tipo de objeto gerenciado pelo alocador.|
|[Referência](#reference)|Um tipo que fornece uma referência ao tipo de objeto gerenciado pelo alocador.|
|[size_type](#size_type)|Um tipo integral não assinado que pode representar o `allocator_base` comprimento de qualquer seqüência que um objeto de tipo pode alocar.|
|[Value_type](#value_type)|Um tipo que é gerenciado pelo alocador.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[_Charalloc](#charalloc)|Aloca o armazenamento para uma matriz de **tipo char**.|
|[_Chardealloc](#chardealloc)|Libera o armazenamento para a matriz que contém elementos do tipo **char**.|
|[Endereço](#address)|Localiza o endereço de um objeto cujo valor é especificado.|
|[Alocar](#allocate)|Aloca um bloco de memória grande o suficiente para armazenar pelo menos um número especificado de elementos.|
|[construct](#construct)|Constrói um tipo específico de objeto em um endereço especificado que é inicializado com um valor especificado.|
|[Desalocar](#deallocate)|Libera um número especificado de objetos do armazenamento começando em uma posição especificada.|
|[Destruir](#destroy)|Chama um destruidor de objetos sem desalocar a memória na qual o objeto foi armazenado.|
|[Max_size](#max_size)|Retorna o número de elementos do tipo *Type* que podem ser alocados por um objeto da classe allocator antes que a memória livre seja totalmente usada.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<allocators>

**Namespace:** stdext

## <a name="allocator_base_charalloc"></a><a name="charalloc"></a>allocator_base:_Charalloc

Aloca o armazenamento para uma matriz de **tipo char**.

```cpp
char *_Charalloc(size_type count);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*contagem*|O número de elementos na matriz a serem alocados.|

### <a name="return-value"></a>Valor retornado

Um ponteiro para o objeto alocado.

### <a name="remarks"></a>Comentários

Essa função de membro é usada pelos contêineres quando são compilados com um compilador que não pode compilar reassociação. Ela implementa `_Charalloc` para o alocador definido pelo usuário, retornando o resultado de uma chamada para a função `allocate` do filtro de sincronização.

## <a name="allocator_base_chardealloc"></a><a name="chardealloc"></a>allocator_base:_Chardealloc

Libera o armazenamento para a matriz que contém elementos do tipo **char**.

```cpp
void _Chardealloc(void* ptr, size_type count);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Ptr*|Um ponteiro para o primeiro objeto a ser desalocado do armazenamento.|
|*contagem*|O número de objetos a serem desalocados do armazenamento.|

### <a name="remarks"></a>Comentários

Essa função de membro é usada pelos contêineres quando são compilados com um compilador que não pode compilar reassociação. Ela implementa `_Chardealloc` para o alocador definido pelo usuário ao chamar a função `deallocate` do filtro de sincronização. O ponteiro PTR deve ter sido retornado anteriormente por uma chamada para `_Charalloc` de um objeto alocador que compara como igual a `*this`, alocando um objeto de matriz dos mesmos tipo e tamanho. `_Chardealloc` nunca gera uma exceção.

## <a name="allocator_baseaddress"></a><a name="address"></a>allocator_base::endereço

Localiza o endereço de um objeto cujo valor é especificado.

```cpp
pointer address(reference val);

const_pointer address(const_reference val);
```

### <a name="parameters"></a>Parâmetros

*Val*\
O valor const ou não const do objeto cujo endereço está sendo pesquisado.

### <a name="return-value"></a>Valor retornado

Um ponteiro const ou não const para o objeto localizado, de valor const ou não const, respectivamente.

### <a name="remarks"></a>Comentários

Essa função de membro é implementada para o alocador definido pelo usuário, retornando `&val`.

## <a name="allocator_baseallocate"></a><a name="allocate"></a>allocator_base::alocar

Aloca um bloco de memória grande o suficiente para armazenar pelo menos um número especificado de elementos.

```cpp
template <class Other>
pointer allocate(size_type _Nx, const Other* _Hint = 0);

pointer allocate(size_type _Nx);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*_Nx*|O número de elementos na matriz a serem alocados.|
|*_Hint*|Este parâmetro é ignorado.|

### <a name="return-value"></a>Valor retornado

Um ponteiro para o objeto alocado.

### <a name="remarks"></a>Comentários

A função de membro implementa a alocação de memória para o alocador definido pelo usuário, retornando o resultado de uma chamada para a função `allocate` do filtro de sincronização do tipo Type `*` se `_Nx == 1`, caso contrário, retornando o resultado de uma chamada para `operator new(_Nx * sizeof(Type))` transmitido para o tipo Type `*`.

## <a name="allocator_baseallocator_base"></a><a name="allocator_base"></a>allocator_base::allocator_base

Constrói um objeto do tipo `allocator_base`.

```cpp
allocator_base();

template <class Other>
allocator_base(const allocator_base<Other, Sync>& right);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Certo*|O objeto alocador a ser copiado.|

### <a name="remarks"></a>Comentários

O primeiro construtor constrói uma instância de [allocator_base](../standard-library/allocator-base-class.md). O segundo construtor constrói uma instância `allocator_base` de modo que, para qualquer instância de `allocator_base<Type, _Sync>``a`, `allocator_base<Type, Sync>(allocator_base<Other, Sync>(a)) == a`.

## <a name="allocator_baseconst_pointer"></a><a name="const_pointer"></a>allocator_base:const_pointer

Um tipo que fornece um ponteiro constante para o tipo de objeto gerenciado pelo alocador.

```cpp
typedef const Type *const_pointer;
```

## <a name="allocator_baseconst_reference"></a><a name="const_reference"></a>allocator_base:const_reference

Um tipo que fornece uma referência constante ao tipo de objeto gerenciado pelo alocador.

```cpp
typedef const Type& const_reference;
```

## <a name="allocator_baseconstruct"></a><a name="construct"></a>allocator_base::construção

Constrói um tipo específico de objeto em um endereço especificado que é inicializado com um valor especificado.

```cpp
void construct(pointer ptr, const Type& val);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Ptr*|Um ponteiro para o local no qual o objeto deve ser construído.|
|*Val*|O valor com o qual o objeto que está sendo construído deve ser inicializado.|

### <a name="remarks"></a>Comentários

Essa função de membro é implementada para o alocador definido pelo usuário ao chamar `new((void*)ptr Type(val)`.

## <a name="allocator_basedeallocate"></a><a name="deallocate"></a>allocator_base::deallocate

Libera um número especificado de objetos do armazenamento começando em uma posição especificada.

```cpp
void deallocate(pointer ptr, size_type _Nx);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Ptr*|Um ponteiro para o primeiro objeto a ser desalocado do armazenamento.|
|*_Nx*|O número de objetos a serem desalocados do armazenamento.|

### <a name="remarks"></a>Comentários

Essa função de membro é implementada para o alocador definido pelo usuário chamando `deallocate(ptr)` no filtro de sincronização `Sync` se `_Nx == 1`, caso contrário, chamando `operator delete(_Nx * ptr)`.

## <a name="allocator_basedestroy"></a><a name="destroy"></a>allocator_base::destroy

Chama um destruidor de objetos sem desalocar a memória na qual o objeto foi armazenado.

```cpp
void destroy(pointer ptr);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Ptr*|Um ponteiro que designa o endereço do objeto a ser destruído.|

### <a name="remarks"></a>Comentários

Essa função de membro é implementada para o alocador definido pelo usuário ao chamar `ptr->~Type()`.

## <a name="allocator_basedifference_type"></a><a name="difference_type"></a>allocator_base::difference_type

Um tipo integral com sinal que pode representar a diferença entre os valores de ponteiros para o tipo de objeto gerenciado pelo alocador.

```cpp
typedef std::ptrdiff_t difference_type;
```

## <a name="allocator_basemax_size"></a><a name="max_size"></a>allocator_base:max_size

Retorna o número de elementos do tipo `Type` que podem ser alocados por um objeto da classe allocator antes que a memória livre seja totalmente usada.

```cpp
size_type max_size() const;
```

### <a name="return-value"></a>Valor retornado

O número de elementos que podem ser alocados.

### <a name="remarks"></a>Comentários

Essa função de membro é implementada para o alocador definido pelo usuário, retornando `(size_t)-1 / sizeof(Type)` se `0 < (size_t)-1 / sizeof(Type)`, caso contrário, `1`.

## <a name="allocator_basepointer"></a><a name="pointer"></a>allocator_base::pointer

Um tipo que fornece um ponteiro para o tipo de objeto gerenciado pelo alocador.

```cpp
typedef Type *pointer;
```

## <a name="allocator_basereference"></a><a name="reference"></a>allocator_base::referência

Um tipo que fornece uma referência ao tipo de objeto gerenciado pelo alocador.

```cpp
typedef Type& reference;
```

## <a name="allocator_basesize_type"></a><a name="size_type"></a>allocator_base:size_type

Um tipo integral não assinado que pode representar o `allocator_base` comprimento de qualquer seqüência que um objeto de tipo pode alocar.

```cpp
typedef std::size_t size_type;
```

## <a name="allocator_basevalue_type"></a><a name="value_type"></a>allocator_base:value_type

Um tipo que é gerenciado pelo alocador.

```cpp
typedef Type value_type;
```

## <a name="see-also"></a>Confira também

[\<alocadores>](../standard-library/allocators-header.md)
