---
title: Elementos gráficos (C++ AMP) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-amp
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 190a98a4-5f7d-442e-866b-b374ca74c16f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: daff070700c37734e6239514d196f02ee1351c00
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="graphics-c-amp"></a>Elementos gráficos (C++ AMP)
C++ AMP contém várias APIs no [Concurrency:: Graphics](../../parallel/amp/reference/concurrency-graphics-namespace.md) namespace que você pode usar para acessar o suporte de textura na GPU. Alguns cenários comuns são:  
  
-   Você pode usar o [textura](../../parallel/amp/reference/texture-class.md) classe como um contêiner de dados para a computação e exploração de *localidade espacial* do cache de textura e layouts de hardware da GPU. Localidade espacial é a propriedade de elementos de dados estar fisicamente próximos uns dos outros.  
  
-   O tempo de execução fornece interoperabilidade eficiente com sombreadores de computação não. Pixel, vértice, mosaico e sombreadores convexa frequentemente consumirem ou produzem texturas que você pode usar em seus cálculos C++ AMP.  
  
-   Gráficos de APIs em C++ AMP fornecem modos alternativos de acessar sub palavras buffers compactados. Texturas com formatos que representam *texels* (elementos de textura) que são compostos de 8 bits ou escalares de 16 bits permitem acesso a esse armazenamento de dados compactado.  
  
## <a name="the-norm-and-unorm-types"></a>Os tipos normais e unorm  
 O `norm` e `unorm` tipos são tipos escalares que limitam o intervalo de `float` valores; isso é conhecido como *fixação*. Esses tipos podem ser construídos explicitamente de outros tipos escalares. Na conversão, o valor é primeiro convertido em `float` e, em seguida, é fixado à região de respectivos é permitido pela norma [-1,0, 1,0] ou unorm [0,0, 1,0]. Retorna a projeção de + /-infinito + /-1. A projeção de NaN não está definida. Um modelo pode ser construído implicitamente em um unorm e não há nenhuma perda de dados. O operador de conversão implícita em float é definido nesses tipos. Operadores binários definidos entre esses tipos e outros tipos escalares internos, como `float` e `int`: +, -, *, /, = =,! =, >, \<, > =, < =. Também há suporte para os operadores de atribuição composta: + =,-=, \*= / =. O operador unário de negação (-) está definido para tipos de modelo.  
  
## <a name="short-vector-library"></a>Biblioteca de vetor curto  
 A biblioteca de vetor curto fornece algumas das funcionalidades de [tipo Vector](http://go.microsoft.com/fwlink/p/?linkid=248500) que é definido em HLSL e é normalmente usado para definir texels. Um vetor curto é uma estrutura de dados que contém os valores de uma a quatro do mesmo tipo. Os tipos suportados são `double`, `float`, `int`, `norm`, `uint`, e `unorm`. Os nomes de tipo são mostrados na tabela a seguir. Para cada tipo, há também um correspondente `typedef` que não tem um sublinhado no nome. Os tipos que têm os sublinhados estão no [Namespace Concurrency:: Graphics](../../parallel/amp/reference/concurrency-graphics-namespace.md). Os tipos que não possuem os sublinhados estão no [Concurrency::graphics::direct3d Namespace](../../parallel/amp/reference/concurrency-graphics-direct3d-namespace.md) para que eles são claramente separados tipos fundamentais nomeado da mesma forma como `__int8` e `__int16`.  
  
||Comprimento 2|Tamanho 3|Tamanho 4|  
|-|--------------|--------------|--------------|  
|double|double_2<br /><br /> double2|double_3<br /><br /> double3|double_4<br /><br /> double4|  
|float|float_2<br /><br /> float2|float_3<br /><br /> float3|float_4<br /><br /> float4|  
|int|int_2<br /><br /> int2|int_3<br /><br /> INT3|int_4<br /><br /> int4|  
|norm|norm_2<br /><br /> norm2|norm_3<br /><br /> norm3|norm_4<br /><br /> norm4|  
|uint|uint_2<br /><br /> uint2|uint_3<br /><br /> uint3|uint_4<br /><br /> uint4|  
|unorm|unorm_2<br /><br /> unorm2|unorm_3<br /><br /> unorm3|unorm_4<br /><br /> unorm4|  
  
### <a name="operators"></a>Operadores  
 Se um operador estiver definido entre dois vetores curtos, em seguida, ele também é definido entre um vetor de curto e um valor escalar. Além disso, um deles deve ser verdadeiro:  
  
-   Tipo de escalar deve ser o mesmo tipo de elemento do vetor curto.  
  
-   Tipo de escalar pode ser convertido implicitamente para o tipo de elemento de vetor usando apenas uma conversão definida pelo usuário.  
  
 A operação é executada component-wise entre cada componente do vetor de curto e o escalar. Aqui estão os operadores válidos:  
  
|Tipo de operador|Tipos válidos|  
|-------------------|-----------------|  
|Operadores binários|Válido em todos os tipos: +, -, *, /,<br /><br /> Válido em tipos inteiros: %, ^, &#124;, &, <\<, >><br /><br /> Os dois vetores devem ter o mesmo tamanho e o resultado é um vetor do mesmo tamanho.|  
|Operadores relacionais|Válido em todos os tipos: = = e! =|  
|Operador de atribuição composta|Válido em todos os tipos: + =,-=, * = / =<br /><br /> Válido em tipos inteiros: % =, ^ = &#124;= &, =, <\<= >> =|  
|Operadores de incremento e decremento|Válido em todos os tipos: + +, -<br /><br /> Prefixo e sufixo são válidos.|  
|Bit a bit operador (~)|Válido em tipos de inteiros.|  
|Unário - operador|Válido em todos os tipos exceto `unorm` e `uint`.|  
  
### <a name="swizzling-expressions"></a>Expressões swizzling  
 A biblioteca de vetor curto oferece suporte a `vector_type.identifier` construção de acessador para acessar os componentes de um vetor de curto. O `identifier`, que é conhecida como uma *expressão swizzling*, especifica os componentes do vetor. A expressão pode ser um valor de l ou uma r. Caracteres individuais do identificador podem ser: x, y, z e w; ou r, g, b e um. "x" e "r" significa que o componente de zero-ésimo, "y" e componente de média primeiro "g" e assim por diante. (Observe que "x" e "r" não podem ser usados o mesmo identificador.) Portanto, "rgba" e "xyzw" retornará o mesmo resultado. Acessadores de componentes simples como "x" e "y" é tipos de valor escalar. Acessadores de vários componentes são tipos de vetor curto. Por exemplo, se você construir um `int_4` vetor chamado `fourInts` e tem os valores 2, 4, 6 e 8, em seguida, `fourInts.y` retorna o inteiro de 4 e `fourInts.rg` retorna um `int_2` objeto que tem os valores 2 e 4.  
  
## <a name="texture-classes"></a>Classes de textura  
 Muitos GPUs tem hardware e caches que são otimizados para buscar pixels e texels e renderizar imagens e texturas. O [textura\<T, N >](../../parallel/amp/reference/texture-class.md) classe, que é uma classe de contêiner para objetos texel, expõe a funcionalidade de textura dessas GPUs. Um texel pode ser:  
  
-   Um `int`, `uint`, `float`, `double`, `norm`, ou `unorm` escalar.  
  
-   Um vetor curto que tem dois ou quatro componentes. A única exceção é `double_4`, que não é permitido.  
  
 O `texture` objeto pode ter uma classificação de 1, 2 ou 3. O `texture` objeto pode ser capturado somente por referência em lambda de uma chamada para `parallel_for_each`. A textura é armazenada na GPU como objetos de textura Direct3D. Para obter mais informações sobre texturas e texels em Direct3D, consulte [Introdução ao texturas Direct3D 11](http://go.microsoft.com/fwlink/p/?linkid=248502).  
  
 O tipo de texel usado pode ser um dos vários formatos de textura que são usados na programação de elementos gráficos. Por exemplo, um formato RGBA poderia usar 32 bits, com 8 bits cada para R, G, B e elementos escalar. O hardware de textura de uma placa gráfica pode acessar os elementos individuais com base no formato. Por exemplo, se você estiver usando o formato RGBA, o hardware de textura pode extrair cada elemento de 8 bits em um formulário de 32 bits. No C++ AMP, você pode definir os bits por elemento escalar o texel para que você pode acessar automaticamente os elementos individuais escalares no código sem o uso de deslocamento de bit.  
  
### <a name="instantiating-texture-objects"></a>Instanciando objetos de textura  
 Você pode declarar um objeto de textura sem a inicialização. O exemplo de código a seguir declara vários objetos de textura.  
  
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
  
 Você também pode usar um construtor para declarar e inicializar uma `texture` objeto. O exemplo de código a seguir cria um `texture` objeto a partir de um vetor de `float_4` objetos. Os bits por elemento escalar é definido como o padrão. Você não pode usar este construtor com `norm`, `unorm`, ou os vetores curtos de `norm` e `unorm`, porque eles não têm um padrão, o bits por elemento escalar.  
  
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
  
 Você também pode declarar e inicializar uma `texture` objeto usando uma sobrecarga de construtor que usa um ponteiro para os dados de origem, o tamanho da fonte de dados em bytes e os bits por elemento escalar.  
  
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
  
 Texturas nesses exemplos são criadas no modo de exibição padrão do acelerador padrão. Você pode usar outras sobrecargas do construtor, se você quiser especificar um `accelerator_view` objeto. Você não pode criar um objeto de textura um acelerador de CPU.  
  
 Há limites para o tamanho de cada dimensão do `texture` do objeto, como mostrado na tabela a seguir. Um erro de tempo de execução será gerado se você exceder os limites.  
  
|Textura|Limite de tamanho por dimensão|  
|-------------|---------------------|  
|textura\<T, 1 >|16384|  
|textura\<T, 2 >|16384|  
|textura\<T, 3 >|2048|  
  
### <a name="reading-from-texture-objects"></a>Leitura de objetos de textura  
 Você pode ler de um `texture` objeto usando [Texture:: Operator\[\]](reference/texture-class.md#operator_at), [textura:: Operator () operador](reference/texture-class.md#operator_call), ou [Texture:: Get método](reference/texture-class.md#get). Os dois operadores retornam um valor, não uma referência. Portanto, você não pode gravar uma `texture` objeto usando `texture::operator\[\]`.  
  
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
  
 O exemplo de código a seguir demonstra como armazenar canais de textura em um vetor de curto e, em seguida, acessar os elementos individuais de escalares como propriedades do vetor curto.  
  
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
  
|Tipo de dados de textura|Bits válidos por elemento escalar|  
|-----------------------|-----------------------------------|  
|int, int_2, int_4<br /><br /> uint, uint_2, uint_4|8, 16, 32|  
|int_3, uint_3|32|  
|float, float_2, float_4|16, 32|  
|float_3|32|  
|duplo, double_2|64|  
|norma, norm_2, norm_4<br /><br /> unorm, unorm_2, unorm, 4|8, 16|  
  
### <a name="writing-to-texture-objects"></a>Gravar em objetos de textura  
 Use o [Texture:: set](reference/texture-class.md#set) método gravar `texture` objetos. Um objeto de textura pode ser somente leitura ou leitura/gravação. Para um objeto de textura ser legível e gravável, as seguintes condições devem ser verdadeiras:  

  
-   T tem apenas um componente de escalar. (Vetores curtos não são permitidos).  
  
-   T não é `double`, `norm`, ou `unorm`.  
  
-   O `texture::bits_per_scalar_element` propriedade é 32.  
  
 Se todas as três não forem verdadeiras, o `texture` objeto é somente leitura. As primeiras duas condições são verificadas durante a compilação. Um erro de compilação será gerado se você tiver um código que tenta gravar um `readonly` objeto textura. A condição de `texture::bits_per_scalar_element` é detectado em tempo de execução e o tempo de execução gera o [unsupported_feature](../../parallel/amp/reference/unsupported-feature-class.md) exceção se você tentar gravar uma readonly `texture` objeto.  
  
 O exemplo de código a seguir grava os valores para um objeto de textura.  
  
```cpp  
void writeTexture() {  
    texture<int, 1> tex1(16);

    parallel_for_each(tex1.extent, [&tex1] (index<1> idx) restrict(amp) {      
    tex1.set(idx, 0);

 });

 
}  
 
```  
  
### <a name="copying-texture-objects"></a>Copiando objetos de textura  
 Você pode copiar entre objetos de textura usando o [cópia](reference/concurrency-namespace-functions-amp.md#copy) função ou o [copy_async](reference/concurrency-namespace-functions-amp.md#copy_async) de função, conforme mostrado no exemplo de código a seguir.  
  
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
  
 Você também pode copiar de uma textura para outro usando o [Texture:: copy_to](reference/texture-class.md#copy_to) método. As duas texturas podem estar em accelerator_views diferentes. Quando você copia para uma `writeonly_texture_view` do objeto, os dados são copiados para o subjacente `texture` objeto. Os bits por elemento escalar e a extensão devem ser o mesmo na origem e destino `texture` objetos. Se esses requisitos não forem atendidos, o tempo de execução lança uma exceção.  

  
## <a name="texture-view-classes"></a>Classes de exibição de textura  
 C++ AMP apresenta o [classe texture_view](../../parallel/amp/reference/texture-view-class.md) em [!INCLUDE[vs_dev12](../../atl-mfc-shared/includes/vs_dev12_md.md)]. Suportam a exibições de textura os mesmos tipos de texel e classificações como o [classe texture](../../parallel/amp/reference/texture-class.md), mas ao contrário de texturas, fornecem acesso aos recursos de hardware adicional, como amostragem de textura e mipmaps. Exibições de textura oferecem suporte a acesso somente leitura, somente gravação e leitura / gravação aos dados subjacentes de textura.  
  
-   Acesso somente leitura é fornecido pelo `texture_view<const T, N>` especialização de modelo, que dá suporte a elementos que têm 1, 2 ou 4 componentes, textura amostragem e dinâmico acesso a uma variedade de mipmap níveis são determinadas quando o modo de exibição é instanciado.  
  
-   Acesso somente gravação é fornecido pela classe de modelo não especializado `texture_view<T, N>`, que oferece suporte a elementos que têm componentes de 2 ou 4 e podem acessar um nível de mipmap que determina quando o modo de exibição é instanciado. Ele não oferece suporte a amostragem.  
  
-   Acesso de leitura / gravação é fornecido pela classe de modelo não especializado `texture_view<T, N>`, que, como texturas, oferece suporte a elementos que têm apenas um componente; o modo de exibição pode acessar um nível de mipmap que determina quando ele é instanciado. Ele não oferece suporte a amostragem.  
  
 Exibições de textura são análogas às exibições de matriz, mas não fornecem a funcionalidade de gerenciamento e a movimentação de dados automática que o [classe array_view](../../parallel/amp/reference/array-view-class.md) fornece em relação a [classe array](../../parallel/amp/reference/array-class.md). Um `texture_view` só podem ser acessados no modo de exibição accelerator onde residem os dados subjacentes de textura.  
  
### <a name="writeonlytextureview-deprecated"></a>writeonly_texture_view preterido  
 Para [!INCLUDE[vs_dev12](../../atl-mfc-shared/includes/vs_dev12_md.md)], C++ AMP apresenta um melhor suporte para recursos de textura de hardware, como amostragem e mipmaps, que pode não ser compatível com o [classe writeonly_texture_view](../../parallel/amp/reference/writeonly-texture-view-class.md). Recentemente introduzido `texture_view` classe suporta um subconjunto da funcionalidade do `writeonly_texture_view`; como resultado, `writeonly_texture_view` foi preterido.  
  
 É recomendável — pelo menos para o novo código — que você use `texture_view` a funcionalidade de acesso que foram anteriormente fornecida pelo `writeonly_texture_view`. Compare os seguir dois exemplos de código que gravar em um objeto de textura que tem dois componentes (int_2). Observe que em ambos os casos, o modo de exibição, `wo_tv4`, devem ser capturados pelo valor da expressão lambda. Aqui está o exemplo que usa o novo `texture_view` classe:  
  
```cpp  
void write2ComponentTexture() {  
    texture<int_2, 1> tex4(16);

    texture_view<int_2, 1> wo_tv4(tex4);

    parallel_for_each(extent<1>(16), [=] (index<1> idx) restrict(amp) {  
    wo_tv4.set(idx, int_2(1, 1));

 });

}  
```  
  
 E aqui está preterido `writeonly_texture_view` classe:  
  
```  
void write2ComponentTexture() {  
    texture<int_2, 1> tex4(16);

    writeonly_texture_view<int_2, 1> wo_tv4(tex4);

    parallel_for_each(extent<1>(16), [=] (index<1> idx) restrict(amp) {     
    wo_tv4.set(idx, int_2(1, 1));

 });

}  
```  
  
 Como você pode ver, os dois exemplos de código são praticamente idênticos quando tudo o que você está fazendo está gravando o nível de mipmap primário. Se você usou `writeonly_texture_view` em código existente e você não estiver planejando aprimorar a que o código, você não precisa alterá-la. No entanto, se você estiver pensando sobre como colocar esse código para a frente, sugerimos que você reescreva-lo para uso `texture_view` porque os aprimoramentos nele oferecem suporte a novos recursos de textura de hardware. Leia mais para obter mais informações sobre esses novos recursos.  
  
 Para obter mais informações sobre a substituição de `writeonly_texture_view`, consulte [visão geral do projeto de modo de exibição da textura no C++ AMP](http://blogs.msdn.com/b/nativeconcurrency/archive/2013/07/25/overview-of-the-texture-view-design-in-c-amp.aspx) na programação paralela no blog de código nativo.  
  
### <a name="instantiating-texture-view-objects"></a>Instanciando objetos de exibição de textura  
 Declarando um `texture_view` é semelhante ao declarar um `array_view` que está associado com um `array`. O exemplo de código a seguir declara vários `texture` objetos e `texture_view` objetos que estão associados eles.  
  
```  
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
  
 Observe como uma textura exibir cujo tipo de elemento é não constante e tem um componente é leitura / gravação, mas uma exibição de textura, cujo tipo de elemento é não constante, mas tem mais de um componenent são somente gravação. Exibições de textura dos tipos de elemento constantes são sempre somente leitura, mas se o tipo de elemento é não constante, em seguida, o número de componentes no elemento determina se é leitura / gravação (1 componente) ou somente gravação (vários componentes).  
  
 O tipo de elemento de um `texture_view`— seu qualidade de const e também o número de componentes tem — também desempenha uma função para determinar se o modo de exibição dá suporte à amostragem de textura, e como os níveis de mipmap podem ser acessados:  
  
|Tipo|Componentes|Ler|Write|Amostragem|Acesso de Mipmap|  
|----------|----------------|----------|-----------|--------------|-------------------|  
|texture_view\<const T, N >|1, 2, 4|Sim|Nenhum (1)|Sim|Sim, indexáveis. Intervalo é determinado na instanciação.|  
|Texture_view\<T, N >|1<br /><br /> 2, 4|Sim<br /><br /> Não (2)|Sim<br /><br /> Sim|Nenhum (1)<br /><br /> Nenhum (1)|Sim, um nível. Nível é determinado na instanciação.<br /><br /> Sim, um nível. Nível é determinado na instanciação.|  
  
 Esta tabela, você pode ver que as exibições de textura somente leitura dão suporte total aos novos recursos em troca de não conseguir gravar no modo de exibição. Exibições de textura gravável são limitadas em que eles podem acessar apenas um nível de mipmap. Modos de exibição de leitura-gravação textura são ainda mais especializados que gravável, porque eles adicionar o requisito de que o tipo de elemento da exibição de textura tem apenas um componente. Observe que amostragem não há suporte para modos de exibição de textura gravável porque é uma operação orientados para leitura.  
  
### <a name="reading-from-texture-view-objects"></a>Leitura de objetos de exibição de textura  
 Lendo dados de textura sem exemplo não deverão através de uma exibição de textura é como ler a textura em si, exceto que texturas são capturadas por referência, enquanto as exibições de textura são capturadas pelo valor. Demonstram os seguir dois exemplos de código; primeiro, usando `texture` somente:  
  
```  
void write2ComponentTexture() {  
    texture<int_2, 1> text_data(16);

    parallel_for_each(extent<1>(16), [&] (index<1> idx) restrict(amp) {  
    tex_data.set(idx, int_2(1, 1));

 });

}  
```  
  
 E aqui está o mesmo exemplo, mas agora usa o `texture_view` classe:  
  
```  
void write2ComponentTexture() {  
    texture<int_2, 1> tex_data(16);

    texture_view<int_2, 1> tex_view(tex_data);

    parallel_for_each(extent<1>(16), [=] (index<1> idx) restrict(amp) {  
    tex_view.set(idx, int_2(1, 1));

 });

}  
```  
 Modos de exibição cujos elementos são baseados em tipos de ponto flutuante de textura — por exemplo, float, float_2 ou float_4 — também pode ser leitura por meio de amostragem de textura para aproveitar o suporte de hardware para diversos modos de filtragem e modos de endereçamento. C++ AMP dá suporte a dois modos de filtragem que são mais comuns em cenários de computação — ponto-filtragem (vizinho mais próximo) e linear-(média ponderada) — e quatro modos de endereçamento — encapsulados, espelhado, fixado e borda. Para obter mais informações sobre modos de endereçamento, consulte [enumeração address_mode](reference/concurrency-graphics-namespace-enums.md#address_mode).  
  
 Além dos modos de C++ AMP oferece suporte diretamente, você pode acessar outros modos de filtragem e modos de endereçamento da plataforma subjacente, usando as APIs de interoperabilidade para adotar uma amostra de textura que foi criada por meio de APIs da plataforma diretamente. Por exemplo, Direct3D oferece suporte a outros modos de filtragem, como anisotrópico e se aplicam a um modo de endereçamento diferente para cada dimensão de uma textura. Você pode criar uma amostra de textura cujas coordenadas são encapsuladas verticalmente, espelhadas horizontalmente e de amostra com anisotrópico usando as APIs do Direct3D e, em seguida, aproveitar a amostra no código do C++ AMP usando o `make_sampler` API de interoperabilidade. Para obter mais informações, consulte [amostragem de textura no C++ AMP](http://blogs.msdn.com/b/nativeconcurrency/archive/2013/07/18/texture-sampling-in-c-amp.aspx) na programação paralela no blog de código nativo.  
  
 Exibições de textura também dão suporte a leitura de mipmaps. Modos de exibição somente leitura de textura (aqueles que têm um tipo de elemento const) oferecem mais flexibilidade porque um intervalo de mip-níveis que é determinado na instanciação pode ser exemplificado dinamicamente, e como os elementos que têm 1, 2 ou 4 componentes têm suporte. Exibições de textura de leitura / gravação que tenham elementos que têm um componente também oferecem suporte a mipmaps, mas apenas de um nível que é determinado na instanciação. Para obter mais informações, consulte [textura com Mipmaps](http://blogs.msdn.com/b/nativeconcurrency/archive/2013/08/22/texture-with-mipmaps.aspx) na programação paralela no blog de código nativo.  
  
### <a name="writing-to-texture-view-objects"></a>Gravar em objetos de exibição de textura  
 Use o [texture_view:: Get método](reference/texture-view-class.md#get) gravar subjacente `texture` por meio de `texture_view` objeto. Uma exibição de textura pode ser somente leitura, leitura / gravação ou somente gravação. Para uma exibição de textura para ser gravável, ele deverá ter um tipo de elemento que é não constante; para uma exibição de textura ser legível e gravável, seu tipo de elemento também deve ter apenas um componente. Caso contrário, o modo de exibição de textura é somente leitura. Você pode apenas um mipmap nível de acesso de uma textura simultaneamente através de uma exibição de textura, e o nível é especificado quando o modo de exibição é instanciado.  
  
 Este exemplo mostra como gravar em nível de mipmap detalhadas de segundo mais de uma textura que tem 4 níveis de mipmap. O nível de mipmap mais detalhado é 0.  
  
```  
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

 O tempo de execução C++ AMP dá suporte a interoperabilidade entre `texture<T,1>` e [ID3D11Texture1D interface](http://go.microsoft.com/fwlink/p/?linkId=248503), entre `texture<T,2>` e [ID3D11Texture2D interface](http://go.microsoft.com/fwlink/p/?linkId=255317)e entre `texture<T,3>`e [ID3D11Texture3D interface](http://go.microsoft.com/fwlink/p/?linkId=255377). O [get_texture](reference/concurrency-graphics-direct3d-namespace-functions.md#get_texture) leva um `texture` objeto e retorna um `IUnknown` interface. O [make_texture](reference/concurrency-graphics-direct3d-namespace-functions.md#make_texture) leva um `IUnknown` interface e um `accelerator_view` objeto e retorna um `texture` objeto.  
  
## <a name="see-also"></a>Consulte também  
 [Classe double_2](../../parallel/amp/reference/double-2-class.md)   
 [Classe double_3](../../parallel/amp/reference/double-3-class.md)   
 [Classe double_4](../../parallel/amp/reference/double-4-class.md)   
 [Classe float_2](../../parallel/amp/reference/float-2-class.md)   
 [Classe float_3](../../parallel/amp/reference/float-3-class.md)   
 [Classe float_4](../../parallel/amp/reference/float-4-class.md)   
 [Classe int_2](../../parallel/amp/reference/int-2-class.md)   
 [Classe int_3](../../parallel/amp/reference/int-3-class.md)   
 [Classe int_4](../../parallel/amp/reference/int-4-class.md)   
 [Classe norm_2](../../parallel/amp/reference/norm-2-class.md)   
 [Classe norm_3](../../parallel/amp/reference/norm-3-class.md)   
 [Classe norm_4](../../parallel/amp/reference/norm-4-class.md)   
 [Estrutura short_vector](../../parallel/amp/reference/short-vector-structure.md)   
 [Estrutura short_vector_traits](../../parallel/amp/reference/short-vector-traits-structure.md)   
 [Classe uint_2](../../parallel/amp/reference/uint-2-class.md)   
 [Classe uint_3](../../parallel/amp/reference/uint-3-class.md)   
 [Classe uint_4](../../parallel/amp/reference/uint-4-class.md)   
 [Classe unorm_2](../../parallel/amp/reference/unorm-2-class.md)   
 [Classe unorm_3](../../parallel/amp/reference/unorm-3-class.md)   
 [Classe unorm_4](../../parallel/amp/reference/unorm-4-class.md)
