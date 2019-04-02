---
title: 'Como: Ativar e usar um componente de tempo de execução do Windows usando a WRL'
ms.date: 11/04/2016
ms.topic: reference
ms.assetid: 54828f02-6af3-45d1-b965-d0104442f8d5
ms.openlocfilehash: ccc64769ca319e8aba141ce95a00eb876cc051f3
ms.sourcegitcommit: 5cecccba0a96c1b4ccea1f7a1cfd91f259cc5bde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/01/2019
ms.locfileid: "58783793"
---
# <a name="how-to-activate-and-use-a-windows-runtime-component-using-wrl"></a>Como: Ativar e usar um componente de tempo de execução do Windows usando a WRL

Este documento mostra como usar a biblioteca de modelos do Windows em tempo de execução C++ (WRL) para inicializar o tempo de execução do Windows e como ativar e usar um componente de tempo de execução do Windows.

Para usar um componente, você deve adquirir um ponteiro de interface para o tipo que é implementado pelo componente. E como a tecnologia subjacente do tempo de execução do Windows é o modelo de objeto de componente (COM), você deve seguir as regras de COM para manter uma instância do tipo. Por exemplo, você deve manter o *contagem de referência* que determina quando o tipo é excluído da memória.

Para simplificar o uso do Windows Runtime, biblioteca de modelos de C++ de tempo de execução do Windows fornece o modelo de ponteiro inteligente [ComPtr\<T >](comptr-class.md), que executa automaticamente a contagem de referência. Quando você declara uma variável, especifique `ComPtr<` *nome da interface* `>` *identificador*. Para acessar um membro de interface, aplicar o operador de acesso de membro de seta (`->`) para o identificador.

> [!IMPORTANT]
> Quando você chama uma função de interface, sempre teste o valor de retorno de HRESULT.

## <a name="activating-and-using-a-windows-runtime-component"></a>Ativando e usando um componente de tempo de execução do Windows

As seguintes etapas usam o `Windows::Foundation::IUriRuntimeClass` interface para demonstrar como criar um alocador de ativação para um componente de tempo de execução do Windows, crie uma instância desse componente e recuperar um valor da propriedade. Eles também mostram como inicializar o tempo de execução do Windows. Segue o exemplo completo.

> [!IMPORTANT]
> Embora você normalmente usa a biblioteca de modelos de C++ de tempo de execução do Windows em um aplicativo da plataforma Universal do Windows (UWP), este exemplo usa um aplicativo de console para fins ilustrativos. As funções, como `wprintf_s` não estão disponíveis de um aplicativo UWP. Para obter mais informações sobre os tipos e funções que você pode usar em um aplicativo UWP, consulte [funções de CRT sem suporte em aplicativos da plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md) e [Win32 e COM para aplicativos UWP](/uwp/win32-and-com/win32-and-com-for-uwp-apps).

#### <a name="to-activate-and-use-a-windows-runtime-component"></a>Para ativar e usar um componente de tempo de execução do Windows

1. Incluir (`#include`) todas as necessárias em tempo de execução do Windows, biblioteca de modelos de C++ de tempo de execução do Windows ou cabeçalhos de biblioteca padrão C++.

   [!code-cpp[wrl-consume-component#2](../codesnippet/CPP/how-to-activate-and-use-a-windows-runtime-component-using-wrl_1.cpp)]

   É recomendável que você utilize o `using namespace` diretiva em seu arquivo. cpp para tornar o código mais legível.

2. Inicialize o thread no qual o aplicativo é executado. Cada aplicativo deve inicializar seu thread e o modelo de threading. Este exemplo usa o [Microsoft::WRL::Wrappers::RoInitializeWrapper](roinitializewrapper-class.md) de classe para inicializar o tempo de execução do Windows e especifica [RO_INIT_MULTITHREADED](/windows/desktop/api/roapi/ne-roapi-ro_init_type) como o modelo de threading. O `RoInitializeWrapper` chamado pela classe `Windows::Foundation::Initialize` durante a construção, e `Windows::Foundation::Uninitialize` quando ele é destruído.

   [!code-cpp[wrl-consume-component#3](../codesnippet/CPP/how-to-activate-and-use-a-windows-runtime-component-using-wrl_2.cpp)]

   Na segunda instrução, o [RoInitializeWrapper::HRESULT](roinitializewrapper-class.md#hresult) operador retorna o `HRESULT` da chamada para `Windows::Foundation::Initialize`.

3. Criar uma *alocador de ativação* para o `ABI::Windows::Foundation::IUriRuntimeClassFactory` interface.

   [!code-cpp[wrl-consume-component#4](../codesnippet/CPP/how-to-activate-and-use-a-windows-runtime-component-using-wrl_3.cpp)]

   O tempo de execução do Windows usa nomes totalmente qualificados para identificar tipos. O `RuntimeClass_Windows_Foundation_Uri` parâmetro é uma cadeia de caracteres que é fornecida pelo tempo de execução do Windows e contém o nome de classe de tempo de execução necessários.

4. Inicializar uma [Microsoft::WRL::Wrappers::HString](hstring-class.md) variável que representa o URI `"http://www.microsoft.com"`.

   [!code-cpp[wrl-consume-component#6](../codesnippet/CPP/how-to-activate-and-use-a-windows-runtime-component-using-wrl_4.cpp)]

   No tempo de execução do Windows, você não alocar memória para uma cadeia de caracteres que usará o tempo de execução do Windows. Em vez disso, o tempo de execução do Windows cria uma cópia de sua cadeia de caracteres em um buffer que mantém e usa para operações e, em seguida, retorna um identificador para o buffer que ele criou.

5. Use o `IUriRuntimeClassFactory::CreateUri` método de fábrica para criar um `ABI::Windows::Foundation::IUriRuntimeClass` objeto.

   [!code-cpp[wrl-consume-component#7](../codesnippet/CPP/how-to-activate-and-use-a-windows-runtime-component-using-wrl_5.cpp)]

6. Chame o `IUriRuntimeClass::get_Domain` método para recuperar o valor da `Domain` propriedade.

   [!code-cpp[wrl-consume-component#8](../codesnippet/CPP/how-to-activate-and-use-a-windows-runtime-component-using-wrl_6.cpp)]

7. Imprimir o nome de domínio para o console e retornar. Todos os `ComPtr` e há objetos RAII deixar o escopo e são liberados automaticamente.

   [!code-cpp[wrl-consume-component#9](../codesnippet/CPP/how-to-activate-and-use-a-windows-runtime-component-using-wrl_7.cpp)]

   O [WindowsGetStringRawBuffer](/windows/desktop/api/winstring/nf-winstring-windowsgetstringrawbuffer) função recupera o formulário de Unicode subjacente da cadeia de caracteres do URI.

Aqui está o exemplo completo:

[!code-cpp[wrl-consume-component#1](../codesnippet/CPP/how-to-activate-and-use-a-windows-runtime-component-using-wrl_8.cpp)]

## <a name="compiling-the-code"></a>Compilando o código

Para compilar o código, copiá-lo e, em seguida, cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `wrl-consume-component.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.

`cl.exe wrl-consume-component.cpp runtimeobject.lib`

## <a name="see-also"></a>Consulte também

[WRL (Biblioteca de Modelos C++ do Tempo de Execução do Windows)](windows-runtime-cpp-template-library-wrl.md)