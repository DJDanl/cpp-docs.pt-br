---
title: Coleções (C++/CX)
ms.date: 11/19/2018
ms.assetid: 914da30b-aac5-4cd7-9da3-a5ac08cdd72c
ms.openlocfilehash: ff3fb9899355ec05083dc15c16d74c9aa1d3fd8f
ms.sourcegitcommit: 180f63704f6ddd07a4172a93b179cf0733fd952d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/06/2019
ms.locfileid: "70740327"
---
# <a name="collections-ccx"></a>Coleções (C++/CX)

Em um C++programa/CX, você pode fazer uso gratuito de contêineres STL (Standard Template Library) ou qualquer outro tipo de coleção definido pelo usuário. No entanto, quando você passa as coleções para frente e para trás pela ABI (interface binária de aplicativo Windows Runtime) — por exemplo, para um controle XAML ou para um cliente JavaScript — você deve usar Windows Runtime tipos de coleção.

O Windows Runtime define as interfaces para coleções e tipos relacionados, e C++/CX fornece as implementações concretas C++ no arquivo de cabeçalho Collection. h. Esta ilustração mostra as relações entre os tipos de coleção:

![Árvore&#43;&#43;&#47;de herança c CX para tipos de coleção](../cppcx/media/cppcxcollectionsinheritancetree.png "árvore de herança c&#43;&#43;&#47;CX para tipos de coleção")

- A [classe Platform::Collections::Vector](../cppcx/platform-collections-vector-class.md) é semelhante à [classe std::vector](../standard-library/vector-class.md).

- A [classe Platform::Collections::Map](../cppcx/platform-collections-map-class.md) é semelhante à [classe std::map](../standard-library/map-class.md).

- A[classe Platform::Collections::VectorView](../cppcx/platform-collections-vectorview-class.md) e a[classe Platform::Collections::MapView](../cppcx/platform-collections-mapview-class.md) são versões somente leitura de `Vector` e a `Map`.

- Iteradores são definidos no [namespace Platform::Collections](../cppcx/platform-collections-namespace.md). Esses iteradores satisfazem os requisitos para iteradores STL e permitem o uso de [std::find](../standard-library/algorithm-functions.md#find),  [std::count_if](../standard-library/algorithm-functions.md#count_if)e outros algoritmos STL em qualquer tipo de interface [Windows::Foundation::Collections](/uwp/api/windows.foundation.collections) ou tipo concreto [Platform::Collections](../cppcx/platform-collections-namespace.md) . Por exemplo, isso significa que você pode iterar uma coleção em um componente Windows Runtime que é criado C# no e aplicar um algoritmo STL a ele.

   > [!IMPORTANT]
   > Os iteradores proxy `VectorIterator` e `VectorViewIterator` utilizam os objetos proxy `VectoryProxy<T>` e `ArrowProxy<T>` para permitir o uso com contêineres STL. Para obter mais informações, consulte "Elementos VectorProxy" mais adiante neste artigo.

- Os C++tipos de coleção/CX dão suporte às mesmas garantias de segurança de thread que os contêineres STL dão suporte.

- [Windows::Foundation::Collections::IObservableVector](/uwp/api/Windows.Foundation.Collections.IObservableVector_T_) e [Windows::Foundation::Collections::IObservableMap](/uwp/api/Windows.Foundation.Collections.IObservableMap_K_V_) definem eventos que são acionados quando a coleção é alterada de várias maneiras. Com a implementação dessas interfaces,  [Platform::Collections::Map](../cppcx/platform-collections-map-class.md) e [Platform::Collections::Vector](../cppcx/platform-collections-vector-class.md) oferecem suporte à associação de dados com coleções XAML. Por exemplo, se você tiver um `Vector` com dados associados a `Grid`, quando você adicionar um item a uma coleção, a alteração será refletida na interface de usuário da grade.

## <a name="vector-usage"></a>Uso do vetor

Quando sua classe precisa passar um contêiner de sequência para outro componente Windows Runtime, use [Windows:: Foundation:: Collections:: IVector\<t >](/uwp/api/Windows.Foundation.Collections.IVector_T_) como o parâmetro ou tipo de retorno, e [Platform:: Collections::\<vector T >](../cppcx/platform-collections-vector-class.md) como a implementação concreta. Se você tentar usar um tipo `Vector` em um valor ou parâmetro de retorno público, será gerado o erro do compilador C3986. Você pode corrigir o erro alterando `Vector` para `IVector`.

> [!IMPORTANT]
> Se você estiver passando uma sequência no seu próprio programa, use `Vector` ou `std::vector` , pois eles são mais eficientes do que `IVector`. Use `IVector` somente ao passar o contêiner pela ABI.
>
> O sistema do tipo Windows Runtime não dá suporte ao conceito de matrizes denteadas e, portanto, você não pode passar um\<IVector < Platform:: array T > > como um valor de retorno ou um parâmetro de método. Para passar uma matriz denteada ou uma sequência de sequências através da ABI, use `IVector<IVector<T>^>`.

`Vector<T>` fornece os métodos necessários para adição, remoção e acesso a itens na coleção e é implicitamente conversível em `IVector<T>`. Você também pode usar algoritmos STL em instâncias de `Vector<T>`. O exemplo a seguir demonstra alguns usos básicos. As funções [begin](../cppcx/begin-function.md) e [end](../cppcx/end-function.md) aqui são do namespace `Platform::Collections` , não do namespace `std` .

[!code-cpp[cx_collections#01](../cppcx/codesnippet/CPP/collections/class1.cpp#01)]

Se você tiver um código existente que `std::vector` usa e deseja reutilizá-lo em um componente Windows Runtime, basta usar um `Vector` dos construtores que utilizam um `std::vector` ou um par de iteradores para construir um `Vector` no ponto em que você passa o coleção em toda a ABI. O exemplo a seguir mostra como usar o construtor de movimentação `Vector` para inicialização eficiente de um `std::vector`. Após a operação de movimentação, a variável de `vec` original não será mais válida.

[!code-cpp[cx_collections#02](../cppcx/codesnippet/CPP/collections/class1.cpp#02)]

Se você tiver um vetor de cadeias de caracteres que deve passar pela ABI em algum ponto futuro, será preciso decidir se as cadeias de caracteres serão criadas inicialmente como tipos de `std::wstring` ou como tipos de `Platform::String^` . Se for necessário muito processamento nessas cadeias de caracteres, use `wstring`. Caso contrário, crie as cadeias de caracteres como tipos de `Platform::String^` e evite o custo de convertê-las posteriormente. Você também deve decidir se essas cadeias de caracteres serão colocadas em um `std:vector` ou `Platform::Collections::Vector` internamente. Como prática geral, use `std::vector` e crie um `Platform::Vector` a partir dele somente quando passar o contêiner pela ABI.

## <a name="value-types-in-vector"></a>Tipos de valor no vetor

Qualquer elemento a ser armazenado em um [Platform::Collections::Vector](../cppcx/platform-collections-vector-class.md) deve oferecer suporte à comparação de igualdade, seja implicitamente ou usando um comparador personalizado [std::equal_to](../standard-library/equal-to-struct.md) que você fornece. Todos os tipos de referência e todos os tipos escalares oferecem suporte implicitamente às comparações de igualdade. Para os tipos de valor não escalar, como [Windows::Foundation::DateTime](/uwp/api/windows.foundation.datetime), ou para comparações personalizadas (por exemplo, `objA->UniqueID == objB->UniqueID`), é necessário fornecer um objeto de função personalizado.

## <a name="vectorproxy-elements"></a>Elementos VectorProxy

[Plataforma:: Collections:: VectorIterator](../cppcx/platform-collections-vectoriterator-class.md) e [plataforma:: Collections:: VectorViewIterator](../cppcx/platform-collections-vectorviewiterator-class.md) habilitam o uso `range for` de loops e algoritmos como [std:: Sort](../standard-library/algorithm-functions.md#sort) com um contêiner [IVector\<T >](/uwp/api/Windows.Foundation.Collections.IVector_T_) . Porém, os elementos `IVector` não podem ser acessados por meio do desreferenciamento do ponteiro C++; eles podem ser acessados somente por pelos métodos [GetAt](/uwp/api/windows.foundation.collections.ivector-1.getat) e [SetAt](/uwp/api/windows.foundation.collections.ivector-1.setat) . Portanto, esses `Platform::Details::VectorProxy<T>` iteradores usam as classes proxy e `Platform::Details::ArrowProxy<T>` para fornecer acesso aos elementos individuais por meio __\*__ de operadores,  __\[__ __->__ e], conforme exigido pela biblioteca padrão. Estritamente falando, dado um `IVector<Person^> vec`, o tipo de `*begin(vec)` será `VectorProxy<Person^>`. Entretanto, o objeto proxy é quase sempre transparente ao seu código. Esses objetos proxy não estão documentados porque são apenas para uso interno dos iteradores, mas é útil saber como o mecanismo funciona.

Quando você usar um loop `range for` sobre contêineres `IVector` , use `auto&&` para habilitar a variável de iterador para associar corretamente aos elementos `VectorProxy` . Se você usar `auto` ou `auto&`, o aviso do compilador C4239 será gerado e `VectoryProxy` será mencionado no texto de aviso.

A ilustração a seguir mostra um loop `range for` sobre um `IVector<Person^>`. Observe que a execução é interrompida no ponto de interrupção na linha 64. A janela **QuickWatch** mostra que a variável de iterador `p` é na verdade um `VectorProxy<Person^>` que tem as variáveis de membro `m_v` e `m_i` . Entretanto, quando você chama `GetType` nessa variável, é retornado o tipo idêntico à instância `Person` de `p2`. A conclusão é que, embora `VectorProxy` e `ArrowProxy` possam aparecer em **QuickWatch**, determinados erros do compilador do depurador, ou outros locais, geralmente não precisam ter uma codificação explícita para eles.

![VectorProxy no intervalo&#45;com base no loop](../cppcx/media/vectorproxy-1.png "VectorProxy no&#45;intervalo para loop")

Um cenário em que é necessário codificar em torno do objeto proxy é quando você precisa executar um `dynamic_cast` nos elementos — por exemplo, quando você está procurando objetos XAML de um determinado tipo em uma coleção de elementos `UIElement` . Nesse caso, você deve primeiro converter o elemento em [Platform::Object](../cppcx/platform-object-class.md)^ e depois executar a conversão dinâmica:

```cpp
void FindButton(UIElementCollection^ col)
{
    // Use auto&& to avoid warning C4239
    for (auto&& elem : col)
    {
        Button^ temp = dynamic_cast<Button^>(static_cast<Object^>(elem));
        if (nullptr != temp)
        {
            // Use temp...
        }
    }
}
```

## <a name="map-usage"></a>Uso do mapa

Este exemplo mostra como inserir itens e vê-los em uma [plataforma:: Collections:: map](../cppcx/platform-collections-map-class.md)e, em seguida, retornar `Map` o como somente leitura [Windows:: Foundation:: Collections:: IMapView]/UWP/API/Windows.Foundation.Collections.IMapView_K_V_) Escreva.

[!code-cpp[cx_collections#04](../cppcx/codesnippet/CPP/collections/class1.cpp#04)]

Em geral, para a funcionalidade de mapa interna, prefira o tipo `std::map` por motivos de desempenho. Se precisar transmitir o contêiner pela ABI, construa um [Platform::Collections::Map](../cppcx/platform-collections-map-class.md) a partir de [std::map](../standard-library/map-class.md) e retorne `Map` como um [Windows::Foundation::Collections::IMap](/uwp/api/Windows.Foundation.Collections.IMap_K_V_). Se você tentar usar um tipo `Map` em um valor ou parâmetro de retorno público, será gerado o erro do compilador C3986. Você pode corrigir o erro alterando `Map` para `IMap`. Em alguns casos (por exemplo, se você não estiver fazendo um grande número de pesquisas ou inserções e estiver passando a coleção pela ABI frequentemente), poderá ser menos caro usar `Platform::Collections::Map` desde o início e evitar o custo de converter o `std::map`. Em qualquer caso, evite as operações de pesquisa e inserção em um `IMap` , pois elas são as menos eficazes dos três tipos. Converta em `IMap` somente no ponto em que você passa o contêiner pela ABI.

## <a name="value-types-in-map"></a>Tipos de valor no mapa

Os elementos de um [Platform::Collections::Map](../cppcx/platform-collections-map-class.md) são ordenados. Qualquer elemento a ser armazenado em um `Map` deve oferecer suporte à comparação de inferioridade com ordenação fraca estrita, seja implicitamente ou usando um comparador personalizado [stl::less](../standard-library/less-struct.md) fornecido por você. Os tipos escalares oferecem suporte à comparação implicitamente. Para os tipos de valor não escalar, como `Windows::Foundation::DateTime`, ou para comparações personalizadas (por exemplo, `objA->UniqueID < objB->UniqueID`), você deverá fornecer um comparador personalizado.

## <a name="collection-types"></a>Tipos de coleção

As coleções se enquadram em quatro categorias: versões modificáveis e somente leitura das coleções de sequência e coleções associativas. Além disso, C++o/CX aprimora coleções fornecendo três classes de iterador que simplificam o acesso de coleções.

Os elementos de uma coleção modificável podem ser alterados, mas os elementos de uma coleção somente leitura, que é conhecida como *exibição*, só podem ser lidos. Elementos de uma coleção [Platform:: Collections:: vector](../cppcx/platform-collections-vector-class.md) ou[Platform:: coleções:: VectorView](../cppcx/platform-collections-vectorview-class.md) podem ser acessados usando um iterador ou o [vetor:: GetAt](../cppcx/platform-collections-vector-class.md#getat) e um índice da coleção. Os elementos de uma coleção associativa podem ser acessados usando o [mapa:: Lookup](../cppcx/platform-collections-map-class.md#lookup) e uma chave da coleção.

[classe Platform::Collections::Map](../cppcx/platform-collections-map-class.md)<br/>
uma coleção modificável, associativa. Os elementos de mapa são pares chave-valor. Há suporte para as operações de pesquisar uma chave para recuperar seu valor associado e iterar por todos os pares chave-valor.

`Map` e `MapView` se tornam modelos no `<K, V, C = std::less<K>>`; portanto, você pode personalizar o comparador.  Além disso, `Vector` e `VectorView` se tornam modelos no `<T, E = std::equal_to<T>>` para que você possa personalizar o comportamento de `IndexOf()`. Isso é importante principalmente para `Vector` e `VectorView` e estruturas de valor. Por exemplo, para criar um\<comparador Windows:: Foundation::D atetime >, você deve fornecer um comparador personalizado porque DateTime não sobrecarrega o operador = =.

[classe Platform::Collections::MapView](../cppcx/platform-collections-mapview-class.md)<br/>
Uma versão somente leitura de `Map`.

[Platform::Collections::Vector Class](../cppcx/platform-collections-vector-class.md)<br/>
Uma coleção de sequências modificável. `Vector<T>` oferece suporte a operações [Append](../cppcx/platform-collections-vector-class.md#append) de acesso aleatório de tempo constante e de tempo constante amortizado.

[classe Platform::Collections::VectorView](../cppcx/platform-collections-vectorview-class.md)<br/>
Uma versão somente leitura de `Vector`.

[Classe Platform::Collections::InputIterator](../cppcx/platform-collections-inputiterator-class.md)<br/>
Um iterador STL que satisfaz os requisitos de um iterador de entrada STL.

[Classe Platform::Collections::VectorIterator](../cppcx/platform-collections-vectoriterator-class.md)<br/>
Um iterador STL que satisfaz os requisitos de um iterador de acesso aleatório mutável STL.

[Classe Platform::Collections::VectorViewIterator](../cppcx/platform-collections-vectorviewiterator-class.md)<br/>
Um iterador STL que satisfaz os requisitos de um iterador de acesso aleatório STL  `const` .

### <a name="begin-and-end-functions"></a>Funções begin() e end()

Para simplificar o uso da STL para processar `Vector`, `VectorView`, `Map`, `MapView`e `Windows::Foundation::Collections` objetos arbitrários, C++o/CX dá suporte a sobrecargas da [função Begin](../cppcx/begin-function.md) e [End Function](../cppcx/end-function.md) não-member funções.

A tabela a seguir lista os iteradores e as funções disponíveis.

|Iterators|Funções|
|---------------|---------------|
|[Platform::Collections::VectorIterator\<T>](../cppcx/platform-collections-vectoriterator-class.md)<br /><br /> (Armazena [internamente o Windows:: Foundation:: Collections:: IVector\<T >](/uwp/api/Windows.Foundation.Collections.IVector_T_) e int.)|[begin](../cppcx/begin-function.md)/ [end](../cppcx/end-function.md)([Windows::Foundation::Collections:: IVector\<T >](/uwp/api/Windows.Foundation.Collections.IVector_T_))|
|[Platform::Collections::VectorViewIterator\<T>](../cppcx/platform-collections-vectorviewiterator-class.md)<br /><br /> (Internamente armazena [IVectorView\<T >](/uwp/api/Windows.Foundation.Collections.IVectorView_T_)^ e int.)|[begin](../cppcx/begin-function.md)/ [end](../cppcx/end-function.md) ([IVectorView\<T>](/uwp/api/Windows.Foundation.Collections.IVectorView_T_)^)|
|[Platform::Collections::InputIterator\<T>](../cppcx/platform-collections-inputiterator-class.md)<br /><br /> (Internamente armazena [IIterator\<T >](/uwp/api/Windows.Foundation.Collections.IIterator_T_)^ e T.)|[Iniciar](../cppcx/begin-function.md)/ [término](../cppcx/end-function.md) ([IIterable\<T>](/uwp/api/Windows.Foundation.Collections.IIterable_T_))|
|[Platform::Collections::InputIterator<IKeyValuePair\<K, V>^>](../cppcx/platform-collections-inputiterator-class.md)<br /><br /> (Internamente armazena [IIterator\<T >](/uwp/api/Windows.Foundation.Collections.IIterator_T_)^ e T.)|[início](../cppcx/begin-function.md)/ [final](../cppcx/end-function.md) ([IMap\<K,V>](/uwp/api/Windows.Foundation.Collections.IMap_K_V_).|
|[Platform::Collections::InputIterator<IKeyValuePair\<K, V>^>](../cppcx/platform-collections-inputiterator-class.md)<br /><br /> (Internamente armazena [IIterator\<T >](/uwp/api/Windows.Foundation.Collections.IIterator_T_)^ e T.)|[begin](../cppcx/begin-function.md)/ [end](../cppcx/end-function.md) ([Windows::Foundation::Collections::IMapView]/uwp/api/Windows.Foundation.Collections.IMapView_K_V_))|

### <a name="collection-change-events"></a>Eventos de alteração de coleção

`Vector` e `Map` oferecem suporte à associação de dados em coleções XAML implementando eventos que ocorrem quando um objeto de coleção é alterado ou redefinido, ou quando um elemento de uma coleção é inserido, removido ou alterado. Você pode escrever seus próprios tipos que ofereçam suporte à associação de dados, embora eles não possam ser herdados de `Map` nem de `Vector` , pois esses tipos são lacrados.

Os delegados [Windows::Foundation::Collections::VectorChangedEventHandler](/uwp/api/windows.foundation.collections.vectorchangedeventhandler) e [Windows::Foundation::Collections::MapChangedEventHandler](/uwp/api/windows.foundation.collections.mapchangedeventhandler) especificam as assinaturas dos manipuladores de eventos para eventos de alteração da coleção. A classe enum pública [Windows::Foundation::Collections::CollectionChange](/uwp/api/windows.foundation.collections.collectionchange) e as classes ref `Platform::Collection::Details::MapChangedEventArgs` e `Platform::Collections::Details::VectorChangedEventArgs` armazenam os argumentos de eventos para determinar o que provocou o evento. Os `*EventArgs` tipos são definidos `Details` no namespace porque você não precisa construí-los ou consumi-los explicitamente ao usar `Map` ou `Vector`.

## <a name="see-also"></a>Consulte também

[Sistema de tipos](../cppcx/type-system-c-cx.md)<br/>
[Referência da linguagem C++/CX](../cppcx/visual-c-language-reference-c-cx.md)<br/>
[Referência de namespaces](../cppcx/namespaces-reference-c-cx.md)
