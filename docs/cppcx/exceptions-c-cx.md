---
title: Exceções (C++/CX)
ms.date: 07/02/2019
ms.assetid: 6cbdc1f1-e4d7-4707-a670-86365146432f
ms.openlocfilehash: 7b4475cfa92aa952dd5a2996508d9343255b7ed2
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87231007"
---
# <a name="exceptions-ccx"></a>Exceções (C++/CX)

O tratamento de erros no C++/CX é baseado em exceções. No nível mais fundamental, os componentes do Windows Runtime relatam erros como valores HRESULT. No C++/CX, esses valores são convertidos em exceções fortemente tipadas que contêm um valor HRESULT e uma descrição de cadeia de caracteres que você pode acessar programaticamente.  As exceções são implementadas como uma **`ref class`** derivada de `Platform::Exception` .  O namespace `Platform` define classes de exceção distinta para os valores HRESULT mais comuns; todos os outros valores são relatados por meio da classe `Platform::COMException` . Todas as classes de exceção têm um campo [Exception::HResult](platform-exception-class.md#hresult) que você pode usar para recuperar o HRESULT original. Você também pode examinar as informações de pilha de chamadas do código de usuário no depurador que podem ajudar a identificar a origem original da exceção, mesmo que tenha sido originada no código escrito em um idioma diferente do C++.

## <a name="exceptions"></a>Exceções

Em seu programa C++, você pode lançar e capturar uma exceção que vem de uma operação Windows Runtime, uma exceção derivada de `std::exception` ou um tipo definido pelo usuário. Você precisa lançar uma exceção Windows Runtime somente quando ela cruzar o limite da ABI (interface binária do aplicativo), por exemplo, quando o código que captura sua exceção é escrito em JavaScript. Quando uma exceção de C++ não Windows Runtime atinge o limite da ABI, a exceção é convertida em uma `Platform::FailureException` exceção, que representa uma E_FAIL HRESULT. Para obter mais informações sobre a ABI, consulte [Creating Windows Runtime Components in C++](/windows/uwp/winrt-components/creating-windows-runtime-components-in-cpp).

Você pode declarar uma [plataforma:: exceção](platform-exception-class.md) usando um dos dois construtores que usam um parâmetro HRESULT ou um parâmetro HRESULT e um parâmetro [Platform:: String](platform-string-class.md)^ que pode ser passado pela Abi para qualquer Windows Runtime aplicativo que o manipule. Ou pode declarar uma exceção usando uma de duas sobrecargas do [](platform-exception-class.md#createexception) método Exception::CreateException que adotam um parâmetro HRESULT, ou um parâmetro HRESULT e um parâmetro `Platform::String^` .

## <a name="standard-exceptions"></a>Exceções padrão

O C++/CX dá suporte a um conjunto de exceções padrão que representam erros de HRESULT típicos. Cada exceção padrão é derivada de [Platform::COMException](platform-comexception-class.md), que, por sua vez, é derivada de `Platform::Exception`. Quando você gera uma exceção através dos limites da ABI, é necessário gerar uma das exceções padrão.

você não pode derivar seu próprio tipo de exceção de `Platform::Exception`. Para gerar uma exceção personalizada, use um HRESULT definido pelo usuário para construir um objeto `COMException` .

A tabela a seguir lista as exceções padrão.

|Nome|HRESULT subjacente|Descrição|
|----------|------------------------|-----------------|
|COMException|*hresult definido pelo usuário*|Gerada quando um HRESULT não reconhecido é retornado de um chamada de método COM.|
|AccessDeniedException|E \_ ACCESSDENIED|Gerada quando o acesso a um recurso é negado.|
|ChangedStateException|\_estado alterado \_|Gerada quando métodos de um iterador de coleção ou uma exibição de coleção são chamados após a alteração da coleção pai, portanto, invalidando os resultados do método.|
|ClassNotRegisteredException|REGDB \_ E \_ CLASSNOTREG|Gerada quando uma classe COM não foi registrada.|
|DisconnectedException|RPC \_ E \_ desconectado|Gerada quando um objeto é desconectado de seus clientes.|
|FailureException|E \_ falha|Gerada quando uma operação falha.|
|InvalidArgumentException|E \_ INVALIDARG|Gerada quando um dos argumentos fornecidos a um método não é válido.|
|InvalidCastException|E \_ NOinterface|Gerada quando um tipo não pode ser convertido em outro tipo.|
|NotImplementedException|E \_ NOTIMPL|Gerada se um método de interface não foi implementado em uma classe.|
|NullReferenceException|\_ponteiro E|Gerada quando ocorre uma tentativa de cancelar a referência de um objeto de referência nula.|
|ObjectDisposedException|RO \_ E \_ fechado|Gerada quando uma operação é executada em um objeto descartado.|
|OperationCanceledException|E \_ anular|Gerada quando uma operação é anulada.|
|OutOfBoundsException|\_limites E|Gerada quando uma operação tenta acessar dados fora do intervalo válido.|
|OutOfMemoryException|E \_ OUTOFMEMORY|Gerada quando a memória para concluir a operação é insuficiente.|
|WrongThreadException|RPC \_ E \_ thread incorreto \_|Gerada quando um thread chama via um ponteiro de interface, que destina-se a um objeto proxy que não pertence ao apartment do thread.|

## <a name="hresult-and-message-properties"></a>Propriedades de HResult e de Message

Todas as exceções têm uma propriedade [HResult](platform-comexception-class.md#hresult) e uma propriedade [Message](platform-comexception-class.md#message) . A propriedade [Exception::HResult](platform-exception-class.md#hresult) obtém o valor HRESULT numérico subjacente da exceção. A propriedade [Exception::Message](platform-exception-class.md#message) obtém a cadeia de caracteres fornecida pelo sistema que descreve a exceção. No Windows 8, a mensagem está disponível apenas no depurador e é somente leitura. Isso significa que você não pode alterá-la ao gerar novamente a exceção. No Windows 8.1, você pode acessar a cadeia de caracteres da mensagem programaticamente e fornecer uma nova mensagem se a exceção for gerada novamente. As melhores informações da pilha de chamadas também estão disponíveis no depurador, incluindo pilhas de chamadas de método assíncrono.

### <a name="examples"></a>Exemplos

Este exemplo mostra como lançar uma exceção de Windows Runtime para operações síncronas:

[!code-cpp[cx_exceptions#01](codesnippet/CPP/exceptiontest/class1.cpp#01)]

O exemplo a seguir mostra como capturar a exceção.

[!code-cpp[cx_exceptions#02](codesnippet/CPP/exceptiontest/class1.cpp#02)]

Para capturar as exceções que são geradas durante uma operação assíncrona, use a classe Task e adicione uma continuação de tratamento de erros. A continuação do tratamento de erro realiza marshaling das exceções que são geradas em outros threads de volta para o thread chamador, de modo que você possa tratar todas as exceções potenciais em apenas um ponto no seu código. Para obter mais informações, veja [Programação assíncrona em C++](/windows/uwp/threading-async/asynchronous-programming-in-cpp-universal-windows-platform-apps).

## <a name="unhandlederrordetected-event"></a>Evento UnhandledErrorDetected

No Windows 8.1 você pode assinar o evento estático [Windows:: ApplicationModel:: Core:: CoreApplication:: UnhandledErrorDetected](/uwp/api/windows.applicationmodel.core.icoreapplicationunhandlederror.unhandlederrordetected) , que fornece acesso a erros sem tratamento que estão prestes a abrir o processo. Independentemente da origem do erro, ele chega a esse manipulador como um objeto [Windows::ApplicationModel::Core::UnhandledError](/uwp/api/windows.applicationmodel.core.unhandlederror) que é transmitido com os argumentos do evento. Quando você chama `Propagate` no objeto, ele cria e gera uma exceção `Platform::*Exception` do tipo correspondente ao código de erro. Nos blocos catch, você pode salvar o estado do usuário, se necessário, e permitir que o processo seja encerrado chamando **`throw`** , ou fazer algo para colocar o programa novamente em um estado conhecido. O exemplo a seguir mostra o padrão básico:

Em app. XAML. h:

```cpp
void OnUnhandledException(Platform::Object^ sender, Windows::ApplicationModel::Core::UnhandledErrorDetectedEventArgs^ e);
```

Em app. XAML. cpp:

```cpp
// Subscribe to the event, for example in the app class constructor:
Windows::ApplicationModel::Core::CoreApplication::UnhandledErrorDetected += ref new EventHandler<UnhandledErrorDetectedEventArgs^>(this, &App::OnUnhandledException);

// Event handler implementation:
void App::OnUnhandledException(Platform::Object^ sender, Windows::ApplicationModel::Core::UnhandledErrorDetectedEventArgs^ e)
{
    auto err = e->UnhandledError;

    if (!err->Handled) //Propagate has not been called on it yet.
{
    try
    {
        err->Propagate();
    }
    // Catch any specific exception types if you know how to handle them
    catch (AccessDeniedException^ ex)
    {
        // TODO: Log error and either take action to recover
        // or else re-throw exception to continue fail-fast
    }
}
```

### <a name="remarks"></a>Comentários

C++/CX não usa a **`finally`** cláusula.

## <a name="see-also"></a>Confira também

[Referência de linguagem do C++/CX](visual-c-language-reference-c-cx.md)<br/>
[Referência de namespaces](namespaces-reference-c-cx.md)
