---
title: "Classe allocator_traits | Microsoft Docs"
ms.custom: ""
ms.date: "11/04/2016"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "memory/std::allocator_traits"
  - "memory/std::allocator_traits::propagate_on_container_move_assignment"
  - "memory/std::allocator_traits::const_pointer"
  - "memory/std::allocator_traits::propagate_on_container_swap"
  - "memory/std::allocator_traits::propagate_on_container_copy_assignment"
  - "memory/std::allocator_traits::difference_type"
  - "memory/std::allocator_traits::allocator_type"
  - "memory/std::allocator_traits::value_type"
  - "memory/std::allocator_traits::pointer"
  - "memory/std::allocator_traits::size_type"
  - "memory/std::allocator_traits::const_void_pointer"
  - "memory/std::allocator_traits::void_pointer"
dev_langs: 
  - "C++"
ms.assetid: 612974b8-b5d4-4668-82fb-824bff6821d6
caps.latest.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
translation.priority.ht: 
  - "cs-cz"
  - "de-de"
  - "es-es"
  - "fr-fr"
  - "it-it"
  - "ja-jp"
  - "ko-kr"
  - "pl-pl"
  - "pt-br"
  - "ru-ru"
  - "tr-tr"
  - "zh-cn"
  - "zh-tw"
---
# <a name="allocatortraits-class"></a>Classe allocator_traits
A classe de modelo descreve um objeto que complementa um *tipo de alocador*. Um tipo de alocador é qualquer tipo que descreve um objeto alocador que é usado para gerenciar o armazenamento alocado. Especificamente, para qualquer tipo de alocador `Alloc`, você pode usar `allocator_traits<Alloc>` para determinar todas as informações necessárias para um contêiner habilitado para alocador. Para obter mais informações, consulte a [Classe allocator](../standard-library/allocator-class.md) padrão.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
template <class Alloc>
class allocator_traits;
```  
  
### <a name="typedefs"></a>Typedefs  
  
|Nome|Descrição|  
|----------|-----------------|  
|`allocator_traits::allocator_type`|Esse tipo é um sinônimo do parâmetro de modelo `Alloc`.|  
|`allocator_traits::const_pointer`|Esse tipo será `Alloc::const_pointer`, se aquele tipo for bem formado, caso contrário, será `pointer_traits<pointer>::rebind<const value_type>`.|  
|`allocator_traits::const_void_pointer`|Esse tipo será `Alloc::const_void_pointer`, se aquele tipo for bem formado, caso contrário, será `pointer_traits<pointer>::rebind<const void>`.|  
|`allocator_traits::difference_type`|Esse tipo será `Alloc::difference_type`, se aquele tipo for bem formado, caso contrário, será `pointer_traits<pointer>::difference_type`.|  
|`allocator_traits::pointer`|Esse tipo será `Alloc::pointer`, se aquele tipo for bem formado, caso contrário, será `value_type *`.|  
|`allocator_traits::propagate_on_container_copy_assignment`|Esse tipo será `Alloc::propagate_on_container_copy_assignment`, se aquele tipo for bem formado, caso contrário, será `false_type`.|  
|`allocator_traits::propagate_on_container_move_assignment`|Esse tipo será `Alloc::propagate_on_container_move_assignment`, se aquele tipo for bem formado, caso contrário, será `false_type`. Se o tipo for verdadeiro, um contêiner habilitado para alocador copiará seu alocador armazenado em uma atribuição de movimentação.|  
|`allocator_traits::propagate_on_container_swap`|Esse tipo será `Alloc::propagate_on_container_swap`, se aquele tipo for bem formado, caso contrário, será `false_type`. Se o tipo for verdadeiro, um contêiner habilitado para alocador trocará seu alocador armazenado em uma troca.|  
|`allocator_traits::size_type`|Esse tipo será `Alloc::size_type`, se aquele tipo for bem formado, caso contrário, será `make_unsigned<difference_type>::type`.|  
|`allocator_traits::value_type`|Esse tipo é um sinônimo de `Alloc::value_type`.|  
|`allocator_traits::void_pointer`|Esse tipo será `Alloc::void_pointer`, se aquele tipo for bem formado, caso contrário, será `pointer_traits<pointer>::rebind<void>`.|  
  
### <a name="static-methods"></a>Métodos estáticos  
 Os seguintes métodos estáticos chamam o método correspondente em um parâmetro alocador determinado.  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método allocator_traits::allocate](#allocator_traits__allocate_method)|Método estático que aloca memória usando o parâmetro alocador determinado.|  
|[Método allocator_traits::construct](#allocator_traits__construct_method)|Método estático que usa um alocador especificado para construir um objeto.|  
|[Método allocator_traits::deallocate](#allocator_traits__deallocate_method)|Método estático que usa um alocador especificado para desalocar um número especificado de objetos.|  
|[Método allocator_traits::destroy](#allocator_traits__destroy_method)|Método estático que usa um alocador especificado para chamar o destruidor em um objeto sem desalocar sua memória.|  
|[Método allocator_traits::max_size](#allocator_traits__max_size_method)|Método estático que usa um alocador especificado para determinar o número máximo de objetos que podem ser alocados.|  
|[Método allocator_traits::select_on_container_copy_construction](#allocator_traits__select_on_container_copy_construction_method)|Método estático que chama `select_on_container_copy_construction` no alocador especificado.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<memory>  
  
 **Namespace:** std  
  
##  <a name="a-nameallocatortraitsallocatemethoda--allocatortraitsallocate-method"></a><a name="allocator_traits__allocate_method"></a>  Método allocator_traits::allocate  
 Método estático que aloca memória usando o parâmetro alocador determinado.  
  
```cpp  
static pointer allocate(Alloc& al, size_type count);

static pointer allocate(Alloc& al, size_type count,
    typename allocator_traits<void>::const_pointer* hint);
```  
  
### <a name="parameters"></a>Parâmetros  
 `al`  
 Um objeto alocador.  
  
 `count`  
 O número de elementos a serem alocados.  
  
 `hint`  
 Um `const_pointer` que pode ajudar o objeto alocador a atender à solicitação de armazenamento, localizando o endereço de um objeto alocado antes da solicitação. Um ponteiro nulo é tratado como nenhuma dica.  
  
### <a name="return-value"></a>Valor de retorno  
 Cada método retorna um ponteiro para o objeto alocado.  
  
 O primeiro método estático retorna `al.allocate(count)`.  
  
 O segundo método retornará `al.allocate(count, hint)`, se essa expressão for bem formada, caso contrário, retornará `al.allocate(count)`.  
  
##  <a name="a-nameallocatortraitsconstructmethoda--allocatortraitsconstruct-method"></a><a name="allocator_traits__construct_method"></a>  Método allocator_traits::construct  
 Método estático que usa um alocador especificado para construir um objeto.  
  
```cpp  
template <class Uty, class Types>
static void construct(Alloc& al, Uty* ptr, Types&&... args);
```  
  
### <a name="parameters"></a>Parâmetros  
 `al`  
 Um objeto alocador.  
  
 `ptr`  
 Um ponteiro para o local no qual o objeto deve ser construído.  
  
 `args`  
 Uma lista de argumentos que é passada ao construtor de objetos.  
  
### <a name="remarks"></a>Comentários  
 A função de membro estática chamará `al.construct(ptr, args...)`, se essa expressão for bem formada, caso contrário, será avaliada como `::new (static_cast<void *>(ptr)) Uty(std::forward<Types>(args)...)`.  
  
##  <a name="a-nameallocatortraitsdeallocatemethoda--allocatortraitsdeallocate-method"></a><a name="allocator_traits__deallocate_method"></a>  Método allocator_traits::deallocate  
 Método estático que usa um alocador especificado para desalocar um número especificado de objetos.  
  
```cpp  
static void deallocate(Alloc al,
    pointer ptr,
    size_type count);
```  
  
### <a name="parameters"></a>Parâmetros  
 `al`  
 Um objeto alocador.  
  
 `ptr`  
 Um ponteiro para o local inicial dos objetos a serem desalocados.  
  
 `count`  
 O número de objetos a serem desalocados.  
  
### <a name="remarks"></a>Comentários  
 Esse método chama `al.deallocate(ptr, count)`.  
  
 Esse método não gera nada.  
  
##  <a name="a-nameallocatortraitsdestroymethoda--allocatortraitsdestroy-method"></a><a name="allocator_traits__destroy_method"></a>  Método allocator_traits::destroy  
 Método estático que usa um alocador especificado para chamar o destruidor em um objeto sem desalocar sua memória.  
  
```cpp  
template <class Uty>
static void destroy(Alloc& al, Uty* ptr);
```  
  
### <a name="parameters"></a>Parâmetros  
 `al`  
 Um objeto alocador.  
  
 `ptr`  
 Um ponteiro para o local do objeto.  
  
### <a name="remarks"></a>Comentários  
 Esse método chamará `al.destroy(ptr)`, se essa expressão for bem formada, caso contrário, será avaliado como `ptr->~Uty()`.  
  
##  <a name="a-nameallocatortraitsmaxsizemethoda--allocatortraitsmaxsize-method"></a><a name="allocator_traits__max_size_method"></a>  Método allocator_traits::max_size  
 Método estático que usa um alocador especificado para determinar o número máximo de objetos que podem ser alocados.  
  
```cpp  
static size_type max_size(const Alloc& al);
```  
  
### <a name="parameters"></a>Parâmetros  
 `al`  
 Um objeto alocador.  
  
### <a name="remarks"></a>Comentários  
 Esse método retornará `al.max_size()`, se essa expressão for bem formada, caso contrário, retornará `numeric_limits<size_type>::max()`.  
  
##  <a name="a-nameallocatortraitsselectoncontainercopyconstructionmethoda--allocatortraitsselectoncontainercopyconstruction-method"></a><a name="allocator_traits__select_on_container_copy_construction_method"></a>  Método allocator_traits::select_on_container_copy_construction  
 Método estático que chama `select_on_container_copy_construction` no alocador especificado.  
  
```cpp  
static Alloc select_on_container_copy_construction(const Alloc& al);
```  
  
### <a name="parameters"></a>Parâmetros  
 `al`  
 Um objeto alocador.  
  
### <a name="return-value"></a>Valor de retorno  
 Esse método retornará `al.select_on_container_copy_construction()`, se aquele tipo for bem formado, caso contrário, retornará `al`.  
  
### <a name="remarks"></a>Comentários  
 Esse método é usado para especificar um alocador quando o contêiner associado é construído por cópia.  
  
## <a name="see-also"></a>Consulte também  
 [\<memory>](../standard-library/memory.md)   
 [Struct pointer_traits](../standard-library/pointer-traits-struct.md)   
 [Classe scoped_allocator_adaptor](../standard-library/scoped-allocator-adaptor-class.md)
