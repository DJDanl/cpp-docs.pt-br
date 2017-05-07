---
title: C2280 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 04/25/2017
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C2280
helpviewer_keywords:
- C2280
dev_langs:
- C++
ms.assetid: e6c5b1fb-2b9b-4554-8ff9-775eeb37161b
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 66798adc96121837b4ac2dd238b9887d3c5b7eef
ms.openlocfilehash: bec93f1ee238184cbb4eed0d98921fb28e94e222
ms.lasthandoff: 04/29/2017

---
# <a name="compiler-error-c2280"></a>C2280 de erro do compilador  
  
'*declaração*': tentativa de fazer referência a uma função excluída  
  
O compilador detectou uma tentativa de fazer referência a um `deleted` função. Esse erro pode ser causado por uma chamada para uma função de membro que foi explicitamente marcada como `= deleted` no código-fonte. Esse erro também pode ser causado por uma chamada para uma função de membro especial implícito de uma estrutura ou classe que é declarado e marcado como automaticamente `deleted` pelo compilador. Para obter mais informações sobre quando o compilador gera automaticamente `default` ou `deleted` funções de membro especial, consulte [funções de membro especial](../../cpp/special-member-functions.md).  
  
## <a name="example-explicitly-deleted-functions"></a>Exemplo: Explicitamente excluídos funções  

Uma chamada para um explicitamente `deleted` função causa esse erro. Um explicitamente `deleted` função de membro implica que a classe ou struct intencionalmente concebida para impedir seu uso, para corrigir esse problema, você deve alterar seu código para evitá-la.  
  
```cpp  
// C2280_explicit.cpp
// compile with: cl /c /W4 C2280_explicit.cpp
struct A {
    A();
    A(int) = delete;
};

struct B {
    A a1;
    A a2 = A(3); // C2280, calls deleted A::A(int)
    // To fix, remove the call to A(int)
};

void f() {
    B b;    // calls implicit B::B(void)
}
```  
  
## <a name="example-uninitialized-data-members"></a>Exemplo: Membros de dados não inicializados  
  
Um membro de dados de tipo de referência não inicializado ou `const` membro de dados faz com que o compilador declara implicitamente um `deleted` construtor padrão. Para corrigir esse problema, inicialize o membro de dados quando ela é declarada.  
  
```cpp  
// C2280_uninit.cpp
// compile with: cl /c C2280_uninit.cpp
struct A {
    const int i; // uninitialized const-qualified data
    // members or reference type data members cause
    // the implicit default constructor to be deleted.
    // To fix, initialize the value in the declaration:
    // const int i = 42;
} a;    // C2280
```  
  
## <a name="example-reference-and-const-data-members"></a>Exemplo: Referência e constantes membros de dados  
  
Um `const` ou membro de dados de tipo de referência faz com que o compilador declarar um `deleted` operador de atribuição de cópia. Depois de inicializadas, esses membros não podem ser atribuídos, para que uma simple cópia ou movimentação não pode funcionar. Para corrigir esse problema, é recomendável que você altere a lógica para remover as operações de atribuição que causam o erro.  
  
```cpp  
// C2280_ref.cpp
// compile with: cl /c C2280_ref.cpp
extern int k;
struct A {
    A();
    int& ri = k; // a const or reference data member causes 
    // implicit copy assignment operator to be deleted.
};

void f() {
    A a1, a2;
    // To fix, consider removing this assignment.
    a2 = a1;    // C2280
}
```  
  
## <a name="example-movable-deletes-implicit-copy"></a>Exemplo: Movable exclui cópia implícita  
  
Se uma classe declara um construtor move ou o operador de atribuição de movimentação, mas não declarar explicitamente um construtor de cópia, o compilador implicitamente declara um construtor de cópia e define-o como `deleted`. Da mesma forma, se uma classe declara um construtor move ou o operador de atribuição de movimentação, mas não declarar explicitamente um operador de atribuição de cópia, o compilador implicitamente declara um operador de atribuição de cópia e define-o como `deleted`. Para corrigir esse problema, você deve declarar explicitamente esses membros.  
 
Quando você vir o erro C2280 na conexão com um `unique_ptr`, provavelmente é porque você está tentando chamar seu construtor de cópia, o que é uma `deleted` função. Por design, um `unique_ptr` não pode ser copiado. Use um construtor de movimento para transferir a propriedade.  

```cpp  
// C2280_move.cpp
// compile with: cl /c C2280_move.cpp
class base  
{  
public:  
    base();  
    ~base(); 
    base(base&&); 
    // Move constructor causes copy constructor to be
    // implicitly declared as deleted. To fix this 
    // issue, you can explicitly declare a copy constructor:
    // base(base&);
    // If you want the compiler default version, do this:
    // base(base&) = default;
};  

void copy(base *p)  
{  
    base b{*p};  // C2280
}  
```  

## <a name="example-variant-and-volatile-members"></a>Exemplo: Membros de variáveis e volátil  
  
Versões do compilador antes do Visual Studio 2015 atualização 2 foram construtores padrão gerados e não conformes e destruidores para uniões anônimas. Esses agora são implicitamente declarados como `deleted`. Essas versões também permitiam não conformes definição implícita de `default` copiar e mover construtores e `default` copiar e mover os operadores de atribuição em classes e estruturas que têm `volatile` variáveis de membro. O compilador agora considera esses ter construtores não trivial e operadores de atribuição e não gera `default` implementações. Quando essa classe é um membro de uma união ou uma união anônima dentro de uma classe, construtores de cópia e movimentação e operadores de atribuição de cópia e movimentação da união ou classe são definidos implicitamente como `deleted`. Para corrigir esse problema, você deve declarar explicitamente as funções de membro especial necessária.  
  
```cpp  
// C2280_variant.cpp
// compile with: cl /c C2280_variant.cpp
struct A {  
    A() = default;
    A(const A&);
};  

struct B {  
    union {  
        A a;  
        int i;  
    };
    // To fix this issue, declare the required 
    // special member functions:
    // B(); 
    // B(const B& b);
};  

int main() {
    B b1;  
    B b2(b1);  // C2280  
}
```  
  
## <a name="example-indirect-base-members-deleted"></a>Exemplo: Membros base indiretos excluídos  
  
Versões do compilador antes do Visual Studio 2015 atualização 2 foram não conformes e permissão de uma classe derivada para chamadas de funções de indiretamente derivados de membro especial `private virtual` classes base. O compilador agora emite o erro do compilador C2280 quando essa chamada é feita.  
  
Neste exemplo, classe `top` deriva indiretamente de privada virtual `base`. No código de conformidade, isso faz com que os membros de `base` inacessível para `top`; um objeto do tipo `top` não pode ser padrão construído ou destruído. Para corrigir esse problema no código que usavam o antigo comportamento de compilador, alterar a classe intermediária usar `protected virtual` derivação ou altere o `top` classe usar derivação direta:  

```cpp  
// C2280_indirect.cpp
// compile with: cl /c C2280_indirect.cpp
class base  
{  
protected:  
    base();  
    ~base();  
};  

class middle : private virtual base {}; 
// Possible fix: Replace line above with:
// class middle : protected virtual base {};
class top : public virtual middle {};    // C4594, C4624
// Another possible fix: use direct derivation:
// class top : public virtual middle, private virtual base {};   

void destroy(top *p)  
{  
    delete p;  // C2280  
}  
```  
  
