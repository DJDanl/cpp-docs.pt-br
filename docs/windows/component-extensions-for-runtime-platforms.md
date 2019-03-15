---
title: Extensões de componentes para .NET e UWP
ms.date: 10/12/2018
ms.topic: reference
helpviewer_keywords:
- what's new [C++], keywords
- what's new [C++], language features
- C++, keywords
- keywords [C++]
- Managed Extensions for C++, replacement syntax
ms.assetid: 1e400ee6-3ac9-4910-a608-9d3d5993e423
ms.openlocfilehash: e9586244c9e2293ba6b484efb158fc3a2529c0ea
ms.sourcegitcommit: faa42c8a051e746d99dcebe70fd4bbaf3b023ace
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/15/2019
ms.locfileid: "57814482"
---
# <a name="component-extensions-for-net-and-uwp"></a>Extensões de componentes para .NET e UWP

O padrão C++ permite que fornecedores de compilador fornecer extensões não padrão para a linguagem. A Microsoft fornece extensões para ajudá-lo a se conectar a C++ nativa de código para código que é executado no .NET Framework ou a Universal Windows Platform (UWP). As extensões do .NET são chamadas C + + c++ CLI e para gerar código que é executado no .NET gerenciado o ambiente de execução que é chamado o tempo de execução de linguagem comum (CLR). As extensões UWP são chamadas C + + c++ /CLI CX e eles produzem código de máquina nativo.

> [!NOTE]
> Para novos aplicativos, é recomendável usar C + + c++ /CLI WinRT em vez de C + + c++ /CLI CX. C + + c++ /CLI WinRT é uma nova, o padrão C + + 17 projeção de linguagem para APIs do Windows Runtime. Continuaremos a dar suporte a C + + c++ /CLI CX e WRL, mas altamente recomendável que usem novos aplicativos C + + c++ /CLI WinRT. Para obter mais informações, consulte [C + + c++ /CLI WinRT](https://docs.microsoft.com/windows/uwp/cpp-and-winrt-apis/index).

### <a name="two-runtimes-one-set-of-extensions"></a>Dois tempos de execução, um conjunto de extensões

C + + c++ CLI estende o padrão ISO/ANSI C++ e é definido em Ecma C + c++ padrão da CLI. Para obter mais informações, consulte [programação do .NET com C + + c++ CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md).

O C + + c++ /CLI extensões CX são um subconjunto de C + + c++ CLI. Embora a sintaxe de extensão é idêntica na maioria dos casos, o código que é gerado depende se você especificar o `/ZW` opção de compilador para que se destinam à UWP, ou o `/clr` opção ao destino .NET. Essas opções são definidas automaticamente quando você usa o Visual Studio para criar um projeto.

## <a name="data-type-keywords"></a>Palavras-chave de tipo de dados

Incluem as extensões de linguagem *agregar as palavras-chave*, que consistem em dois tokens separados por espaço em branco. Os tokens podem ter um significado quando são usadas separadamente e outro significado quando eles são usados juntos. Por exemplo, a palavra "ref" é um identificador comum, e a palavra "class" é uma palavra-chave que declara uma classe nativa. Mas quando essas palavras são combinadas para formar **classe ref**, a palavra-chave agregada resultante declara uma entidade que é conhecida como um *classe runtime*.

As extensões também incluem *contextual* palavras-chave. Uma palavra-chave é tratada como contextual, dependendo do tipo de instrução que contém e seu posicionamento na declaração. Por exemplo, o token "property" pode ser um identificador, ou ele pode declarar um tipo especial de membro de classe pública.

A tabela a seguir lista as palavras-chave na extensão de linguagem C++.

|Palavra-chave|Sensíveis ao contexto|Finalidade|Referência|
|-------------|-----------------------|-------------|---------------|
|**classe ref**<br /><br /> **estrutura ref**|Não|Declara uma classe.|[Classes e Structs](../windows/classes-and-structs-cpp-component-extensions.md)|
|**classe de valor**<br /><br /> **estrutura de valor**|Não|Declara uma classe de valor.|[Classes e Structs](../windows/classes-and-structs-cpp-component-extensions.md)|
|**classe de interface**<br /><br /> **interface struct**|Não|Declara uma interface.|[classe de interface](../windows/interface-class-cpp-component-extensions.md)|
|**classe de enum**<br /><br /> **Enum struct**|Não|Declara uma enumeração.|[classe de enum](../windows/enum-class-cpp-component-extensions.md)|
|**propriedade**|Sim|Declara uma propriedade.|[propriedade](../windows/property-cpp-component-extensions.md)|
|**delegate**|Sim|Declara um delegado.|[delegate (C++/CLI e C++/CX)](../windows/delegate-cpp-component-extensions.md)|
|**event**|Sim|Declara um evento.|[event](../windows/event-cpp-component-extensions.md)|

## <a name="override-specifiers"></a>Especificadores de Substituição

Você pode usar as seguintes palavras-chave para qualificar o comportamento de substituição para derivação. Embora o **novo** palavra-chave não é uma extensão do C++, ele está listado aqui, porque ele pode ser usado em um contexto adicional. Alguns especificadores também são válidas para programação nativa. Para obter mais informações, confira [Como: Declarar especificadores de substituição em compilações nativas (C + + / CLI)](../dotnet/how-to-declare-override-specifiers-in-native-compilations-cpp-cli.md).

|Palavra-chave|Sensíveis ao contexto|Finalidade|Referência|
|-------------|-----------------------|-------------|---------------|
|**abstract**|Sim|Indica que as funções ou classes são abstratas.|[abstract](../windows/abstract-cpp-component-extensions.md)|
|**new**|Não|Indica que uma função não é uma substituição de uma versão da classe base.|[novo (novo slot em vtable)](../windows/new-new-slot-in-vtable-cpp-component-extensions.md)|
|**override**|Sim|Indica que um método deve ser uma substituição de uma versão de classe base.|[override](../windows/override-cpp-component-extensions.md)|
|**sealed**|Sim|Impede que as classes que estão sendo usadas como classes base.|[sealed](../windows/sealed-cpp-component-extensions.md)|

## <a name="keywords-for-generics"></a>Palavras-chave para genéricos

As seguintes palavras-chave foram adicionadas para dar suporte a tipos genéricos. Para obter mais informações, consulte [Genéricos](../windows/generics-cpp-component-extensions.md).

|Palavra-chave|Sensíveis ao contexto|Finalidade|
|-------------|-----------------------|-------------|
|**generic**|Não|Declara um tipo genérico.|
|**where**|Sim|Especifica as restrições que são aplicadas a um parâmetro de tipo genérico.|

## <a name="miscellaneous-keywords"></a>Diversas palavras-chave

As seguintes palavras-chave foram adicionadas às extensões do C++.

|Palavra-chave|Sensíveis ao contexto|Finalidade|Referência|
|-------------|-----------------------|-------------|---------------|
|**finally**|Sim|Indica o comportamento de handlings de exceção padrão.|[Tratamento de Exceção](../windows/exception-handling-cpp-component-extensions.md)|
|**for each, in**|Não|Enumera os elementos de uma coleção.|[for each, in](../dotnet/for-each-in.md)|
|**gcnew**|Não|Aloca tipos no heap coletado como lixo. Use em vez de **novos** e **excluir**.|[ref new, gcnew](../windows/ref-new-gcnew-cpp-component-extensions.md)|
|**ref new**|Sim|Aloca um tipo de tempo de execução do Windows. Use em vez de **novos** e **excluir**.|[ref new, gcnew](../windows/ref-new-gcnew-cpp-component-extensions.md)|
|**initonly**|Sim|Indica que um membro só pode ser inicializado na declaração ou em um construtor estático.|[initonly (C++/CLI)](../dotnet/initonly-cpp-cli.md)|
|**literal**|Sim|Cria uma variável de literal.|[literal](../windows/literal-cpp-component-extensions.md)|
|**nullptr**|Não|Indica que um identificador ou ponteiro não faz referência a um objeto.|[nullptr](../windows/nullptr-cpp-component-extensions.md)|

## <a name="template-constructs"></a>Construções de modelo

As seguintes construções de linguagem são implementadas como modelos, em vez de como as palavras-chave. Se você especificar o `/ZW` opção de compilador, eles são definidos na `lang` namespace. Se você especificar o `/clr` opção de compilador, eles são definidos na `cli` namespace.

|Palavra-chave|Finalidade|Referência|
|-------------|-------------|---------------|
|**array**|Declara uma matriz.|[Matrizes](../windows/arrays-cpp-component-extensions.md)|
|**interior_ptr**|(CLR) Pontos de dados em um tipo de referência.|[interior_ptr (C++/CLI)](../windows/interior-ptr-cpp-cli.md)|
|**pin_ptr**|(CLR) Aponta para os tipos de referência CLR para suprimir temporariamente o sistema de coleta de lixo.|[pin_ptr (C++/CLI)](../windows/pin-ptr-cpp-cli.md)|
|**safe_cast**|Determina e executa o método de conversão ideal para um tipo de tempo de execução.|[safe_cast](../windows/safe-cast-cpp-component-extensions.md)|
|**typeid**|(CLR) Recupera um <xref:System.Type?displayProperty=fullName> objeto que descreve o tipo de dado ou objeto.|[typeid](../windows/typeid-cpp-component-extensions.md)|

## <a name="declarators"></a>Declaradores

Os declaradores de tipo a seguir instruem o tempo de execução para gerenciar automaticamente o tempo de vida e a exclusão de objetos alocados.

|Operador|Finalidade|Referência|
|--------------|-------------|---------------|
|`^`|Declara um identificador para um objeto; ou seja, um ponteiro para um objeto de tempo de execução do Windows ou do CLR será excluído automaticamente quando ele não é mais utilizável.|[Operador Handle to Object (^)](../windows/handle-to-object-operator-hat-cpp-component-extensions.md)|
|`%`|Declara uma referência de rastreamento; ou seja, uma referência a um objeto de tempo de execução do Windows ou do CLR que será excluído automaticamente quando ele não é mais utilizável.|[Operador de referência de acompanhamento](../windows/tracking-reference-operator-cpp-component-extensions.md)|

## <a name="additional-constructs-and-related-topics"></a>Outras construções e tópicos relacionados

Esta seção lista as construções de programação adicionais e tópicos que pertencem ao CLR.

|Tópico|Descrição|
|-----------|-----------------|
|[__identifier (C++/CLI)](../windows/identifier-cpp-cli.md)|(Tempo de execução do Windows e CLR) Permite o uso de palavras-chave como identificadores.|
|[Listas de argumentos variáveis (...) (C++/CLI)](../windows/variable-argument-lists-dot-dot-dot-cpp-cli.md)|(Tempo de execução do Windows e CLR) Permite que uma função para obter um número variável de argumentos.|
|[Equivalentes do .NET Framework aos tipos nativos do C++ (C++/CLI)](../dotnet/dotnet-framework-equivalents-to-cpp-native-types-cpp-cli.md)|Lista os tipos CLR que são usados no lugar de tipos integrais do C++.|
|[appdomain](../cpp/appdomain.md) **__declspec** modifier|**declspec** modificador que exige a existem de variáveis estáticas e globais por appdomain.|
|[Conversões C-Style com /clr (C + + / CLI)](../windows/c-style-casts-with-clr-cpp-cli.md)|Descreve como conversões de estilo C são interpretados.|
|[clrcall](../cpp/clrcall.md) convenção de chamada|Indica a convenção de chamada compatíveis com CLR.|
|`__cplusplus_cli`|[Macros predefinidas](../preprocessor/predefined-macros.md)|
|[Atributos personalizados](../windows/custom-attributes-cpp.md)|Descreve como definir seus próprios atributos CLR.|
|[Tratamento de Exceção](../windows/exception-handling-cpp-component-extensions.md)|Fornece uma visão geral de manipulação de exceção.|
|[Substituições explícitas](../windows/explicit-overrides-cpp-component-extensions.md)|Demonstra como funções de membro podem substituir membros arbitrários.|
|[Assemblies amigáveis (C++)](../dotnet/friend-assemblies-cpp.md)|Discute como um assembly de cliente pode acessar todos os tipos em um componente de assembly.|
|[Conversão boxing](../windows/boxing-cpp-component-extensions.md)|Demonstra as condições nas quais valores de tipos de conversão boxing são realizados.|
|[Suporte a compilador para características de tipo](../windows/compiler-support-for-type-traits-cpp-component-extensions.md)|Discute como detectar as características de tipos em tempo de compilação.|
|[gerenciado, não gerenciado](../preprocessor/managed-unmanaged.md) pragmas|Demonstra como gerenciadas e funções podem coexistir no mesmo módulo.|
|[process](../cpp/process.md) **__declspec** modifier|**declspec** modificador que rege a maneira que as variáveis globais e estáticas existem por processo.|
|[Reflexão (C++/CLI)](../dotnet/reflection-cpp-cli.md)|Demonstra a versão do CLR de informações de tipo de tempo de execução.|
|[Cadeia de caracteres](../windows/string-cpp-component-extensions.md)|Discute a conversão de compilador de literais de cadeia de caracteres para <xref:System.String>.|
|[Encaminhamento de tipo (C++/CLI)](../windows/type-forwarding-cpp-cli.md)|Permite a movimentação de um tipo em um assembly de envio para outro assembly para que o código do cliente não precisa ser recompilado.|
|[Atributos definidos pelo usuário](../windows/user-defined-attributes-cpp-component-extensions.md)|Demonstra os atributos definidos pelo usuário.|
|[Diretiva #using](../preprocessor/hash-using-directive-cpp.md)|Importa os assemblies externos.|
|[Documentação XML](../build/reference/xml-documentation-visual-cpp.md)|Explica a documentação de código com base em XML usando [/doc (processar comentários de documentação) (C/C++)](../build/reference/doc-process-documentation-comments-c-cpp.md)|

## <a name="see-also"></a>Consulte também

[Programação do .NET com C++/CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)<br/>
[Interoperabilidade entre .NET e nativo](../dotnet/native-and-dotnet-interoperability.md)