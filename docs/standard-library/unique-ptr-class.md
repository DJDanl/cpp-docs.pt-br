---
title: "Classe unique_ptr | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "unique_ptr"
  - "std.unique_ptr"
  - "std::unique_ptr"
  - "memory/std::unique_ptr"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe unique_ptr"
ms.assetid: acdf046b-831e-4a4a-83aa-6d4ee467db9a
caps.latest.revision: 22
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe unique_ptr
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Armazena um ponteiro para um objeto de propriedade ou uma matriz.  A matriz de objetos\/pertence a nenhum outro`unique_ptr`.  A matriz de objetos\/é destruída quando o`unique_ptr`é destruído.  
  
## Sintaxe  
  
```  
template< class T, class Del = default_delete<T> >  
    class unique_ptr {  
public:  
    unique_ptr( );  
    unique_ptr( nullptr_t Nptr );  
    explicit unique_ptr( pointer Ptr );  
    unique_ptr( pointer Ptr,  
        typename conditional<is_reference<Del>::value,   
            Del,  
            typename add_reference<const Del>::type>::type Deleter);  
    unique_ptr (pointer Ptr,  
        typename remove_reference<Del>::type&& Deleter);  
    unique_ptr (unique_ptr&& Right);  
    template<class T2, Class Del2> unique_ptr( unique_ptr<T2, Del2>&& Right );  
    unique_ptr( const unique_ptr& Right    ) = delete;  
    unique_ptr& operator=(const unique_ptr& Right     ) = delete;  
};  
  
```  
  
```  
//Specialization for arrays:  
template <class T, class D> class unique_ptr<T[], D>   
{   public:       
     typedef pointer;  
     typedef T element_type;  
     typedef D deleter_type;  
  
     constexpr unique_ptr() noexcept;  
     template <class U> explicit unique_ptr(U p) noexcept;  
     template <class U> unique_ptr(U p, see below d) noexcept;  
     template <class U> unique_ptr(U p, see below d) noexcept;  
     unique_ptr(unique_ptr&& u) noexcept;  
     constexpr unique_ptr(nullptr_t) noexcept : unique_ptr() { }  
     template <class U, class E>  
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
     template <class U> void reset(U p) noexcept = delete;  
     void swap(unique_ptr& u) noexcept;  
  
    // disable copy from lvalue  
     unique_ptr(const unique_ptr&) = delete;  
     unique_ptr& operator=(const unique_ptr&) = delete;  
   };  
 }  
  
```  
  
#### Parâmetros  
 `Right`  
 Um `unique_ptr`.  
  
 `Nptr`  
 Um `rvalue` do tipo `std::nullptr_t`.  
  
 `Ptr`  
 Um `pointer`.  
  
 `Deleter`  
 Uma função `deleter` que é associada a `unique_ptr`.  
  
## Exceções  
 Nenhuma exceção é gerada por `unique_ptr`.  
  
## Comentários  
 A classe `unique_ptr` substitui `auto_ptr` e pode ser usada como um elemento dos contêineres da STL.  
  
 Use a função auxiliar [make\_unique](../Topic/make_unique.md) para criar de modo eficiente novas instâncias de `unique_ptr`.  
  
 `unique_ptr` gerencia exclusivamente um recurso.  Cada objeto `unique_ptr` armazena um ponteiro para o objeto que possui ou armazena um ponteiro nulo.  Um recurso pode pertencer a não mais de um`unique_ptr`do objeto;  Quando uma`unique_ptr`objeto que possui um recurso específico é destruído, o recurso é liberado.  Um`unique_ptr`objeto pode ser movido, mas não copiado;  Para obter mais informações, consulte[Declarador de referência Rvalue: &&](../cpp/rvalue-reference-declarator-amp-amp.md).  
  
 O recurso é liberado chamando um objeto `deleter` armazenado do tipo `Del` que sabe como os recursos são alocados para um determinado `unique_ptr`.  O `deleter` `default_delete``<T>` padrão supõe que o recurso apontado por `_Ptr` é alocado com `new` e que ele pode ser liberado chamando `delete _``Ptr`.  \(Uma especialização parcial `unique_ptr<T[]>`gerencia objetos de matriz alocados com `new[]` e tem o `deleter` `default_delete<T[]>` padrão, especializado para chamar delete\[\] `_Ptr`.\)  
  
 O ponteiro armazenado para um recurso possuído, `stored_ptr` tem o tipo `pointer`.  Ele será `Del::pointer` se definido, e `T *` , se não.  O objeto `deleter` armazenado `stored_deleter` não ocupará nenhum espaço no objeto se `deleter` não tiver estado.  Observe que `Del` pode ser um tipo de referência.  
  
## Membros  
  
### Construtores  
  
|||  
|-|-|  
|[unique\_ptr::unique\_ptr](../Topic/unique_ptr::unique_ptr.md)|Há sete construtores para `unique_ptr`.|  
  
### DefsTipo  
  
|||  
|-|-|  
|[deleter\_type](../Topic/deleter_type.md)|Um sinônimo para o parâmetro de modelo `Del`.|  
|[element\_type](../Topic/element_type.md)|Um sinônimo para o parâmetro de modelo `T``.`|  
|[ponteiro](../Topic/pointer.md)|Um sinônimo para `Del::pointer` se definido, caso contrário `T *`.|  
  
### Funções membro  
  
|||  
|-|-|  
|[unique\_ptr::get](../Topic/unique_ptr::get.md)|Retorna `stored_ptr`.|  
|[unique\_ptr::get\_deleter](../Topic/unique_ptr::get_deleter.md)|Retorna uma referência para `stored_deleter`.|  
|[unique\_ptr::release](../Topic/unique_ptr::release.md)|Armazena `pointer()` em `stored_ptr` e retorna seu conteúdo anterior.|  
|[unique\_ptr::reset](../Topic/unique_ptr::reset.md)|Libera o recurso possuído atualmente e aceita um novo recurso.|  
|[unique\_ptr::swap](../Topic/unique_ptr::swap.md)|Troca o recurso e `deleter` pelo `unique_ptr` fornecido.|  
  
### Operadores  
  
|||  
|-|-|  
|`operator bool`|O operador retorna um valor de um tipo que pode ser convertido em `bool`.  O resultado da conversão em `bool` é `true` quando `get() != pointer()`, caso contrário `false`.|  
|`operator->`|A função membro retorna `stored_ptr``.`|  
|`operator*`|A função membro retorna\*`stored_ptr``.`|  
|[unique\_ptr operator\=](../Topic/unique_ptr%20operator=.md)|Atribui o valor de um `unique_ptr` \(ou um `pointer-type`\) para o `unique_ptr` atual.|  
  
## Requisitos  
 **Cabeçalho:**\< memória \>  
  
 **Namespace:** std  
  
## Consulte também  
 [\<memory\>](../standard-library/memory.md)