---
title: Usando objetos accelerator e accelerator_view
ms.date: 11/04/2016
ms.assetid: 18f0dc66-8236-4420-9f46-1a14f2c3fba1
ms.openlocfilehash: 4144adf288ddefd7f7dd00ada91f97aea94e6bce
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50668592"
---
# <a name="using-accelerator-and-acceleratorview-objects"></a>Usando objetos accelerator e accelerator_view

Você pode usar o [accelerator](../../parallel/amp/reference/accelerator-class.md) e [accelerator_view](../../parallel/amp/reference/accelerator-view-class.md) classes para especificar o dispositivo ou emulador para executar seu código C++ AMP em. Um sistema pode ter vários dispositivos ou emuladores que diferem pela quantidade de memória, suporte à memória compartilhada, suporte à depuração ou suporte de precisão dupla. C++ Accelerated Massive Parallelism (C++ AMP) fornece APIs que você pode usar para examinar os Aceleradores disponíveis, definir um como padrão, especificar várias accelerator_views para chamadas múltiplas ao parallel_for_each e executar tarefas de depuração especiais.

## <a name="using-the-default-accelerator"></a>Usando o acelerador padrão

O tempo de execução C++ AMP escolhe um acelerador padrão, a menos que você escreva código para escolher um específico. O tempo de execução escolhe o acelerador padrão da seguinte maneira:

1. Se o aplicativo estiver em execução no modo de depuração, um acelerador que oferece suporte à depuração.

2. Caso contrário, o Acelerador que é especificado pela variável de ambiente CPPAMP_DEFAULT_ACCELERATOR, se ele for definido.

3. Caso contrário, um dispositivo não emulado.

4. Caso contrário, o dispositivo que tem a maior quantidade de memória disponível.

5. Caso contrário, um dispositivo que não está anexado à exibição.

Além disso, o tempo de execução Especifica um `access_type` de `access_type_auto` para o acelerador padrão. Isso significa que o acelerador padrão usa a memória compartilhada se ele tem suporte e se suas características de desempenho (largura de banda e latência) são conhecidas por ser o mesmo que a memória dedicada (não compartilhada).

Você pode determinar as propriedades do acelerador padrão construindo o acelerador padrão e examinando suas propriedades. O exemplo de código a seguir mostra o caminho, a quantidade de memória do acelerador, suporte à memória compartilhada, suporte de precisão dupla e suporte de precisão dupla limitado do acelerador padrão.

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

Você pode definir a variável de ambiente CPPAMP_DEFAULT_ACCELERATOR para especificar o `accelerator::device_path` do acelerador padrão. O caminho é dependente de hardware. O código a seguir usa o `accelerator::get_all` de função para recuperar uma lista de Aceleradores disponíveis e, em seguida, exibe o caminho e as características de cada acelerador.

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

Para selecionar um acelerador, use o `accelerator::get_all` método para recuperar uma lista de Aceleradores disponíveis e, em seguida, selecione uma com base em suas propriedades. Este exemplo mostra como escolher o Acelerador que tem a maior memória:

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
> Um dos aceleradores que são retornados pelo `accelerator::get_all` é o Acelerador de CPU. Você não pode executar o código no Acelerador CPU. Para filtrar o Acelerador de CPU, compare o valor da [device_path](reference/accelerator-class.md#device_path) propriedade do acelerador que é retornado pelo `accelerator::get_all` com o valor da [Accelerator:: cpu_accelerator](reference/accelerator-class.md#cpu_accelerator). Para obter mais informações, consulte a seção "Aceleradores especiais" neste artigo.

## <a name="shared-memory"></a>Memória compartilhada

Memória compartilhada é a memória que pode ser acessada pela CPU e pelo acelerador. O uso de memória compartilhada elimina ou reduz significativamente a sobrecarga de copiar dados entre a CPU e o acelerador. Embora a memória for compartilhada, não pode ser acessada simultaneamente pela CPU e pelo Acelerador, e isso fizer um comportamento indefinido. A propriedade do acelerador [supports_cpu_shared_memory](reference/accelerator-class.md#supports_cpu_shared_memory) retorna **verdadeiro** se o Acelerador oferece suporte à memória compartilhada e o [default_cpu_access_type](reference/accelerator-class.md#default_cpu_access_type) obtenções de propriedade o padrão [access_type](reference/concurrency-namespace-enums-amp.md#access_type) da memória alocada na `accelerator`— por exemplo, **matriz**s associados com o `accelerator`, ou `array_view` objetos acessados no `accelerator`.

O tempo de execução C++ AMP escolhe automaticamente o melhor padrão `access_type` para cada `accelerator`, mas as características de desempenho (largura de banda e latência) de memória compartilhada podem ser piores do que aqueles de memória do acelerador de (não compartilhada) dedicada ao ler da CPU, gravar da CPU, ou ambos. Se a memória compartilhada funcionar tão bem como a memória dedicada para ler e gravar da CPU, o tempo de execução padrão será `access_type_read_write`; caso contrário, o tempo de execução escolhe um padrão mais conservador `access_type`e permite que o aplicativo substituí-la se acessar a memória padrões dos kernels de computação se beneficiar de um outro `access_type`.

O exemplo de código a seguir mostra como determinar se o acelerador padrão dá suporte à memória compartilhada e, em seguida, substitui seu tipo de acesso padrão e cria um `accelerator_view` dele.

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

Uma `accelerator_view` sempre reflete o `default_cpu_access_type` da `accelerator` está associado, e não fornece nenhuma interface para substituir ou alterar seu `access_type`.

## <a name="changing-the-default-accelerator"></a>Alterando o acelerador padrão

Você pode alterar o acelerador padrão chamando o `accelerator::set_default` método. Você pode alterar o acelerador padrão apenas uma vez por aplicativo de execução e você deve alterá-lo antes de qualquer código é executado na GPU. Quaisquer chamadas de função subsequentes para alterar o acelerador retornam **falsos**. Se você deseja usar um acelerador diferente em uma chamada para `parallel_for_each`, leia a seção "Usando múltiplos aceleradores" neste artigo. O exemplo de código a seguir define o acelerador padrão para um que não é emulado, não está conectado a uma exibição e dá suporte à precisão dupla.

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

## <a name="using-multiple-accelerators"></a>Usando múltiplos aceleradores

Há duas maneiras de usar múltiplos aceleradores em seu aplicativo:

- Você pode passar `accelerator_view` objetos para as chamadas para o [parallel_for_each](reference/concurrency-namespace-functions-amp.md#parallel_for_each) método.

- Você pode construir uma **array** usando uma versão específica do objeto `accelerator_view` objeto. O tempo de execução C++ AMP pegará o `accelerator_view` objeto do capturado **matriz** objeto na expressão lambda.

## <a name="special-accelerators"></a>Aceleradores especiais

Os caminhos de dispositivo dos três Aceleradores especiais estão disponíveis como propriedades do `accelerator` classe:

- [Membro de dados de Accelerator::direct3d_ref](reference/accelerator-class.md#direct3d_ref): Este acelerador de thread único usa software na CPU para emular uma placa gráfica genérica. Ele é usado por padrão para depuração, mas não é útil na produção porque é mais lento do que os aceleradores de hardware. Além disso, ele só está disponível no SDK do DirectX e o SDK do Windows e é improvável que esteja instalado nos computadores dos seus clientes. Para obter mais informações, consulte [depurando código de GPU](/visualstudio/debugger/debugging-gpu-code).

- [Membro de dados de Accelerator::direct3d_warp](reference/accelerator-class.md#direct3d_warp): Este acelerador fornece uma solução de fallback para a execução de código C++ AMP em CPUs de vários núcleos que usam extensões de SIMD de Streaming (SSE).

- [Accelerator:: cpu_accelerator membro de dados](reference/accelerator-class.md#cpu_accelerator): você pode usar esse acelerador para configurar matrizes de teste. Ele não é possível executar o código de C++ AMP. Para obter mais informações, consulte o [Preparando matrizes no C++ AMP](https://blogs.msdn.microsoft.com/nativeconcurrency/2011/11/09/staging-arrays-in-c-amp/) postar no blog programação paralela em código nativo.

## <a name="interoperability"></a>Interoperabilidade

O tempo de execução C++ AMP oferece suporte à interoperabilidade entre o `accelerator_view` classe e o Direct3D [ID3D11Device interface](/windows/desktop/api/d3d11/nn-d3d11-id3d11device). O [create_accelerator_view](reference/concurrency-direct3d-namespace-functions-amp.md#create_accelerator_view) leva um `IUnknown` interface e retorna um `accelerator_view` objeto. O [get_device](reference/concurrency-direct3d-namespace-functions-amp.md#get_device) leva um `accelerator_view` objeto e retorna um `IUnknown` interface.

## <a name="see-also"></a>Consulte também

[C++ AMP (C++ Accelerated Massive Parallelism)](../../parallel/amp/cpp-amp-cpp-accelerated-massive-parallelism.md)<br/>
[Depurando código de GPU](/visualstudio/debugger/debugging-gpu-code)<br/>
[Classe accelerator_view](../../parallel/amp/reference/accelerator-view-class.md)