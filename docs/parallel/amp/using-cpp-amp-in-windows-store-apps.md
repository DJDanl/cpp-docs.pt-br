---
title: "Usando C++ AMP em aplicativos da Windows Store | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
ms.assetid: 85577298-2c28-4209-9470-eb21048615db
caps.latest.revision: 14
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Usando C++ AMP em aplicativos da Windows Store
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

É possível usar o C\+\+ AMP \(C\+\+ Accelerated Massive Parallelism\) no seu aplicativo do [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] para executar cálculos em GPU \(unidade de processamento gráfico\) ou em outros aceleradores computacionais.  No entanto, o C\+\+ AMP não fornece APIs para trabalhar diretamente com tipos de Tempo de Execução do Windows, e o Tempo de Execução do Windows não fornece um wrapper para o C\+\+ AMP.  Ao usar os tipos de Tempo de Execução do Windows em seu código, incluindo aqueles que você mesmo criou, converta\-os para tipos compatíveis com C\+\+ AMP.  
  
## Considerações sobre desempenho  
 Se você estiver usando [!INCLUDE[cppwrt](../../build/reference/includes/cppwrt_md.md)] \([!INCLUDE[cppwrt_short](../Token/cppwrt_short_md.md)]\) para criar seu aplicativo [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)], recomendamos que use tipos de dados antigos e simples \(POD\) juntamente com o armazenamento contíguo, por exemplo `std::vector` ou setas no estilo C, para dados que serão usados com C\+\+ AMP.  Isso pode ajudar você a obter um desempenho melhor do que usar tipos de não POD ou contêineres do Windows RT porque não precisa ocorrer nenhum empacotamento.  
  
 Em um kernel do C\+\+ AMP, para acessar dados armazenados dessa forma, basta encapsular o `std::vector` ou o armazenamento de matriz em um `concurrency::array_view` e, em seguida, usar a exibição de matriz em um loop de `concurrency::parallel_for_each`:  
  
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
  
## Marshaling tipos de Tempo de Execução do Windows  
 Quando você trabalha com APIs de Tempo de Execução do Windows, convém usar C\+\+ AMP nos dados armazenados em um contêiner de Tempo de Execução do Windows, como `Platform::Array<T>^` ou em tipos de dados complexos, como classes ou estruturas que são declaradas com a palavra\-chave `ref` ou `value`.  Nessas situações, você tem que fazer um pouco de trabalho adicional para tornar os dados disponíveis para o C\+\+ AMP.  
  
### Platform::Array\<T\>^, em que T é um tipo POD  
 Quando você encontra `Platform::Array<T>^` e T é um tipo POD, você pode acessar o armazenamento subjacente usando apenas a função de membro `get`:  
  
```cpp  
Platform::Array<float>^ arr; // Assume that this was returned by a Windows Runtime API  
concurrency::array_view<float, 1> av(arr->Length, &arr->get(0));  
  
```  
  
 Se T não é um tipo de POD, use a técnica descrita na seção a seguir para usar os dados com C\+\+ AMP.  
  
### Tipos de Tempo de Execução do Windows: classes ref e value  
 O C\+\+ AMP não tem suporte para tipos de dados complexos.  Isso inclui tipos não POD e todos os tipos declarados usando a palavra\-chave `ref` ou a palavra\-chave `value`.  Se um tipo sem suporte é usado em um contexto `restrict(amp)`, um erro de tempo de compilação é gerado.  
  
 Ao encontrar um tipo sem suporte, você pode copiar as partes interessantes dos dados em um objeto de `concurrency::array`.  Além de disponibilizar os dados para consumo do C\+\+ AMP, essa abordagem de cópia manual também pode melhorar o desempenho, maximizando a localidade de dados e garantindo que os dados que não serão usados não sejam copiados para o acelerador.  É possível melhorar ainda mais o desempenho usando uma *matriz de teste*, que é um formulário especial de `concurrency::array` que fornece uma dica em tempo de execução de AMP que a matriz deve ser otimizada para a transferência frequente entre ela e outras matrizes no acelerador especificado.  
  
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
..property int b;  
};  
  
// Some other file  
std::vector<pixel_color^> pixels (256);   
  
for(pixel_color ^pixel : pixels)   
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
  red_vec[i] = pixels[i]->r; blue_vec[i] = pixels[i]->b;  
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
  
## Consulte também  
 [Criar seu primeiro aplicativo do Windows Store usando C\+\+](http://go.microsoft.com/fwlink/p/?LinkId=249073)   
 [Criando componentes de Tempo de Execução do Windows em C\+\+](http://go.microsoft.com/fwlink/p/?LinkId=249076)