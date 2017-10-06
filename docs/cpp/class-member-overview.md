---
title: "Visão geral do membro da classe | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- members [C++], types of class members
- members [C++]
- class members [C++], types of
- class members
ms.assetid: 8802cfa9-705d-4f37-acde-245d6838010c
caps.latest.revision: 9
author: mikeblome
ms.author: mblome
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
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 0a5a62edf0e71b4fecf25cf10731af7d7c515da7
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="class-member-overview"></a>Visão geral de membros de classe
Uma classe ou estrutura consiste em seus membros. O trabalho que faz uma classe é executado por suas funções de membro. O estado que o mantém é armazenado em seus membros de dados. Inicialização de membros é feita por construtores e trabalho de limpeza como liberação de memória e liberação de recursos é feita por destruidores. No C++ 11 e posterior, membros de dados pode (e geralmente deve) ser inicializados no ponto de declaração.  
  
## <a name="kinds-of-class-members"></a>Tipos de membros de classe  
 A lista completa das categorias de membro é o seguinte:  
  
-   [Funções de membro especial](special-member-functions.md).  
  
-   [Visão geral das funções de membro](overview-of-member-functions.md).  
  
-   [Membros de dados](static-members-cpp.md) tipos definidos pelo incluindo tipos internos e outro usuário.  
  
-   Operadores  
  
-   [Aninhados declarações de classe](nested-class-declarations.md) e.)  
  
-   [Uniões](unions.md)  
  
-   [Enumerações](../cpp/enumerations-cpp.md).  
  
-   [Campos de bit](../cpp/cpp-bit-fields.md).  
  
-   [Amigos](../cpp/friend-cpp.md).  
  
-   [Aliases e typedefs](../cpp/aliases-and-typedefs-cpp.md).  
  
    > [!NOTE]
    >  Os friends são incluídos na lista anterior porque estão contidos na declaração da classe. Porém, eles não são membros da classe true, pois não estão no escopo da classe.  
  
## <a name="example-class-declaration"></a>Declaração de classe de exemplo  
 O exemplo a seguir mostra uma declaração de classe simples:  
  
```  
// TestRun.h  
  
class TestRun  
{  
    // Start member list.  
  
    //The class interface accessible to all callers.  
public:  
    // Use compiler-generated default constructor:  
    TestRun() = default;   
    // Don't generate a copy constructor:  
    TestRun(const TestRun&) = delete;    
    TestRun(std::string name);  
    void DoSomething();  
    int Calculate(int a, double d);  
    virtual ~TestRun();  
    enum class State { Active, Suspended };  
  
    // Accessible to this class and derived classes only.  
protected:  
    virtual void Initialize();  
    virtual void Suspend();  
    State GetState();  
  
    // Accessible to this class only.  
private:  
    // Default brace-initialization of instance members:  
    State _state{ State::Suspended };   
    std::string _testName{ "" };   
    int _index{ 0 };  
  
    // Non-const static member:  
    static int _instances;  
    // End member list.  
};  
  
// Define and initialize static member.  
int TestRun::_instances{ 0 };  
```  
  
## <a name="member-accessibility"></a>Acessibilidade de membro  
 Os membros de uma classe são declarados na lista de membros. A lista de membros de uma classe pode ser dividida em qualquer número de `private`, `protected` e **pública** seções usando palavras-chave, conhecidas como especificadores de acesso.  Dois-pontos **:** deve seguir o especificador de acesso.  Essas seções não precisam ser contíguas, ou seja, qualquer uma dessas palavras-chave pode aparecer várias vezes na lista de membros.  A palavra-chave designa o acesso de todos os membros acima até o próximo especificador de acesso ou a próxima chave de fechamento. Para obter mais informações, consulte [controle de acesso de membro (C++)](../cpp/member-access-control-cpp.md).  
  
## <a name="static-members"></a>Membros estáticos  
 Um membro de dados pode ser declarado como estático, que significa que todos os objetos da classe tem acesso para a mesma cópia dele. Uma função de membro pode ser declarada como estática, caso em que ele pode acessar somente os membros de dados estáticos da classe (e não tem nenhum *isso* ponteiro). Para obter mais informações, consulte [membros de dados estáticos](../cpp/static-members-cpp.md).  
  
## <a name="special-member-functions"></a>Funções de membro especiais  
 Funções de membro especiais são funções que são fornecidas automaticamente pelo compilador, se você não especificá-los em seu código-fonte.  
  
1.  Construtor padrão  
  
2.  Construtor de cópia  
  
3.  **(C + + 11) ** Construtor de movimento  
  
4.  Operador de atribuição de cópia  
  
5.  **(C + + 11) ** Operador de atribuição de movimentação  
  
6.  Destruidor  
  
Para obter mais informações, consulte [funções de membro especial](../cpp/special-member-functions.md).
  
## <a name="memberwise-initialization"></a>Inicialização memberwise  
 No C++ 11 e posterior, declaradores de membro não estático podem conter inicializadores.  
  
```  
  
class CanInit  
{  
public:  
    long num {7};       // OK in C++11  
    int k = 9;          // OK in C++11  
    static int i = 9; // Error: must be defined and initialized  
                      // outside of class declaration.  
  
    // initializes num to 7 and k to 9  
    CanInit(){}  
  
    // overwrites original initialized value of num:  
    CanInit(int val) : num(val) {}  
};  
int main()  
{  
}  
```  
  
 Se um membro é atribuído um valor em um construtor, esse valor substituirá o valor com o qual o membro foi inicializado no ponto de declaração.  
  
 Há apenas uma cópia compartilhada membros de dados estáticos para todos os objetos de um determinado tipo de classe. Os membros de dados estáticos devem ser definidos e podem ser inicializados no escopo do arquivo. (Para obter mais informações sobre membros de dados estáticos, consulte [membros de dados estáticos](../cpp/static-members-cpp.md).) O exemplo a seguir mostra como realizar essas inicializações:  
  
```  
// class_members2.cpp  
class CanInit2  
{  
public:  
    CanInit2() {} // Initializes num to 7 when new objects of type   
                 //  CanInit are created.  
    long     num {7};  
    static int i;  
    static int j;  
};  
  
// At file scope:  
  
// i is defined at file scope and initialized to 15.  
// The initializer is evaluated in the scope of CanInit.  
int CanInit2::i = 15;  
  
// The right side of the initializer is in the scope   
// of the object being initialized  
int CanInit2::j = i;  
```  
  
> [!NOTE]
>  O nome da classe, `CanInit2`, deve preceder `i` para especificar que `i` que está sendo definida é um membro da classe `CanInit2`.  
  
## <a name="see-also"></a>Consulte também  
 [Classes e Structs](../cpp/classes-and-structs-cpp.md)

