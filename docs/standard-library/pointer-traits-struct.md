---
title: "Struct pointer_traits | Microsoft Docs"
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
  - "memory/std::pointer_traits::element_type"
  - "memory/std::pointer_traits::pointer"
  - "memory/std::pointer_traits"
  - "memory/std::pointer_traits::difference_type"
  - "memory/std::pointer_traits::rebind"
  - "xmemory0/std::pointer_traits::element_type"
  - "xmemory0/std::pointer_traits::pointer"
  - "xmemory0/std::pointer_traits"
  - "xmemory0/std::pointer_traits::difference_type"
  - "xmemory0/std::pointer_traits::rebind"
dev_langs: 
  - "C++"
ms.assetid: 545aecf1-3561-4859-8b34-603c079fe1b3
caps.latest.revision: 13
caps.handback.revision: 2
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Struct pointer_traits
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Fornece informações que são necessárias a um objeto da classe de modelo `allocator_traits` para descrever um alocador com tipo de ponteiro `Ptr`.  
  
## Sintaxe  
  
```cpp  
template<class Ptr>  
    struct pointer_traits;  
```  
  
## Comentários  
 O Ptr pode ser um ponteiro bruto do tipo `Ty *` ou classe com as propriedades a seguir.  
  
```  
template<class Ty, class... Rest>  
    struct Ptr  
    { // describes a pointer type usable by allocators  
    typedef Ptr pointer;  
    typedef T1 element_type; // optional  
    typedef T2 difference_type; // optional  
    template<class Other>  
        using rebind = typename Ptr<Other, Rest...>; // optional  
  
    static pointer pointer_to(element_type& obj); // optional  
    };  
```  
  
> [!WARNING]
>  Quando o padrão do C\+\+ especificar o membro de `rebind` como um modelo de alias, as ferramentas do Visual C\+\+ reassociações como `struct`.  
  
### Typedefs  
  
|Nome|Descrição|  
|----------|---------------|  
|`typedef T2 difference_type`|O tipo `T2` é `Ptr::difference_type` se esse tipo existir, caso contrário `ptrdiff_t`.  Se `Ptr` é um ponteiro bruto, o tipo é `ptrdiff_t`.|  
|`typedef T1 element_type`|O tipo `T1` é `Ptr::element_type` se esse tipo existir, caso contrário `Ty`.  Se `Ptr` é um ponteiro bruto, o tipo é `Ty`.|  
|`typedef Ptr pointer`|O tipo é `Ptr`.|  
  
### Structs  
  
|Nome|Descrição|  
|----------|---------------|  
|`pointer_traits::rebind`|Tentativas de conversão do tipo subjacente do ponteiro para um tipo especificado.|  
  
### Métodos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método pointer\_traits::pointer\_to](../Topic/pointer_traits::pointer_to%20Method.md)|Converte arbitrária uma referência a um objeto da classe `Ptr`.|  
  
## Requisitos  
 **Cabeçalho:** \<memória\>  
  
 **Namespace:** std  
  
## Consulte também  
 [\<memory\>](../standard-library/memory.md)   
 [Classe allocator\_traits](../Topic/allocator_traits%20Class.md)