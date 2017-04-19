---
title: Classe allocator_base | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- allocator_base
- allocators/stdext::allocator_base
- stdext::allocator_base
- stdext::allocators::allocator_base
- allocators/stdext::allocators::allocator_base
- allocators::allocator_base
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
- allocator_base class
ms.assetid: f920b45f-2a88-4bb0-8ead-b6126b426ed4
caps.latest.revision: 17
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: c355c76db22cd581bc0458d48c93563f4bbe7712
ms.lasthandoff: 02/25/2017

---
# <a name="allocatorbase-class"></a>Classe allocator_base
Define a classe base e as funções comuns necessárias para criar um alocador definido pelo usuário de um filtro de sincronização.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class Type, class Sync>  
class allocator_base
```  
  
#### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`Type`|O tipo dos elementos alocados pelo alocador.|  
|`Sync`|A política de sincronização do alocador, que é [Classe sync_none](../standard-library/sync-none-class.md), [Classe sync_per_container](../standard-library/sync-per-container-class.md), [Classe sync_per_thread](../standard-library/sync-per-thread-class.md) ou [Classe sync_shared](../standard-library/sync-shared-class.md).|  
  
### <a name="constructors"></a>Construtores  
  
|||  
|-|-|  
|[allocator_base](#allocator_base__allocator_base)|Constrói um objeto do tipo `allocator_base`.|  
  
### <a name="typedefs"></a>TypeDefs  
  
|||  
|-|-|  
|[const_pointer](#allocator_base__const_pointer)|Um tipo que fornece um ponteiro constante para o tipo de objeto gerenciado pelo alocador.|  
|[const_reference](#allocator_base__const_reference)|Um tipo que fornece uma referência constante ao tipo de objeto gerenciado pelo alocador.|  
|[difference_type](#allocator_base__difference_type)|Um tipo integral com sinal que pode representar a diferença entre os valores de ponteiros para o tipo de objeto gerenciado pelo alocador.|  
|[pointer](#allocator_base__pointer)|Um tipo que fornece um ponteiro para o tipo de objeto gerenciado pelo alocador.|  
|[reference](#allocator_base__reference)|Um tipo que fornece uma referência ao tipo de objeto gerenciado pelo alocador.|  
|[size_type](#allocator_base__size_type)|Um tipo integral sem sinal que pode representar o comprimento de qualquer sequência que um objeto da classe de modelo `allocator_base` possa alocar.|  
|[value_type](#allocator_base__value_type)|Um tipo que é gerenciado pelo alocador.|  
  
### <a name="member-functions"></a>Funções membro  
  
|||  
|-|-|  
|[_Charalloc](#allocator_base___charalloc)|Aloca armazenamento para uma matriz do tipos `char`.|  
|[_Chardealloc](#allocator_base___chardealloc)|Libera armazenamento para a matriz que contém os elementos do tipo `char`.|  
|[address](#allocator_base__address)|Localiza o endereço de um objeto cujo valor é especificado.|  
|[allocate](#allocator_base__allocate)|Aloca um bloco de memória grande o suficiente para armazenar pelo menos um número especificado de elementos.|  
|[construct](#allocator_base__construct)|Constrói um tipo específico de objeto em um endereço especificado que é inicializado com um valor especificado.|  
|[deallocate](#allocator_base__deallocate)|Libera um número especificado de objetos do armazenamento começando em uma posição especificada.|  
|[destroy](#allocator_base__destroy)|Chama um destruidor de objetos sem desalocar a memória na qual o objeto foi armazenado.|  
|[max_size](#allocator_base__max_size)|Retorna o número de elementos do tipo `Type` que podem ser alocados por um objeto da classe allocator antes que a memória livre seja totalmente usada.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<allocators>  
  
 **Namespace:** stdext  
  
##  <a name="allocator_base___charalloc"></a>  allocator_base::_Charalloc  
 Aloca armazenamento para uma matriz do tipos `char`.  
  
```
char *_Charalloc(size_type count);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`count`|O número de elementos na matriz a serem alocados.|  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o objeto alocado.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro é usada pelos contêineres quando são compilados com um compilador que não pode compilar reassociação. Ela implementa `_Charalloc` para o alocador definido pelo usuário, retornando o resultado de uma chamada para a função `allocate` do filtro de sincronização.  
  
##  <a name="allocator_base___chardealloc"></a>  allocator_base::_Chardealloc  
 Libera armazenamento para a matriz que contém os elementos do tipo `char`.  
  
```
void _Chardealloc(void* ptr, size_type count);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`ptr`|Um ponteiro para o primeiro objeto a ser desalocado do armazenamento.|  
|`count`|O número de objetos a serem desalocados do armazenamento.|  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro é usada pelos contêineres quando são compilados com um compilador que não pode compilar reassociação. Ela implementa `_Chardealloc` para o alocador definido pelo usuário ao chamar a função `deallocate` do filtro de sincronização. O ponteiro PTR deve ter sido retornado anteriormente por uma chamada para `_Charalloc` de um objeto alocador que compara como igual a `*this`, alocando um objeto de matriz dos mesmos tipo e tamanho. `_Chardealloc` nunca gera uma exceção.  
  
##  <a name="allocator_base__address"></a>  allocator_base::address  
 Localiza o endereço de um objeto cujo valor é especificado.  
  
```
pointer address(reference val);

const_pointer address(const_reference val);
```  
  
### <a name="parameters"></a>Parâmetros  
 `val`  
 O valor const ou não const do objeto cujo endereço está sendo pesquisado.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro const ou não const para o objeto localizado, de valor const ou não const, respectivamente.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro é implementada para o alocador definido pelo usuário, retornando `&val`.  
  
##  <a name="allocator_base__allocate"></a>  allocator_base::allocate  
 Aloca um bloco de memória grande o suficiente para armazenar pelo menos um número especificado de elementos.  
  
```
template <class Other>  
pointer allocate(size_type _Nx, const Other* _Hint = 0);

pointer allocate(size_type _Nx);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`_Nx`|O número de elementos na matriz a serem alocados.|  
|`_Hint`|Este parâmetro é ignorado.|  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o objeto alocado.  
  
### <a name="remarks"></a>Comentários  
 A função de membro implementa a alocação de memória para o alocador definido pelo usuário, retornando o resultado de uma chamada para a função `allocate` do filtro de sincronização do tipo Type `*` se `_Nx == 1`, caso contrário, retornando o resultado de uma chamada para `operator new(_Nx * sizeof(Type))` transmitido para o tipo Type `*`.  
  
##  <a name="allocator_base__allocator_base"></a>  allocator_base::allocator_base  
 Constrói um objeto do tipo `allocator_base`.  
  
```
allocator_base();

template <class Other>  
allocator_base(const allocator_base<Other, Sync>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`right`|O objeto alocador a ser copiado.|  
  
### <a name="remarks"></a>Comentários  
 O primeiro construtor constrói uma instância de [allocator_base](../standard-library/allocator-base-class.md). O segundo construtor constrói uma instância `allocator_base` de modo que, para qualquer instância de `allocator_base<Type, _Sync>` `a`, `allocator_base<Type, Sync>(allocator_base<Other, Sync>(a)) == a`.  
  
##  <a name="allocator_base__const_pointer"></a>  allocator_base::const_pointer  
 Um tipo que fornece um ponteiro constante para o tipo de objeto gerenciado pelo alocador.  
  
```
typedef const Type *const_pointer;
```  
  
##  <a name="allocator_base__const_reference"></a>  allocator_base::const_reference  
 Um tipo que fornece uma referência constante ao tipo de objeto gerenciado pelo alocador.  
  
```
typedef const Type& const_reference;
```  
  
##  <a name="allocator_base__construct"></a>  allocator_base::construct  
 Constrói um tipo específico de objeto em um endereço especificado que é inicializado com um valor especificado.  
  
```
void construct(pointer ptr, const Type& val);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`ptr`|Um ponteiro para o local no qual o objeto deve ser construído.|  
|`val`|O valor com o qual o objeto que está sendo construído deve ser inicializado.|  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro é implementada para o alocador definido pelo usuário ao chamar `new((void*)ptr Type(val)`.  
  
##  <a name="allocator_base__deallocate"></a>  allocator_base::deallocate  
 Libera um número especificado de objetos do armazenamento começando em uma posição especificada.  
  
```
void deallocate(pointer ptr, size_type _Nx);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`ptr`|Um ponteiro para o primeiro objeto a ser desalocado do armazenamento.|  
|`_Nx`|O número de objetos a serem desalocados do armazenamento.|  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro é implementada para o alocador definido pelo usuário chamando `deallocate(ptr)` no filtro de sincronização `Sync` se `_Nx == 1`, caso contrário, chamando `operator delete(_Nx * ptr)`.  
  
##  <a name="allocator_base__destroy"></a>  allocator_base::destroy  
 Chama um destruidor de objetos sem desalocar a memória na qual o objeto foi armazenado.  
  
```
void destroy(pointer ptr);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`ptr`|Um ponteiro que designa o endereço do objeto a ser destruído.|  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro é implementada para o alocador definido pelo usuário ao chamar `ptr->~Type()`.  
  
##  <a name="allocator_base__difference_type"></a>  allocator_base::difference_type  
 Um tipo integral com sinal que pode representar a diferença entre os valores de ponteiros para o tipo de objeto gerenciado pelo alocador.  
  
```
typedef std::ptrdiff_t difference_type;
```  
  
##  <a name="allocator_base__max_size"></a>  allocator_base::max_size  
 Retorna o número de elementos do tipo `Type` que podem ser alocados por um objeto da classe allocator antes que a memória livre seja totalmente usada.  
  
```
size_type max_size() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de elementos que podem ser alocados.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro é implementada para o alocador definido pelo usuário, retornando `(size_t)-1 / sizeof(Type)` se `0 < (size_t)-1 / sizeof(Type)`, caso contrário, `1`.  
  
##  <a name="allocator_base__pointer"></a>  allocator_base::pointer  
 Um tipo que fornece um ponteiro para o tipo de objeto gerenciado pelo alocador.  
  
```
typedef Type *pointer;
```  
  
##  <a name="allocator_base__reference"></a>  allocator_base::reference  
 Um tipo que fornece uma referência ao tipo de objeto gerenciado pelo alocador.  
  
```
typedef Type& reference;
```  
  
##  <a name="allocator_base__size_type"></a>  allocator_base::size_type  
 Um tipo integral sem sinal que pode representar o comprimento de qualquer sequência que um objeto da classe de modelo `allocator_base` possa alocar.  
  
```
typedef std::size_t size_type;
```  
  
##  <a name="allocator_base__value_type"></a>  allocator_base::value_type  
 Um tipo que é gerenciado pelo alocador.  
  
```
typedef Type value_type;
```  
  
## <a name="see-also"></a>Consulte também  
 [\<allocators>](../standard-library/allocators-header.md)




