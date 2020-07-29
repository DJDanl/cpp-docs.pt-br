---
title: Extensões de componentes para .NET e UWP
ms.date: 10/12/2018
ms.topic: overview
helpviewer_keywords:
- what's new [C++], keywords
- what's new [C++], language features
- C++, keywords
- keywords [C++]
- Managed Extensions for C++, replacement syntax
ms.assetid: 1e400ee6-3ac9-4910-a608-9d3d5993e423
ms.openlocfilehash: aa6e5d1ea7d1bc2d7ebfaf07c7c9f808b37e9804
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87219762"
---
# <a name="component-extensions-for-net-and-uwp"></a>Extensões de componentes para .NET e UWP

O padrão C++ permite que os fornecedores de compiladores forneçam extensões não padrão para a linguagem. A Microsoft fornece extensões para ajudar você a conectar o código C++ nativo ao código executado no .NET Framework ou na Plataforma Universal do Windows (UWP). As extensões .NET são chamadas de C++/CLI e geram um código que é executado no ambiente de execução gerenciado pelo .NET, chamado de Common Language Runtime (CLR). As extensões da UWP são chamadas de C++ /CX e geram um código de máquina nativo.

> [!NOTE]
> Para novos aplicativos, recomendamos o uso de C++/WinRT em vez de C++/CX. C++/WinRT é uma nova projeção de linguagem padrão C++17 para APIs do Windows Runtime. Continuaremos a dar suporte a C++/CX e WRL, mas recomendamos que os novos aplicativos usem o C++/WinRT. Para obter mais informações, consulte [C++/WinRT](/windows/uwp/cpp-and-winrt-apis/index).

### <a name="two-runtimes-one-set-of-extensions"></a>Dois runtimes, um conjunto de extensões

A C++/CLI amplia o padrão ISO/ANSI de C++ e é definida sob o padrão Ecma C++/CLI. Saiba mais em [Programação do .NET C++/CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md).

As extensões C++/CX são um subconjunto de C++/CLI. Embora a sintaxe da extensão seja idêntica na maioria dos casos, o código gerado depende de você especificar a opção de compilador `/ZW` para o UWP de destino ou a opção `/clr` para o .NET de destino. Essas opções são definidas automaticamente quando você usa o Visual Studio para criar um projeto.

## <a name="data-type-keywords"></a>Palavras-chave do tipo de dados

As extensões de linguagem incluem *palavras-chave agregadas*, que consistem em dois tokens separados por espaço em branco. Os tokens podem ter um significado quando são usados ​​separadamente e outro significado quando são usados ​​juntos. Por exemplo, a palavra "ref" é um identificador comum e a palavra "class" é uma palavra-chave que declara uma classe nativa. Mas quando essas palavras são combinadas para formar **ref class**, a palavra-chave agregada resultante declara uma entidade que é conhecida como *classe de runtime*.

As extensões também incluem palavras-chave *contextuais*. Uma palavra-chave é tratada como contextual dependendo do tipo de instrução que a contém e de seu posicionamento nessa instrução. Por exemplo, o token "propriedade" pode ser um identificador ou pode declarar um tipo especial de membro de classe pública.

A tabela a seguir lista palavras-chave na extensão de linguagem C++.

|Palavra-chave|Contextual|Finalidade|Referência|
|-------------|-----------------------|-------------|---------------|
|**ref class**<br /><br /> **ref struct**|Não|Declara uma classe.|[Classes e structs](classes-and-structs-cpp-component-extensions.md)|
|**value class**<br /><br /> **estrutura de valor**|Não|Declara uma classe de valor.|[Classes e structs](classes-and-structs-cpp-component-extensions.md)|
|**Classe de interface**<br /><br /> **interface struct**|Não|Declara uma interface.|[Classe de interface](interface-class-cpp-component-extensions.md)|
|**Classe enum**<br /><br /> **enum struct**|Não|Declara uma enumeração.|[Classe enum](enum-class-cpp-component-extensions.md)|
|**`property`**|Sim|Declara uma propriedade.|[property](property-cpp-component-extensions.md)|
|**delegate**|Sim|Declara um delegado.|[delegate (C++/CLI e C++/CX)](delegate-cpp-component-extensions.md)|
|**event**|Sim|Declara um evento.|[event](event-cpp-component-extensions.md)|

## <a name="override-specifiers"></a>Especificadores de Substituição

Você pode usar as seguintes palavras-chave para qualificar o comportamento de substituição para derivação. Embora a **`new`** palavra-chave não seja uma extensão do C++, ela é listada aqui porque pode ser usada em um contexto adicional. Alguns especificadores também são válidos para programação nativa. Para obter mais informações, consulte [como: declarar especificadores de substituição em compilações nativas (C++/CLI)](../dotnet/how-to-declare-override-specifiers-in-native-compilations-cpp-cli.md).

|Palavra-chave|Contextual|Finalidade|Referência|
|-------------|-----------------------|-------------|---------------|
|**resume**|Sim|Indica que as funções ou classes são abstratas.|[resume](abstract-cpp-component-extensions.md)|
|**`new`**|Não|Indica que uma função não é uma substituição de uma versão de classe base.|[novo (novo slot em vtable)](new-new-slot-in-vtable-cpp-component-extensions.md)|
|**override**|Sim|Indica que um método deve ser uma substituição de uma versão de classe base.|[override](override-cpp-component-extensions.md)|
|**sealed**|Sim|Impede que classes sejam usadas como classes base.|[sealed](sealed-cpp-component-extensions.md)|

## <a name="keywords-for-generics"></a>Palavras-chave para genéricos

As seguintes palavras-chave foram adicionadas para serem compatíveis com tipos genéricos. Para obter mais informações, consulte [Genéricos](generics-cpp-component-extensions.md).

|Palavra-chave|Contextual|Finalidade|
|-------------|-----------------------|-------------|
|**genérica**|Não|Declara um tipo genérico.|
|**where**|Sim|Especifica as restrições aplicadas a um parâmetro de tipo genérico.|

## <a name="miscellaneous-keywords"></a>Palavras-chave diversas

As seguintes palavras-chave foram adicionadas às extensões C++.

|Palavra-chave|Contextual|Finalidade|Referência|
|-------------|-----------------------|-------------|---------------|
|**disso**|Sim|Indica o comportamento de tratamento de exceção padrão.|[Tratamento de exceção](exception-handling-cpp-component-extensions.md)|
|**for each, in**|Não|Enumera elementos de uma coleção.|[for each, in](../dotnet/for-each-in.md)|
|**gcnew**|Não|Aloca os tipos no heap coletado do lixo. Use em vez de **`new`** e **`delete`** .|[ref new, gcnew](ref-new-gcnew-cpp-component-extensions.md)|
|**ref new**|Sim|Aloca um tipo do Windows Runtime. Use em vez de **`new`** e **`delete`** .|[ref new, gcnew](ref-new-gcnew-cpp-component-extensions.md)|
|**initonly**|Sim|Indica que um membro só pode ser inicializado na declaração ou em um construtor estático.|[InitOnly (C++/CLI)](../dotnet/initonly-cpp-cli.md)|
|**literal**|Sim|Cria uma variável literal.|[literal](literal-cpp-component-extensions.md)|
|**`nullptr`**|Não|Indica que um identificador ou ponteiro não aponta para um objeto.|[nullptr](nullptr-cpp-component-extensions.md)|

## <a name="template-constructs"></a>Construções de modelo

As seguintes construções de linguagem são implementadas como modelos, em vez de como palavras-chave. Se você especificar a opção de compilador `/ZW`, eles serão definidos no namespace `lang`. Se você especificar a opção de compilador `/clr`, eles serão definidos no namespace `cli`.

|Palavra-chave|Finalidade|Referência|
|-------------|-------------|---------------|
|**array**|Declara uma matriz.|[matrizes](arrays-cpp-component-extensions.md)|
|**interior_ptr**|(Somente CLR) Aponta para dados em um tipo de referência.|[interior_ptr (C++/CLI)](interior-ptr-cpp-cli.md)|
|**pin_ptr**|(Apenas CLR) Aponta para os tipos de referência do CLR para suprimir temporariamente o sistema de coleta de lixo.|[pin_ptr (C++/CLI)](pin-ptr-cpp-cli.md)|
|**safe_cast**|Determina e executa o método de conversão ideal para um tipo de runtime.|[safe_cast](safe-cast-cpp-component-extensions.md)|
|**`typeid`**|(Somente CLR) Recupera um objeto <xref:System.Type?displayProperty=fullName> que descreve o tipo ou objeto fornecido.|[identificação](typeid-cpp-component-extensions.md)|

## <a name="declarators"></a>Declaradores

Os seguintes declaradores de tipo instruem o runtime a gerenciar automaticamente o tempo de vida e a exclusão de objetos alocados.

|Operador|Finalidade|Referência|
|--------------|-------------|---------------|
|`^`|Declara um identificador para um objeto; ou seja, um ponteiro para um objeto do Windows Runtime ou do CLR que é automaticamente excluído quando não puder mais ser usado.|[Identificador para operador de objeto (^)](handle-to-object-operator-hat-cpp-component-extensions.md)|
|`%`|Declara uma referência de companhamento; ou seja, uma referência a um objeto do Windows Runtime ou do CLR que é automaticamente excluído quando não puder mais ser usado.|[Operador de referência de rastreamento](tracking-reference-operator-cpp-component-extensions.md)|

## <a name="additional-constructs-and-related-topics"></a>Construções adicionais e tópicos relacionados

Esta seção lista construções de programação adicionais e tópicos que pertencem ao CLR.

|Tópico|Descrição|
|-----------|-----------------|
|[__identifier (C++/CLI)](identifier-cpp-cli.md)|(Windows Runtime e CLR) Permite o uso de palavras-chave como identificadores.|
|[Listas de argumentos variáveis (...) (C++/CLI)](variable-argument-lists-dot-dot-dot-cpp-cli.md)|(Windows Runtime e CLR) Permite que uma função obtenha um número variável de argumentos.|
|[.NET Framework equivalentes a tipos nativos C++ (C++/CLI)](../dotnet/dotnet-framework-equivalents-to-cpp-native-types-cpp-cli.md)|Lista os tipos de CLR que são usados ​​no lugar dos tipos integrais de C++.|
|[AppDomain](../cpp/appdomain.md) **`__declspec`** privacidade|**`__declspec`** modificador que exige que variáveis estáticas e globais existam por AppDomain.|
|[Conversões de Estilo C-Style com /clr (C++/CLI)](c-style-casts-with-clr-cpp-cli.md)|Descreve como as conversões C-Style são interpretadas.|
|Convenção de chamada [__clrcall](../cpp/clrcall.md)|Indica a convenção de chamada compatível com CLR.|
|`__cplusplus_cli`|[Macros predefinidas](../preprocessor/predefined-macros.md)|
|[Atributos personalizados](user-defined-attributes-cpp-component-extensions.md)|Descreve como definir seus próprios atributos CLR.|
|[Tratamento de exceção](exception-handling-cpp-component-extensions.md)|Fornece uma visão geral do tratamento de exceção.|
|[Substituições explícitas](explicit-overrides-cpp-component-extensions.md)|Demonstra como as funções de membro podem substituir membros arbitrários.|
|[Assemblies Friend (C++)](../dotnet/friend-assemblies-cpp.md)|Discute como um assembly de cliente pode acessar todos os tipos em um componente de assembly.|
|[Conversão boxing](boxing-cpp-component-extensions.md)|Demonstra as condições nas quais os tipos de valores são convertidos.|
|[Suporte do compilador para características de tipo](compiler-support-for-type-traits-cpp-component-extensions.md)|Discute como detectar características de tipos em tempo de compilação.|
|pragmas [gerenciados e não](../preprocessor/managed-unmanaged.md) gerenciados|Demonstra como funções gerenciadas e não gerenciadas podem coexistir no mesmo módulo.|
|[processo](../cpp/process.md) **`__declspec`** do privacidade|**`__declspec`** modificador que exige que variáveis estáticas e globais existam por processo.|
|[Reflexão (C++/CLI)](../dotnet/reflection-cpp-cli.md)|Demonstra a versão para CLR das informações de tipo em tempo de execução.|
|[Cadeia de caracteres](string-cpp-component-extensions.md)|Discute a conversão do compilador de literais de cadeia de caracteres para <xref:System.String>.|
|[Encaminhamento de tipos (C++/CLI)](type-forwarding-cpp-cli.md)|Permite o movimento de um tipo em um assembly de remessa para outro assembly para que o código do cliente não precise ser recompilado.|
|[Atributos definidos pelo usuário](user-defined-attributes-cpp-component-extensions.md)|Demonstra atributos definidos pelo usuário.|
|[#using diretiva](../preprocessor/hash-using-directive-cpp.md)|Importa assemblies externos.|
|[Documentação XML](../build/reference/xml-documentation-visual-cpp.md)|Explica a documentação de código baseada em XML usando [/doc (Processar comentários da documentação) (C/C++)](../build/reference/doc-process-documentation-comments-c-cpp.md)|

## <a name="see-also"></a>Confira também

[Programação .NET com C++/CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)<br/>
[Interoperabilidade entre nativo e .NET](../dotnet/native-and-dotnet-interoperability.md)
