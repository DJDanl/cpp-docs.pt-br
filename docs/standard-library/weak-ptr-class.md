---
title: "Classe weak_ptr | Microsoft Docs"
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
  - "std.tr1.weak_ptr"
  - "tr1.weak_ptr"
  - "weak_ptr"
  - "tr1::weak_ptr"
  - "std::tr1::weak_ptr"
  - "memory/std::tr1::weak_ptr"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe weak_ptr"
  - "Classe weak_ptr [TR1]"
ms.assetid: 2db4afb2-c7be-46fc-9c20-34ec2f8cc7c2
caps.latest.revision: 22
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe weak_ptr
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Encapsula um ponteiro vinculado de modo fraco.  
  
## Sintaxe  
  
```  
template<class Ty> class weak_ptr {  
public:  
    typedef Ty element_type;  
  
    weak_ptr();  
    weak_ptr(const weak_ptr&);  
    template<class Other>  
        weak_ptr(const weak_ptr<Other>&);  
    template<class Other>  
        weak_ptr(const shared_ptr<Other>&);  
  
    weak_ptr& operator=(const weak_ptr&);  
    template<class Other>  
        weak_ptr& operator=(const weak_ptr<Other>&);  
    template<class Other>  
        weak_ptr& operator=(shared_ptr<Other>&);  
  
    void swap(weak_ptr&);  
    void reset();  
  
    long use_count() const;  
    bool expired() const;  
    shared_ptr<Ty> lock() const;  
    };  
```  
  
#### Parâmetros  
 `Ty`  
 O tipo controlado pelo ponteiro fraco.  
  
## Comentários  
 A classe de modelo descreve um objeto que aponta para um recurso que é gerenciado por um ou mais[Classe shared\_ptr](../standard-library/shared-ptr-class.md)objetos.  O`weak_ptr`objetos que apontam para um recurso não afetam a contagem de referência do recurso.  Assim, quando a última`shared_ptr`objeto que gerencia esse recurso é destruído o recurso será liberado, mesmo que haja`weak_ptr`objetos apontando para esse recurso.  Isso é essencial para evitar ciclos em estruturas de dados.  
  
 Um`weak_ptr`objeto aponta para um recurso se ele foi construído a partir um`shared_ptr`objeto que possui esse recurso, se ele foi construído a partir um`weak_ptr`objeto que aponta para esse recurso, ou se esse recurso foi atribuído a ele com[weak\_ptr::operator\=](../Topic/weak_ptr::operator=.md).  Um`weak_ptr`objeto não fornecem acesso direto ao recurso que ele aponta.  Código que precisa usar o recurso faz então com uma`shared_ptr`objeto que possui esse recurso criado chamando a função de membro[weak\_ptr::lock](../Topic/weak_ptr::lock.md).  Um`weak_ptr`objeto expirou quando o recurso que ele aponta para tiver sido liberado porque todos os`shared_ptr`objetos que são proprietários do recurso tiverem sido destruídos.  Chamar`lock`em uma`weak_ptr`objeto expirou cria um objeto shared\_ptr vazio.  
  
 Um objeto weak\_ptr vazio não aponta para todos os recursos e não tem nenhum bloco de controle.  A função de membro`lock`retorna um objeto shared\_ptr vazio.  
  
 Um ciclo ocorre quando dois ou mais recursos controlados por`shared_ptr`objetos mantiverem mutuamente referenciando`shared_ptr`objetos.  Por exemplo, uma lista vinculada circular com três elementos tem um nó principal`N0`; esse nó contém um`shared_ptr`objeto que possui o próximo nó,`N1`; esse nó contém um`shared_ptr`objeto que possui o próximo nó,`N2`; esse nó, por sua vez, contém um`shared_ptr`objeto que possui o nó principal,`N0`fechando o ciclo.  Nessa situação, nenhuma das contagens de referência nunca se tornará zero e os nós no ciclo não serão liberados.  Para eliminar o ciclo, o último nó`N2`deve conter um`weak_ptr`objeto apontando para`N0`em vez de um`shared_ptr`objeto.  Uma vez que o`weak_ptr`não possui o objeto`N0`não afeta`N0`da contagem de referência, e quando a última referência do programa para o nó principal é destruída os nós na lista também serão destruídos.  
  
## Membros  
  
### Construtores  
  
|||  
|-|-|  
|[weak\_ptr::weak\_ptr](../Topic/weak_ptr::weak_ptr.md)|Constrói um `weak_ptr`.|  
  
### Métodos  
  
|||  
|-|-|  
|[weak\_ptr::element\_type](../Topic/weak_ptr::element_type.md)|O tipo do elemento.|  
|[weak\_ptr::expired](../Topic/weak_ptr::expired.md)|Testa se a propriedade expirou.|  
|[weak\_ptr::lock](../Topic/weak_ptr::lock.md)|Obtém a propriedade exclusiva de um recurso.|  
|[weak\_ptr::owner\_before](../Topic/weak_ptr::owner_before.md)|Retorna`true`se esse`weak_ptr`ordenados antes \(ou inferior\) o ponteiro fornecido.|  
|[weak\_ptr::reset](../Topic/weak_ptr::reset.md)|Recursos de propriedade de versões.|  
|[weak\_ptr::swap](../Topic/weak_ptr::swap.md)|Troca dois`weak_ptr`objetos.|  
|[weak\_ptr::use\_count](../Topic/weak_ptr::use_count.md)|Número de contagens de designado`shared_ptr`objetos.|  
  
### Operadores  
  
|||  
|-|-|  
|[weak\_ptr::operator\=](../Topic/weak_ptr::operator=.md)|Substitui o recurso de propriedade.|  
  
## Requisitos  
 **Cabeçalho:** \<memory\>  
  
 **Namespace:** std  
  
## Consulte também  
 [Classe shared\_ptr](../standard-library/shared-ptr-class.md)