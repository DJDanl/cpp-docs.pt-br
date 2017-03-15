---
title: "Usando objetos accelerator e accelerator_view | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
ms.assetid: 18f0dc66-8236-4420-9f46-1a14f2c3fba1
caps.latest.revision: 17
caps.handback.revision: 17
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Usando objetos accelerator e accelerator_view
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Você pode usar o [accelerator](../../parallel/amp/reference/accelerator-class.md) e [accelerator_view](../Topic/accelerator_view%20Class.md) classes para especificar o dispositivo ou emulador para executar seu código C++ AMP. Um sistema pode ter vários dispositivos ou emuladores diferentes pela quantidade de memória, suporte à memória compartilhada, suporte a depuração ou suporte de precisão dupla. C++ Accelerated Massive Parallelism (C++ AMP) fornece APIs que você pode usar para examinar os Aceleradores disponíveis, definir uma como padrão, especificar vários accelerator_views para várias chamadas para parallel_for_each e executar tarefas de depuração especiais.  
  
## <a name="using-the-default-accelerator"></a>Usando o acelerador padrão  
 O tempo de execução C++ AMP escolhe um acelerador padrão, a menos que você escrever código para escolher um específico. O runtime decide o acelerador padrão da seguinte maneira:  
  
1.  Se o aplicativo é executado no modo de depuração, um acelerador que oferece suporte à depuração.  
  
2.  Caso contrário, o acelerador especificado pela variável de ambiente CPPAMP_DEFAULT_ACCELERATOR, se ela está definida.  
  
3.  Caso contrário, um dispositivo não emulados.  
  
4.  Caso contrário, o dispositivo que tem a maior quantidade de memória disponível.  
  
5.  Caso contrário, um dispositivo que não está anexado à exibição.  
  
 Além disso, o tempo de execução Especifica um `access_type` de `access_type_auto` Accelerator padrão. Isso significa que o acelerador padrão usa memória compartilhada, se ele tem suporte e suas características de desempenho (largura de banda e latência) costumam ser a mesma memória dedicada (não compartilhado).  
  
 Você pode determinar as propriedades do acelerador padrão de construir o acelerador padrão e examinando suas propriedades. O exemplo de código a seguir imprime o caminho, a quantidade de memória de acelerador, suporte à memória compartilhada, suporte de precisão dupla e suporte limitado de precisão dupla do acelerador padrão.  
  
```cpp  
 
void default_properties() {  
    accelerator default_acc;  
    std::wcout <<default_acc.device_path <<"\n";  
    std::wcout <<default_acc.dedicated_memory <<"\n";  
    std::wcout <<(accs[i].supports_cpu_shared_memory    
 "CPU shared memory: true" : "CPU shared memory: false") <<"\n";  
    std::wcout <<(accs[i].supports_double_precision    
 "double precision: true" : "double precision: false") <<"\n";  
    std::wcout <<(accs[i].supports_limited_double_precision    
 "limited double precision: true" : "limited double precision: false") <<"\n";  
}  
 
```  
  
### <a name="cppampdefaultaccelerator-environment-variable"></a>Variável de ambiente CPPAMP_DEFAULT_ACCELERATOR  
 Você pode definir a variável de ambiente CPPAMP_DEFAULT_ACCELERATOR para especificar o `accelerator::device_path` do acelerador padrão. O caminho é dependente do hardware. O código a seguir usa o `accelerator::get_all` de função para recuperar uma lista de aceleradores de disponível e, em seguida, exibe o caminho e as características de cada acelerador.  
  
```cpp  
 
void list_all_accelerators()  
{  
    std::vector<accelerator> accs = accelerator::get_all();
for (int i = 0; i <accs.size();

i++) {  
    std::wcout <<accs[i].device_path <<"\n";  
    std::wcout <<accs[i].dedicated_memory <<"\n";  
    std::wcout <<(accs[i].supports_cpu_shared_memory    
 "CPU shared memory: true" : "CPU shared memory: false") <<"\n";  
    std::wcout <<(accs[i].supports_double_precision    
 "double precision: true" : "double precision: false") <<"\n";  
    std::wcout <<(accs[i].supports_limited_double_precision    
 "limited double precision: true" : "limited double precision: false") <<"\n";  
 }  
}  
 
```  
  
## <a name="selecting-an-accelerator"></a>Selecionando um acelerador  
 Para selecionar um acelerador, use o `accelerator::get_all` método para recuperar uma lista dos Aceleradores disponíveis e, em seguida, selecione uma com base em suas propriedades. Este exemplo mostra como selecionar o Acelerador que tenha mais memória:  
  
```cpp  
 
void pick_with_most_memory()  
{  
    std::vector<accelerator> accs = accelerator::get_all();
accelerator acc_chosen = accs[0];  
    for (int i = 0; i <accs.size();

i++) {  
    if (accs[i].dedicated_memory> acc_chosen.dedicated_memory) {  
    acc_chosen = accs[i];  
 }  
 }  
 
    std::wcout <<"The accelerator with the most memory is "    
 <<acc_chosen.device_path <<"\n"  
 <<acc_chosen.dedicated_memory <<".\n";  
}  
 
```  
  
> [!NOTE]
>  Um dos aceleradores que são retornados pelo `accelerator::get_all` é o Acelerador de CPU. Você não pode executar código no Acelerador de CPU. Para filtrar o Acelerador de CPU, compare o valor da [device_path](../Topic/accelerator::device_path%20Data%20Member.md) propriedade do accelerator que é retornado pelo `accelerator::get_all` com o valor da [Accelerator:: cpu_accelerator](../Topic/accelerator::cpu_accelerator%20Data%20Member.md). Para obter mais informações, consulte a seção "Aceleradores especial" neste artigo.  
  
## <a name="shared-memory"></a>Memória compartilhada  
 Memória compartilhada é a memória que pode ser acessada pela CPU e o acelerador. O uso de memória compartilhada elimina ou reduz significativamente a sobrecarga de cópia de dados entre a CPU e o acelerador. Embora a memória for compartilhada, não pode ser acessada simultaneamente por CPU e o acelerador, e isso fizer um comportamento indefinido. A propriedade accelerator [supports_cpu_shared_memory](../Topic/accelerator::supports_cpu_shared_memory%20Data%20Member.md) retorna `true` se o Acelerador oferece suporte à memória compartilhada e o [default_cpu_access_type](../Topic/accelerator::default_cpu_access_type%20Data%20Member.md) propriedade obtém o padrão [access_type](../Topic/access_type%20Enumeration.md) para a memória alocada no `accelerator`— por exemplo, `array`s associados a `accelerator`, ou `array_view` objetos acessados no `accelerator`.  
  
 O tempo de execução C++ AMP escolhe automaticamente o melhor padrão `access_type` para cada `accelerator`, mas as características de desempenho (largura de banda e latência) de memória compartilhada podem ser piores do que aqueles de memória dedicada accelerator (não compartilhada) durante a leitura da CPU, escrevendo da CPU, ou ambos. Se a memória compartilhada executa, bem como memória dedicada para leitura e gravação da CPU, o tempo de execução padrão `access_type_read_write`; caso contrário, o tempo de execução escolhe um padrão mais conservadora `access_type`, e permite que o aplicativo para substituí-la se os padrões de acesso de memória de seus kernels de computação se beneficiar de um outro `access_type`.  
  
 O exemplo de código a seguir mostra como determinar se o acelerador padrão dá suporte à memória compartilhada e, em seguida, substitui o tipo de acesso padrão e cria um `accelerator_view` dele.  
  
```cpp  
#include <amp.h>  
#include <iostream>  
  
using namespace Concurrency;  
  
int main()  
{  
  accelerator acc = accelerator(accelerator::default_accelerator);  
  
  // Early out if the default accelerator doesn’t support shared memory.  
  if(!acc.supports_cpu_shared_memory)  
  {  
    std::cout << "The default accelerator does not support shared memory" << std::endl;  
    return 1;  
  }  
  
  // Override the default CPU access type.  
  acc.set_default_cpu_access_type(access_type_read_write);  
  
  // Create an accelerator_view from the default accelerator. The  
  // accelerator_view reflects the default_cpu_access_type of the  
  // accelerator it’s associated with.  
  accelerator_view acc_v = acc.default_view;  
}  
  
```  
  
 Um `accelerator_view` sempre reflete o `default_cpu_access_type` do `accelerator` está associado, e não fornece nenhuma interface para substituir ou alterar seu `access_type`.  
  
## <a name="changing-the-default-accelerator"></a>Alterando o acelerador padrão  
 Você pode alterar o acelerador padrão chamando o `accelerator::set_default` método. Você pode alterar o acelerador padrão apenas uma vez por aplicativo de execução e você deve alterá-la para que qualquer código é executado na GPU. Quaisquer chamadas de função subsequentes para alterar o acelerador retornam `false`. Se você deseja usar um acelerador diferente em uma chamada para `parallel_for_each`, leia a seção "Usando várias aceleradores" neste artigo. O exemplo de código a seguir define o acelerador padrão para um que não é emulado, não está conectado a uma exibição e dá suporte à precisão dupla.  
  
```cpp  
 
    bool pick_accelerator()  
{  
    std::vector<accelerator> accs = accelerator::get_all();
accelerator chosen_one;  
 
    auto result = 
    std::find_if(accs.begin(), accs.end(), [] (const accelerator& acc)  
 {  
    return !acc.is_emulated&& 
    acc.supports_double_precision&& 
 !acc.has_display;  
 });

 
    if (result != accs.end())  
    chosen_one = *(result);

 
    std::wcout <<chosen_one.description <<std::endl;  
 
    bool success = accelerator::set_default(chosen_one.device_path);

    return success;  
}  
 
```  
  
## <a name="using-multiple-accelerators"></a>Usando Aceleradores de vários  
 Há duas maneiras de usar vários aceleradores em seu aplicativo:  
  
-   Você pode passar `accelerator_view` objetos para as chamadas para o [parallel_for_each](../Topic/parallel_for_each%20Function%20\(C++%20AMP\).md) método.  
  
-   Você pode construir um `array` usando uma versão específica do objeto `accelerator_view` objeto. O tempo de execução do C + AMP pegará o `accelerator_view` objeto do capturados `array` objeto na expressão lambda.  
  
## <a name="special-accelerators"></a>Aceleradores especiais  
 Os caminhos de dispositivo de três Aceleradores especiais estão disponíveis como propriedades da `accelerator` classe:  
  
- [Accelerator:: direct3d_ref membro de dados](../Topic/accelerator::direct3d_ref%20Data%20Member.md): esse acelerador de thread único usa software na CPU para emular uma placa gráfica genérico. Ele é usado por padrão para depuração, mas não é útil na produção porque é mais lento do que os aceleradores de hardware. Além disso, ele só está disponível no SDK do DirectX e o SDK do Windows e é improvável de ser instalado em computadores de seus clientes. Para obter mais informações, consulte [depurando código de GPU](../Topic/Debugging%20GPU%20Code.md).  
  
- [Accelerator:: direct3d_warp membro de dados](../Topic/accelerator::direct3d_warp%20Data%20Member.md): esse acelerador fornece uma solução fallback para a execução de código C++ AMP em CPUs de vários núcleos que usam o Streaming SIMD Extensions (SSE).  
  
- [Accelerator:: cpu_accelerator membro de dados](../Topic/accelerator::cpu_accelerator%20Data%20Member.md): você pode usar esse acelerador para configurar conjuntos de teste. Ele não pode executar código C++ AMP. Para obter mais informações, consulte o [preparo matrizes em C++ AMP](http://go.microsoft.com/fwlink/p/LinkId=248485) Lançar em programação paralela no blog de código nativo.  
  
## <a name="interoperability"></a>Interoperabilidade  
 O tempo de execução C++ AMP dá suporte à interoperabilidade entre o `accelerator_view` classe e o Direct3D [ID3D11Device interface](http://go.microsoft.com/fwlink/p/LinkId=248488). O [create_accelerator_view](../Topic/create_accelerator_view%20Function.md) leva um `IUnknown` interface e retorna um `accelerator_view` objeto. O [get_device](http://msdn.microsoft.com/pt-br/8194125e-8396-4d62-aa8a-65831dea8439) leva um `accelerator_view` objeto e retorna um `IUknown` interface.  
  
## <a name="see-also"></a>Consulte também  
 [C++ AMP (C++ Accelerated Massive Parallelism)](../../parallel/amp/cpp-amp-cpp-accelerated-massive-parallelism.md)   
 [Depurando código de GPU](../Topic/Debugging%20GPU%20Code.md)   
 [Classe accelerator_view](../Topic/accelerator_view%20Class.md)
