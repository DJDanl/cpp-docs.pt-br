---
title: "Windows Runtime and Managed Templates (C++ Component Extensions) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "templates, with CLR types"
ms.assetid: cf59d16b-5514-448b-9a95-e0b4fcb616a6
caps.latest.revision: 14
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Windows Runtime and Managed Templates (C++ Component Extensions)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os modelos lhe permitem definir um protótipo de um tipo de Tempo de Execução do Windows ou de Common Language Runtime, e criar\-los uma instância em variações de aquele tipo usando parâmetros de tipo diferente do modelo.  
  
## Todos os Tempos de Execução  
 Você pode criar modelos dos tipos de valor ou de referência.  Para obter mais informações sobre como criar tipos de valor ou de referência, consulte [Classes and Structs](../windows/classes-and-structs-cpp-component-extensions.md).  
  
 Para obter mais informações sobre modelos da classe padrão do C\+\+, consulte [Modelos de classe](../Topic/Class%20Templates.md).  
  
## Tempo de execução do windows  
 \(Não há nenhum comentário sobre este recurso de linguagem que se aplica somente Tempo de Execução do Windows\).  
  
### Requisitos  
 Opção do compilador: **\/ZW**  
  
## Common Language Runtime  
 Há algumas limitações a criar modelos de classes de tipos gerenciados, que são demonstrados nos exemplos de código.  
  
### Requisitos  
 Opção do compilador: **\/clr**  
  
### Exemplos  
 **Exemplo**  
  
 É possível criar uma instância de um tipo genérico com um parâmetro de tipo gerenciado do modelo, mas você não pode criar uma instância de um modelo gerenciado com um parâmetro genérico de modelo do tipo.  Isso porque os tipos genéricos são resolvidos em tempo de execução.  Para obter mais informações, consulte [Generics and Templates \(Visual C\+\+\)](../windows/generics-and-templates-visual-cpp.md).  
  
```cpp  
// managed_templates.cpp  
// compile with: /clr /c  
  
generic<class T>   
ref class R;   
  
template<class T>   
ref class Z {  
   // Instantiate a generic with a template parameter.  
   R<T>^ r;    // OK  
};  
  
generic<class T>   
ref class R {  
   // Cannot instantiate a template with a generic parameter.  
   Z<T>^ z;   // C3231  
};  
```  
  
 **Exemplo**  
  
 Um tipo ou uma função genérico não podem ser aninhados em um modelo gerenciado.  
  
```cpp  
// managed_templates_2.cpp  
// compile with: /clr /c  
  
template<class T> public ref class R {  
   generic<class T> ref class W {};   // C2959  
};  
```  
  
 **Exemplo**  
  
 Você não pode acessar os modelos definidos em um assembly referenciado com sintaxe da linguagem de C\+\+\/CLI, mas você pode usar a reflexão.  Se um modelo não é criado uma instância do, não é emitido nos metadados.  Se um modelo é criada uma instância, somente as funções de membro referenciadas serão exibidas nos metadados.  
  
```cpp  
// managed_templates_3.cpp  
// compile with: /clr  
  
// Will not appear in metadata.  
template<class T> public ref class A {};  
  
// Will appear in metadata as a specialized type.  
template<class T> public ref class R {  
public:  
   // Test is referenced, will appear in metadata  
   void Test() {}  
  
   // Test2 is not referenced, will not appear in metadata  
   void Test2() {}  
};  
  
// Will appear in metadata.  
generic<class T> public ref class G { };  
  
public ref class S { };  
  
int main() {  
   R<int>^ r = gcnew R<int>;  
   r->Test();  
}  
```  
  
 **Exemplo**  
  
 Você pode alterar o modificador gerenciado de uma classe em uma especialização parcial ou na especialização explícita de um modelo da classe.  
  
```cpp  
// managed_templates_4.cpp  
// compile with: /clr /c  
  
// class template  
// ref class  
template <class T>  
ref class A {};  
  
// partial template specialization  
// value type  
template <class T>  
value class A <T *> {};  
  
// partial template specialization  
// interface  
template <class T>   
interface class A<T%> {};  
  
// explicit template specialization  
// native class  
template <>  
class A <int> {};  
  
```  
  
## Consulte também  
 [Component Extensions for Runtime Platforms](../windows/component-extensions-for-runtime-platforms.md)