---
title: "Classe shared_ptr | Microsoft Docs"
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
  - "shared_ptr"
  - "tr1::shared_ptr"
  - "memory/std::tr1::shared_ptr"
  - "std::tr1::shared_ptr"
  - "std.tr1.shared_ptr"
  - "tr1.shared_ptr"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe shared_ptr"
  - "Classe shared_ptr [TR1]"
ms.assetid: 1469fc51-c658-43f1-886c-f4530dd84860
caps.latest.revision: 29
caps.handback.revision: 20
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe shared_ptr
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Encapsula um ponteiro inteligente de contagem de referência em torno de um objeto alocado dinamicamente.  
  
## Sintaxe  
  
```  
template<class Ty>  
   class shared_ptr {  
public:  
    typedef Ty element_type;  
  
    shared_ptr();  
    shared_ptr(nullptr_t);   
    shared_ptr(const shared_ptr& sp);  
    shared_ptr(shared_ptr&& sp);  
    template<class Other>  
        explicit shared_ptr(Other * ptr);  
    template<class Other, class D>  
        shared_ptr(Other * ptr, D dtor);  
    template<class D>  
        shared_ptr(nullptr_t, D dtor);  
    template<class Other, class D, class A>  
        shared_ptr(Other *ptr, D dtor, A alloc);  
    template<class D, class A>  
        shared_ptr(nullptr_t, D dtor, A alloc);  
    template<class Other>  
        shared_ptr(const shared_ptr<Other>& sp);  
    template<class Other>  
        shared_ptr(const shared_ptr<Other>&& sp);  
    template<class Other>  
        explicit shared_ptr(const weak_ptr<Other>& wp);  
    template<class Other>  
        shared_ptr(auto_ptr<Other>& ap);  
    template<class Other, class D>  
        shared_ptr(unique_ptr<Other, D>&& up);  
    template<class Other>  
        shared_ptr(const shared_ptr<Other>& sp, Ty *ptr);  
    ~shared_ptr();  
    shared_ptr& operator=(const shared_ptr& sp);  
    template<class Other>   
        shared_ptr& operator=(const shared_ptr<Other>& sp);  
    shared_ptr& operator=(shared_ptr&& sp);  
    template<class Other>   
        shared_ptr& operator=(shared_ptr<Other>&& sp);  
    template<class Other>   
        shared_ptr& operator=(auto_ptr< Other >&& ap);  
    template <class Other, class D>   
        shared_ptr& operator=(const unique_ptr< Other, D>& up) = delete;  
    template <class Other, class D>  
        shared_ptr& operator=(unique_ptr<Other, D>&& up);  
    void swap(shared_ptr& sp);  
    void reset();  
    template<class Other>  
        void reset(Other *ptr);  
    template<class Other, class D>  
        void reset(Other *ptr, D dtor);  
    template<class Other, class D, class A>  
        void reset(Other *ptr, D dtor, A alloc);  
    Ty *get() const;  
    Ty& operator*() const;  
    Ty *operator->() const;  
    long use_count() const;  
    bool unique() const;  
    operator bool() const;  
  
    template<class Other>  
        bool owner_before(shared_ptr<Other> const& ptr) const;  
    template<class Other>  
        bool owner_before(weak_ptr<Other> const& ptr) const;  
    template<class D, class Ty>   
        D* get_deleter(shared_ptr<Ty> const& ptr);  
};  
  
```  
  
#### Parâmetros  
 `Ty`  
 O tipo controlado pelo ponteiro compartilhado.  
  
 `Other`  
 O tipo controlado pelo ponteiro de argumento.  
  
 `ptr`  
 O ponteiro para copiar.  
  
 `D`  
 O tipo do deleter.  
  
 `A`  
 O tipo do alocador.  
  
 `dtor`  
 Deleter.  
  
 `alloc`  
 O alocador.  
  
 `sp`  
 O ponteiro inteligente para copiar ou mover.  
  
 `wp`  
 O ponteiro fraco para copiar ou mover.  
  
 `ap`  
 O ponteiro automaticamente para copiar ou mover.  
  
 `up`  
 O ponteiro exclusivo para mover.  
  
## Comentários  
 A classe de modelo descreve um objeto que usa gerenciar recursos de contagem de referência.  Um`shared_ptr`efetivamente o objeto contém um ponteiro para o recurso que possui ou contém um ponteiro nulo.  Um recurso pode pertencer a mais de um`shared_ptr`do objeto; quando o último`shared_ptr`objeto que possui um recurso específico é destruído, o recurso é liberado.  
  
 Um`shared_ptr`pára possui um recurso quando é reatribuído ou redefinir.  
  
 O argumento de modelo`Ty`pode ser um tipo incompleto, exceto conforme observado para determinadas funções de membro.  
  
 Quando uma`shared_ptr<Ty>`objeto é construído a partir de um ponteiro de recurso do tipo`G*`ou um`shared_ptr<G>`o tipo de ponteiro`G*`deve ser conversível para`Ty*`.  Se não for, o código não será compilado.  Por exemplo:  
  
```cpp  
class F {};  
class G : public F {};  
```  
  
```cpp  
  
#include <memory>  
  
using namespace std;  
  
shared_ptr<G> sp0(new G);   // okay, template parameter G and argument G*  
shared_ptr<G> sp1(sp0);     // okay, template parameter G and argument shared_ptr<G>  
shared_ptr<F> sp2(new G);   // okay, G* convertible to F*  
shared_ptr<F> sp3(sp0);     // okay, template parameter F and argument shared_ptr<G>  
shared_ptr<F> sp4(sp2);     // okay, template parameter F and argument shared_ptr<F>  
shared_ptr<int> sp5(new G); // error, G* not convertible to int*  
shared_ptr<int> sp6(sp2);   // error, template parameter int and argument shared_ptr<F>  
```  
  
 Um`shared_ptr`objeto possui um recurso:  
  
-   Se ele foi construído com um ponteiro para esse recurso  
  
-   Se ele foi construído a partir um`shared_ptr`objeto que possui esse recurso  
  
-   Se ele foi construído a partir um[Classe weak\_ptr](../standard-library/weak-ptr-class.md)objeto que aponta para esse recurso, ou  
  
-   Se a propriedade do recurso foi atribuída a ele, com[shared\_ptr::operator\=](../Topic/shared_ptr::operator=.md)ou chamando a função de membro[shared\_ptr::reset](../Topic/shared_ptr::reset.md).  
  
 O`shared_ptr`objetos que possuem um recurso compartilham um bloco de controle.  O bloco de controle contém:  
  
-   o número de`shared_ptr`objetos que são proprietários do recurso  
  
-   o número de`weak_ptr`objetos que apontam para o recurso  
  
-   deleter para esse recurso se ele tiver um,  
  
-   o alocador personalizado para o bloco de controle se ele tiver um.  
  
 Um`shared_ptr`possui um bloco de controle de objeto que é inicializado usando um ponteiro nulo e não está vazio.  Após um`shared_ptr`objeto libera um recurso, ele não possui esse recurso.  Após um`weak_ptr`objeto libera um recurso, ele não aponta para esse recurso.  
  
 Quando o número de`shared_ptr`objetos que o próprio um recurso se torna zero, o recurso for liberado, excluindo\-o ou passando o seu endereço para um deleter, dependendo de como a propriedade do recurso foi originalmente criada.  Quando o número de`shared_ptr`objetos que possuem um recurso é zero e o número de`weak_ptr`objetos que apontam para que o recurso é zero, o bloco de controle é liberado, usando o alocador personalizado para o bloco de controle se ele tiver um.  
  
 Vazia`shared_ptr`objeto não possui todos os recursos e não tem nenhum bloco de controle.  
  
 Um deleter é um objeto de função que tem uma função de membro`operator()`.  Seu tipo deve ser a cópia pode ser construída e seu construtor e destruidor não devem lançar exceções.  Ele aceita um parâmetro, o objeto a ser excluído.  
  
 Algumas funções usam uma lista de argumentos que define propriedades de resultante`shared_ptr<Ty>`ou`weak_ptr<Ty>`objeto.  Você pode especificar uma lista de argumentos tal de várias maneiras:  
  
 nenhum argumento, o objeto resultante é vazia`shared_ptr`objeto ou vazia`weak_ptr`objeto.  
  
 `ptr`– um ponteiro de tipo`Other*`para o recurso a ser gerenciado.  `Ty`deve ser um tipo completo.  Se a função falhar \(porque o bloco de controle não pode ser alocado\) ele avalia a expressão`delete ptr`.  
  
 `ptr, dtor`– um ponteiro de tipo`Other*`ao recurso a ser gerenciado e um deleter para esse recurso.  Se a função falhar \(porque não é possível alocar o bloco de controle\), ele chama`dtor(ptr)`que deve ser bem definido.  
  
 `ptr, dtor, alloc`– um ponteiro de tipo`Other*`para os recursos a serem gerenciados, um deleter para esse recurso e um alocador para gerenciar qualquer armazenamento que deve ser alocado e liberado.  Se a função falhar \(porque o bloco de controle não pode ser alocado\) chama`dtor(ptr)`que deve ser bem definido.  
  
 `sp`– um`shared_ptr<Other>`objeto que possui o recurso a ser gerenciado.  
  
 `wp`– um`weak_ptr<Other>`objeto que aponta para o recurso a ser gerenciado.  
  
 `ap`– um`auto_ptr<Other>`objeto que contém um ponteiro para o recurso a ser gerenciado.  Se a função obtiver êxito\-chamadas`ap.release()`; caso contrário, ela deixa`ap`inalterado.  
  
 Em todos os casos, o tipo de ponteiro`Other*`deve ser conversível para`Ty*`.  
  
## Segurança de threads  
 Vários threads podem ler e gravar diferentes`shared_ptr`objetos ao mesmo tempo, mesmo quando os objetos são cópias que compartilham a propriedade.  
  
## Membros  
  
### Construtores  
  
|||  
|-|-|  
|[shared\_ptr::shared\_ptr](../Topic/shared_ptr::shared_ptr.md)|Constrói um `shared_ptr`.|  
|[shared\_ptr::~shared\_ptr](../Topic/shared_ptr::~shared_ptr.md)|Destrói um`shared_ptr`.|  
  
### Métodos  
  
|||  
|-|-|  
|[shared\_ptr::element\_type](../Topic/shared_ptr::element_type.md)|O tipo de um elemento.|  
|[shared\_ptr::get](../Topic/shared_ptr::get.md)|Obtém o endereço do recurso possuído.|  
|[shared\_ptr::owner\_before](../Topic/shared_ptr::owner_before.md)|Retorna VERDADEIRO se esta`shared_ptr`ordenados antes \(ou inferior\) o ponteiro fornecido.|  
|[shared\_ptr::reset](../Topic/shared_ptr::reset.md)|Substitua o recurso possuído.|  
|[shared\_ptr::swap](../Topic/shared_ptr::swap.md)|Troca dois`shared_ptr`objetos.|  
|[shared\_ptr::unique](../Topic/shared_ptr::unique.md)|Testa se o recurso possuído é exclusivo.|  
|[shared\_ptr::use\_count](../Topic/shared_ptr::use_count.md)|Números de contagens de proprietários de recursos.|  
  
### Operadores  
  
|||  
|-|-|  
|[shared\_ptr::tipo booliano de operador](../Topic/shared_ptr::operator%20boolean-type.md)|Testa se um recurso possuído existe.|  
|[shared\_ptr::operator\*](../Topic/shared_ptr::operator*.md)|Obtém o valor designado.|  
|[shared\_ptr::operator\=](../Topic/shared_ptr::operator=.md)|Substitui o recurso possuído.|  
|[shared\_ptr::operator\-\>](../Topic/shared_ptr::operator-%3E.md)|Obtém um ponteiro para o valor designado.|  
  
## Requisitos  
 **Cabeçalho:** \<memory\>  
  
 **Namespace:** std  
  
## Consulte também  
 [Classe weak\_ptr](../standard-library/weak-ptr-class.md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)