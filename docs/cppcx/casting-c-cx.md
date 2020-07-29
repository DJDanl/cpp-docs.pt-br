---
title: Conversão (C++/CX)
ms.date: 06/19/2018
ms.assetid: 5247f6c7-6a0a-4021-97c9-21c868bd9455
ms.openlocfilehash: a51e02b59b2f7229193987f993edbccfb56b779d
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87233516"
---
# <a name="casting-ccx"></a>Conversão (C++/CX)

Quatro operadores de conversão diferentes se aplicam a tipos de Windows Runtime: [operador de static_cast](../cpp/static-cast-operator.md), [operador de dynamic_cast](../cpp/dynamic-cast-operator.md), operador de **safe_cast**e [operador de reinterpret_cast](../cpp/reinterpret-cast-operator.md). **safe_cast** e **`static_cast`** gerar uma exceção quando a conversão não puder ser executada; [Static_cast operador](../cpp/static-cast-operator.md) também executa a verificação de tipo em tempo de compilação. **`dynamic_cast`** retorna **`nullptr`** se falha ao converter o tipo. Embora **`reinterpret_cast`** o retorne um valor não nulo, ele pode ser inválido. Por esse motivo, recomendamos que você não use **`reinterpret_cast`** a menos que saiba que a conversão terá sucesso. Além disso, recomendamos que você não use conversões de estilo C em seu código C++/CX porque elas são idênticas a **`reinterpret_cast`** .

O compilador e o runtime também executam conversões implícitas - por exemplo, em operações de conversão boxing quando um tipo de valor ou um tipo interno é transmitido como argumentos para um método cujo tipo de parâmetro é `Object^`. Em tese, uma conversão implícita nunca deve causar uma exceção no tempo de execução; se o compilador não puder executar uma conversão implícita, ele gerará um erro no tempo de compilação.

Windows Runtime é uma abstração sobre COM, que usa códigos de erro HRESULT em vez de exceções. Em geral, [Platform::InvalidCastException](../cppcx/platform-invalidcastexception-class.md) indica um erro COM de nível baixo de E_NOINTERFACE.

## <a name="static_cast"></a>static_cast

Um **`static_cast`** é verificado no momento da compilação para determinar se há uma relação de herança entre os dois tipos. A conversão causará um erro do compilador se os tipos não estiverem relacionados.

Um **`static_cast`** em uma classe ref também faz com que uma verificação de tempo de execução seja executada. R **`static_cast`** em uma classe ref pode passar a verificação de tempo de compilação, mas ainda falha em tempo de execução; nesse caso, um `Platform::InvalidCastException` é gerado. Geralmente, você não precisa tratar essas exceções, pois quase sempre elas indicam erros de programação que você pode eliminar durante as fases de desenvolvimento e teste.

Use **`static_cast`** se o código declarar explicitamente uma relação entre os dois tipos e, portanto, você tiver certeza de que a conversão deve funcionar.

```cpp
    interface class A{};
    public ref class Class1 sealed : A { };
    // ...
    A^ obj = ref new Class1(); // Class1 is an A
    // You know obj is a Class1. The compiler verifies that this is possible, and in C++/CX a run-time check is also performed.
    Class1^ c = static_cast<Class1^>(obj);
```

## <a name="safe_cast"></a>safe_cast

O operador de **safe_cast** faz parte de Windows Runtime. Ele executa uma verificação de tipo no tempo de execução e gera `Platform::InvalidCastException` se houver falhas na conversão. Use **safe_cast** quando uma falha de tempo de execução indica uma condição excepcional. A principal finalidade do **safe_cast** é ajudar a identificar erros de programação durante as fases de desenvolvimento e teste no ponto em que ocorrem. Você não precisa lidar com a exceção porque a própria exceção não tratada identifica o ponto de falha.

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

## <a name="dynamic_cast"></a>dynamic_cast

Use **`dynamic_cast`** quando você converte um objeto (mais especificamente, um chapéu **^** ) para um tipo mais derivado, você espera que o objeto de destino às vezes seja **`nullptr`** ou que a conversão possa falhar, e você deseja tratar essa condição como um caminho de código normal em vez de uma exceção. Por exemplo, no modelo de projeto **aplicativo em branco (universal do Windows)** , o `OnLaunched` método em app. Xamp. cpp usa **`dynamic_cast`** para testar se a janela do aplicativo tem conteúdo. Não será um erro se não tiver conteúdo; é uma condição esperada. `Windows::Current::Content` é um `Windows::UI::XAML::UIElement` , e a conversão é em `Windows::UI.XAML::Controls::Frame`, que é um tipo mais derivado na hierarquia de herança.

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

Outro uso do **`dynamic_cast`** é investigar um `Object^` para determinar se ele contém um tipo de valor em caixa. Nesse caso, você tenta um `dynamic_cast<Platform::Box>` ou um `dynamic_cast<Platform::IBox>`.

## <a name="dynamic_cast-and-tracking-references-"></a>dynamic_cast e referências de acompanhamento (%)

Você também pode aplicar um **`dynamic_cast`** a uma referência de rastreamento, mas, nesse caso, a conversão se comporta como **safe_cast**. Ela `Platform::InvalidCastException` é lançada em caso de falha porque uma referência de rastreamento não pode ter um valor de **`nullptr`** .

## <a name="reinterpret_cast"></a>reinterpret_cast

É recomendável não usar [reinterpret_cast](../cpp/reinterpret-cast-operator.md) , pois não serão executadas verificações de tempo de compilação nem de tempo de execução. Na pior das hipóteses, um **`reinterpret_cast`** possibilita que erros de programação não sejam detectados no momento do desenvolvimento e cause erros sutis ou catastróficos no comportamento do seu programa. Portanto, recomendamos que você use **`reinterpret_cast`** apenas nesses casos raros quando você deve converter entre tipos não relacionados e sabe que a conversão terá sucesso. Um exemplo de um uso raro é converter um tipo de Windows Runtime para seu tipo de ABI subjacente — isso significa que você está assumindo o controle da contagem de referência para o objeto. Para fazer isso, recomendamos usar o ponteiro inteligente [ComPtr Class](../cpp/com-ptr-t-class.md) . Caso contrário, você deverá chamar especificamente a versão na interface. O exemplo a seguir mostra como uma classe de referência pode ser convertida em `IInspectable*`.

```cpp
#include <wrl.h>
using namespace Microsoft::WRL;
auto winRtObject = ref new SomeWinRTType();
ComPtr<IInspectable> inspectable = reinterpret_cast<IInspectable*>(winRtObject);
// ...
```

Se você usar o **`reinterpret_cast`** para converter da interface de tempo de execução oneWindows para outra, fará com que o objeto seja liberado duas vezes. Portanto, use essa conversão somente quando você estiver convertendo para uma interface de extensões de componente não C + +.

## <a name="abi-types"></a>Tipos de ABI.

- Os tipos de ABI permanecem ativos em cabeçalhos no Windows SDK. Convenientemente, os cabeçalhos são nomeados com namespaces - por exemplo, `windows.storage.h`.

- Os tipos de ABI permanecem ativos em uma ABI de namespace especial - por exemplo, `ABI::Windows::Storage::Streams::IBuffer*`.

- Conversões entre um tipo de interface Windows Runtime e seu tipo equivalente de ABI são sempre seguros, ou seja, `IBuffer^` para `ABI::IBuffer*` .

- Uma classe de tempo de execução Windows Runtime sempre deve ser convertida em `IInspectable*` ou em sua interface padrão, se isso for conhecido.

- Depois de converter em tipos de ABI, você possui o tempo de vida do tipo e deverá seguir as regras COM. Recomendamos usar `WRL::ComPtr` para simplificar o gerenciamento de tempo de vida de ponteiros de ABI.

A tabela a seguir resume os casos em que é seguro usar **`reinterpret_cast`** . Em todos os casos, a conversão é segura em ambas as direções.

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

## <a name="see-also"></a>Confira também

- [Sistema de tipo](../cppcx/type-system-c-cx.md)
- [Referência de linguagem do C++/CX](../cppcx/visual-c-language-reference-c-cx.md)
- [Referência de namespaces](../cppcx/namespaces-reference-c-cx.md)
