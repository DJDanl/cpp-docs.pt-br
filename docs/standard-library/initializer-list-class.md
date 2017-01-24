---
title: "initializer_list Class | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
ms.assetid: 1f2c0ff4-5636-4f79-b008-e75426e3d2ab
caps.latest.revision: 17
caps.handback.revision: 4
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# initializer_list Class
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Fornece acesso a uma matriz de elementos em que cada membro é do tipo especificado.  
  
## Sintaxe  
  
```cpp  
template<  
    class Type >  
    class initializer_list  
```  
  
#### Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|---------------|  
|`_Elem`|O elemento tipo de dados a ser armazenado na`initializer_list`.|  
|`_First`|O ponteiro para o primeiro elemento do`initializer_list`.|  
|`_Last`|O ponteiro para o último elemento do`initializer_list`.|  
  
## Comentários  
 Um`initializer_list`pode ser construída usando uma lista de inicializadores entre chaves:  
  
```cpp  
initializer_list<int> i1{ 1, 2, 3, 4 };  
```  
  
 O compilador transforma listas de inicializadores entre chaves com elementos homogêneas em um`initializer_list`sempre que a assinatura de função requer um`initializer_list`.  Para obter mais detalhes sobre como usar`initializer_list`consulte[Inicialização uniforme e delegação de construtores](../cpp/uniform-initialization-and-delegating-constructors.md)  
  
### Construtores  
  
|||  
|-|-|  
|[initializer\_list](../Topic/forward_list::forward_list.md)|Constrói um objeto do tipo`initializer_list`.|  
  
### DefsTipo  
  
|||  
|-|-|  
|value\_type|O tipo dos elementos de`initializer_list`.|  
|referência|Um tipo que fornece uma referência a um elemento de`initializer_list`.|  
|const\_reference|Um tipo que fornece uma referência a um elemento constante a`initializer_list`.|  
|size\_type|Um tipo que representa o número de elementos de`initializer_list`.|  
|iterator|Um tipo que fornece um iterador para o`initializer_list`.|  
|const\_iterator|Um tipo que fornece um iterador constante para o`initializer_list`.|  
  
### Funções membro  
  
|||  
|-|-|  
|[begin](../Topic/initializer_list::begin.md)|Retorna um ponteiro para o primeiro elemento em um`initializer_list`.|  
|[end](../Topic/initializer_list::end.md)|Retorna um ponteiro para após o último elemento em um`initializer_list`.|  
|[size](../Topic/initializer_list::size.md)|Retorna o número de elementos no `initializer_list`.|  
  
## Requisitos  
 **Cabeçalho:**\< initializer\_list \>  
  
 **Namespace:** std  
  
## Consulte também  
 [\<forward\_list\>](../standard-library/forward-list.md)