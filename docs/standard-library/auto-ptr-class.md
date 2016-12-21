---
title: "Classe auto_ptr | Microsoft Docs"
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
  - "std::auto_ptr"
  - "std.auto_ptr"
  - "auto_ptr"
  - "memory/std::auto_ptr"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe auto_ptr"
ms.assetid: 7f9108b6-9eb3-4634-b615-cf7aa814f23b
caps.latest.revision: 26
caps.handback.revision: 17
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe auto_ptr
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Encapsula um ponteiro inteligente ao redor de um recurso que garante que o recurso é destruído automaticamente ao controle deixa um bloco.  
  
 Mais capacitado`unique_ptr`classe substitui`auto_ptr`.  Para obter mais informações, consulte[Classe unique\_ptr](../standard-library/unique-ptr-class.md).  
  
 Para obter mais informações sobre`throw()`e manipulação de exceção, consulte[Especificações de exceção \(lançar\)](../cpp/exception-specifications-throw-cpp.md).  
  
## Sintaxe  
  
```  
template<class Type>  
    class auto_ptr {  
public:  
    typedef Type element_type;  
    explicit auto_ptr(Type *_Ptr = 0) throw();  
    auto_ptr(auto_ptr<Type>& _Right) throw();  
    template<class Other>  
        operator auto_ptr<Other>() throw();  
    template<class Other>  
        auto_ptr<Type>& operator=(auto_ptr<Other>& _Right) throw();  
    template<class Other>  
        auto_ptr(auto_ptr<Other>& _Right);  
    auto_ptr<Type>& operator=(auto_ptr<Type>& _Right);  
    ~auto_ptr();  
    Type& operator*() const throw();  
    Type *operator->()const throw();  
    Type *get() const throw();  
    Type *release()throw();  
    void reset(Type *_Ptr = 0);  
};  
```  
  
#### Parâmetros  
 `_Right`  
 O`auto_ptr`da qual obter um recurso existente.  
  
 `_Ptr`  
 O ponteiro especificado para substituir o ponteiro armazenado.  
  
## Comentários  
 A classe de modelo descreve um ponteiro inteligente, chamado um`auto_ptr,`para um objeto alocado.  O ponteiro deve ser nulo ou designar um objeto alocado pelo`new`.  O`auto_ptr`transfere a propriedade se o valor armazenado é atribuído a outro objeto.  \(Ele substitui o valor armazenado após uma transferência com um ponteiro nulo.\) O destruidor de`auto_ptr<Type>`exclui o objeto alocado.  O`auto_ptr<Type>`garante que um objeto alocado é excluído automaticamente quando o controle sai de um bloco, mesmo por meio de uma exceção lançada.  Você não deve criar dois`auto_ptr<Type>`objetos que possuem o mesmo objeto.  
  
 Você pode passar um`auto_ptr<Type>`objeto por valor como um argumento para uma chamada de função.  Um`auto_ptr`não pode ser um elemento de qualquer contêiner de biblioteca padrão.  Confiável não é possível gerenciar uma sequência de`auto_ptr<Type>`objetos com um contêiner Standard Template Library.  
  
## Membros  
  
### Construtores  
  
|||  
|-|-|  
|[auto\_ptr](../Topic/auto_ptr::auto_ptr.md)|O construtor para objetos do tipo `auto_ptr`.|  
  
### DefsTipo  
  
|||  
|-|-|  
|[element\_type](../Topic/auto_ptr::element_type.md)|O tipo é um sinônimo para o parâmetro de modelo`Type`.|  
  
### Funções membro  
  
|||  
|-|-|  
|[obter](../Topic/auto_ptr::get.md)|A função de membro retorna o ponteiro armazenado`myptr`.|  
|[versão](../Topic/auto_ptr::release.md)|O membro substitui o ponteiro armazenado`myptr`com um ponteiro nulo e retorna o ponteiro armazenado anteriormente.|  
|[redefinir](../Topic/auto_ptr::reset.md)|A função de membro avalia a expressão`delete myptr`mas somente se o valor do ponteiro armazenado`myptr`muda como resultado da chamada de função.  Ele substitui o ponteiro armazenado com`ptr`.|  
  
### Operadores  
  
|||  
|-|-|  
|[operator\=](../Topic/auto_ptr::operator=.md)|Um operador de atribuição que transfere a propriedade de uma`auto_ptr`objeto para outro.|  
|[operator\*](../Topic/auto_ptr::operator*.md)|O operador de desreferenciamento para objetos do tipo`auto_ptr`.|  
|[operator\-\>](../Topic/auto_ptr::operator-%3E.md)|O operador para permitir o acesso de membro.|  
|[operador auto\_ptr \< outros \>](../Topic/auto_ptr::operator%20auto_ptr%3COther%3E.md)|Converte uma espécie de`auto_ptr`em outro tipo de`auto_ptr`.|  
|[operador auto\_ptr\_ref \< outros \>](../Topic/auto_ptr::operator%20auto_ptr_ref%3COther%3E.md)|Converte a partir de um`auto_ptr`para um`auto_ptr_ref`.|  
  
## Requisitos  
 **Cabeçalho:** \< memória \>  
  
 **Namespace:** std  
  
## Consulte também  
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Classe unique\_ptr](../standard-library/unique-ptr-class.md)