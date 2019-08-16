---
title: Usando objetos accelerator e accelerator_view
ms.date: 11/04/2016
ms.assetid: 18f0dc66-8236-4420-9f46-1a14f2c3fba1
ms.openlocfilehash: 80d9c26f636cc736f90eacddea07a8fc31caff93
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69512875"
---
# <a name="using-accelerator-and-accelerator_view-objects"></a>Usando objetos accelerator e accelerator_view

Você pode usar as classes [Accelerator](../../parallel/amp/reference/accelerator-class.md) e [accelerator_view](../../parallel/amp/reference/accelerator-view-class.md) para especificar o dispositivo ou emulador no qual C++ executar o amp code. Um sistema pode ter vários dispositivos ou emuladores que diferem por quantidade de memória, suporte a memória compartilhada, suporte à depuração ou suporte de precisão dupla. C++O amp (C++ grande paralelismo) acelerado fornece APIs que você pode usar para examinar os Aceleradores disponíveis, definir um como padrão, especificar vários accelerator_views para várias chamadas para parallel_for_each e executar tarefas de depuração especiais.

## <a name="using-the-default-accelerator"></a>Usando o acelerador padrão

O C++ tempo de execução de amp escolhe um acelerador padrão, a menos que você escreva o código para escolher um específico. O tempo de execução escolhe o acelerador padrão da seguinte maneira:

1. Se o aplicativo estiver sendo executado no modo de depuração, um acelerador que dá suporte à depuração.

2. Caso contrário, o acelerador especificado pela variável de ambiente CPPAMP_DEFAULT_ACCELERATOR, se estiver definido.

3. Caso contrário, um dispositivo não emulado.

4. Caso contrário, o dispositivo que tem a maior quantidade de memória disponível.

5. Caso contrário, um dispositivo que não está anexado à exibição.

Além disso, o tempo de `access_type` execução `access_type_auto` especifica um de para o acelerador padrão. Isso significa que o acelerador padrão usa memória compartilhada se houver suporte e se suas características de desempenho (largura de banda e latência) forem conhecidas como memória dedicada (não compartilhada).

Você pode determinar as propriedades do acelerador padrão construindo o acelerador padrão e examinando suas propriedades. O exemplo de código a seguir imprime o caminho, a quantidade de memória do acelerador, o suporte à memória compartilhada, o suporte de precisão dupla e o suporte limitado à precisão dupla do acelerador padrão.

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

### <a name="cppamp_default_accelerator-environment-variable"></a>Variável de ambiente CPPAMP_DEFAULT_ACCELERATOR

Você pode definir a variável de ambiente CPPAMP_DEFAULT_ACCELERATOR para especificar `accelerator::device_path` o do acelerador padrão. O caminho depende do hardware. O código a seguir usa `accelerator::get_all` a função para recuperar uma lista dos Aceleradores disponíveis e, em seguida, exibe o caminho e as características de cada acelerador.

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

Para selecionar um acelerador, use `accelerator::get_all` o método para recuperar uma lista dos Aceleradores disponíveis e, em seguida, selecione um com base em suas propriedades. Este exemplo mostra como escolher o acelerador que tem mais memória:

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
> Um dos aceleradores que são retornados pelo `accelerator::get_all` é o acelerador de CPU. Não é possível executar código no acelerador de CPU. Para filtrar o acelerador de CPU, compare o valor da propriedade [device_path](reference/accelerator-class.md#device_path) do acelerador que é retornado por `accelerator::get_all` com o valor do [acelerador:: cpu_accelerator](reference/accelerator-class.md#cpu_accelerator). Para obter mais informações, consulte a seção "aceleradores especiais" neste artigo.

## <a name="shared-memory"></a>Memória compartilhada

Memória compartilhada é a memória que pode ser acessada pela CPU e pelo acelerador. O uso da memória compartilhada elimina ou reduz significativamente a sobrecarga de copiar dados entre a CPU e o acelerador. Embora a memória seja compartilhada, ela não pode ser acessada simultaneamente pela CPU e pelo acelerador, e fazer isso causa um comportamento indefinido. A propriedade Accelerator [supports_cpu_shared_memory](reference/accelerator-class.md#supports_cpu_shared_memory) retornará **true** se o acelerador der suporte à memória compartilhada e a propriedade [default_cpu_access_type](reference/accelerator-class.md#default_cpu_access_type) obterá o [access_type](reference/concurrency-namespace-enums-amp.md#access_type) padrão para a memória alocada no `accelerator`— por exemplo, **matrizes**s associadas com `accelerator`os objetos `array_view` ou acessados `accelerator`no.

O C++ amp Runtime escolhe automaticamente o melhor padrão `access_type` para cada `accelerator`, mas as características de desempenho (largura de banda e latência) da memória compartilhada podem ser piores do que aquelas da memória de acelerador dedicada (não compartilhada) quando leitura da CPU, gravação da CPU ou ambos. Se a memória compartilhada for executada, bem como memória dedicada para leitura e gravação da CPU, o tempo de execução `access_type_read_write`padrão será; caso contrário, o tempo de execução `access_type`escolherá um padrão mais conservador e permitirá que o aplicativo o substitua se o acesso à memória for os padrões de seus kernels de computação se beneficiam de um diferente `access_type`.

O exemplo de código a seguir mostra como determinar se o acelerador padrão dá suporte à memória compartilhada e, em seguida, substitui seu `accelerator_view` tipo de acesso padrão e cria um dele.

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

Um `accelerator_view` sempre reflete o `default_cpu_access_type` do `accelerator` qual está associado e não fornece nenhuma interface para substituir ou alterar seu `access_type`.

## <a name="changing-the-default-accelerator"></a>Alterando o acelerador padrão

Você pode alterar o acelerador padrão chamando o `accelerator::set_default` método. Você pode alterar o acelerador padrão apenas uma vez por execução de aplicativo e deve alterá-lo antes de qualquer código ser executado na GPU. Todas as chamadas de função subsequentes para alterar o acelerador retornam **false**. Se você quiser usar um acelerador diferente em uma chamada para `parallel_for_each`, leia a seção "usando vários aceleradores" neste artigo. O exemplo de código a seguir define o acelerador padrão como um que não é emulado, não está conectado a uma exibição e dá suporte à precisão dupla.

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

Há duas maneiras de usar vários aceleradores em seu aplicativo:

- Você pode passar `accelerator_view` objetos para as chamadas para o método [parallel_for_each](reference/concurrency-namespace-functions-amp.md#parallel_for_each) .

- Você pode construir um objeto de **matriz** usando um `accelerator_view` objeto específico. O tempo de execução do C + amp selecionará o `accelerator_view` objeto do objeto de **matriz** capturado na expressão lambda.

## <a name="special-accelerators"></a>Aceleradores especiais

Os caminhos de dispositivo de três aceleradores especiais estão disponíveis como propriedades da `accelerator` classe:

- [acelerador::D membro de dados irect3d_ref](reference/accelerator-class.md#direct3d_ref): Esse acelerador de thread único usa software na CPU para emular uma placa gráfica genérica. Ele é usado por padrão para depuração, mas não é útil na produção porque é mais lento do que os aceleradores de hardware. Além disso, ele está disponível apenas no SDK do DirectX e no SDK do Windows, e é improvável que seja instalado nos computadores dos seus clientes. Para obter mais informações, consulte [depuração de código de GPU](/visualstudio/debugger/debugging-gpu-code).

- [acelerador::D membro de dados irect3d_warp](reference/accelerator-class.md#direct3d_warp): Esse acelerador fornece uma solução de fallback C++ para executar o amp code em CPUs com vários núcleos que usam SSE (Streaming SIMD Extensions).

- [membro de dados Accelerator:: cpu_accelerator](reference/accelerator-class.md#cpu_accelerator): Você pode usar esse acelerador para configurar matrizes de preparo. Ele não pode C++ executar o amp code. Para obter mais informações, consulte as [matrizes de C++ preparo em amp](https://blogs.msdn.microsoft.com/nativeconcurrency/2011/11/09/staging-arrays-in-c-amp/) post no blog sobre programação paralela em código nativo.

## <a name="interoperability"></a>Interoperabilidade

O C++ tempo de execução de amp dá suporte `accelerator_view` à interoperabilidade entre a classe e a [interface Direct3D ID3D11Device](/windows/win32/api/d3d11/nn-d3d11-id3d11device). O método [create_accelerator_view](reference/concurrency-direct3d-namespace-functions-amp.md#create_accelerator_view) usa uma `IUnknown` interface e retorna um `accelerator_view` objeto. O método [get_device](reference/concurrency-direct3d-namespace-functions-amp.md#get_device) pega um `accelerator_view` objeto e retorna uma `IUnknown` interface.

## <a name="see-also"></a>Consulte também

[C++ AMP (C++ Accelerated Massive Parallelism)](../../parallel/amp/cpp-amp-cpp-accelerated-massive-parallelism.md)<br/>
[Depurando código de GPU](/visualstudio/debugger/debugging-gpu-code)<br/>
[Classe accelerator_view](../../parallel/amp/reference/accelerator-view-class.md)
