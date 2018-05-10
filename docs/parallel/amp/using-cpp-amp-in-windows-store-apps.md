---
title: Usando C++ AMP em aplicativos UWP | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-amp
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 85577298-2c28-4209-9470-eb21048615db
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 5736c84f21535222de5659780968efd98e1467da
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="using-c-amp-in-uwp-apps"></a>Usando C++ AMP em aplicativos UWP
Você pode usar C++ AMP (C++ Accelerated Massive Parallelism) em seu aplicativo do Windows UWP (plataforma Universal) para executar cálculos na GPU (unidade de processamento gráfico) ou outros Aceleradores computacionais. No entanto, C++ AMP não fornece APIs para trabalhar diretamente com os tipos de tempo de execução do Windows e o tempo de execução do Windows não fornece um wrapper para C++ AMP. Quando você usa os tipos de tempo de execução do Windows em seu código, incluindo aqueles que você criou por conta própria — você deve convertê-los em tipos compatíveis com C++ AMP.  
  
## <a name="performance-considerations"></a>Considerações sobre desempenho  
 Se você estiver usando [!INCLUDE[cppwrt](../../build/reference/includes/cppwrt_md.md)] ([!INCLUDE[cppwrt_short](../../build/reference/includes/cppwrt_short_md.md)]) para criar seu aplicativo do Windows UWP (plataforma Universal), é recomendável que você use tipos simples antigo-dados (POD) junto com o armazenamento de contíguo — por exemplo, `std::vector` ou matrizes de estilo C — para dados que serão usados com C++ AMP. Isso pode ajudá-lo a alcançar desempenho maior do que usando tipos não POD ou contêineres do Windows RT porque nenhum marshaling deve ocorrer.  
  
 Em um núcleo de C++ AMP, para acessar os dados que são armazenados dessa forma, basta encapsular o `std::vector` ou matriz de armazenamento em um `concurrency::array_view` e, em seguida, usar o modo de exibição de matriz em um `concurrency::parallel_for_each` loop:  
  
```cpp  
// simple vector addition example  
std::vector<int> data0(1024, 1);
std::vector<int> data1(1024, 2);
std::vector<int> data_out(data0.size(), 0);
  
concurrency::array_view<int, 1> av0(data0.size(), data0);
concurrency::array_view<int, 1> av1(data1.size(), data1);
concurrency::array_view<int, 1> av2(data_out.size(), data2);
  
av2.discard_data();
  
concurrency::parallel_for_each(av0.extent, [=](concurrency::index<1> idx) restrict(amp)  
    {  
        av2[idx] = av0[idx] + av1[idx];  
    });
```  
  
## <a name="marshaling-windows-runtime-types"></a>Marshaling tipos de Tempo de Execução do Windows  
 Quando você trabalha com APIs do Windows Runtime, talvez você queira usar C++ AMP em dados que são armazenados em um contêiner de tempo de execução do Windows como um `Platform::Array<T>^` ou em tipos de dados complexos, como classes ou estruturas que são declaradas usando o `ref` palavra-chave ou o `value`</C4>palavra-chave. Nessas situações, você precisa realizar algum trabalho adicional para disponibilizar os dados para C++ AMP.  
  
### <a name="platformarrayt-where-t-is-a-pod-type"></a>Platform:: array\<T > ^, onde T é um tipo POD  
 Quando você encontrar um `Platform::Array<T>^` e T é um tipo POD, você pode acessar o armazenamento subjacente apenas usando o `get` função de membro:  
  
```cpp  
Platform::Array<float>^ arr; // Assume that this was returned by a Windows Runtime API  
concurrency::array_view<float, 1> av(arr->Length, &arr->get(0));
```  
  
 Se T não é um tipo POD, use a técnica descrita na seção a seguir para usar os dados com C++ AMP.  
  
### <a name="windows-runtime-types-ref-classes-and-value-classes"></a>Tipos de Tempo de Execução do Windows: classes ref e value  
 C++ AMP não dá suporte a tipos de dados complexos. Isso inclui tipos não POD e quaisquer tipos que são declarados usando o `ref` palavra-chave ou o `value` palavra-chave. Se um tipo sem suporte for usado em um `restrict(amp)` contexto, um erro de tempo de compilação é gerado.  
  
 Quando você encontrar um tipo sem suporte, você pode copiar partes interessantes de seus dados em um `concurrency::array` objeto. Além de tornar os dados disponíveis para C++ AMP consumir, essa abordagem de cópia manual também pode melhorar o desempenho, maximizando a localidade dos dados e garantindo que os dados que não possa ser utilizados não copiados para o acelerador. Você pode melhorar o desempenho ainda mais usando uma *preparo matriz*, que é uma forma especial de `concurrency::array` que fornece uma dica para o tempo de execução de AMP a matriz deve ser otimizada para transferência frequente entre ele e outras matrizes no acelerador especificado.  
  
```cpp  
// pixel_color.h  
ref class pixel_color sealed  
{  
public: 
    pixel_color(Platform::String^ color_name, int red, int green, int blue)   
    {  
        name = color_name;  
        r = red;  
        g = green;  
        b = blue;  
    }  
 
    property Platform::String^ name;   
    property int r;  
    property int g;  
    property int b;  
};  
  
// Some other file  
  
std::vector<pixel_color^> pixels (256);
  
for (pixel_color ^pixel : pixels)   
{  
    pixels.push_back(ref new pixel_color("blue", 0, 0, 255));
}  
  
// Create the accelerators  
auto cpuAccelerator = concurrency::accelerator(concurrency::accelerator::cpu_accelerator);
auto devAccelerator = concurrency::accelerator(concurrency::accelerator::default_accelerator);
  
// Create the staging arrays  
concurrency::array<float, 1> red_vec(256, cpuAccelerator.default_view, devAccelerator.default_view);
concurrency::array<float, 1>  blue_vec(256, cpuAccelerator.default_view, devAccelerator.default_view);
  
// Extract data from the complex array of structs into staging arrays.  
concurrency::parallel_for(0, 256, [&](int i)  
    {   
        red_vec[i] = pixels[i]->r;  
        blue_vec[i] = pixels[i]->b;  
    });
  
// Array views are still used to copy data to the accelerator  
concurrency::array_view<float, 1> av_red(red_vec);
concurrency::array_view<float, 1> av_blue(blue_vec);
  
// Change all pixels from blue to red.  
concurrency::parallel_for_each(av_red.extent, [=](index<1> idx) restrict(amp)  
    {  
        av_red[idx] = 255;  
        av_blue[idx] = 0;  
    });
```  
  
## <a name="see-also"></a>Consulte também  
 [Criar seu primeiro aplicativo UWP usando C++](/windows/uwp/get-started/create-a-basic-windows-10-app-in-cpp)   
 [Criando componentes de tempo de execução do Windows em C++](/windows/uwp/winrt-components/creating-windows-runtime-components-in-cpp)

