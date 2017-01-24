---
title: "Operador de resolu&#231;&#227;o do escopo: :: | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "::"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Operador ::"
  - "operadores [C++], resolução do escopo"
  - "Operador de resolução do escopo"
  - "escopo, Operador de resolução do escopo"
ms.assetid: fd5de9d3-c716-4e12-bae9-03a16fd79a50
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Operador de resolu&#231;&#227;o do escopo: ::
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O operador de resolução do escopo `::` é utilizado para identificar e remover ambiguidades de identificadores usados em escopos diferentes.  Para obter mais informações sobre escopo, consulte [Escopo](../cpp/scope-visual-cpp.md).  
  
## Sintaxe  
  
```  
:: identifier class-name :: identifier namespace :: identifier enum class :: identifier enum struct :: identifier  
```  
  
## Comentários  
 O `identifier` pode ser uma variável, uma função ou um valor de enumeração.  
  
## Com classes e namespaces  
 O exemplo a seguir mostra como o operador de resolução do escopo é usado com namespaces e classes:  
  
```cpp  
namespace NamespaceA{  
    int x;  
    class ClassA {  
    public:  
        int x;  
    };  
}  
  
int main() {  
  
    // A namespace name used to disambiguate  
    NamespaceA::x = 1;  
  
    // A class name used to disambiguate  
    NamespaceA::ClassA a1;  
    a1.x = 2;  
  
}  
  
```  
  
 Um operador de resolução do escopo sem um qualificador de escopo refere\-se ao namespace global.  
  
```cpp  
namespace NamespaceA{  
    int x;  
}  
  
int x;   
  
int main() {  
    int x;  
  
    // the x in main()  
    x = 0;   
    // The x in the global namespace  
    ::x = 1;   
  
    // The x in the A namespace  
    NamespaceA::x = 2;   
}  
```  
  
 Você pode usar o operador de resolução do escopo para identificar um membro de um namespace ou para identificar um namespace que nomeia namespace de membros em uma diretiva de uso.  No exemplo abaixo, você pode usar `NamespaceC` para qualificar `ClassB`, embora `ClassB` tenha sido declarada em namespace `NamespaceB` porque `NamespaceB` foi nomeado em `NamespaceC` por uma diretiva de uso.  
  
```cpp  
namespace NamespaceB {  
    class ClassB {  
    public:  
        int x;  
    };  
}  
  
namespace NamespaceC{  
    using namespace B;  
  
}  
int main() {  
    NamespaceB::ClassB c_b;  
    NamespaceC::ClassB c_c;  
  
    c_b.x = 3;  
    c_c.x = 4;  
}  
  
```  
  
 Você pode usar cadeias de operadores de resolução do escopo.  No exemplo a seguir, `NamespaceD::NamespaceD1` identifica o namespace aninhado `NamespaceD1` e `NamespaceE::ClassE::ClassE1` identifica a classe aninhada `ClassE1`.  
  
```cpp  
namespace NamespaceD{  
    namespace NamespaceD1{  
        int x;  
    }  
}  
  
namespace NamespaceE{  
  
    class ClassE{  
    public:  
        class ClassE1{  
        public:  
            int x;  
        };  
    };  
}  
  
int main() {  
    NamespaceD:: NamespaceD1::x = 6;  
    NamespaceE::ClassE::ClassE1 e1;  
    e1.x = 7  ;  
}  
  
```  
  
## Com membros estáticos  
 Você deve usar o operador de resolução do escopo para chamar membros estáticos de classes.  
  
```cpp  
class ClassG {  
public:  
    static int get_x() { return x;}  
    static int x;  
};  
  
int ClassG::x = 6;  
  
int main() {  
  
    int gx1 = ClassG::x;  
    int gx2 = ClassG::get_x();   
}  
  
```  
  
## Com enumerações de escopo  
 O operador de resolução do escopo é também usado com os valores de uma enumeração de escopo [Declarações de enumeração](../cpp/enumerations-cpp.md), como no exemplo a seguir:  
  
```cpp  
enum class EnumA{  
    First,  
    Second,  
    Third  
};  
  
int main() {  
  
    EnumA enum_value = EnumA::First;  
}  
  
```  
  
## Consulte também  
 [Operadores, precedência e associatividade C\+\+](../cpp/cpp-built-in-operators-precedence-and-associativity.md)   
 [Namespaces](../cpp/namespaces-cpp.md)   
 [Nomes e nomes qualificados](../misc/names-and-qualified-names.md)