---
title: Coleções (C++/CX)
ms.date: 11/19/2018
ms.assetid: 914da30b-aac5-4cd7-9da3-a5ac08cdd72c
ms.openlocfilehash: d256e333ddf31bdb637680b70718af85e753a21d
ms.sourcegitcommit: 9e891eb17b73d98f9086d9d4bfe9ca50415d9a37
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/20/2018
ms.locfileid: "52176387"
---
# <a name="collections-ccx"></a>Coleções (C++/CX)

No C + + / programa c++ /CX, você pode usar livremente de contêineres STL Standard Template Library () ou qualquer outro tipo de coleção definida pelo usuário. No entanto, quando você passa coleções e para trás pela interface de binária de aplicativo (ABI) do tempo de execução do Windows — por exemplo, para um controle XAML ou para um cliente JavaScript — você deve usar tipos de coleção de tempo de execução do Windows.

O tempo de execução do Windows define as interfaces para coleções e tipos relacionados e C + + c++ /CLI CX fornece as implementações C++ concretas no arquivo de cabeçalho Collection. h. Esta ilustração mostra as relações entre os tipos de coleção:

![C&#43;&#43;&#47;árvore de herança do CX para tipos de coleção](../cppcx/media/cppcxcollectionsinheritancetree.png "C&#43;&#43;&#47;árvore de herança do CX para tipos de coleção")

- A [classe Platform::Collections::Vector](../cppcx/platform-collections-vector-class.md) é semelhante à [classe std::vector](../standard-library/vector-class.md).

- A [classe Platform::Collections::Map](../cppcx/platform-collections-map-class.md) é semelhante à [classe std::map](../standard-library/map-class.md).

- A[classe Platform::Collections::VectorView](../cppcx/platform-collections-vectorview-class.md) e a[classe Platform::Collections::MapView](../cppcx/platform-collections-mapview-class.md) são versões somente leitura de `Vector` e a `Map`.

- Iteradores são definidos no [namespace Platform::Collections](../cppcx/platform-collections-namespace.md). Esses iteradores satisfazem os requisitos para iteradores STL e permitem o uso de [std::find](../standard-library/algorithm-functions.md#find),  [std::count_if](../standard-library/algorithm-functions.md#count_if)e outros algoritmos STL em qualquer tipo de interface [Windows::Foundation::Collections](https://msdn.microsoft.com/library/windows/apps/windows.foundation.collections.aspx) ou tipo concreto [Platform::Collections](../cppcx/platform-collections-namespace.md) . Por exemplo, isso significa que você pode iterar uma coleção em um componente de tempo de execução do Windows que é criado em c# e aplica um algoritmo STL a ele.

   > [!IMPORTANT]
   > Os iteradores proxy `VectorIterator` e `VectorViewIterator` utilizam os objetos proxy `VectoryProxy<T>` e `ArrowProxy<T>` para permitir o uso com contêineres STL. Para obter mais informações, consulte "Elementos VectorProxy" mais adiante neste artigo.

- O C + + c++ /CLI a segurança do thread mesmo garante que os contêineres STL dão suporte a tipos de coleção do CX.

- [Windows::Foundation::Collections::IObservableVector](/uwp/api/Windows.Foundation.Collections.IObservableVector_T_) e [Windows::Foundation::Collections::IObservableMap](/uwp/api/Windows.Foundation.Collections.IObservableMap_K_V_) definem eventos que são acionados quando a coleção é alterada de várias maneiras. Com a implementação dessas interfaces,  [Platform::Collections::Map](../cppcx/platform-collections-map-class.md) e [Platform::Collections::Vector](../cppcx/platform-collections-vector-class.md) oferecem suporte à associação de dados com coleções XAML. Por exemplo, se você tiver um `Vector` com dados associados a `Grid`, quando você adicionar um item a uma coleção, a alteração será refletida na interface de usuário da grade.

## <a name="vector-usage"></a>Uso do vetor

Quando sua classe precisar passar um contêiner de sequência para outro componente de tempo de execução do Windows, use [Collections:: IVector\<T >](https://msdn.microsoft.com/library/windows/apps/br206631.aspx) como o parâmetro ou tipo de retorno, e [Platform:: Collections::Vector\<T >](../cppcx/platform-collections-vector-class.md) como a implementação concreta. Se você tentar usar um tipo `Vector` em um valor ou parâmetro de retorno público, será gerado o erro do compilador C3986. Você pode corrigir o erro alterando `Vector` para `IVector`.

> [!IMPORTANT]
> Se você estiver passando uma sequência no seu próprio programa, use `Vector` ou `std::vector` , pois eles são mais eficientes do que `IVector`. Use `IVector` somente ao passar o contêiner pela ABI.
>
> O sistema de tipo de tempo de execução do Windows não suporta o conceito de matrizes denteadas e, portanto, você não pode passar um IVector < Platform:: array\<T >> como um parâmetro de método ou valor de retorno. Para passar uma matriz denteada ou uma sequência de sequências através da ABI, use `IVector<IVector<T>^>`.

`Vector<T>` fornece os métodos necessários para adição, remoção e acesso a itens na coleção e é implicitamente conversível em `IVector<T>`. Você também pode usar algoritmos STL em instâncias de `Vector<T>`. O exemplo a seguir demonstra alguns usos básicos. As funções [begin](../cppcx/begin-function.md) e [end](../cppcx/end-function.md) aqui são do namespace `Platform::Collections` , não do namespace `std` .

[!code-cpp[cx_collections#01](../cppcx/codesnippet/CPP/collections/class1.cpp#01)]

Se você tiver um código que usa `std::vector` e você quiser reutilizá-lo em um componente de tempo de execução do Windows, basta usar uma da `Vector` construtores que usa um `std::vector` ou um par de iteradores para construir um `Vector` no ponto em que você passa o coleção pela ABI. O exemplo a seguir mostra como usar o construtor de movimentação `Vector` para inicialização eficiente de um `std::vector`. Após a operação de movimentação, a variável de `vec` original não será mais válida.

[!code-cpp[cx_collections#02](../cppcx/codesnippet/CPP/collections/class1.cpp#02)]

Se você tiver um vetor de cadeias de caracteres que deve passar pela ABI em algum ponto futuro, será preciso decidir se as cadeias de caracteres serão criadas inicialmente como tipos de `std::wstring` ou como tipos de `Platform::String^` . Se for necessário muito processamento nessas cadeias de caracteres, use `wstring`. Caso contrário, crie as cadeias de caracteres como tipos de `Platform::String^` e evite o custo de convertê-las posteriormente. Você também deve decidir se essas cadeias de caracteres serão colocadas em um `std:vector` ou `Platform::Collections::Vector` internamente. Como prática geral, use `std::vector` e crie um `Platform::Vector` a partir dele somente quando passar o contêiner pela ABI.

## <a name="value-types-in-vector"></a>Tipos de valor no vetor

Qualquer elemento a ser armazenado em um [Platform::Collections::Vector](../cppcx/platform-collections-vector-class.md) deve oferecer suporte à comparação de igualdade, seja implicitamente ou usando um comparador personalizado [std::equal_to](../standard-library/equal-to-struct.md) que você fornece. Todos os tipos de referência e todos os tipos escalares oferecem suporte implicitamente às comparações de igualdade. Para os tipos de valor não escalar, como [Windows::Foundation::DateTime](https://msdn.microsoft.com/library/windows/apps/windows.foundation.datetime.aspx), ou para comparações personalizadas (por exemplo, `objA->UniqueID == objB->UniqueID`), é necessário fornecer um objeto de função personalizado.

## <a name="vectorproxy-elements"></a>Elementos VectorProxy

[{1&gt;Platform::Collections::vectoriterator&lt;1](../cppcx/platform-collections-vectoriterator-class.md) e [Platform::Collections::vectorviewiterator&lt;1}](../cppcx/platform-collections-vectorviewiterator-class.md) permitem o uso de `range for` loops e algoritmos como [4&gt;std::Sort&lt;4](../standard-library/algorithm-functions.md#sort) com um [ IVector\<T >](https://msdn.microsoft.com/library/windows/apps/br206631.aspx) contêiner. Porém, os elementos `IVector` não podem ser acessados por meio do desreferenciamento do ponteiro C++; eles podem ser acessados somente por pelos métodos [GetAt](https://msdn.microsoft.com/library/windows/apps/br206634.aspx) e [SetAt](https://msdn.microsoft.com/library/windows/apps/br206642.aspx) . Portanto, esses iteradores usam as classes de proxy `Platform::Details::VectorProxy<T>` e `Platform::Details::ArrowProxy<T>` para fornecer acesso aos elementos individuais por meio __\*__, __->__ e  __\[]__ operadores, conforme exigido pela biblioteca padrão. Estritamente falando, dado um `IVector<Person^> vec`, o tipo de `*begin(vec)` será `VectorProxy<Person^>`. Entretanto, o objeto proxy é quase sempre transparente ao seu código. Esses objetos proxy não estão documentados porque são apenas para uso interno dos iteradores, mas é útil saber como o mecanismo funciona.

Quando você usar um loop `range for` sobre contêineres `IVector` , use `auto&&` para habilitar a variável de iterador para associar corretamente aos elementos `VectorProxy` . Se você usar `auto` ou `auto&`, o aviso do compilador C4239 será gerado e `VectoryProxy` será mencionado no texto de aviso.

A ilustração a seguir mostra um loop `range for` sobre um `IVector<Person^>`. Observe que a execução é interrompida no ponto de interrupção na linha 64. A janela **QuickWatch** mostra que a variável de iterador `p` é na verdade um `VectorProxy<Person^>` que tem as variáveis de membro `m_v` e `m_i` . Entretanto, quando você chama `GetType` nessa variável, é retornado o tipo idêntico à instância `Person` de `p2`. A conclusão é que, embora `VectorProxy` e `ArrowProxy` possam aparecer em **QuickWatch**, determinados erros do compilador do depurador, ou outros locais, geralmente não precisam ter uma codificação explícita para eles.

![VectorProxy no intervalo&#45;com base em loop for](../cppcx/media/vectorproxy-1.png "VectorProxy no intervalo&#45;com base em loop for")

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

Este exemplo mostra como inserir itens e observá-los em um [Platform::Collections::Map&lt;2](../cppcx/platform-collections-map-class.md)e, em seguida, retornar o `Map` como um somente leitura [3&gt;{4&gt;Windows::Foundation::Collections::imapview&lt;4}&lt;3}] / uwp/api / Tipo de Windows.Foundation.Collections.IMapView_K_V_).

[!code-cpp[cx_collections#04](../cppcx/codesnippet/CPP/collections/class1.cpp#04)]

Em geral, para a funcionalidade de mapa interna, prefira o tipo `std::map` por motivos de desempenho. Se precisar transmitir o contêiner pela ABI, construa um [Platform::Collections::Map](../cppcx/platform-collections-map-class.md) a partir de [std::map](../standard-library/map-class.md) e retorne `Map` como um [Windows::Foundation::Collections::IMap](/uwp/api/Windows.Foundation.Collections.IMap_K_V_). Se você tentar usar um tipo `Map` em um valor ou parâmetro de retorno público, será gerado o erro do compilador C3986. Você pode corrigir o erro alterando `Map` para `IMap`. Em alguns casos (por exemplo, se você não estiver fazendo um grande número de pesquisas ou inserções e estiver passando a coleção pela ABI frequentemente), poderá ser menos caro usar `Platform::Collections::Map` desde o início e evitar o custo de converter o `std::map`. Em qualquer caso, evite as operações de pesquisa e inserção em um `IMap` , pois elas são as menos eficazes dos três tipos. Converta em `IMap` somente no ponto em que você passa o contêiner pela ABI.

## <a name="value-types-in-map"></a>Tipos de valor no mapa

Os elementos de um [Platform::Collections::Map](../cppcx/platform-collections-map-class.md) são ordenados. Qualquer elemento a ser armazenado em um `Map` deve oferecer suporte à comparação de inferioridade com ordenação fraca estrita, seja implicitamente ou usando um comparador personalizado [stl::less](../standard-library/less-struct.md) fornecido por você. Os tipos escalares oferecem suporte à comparação implicitamente. Para os tipos de valor não escalar, como `Windows::Foundation::DateTime`, ou para comparações personalizadas (por exemplo, `objA->UniqueID < objB->UniqueID`), você deverá fornecer um comparador personalizado.

## <a name="collection-types"></a>Tipos de coleção

As coleções se enquadram em quatro categorias: versões modificáveis e somente leitura das coleções de sequência e coleções associativas. Além disso, C + + c++ /CX aprimora as coleções fornecendo três classes de iterador que simplificam o acesso de coleções.

Os elementos de uma coleção modificável podem ser alterados, mas os elementos de uma coleção somente leitura, que é conhecida como *exibição*, só podem ser lidos. Elementos de uma [Platform::Collections::Vector&lt;2](../cppcx/platform-collections-vector-class.md) ou[Platform::Collections::vectorview&lt;1}](../cppcx/platform-collections-vectorview-class.md) coleção pode ser acessada por meio da coleção ou de um iterador [Vector:: getat](../cppcx/platform-collections-vector-class.md#getat) e um índice. Elementos de uma coleção associativa podem ser acessados por meio da coleção [Map:: Lookup](../cppcx/platform-collections-map-class.md#lookup) e uma chave.

[classe Platform::Collections::Map](../cppcx/platform-collections-map-class.md)<br/>
uma coleção modificável, associativa. Os elementos de mapa são pares chave-valor. Há suporte para as operações de pesquisar uma chave para recuperar seu valor associado e iterar por todos os pares chave-valor.

`Map` e `MapView` se tornam modelos no `<K, V, C = std::less<K>>`; portanto, você pode personalizar o comparador.  Além disso, `Vector` e `VectorView` se tornam modelos no `<T, E = std::equal_to<T>>` para que você possa personalizar o comportamento de `IndexOf()`. Isso é importante principalmente para `Vector` e `VectorView` e estruturas de valor. Por exemplo, para criar um vetor\<DateTime >, você deve fornecer um comparador personalizado, pois DateTime não sobrecarrega o operador = =.

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

Para simplificar o uso de STL para processar `Vector`, `VectorView`, `Map`, `MapView`e arbitrário `Windows::Foundation::Collections` objetos C + +, c++ /CLI CX dá suporte a sobrecargas do [função begin](../cppcx/begin-function.md) e [final Função](../cppcx/end-function.md) funções não membro.

A tabela a seguir lista os iteradores e as funções disponíveis.

|Iterators|Funções|
|---------------|---------------|
|[Platform::Collections::VectorIterator\<T>](../cppcx/platform-collections-vectoriterator-class.md)<br /><br /> (Armazena internamente [Collections:: IVector\<T >](https://msdn.microsoft.com/library/windows/apps/br206631.aspx) e int.)|[Comece](../cppcx/begin-function.md)/ [final](../cppcx/end-function.md)([Collections:: IVector\<T >](https://msdn.microsoft.com/library/windows/apps/br206631.aspx))|
|[Platform::Collections::VectorViewIterator\<T>](../cppcx/platform-collections-vectorviewiterator-class.md)<br /><br /> (Armazena internamente [IVectorView\<T >](https://msdn.microsoft.com/library/windows/apps/br226058.aspx)^ e int.)|[Comece](../cppcx/begin-function.md)/ [final](../cppcx/end-function.md) ([IVectorView\<T >](https://msdn.microsoft.com/library/windows/apps/br226058.aspx)^)|
|[Platform::Collections::InputIterator\<T>](../cppcx/platform-collections-inputiterator-class.md)<br /><br /> (Armazena internamente [IIterator\<T >](https://msdn.microsoft.com/library/windows/apps/br226026.aspx)^ e T.)|[Comece](../cppcx/begin-function.md)/ [final](../cppcx/end-function.md) ([IIterable\<T >](https://msdn.microsoft.com/library/windows/apps/br226024.aspx))|
|[Platform::Collections::InputIterator<IKeyValuePair\<K, V>^>](../cppcx/platform-collections-inputiterator-class.md)<br /><br /> (Armazena internamente [IIterator\<T >](https://msdn.microsoft.com/library/windows/apps/br226026.aspx)^ e T.)|[Comece](../cppcx/begin-function.md)/ [final](../cppcx/end-function.md) ([IMap\<K, V >](/uwp/api/Windows.Foundation.Collections.IMap_K_V_).|
|[Platform::Collections::InputIterator<IKeyValuePair\<K, V>^>](../cppcx/platform-collections-inputiterator-class.md)<br /><br /> (Armazena internamente [IIterator\<T >](https://msdn.microsoft.com/library/windows/apps/br226026.aspx)^ e T.)|[Comece](../cppcx/begin-function.md)/ [final](../cppcx/end-function.md) ([Windows:: Foundation::Collections::IMapView]/uwp/api/Windows.Foundation.Collections.IMapView_K_V_))|

### <a name="collection-change-events"></a>Eventos de alteração de coleção

`Vector` e `Map` oferecem suporte à associação de dados em coleções XAML implementando eventos que ocorrem quando um objeto de coleção é alterado ou redefinido, ou quando um elemento de uma coleção é inserido, removido ou alterado. Você pode escrever seus próprios tipos que ofereçam suporte à associação de dados, embora eles não possam ser herdados de `Map` nem de `Vector` , pois esses tipos são lacrados.

Os delegados [Windows::Foundation::Collections::VectorChangedEventHandler](/uwp/api/windows.foundation.collections.vectorchangedeventhandler) e [Windows::Foundation::Collections::MapChangedEventHandler](/uwp/api/windows.foundation.collections.mapchangedeventhandler) especificam as assinaturas dos manipuladores de eventos para eventos de alteração da coleção. A classe enum pública [Windows::Foundation::Collections::CollectionChange](https://msdn.microsoft.com/library/windows/apps/windows.foundation.collections.collectionchange.aspx) e as classes ref `Platform::Collection::Details::MapChangedEventArgs` e `Platform::Collections::Details::VectorChangedEventArgs` armazenam os argumentos de eventos para determinar o que provocou o evento. O `*EventArgs` tipos são definidos na `Details` namespace porque você não precisa construí-los nem consumi-los explicitamente quando você usa `Map` ou `Vector`.

## <a name="see-also"></a>Consulte também

[Sistema de tipos](../cppcx/type-system-c-cx.md)<br/>
[Referência de linguagem do Visual C++](../cppcx/visual-c-language-reference-c-cx.md)<br/>
[Referência de namespaces](../cppcx/namespaces-reference-c-cx.md)