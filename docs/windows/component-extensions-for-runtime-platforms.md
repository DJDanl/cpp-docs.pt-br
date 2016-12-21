---
title: "Component Extensions for Runtime Platforms | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
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
  - "what's new [C++], keywords"
  - "what's new [C++], language features"
  - "Visual C++, keywords"
  - "keywords [C++]"
  - "Managed Extensions for C++, replacement syntax"
ms.assetid: 1e400ee6-3ac9-4910-a608-9d3d5993e423
caps.latest.revision: 77
caps.handback.revision: 77
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Component Extensions for Runtime Platforms
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Visual C\+\+ fornece extensões de linguagem para ajudar a você programar em plataformas de tempo de execução.  Usando [!INCLUDE[cppwrt](../build/reference/includes/cppwrt_md.md)] \([!INCLUDE[cppwrt_short](../Token/cppwrt_short_md.md)]\), você pode programar [!INCLUDE[win8_appname_long](../build/includes/win8_appname_long_md.md)] aplicativos e componentes compilados para código nativo.  Embora você possa criar [!INCLUDE[win8_appname_long](../build/includes/win8_appname_long_md.md)] aplicativos por programação diretamente contra o [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] interfaces COM, usando [!INCLUDE[cppwrt_short](../Token/cppwrt_short_md.md)], você pode trabalhar com outras linguagens de programação do C\+\+ moderno, exceções e construtores.  Para habilitar a programação do C\+\+ em um ambiente de execução gerenciado na plataforma .NET, você pode usar [!INCLUDE[cppcli](../build/reference/includes/cppcli_md.md)].  
  
 **Dois tempos de execução, um conjunto de extensões**  
  
 [!INCLUDE[cppwrt_short](../Token/cppwrt_short_md.md)] é um subconjunto de [!INCLUDE[cppcli](../build/reference/includes/cppcli_md.md)].  Para as extensões que são comuns a [!INCLUDE[cppwrt_short](../Token/cppwrt_short_md.md)] e [!INCLUDE[cppcli](../build/reference/includes/cppcli_md.md)], a semântica depende se você tiver como alvo o common language runtime \(CLR\) ou o [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)].  Para compilar o aplicativo seja executado no [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)], especifique o **\/ZW** opção de compilador.  Para compilá\-lo para ser executado no CLR, especifique o **\/clr** opção de compilador.  Essas opções são definidas automaticamente quando você usa o Visual Studio para criar um projeto.  
  
 Para obter mais informações sobre como criar [!INCLUDE[win8_appname_long](../build/includes/win8_appname_long_md.md)] aplicativos em C\+\+, consulte [aplicativos roteiro para execução do Windows usando C\+\+](http://msdn.microsoft.com/library/windows/apps/hh700360.aspx).  
  
 [!INCLUDE[cppcli](../build/reference/includes/cppcli_md.md)] estende o padrão ANSI\/ISO C\+\+ e definidos de acordo com a Ecma [!INCLUDE[cppcli](../build/reference/includes/cppcli_md.md)] padrão.  Para obter mais informações, consulte [Programação do .NET com o C \+ \+ \/ CLI \(Visual C\+\+\)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md).  
  
## Palavras\-chave de tipo de dados  
 As extensões de linguagem incluem *agregar as palavras\-chave*, que são palavras\-chave que consistem em dois tokens separados por espaços em branco.  Os tokens podem ter um significado quando são usados separadamente e outro significado quando eles são usados juntos.  Por exemplo, a palavra "ref" é um identificador comum, e a palavra "class" é uma palavra\-chave que declara uma classe nativa.  Mas quando essas palavras são combinadas para formar `ref class`, a palavra\-chave agregada resultante declara uma entidade que é conhecida como um *classe runtime*.  
  
 As extensões também incluem *contextual* palavras\-chave.  Uma palavra\-chave é tratada como contextual, dependendo do tipo de instrução que contém e seu posicionamento na instrução.  Por exemplo, o token "propriedade" pode ser um identificador, ou ele pode declarar um tipo especial de membro de classe pública.  
  
 A tabela a seguir lista as palavras\-chave na extensão da linguagem C\+\+.  
  
|Palavra\-chave|Sensível ao contexto|Finalidade|Referência|  
|--------------------|--------------------------|----------------|----------------|  
|`ref class`<br /><br /> `ref struct`|Não|Declara uma classe.|[Classes and Structs](../windows/classes-and-structs-cpp-component-extensions.md)|  
|`value class`<br /><br /> `value struct`|Não|Declara uma classe de valor.|[Classes and Structs](../windows/classes-and-structs-cpp-component-extensions.md)|  
|`interface class`<br /><br /> `interface struct`|Não|Declara uma interface.|[interface class](../windows/interface-class-cpp-component-extensions.md)|  
|`enum class`<br /><br /> `enum struct`|Não|Declara uma enumeração.|[enum class](../windows/enum-class-cpp-component-extensions.md)|  
|`property`|Sim|Declara uma propriedade.|[property](../windows/property-cpp-component-extensions.md)|  
|`delegate`|Sim|Declara um delegado.|[delegado](../windows/delegate-cpp-component-extensions.md)|  
|`event`|Sim|Declara um evento.|[event](../windows/event-cpp-component-extensions.md)|  
  
## Especificadores de Substituição  
 Você pode usar as seguintes palavras\-chave para qualificar o comportamento de substituição para derivação.  Embora o `new` palavra\-chave não é uma extensão do C\+\+, ele está listado aqui porque ele pode ser usado em um contexto adicional.  Alguns especificadores também são válidos de programação nativa.  Para obter mais informações, consulte [Como declarar especificadores de substituição em compilações nativas](../dotnet/how-to-declare-override-specifiers-in-native-compilations-cpp-cli.md).  
  
|Palavra\-chave|Sensível ao contexto|Finalidade|Referência|  
|--------------------|--------------------------|----------------|----------------|  
|`abstract`|Sim|Indica que as funções ou classes são abstratas.|[abstract](../windows/abstract-cpp-component-extensions.md)|  
|`new`|Não|Indica que uma função não é uma substituição de uma versão da classe base.|[new \(new slot in vtable\)](../windows/new-new-slot-in-vtable-cpp-component-extensions.md)|  
|`override`|Sim|Indica que um método deve ser uma substituição de uma versão da classe base.|[override](../windows/override-cpp-component-extensions.md)|  
|`sealed`|Sim|Impede que classes que estão sendo usadas como classes base.|[sealed](../windows/sealed-cpp-component-extensions.md)|  
  
## Palavras\-chave para genéricos  
 As seguintes palavras\-chave foram adicionadas para dar suporte a tipos genéricos.  Para obter mais informações, consulte [Generics](../windows/generics-cpp-component-extensions.md).  
  
|Palavra\-chave|Sensível ao contexto|Finalidade|  
|--------------------|--------------------------|----------------|  
|`generic`|Não|Declara um tipo genérico.|  
|`where`|Sim|Especifica as restrições são aplicadas a um parâmetro de tipo genérico.|  
  
## Diversas palavras\-chave  
 As seguintes palavras\-chave foram adicionadas às extensões do C\+\+.  
  
|Palavra\-chave|Sensível ao contexto|Finalidade|Referência|  
|--------------------|--------------------------|----------------|----------------|  
|`finally`|Sim|Indica o comportamento de handlings de exceção padrão.|[Exception Handling](../windows/exception-handling-cpp-component-extensions.md)|  
|`for each, in`|Não|Enumera os elementos de uma coleção.|[for each, in](../dotnet/for-each-in.md)|  
|`gcnew`|Não|Aloca tipos no heap coletado como lixo.  Use, em vez de `new` e `delete`.|[ref new, gcnew](../windows/ref-new-gcnew-cpp-component-extensions.md)|  
|`ref new`|Sim|Aloca um [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] tipo.  Use, em vez de `new` e `delete`.|[ref new, gcnew](../windows/ref-new-gcnew-cpp-component-extensions.md)|  
|`initonly`|Sim|Indica que um membro só pode ser inicializado na declaração ou em um construtor estático.|[initonly](../dotnet/initonly-cpp-cli.md)|  
|`literal`|Sim|Cria uma variável literal.|[literal](../windows/literal-cpp-component-extensions.md)|  
|`nullptr`|Não|Indica que um identificador ou ponteiro não faz referência a um objeto.|[nullptr](../windows/nullptr-cpp-component-extensions.md)|  
  
## Construções de modelo  
 As seguintes construções de linguagem são implementadas como modelos, em vez de como palavras\-chave.  Se você especificar o **\/ZW** opção de compilador são definidos no `lang` namespace.  Se você especificar o **\/clr** opção de compilador são definidos no `cli` namespace.  
  
|Palavra\-chave|Finalidade|Referência|  
|--------------------|----------------|----------------|  
|`array`|Declara uma matriz.|[Arrays](../windows/arrays-cpp-component-extensions.md)|  
|`interior_ptr`|\(CLR\) Pontos de dados em um tipo de referência.|[interior\_ptr \(C\+\+\/CLI\)](../windows/interior-ptr-cpp-cli.md)|  
|`pin_ptr`|\(CLR\) Pontos de referência para tipos de CLR para suprimir temporariamente o sistema de coleta de lixo.|[pin\_ptr \(C\+\+\/CLI\)](../Topic/pin_ptr%20\(C++-CLI\).md)|  
|`safe_cast`|Determina e executa o método de conversão ideal para um tipo de tempo de execução.|[safe\_cast](../windows/safe-cast-cpp-component-extensions.md)|  
|`typeid`|\(CLR\) Recupera um <xref:System.Type?displayProperty=fullName> objeto que descreve o tipo de dado ou objeto.|[typeid](../Topic/typeid%20%20\(C++%20Component%20Extensions\).md)|  
  
## Declaradores  
 Os declaradores de tipo a seguir instruem o tempo de execução para gerenciar automaticamente o tempo de vida e a exclusão de objetos alocados.  
  
|Operador|Finalidade|Referência|  
|--------------|----------------|----------------|  
|`^`|Declara um identificador para um objeto; ou seja, um ponteiro para um [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] ou objeto CLR que é excluído automaticamente quando não é mais utilizável.|[Operador Handle to Object \(^\)](../windows/handle-to-object-operator-hat-cpp-component-extensions.md)|  
|`%`|Declara uma referência de rastreamento; ou seja, uma referência a um [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] ou objeto CLR que é excluído automaticamente quando não é mais utilizável.|[Tracking Reference Operator](../windows/tracking-reference-operator-cpp-component-extensions.md)|  
  
## Outras construções e tópicos relacionados  
 Esta seção lista as construções de programação adicionais e tópicos que pertencem ao CLR.  
  
|Tópico|Descrição|  
|------------|---------------|  
|[\_\_identifier \(C\+\+\/CLI\)](../windows/identifier-cpp-cli.md)|\([!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] e CLR\) permite o uso de palavras\-chave como identificadores.|  
|[Variable Argument Lists \(...\) \(C\+\+\/CLI\)](../windows/variable-argument-lists-dot-dot-dot-cpp-cli.md)|\([!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] e CLR\) permite que uma função para obter um número variável de argumentos.|  
|[Equivalentes do .NET Framework aos tipos nativos do C\+\+](../dotnet/dotnet-framework-equivalents-to-cpp-native-types-cpp-cli.md)|Lista os tipos CLR que são usados no lugar de tipos integrais do C\+\+.|  
|[appdomain](../Topic/appdomain.md) `__declspec` modificador|`__declspec` modificador que exige a existem de variáveis globais e estáticas por appdomain.|  
|[C\-Style Casts with \/clr \(C\+\+\/CLI\)](../windows/c-style-casts-with-clr-cpp-cli.md)|Descreve como conversões de estilo C são interpretadas.|  
|[\_\_clrcall](../cpp/clrcall.md) convenção de chamada|Indica a convenção de chamada compatíveis com CLR.|  
|`__cplusplus_cli`|[Macros predefinidas](../preprocessor/predefined-macros.md)|  
|[Custom Attributes](../windows/custom-attributes-cpp.md)|Descreve como definir seus próprios atributos CLR.|  
|[Exception Handling](../windows/exception-handling-cpp-component-extensions.md)|Fornece uma visão geral de manipulação de exceção.|  
|[Explicit Overrides](../windows/explicit-overrides-cpp-component-extensions.md)|Demonstra como funções de membro podem substituir membros arbitrários.|  
|[Assemblies amigáveis \(C\+\+\)](../dotnet/friend-assemblies-cpp.md)|Discute como um assembly de cliente pode acessar todos os tipos em um componente do assembly.|  
|[Boxing](../windows/boxing-cpp-component-extensions.md)|Demonstra as condições em quais valores de tipos de conversão boxing são realizados.|  
|[Compiler Support for Type Traits](../windows/compiler-support-for-type-traits-cpp-component-extensions.md)|Discute como detectar as características dos tipos em tempo de compilação.|  
|[gerenciado, não gerenciado](../preprocessor/managed-unmanaged.md) pragmas|Demonstra como gerenciadas e funções podem coexistir no mesmo módulo.|  
|[process](../cpp/process.md) `__declspec` modificador|`__declspec` modificador que exige a existem de variáveis globais e estáticas por processo.|  
|[Reflexão](../dotnet/reflection-cpp-cli.md)|Demonstra a versão do CLR de informações de tipo de tempo de execução.|  
|[String](../windows/string-cpp-component-extensions.md)|Discute a conversão de compilador de literais de cadeia de caracteres para <xref:System.String>.|  
|[Type Forwarding \(C\+\+\/CLI\)](../windows/type-forwarding-cpp-cli.md)|Permite a movimentação de um tipo em um assembly de envio para outro conjunto para que o código do cliente não precisa ser recompilado.|  
|[User\-Defined Attributes](../windows/user-defined-attributes-cpp-component-extensions.md)|Demonstra os atributos definidos pelo usuário.|  
|[Diretiva \#using](../preprocessor/hash-using-directive-cpp.md)|Importa os assemblies externos.|  
|[A Documentação XML](../ide/xml-documentation-visual-cpp.md)|Explica a documentação do código com base em XML usando [\/doc \(Processar comentários de documentação\)](../build/reference/doc-process-documentation-comments-c-cpp.md)|  
  
## Consulte também  
 [Programação do .NET com o C \+ \+ \/ CLI \(Visual C\+\+\)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)   
 [Nativo e interoperabilidade .NET](../Topic/Native%20and%20.NET%20Interoperability.md)