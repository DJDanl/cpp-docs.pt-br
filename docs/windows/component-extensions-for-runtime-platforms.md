---
title: Extensões de componentes para plataformas de tempo de execução | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- what's new [C++], keywords
- what's new [C++], language features
- Visual C++, keywords
- keywords [C++]
- Managed Extensions for C++, replacement syntax
ms.assetid: 1e400ee6-3ac9-4910-a608-9d3d5993e423
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: e60a1285f54de6b1cbfe311d4d9cbbc547785176
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
---
# <a name="component-extensions-for-runtime-platforms"></a>Extensões de componente para plataformas de tempo de execução
Visual C++ fornece extensões de linguagem para ajudar você programe em plataformas de tempo de execução. Usando C + + CX, você pode programar aplicativos de plataforma Universal do Windows e componentes que são compilados para código nativo. Embora você possa criar aplicativos de plataforma Universal do Windows por programação diretamente em interfaces COM tempo de execução do Windows, usando C + + CX, você pode trabalhar com construtores, exceções e outras linguagens de programação de C++ moderno. Para habilitar a programação de C++ em um ambiente de execução gerenciado na plataforma .NET, você pode usar C + + CLI.  
  
 **Dois tempos de execução, um conjunto de extensões**  
  
 C + + CX é um subconjunto de C + + CLI. Para as extensões que são comuns a C + + CX e C + + CLI, a semântica depende se você está visando o common language runtime (CLR) ou o tempo de execução do Windows. Para compilar seu aplicativo para ser executado no tempo de execução do Windows, especifique o **/ZW** opção de compilador. Para compilá-lo para ser executado no CLR, especifique o **/clr** opção de compilador. Essas opções são definidas automaticamente quando você usa o Visual Studio para criar um projeto.  
  
 Para obter mais informações sobre como criar aplicativos de plataforma Universal do Windows em C++, consulte [aplicativos roteiro para Windows Runtime usando C++](http://msdn.microsoft.com/library/windows/apps/hh700360.aspx).  
  
 C + + CLI estende o padrão ANSI/ISO C++ e é definido em Ecma C + + CLI padrão. Para obter mais informações, consulte [programação .NET com C + + CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md).  
  
## <a name="data-type-keywords"></a>Palavras-chave de tipo de dados  
 As extensões de linguagem incluem *agregar as palavras-chave*, que são palavras-chave que consistem em dois tokens separados por espaços em branco. Os tokens podem ter um significado quando eles são usados separadamente e o significado de outro quando eles são usados juntos. Por exemplo, a palavra "ref" é um identificador comum, e a palavra "class" é uma palavra-chave que declara uma classe nativo. Mas quando essas palavras são combinadas para formar `ref class`, a palavra-chave agregada resultante declara uma entidade que é conhecida como um *classe runtime*.  
  
 As extensões também incluem *contextual* palavras-chave. Uma palavra-chave é tratada como contextual dependendo do tipo de instrução que contém e seu posicionamento na instrução. Por exemplo, o token "property" pode ser um identificador, ou ele pode declarar um tipo especial de membro de classe pública.  
  
 A tabela a seguir lista as palavras-chave na extensão de linguagem do C++.  
  
|Palavra-chave|Sensíveis ao contexto|Finalidade|Referência|  
|-------------|-----------------------|-------------|---------------|  
|`ref class`<br /><br /> `ref struct`|Não|Declara uma classe.|[Classes e Structs](../windows/classes-and-structs-cpp-component-extensions.md)|  
|`value class`<br /><br /> `value struct`|Não|Declara uma classe de valor.|[Classes e Structs](../windows/classes-and-structs-cpp-component-extensions.md)|  
|`interface class`<br /><br /> `interface struct`|Não|Declara uma interface.|[classe de interface](../windows/interface-class-cpp-component-extensions.md)|  
|`enum class`<br /><br /> `enum struct`|Não|Declara uma enumeração.|[classe de enum](../windows/enum-class-cpp-component-extensions.md)|  
|`property`|Sim|Declara uma propriedade.|[propriedade](../windows/property-cpp-component-extensions.md)|  
|`delegate`|Sim|Declara um delegate.|[delegate (Extensões de componentes do C++)](../windows/delegate-cpp-component-extensions.md)|  
|`event`|Sim|Declara um evento.|[event](../windows/event-cpp-component-extensions.md)|  
  
## <a name="override-specifiers"></a>Especificadores de Substituição  
 Você pode usar as seguintes palavras-chave para qualificar o comportamento de substituição para derivação. Embora o `new` palavra-chave não é uma extensão do C++, ele é listado aqui porque ele pode ser usado em um contexto adicional. Alguns especificadores também são válidas para programação nativa. Para obter mais informações, consulte [como: declarar especificadores de substituição em compilações nativas (C + + CLI)](../dotnet/how-to-declare-override-specifiers-in-native-compilations-cpp-cli.md).  
  
|Palavra-chave|Sensíveis ao contexto|Finalidade|Referência|  
|-------------|-----------------------|-------------|---------------|  
|`abstract`|Sim|Indica que funções ou classes abstratas.|[abstract](../windows/abstract-cpp-component-extensions.md)|  
|`new`|Não|Indica que uma função não é uma substituição de uma versão de classe base.|[novo (novo slot em vtable)](../windows/new-new-slot-in-vtable-cpp-component-extensions.md)|  
|`override`|Sim|Indica que um método deve ser uma substituição de uma versão de classe base.|[override](../windows/override-cpp-component-extensions.md)|  
|`sealed`|Sim|Evita que classes sejam usadas como classes base.|[sealed](../windows/sealed-cpp-component-extensions.md)|  
  
## <a name="keywords-for-generics"></a>Palavras-chave para genéricos  
 As seguintes palavras-chave foram adicionadas para oferecer suporte a tipos genéricos. Para obter mais informações, consulte [Genéricos](../windows/generics-cpp-component-extensions.md).  
  
|Palavra-chave|Sensíveis ao contexto|Finalidade|  
|-------------|-----------------------|-------------|  
|`generic`|Não|Declara um tipo genérico.|  
|`where`|Sim|Especifica as restrições que são aplicadas a um parâmetro de tipo genérico.|  
  
## <a name="miscellaneous-keywords"></a>Palavras-chave diversas  
 As seguintes palavras-chave foram adicionadas às extensões do C++.  
  
|Palavra-chave|Sensíveis ao contexto|Finalidade|Referência|  
|-------------|-----------------------|-------------|---------------|  
|`finally`|Sim|Indica o comportamento de handlings de exceção padrão.|[Tratamento de Exceção](../windows/exception-handling-cpp-component-extensions.md)|  
|`for each, in`|Não|Enumera os elementos de uma coleção.|[for each, in](../dotnet/for-each-in.md)|  
|`gcnew`|Não|Aloca tipos no heap coletado como lixo. Usar em vez de `new` e `delete`.|[gcnew novo ref](../windows/ref-new-gcnew-cpp-component-extensions.md)|  
|`ref new`|Sim|Aloca um tipo de tempo de execução do Windows. Usar em vez de `new` e `delete`.|[gcnew novo ref](../windows/ref-new-gcnew-cpp-component-extensions.md)|  
|`initonly`|Sim|Indica que um membro só pode ser inicializado na declaração ou em um construtor estático.|[initonly (C++/CLI)](../dotnet/initonly-cpp-cli.md)|  
|`literal`|Sim|Cria uma variável de literal.|[Literal](../windows/literal-cpp-component-extensions.md)|  
|`nullptr`|Não|Indica que um identificador ou ponteiro não faz referência a um objeto.|[nullptr](../windows/nullptr-cpp-component-extensions.md)|  
  
## <a name="template-constructs"></a>Construções de modelo  
 As seguintes construções de linguagem são implementadas como modelos, em vez de como palavras-chave. Se você especificar o **/ZW** opção de compilador são definidas no `lang` namespace. Se você especificar o **/clr** opção de compilador são definidas no `cli` namespace.  
  
|Palavra-chave|Finalidade|Referência|  
|-------------|-------------|---------------|  
|`array`|Declara uma matriz.|[Matrizes](../windows/arrays-cpp-component-extensions.md)|  
|`interior_ptr`|(CLR) Pontos de dados em um tipo de referência.|[interior_ptr (C++/CLI)](../windows/interior-ptr-cpp-cli.md)|  
|`pin_ptr`|(CLR) Pontos para tipos de referência do CLR para suprimir temporariamente o sistema de coleta de lixo.|[pin_ptr (C++/CLI)](../windows/pin-ptr-cpp-cli.md)|  
|`safe_cast`|Determina e executa o método de conversão ideal para um tipo de tempo de execução.|[Safe_cast](../windows/safe-cast-cpp-component-extensions.md)|  
|`typeid`|(CLR) Recupera um <xref:System.Type?displayProperty=fullName> objeto que descreve o tipo especificado ou o objeto.|[TypeId](../windows/typeid-cpp-component-extensions.md)|  
  
## <a name="declarators"></a>Declaradores  
 As seguir declaradores tipo instruem o tempo de execução para gerenciar automaticamente o tempo de vida e a exclusão de objetos alocados.  
  
|Operador|Finalidade|Referência|  
|--------------|-------------|---------------|  
|`^`|Declara um identificador para um objeto; ou seja, um ponteiro para um objeto de tempo de execução do Windows ou CLR é excluído automaticamente quando ele não será mais utilizável.|[Operador Handle to Object (^)](../windows/handle-to-object-operator-hat-cpp-component-extensions.md)|  
|`%`|Declara uma referência de rastreamento; ou seja, uma referência a um objeto de tempo de execução do Windows ou CLR é excluído automaticamente quando ele não será mais utilizável.|[Operador de referência de rastreamento](../windows/tracking-reference-operator-cpp-component-extensions.md)|  
  
## <a name="additional-constructs-and-related-topics"></a>Outras construções e tópicos relacionados  
 Esta seção lista as construções de programação adicionais e tópicos que pertencem ao CLR.  
  
|Tópico|Descrição|  
|-----------|-----------------|  
|[__identifier (C++/CLI)](../windows/identifier-cpp-cli.md)|(Tempo de execução do Windows e CLR) Habilita o uso de palavras-chave como identificadores.|  
|[Listas de argumentos variáveis (...) (C++/CLI)](../windows/variable-argument-lists-dot-dot-dot-cpp-cli.md)|(Tempo de execução do Windows e CLR) Permite que uma função que tenha um número variável de argumentos.|  
|[Equivalentes do .NET Framework aos tipos nativos do C++ (C++/CLI)](../dotnet/dotnet-framework-equivalents-to-cpp-native-types-cpp-cli.md)|Lista os tipos CLR que são usados no lugar de tipos integrais do C++.|  
|[AppDomain](../cpp/appdomain.md) `__declspec` modificador|`__declspec` modificador que exige a existem de variáveis globais e estáticos por appdomain.|  
|[Conversões do estilo C com /clr (C + + CLI)](../windows/c-style-casts-with-clr-cpp-cli.md)|Descreve como conversões do estilo C são interpretados.|  
|[clrcall](../cpp/clrcall.md) convenção de chamada|Indica a convenção de chamada CLR compatível.|  
|`__cplusplus_cli`|[Macros predefinidas](../preprocessor/predefined-macros.md)|  
|[Atributos personalizados](../windows/custom-attributes-cpp.md)|Descreve como definir seus próprios atributos CLR.|  
|[Tratamento de Exceção](../windows/exception-handling-cpp-component-extensions.md)|Fornece uma visão geral de manipulação de exceção.|  
|[Substituições explícitas](../windows/explicit-overrides-cpp-component-extensions.md)|Demonstra como funções de membro podem substituir membros arbitrários.|  
|[Assemblies amigáveis (C++)](../dotnet/friend-assemblies-cpp.md)|Discute como um assembly de cliente pode acessar todos os tipos em um componente de assembly.|  
|[Conversão boxing](../windows/boxing-cpp-component-extensions.md)|Demonstra as condições em quais valores de tipos são demarcados.|  
|[Suporte de compilador de traços de tipo](../windows/compiler-support-for-type-traits-cpp-component-extensions.md)|Discute como detectar características de tipos em tempo de compilação.|  
|[gerenciado, não gerenciado](../preprocessor/managed-unmanaged.md) pragmas|Demonstra como gerenciadas e funções podem coexistir no mesmo módulo.|  
|[processo](../cpp/process.md) `__declspec` modificador|`__declspec` modificador que exige a existem de variáveis globais e estáticos por processo.|  
|[Reflexão (C++/CLI)](../dotnet/reflection-cpp-cli.md)|Demonstra a versão CLR de informações de tipo de tempo de execução.|  
|[Cadeia de caracteres](../windows/string-cpp-component-extensions.md)|Discute a conversão de compilador de literais de cadeia de caracteres para <xref:System.String>.|  
|[Encaminhamento de tipo (C++/CLI)](../windows/type-forwarding-cpp-cli.md)|Permite a movimentação de um tipo em um assembly de envio para outro conjunto para que o código do cliente não precisa ser recompilado.|  
|[Atributos definidos pelo usuário](../windows/user-defined-attributes-cpp-component-extensions.md)|Demonstra os atributos definidos pelo usuário.|  
|[Diretiva #using](../preprocessor/hash-using-directive-cpp.md)|Importa assemblies externos.|  
|[Documentação XML](../ide/xml-documentation-visual-cpp.md)|Explica a documentação de código baseado em XML usando [/doc (processar comentários de documentação) (C/C++)](../build/reference/doc-process-documentation-comments-c-cpp.md)|  
  
## <a name="see-also"></a>Consulte também  
 [Programação do .NET com C + + CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)   
 [Interoperabilidade entre .NET e nativo](../dotnet/native-and-dotnet-interoperability.md)