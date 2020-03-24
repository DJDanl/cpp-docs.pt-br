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
ms.openlocfilehash: 6b3add1c0de8aa1f8ec66e8d220443c4a0efd704
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80172459"
---
# <a name="component-extensions-for-net-and-uwp"></a>Extensões de componentes para .NET e UWP

O padrão C++ permite que os fornecedores de compiladores forneçam extensões não padrão para a linguagem. A Microsoft fornece extensões para ajudar você a conectar o código C++ nativo ao código executado no .NET Framework ou na Plataforma Universal do Windows (UWP). As extensões .NET são chamadas de C++/CLI e geram um código que é executado no ambiente de execução gerenciado pelo .NET, chamado de Common Language Runtime (CLR). As extensões da UWP são chamadas de C++ /CX e geram um código de máquina nativo.

> [!NOTE]
> Para novos aplicativos, recomendamos o uso de C++/WinRT em vez de C++/CX. C++/WinRT é uma nova projeção de linguagem padrão C++17 para APIs do Windows Runtime. Continuaremos a dar suporte a C++/CX e WRL, mas recomendamos que os novos aplicativos usem o C++/WinRT. Saiba mais em [C++/WinRT](/windows/uwp/cpp-and-winrt-apis/index).

### <a name="two-runtimes-one-set-of-extensions"></a>Dois runtimes, um conjunto de extensões

A C++/CLI amplia o padrão ISO/ANSI de C++ e é definida sob o padrão Ecma C++/CLI. Saiba mais em [Programação do .NET C++/CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md).

As extensões C++/CX são um subconjunto de C++/CLI. Embora a sintaxe da extensão seja idêntica na maioria dos casos, o código gerado depende de você especificar a opção de compilador `/ZW` para o UWP de destino ou a opção `/clr` para o .NET de destino. Essas opções são definidas automaticamente quando você usa o Visual Studio para criar um projeto.

## <a name="data-type-keywords"></a>Palavras-chave do tipo de dados

As extensões de linguagem incluem *palavras-chave agregadas*, que consistem em dois tokens separados por espaço em branco. Os tokens podem ter um significado quando são usados ​​separadamente e outro significado quando são usados ​​juntos. Por exemplo, a palavra "ref" é um identificador comum e a palavra "class" é uma palavra-chave que declara uma classe nativa. Mas quando essas palavras são combinadas para formar **ref class**, a palavra-chave agregada resultante declara uma entidade que é conhecida como *classe de runtime*.

As extensões também incluem palavras-chave *contextuais*. Uma palavra-chave é tratada como contextual dependendo do tipo de instrução que a contém e de seu posicionamento nessa instrução. Por exemplo, o token "propriedade" pode ser um identificador ou pode declarar um tipo especial de membro de classe pública.

A tabela a seguir lista palavras-chave na extensão de linguagem C++.

|Palavra-chave|Contextual|Finalidade|Referência|
|-------------|-----------------------|-------------|---------------|
|**ref class**<br /><br /> **ref struct**|Não|Declara uma classe.|[Classes e Structs](classes-and-structs-cpp-component-extensions.md)|
|**value class**<br /><br /> **value struct**|Não|Declara uma classe de valor.|[Classes e Structs](classes-and-structs-cpp-component-extensions.md)|
|**classe de interface**<br /><br /> **interface struct**|Não|Declara uma interface.|[classe de interface](interface-class-cpp-component-extensions.md)|
|**enum class**<br /><br /> **enum struct**|Não|Declara uma enumeração.|[enum class](enum-class-cpp-component-extensions.md)|
|**property**|Sim|Declara uma propriedade.|[property](property-cpp-component-extensions.md)|
|**delegate**|Sim|Declara um delegado.|[delegate (C++/CLI e C++/CX)](delegate-cpp-component-extensions.md)|
|**event**|Sim|Declara um evento.|[event](event-cpp-component-extensions.md)|

## <a name="override-specifiers"></a>Especificadores de Substituição

Você pode usar as seguintes palavras-chave para qualificar o comportamento de substituição para derivação. Embora a **nova** palavra-chave não seja uma extensão de C++, ela é listada aqui porque pode ser usada em um contexto adicional. Alguns especificadores também são válidos para programação nativa. Para obter mais informações, consulte [como: declarar especificadores de substituição em/CLI (C++compilações nativas)](../dotnet/how-to-declare-override-specifiers-in-native-compilations-cpp-cli.md).

|Palavra-chave|Contextual|Finalidade|Referência|
|-------------|-----------------------|-------------|---------------|
|**abstract**|Sim|Indica que as funções ou classes são abstratas.|[abstract](abstract-cpp-component-extensions.md)|
|**novo**|Não|Indica que uma função não é uma substituição de uma versão de classe base.|[novo (novo slot em vtable)](new-new-slot-in-vtable-cpp-component-extensions.md)|
|**override**|Sim|Indica que um método deve ser uma substituição de uma versão de classe base.|[override](override-cpp-component-extensions.md)|
|**sealed**|Sim|Impede que classes sejam usadas como classes base.|[sealed](sealed-cpp-component-extensions.md)|

## <a name="keywords-for-generics"></a>Palavras-chave para genéricos

As seguintes palavras-chave foram adicionadas para serem compatíveis com tipos genéricos. Para obter mais informações, consulte [Genéricos](generics-cpp-component-extensions.md).

|Palavra-chave|Contextual|Finalidade|
|-------------|-----------------------|-------------|
|**generic**|Não|Declara um tipo genérico.|
|**where**|Sim|Especifica as restrições aplicadas a um parâmetro de tipo genérico.|

## <a name="miscellaneous-keywords"></a>Palavras-chave diversas

As seguintes palavras-chave foram adicionadas às extensões C++.

|Palavra-chave|Contextual|Finalidade|Referência|
|-------------|-----------------------|-------------|---------------|
|**finally**|Sim|Indica o comportamento de tratamento de exceção padrão.|[Tratamento de Exceção](exception-handling-cpp-component-extensions.md)|
|**for each, in**|Não|Enumera elementos de uma coleção.|[for each, in](../dotnet/for-each-in.md)|
|**gcnew**|Não|Aloca os tipos no heap coletado do lixo. Use em vez de **new** e **delete**.|[ref new, gcnew](ref-new-gcnew-cpp-component-extensions.md)|
|**ref new**|Sim|Aloca um tipo do Windows Runtime. Use em vez de **new** e **delete**.|[ref new, gcnew](ref-new-gcnew-cpp-component-extensions.md)|
|**initonly**|Sim|Indica que um membro só pode ser inicializado na declaração ou em um construtor estático.|[initonly (C++/CLI)](../dotnet/initonly-cpp-cli.md)|
|**literal**|Sim|Cria uma variável literal.|[literal](literal-cpp-component-extensions.md)|
|**nullptr**|Não|Indica que um identificador ou ponteiro não aponta para um objeto.|[nullptr](nullptr-cpp-component-extensions.md)|

## <a name="template-constructs"></a>Construções de modelo

As seguintes construções de linguagem são implementadas como modelos, em vez de como palavras-chave. Se você especificar a opção de compilador `/ZW`, eles serão definidos no namespace `lang`. Se você especificar a opção de compilador `/clr`, eles serão definidos no namespace `cli`.

|Palavra-chave|Finalidade|Referência|
|-------------|-------------|---------------|
|**array**|Declara uma matriz.|[Matrizes](arrays-cpp-component-extensions.md)|
|**interior_ptr**|(Somente CLR) Aponta para dados em um tipo de referência.|[interior_ptr (C++/CLI)](interior-ptr-cpp-cli.md)|
|**pin_ptr**|(Apenas CLR) Aponta para os tipos de referência do CLR para suprimir temporariamente o sistema de coleta de lixo.|[pin_ptr (C++/CLI)](pin-ptr-cpp-cli.md)|
|**safe_cast**|Determina e executa o método de conversão ideal para um tipo de runtime.|[safe_cast](safe-cast-cpp-component-extensions.md)|
|**typeid**|(Somente CLR) Recupera um objeto <xref:System.Type?displayProperty=fullName> que descreve o tipo ou objeto fornecido.|[typeid](typeid-cpp-component-extensions.md)|

## <a name="declarators"></a>Declaradores

Os seguintes declaradores de tipo instruem o runtime a gerenciar automaticamente o tempo de vida e a exclusão de objetos alocados.

|Operador|Finalidade|Referência|
|--------------|-------------|---------------|
|`^`|Declara um identificador para um objeto; ou seja, um ponteiro para um objeto do Windows Runtime ou do CLR que é automaticamente excluído quando não puder mais ser usado.|[Operador Handle to Object (^)](handle-to-object-operator-hat-cpp-component-extensions.md)|
|`%`|Declara uma referência de companhamento; ou seja, uma referência a um objeto do Windows Runtime ou do CLR que é automaticamente excluído quando não puder mais ser usado.|[Operador de Referência de Acompanhamento](tracking-reference-operator-cpp-component-extensions.md)|

## <a name="additional-constructs-and-related-topics"></a>Construções adicionais e tópicos relacionados

Esta seção lista construções de programação adicionais e tópicos que pertencem ao CLR.

|Tópico|DESCRIÇÃO|
|-----------|-----------------|
|[__identifier (C++/CLI)](identifier-cpp-cli.md)|(Windows Runtime e CLR) Permite o uso de palavras-chave como identificadores.|
|[Listas de argumentos variáveis (...) (C++/CLI)](variable-argument-lists-dot-dot-dot-cpp-cli.md)|(Windows Runtime e CLR) Permite que uma função obtenha um número variável de argumentos.|
|[Equivalentes do .NET Framework aos tipos nativos do C++ (C++/CLI)](../dotnet/dotnet-framework-equivalents-to-cpp-native-types-cpp-cli.md)|Lista os tipos de CLR que são usados ​​no lugar dos tipos integrais de C++.|
|modificador de **__declspec** [AppDomain](../cpp/appdomain.md)|O modificador **__ declspec** que exige que variáveis ​​estáticas e globais existam por domínio de aplicativo.|
|[Conversões C-Style com /clr (C++/CLI)](c-style-casts-with-clr-cpp-cli.md)|Descreve como as conversões C-Style são interpretadas.|
|Convenção de chamada [__clrcall](../cpp/clrcall.md)|Indica a convenção de chamada compatível com CLR.|
|`__cplusplus_cli`|[Macros predefinidas](../preprocessor/predefined-macros.md)|
|[Atributos personalizados](user-defined-attributes-cpp-component-extensions.md)|Descreve como definir seus próprios atributos CLR.|
|[Tratamento de Exceção](exception-handling-cpp-component-extensions.md)|Fornece uma visão geral do tratamento de exceção.|
|[Substituições explícitas](explicit-overrides-cpp-component-extensions.md)|Demonstra como as funções de membro podem substituir membros arbitrários.|
|[Assemblies amigáveis (C++)](../dotnet/friend-assemblies-cpp.md)|Discute como um assembly de cliente pode acessar todos os tipos em um componente de assembly.|
|[Conversão boxing](boxing-cpp-component-extensions.md)|Demonstra as condições nas quais os tipos de valores são convertidos.|
|[Suporte para Compilador de Traços de Tipo](compiler-support-for-type-traits-cpp-component-extensions.md)|Discute como detectar características de tipos em tempo de compilação.|
|Pragmas [managed, unmanaged](../preprocessor/managed-unmanaged.md)|Demonstra como funções gerenciadas e não gerenciadas podem coexistir no mesmo módulo.|
|modificador de **__declspec** de [processo](../cpp/process.md)|O modificador **__ declspec** que exige que variáveis ​​estáticas e globais existam por processo.|
|[Reflexão (C++/CLI)](../dotnet/reflection-cpp-cli.md)|Demonstra a versão para CLR das informações de tipo em tempo de execução.|
|[Cadeia de caracteres](string-cpp-component-extensions.md)|Discute a conversão do compilador de literais de cadeia de caracteres para <xref:System.String>.|
|[Encaminhamento de tipo (C++/CLI)](type-forwarding-cpp-cli.md)|Permite o movimento de um tipo em um assembly de remessa para outro assembly para que o código do cliente não precise ser recompilado.|
|[Atributos definidos pelo usuário](user-defined-attributes-cpp-component-extensions.md)|Demonstra atributos definidos pelo usuário.|
|[Diretiva #using](../preprocessor/hash-using-directive-cpp.md)|Importa assemblies externos.|
|[Documentação XML](../build/reference/xml-documentation-visual-cpp.md)|Explica a documentação de código baseada em XML usando [/doc (Processar comentários da documentação) (C/C++)](../build/reference/doc-process-documentation-comments-c-cpp.md)|

## <a name="see-also"></a>Confira também

[Programação do .NET com C++/CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)<br/>
[Interoperabilidade entre .NET e nativo](../dotnet/native-and-dotnet-interoperability.md)
