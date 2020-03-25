---
title: Como ativar e usar um componente de Windows Runtime  com WRL
ms.date: 11/04/2016
ms.topic: reference
ms.assetid: 54828f02-6af3-45d1-b965-d0104442f8d5
ms.openlocfilehash: 7f49c1362bea12576df6039b9e9f0b455cb4fae4
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80213948"
---
# <a name="how-to-activate-and-use-a-windows-runtime-component-using-wrl"></a>Como ativar e usar um componente de Windows Runtime  com WRL

Este documento mostra como usar a WRL ( C++ biblioteca de modelos de Windows Runtime) para inicializar o Windows Runtime e como ativar e usar um componente de Windows Runtime.

Para usar um componente, você deve adquirir um ponteiro de interface para o tipo que é implementado pelo componente. E como a tecnologia subjacente da Windows Runtime é a Component Object Model (COM), você deve seguir as regras COM para manter uma instância do tipo. Por exemplo, você deve manter a *contagem de referência* que determina quando o tipo é excluído da memória.

Para simplificar o uso do Windows Runtime, Windows Runtime C++ biblioteca de modelos fornece o modelo de ponteiro inteligente, [ComPtr\<t >](comptr-class.md), que executa automaticamente a contagem de referência. Ao declarar uma variável, especifique `ComPtr<`*nome da interface*`>` *identificador*. Para acessar um membro de interface, aplique o operador de acesso de membro de seta (`->`) ao identificador.

> [!IMPORTANT]
> Ao chamar uma função de interface, sempre teste o valor de retorno HRESULT.

## <a name="activating-and-using-a-windows-runtime-component"></a>Ativando e usando um componente Windows Runtime

As etapas a seguir usam a interface `Windows::Foundation::IUriRuntimeClass` para demonstrar como criar uma fábrica de ativação para um componente Windows Runtime, criar uma instância desse componente e recuperar um valor de propriedade. Eles também mostram como inicializar o Windows Runtime. Veja a seguir o exemplo completo.

> [!IMPORTANT]
> Embora você normalmente use a Windows Runtime C++ biblioteca de modelos em um aplicativo plataforma universal do Windows (UWP), este exemplo usa um aplicativo de console para ilustração. Funções como `wprintf_s` não estão disponíveis em um aplicativo UWP. Para obter mais informações sobre os tipos e funções que você pode usar em um aplicativo UWP, consulte [funções CRT sem suporte em aplicativos plataforma universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md) e [Win32 e com para aplicativos UWP](/uwp/win32-and-com/win32-and-com-for-uwp-apps).

#### <a name="to-activate-and-use-a-windows-runtime-component"></a>Para ativar e usar um componente Windows Runtime

1. Incluir (`#include`) qualquer Windows Runtime necessário, Windows Runtime C++ biblioteca de modelos ou C++ cabeçalhos de biblioteca padrão.

   [!code-cpp[wrl-consume-component#2](../codesnippet/CPP/how-to-activate-and-use-a-windows-runtime-component-using-wrl_1.cpp)]

   Recomendamos que você utilize a diretiva `using namespace` em seu arquivo. cpp para tornar o código mais legível.

2. Inicialize o thread no qual o aplicativo é executado. Cada aplicativo deve inicializar seu thread e modelo de Threading. Este exemplo usa a classe [Microsoft:: WRL:: wrappers:: RoInitializeWrapper](roinitializewrapper-class.md) para inicializar a Windows Runtime e especifica [RO_INIT_MULTITHREADED](/windows/win32/api/roapi/ne-roapi-ro_init_type) como o modelo de Threading. A classe `RoInitializeWrapper` chama `Windows::Foundation::Initialize` na construção e `Windows::Foundation::Uninitialize` quando ela é destruída.

   [!code-cpp[wrl-consume-component#3](../codesnippet/CPP/how-to-activate-and-use-a-windows-runtime-component-using-wrl_2.cpp)]

   Na segunda instrução, o operador [RoInitializeWrapper:: HRESULT](roinitializewrapper-class.md#hresult) retorna o `HRESULT` da chamada para `Windows::Foundation::Initialize`.

3. Crie uma *fábrica de ativação* para a interface `ABI::Windows::Foundation::IUriRuntimeClassFactory`.

   [!code-cpp[wrl-consume-component#4](../codesnippet/CPP/how-to-activate-and-use-a-windows-runtime-component-using-wrl_3.cpp)]

   O Windows Runtime usa nomes totalmente qualificados para identificar tipos. O parâmetro `RuntimeClass_Windows_Foundation_Uri` é uma cadeia de caracteres fornecida pelo Windows Runtime e contém o nome de classe de tempo de execução necessário.

4. Inicialize uma variável [Microsoft:: WRL:: wrappers:: HString](hstring-class.md) que representa o URI `"https://www.microsoft.com"`.

   [!code-cpp[wrl-consume-component#6](../codesnippet/CPP/how-to-activate-and-use-a-windows-runtime-component-using-wrl_4.cpp)]

   No Windows Runtime, você não aloca memória para uma cadeia de caracteres que o Windows Runtime usará. Em vez disso, o Windows Runtime cria uma cópia da cadeia de caracteres em um buffer que ele mantém e usa para operações e, em seguida, retorna um identificador para o buffer que ele criou.

5. Use o método de fábrica `IUriRuntimeClassFactory::CreateUri` para criar um objeto `ABI::Windows::Foundation::IUriRuntimeClass`.

   [!code-cpp[wrl-consume-component#7](../codesnippet/CPP/how-to-activate-and-use-a-windows-runtime-component-using-wrl_5.cpp)]

6. Chame o método `IUriRuntimeClass::get_Domain` para recuperar o valor da propriedade `Domain`.

   [!code-cpp[wrl-consume-component#8](../codesnippet/CPP/how-to-activate-and-use-a-windows-runtime-component-using-wrl_6.cpp)]

7. Imprima o nome de domínio para o console e retorne. Todos os objetos `ComPtr` e RAII deixam o escopo e são liberados automaticamente.

   [!code-cpp[wrl-consume-component#9](../codesnippet/CPP/how-to-activate-and-use-a-windows-runtime-component-using-wrl_7.cpp)]

   A função [WindowsGetStringRawBuffer](/windows/win32/api/winstring/nf-winstring-windowsgetstringrawbuffer) recupera a forma Unicode subjacente da cadeia de caracteres do URI.

Aqui está o exemplo completo:

[!code-cpp[wrl-consume-component#1](../codesnippet/CPP/how-to-activate-and-use-a-windows-runtime-component-using-wrl_8.cpp)]

## <a name="compiling-the-code"></a>Compilando o Código

Para compilar o código, copie-o e cole-o em um projeto do Visual Studio ou cole-o em um arquivo chamado `wrl-consume-component.cpp` e, em seguida, execute o comando a seguir em uma janela de prompt de comando do Visual Studio.

`cl.exe wrl-consume-component.cpp runtimeobject.lib`

## <a name="see-also"></a>Confira também

[WRL (Biblioteca de Modelos C++ do Tempo de Execução do Windows)](windows-runtime-cpp-template-library-wrl.md)
