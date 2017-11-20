---
title: "Conversão (C + + CX) | Microsoft Docs"
ms.custom: 
ms.date: 12/30/2016
ms.technology: cpp-windows
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: 5247f6c7-6a0a-4021-97c9-21c868bd9455
caps.latest.revision: "15"
author: ghogen
ms.author: ghogen
manager: ghogen
ms.openlocfilehash: f1373686ca960f86ca9e8b2ea4756911906fd66d
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="casting-ccx"></a>Conversão (C++/CX)
Quatro operadores cast diferentes se aplicam a tipos de Windows Runtime: [operador static_cast](../cpp/static-cast-operator.md), [operador dynamic_cast](../cpp/dynamic-cast-operator.md), **operador safe_cast**, e [ Operador reinterpret_cast](../cpp/reinterpret-cast-operator.md). `safe_cast` e `static_cast` geram uma exceção quando a conversão não pode ser executada; o [Operador static_cast](../cpp/static-cast-operator.md) também executa a verificação do tipo em tempo de compilação. `dynamic_cast` retornará `nullptr` se não converter o tipo. Embora `reinterpret_cast` retorne um valor não nulo, ele poderá ser inválido. Por esse motivo, é recomendável não usar `reinterpret_cast` a menos que você saiba que a conversão funcionará. Além disso, é recomendável que você não usar conversões do estilo C em C + + CX código porque eles são idênticos a `reinterpret_cast`.  
  
 O compilador e o tempo de execução também executam conversões implícitas - por exemplo, em operações de conversão boxing quando um tipo de valor ou um tipo interno é transmitido como argumentos para um método cujo tipo de parâmetro é `Object^`. Em tese, uma conversão implícita nunca deve causar uma exceção no tempo de execução; se o compilador não puder executar uma conversão implícita, ele gerará um erro no tempo de compilação.  
  
Tempo de execução do Windows é uma abstração sobre COM, que usa códigos de erro HRESULT em vez de exceções. Em geral, [Platform::InvalidCastException](../cppcx/platform-invalidcastexception-class.md) indica um erro COM de nível baixo de E_NOINTERFACE.  
  
## <a name="staticcast"></a>static_cast  
 Um `static_cast` é verificado no tempo de compilação para determinar se há uma relação de herança entre os dois tipos. A conversão causará um erro do compilador se os tipos não estiverem relacionados.  
  
 Um `static_cast` em uma classe ref também faz com que uma verificação de tempo de execução seja executada. `static_cast` em uma classe de referência pode transmitir a verificação de tempo de compilação, mas ainda falhar no tempo de execução; `Platform::InvalidCastException` é lançada nesse caso. Geralmente, você não precisa tratar essas exceções, pois quase sempre elas indicam erros de programação que você pode eliminar durante as fases de desenvolvimento e teste.  
  
 Use `static_cast` se o código declarar explicitamente uma relação entre os dois tipos e se você estiver certo de que a conversão funcionará.  
  
```
    interface class A{};  
    public ref class Class1 sealed : A { };  
...  
    A^ obj = ref new Class1(); // Class1 is an A  
    // You know obj is a Class1. The compiler verifies that this is possible, and in C++/CX a run-time check is also performed.  
    Class1^ c = static_cast<Class1^>(obj);
```  
  
## <a name="safecast"></a>safe_cast  
 O `safe_cast` operador é parte ofWindows tempo de execução. Ele executa uma verificação de tipo no tempo de execução e gera `Platform::InvalidCastException` se houver falhas na conversão. Use `safe_cast` quando uma falha no tempo de execução indicar uma condição excepcional. O objetivo principal de `safe_cast` é ajudar a identificar erros de programação durante as fases de desenvolvimento e teste no ponto em que eles ocorrem. Você não precisa lidar com a exceção porque a própria exceção não tratada identifica o ponto de falha.  
  
 Use safe_cast se o código não declarar a relação e você tiver certeza de que a conversão funcionará.  
  
```  
    // A and B are not related  
    interface class A{};  
    interface class B{};  
    public ref class Class1 sealed : A, B { };  
...  
    A^ obj = ref new Class1();  
  
    // You know that obj’s backing type implements A and B, but  
    // the compiler can’t tell this by comparing A and B. The run-time type check succeeds.  
    B^ obj2 = safe_cast<B^>(obj);  
```  
  
## <a name="dynamiccast"></a>dynamic_cast  
 Use `dynamic_cast` quando você converter um objeto (mais especificamente, `^`) para um tipo mais derivado, esperar que o destino de objeto, às vezes, pode ser `nullptr` ou que a conversão falhe, e você desejar tratar essa condição como um código comum caminho, em vez de uma exceção. Por exemplo, no modelo de projeto **Aplicativo em Branco da Windows Store** , o método `OnLaunched` em `app.xamp.cpp` usa `dynamic_cast` para testar se a janela do aplicativo tem conteúdo. Não será um erro se não tiver conteúdo; é uma condição esperada. `Windows::Current::Content` é um `Windows::UI::XAML::UIElement` , e a conversão é em `Windows::UI.XAML::Controls::Frame`, que é um tipo mais derivado na hierarquia de herança.  
```
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
...  
```  
 Outro uso de `dynamic_cast` é investigar um `Object^` para determinar se ele contém um tipo de valor demarcado. Nesse caso, você tenta um `dynamic_cast<Platform::Box>` ou um `dynamic_cast<Platform::IBox>`.  
  
 **dynamic_cast e referências de acompanhamento (%)**  
  
 Você também pode aplicar `dynamic_cast` a uma referência de acompanhamento, mas nesse caso a conversão se comporta como `safe_cast`. Ela gera `Platform::InvalidCastException` em caso de falha porque uma referência de acompanhamento não pode ter um valor de `nullptr`.  
  
## <a name="reinterpretcast"></a>reinterpret_cast  
 É recomendável não usar [reinterpret_cast](../cpp/reinterpret-cast-operator.md) , pois não serão executadas verificações de tempo de compilação nem de tempo de execução. No pior dos casos, um `reinterpret_cast` permite que erros de programação não sejam detectados no período de desenvolvimento e causem erros sutis ou catastróficos no comportamento do programa. Dessa forma, recomendamos que você use `reinterpret_cast` apenas em casos raros em que for necessário converter tipos não relacionados e você tiver certeza de que a conversão funcionará. Um exemplo de uso incomum é converter aWindows tipo de tempo de execução ao seu tipo ABI subjacente-isso significa que você assumindo o controle da referência da contagem do objeto. Para fazer isso, recomendamos usar o ponteiro inteligente [ComPtr Class](../cpp/com-ptr-t-class.md) . Caso contrário, você deverá chamar especificamente a versão na interface. O exemplo a seguir mostra como uma classe de referência pode ser convertida em `IInspectable*`.  
  
```  
#include <wrl.h>  
using namespace Microsoft::WRL;  
auto winRtObject = ref new SomeWinRTType();  
ComPtr<IInspectable> inspectable = reinterpret_cast<IInspectable*>(winRtObject);  
...
```  
  
 Se você usar `reinterpret_cast` para converter de interface de tempo de execução oneWindows para outra, é fazer com que o objeto será liberado duas vezes. Dessa forma, use essa conversão apenas quando estiver convertendo uma interface que não seja de[!INCLUDE[cppwrt](../cppcx/includes/cppwrt-md.md)] .  
  
 **Tipos de ABI.**  
  
-   Os tipos de ABI permanecem ativos em cabeçalhos no Windows SDK. Convenientemente, os cabeçalhos são nomeados com namespaces - por exemplo, `windows.storage.h`.  
  
-   Os tipos de ABI permanecem ativos em uma ABI de namespace especial - por exemplo, `ABI::Windows::Storage::Streams::IBuffer*`.  
  
-   Conversões entre o tipo de interface de tempo de execução aWindows e seu tipo ABI equivalente são sempre seguras — ou seja, `IBuffer^` para `ABI::IBuffer*`.  
  
-   Classe de tempo de execução AWindows Runtime deve sempre ser convertida em `IInspectable*` ou sua interface padrão, se for conhecida.  
  
-   Depois de converter em tipos de ABI, você possui o tempo de vida do tipo e deverá seguir as regras COM. Recomendamos usar `WRL::ComPtr` para simplificar o gerenciamento de tempo de vida de ponteiros de ABI.  
  
 A tabela a seguir resume os casos em que é seguro usar `reinterpret_cast`. Em todos os casos, a conversão é segura em ambas as direções.  
  
|||  
|-|-|  
|HSTRING|String^|  
|HSTRING*|String^*|  
|IInspectable*|Object^|  
|IInspectable**|Object^*|  
|IInspectable-derived-type*|same-interface-from-winmd^|  
|IInspectable-derived-type**|same-interface-from-winmd^*|  
|IDefault-interface-of-RuntimeClass*|same-RefClass-from-winmd^|  
|IDefault-interface-of-RuntimeClass**|same-RefClass-from-winmd^*|  
  
## <a name="see-also"></a>Consulte também  
 [Sistema de tipos](../cppcx/type-system-c-cx.md)   
 [Referência de linguagem do Visual C++](../cppcx/visual-c-language-reference-c-cx.md)   
 [Referência de namespaces](../cppcx/namespaces-reference-c-cx.md)
