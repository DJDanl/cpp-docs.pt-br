---
title: Classe allocator_base | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
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
dev_langs:
- C++
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9f27cb2bc1a711b77006fa496cc080f546e539ab
ms.sourcegitcommit: 3614b52b28c24f70d90b20d781d548ef74ef7082
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/11/2018
ms.locfileid: "38962441"
---
# <a name="allocatorbase-class"></a>Classe allocator_base

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
|*sincronização*|A política de sincronização do alocador, que é [Classe sync_none](../standard-library/sync-none-class.md), [Classe sync_per_container](../standard-library/sync-per-container-class.md), [Classe sync_per_thread](../standard-library/sync-per-thread-class.md) ou [Classe sync_shared](../standard-library/sync-shared-class.md).|

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[allocator_base](#allocator_base)|Constrói um objeto do tipo `allocator_base`.|

### <a name="typedefs"></a>Typedefs

|Nome de tipo|Descrição|
|-|-|
|[const_pointer](#const_pointer)|Um tipo que fornece um ponteiro constante para o tipo de objeto gerenciado pelo alocador.|
|[const_reference](#const_reference)|Um tipo que fornece uma referência constante ao tipo de objeto gerenciado pelo alocador.|
|[difference_type](#difference_type)|Um tipo integral com sinal que pode representar a diferença entre os valores de ponteiros para o tipo de objeto gerenciado pelo alocador.|
|[pointer](#pointer)|Um tipo que fornece um ponteiro para o tipo de objeto gerenciado pelo alocador.|
|[reference](#reference)|Um tipo que fornece uma referência ao tipo de objeto gerenciado pelo alocador.|
|[size_type](#size_type)|Um tipo integral sem sinal que pode representar o comprimento de qualquer sequência que um objeto da classe de modelo `allocator_base` possa alocar.|
|[value_type](#value_type)|Um tipo que é gerenciado pelo alocador.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[_Charalloc](#charalloc)|Aloca armazenamento para uma matriz do tipo **char**.|
|[_Chardealloc](#chardealloc)|Libera armazenamento para a matriz que contém elementos do tipo **char**.|
|[address](#address)|Localiza o endereço de um objeto cujo valor é especificado.|
|[allocate](#allocate)|Aloca um bloco de memória grande o suficiente para armazenar pelo menos um número especificado de elementos.|
|[construct](#construct)|Constrói um tipo específico de objeto em um endereço especificado que é inicializado com um valor especificado.|
|[deallocate](#deallocate)|Libera um número especificado de objetos do armazenamento começando em uma posição especificada.|
|[destroy](#destroy)|Chama um destruidor de objetos sem desalocar a memória na qual o objeto foi armazenado.|
|[max_size](#max_size)|Retorna o número de elementos do tipo *Type* que podem ser alocados por um objeto da classe allocator antes que a memória livre seja totalmente usada.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<allocators>

**Namespace:** stdext

## <a name="charalloc"></a>  allocator_base::_Charalloc

Aloca armazenamento para uma matriz do tipo **char**.

```cpp
char *_Charalloc(size_type count);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*count*|O número de elementos na matriz a serem alocados.|

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o objeto alocado.

### <a name="remarks"></a>Comentários

Essa função de membro é usada pelos contêineres quando são compilados com um compilador que não pode compilar reassociação. Ela implementa `_Charalloc` para o alocador definido pelo usuário, retornando o resultado de uma chamada para a função `allocate` do filtro de sincronização.

## <a name="chardealloc"></a>  allocator_base::_Chardealloc

Libera armazenamento para a matriz que contém elementos do tipo **char**.

```cpp
void _Chardealloc(void* ptr, size_type count);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*ptr*|Um ponteiro para o primeiro objeto a ser desalocado do armazenamento.|
|*count*|O número de objetos a serem desalocados do armazenamento.|

### <a name="remarks"></a>Comentários

Essa função de membro é usada pelos contêineres quando são compilados com um compilador que não pode compilar reassociação. Ela implementa `_Chardealloc` para o alocador definido pelo usuário ao chamar a função `deallocate` do filtro de sincronização. O ponteiro PTR deve ter sido retornado anteriormente por uma chamada para `_Charalloc` de um objeto alocador que compara como igual a `*this`, alocando um objeto de matriz dos mesmos tipo e tamanho. `_Chardealloc` nunca gera uma exceção.

## <a name="address"></a>  allocator_base::address

Localiza o endereço de um objeto cujo valor é especificado.

```cpp
pointer address(reference val);

const_pointer address(const_reference val);
```

### <a name="parameters"></a>Parâmetros

*Val* o valor const ou do objeto cujo endereço está sendo pesquisado.

### <a name="return-value"></a>Valor de retorno

Um ponteiro const ou não const para o objeto localizado, de valor const ou não const, respectivamente.

### <a name="remarks"></a>Comentários

Essa função de membro é implementada para o alocador definido pelo usuário, retornando `&val`.

## <a name="allocate"></a>  allocator_base::allocate

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

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o objeto alocado.

### <a name="remarks"></a>Comentários

A função de membro implementa a alocação de memória para o alocador definido pelo usuário, retornando o resultado de uma chamada para a função `allocate` do filtro de sincronização do tipo Type `*` se `_Nx == 1`, caso contrário, retornando o resultado de uma chamada para `operator new(_Nx * sizeof(Type))` transmitido para o tipo Type `*`.

## <a name="allocator_base"></a>  allocator_base::allocator_base

Constrói um objeto do tipo `allocator_base`.

```cpp
allocator_base();

template <class Other>
allocator_base(const allocator_base<Other, Sync>& right);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*right*|O objeto alocador a ser copiado.|

### <a name="remarks"></a>Comentários

O primeiro construtor constrói uma instância de [allocator_base](../standard-library/allocator-base-class.md). O segundo construtor constrói uma instância `allocator_base` de modo que, para qualquer instância de `allocator_base<Type, _Sync>` `a`, `allocator_base<Type, Sync>(allocator_base<Other, Sync>(a)) == a`.

## <a name="const_pointer"></a>  allocator_base::const_pointer

Um tipo que fornece um ponteiro constante para o tipo de objeto gerenciado pelo alocador.

```cpp
typedef const Type *const_pointer;
```

## <a name="const_reference"></a>  allocator_base::const_reference

Um tipo que fornece uma referência constante ao tipo de objeto gerenciado pelo alocador.

```cpp
typedef const Type& const_reference;
```

## <a name="construct"></a>  allocator_base::construct

Constrói um tipo específico de objeto em um endereço especificado que é inicializado com um valor especificado.

```cpp
void construct(pointer ptr, const Type& val);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*ptr*|Um ponteiro para o local no qual o objeto deve ser construído.|
|*Val*|O valor com o qual o objeto que está sendo construído deve ser inicializado.|

### <a name="remarks"></a>Comentários

Essa função de membro é implementada para o alocador definido pelo usuário ao chamar `new((void*)ptr Type(val)`.

## <a name="deallocate"></a>  allocator_base::deallocate

Libera um número especificado de objetos do armazenamento começando em uma posição especificada.

```cpp
void deallocate(pointer ptr, size_type _Nx);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*ptr*|Um ponteiro para o primeiro objeto a ser desalocado do armazenamento.|
|*_Nx*|O número de objetos a serem desalocados do armazenamento.|

### <a name="remarks"></a>Comentários

Essa função de membro é implementada para o alocador definido pelo usuário chamando `deallocate(ptr)` no filtro de sincronização `Sync` se `_Nx == 1`, caso contrário, chamando `operator delete(_Nx * ptr)`.

## <a name="destroy"></a>  allocator_base::destroy

Chama um destruidor de objetos sem desalocar a memória na qual o objeto foi armazenado.

```cpp
void destroy(pointer ptr);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*ptr*|Um ponteiro que designa o endereço do objeto a ser destruído.|

### <a name="remarks"></a>Comentários

Essa função de membro é implementada para o alocador definido pelo usuário ao chamar `ptr->~Type()`.

## <a name="difference_type"></a>  allocator_base::difference_type

Um tipo integral com sinal que pode representar a diferença entre os valores de ponteiros para o tipo de objeto gerenciado pelo alocador.

```cpp
typedef std::ptrdiff_t difference_type;
```

## <a name="max_size"></a>  allocator_base::max_size

Retorna o número de elementos do tipo `Type` que podem ser alocados por um objeto da classe allocator antes que a memória livre seja totalmente usada.

```cpp
size_type max_size() const;
```

### <a name="return-value"></a>Valor de retorno

O número de elementos que podem ser alocados.

### <a name="remarks"></a>Comentários

Essa função de membro é implementada para o alocador definido pelo usuário, retornando `(size_t)-1 / sizeof(Type)` se `0 < (size_t)-1 / sizeof(Type)`, caso contrário, `1`.

## <a name="pointer"></a>  allocator_base::pointer

Um tipo que fornece um ponteiro para o tipo de objeto gerenciado pelo alocador.

```cpp
typedef Type *pointer;
```

## <a name="reference"></a>  allocator_base::reference

Um tipo que fornece uma referência ao tipo de objeto gerenciado pelo alocador.

```cpp
typedef Type& reference;
```

## <a name="size_type"></a>  allocator_base::size_type

Um tipo integral sem sinal que pode representar o comprimento de qualquer sequência que um objeto da classe de modelo `allocator_base` possa alocar.

```cpp
typedef std::size_t size_type;
```

## <a name="value_type"></a>  allocator_base::value_type

Um tipo que é gerenciado pelo alocador.

```cpp
typedef Type value_type;
```

## <a name="see-also"></a>Consulte também

[\<allocators>](../standard-library/allocators-header.md)<br/>
