---
title: 'Como: ativar e usar um componente de tempo de execução do Windows com WRL | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-windows
ms.tgt_pltfrm: ''
ms.topic: reference
dev_langs:
- C++
ms.assetid: 54828f02-6af3-45d1-b965-d0104442f8d5
caps.latest.revision: ''
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 5c430ca0dd63c4cbe46986147617ccbd752597ab
ms.sourcegitcommit: 1d11412c8f5e6ddf4edded89e0ef5097cc89f812
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/22/2018
---
# <a name="how-to-activate-and-use-a-windows-runtime-component-using-wrl"></a>Como ativar e usar um componente de Windows Runtime  com WRL
Este documento mostra como usar a biblioteca de modelo (WRL) do Windows em tempo de execução C++ para inicializar o tempo de execução do Windows e como ativar e usar um componente de tempo de execução do Windows.  
  
 Para usar um componente, você deve adquirir um ponteiro de interface para o tipo que é implementado pelo componente. E como a tecnologia subjacente do tempo de execução do Windows é o modelo de objeto de componente (COM), você deve seguir as regras de COM para manter uma instância do tipo. Por exemplo, você deve manter o *contagem de referência* que determina quando o tipo é excluído da memória.  
  
 Para simplificar o uso do Windows Runtime, biblioteca de modelos C++ do Windows Runtime fornece o modelo de ponteiro inteligente, [ComPtr\<T >](../windows/comptr-class.md), que executa automaticamente a contagem de referência. Quando você declara uma variável, especifique `ComPtr<` *-nome da interface* `>` *identificador*. Para acessar um membro de interface, aplique o operador de acesso de membro de seta (`->`) para o identificador.  
  
> [!IMPORTANT]
>  Quando você chama uma função de interface, sempre teste o `HRESULT` valor de retorno.  
  
## <a name="activating-and-using-a-windows-runtime-component"></a>Ativar e usar um componente de tempo de execução do Windows  
 As seguintes etapas usam o `Windows::Foundation::IUriRuntimeClass` interface para demonstrar como criar um alocador de ativação para um componente de tempo de execução do Windows, crie uma instância do componente e recuperar um valor de propriedade. Elas também mostram como inicializar o tempo de execução do Windows. O exemplo completo segue.  
  
> [!IMPORTANT]
>  Embora você costumar usar a biblioteca de modelos de C++ de tempo de execução do Windows em um aplicativo do Windows UWP (plataforma Universal), este exemplo usa um aplicativo de console para fins ilustrativos. Funções como `wprintf_s` não estão disponíveis em um aplicativo UWP. Para obter mais informações sobre os tipos e funções que você pode usar em um aplicativo UWP, consulte [funções de CRT sem suporte em aplicativos de plataforma Universal do Windows](../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md) e [Win32 e COM para aplicativos UWP](/uwp/win32-and-com/win32-and-com-for-uwp-apps).  
  
#### <a name="to-activate-and-use-a-windows-runtime-component"></a>Para ativar e usar um componente de tempo de execução do Windows  
  
1.  Incluir (`#include`) os necessários do Windows Runtime, biblioteca de modelos C++ do Windows Runtime ou cabeçalhos de biblioteca padrão C++.  
  
     [!code-cpp[wrl-consume-component#2](../windows/codesnippet/CPP/how-to-activate-and-use-a-windows-runtime-component-using-wrl_1.cpp)]  
  
     É recomendável que você utiliza o `using namespace` diretiva no arquivo. cpp para tornar o código mais legível.  
  
2.  Inicialize o thread no qual o aplicativo é executado. Cada aplicativo deve inicializar o thread e o modelo de threading. Este exemplo usa o [Microsoft::WRL::Wrappers::RoInitializeWrapper](../windows/roinitializewrapper-class.md) de classe para inicializar o tempo de execução do Windows e especifica [RO_INIT_MULTITHREADED](http://msdn.microsoft.com/library/windows/apps/br224661.aspx) como o modelo de threading. O `RoInitializeWrapper` classe chamadas `Windows::Foundation::Initialize` na construção, e `Windows::Foundation::Uninitialize` quando ele é destruído.  
  
     [!code-cpp[wrl-consume-component#3](../windows/codesnippet/CPP/how-to-activate-and-use-a-windows-runtime-component-using-wrl_2.cpp)]  
  
     Na segunda instrução, o [RoInitializeWrapper::HRESULT](../windows/roinitializewrapper-hresult-parens-operator.md) operador retorna o `HRESULT` da chamada para `Windows::Foundation::Initialize`.  
  
3.  Criar um *alocador de ativação* para o `ABI::Windows::Foundation::IUriRuntimeClassFactory` interface.  
  
     [!code-cpp[wrl-consume-component#4](../windows/codesnippet/CPP/how-to-activate-and-use-a-windows-runtime-component-using-wrl_3.cpp)]  
  
     O tempo de execução do Windows usa nomes totalmente qualificados para identificar tipos. O `RuntimeClass_Windows_Foundation_Uri` parâmetro é uma cadeia de caracteres que é fornecida pelo Windows Runtime e contém o nome de classe de tempo de execução necessários.  
  
4.  Inicializar um [Microsoft::WRL::Wrappers::HString](../windows/hstring-class.md) variável que representa o URI `"http://www.microsoft.com"`.  
  
     [!code-cpp[wrl-consume-component#6](../windows/codesnippet/CPP/how-to-activate-and-use-a-windows-runtime-component-using-wrl_4.cpp)]  
  
     Em tempo de execução do Windows, você não alocar memória para uma cadeia de caracteres que será usado o tempo de execução do Windows. Em vez disso, o tempo de execução do Windows cria uma cópia de sua cadeia de caracteres em um buffer que mantém e usa para operações e, em seguida, retorna um identificador para o buffer que ele criou.  
  
5.  Use o `IUriRuntimeClassFactory::CreateUri` método de fábrica para criar um `ABI::Windows::Foundation::IUriRuntimeClass` objeto.  
  
     [!code-cpp[wrl-consume-component#7](../windows/codesnippet/CPP/how-to-activate-and-use-a-windows-runtime-component-using-wrl_5.cpp)]  
  
6.  Chamar o `IUriRuntimeClass::get_Domain` método para recuperar o valor de `Domain` propriedade.  
  
     [!code-cpp[wrl-consume-component#8](../windows/codesnippet/CPP/how-to-activate-and-use-a-windows-runtime-component-using-wrl_6.cpp)]  
  
7.  O nome de domínio para o console de impressão e retornar. Todos os `ComPtr` e objetos RAII deixam o escopo e são liberados automaticamente.  
  
     [!code-cpp[wrl-consume-component#9](../windows/codesnippet/CPP/how-to-activate-and-use-a-windows-runtime-component-using-wrl_7.cpp)]  
  
     O [WindowsGetStringRawBuffer](http://msdn.microsoft.com/library/windows/apps/br224636.aspx) função recupera o formulário Unicode subjacente da cadeia de caracteres do URI.  
  
 Aqui está o exemplo completo:  
  
 [!code-cpp[wrl-consume-component#1](../windows/codesnippet/CPP/how-to-activate-and-use-a-windows-runtime-component-using-wrl_8.cpp)]  
  
## <a name="compiling-the-code"></a>Compilando o código  
 Para compilar o código, copiá-lo e, em seguida, cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `wrl-consume-component.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.  
  
 **cl.exe wrl-consume-component.cpp runtimeobject.lib**  
  
## <a name="see-also"></a>Consulte também  
 [WRL (Biblioteca de Modelos C++ do Tempo de Execução do Windows)](../windows/windows-runtime-cpp-template-library-wrl.md)