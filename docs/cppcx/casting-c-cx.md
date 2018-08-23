---
title: Conversão (C++ c++ /CX) | Microsoft Docs
ms.custom: ''
ms.date: 06/19/2018
ms.technology: cpp-windows
ms.topic: language-reference
ms.assetid: 5247f6c7-6a0a-4021-97c9-21c868bd9455
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ea0ac57b178baed76e6ccb7418c778c1ba2306f4
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42613296"
---
# <a name="casting-ccx"></a>Conversão (C++/CX)

Quatro operadores cast diferentes se aplicam a tipos de tempo de execução do Windows: [operador static_cast](../cpp/static-cast-operator.md), [operador dynamic_cast](../cpp/dynamic-cast-operator.md), **operador safe_cast**, e [ Operador reinterpret_cast](../cpp/reinterpret-cast-operator.md). **Safe_cast** e **static_cast** lançar uma exceção quando a conversão não pode ser executada; [operador static_cast](../cpp/static-cast-operator.md) também executa a verificação de tipo de tempo de compilação. **dynamic_cast** retorna **nullptr** se ele falhar ao converter o tipo. Embora **reinterpret_cast** retorna um valor não nulo, ele poderá ser inválido. Por esse motivo, recomendamos que você não use **reinterpret_cast** , a menos que você sabe que a conversão seja bem-sucedida. Além disso, é recomendável que você não use conversões de estilo C em seu C + + c++ /CLI CX código porque elas são idênticas às **reinterpret_cast**.

O compilador e o tempo de execução também executam conversões implícitas - por exemplo, em operações de conversão boxing quando um tipo de valor ou um tipo interno é transmitido como argumentos para um método cujo tipo de parâmetro é `Object^`. Em tese, uma conversão implícita nunca deve causar uma exceção no tempo de execução; se o compilador não puder executar uma conversão implícita, ele gerará um erro no tempo de compilação.

Tempo de execução do Windows é uma abstração sobre COM, que usa códigos de erro HRESULT em vez de exceções. Em geral, [Platform::InvalidCastException](../cppcx/platform-invalidcastexception-class.md) indica um erro COM de nível baixo de E_NOINTERFACE.

## <a name="staticcast"></a>static_cast

Um **static_cast** é verificada em tempo de compilação para determinar se há uma relação de herança entre os dois tipos. A conversão causará um erro do compilador se os tipos não estiverem relacionados.

Um **static_cast** em uma referência de classe também faz com que uma verificação de tempo de execução a ser executada. Um **static_cast** em uma referência de classe pode passar pela verificação de tempo de compilação, mas ainda falhar no tempo de execução; nesse caso um `Platform::InvalidCastException` é gerada. Geralmente, você não precisa tratar essas exceções, pois quase sempre elas indicam erros de programação que você pode eliminar durante as fases de desenvolvimento e teste.

Use **static_cast** se o código declara explicitamente uma relação entre os dois tipos, e, portanto, tem certeza que a conversão funcionará.

```cpp
    interface class A{};
    public ref class Class1 sealed : A { };
    // ...
    A^ obj = ref new Class1(); // Class1 is an A
    // You know obj is a Class1. The compiler verifies that this is possible, and in C++/CX a run-time check is also performed.
    Class1^ c = static_cast<Class1^>(obj);
```

## <a name="safecast"></a>safe_cast

O **safe_cast** operador faz parte do tempo de execução do Windows. Ele executa uma verificação de tipo no tempo de execução e gera `Platform::InvalidCastException` se houver falhas na conversão. Use **safe_cast** quando uma falha de tempo de execução indica uma condição excepcional. A principal finalidade de **safe_cast** é ajudar a identificar erros de programação durante o desenvolvimento e teste fases no ponto em que eles ocorrem. Você não precisa lidar com a exceção porque a própria exceção não tratada identifica o ponto de falha.

Use safe_cast se o código não declarar a relação e você tiver certeza de que a conversão funcionará.

```cpp
    // A and B are not related
    interface class A{};
    interface class B{};
    public ref class Class1 sealed : A, B { };
    // ...
    A^ obj = ref new Class1();

    // You know that obj’s backing type implements A and B, but
    // the compiler can’t tell this by comparing A and B. The run-time type check succeeds.
    B^ obj2 = safe_cast<B^>(obj);
```

## <a name="dynamiccast"></a>dynamic_cast

Use **dynamic_cast** quando você converter um objeto (mais especificamente, um chapéu **^**) para um tipo mais derivado, esperar que o destino de objeto, às vezes, pode ser **nullptr** ou que a conversão poderá falhar e você deseja tratar essa condição como um caminho de código normal em vez de uma exceção. Por exemplo, nos **aplicativo em branco (Universal Windows)** modelo de projeto, o `OnLaunched` método app.xamp.cpp usa **dynamic_cast** para testar se a janela do aplicativo tem conteúdo. Não será um erro se não tiver conteúdo; é uma condição esperada. `Windows::Current::Content` é um `Windows::UI::XAML::UIElement` , e a conversão é em `Windows::UI.XAML::Controls::Frame`, que é um tipo mais derivado na hierarquia de herança.

```cpp
void App::OnLaunched(Windows::ApplicationModel::Activation::LaunchActivatedEventArgs^ args)
{
    auto rootFrame = dynamic_cast<Frame^>(Window::Current->Content);

    // Do not repeat app initialization when the window already has content,
    // just ensure that the window is active
    if (rootFrame == nullptr)
    {
        // Create a Frame to act as the navigation context and associate it with
        // a SuspensionManager key
        rootFrame = ref new Frame();
        // ...
    }
}
```

Outro uso dos **dynamic_cast** é investigar um `Object^` para determinar se ele contém um tipo de valor Demarcado. Nesse caso, você tenta um `dynamic_cast<Platform::Box>` ou um `dynamic_cast<Platform::IBox>`.

## <a name="dynamiccast-and-tracking-references-"></a>dynamic_cast e referências de acompanhamento (%)

Você também pode aplicar uma **dynamic_cast** para uma referência de rastreamento, mas nesse caso, a conversão se comporta como **safe_cast**. Ele gera `Platform::InvalidCastException` em caso de falha porque uma referência de rastreamento não pode ter um valor de **nullptr**.

## <a name="reinterpretcast"></a>reinterpret_cast

É recomendável não usar [reinterpret_cast](../cpp/reinterpret-cast-operator.md) , pois não serão executadas verificações de tempo de compilação nem de tempo de execução. Na pior das hipóteses, uma **reinterpret_cast** torna possível para a programação de erros de não ser detectados em tempo de desenvolvimento e causar erros sutis ou catastróficos no comportamento do programa. Portanto, é recomendável que você use **reinterpret_cast** apenas em casos raros em que você deve converter entre tipos não relacionados e você sabe que a conversão seja bem-sucedida. Um exemplo de uso incomum é converter um tipo de tempo de execução do Windows para seu tipo ABI subjacente — isso significa que você está assumindo o controle a contagem de referência para o objeto. Para fazer isso, recomendamos usar o ponteiro inteligente [ComPtr Class](../cpp/com-ptr-t-class.md) . Caso contrário, você deverá chamar especificamente a versão na interface. O exemplo a seguir mostra como uma classe de referência pode ser convertida em `IInspectable*`.

```cpp
#include <wrl.h>
using namespace Microsoft::WRL;
auto winRtObject = ref new SomeWinRTType();
ComPtr<IInspectable> inspectable = reinterpret_cast<IInspectable*>(winRtObject);
// ...
```

Se você usar **reinterpret_cast** para converter de interface de tempo de execução oneWindows para outro, você fazer com que o objeto será liberado duas vezes. Portanto, use essa conversão apenas quando você estiver convertendo para uma interface de extensões de componente não - Visual C++.

## <a name="abi-types"></a>Tipos de ABI.

- Os tipos de ABI permanecem ativos em cabeçalhos no Windows SDK. Convenientemente, os cabeçalhos são nomeados com namespaces - por exemplo, `windows.storage.h`.

- Os tipos de ABI permanecem ativos em uma ABI de namespace especial - por exemplo, `ABI::Windows::Storage::Streams::IBuffer*`.

- Conversões entre um tipo de interface de tempo de execução do Windows e seu tipo de ABI equivalente são sempre seguras — ou seja, `IBuffer^` para `ABI::IBuffer*`.

- Uma classe de tempo de execução do Windows Runtime sempre deve ser convertida em `IInspectable*` ou sua interface padrão, se for conhecida.

- Depois de converter em tipos de ABI, você possui o tempo de vida do tipo e deverá seguir as regras COM. Recomendamos usar `WRL::ComPtr` para simplificar o gerenciamento de tempo de vida de ponteiros de ABI.

A tabela a seguir resume os casos em que é seguro usar **reinterpret_cast**. Em todos os casos, a conversão é segura em ambas as direções.

|||
|-|-|
|`HSTRING`|`String^`|
|`HSTRING*`|`String^*`|
|`IInspectable*`|`Object^`|
|`IInspectable**`|`Object^*`|
|`IInspectable-derived-type*`|`same-interface-from-winmd^`|
|`IInspectable-derived-type**`|`same-interface-from-winmd^*`|
|`IDefault-interface-of-RuntimeClass*`|`same-RefClass-from-winmd^`|
|`IDefault-interface-of-RuntimeClass**`|`same-RefClass-from-winmd^*`|

## <a name="see-also"></a>Consulte também

- [Sistema de tipos](../cppcx/type-system-c-cx.md)
- [Referência de linguagem do Visual C++](../cppcx/visual-c-language-reference-c-cx.md)
- [Referência de namespaces](../cppcx/namespaces-reference-c-cx.md)
