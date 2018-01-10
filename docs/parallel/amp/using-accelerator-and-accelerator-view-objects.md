---
title: Usando objetos accelerator e accelerator_view | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: 18f0dc66-8236-4420-9f46-1a14f2c3fba1
caps.latest.revision: "17"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 8cc676407a88979679a362b3d36f361614524432
ms.sourcegitcommit: 54035dce0992ba5dce0323d67f86301f994ff3db
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/03/2018
---
# <a name="using-accelerator-and-acceleratorview-objects"></a>Usando objetos accelerator e accelerator_view
Você pode usar o [accelerator](../../parallel/amp/reference/accelerator-class.md) e [accelerator_view](../../parallel/amp/reference/accelerator-view-class.md) classes para especificar o dispositivo ou emulador para executar seu código C++ AMP em. Um sistema pode ter vários dispositivos ou emuladores que diferem por quantidade de memória, suporte à memória compartilhada, suporte à depuração ou suporte de precisão dupla. C++ Accelerated Massive Parallelism (C++ AMP) fornece APIs que você pode usar para examinar os Aceleradores disponíveis, definido como o padrão, especifique vários accelerator_views para várias chamadas para parallel_for_each e executar tarefas de depuração especiais.  
  
## <a name="using-the-default-accelerator"></a>Usando o acelerador padrão  
 O tempo de execução C++ AMP escolhe um acelerador padrão, a menos que você escrever código para escolher um específico. O tempo de execução escolhe o acelerador padrão da seguinte maneira:  
  
1.  Se o aplicativo estiver em execução no modo de depuração, um acelerador que dá suporte à depuração.  
  
2.  Caso contrário, o acelerador especificado pela variável de ambiente CPPAMP_DEFAULT_ACCELERATOR, se ele for definido.  
  
3.  Caso contrário, um dispositivo não emulados.  
  
4.  Caso contrário, o dispositivo que tem a maior quantidade de memória disponível.  
  
5.  Caso contrário, um dispositivo que não está anexado à exibição.  
  
 Além disso, o tempo de execução Especifica um `access_type` de `access_type_auto` para o acelerador padrão. Isso significa que o acelerador padrão usa a memória compartilhada se ele tem suporte e suas características de desempenho (largura de banda e latência) são conhecidas como a mesma memória dedicada (não compartilhado).  
  
 Você pode determinar as propriedades do acelerador padrão construindo o acelerador padrão e examinar suas propriedades. O exemplo de código a seguir imprime o caminho, a quantidade de memória de aceleração, suporte à memória compartilhada, suporte de precisão dupla e suporte limitado de precisão dupla do acelerador padrão.  
  
```cpp  
void default_properties() {  
    accelerator default_acc;  
    std::wcout << default_acc.device_path << "\n";  
    std::wcout << default_acc.dedicated_memory << "\n";  
    std::wcout << (accs[i].supports_cpu_shared_memory ?   
        "CPU shared memory: true" : "CPU shared memory: false") << "\n";  
    std::wcout << (accs[i].supports_double_precision ?   
        "double precision: true" : "double precision: false") << "\n";  
    std::wcout << (accs[i].supports_limited_double_precision ?   
        "limited double precision: true" : "limited double precision: false") << "\n";  
}  
 
```  
  
### <a name="cppampdefaultaccelerator-environment-variable"></a>Variável de ambiente CPPAMP_DEFAULT_ACCELERATOR  
 Você pode definir a variável de ambiente CPPAMP_DEFAULT_ACCELERATOR para especificar o `accelerator::device_path` do acelerador padrão. O caminho é dependente do hardware. O código a seguir usa o `accelerator::get_all` de função para recuperar uma lista de aceleradores de disponível e, em seguida, exibe o caminho e as características de cada acelerador.  
  
```cpp  
void list_all_accelerators()  
{  
    std::vector<accelerator> accs = accelerator::get_all();  
  
    for (int i = 0; i <accs.size(); i++) {  
        std::wcout << accs[i].device_path << "\n";  
        std::wcout << accs[i].dedicated_memory << "\n";  
        std::wcout << (accs[i].supports_cpu_shared_memory ?   
            "CPU shared memory: true" : "CPU shared memory: false") << "\n";  
        std::wcout << (accs[i].supports_double_precision ?   
            "double precision: true" : "double precision: false") << "\n";  
        std::wcout << (accs[i].supports_limited_double_precision ?   
            "limited double precision: true" : "limited double precision: false") << "\n";  
    }  
}  
```  
  
## <a name="selecting-an-accelerator"></a>Selecionando um acelerador  
 Para selecionar um acelerador, use o `accelerator::get_all` método para recuperar uma lista de aceleradores de disponível e, em seguida, selecione uma com base em suas propriedades. Este exemplo mostra como selecionar o Acelerador que tem a maior parte da memória:  
  
```cpp  
void pick_with_most_memory()  
{  
    std::vector<accelerator> accs = accelerator::get_all();
    accelerator acc_chosen = accs[0];  
    
    for (int i = 0; i <accs.size(); i++) {  
        if (accs[i].dedicated_memory> acc_chosen.dedicated_memory) {  
            acc_chosen = accs[i];  
        }  
    }  
 
    std::wcout << "The accelerator with the most memory is "    
        << acc_chosen.device_path << "\n"  
        << acc_chosen.dedicated_memory << ".\n";  
}  
```  
  
> [!NOTE]
>  Um dos aceleradores que são retornados pelo `accelerator::get_all` é o Acelerador de CPU. Você não pode executar código no Acelerador de CPU. Para filtrar o Acelerador de CPU, comparar o valor da [device_path](reference/accelerator-class.md#device_path) propriedade do acelerador que é retornado por `accelerator::get_all` com o valor da [Accelerator:: cpu_accelerator](reference/accelerator-class.md#cpu_accelerator). Para obter mais informações, consulte a seção "Aceleradores especial" neste artigo.  
  
## <a name="shared-memory"></a>Memória compartilhada  
 Memória compartilhada é a memória que pode ser acessada por CPU e o acelerador. O uso de memória compartilhada elimina ou reduz significativamente a sobrecarga de cópia de dados entre a CPU e o acelerador. Embora a memória é compartilhada, não pode ser acessado simultaneamente por CPU e o acelerador, e isso fizer um comportamento indefinido. A propriedade accelerator [supports_cpu_shared_memory](reference/accelerator-class.md#supports_cpu_shared_memory) retorna `true` se o Acelerador oferece suporte à memória compartilhada e o [default_cpu_access_type](reference/accelerator-class.md#default_cpu_access_type) propriedade obtém o padrão [access_type](reference/concurrency-namespace-enums-amp.md#access_type) para a memória alocada no `accelerator`— por exemplo, `array`s associados a `accelerator`, ou `array_view` objetos acessados no `accelerator`. 
  
 O tempo de execução C++ AMP escolhe automaticamente o melhor padrão `access_type` para cada `accelerator`, mas as características de desempenho (largura de banda e latência) de memória compartilhada podem ser piores do que aqueles de memória dedicada accelerator (não compartilhada) durante a leitura da CPU, gravando da CPU, ou ambos. Se a memória compartilhada executa, bem como memória dedicada para leitura e gravação da CPU, o tempo de execução padrão `access_type_read_write`; caso contrário, o tempo de execução escolhe um padrão mais conservadora `access_type`e permite que o aplicativo para substituí-la se acessar a memória padrões de kernels sua computação se beneficiar de um `access_type`.  
  
 O exemplo de código a seguir mostra como determinar se o acelerador padrão oferece suporte à memória compartilhada e, em seguida, substitui o seu tipo de acesso padrão e cria um `accelerator_view` dele.  
  
```cpp  
#include <amp.h>  
#include <iostream>  
  
using namespace Concurrency;  
  
int main()  
{  
    accelerator acc = accelerator(accelerator::default_accelerator);  
  
    // Early out if the default accelerator doesn’t support shared memory.  
    if (!acc.supports_cpu_shared_memory)  
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
 Você pode alterar o acelerador padrão chamando o `accelerator::set_default` método. Você pode alterar o acelerador padrão apenas uma vez por aplicativo execução e você deve alterá-la antes de qualquer código que é executado na GPU. Qualquer chamada de função subsequentes para alterar o Acelerador de retorna `false`. Se você deseja usar um acelerador de diferente em uma chamada para `parallel_for_each`, leia a seção "Usando vários aceleradores" neste artigo. O exemplo de código a seguir define o acelerador padrão para um que não é emulado, não está conectado a uma exibição e dá suporte à precisão dupla.  
  
```cpp  
bool pick_accelerator()  
{  
    std::vector<accelerator> accs = accelerator::get_all();
    accelerator chosen_one;  
 
    auto result = std::find_if(accs.begin(), accs.end(), 
        [] (const accelerator& acc) {  
            return !acc.is_emulated && 
                acc.supports_double_precision && 
                !acc.has_display;  
        });
  
    if (result != accs.end()) {  
        chosen_one = *(result);
    }
  
    std::wcout <<chosen_one.description <<std::endl;  
    bool success = accelerator::set_default(chosen_one.device_path);
    return success;  
}  
```  
  
## <a name="using-multiple-accelerators"></a>Usando vários aceleradores  
 Há duas maneiras de usar aceleradores de vários em seu aplicativo:  

-   Você pode passar `accelerator_view` objetos para as chamadas para o [parallel_for_each](reference/concurrency-namespace-functions-amp.md#parallel_for_each) método.  
  
-   Você pode construir um `array` usando uma versão específica do objeto `accelerator_view` objeto. O tempo de execução do C + AMP escolherá o `accelerator_view` objeto de capturados `array` objeto na expressão lambda.  
  
## <a name="special-accelerators"></a>Aceleradores especiais  
 Os caminhos de dispositivo de três Aceleradores especiais estão disponíveis como propriedades da `accelerator` classe:  
  
- [Accelerator:: direct3d_ref membro de dados](reference/accelerator-class.md#direct3d_ref): esse acelerador de thread único usa software da CPU para emular uma placa gráfica genérico. Ele é usado por padrão para depuração, mas não é útil em produção porque é mais lenta do que os aceleradores de hardware. Além disso, ele só está disponível no SDK do DirectX e o SDK do Windows e é improvável ser instalado em computadores de seus clientes. Para obter mais informações, consulte [depuração GPU código](/visualstudio/debugger/debugging-gpu-code).  
  
- [Accelerator:: direct3d_warp membro de dados](reference/accelerator-class.md#direct3d_warp): esse acelerador fornece uma solução de fallback para a execução de código C++ AMP em CPUs de vários núcleos que usam extensões de SIMD de Streaming (SSE).  
  
- [Accelerator:: cpu_accelerator membro de dados](reference/accelerator-class.md#cpu_accelerator): você pode usar esse acelerador para configurar conjuntos de preparo. Ele não é possível executar o código C++ AMP. Para obter mais informações, consulte o [matrizes de preparo no C++ AMP](http://go.microsoft.com/fwlink/p/?linkId=248485) postagem em programação paralela no blog de código nativo.  
  
## <a name="interoperability"></a>Interoperabilidade  
 O tempo de execução C++ AMP dá suporte a interoperabilidade entre o `accelerator_view` classe e o Direct3D [ID3D11Device interface](http://go.microsoft.com/fwlink/p/?linkId=248488). O [create_accelerator_view](reference/concurrency-direct3d-namespace-functions-amp.md#create_accelerator_view) leva um `IUnknown` interface e retorna um `accelerator_view` objeto. O [get_device](http://msdn.microsoft.com/en-us/8194125e-8396-4d62-aa8a-65831dea8439) leva um `accelerator_view` objeto e retorna um `IUknown` interface.  
  
## <a name="see-also"></a>Consulte também  
 [C++ AMP (C++ Accelerated Massive Parallelism)](../../parallel/amp/cpp-amp-cpp-accelerated-massive-parallelism.md)   
 [Depurando código de GPU](/visualstudio/debugger/debugging-gpu-code)   
 [Classe accelerator_view](../../parallel/amp/reference/accelerator-view-class.md)
