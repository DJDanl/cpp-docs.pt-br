---
title: "Classes and Structs  (C++ Component Extensions) | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "public"
  - "ref struct"
  - "value_CPP"
  - "ref class"
  - "value struct"
  - "ref struct_cpp"
  - "ref class_cpp"
  - "value class_cpp"
  - "value struct_cpp"
  - "value class"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "ref class keyword [C++]"
  - "value class keyword [C++]"
  - "value struct keyword [C++]"
  - "ref struct keyword [C++]"
ms.assetid: 5c360764-b229-49c6-9357-66213afbc372
caps.latest.revision: 32
caps.handback.revision: 32
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classes and Structs  (C++ Component Extensions)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Declara uma classe ou estrutura cujo *tempo de vida do objeto* é administrado automaticamente.  Quando o objeto não é mais acessível ou sai do escopo, o Visual C\+\+ descarta automaticamente a memória alocada para o objeto.  
  
## Todos os Tempos de Execução  
 **Sintaxe**  
  
```  
  
          class_access ref class    name modifier :  inherit_access base_type {};  
class_access ref struct   name modifier :  inherit_access base_type {};  
class_access value class  name modifier :  inherit_access base_type {};  
class_access value struct name modifier :  inherit_access base_type {};  
  
```  
  
 **Parâmetros**  
  
 *class\_access* \(opcional\)  
 A acessibilidade da classe ou struct fora do assembly.  Os valores possíveis são **públicas** e `private` \(`private` é o padrão\).  Classes aninhadas ou estruturas não podem ter um *class\_access* especificador.  
  
 *name*  
 O nome da classe ou estrutura.  
  
 *modificador* \(opcional\)  
 [abstrata](../windows/abstract-cpp-component-extensions.md) e [lacrado](../windows/sealed-cpp-component-extensions.md) são os modificadores válidos.  
  
 *inherit\_access* \(opcional\)  
 A acessibilidade de `base_type`.  A acessibilidade permitida somente é `public` \(`public` é o padrão\).  
  
 *base\_type* \(opcional\)  
 Um tipo base.  No entanto, um tipo de valor não pode atuar como um tipo base.  
  
 Para obter mais informações, consulte as descrições de idioma específico deste parâmetro na [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] e [!INCLUDE[clr_for_headings](../dotnet/includes/clr_for_headings_md.md)] seções.  
  
 **Observações**  
  
 A acessibilidade de membro padrão de um objeto declarado com **classe ref** ou **classe de valor** é `private`.  E a acessibilidade de membro padrão de um objeto declarado com **estrutura ref** ou **estrutura de valor** é `public`.  
  
 Quando um tipo de referência herda de outro tipo de referência, funções virtuais na classe base explicitamente devem ser substituídas \(com [override](../windows/override-cpp-component-extensions.md)\) ou oculto \(com [new \(new slot in vtable\)](../windows/new-new-slot-in-vtable-cpp-component-extensions.md)\).  As funções de classe derivada também devem ser marcadas explicitamente como `virtual`.  
  
 Detectar no tempo de compilação se um tipo é um `ref class` ou `ref struct`, ou um `value class` ou `value struct`, use `__is_ref_class (``type``)`, `__is_value_class (``type``)`, ou `__is_simple_value_class (``type``)`.  Para obter mais informações, consulte [Compiler Support for Type Traits](../windows/compiler-support-for-type-traits-cpp-component-extensions.md).  
  
 Para obter mais informações sobre classes e estruturas, consulte  
  
-   [Criando Classes e estruturas](../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md)  
  
-   [Semântica do ponteiro em tipos de referência e valor](../misc/semantics-of-the-this-pointer-in-value-and-reference-types.md)  
  
-   [Semântica da pilha do C\+\+ para tipos de referência](../dotnet/cpp-stack-semantics-for-reference-types.md)  
  
-   [Classes, estruturas e uniões](../Topic/Classes%20and%20Structs%20\(C++\).md)  
  
-   [público e privado em Classes nativas](../misc/how-to-declare-public-and-private-on-native-classes.md)  
  
-   [Classes implicitamente abstratas](../misc/implicitly-abstract-classes.md)  
  
-   [Definir construtores estáticos em uma classe ou estrutura](../misc/how-to-define-static-constructors-in-a-class-or-struct.md)  
  
-   [A cópia do construtor poderá não ser gerada](../Topic/Copy%20Constructor%20May%20Not%20Be%20Generated.md)  
  
-   [Funções Ocultar por Assinatura em tipos de referência](../misc/hide-by-signature-functions-in-reference-types.md)  
  
-   [Destruidores e finalizadores em Visual C\+\+](../misc/destructors-and-finalizers-in-visual-cpp.md)  
  
-   [Visibilidade do tipo e do membro](../Topic/Type%20and%20Member%20Visibility.md)  
  
-   [Operadores definidos pelo usuário](../dotnet/user-defined-operators-cpp-cli.md)  
  
-   [Conversões definidas pelo usuário](../dotnet/user-defined-conversions-cpp-cli.md)  
  
-   [Como encapsular classe nativa a ser usada por C\#](../Topic/How%20to:%20Wrap%20Native%20Class%20for%20Use%20by%20C%23.md)  
  
-   [Generic Classes \(C\+\+\/CLI\)](../Topic/Generic%20Classes%20\(C++-CLI\).md)  
  
## [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)]  
 **Observações**  
  
 Consulte [classes e estruturas Ref](http://msdn.microsoft.com/library/windows/apps/hh699870.aspx) e [classes e estruturas de valor](http://msdn.microsoft.com/library/windows/apps/hh699861.aspx).  
  
 **Parâmetros**  
  
 *base\_type* \(opcional\)  
 Um tipo base.  Um `ref class` ou `ref struct` pode herdar de zero ou mais interfaces e zero ou um `ref` tipos.  Um `value class` ou `value struct` só pode herdar de zero ou mais interfaces.  
  
 Ao declarar um objeto usando o `ref class` ou `ref struct` palavras\-chave, o objeto é acessado por um identificador para um objeto, ou seja, um ponteiro de contador de referência para o objeto.  Quando a variável declarada sai do escopo, o compilador automaticamente exclui o objeto subjacente.  Quando o objeto é usado como um parâmetro em uma chamada ou armazenado em uma variável, um identificador para o objeto, na verdade, é passado ou armazenado.  
  
 Ao declarar um objeto usando o `value class` ou `value struct` palavras\-chave, o tempo de vida do objeto do objeto declarado não é supervisionado.  O objeto é como qualquer outra classe C\+\+ padrão ou struct.  
  
### Requisitos  
 Opção do compilador: **\/ZW**  
  
## [!INCLUDE[clr_for_headings](../dotnet/includes/clr_for_headings_md.md)]  
 **Observações**  
  
 A tabela a seguir lista as diferenças da sintaxe mostrada no **todos os tempos de execução** seção são específicas para o C \+ \+ \/ CLI.  
  
 **Parâmetros**  
  
 *base\_type* \(opcional\)  
 Um tipo base.  Um `ref class` ou `ref struct` pode herdar de zero ou mais gerenciados interfaces e zero ou tipos de uma referência.  Um `value class` ou `value struct` só pode herdar de zero ou mais interfaces gerenciadas.  
  
 O `ref class` e `ref struct` palavras\-chave dizer ao compilador que a classe ou estrutura deve ser alocado no heap.  Quando o objeto é usado como um parâmetro em uma chamada ou armazenado em uma variável, uma referência ao objeto, na verdade, é passada ou armazenada.  
  
 O `value class` e `value struct` palavras\-chave informa ao compilador que o valor alocado de classe ou estrutura é passado para funções ou armazenado em membros.  
  
### Requisitos  
 Opção do compilador: **\/clr**  
  
## Consulte também  
 [Component Extensions for Runtime Platforms](../windows/component-extensions-for-runtime-platforms.md)