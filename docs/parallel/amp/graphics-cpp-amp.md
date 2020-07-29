---
title: Elementos gráficos (C++ AMP)
ms.date: 11/04/2016
ms.assetid: 190a98a4-5f7d-442e-866b-b374ca74c16f
ms.openlocfilehash: e0ea4de44f5215f47fe8c1a5e018bd91a82708ac
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87182805"
---
# <a name="graphics-c-amp"></a>Elementos gráficos (C++ AMP)

C++ AMP contém várias APIs no namespace [Concurrency:: Graphics](../../parallel/amp/reference/concurrency-graphics-namespace.md) que você pode usar para acessar o suporte a textura nas GPUs. Alguns cenários comuns são:

- Você pode usar a classe [Texture](../../parallel/amp/reference/texture-class.md) como um contêiner de dados para computação e exploração da *localidade espacial* do cache de textura e layouts de hardware de GPU. A localidade espacial é a propriedade dos elementos de dados que estão sendo fisicamente próximos uns dos outros.

- O tempo de execução fornece uma interoperabilidade eficiente com sombreadores não computacionais. Sombreadores de pixel, vértice, mosaico e envoltória frequentemente consomem ou produzem texturas que você pode usar em seus C++ AMP cálculos.

- As APIs de gráficos no C++ AMP fornecem maneiras alternativas de acessar os buffers empacotados de subpalavra. As texturas que têm formatos que representam *texels* (elementos de textura) compostos por escalares de 8 ou 16 bits permitem o acesso a tal armazenamento de dados empacotado.

## <a name="the-norm-and-unorm-types"></a>Os tipos normal e unorm

Os `norm` `unorm` tipos e são tipos escalares que limitam o intervalo de **`float`** valores; isso é conhecido como *fixação MSS*. Esses tipos podem ser construídos explicitamente a partir de outros tipos escalares. Na conversão, o valor é primeiro convertido em **`float`** e, em seguida, clamped para a respectiva região permitida por normal [-1,0, 1,0] ou unorm [0,0, 1,0]. Conversão de +/-Infinity retorna +/-1. A conversão de NaN é indefinida. Uma norma pode ser construída implicitamente a partir de um unorm e não há perda de dados. O operador de conversão implícita para float é definido nesses tipos. Os operadores binários são definidos entre esses tipos e outros tipos escalares internos, como **`float`** e **`int`** : +,-, \* ,/, = =,! =, >, \<, > =, <=. Os operadores de atribuição compostos também têm suporte: + =,-=, \* =,/=. O operador de negação unário (-) é definido para tipos normativos.

## <a name="short-vector-library"></a>Biblioteca de vetores curta

A biblioteca de vetores curta fornece algumas das funcionalidades do [tipo de vetor](https://go.microsoft.com/fwlink/p/?linkid=248500) que são definidas em HLSL e normalmente são usadas para definir texels. Um vetor curto é uma estrutura de dados que contém de um a quatro valores do mesmo tipo. Os tipos com suporte são,,,, **`double`** **`float`** **`int`** `norm` `uint` e `unorm` . Os nomes de tipo são mostrados na tabela a seguir. Para cada tipo, há também um correspondente **`typedef`** que não tem um sublinhado no nome. Os tipos que têm os sublinhados estão no [namespace Concurrency:: Graphics](../../parallel/amp/reference/concurrency-graphics-namespace.md). Os tipos que não têm os sublinhados estão no [namespace Concurrency:: Graphics::d irect3d](../../parallel/amp/reference/concurrency-graphics-direct3d-namespace.md) para que eles sejam claramente separados dos tipos fundamentais nomeados de forma semelhante, como **`__int8`** e **`__int16`** .

||Comprimento 2|Comprimento 3|Comprimento 4|
|-|--------------|--------------|--------------|
|double|double_2<br /><br /> double2|double_3<br /><br /> double3|double_4<br /><br /> double4|
|FLOAT|float_2<br /><br /> float2|float_3<br /><br /> float3|float_4<br /><br /> float4|
|INT|int_2<br /><br /> int2|int_3<br /><br /> Int3|int_4<br /><br /> int4|
|norm|norm_2<br /><br /> norm2|norm_3<br /><br /> norm3|norm_4<br /><br /> norm4|
|uint|uint_2<br /><br /> uint2|uint_3<br /><br /> uint3|uint_4<br /><br /> uint4|
|unorm|unorm_2<br /><br /> unorm2|unorm_3<br /><br /> unorm3|unorm_4<br /><br /> unorm4|

### <a name="operators"></a>Operadores

Se um operador for definido entre dois vetores curtos, ele também será definido entre um vetor curto e um escalar. Além disso, um destes deve ser verdadeiro:

- O tipo escalar deve ser o mesmo que o tipo de elemento do vetor pequeno.

- O tipo escalar pode ser convertido implicitamente no tipo de elemento do vetor usando apenas uma conversão definida pelo usuário.

A operação é transportada por componente entre cada componente do vetor curto e o escalar. Estes são os operadores válidos:

|Tipo de operador|Tipos válidos|
|-------------------|-----------------|
|Operadores binários|Válido em todos os tipos: +,-, \* ,/,<br /><br /> Válido em tipos inteiros:%, ^, &#124;, &, <\<, >><br /><br /> Os dois vetores devem ter o mesmo tamanho e o resultado é um vetor do mesmo tamanho.|
|Operadores relacionais|Válido em todos os tipos: = = e! =|
|Operador de atribuição composta|Válido em todos os tipos: + =,-=, \* =,/=<br /><br /> Válido em tipos inteiros:% =, ^ =, &#124;=, &=, <\<=, >>=|
|Operadores de incremento e decremento|Válido em todos os tipos: + +,--<br /><br /> O prefixo e o sufixo são válidos.|
|Operador NOT nonbitry (~)|Válido em tipos inteiros.|
|Operador unário|Válido em todos os tipos, exceto `unorm` e `uint` .|

### <a name="swizzling-expressions"></a>Expressões Swizzling

A biblioteca de vetores curta dá suporte à `vector_type.identifier` construção de acessador para acessar os componentes de um vetor curto. O `identifier` , que é conhecido como uma *expressão swizzling*, especifica os componentes do vetor. A expressão pode ser um l-Value ou um valor de r. Os caracteres individuais no identificador podem ser: x, y, z e w; ou r, g, b e a. "x" e "r" significam o componente zero-th, "y" e "g" significa o primeiro componente e assim por diante. (Observe que "x" e "r" não podem ser usados no mesmo identificador.) Portanto, "RGBA" e "xyzw" retornam o mesmo resultado. Acessadores de componente único, como "x" e "y", são tipos de valor escalar. Acessadores de vários componentes são tipos de vetores curtos. Por exemplo, se você construir um `int_4` vetor nomeado `fourInts` e tiver os valores 2, 4, 6 e 8, `fourInts.y` retornará o inteiro 4 e `fourInts.rg` retornará um `int_2` objeto com os valores 2 e 4.

## <a name="texture-classes"></a>Classes de textura

Muitas GPUs têm hardware e caches otimizados para buscar pixels e texels e para renderizar imagens e texturas. A [classe \<T,N> Texture](../../parallel/amp/reference/texture-class.md) , que é uma classe de contêiner para objetos Texel, expõe a funcionalidade de textura dessas GPUs. Um Texel pode ser:

- Um **`int`** , `uint` , **`float`** , **`double`** , `norm` ou `unorm` escalar.

- Um pequeno vetor que tem dois ou quatro componentes. A única exceção é `double_4` , o que não é permitido.

O `texture` objeto pode ter uma classificação de 1, 2 ou 3. O `texture` objeto só pode ser capturado por referência no lambda de uma chamada para `parallel_for_each` . A textura é armazenada na GPU como objetos de textura de Direct3D. Para obter mais informações sobre texturas e texels no Direct3D, consulte [Introduction to Textures in Direct3D 11](https://go.microsoft.com/fwlink/p/?linkid=248502).

O tipo de Texel que você usa pode ser um dos muitos formatos de textura usados na programação de gráficos. Por exemplo, um formato RGBA poderia usar 32 bits, com 8 bits cada para os elementos R, G, B e escalar. O hardware de textura de uma placa gráfica pode acessar os elementos individuais com base no formato. Por exemplo, se você estiver usando o formato RGBA, o hardware de textura poderá extrair cada elemento de 8 bits em um formato de 32 bits. No C++ AMP, você pode definir o bits por elemento escalar de seu Texel para que você possa acessar automaticamente os elementos escalares individuais no código sem usar a alternância de bits.

### <a name="instantiating-texture-objects"></a>Instanciando objetos de textura

Você pode declarar um objeto de textura sem inicialização. O exemplo de código a seguir declara vários objetos de textura.

```cpp
#include <amp.h>
#include <amp_graphics.h>
using namespace concurrency;
using namespace concurrency::graphics;

void declareTextures() {
    // Create a 16-texel texture of int.
    texture<int, 1> intTexture1(16);
    texture<int, 1> intTexture2(extent<1>(16));

    // Create a 16 x 32 texture of float_2.
    texture<float_2, 2> floatTexture1(16, 32);
    texture<float_2, 2> floatTexture2(extent<2>(16, 32));

    // Create a 2 x 4 x 8 texture of uint_4.
    texture<uint_4, 3> uintTexture1(2, 4, 8);
    texture<uint_4, 3> uintTexture2(extent<3>(2, 4, 8));
}
```

Você também pode usar um construtor para declarar e inicializar um `texture` objeto. O exemplo de código a seguir instancia um `texture` objeto de um vetor de `float_4` objetos. O elemento bits por escala é definido como o padrão. Você não pode usar esse construtor com `norm` , `unorm` ou os vetores curtos de `norm` e `unorm` , porque eles não têm um bits padrão por elemento escalar.

```cpp
#include <amp.h>
#include <amp_graphics.h>
#include <vector>
using namespace concurrency;
using namespace concurrency::graphics;

void initializeTexture() {
    std::vector<int_4> texels;
    for (int i = 0; i < 768 * 1024; i++) {
        int_4 i4(i, i, i, i);
        texels.push_back(i4);
    }

    texture<int_4, 2> aTexture(768, 1024, texels.begin(), texels.end());
}
```

Você também pode declarar e inicializar um `texture` objeto usando uma sobrecarga de construtor que usa um ponteiro para os dados de origem, o tamanho dos dados de origem em bytes e o elemento bits por escala.

```cpp
void createTextureWithBPC() { // Create the source data.
    float source[1024* 2];
    for (int i = 0; i <1024* 2; i++) {
        source[i] = (float)i;
    }
    // Initialize the texture by using the size of source in bytes // and bits per scalar element.
    texture<float_2, 1> floatTexture(1024, source, (unsigned int)sizeof(source), 32U);
}
```

As texturas nesses exemplos são criadas na exibição padrão do acelerador padrão. Você pode usar outras sobrecargas do Construtor se desejar especificar um `accelerator_view` objeto. Não é possível criar um objeto de textura em um acelerador de CPU.

Há limites no tamanho de cada dimensão do `texture` objeto, conforme mostrado na tabela a seguir. Um erro de tempo de execução será gerado se você exceder os limites.

|Textura|Limitação de tamanho por dimensão|
|-------------|---------------------|
|textura\<T,1>|16384|
|textura\<T,2>|16384|
|textura\<T,3>|2.048|

### <a name="reading-from-texture-objects"></a>Lendo de objetos de textura

Você pode ler um `texture` objeto usando o operador [Texture:: Operator \[ \] ](reference/texture-class.md#operator_at), [Texture:: Operator ()](reference/texture-class.md#operator_call)ou [textura:: Get](reference/texture-class.md#get). Os dois operadores retornam um valor, não uma referência. Portanto, você não pode gravar em um `texture` objeto usando `texture::operator\[\]` .

```cpp
void readTexture() {
    std::vector<int_2> src;
    for (int i = 0; i <16 *32; i++) {
        int_2 i2(i, i);

        src.push_back(i2);
    }

    std::vector<int_2> dst(16* 32);

    array_view<int_2, 2> arr(16, 32, dst);

    arr.discard_data();

    const texture<int_2, 2> tex9(16, 32, src.begin(), src.end());

    parallel_for_each(tex9.extent, [=, &tex9] (index<2> idx) restrict(amp) { // Use the subscript operator.
        arr[idx].x += tex9[idx].x; // Use the function () operator.
        arr[idx].x += tex9(idx).x; // Use the get method.
        arr[idx].y += tex9.get(idx).y; // Use the function () operator.
        arr[idx].y += tex9(idx[0], idx[1]).y;
    });

    arr.synchronize();
}
```

O exemplo de código a seguir demonstra como armazenar canais de textura em um vetor curto e, em seguida, acessar os elementos escalares individuais como propriedades do vetor curto.

```cpp
void UseBitsPerScalarElement() { // Create the image data. // Each unsigned int (32-bit) represents four 8-bit scalar elements(r,g,b,a values).
    const int image_height = 16;
    const int image_width = 16;
    std::vector<unsigned int> image(image_height* image_width);

    extent<2> image_extent(image_height, image_width);

    // By using uint_4 and 8 bits per channel, each 8-bit channel in the data source is // stored in one 32-bit component of a uint_4.
    texture<uint_4, 2> image_texture(image_extent, image.data(), image_extent.size()* 4U,  8U);

    // Use can access the RGBA values of the source data by using swizzling expressions of the uint_4.
    parallel_for_each(image_extent,
        [&image_texture](index<2> idx) restrict(amp)
        { // 4 bytes are automatically extracted when reading.
            uint_4 color = image_texture[idx];
            unsigned int r = color.r;
            unsigned int g = color.g;
            unsigned int b = color.b;
            unsigned int a = color.a;
        });
}
```

A tabela a seguir lista os bits válidos por canal para cada tipo de vetor de classificação.

|Tipo de dados Texture|Bits válidos por elemento escalar|
|-----------------------|-----------------------------------|
|int, int_2, int_4<br /><br /> uint, uint_2, uint_4|8, 16, 32|
|int_3, uint_3|32|
|float, float_2, float_4|16, 32|
|float_3|32|
|Double, double_2|64|
|Norma, norm_2 norm_4<br /><br /> unorm, unorm_2, unorm, 4|8, 16|

### <a name="writing-to-texture-objects"></a>Gravando em objetos de textura

Use o método [Texture:: Set](reference/texture-class.md#set) para gravar em `texture` objetos. Um objeto de textura pode ser ReadOnly ou de leitura/gravação. Para que um objeto de textura seja legível e gravável, as seguintes condições devem ser verdadeiras:

- T tem apenas um componente escalar. (Não são permitidos vetores curtos.)

- T não é **`double`** , `norm` , ou `unorm` .

- A `texture::bits_per_scalar_element` propriedade é 32.

Se todos os três não forem verdadeiros, o `texture` objeto será ReadOnly. As duas primeiras condições são verificadas durante a compilação. Um erro de compilação será gerado se você tiver um código que tente gravar em um `readonly` objeto de textura. A condição para `texture::bits_per_scalar_element` é detectada em tempo de execução e o tempo de execução gera a exceção [unsupported_feature](../../parallel/amp/reference/unsupported-feature-class.md) se você tentar gravar em um `texture` objeto ReadOnly.

O exemplo de código a seguir grava valores em um objeto de textura.

```cpp
void writeTexture() {
    texture<int, 1> tex1(16);

    parallel_for_each(tex1.extent, [&tex1] (index<1> idx) restrict(amp) {
        tex1.set(idx, 0);
    });
}
```

### <a name="copying-texture-objects"></a>Copiando objetos de textura

Você pode copiar entre objetos de textura usando a função de [cópia](reference/concurrency-namespace-functions-amp.md#copy) ou a função [copy_async](reference/concurrency-namespace-functions-amp.md#copy_async) , conforme mostrado no exemplo de código a seguir.

```cpp
void copyHostArrayToTexture() { // Copy from source array to texture object by using the copy function.
    float floatSource[1024* 2];
    for (int i = 0; i <1024* 2; i++) {
        floatSource[i] = (float)i;
    }
    texture<float_2, 1> floatTexture(1024);

    copy(floatSource, (unsigned int)sizeof(floatSource), floatTexture);

    // Copy from source array to texture object by using the copy function.
    char charSource[16* 16];
    for (int i = 0; i <16* 16; i++) {
        charSource[i] = (char)i;
    }
    texture<int, 2> charTexture(16, 16, 8U);

    copy(charSource, (unsigned int)sizeof(charSource), charTexture);
    // Copy from texture object to source array by using the copy function.
    copy(charTexture, charSource, (unsigned int)sizeof(charSource));
}
```

Você também pode copiar de uma textura para outra usando o método [Texture:: copy_to](reference/texture-class.md#copy_to) . As duas texturas podem estar em diferentes accelerator_views. Quando você copia para um `writeonly_texture_view` objeto, os dados são copiados para o `texture` objeto subjacente. Os bits por elemento escalar e a extensão devem ser os mesmos nos objetos de origem e de destino `texture` . Se esses requisitos não forem atendidos, o tempo de execução lançará uma exceção.

## <a name="texture-view-classes"></a>Classes de exibição de textura

C++ AMP apresenta a [classe texture_view](../../parallel/amp/reference/texture-view-class.md) no Visual Studio 2013. As exibições de textura dão suporte aos mesmos tipos Texel e classifica como a [classe de textura](../../parallel/amp/reference/texture-class.md), mas ao contrário de texturas, elas fornecem acesso a recursos adicionais de hardware, como amostragem de textura e mipmaps. As exibições de textura dão suporte a somente leitura, somente gravação e acesso de leitura/gravação aos dados de textura subjacentes.

- O acesso somente leitura é fornecido pela `texture_view<const T, N>` especialização de modelo, que dá suporte a elementos que têm 1, 2 ou 4 componentes, amostragem de textura e acesso dinâmico a um intervalo de níveis de mipmap que são determinados quando a exibição é instanciada.

- O acesso somente gravação é fornecido pela classe de modelo não especializada `texture_view<T, N>` , que dá suporte a elementos que têm dois ou 4 componentes e pode acessar um nível de mipmap que é determinado quando a exibição é instanciada. Ele não dá suporte à amostragem.

- O acesso de leitura/gravação é fornecido pela classe de modelo não especializada `texture_view<T, N>` , que, como texturas, dá suporte a elementos que têm apenas um componente; a exibição pode acessar um nível de mipmap que é determinado quando é instanciado. Ele não dá suporte à amostragem.

As exibições de textura são análogas às exibições de matriz, mas não fornecem a funcionalidade de movimentação e gerenciamento automático de dados que a [classe array_view](../../parallel/amp/reference/array-view-class.md) fornece sobre a [classe de matriz](../../parallel/amp/reference/array-class.md). Um `texture_view` só pode ser acessado no modo de exibição acelerador onde residem os dados subjacentes de textura.

### <a name="writeonly_texture_view-deprecated"></a>writeonly_texture_view preterido

Por Visual Studio 2013, C++ AMP introduz um suporte melhor para recursos de textura de hardware, como amostragem e mipmaps, que não podem ser suportados pela [classe writeonly_texture_view](../../parallel/amp/reference/writeonly-texture-view-class.md). A classe introduzida recentemente `texture_view` dá suporte a um superconjunto da funcionalidade no `writeonly_texture_view` ; como resultado, `writeonly_texture_view` é preterida.

Recomendamos, pelo menos, um novo código, que você usa `texture_view` para acessar a funcionalidade que foi fornecida anteriormente pelo `writeonly_texture_view` . Compare os dois exemplos de código a seguir que gravam em um objeto de textura que tem dois componentes (int_2). Observe que em ambos os casos, a exibição, `wo_tv4` , deve ser capturada por valor na expressão lambda. Este é o exemplo que usa a nova `texture_view` classe:

```cpp
void write2ComponentTexture() {
    texture<int_2, 1> tex4(16);

    texture_view<int_2, 1> wo_tv4(tex4);

    parallel_for_each(extent<1>(16), [=] (index<1> idx) restrict(amp) {
        wo_tv4.set(idx, int_2(1, 1));
    });
}
```

E aqui está a classe preterida `writeonly_texture_view` :

```cpp
void write2ComponentTexture() {
    texture<int_2, 1> tex4(16);

    writeonly_texture_view<int_2, 1> wo_tv4(tex4);

    parallel_for_each(extent<1>(16), [=] (index<1> idx) restrict(amp) {
        wo_tv4.set(idx, int_2(1, 1));
    });
}
```

Como você pode ver, os dois exemplos de código são quase idênticos quando tudo o que você está fazendo é gravar no nível de mipmap primário. Se você usou `writeonly_texture_view` em código existente e não estiver planejando aprimorar esse código, não precisará alterá-lo. No entanto, se você estiver pensando em trazer esse código para frente, sugerimos que você o reescreva para uso `texture_view` porque os aprimoramentos nele dão suporte a novos recursos de textura de hardware. Continue lendo para obter mais informações sobre esses novos recursos.

Para obter mais informações sobre a substituição de `writeonly_texture_view` , consulte [visão geral do design de exibição de textura em C++ amp](/archive/blogs/nativeconcurrency/overview-of-the-texture-view-design-in-c-amp) no blog de programação paralela em código nativo.

### <a name="instantiating-texture-view-objects"></a>Instanciando objetos de exibição de textura

Declarar um `texture_view` é semelhante a declarar um `array_view` que está associado a uma **matriz**. O exemplo de código a seguir declara vários `texture` objetos e `texture_view` objetos associados a eles.

```cpp
#include <amp.h>
#include <amp_graphics.h>
using namespace concurrency;
using namespace concurrency::graphics;

void declareTextureViews()
{
    // Create a 16-texel texture of int, with associated texture_views.
    texture<int, 1> intTexture(16);
    texture_view<const int, 1> intTextureViewRO(intTexture);  // read-only
    texture_view<int, 1> intTextureViewRW(intTexture);        // read-write

    // Create a 16 x 32 texture of float_2, with associated texture_views.
    texture<float_2, 2> floatTexture(16, 32);
    texture_view<const float_2, 2> floatTextureViewRO(floatTexture);  // read-only
    texture_view<float_2, 2> floatTextureViewRO(floatTexture);        // write-only

    // Create a 2 x 4 x 8 texture of uint_4, with associated texture_views.
    texture<uint_4, 3> uintTexture(2, 4, 8);
    texture_view<const uint_4, 3> uintTextureViewRO(uintTexture);  // read-only
    texture_view<uint_4, 3> uintTextureViewWO(uintTexture);        // write-only
}
```

Observe como uma exibição de textura cujo tipo de elemento é não const e tem um componente é de leitura/gravação, mas uma exibição de textura cujo tipo de elemento é não const, mas que tem mais de um componenent são somente gravação. As exibições de textura dos tipos de elementos const são sempre somente leitura, mas se o tipo de elemento não for const, o número de componentes no elemento determinará se ele é de leitura/gravação (1 componente) ou somente gravação (vários componentes).

O tipo de elemento de a `texture_view` — seu const-qualidade e também o número de componentes que ele tem — também desempenha uma função para determinar se a exibição dá suporte à amostragem de textura e como os níveis de mipmap podem ser acessados:

|Type|Componentes|Ler|Gravar|amostragem|Acesso mipmap|
|----------|----------------|----------|-----------|--------------|-------------------|
|texture_view\<const T, N>|1, 2, 4|Sim|Não (1)|Sim|Sim, indexável. O intervalo é determinado na instanciação.|
|Texture_view\<T, N>|1<br /><br /> 2, 4|Sim<br /><br /> Não (2)|Sim<br /><br /> Sim|Não (1)<br /><br /> Não (1)|Sim, um nível. O nível é determinado na instanciação.<br /><br /> Sim, um nível. O nível é determinado na instanciação.|

Nessa tabela, você pode ver que exibições de textura somente leitura suportam totalmente os novos recursos do Exchange para não serem capazes de gravar no modo de exibição. As exibições de textura graváveis são limitadas, pois só podem acessar um nível de mipmap. As exibições de textura de leitura e gravação são ainda mais especializadas do que aquelas graváveis, pois elas adicionam o requisito de que o tipo de elemento da exibição de textura tem apenas um componente. Observe que a amostragem não tem suporte para exibições de textura graváveis porque é uma operação orientada para leitura.

### <a name="reading-from-texture-view-objects"></a>Lendo de objetos de exibição de textura

A leitura de dados de textura não amostrados por meio de uma exibição de textura é apenas como a leitura da própria textura, exceto que as texturas são capturadas por referência, enquanto as exibições de textura são capturadas por valor. Os dois exemplos de código a seguir demonstram; Primeiro, usando `texture` apenas:

```cpp
void write2ComponentTexture() {
    texture<int_2, 1> text_data(16);

    parallel_for_each(extent<1>(16), [&] (index<1> idx) restrict(amp) {
        tex_data.set(idx, int_2(1, 1));
    });
}
```

E aqui está o mesmo exemplo, exceto que agora ele usa a `texture_view` classe:

```cpp
void write2ComponentTexture() {
    texture<int_2, 1> tex_data(16);

    texture_view<int_2, 1> tex_view(tex_data);

    parallel_for_each(extent<1>(16), [=] (index<1> idx) restrict(amp) {
        tex_view.set(idx, int_2(1, 1));
    });
}
```

Exibições de textura cujos elementos são baseados em tipos de ponto flutuante — por exemplo, float, float_2 ou float_4 — também podem ser lidos usando a amostragem de textura para tirar proveito do suporte de hardware para vários modos de filtragem e modos de endereçamento. O C++ AMP dá suporte aos dois modos de filtragem que são mais comuns em cenários de computação – filtragem de ponto (vizinho mais próximo) e filtragem linear (média ponderada) – e quatro modos de endereçamento — encapsulado, espelhado, clamped e Border. Para obter mais informações sobre os modos de endereçamento, consulte [Address_mode Enumeration](reference/concurrency-graphics-namespace-enums.md#address_mode).

Além dos modos que C++ AMP dá suporte diretamente, você pode acessar outros modos de filtragem e os modos de endereçamento da plataforma subjacente usando as APIs de interoperabilidade para adotar uma amostra de textura que foi criada usando as APIs de plataforma diretamente. Por exemplo, o Direct3D dá suporte a outros modos de filtragem, como a filtragem de anisotropic, e pode aplicar um modo de endereçamento diferente a cada dimensão de uma textura. Você pode criar uma amostra de textura cujas coordenadas são encapsuladas verticalmente, espelhadas horizontalmente e amostradas com a filtragem de anisotropic usando as APIs do Direct3D e, em seguida, aproveitar a amostra em seu código de C++ AMP usando a `make_sampler` API de interoperabilidade. Para obter mais informações, consulte [amostragem de textura em C++ amp](/archive/blogs/nativeconcurrency/texture-sampling-in-c-amp) no blog sobre programação paralela em código nativo.

As exibições de textura também dão suporte à leitura de mipmaps. As exibições de textura somente leitura (aquelas que têm um tipo de elemento const) oferecem mais flexibilidade porque um intervalo de níveis MIP que é determinado na instanciação pode ser automaticamente amostrado e porque os elementos que têm 1, 2 ou 4 componentes têm suporte. As exibições de textura de leitura/gravação que têm elementos que têm um componente também oferecem suporte a mipmaps, mas apenas de um nível que é determinado na instanciação. Para obter mais informações, consulte [textura com mipmaps](/archive/blogs/nativeconcurrency/texture-with-mipmaps) no blog sobre a programação paralela em código nativo.

### <a name="writing-to-texture-view-objects"></a>Gravando em objetos de exibição de textura

Use o [método texture_view:: Get](reference/texture-view-class.md#get) para gravar no subjacente `texture` por meio do `texture_view` objeto. Uma exibição de textura pode ser somente leitura, leitura/gravação ou somente gravação. Para que uma exibição de textura seja gravável, ela deve ter um tipo de elemento que seja não const; para que uma exibição de textura seja legível e gravável, seu tipo de elemento também deve ter apenas um componente. Caso contrário, a exibição de textura será somente leitura. Você só pode acessar um nível mipmap de uma textura por vez por meio de uma exibição de textura e o nível é especificado quando a exibição é instanciada.

Este exemplo mostra como gravar no segundo nível de mipmap mais detalhado de uma textura que tem quatro níveis de mipmap. O nível de mipmap mais detalhado é nível 0.

```cpp
// Create a texture that has 4 mipmap levels : 16x16, 8x8, 4x4, 2x2
texture<int, 2> tex(extent<2>(16, 16), 16U, 4);

// Create a writable texture view to the second mipmap level :4x4
texture_view<int, 2> w_view(tex, 1);

parallel_for_each(w_view.extent, [=](index<2> idx) restrict(amp)
{
    w_view.set(idx, 123);
});
```

## <a name="interoperability"></a>Interoperabilidade

O tempo de execução do C++ AMP dá suporte à interoperabilidade entre `texture<T,1>` o e a [interface ID3D11Texture1D](https://go.microsoft.com/fwlink/p/?linkId=248503), entre `texture<T,2>` o e a [interface ID3D11Texture2D](https://go.microsoft.com/fwlink/p/?linkId=255317), e entre `texture<T,3>` e a [interface ID3D11Texture3D](https://go.microsoft.com/fwlink/p/?linkId=255377). O método [get_texture](reference/concurrency-graphics-direct3d-namespace-functions.md#get_texture) pega um `texture` objeto e retorna uma `IUnknown` interface. O método [make_texture](reference/concurrency-graphics-direct3d-namespace-functions.md#make_texture) usa uma `IUnknown` interface e um `accelerator_view` objeto e retorna um `texture` objeto.

## <a name="see-also"></a>Confira também

[Classe double_2](../../parallel/amp/reference/double-2-class.md)<br/>
[Classe double_3](../../parallel/amp/reference/double-3-class.md)<br/>
[Classe double_4](../../parallel/amp/reference/double-4-class.md)<br/>
[Classe float_2](../../parallel/amp/reference/float-2-class.md)<br/>
[Classe float_3](../../parallel/amp/reference/float-3-class.md)<br/>
[Classe float_4](../../parallel/amp/reference/float-4-class.md)<br/>
[Classe int_2](../../parallel/amp/reference/int-2-class.md)<br/>
[Classe int_3](../../parallel/amp/reference/int-3-class.md)<br/>
[Classe int_4](../../parallel/amp/reference/int-4-class.md)<br/>
[Classe norm_2](../../parallel/amp/reference/norm-2-class.md)<br/>
[Classe norm_3](../../parallel/amp/reference/norm-3-class.md)<br/>
[Classe norm_4](../../parallel/amp/reference/norm-4-class.md)<br/>
[Estrutura short_vector](../../parallel/amp/reference/short-vector-structure.md)<br/>
[Estrutura short_vector_traits](../../parallel/amp/reference/short-vector-traits-structure.md)<br/>
[Classe uint_2](../../parallel/amp/reference/uint-2-class.md)<br/>
[Classe uint_3](../../parallel/amp/reference/uint-3-class.md)<br/>
[Classe uint_4](../../parallel/amp/reference/uint-4-class.md)<br/>
[Classe unorm_2](../../parallel/amp/reference/unorm-2-class.md)<br/>
[Classe unorm_3](../../parallel/amp/reference/unorm-3-class.md)<br/>
[Classe unorm_4](../../parallel/amp/reference/unorm-4-class.md)
