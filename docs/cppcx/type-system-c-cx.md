---
title: Sistema de tipos (C++/CX)
ms.date: 02/03/2017
ms.assetid: b67bee8a-b526-4872-969e-ef22724e88fe
ms.openlocfilehash: f4a6ea32681ad033b5db9451682c764f0a6d8959
ms.sourcegitcommit: 6b3d793f0ef3bbb7eefaf9f372ba570fdfe61199
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/15/2020
ms.locfileid: "86404620"
---
# <a name="type-system-ccx"></a>Sistema de tipos (C++/CX)

Usando a arquitetura de Windows Runtime, você pode usar C++/CX, Visual Basic, Visual C# e JavaScript para escrever aplicativos e componentes que acessam diretamente a API do Windows e interoperam com outros aplicativos e componentes do Windows Runtime. Plataforma Universal do Windows aplicativos que são escritos em C++ compile para código nativo que é executado diretamente na CPU. Plataforma Universal do Windows aplicativos escritos em C# ou Visual Basic Compilar para a MSIL (Microsoft Intermediate Language) e executá-los no Common Language Runtime (CLR). Plataforma Universal do Windows aplicativos que são gravados em JavaScript são executados em um ambiente de tempo de execução. Os componentes do sistema operacional Windows Runtime em si são escritos em C++ e são executados como código nativo. Todos esses componentes e aplicativos de Plataforma Universal do Windows se comunicam diretamente por meio da ABI (interface binária de aplicativo Windows Runtime).

Para habilitar o suporte para o Windows Runtime em uma linguagem C++ moderna, a Microsoft criou o C++/CX. O C++/CX fornece tipos base internos e implementações de tipos de Windows Runtime fundamentais que permitem que aplicativos e componentes do C++ se comuniquem pela ABI com aplicativos escritos em outras linguagens. Você pode consumir qualquer tipo de Windows Runtime ou criar classes, structs, interfaces e outros tipos definidos pelo usuário que podem ser consumidos por outros aplicativos e componentes do Plataforma Universal do Windows. um aplicativo Plataforma Universal do Windows escrito em C++/CX também pode usar classes C++ regulares e estruturas, desde que elas não tenham acessibilidade pública.

Para uma discussão mais profunda da projeção de idioma C++/CX e como ela funciona sob as coberturas, veja estas postagens do blog:

- [C++/CX, parte 0 de \[ n \] : uma introdução](https://devblogs.microsoft.com/cppblog/ccx-part-0-of-n-an-introduction/)

- [C++/CX, parte 1 de \[ n \] : uma classe simples](https://devblogs.microsoft.com/cppblog/ccx-part-1-of-n-a-simple-class/)

- [C++/CX parte 2 de \[ n \] : tipos que usam chapéus](https://devblogs.microsoft.com/cppblog/ccx-part-2-of-n-types-that-wear-hats/)

- [C++/CX, parte 3 de \[ n \] : em construção](https://devblogs.microsoft.com/cppblog/ccx-part-3-of-n-under-construction/)

- [C++/CX parte 4 de \[ n \] : funções membro estáticas](https://devblogs.microsoft.com/cppblog/ccx-part-4-of-n-static-member-functions/)

## <a name="windows-metadata-winmd-files"></a>Arquivos de metadados do Windows (.winmd)

Quando você compila um aplicativo de Plataforma Universal do Windows escrito em C++, o compilador gera o executável no código de máquina nativo e também gera um arquivo de metadados do Windows (. winmd) separado que contém descrições dos tipos de Windows Runtime públicos, que incluem classes, estruturas, enumerações, interfaces, interfaces com parâmetros e delegados. O formato de metadados lembra o formato usado nos assemblies do .NET Framework.  Em um componente do C++, o arquivo .winmd contém apenas metadados; o código executável reside em um arquivo separado. Esse é o caso para os componentes de Windows Runtime incluídos no Windows. O nome do arquivo WinMD deve coincidir ou ser um prefixo do namespace raiz no código-fonte. (Para as linguagens .NET Framework, o arquivo .winmd contém o código e os metadados, assim como um assembly do .NET Framework.)

Os metadados no arquivo .winmd representam a superfície publicada do seu código. Os tipos publicados são visíveis para outras plataformas universais do Windows, independentemente da linguagem na qual os outros aplicativos estão escritos. Portanto, os metadados ou o código publicado só podem conter tipos especificados pelo sistema de tipos de Windows Runtime. As construções de linguagem específicas ao C++, como classes, matrizes, modelos ou contêineres STL regulares não podem ser publicadas nos metadados porque um aplicativo cliente Javascript ou C# não saberia o que fazer com elas.

Se um tipo ou um método estará visível nos metadados dependerá de quais modificadores de acessibilidade foram aplicados a ele. Para ser visível, um tipo deve ser declarado em um namespace e deve ser declarado como público. Uma classe ref não pública é permitida como um tipo auxiliar interno no seu código; ela não está visível nos metadados. Até mesmo em uma classe ref pública, nem todos os membros estão necessariamente visíveis. A tabela a seguir lista a relação entre os especificadores de acesso C++ em uma classe ref pública e Windows Runtime visibilidade de metadados:

|||
|-|-|
|**Publicado nos metadados**|**Não publicado nos metadados**|
|públicos|particulares|
|protegidos|interno|
|público protegido|privado protegido|

Use o **Pesquisador de objetos** para exibir o conteúdo de arquivos .winmd. Os componentes Windows Runtime incluídos com o Windows estão no arquivo Windows. winmd. O arquivo default. winmd contém os tipos fundamentais que são usados no C++/CX, e o Platform. winmd contém tipos adicionais do namespace da plataforma. Por padrão, esses três arquivos. winmd são incluídos em cada projeto C++ para aplicativos Plataforma Universal do Windows.

> [!TIP]
> Os tipos no [Platform::Collections Namespace](../cppcx/platform-collections-namespace.md) não aparecem no arquivo .winmd porque não são públicos. Eles são implementações particulares específicas do C++ das interfaces definidas em `Windows::Foundation::Collections`. Um aplicativo Windows Runtime escrito em JavaScript ou C# não sabe o que é uma [classe Platform:: Collections:: vector](../cppcx/platform-collections-vector-class.md) , mas pode consumir um `Windows::Foundation::Collections::IVector` . Os tipos `Platform::Collections` são definidos em collection.h.

## <a name="windows-runtime-type-system-in-ccx"></a>Sistema de tipos de Windows Runtime em C++/CX

As seções a seguir descrevem os principais recursos do sistema de tipos de Windows Runtime e como eles têm suporte no C++/CX.

### <a name="namespaces"></a>Namespaces

Todos os tipos de Windows Runtime devem ser declarados dentro de um namespace; a própria API do Windows é organizada por namespaces. Um arquivo .winmd deve ter o mesmo nome do namespace raiz. Por exemplo, uma classe denominada A.B.C.MyClass poderá ser instanciada somente se for definida em um arquivo de metadados denominado A.winmd ou A.B.winmd ou A.B.C.winmd. O nome da DLL não precisa coincidir com o nome do arquivo .winmd.

A própria API do Windows foi reinventada como uma biblioteca de classes bem fatorada organizada por namespaces.  Todos os componentes de Windows Runtime são declarados nos namespaces Windows. *.

Para obter mais informações, consulte [namespaces e visibilidade de tipo](../cppcx/namespaces-and-type-visibility-c-cx.md).

### <a name="fundamental-types"></a>Tipos fundamentais

O Windows Runtime define os seguintes tipos fundamentais: UInt8, Int16, UInt16, Int32, UInt32, Int64, UInt64, Single, Double, Char16, Boolean e String. O C++/CX dá suporte aos tipos numéricos fundamentais em seu namespace padrão como UInt16, UInt32, UInt64, Int16, Int32, Int64, float32, float64 e char16. Boolean e String também são definidos no namespace Platform.

O C++/CX também define uint8, equivalente a `unsigned char` , que não tem suporte no Windows Runtime e não pode ser usado em APIs públicas.

Um tipo fundamental pode ser transformado em anulável convertendo-o em uma interface [Platform::IBox Interface](../cppcx/platform-ibox-interface.md) . Para obter mais informações, consulte [Classes e estruturas de valor](../cppcx/value-classes-and-structs-c-cx.md).

Para obter mais informações sobre tipos fundamentais, consulte [Tipos fundamentais](../cppcx/fundamental-types-c-cx.md)

### <a name="strings"></a>Cadeias de caracteres

Uma cadeia de caracteres Windows Runtime é uma sequência imutável de caracteres UNICODE de 16 bits. Uma cadeia de caracteres Windows Runtime é projetada como `Platform::String^` . Essa classe fornece métodos para construção, manipulação e conversão de cadeia de caracteres de e em `wchar_t`.

Para obter mais informações, consulte [Cadeias de caracteres](../cppcx/strings-c-cx.md).

### <a name="arrays"></a>Matrizes

O Windows Runtime dá suporte a matrizes unidimensionais de qualquer tipo. Não há suporte para matrizes de matrizes.  No C++/CX, Windows Runtime matrizes são projetadas como a [classe Platform:: array](../cppcx/platform-array-class.md).

Para obter mais informações, consulte [array e WriteOnlyArray](../cppcx/array-and-writeonlyarray-c-cx.md)

### <a name="ref-classes-and-structs"></a>Classes e estruturas ref

Uma classe de Windows Runtime é projetada em C++/CX como uma ref class ou ref struct, pois elas são copiadas por referência. O gerenciamento de memória para classes e estruturas ref é manipulado de forma transparente por meio da contagem de referência. Quando a última referência a um objeto fica fora do escopo, o objeto é destruído. Uma classe ou estrutura ref pode:

- Conter como membros construtores, métodos, propriedades e eventos. Esses membros podem ter acessibilidade pública, privada, protegida ou interna.

- Pode conter definições aninhadas privadas de enum, estrutura ou classe.

- Pode herdar diretamente de uma classe base e pode implementar qualquer número de interfaces. Todas as classes ref podem ser convertidas implicitamente na [Platform::Object Class](../cppcx/platform-object-class.md) e podem substituir seus métodos virtuais, por exemplo, [Object::ToString](../cppcx/platform-object-class.md#tostring).

Uma classe ref que tem um construtor público também precisa ser declarada como fechada para evitar mais derivação.

Para obter mais informações, consulte [ref classes e structs](../cppcx/ref-classes-and-structs-c-cx.md)

### <a name="value-classes-and-structs"></a>Classes e estruturas de valor

Uma classe ou estrutura de valor representa uma estrutura de dados básica e contém apenas campos, que podem ser classes de valor, estruturas de valor ou o tipo `Platform::String^`.  As estruturas e classes de valor são copiadas por valor.

Um estrutura de valor pode ser transformada em anulável convertendo em uma interface IBox.

Para obter mais informações, consulte [Classes e estruturas de valor](../cppcx/value-classes-and-structs-c-cx.md).

### <a name="partial-classes"></a>Classes parciais

O recurso de classe parcial permite que uma classe seja definida em vários arquivos. Ele é usado principalmente para habilitar a geração de ferramentas, como o editor XAML, para modificar um arquivo sem tocar no arquivo que você edita.

Para obter mais informações, consulte [Classes parciais](../cppcx/partial-classes-c-cx.md)

### <a name="properties"></a>Propriedades

Uma propriedade é um membro de dados públicos de qualquer tipo de Windows Runtime e é implementada como um par de métodos get/set. O código de cliente acessa uma propriedade como se fosse um campo público. Uma propriedade que não requer código get ou set personalizado é conhecida como uma *propriedade trivial* e pode ser declarada sem métodos get ou set explícitos.

Para obter mais informações, consulte [Propriedades](../cppcx/properties-c-cx.md).

### <a name="windows-runtime-collections-in-ccx"></a>Coleções de Windows Runtime em C++/CX

O Windows Runtime define um conjunto de interfaces para tipos de coleção que cada linguagem implementa de sua própria maneira. O C++/CX fornece implementações na classe [Platform:: coleções:: vector](../cppcx/platform-collections-vector-class.md), [plataforma:: Collections:: map](../cppcx/platform-collections-map-class.md)e outros tipos de coleção concreto relacionados, que são compatíveis com suas contrapartes da STL (biblioteca de modelos padrão).

Para obter mais informações, consulte [coleções](../cppcx/collections-c-cx.md).

### <a name="template-ref-classes"></a>Classes de referência de modelo

As classes ref particulares e internas podem ser modeladas e especializadas.

Para obter mais informações, consulte [Classes de referência de modelo](../cppcx/template-ref-classes-c-cx.md).

### <a name="interfaces"></a>Interfaces

Uma interface Windows Runtime define um conjunto de propriedades públicas, métodos e eventos que uma ref class ou ref struct deve implementar se for herdada da interface.

Para obter mais informações, consulte [interfaces](../cppcx/interfaces-c-cx.md).

### <a name="enums"></a>Enumerações

Uma classe enum no Windows Runtime assemelha-se a uma enumeração com escopo em C++. O tipo subjacente é int32, a menos que o atributo [Flags] seja aplicado; nesse caso, o tipo subjacente será uint32.

Para obter mais informações, consulte [Enums](../cppcx/enums-c-cx.md).

### <a name="delegates"></a>Delegados

Um delegado no Windows Runtime é análogo a um objeto std:: function em C++. É um tipo especial de classe ref usado para invocar funções fornecidas pelo cliente que têm assinaturas compatíveis.  Delegados são usados com mais frequência no Windows Runtime como o tipo de um evento.

Para obter mais informações, consulte [Delegados](../cppcx/delegates-c-cx.md).

### <a name="exceptions"></a>Exceções

Em C++/CX, você pode capturar tipos de exceção personalizados, tipos [std::exception](../standard-library/exception-class.md) e tipos [Platform::Exception](../cppcx/platform-exception-class.md) .

Para obter mais informações, consulte [Exceções](../cppcx/exceptions-c-cx.md).

### <a name="events"></a>Eventos

Um evento é um membro público em uma classe ou estrutura ref cujo tipo é delegado. Um evento somente pode ser invocado, ou seja, disparado, pela classe que o possui. No entanto, o código de cliente pode fornecer suas próprias funções, que são conhecidas como manipuladores de eventos e são invocadas quando a classe possuidora dispara o evento.

Para obter mais informações, consulte [Eventos](../cppcx/events-c-cx.md).

### <a name="casting"></a>Conversão

O C++/CX oferece suporte aos operadores cast C++ padrão [static_cast](../cpp/static-cast-operator.md), [dynamic_cast](../cpp/dynamic-cast-operator.md)e [reinterpret_cast](../cpp/reinterpret-cast-operator.md), além do operador **safe_cast** que é específico ao C++/CX.

Para obter mais informações, consulte [Conversão](../cppcx/casting-c-cx.md).

### <a name="boxing"></a>Conversão boxing

Uma variável demarcada é um tipo de valor que é encapsulado em um tipo de referência em situações nas quais a semântica de referência é necessária.

Para obter mais informações, consulte [Boxing](../cppcx/boxing-c-cx.md).

### <a name="attributes"></a>Atributos

Um atributo é um valor de metadados que pode ser aplicado a qualquer tipo de Windows Runtime ou membro de tipo e pode ser inspecionado em tempo de execução. O Windows Runtime define um conjunto de atributos comuns no `Windows::Foundation::Metadata` namespace. Os atributos definidos pelo usuário em interfaces públicas não são suportados pelo Windows Runtime nesta versão.

## <a name="api-deprecation"></a>Substituição de API

Descreve como marcar APIs públicas como preteridas usando o mesmo atributo usado pelos tipos de sistema Windows Runtime.

Para obter mais informações, consulte [preterindo tipos e membros](../cppcx/deprecating-types-and-members-c-cx.md).

## <a name="see-also"></a>Confira também

[Referência de linguagem do C++/CX](../cppcx/visual-c-language-reference-c-cx.md)
