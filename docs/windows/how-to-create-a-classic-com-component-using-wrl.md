---
title: 'Como: criar um componente COM clássico com WRL | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
dev_langs:
- C++
ms.assetid: 5efe7690-90d5-4c3c-9e53-11a14cefcb19
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 3844c0ad304c1ebd18a707ca1821b72b60e92707
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43198013"
---
# <a name="how-to-create-a-classic-com-component-using-wrl"></a>Como criar um componente COM clássico com WRL

Você pode usar a biblioteca de modelos do Windows em tempo de execução C++ (WRL) para criar componentes COM clássicos básicos para uso em aplicativos da área de trabalho, além de usá-lo para aplicativos da plataforma Universal do Windows (UWP). Para a criação de componentes COM, a biblioteca de modelos C++ do Windows Runtime podem exigir menos código do que o ATL. Para obter informações sobre o subconjunto COM a biblioteca de modelos C++ do Windows Runtime oferece suporte, consulte [biblioteca de modelos em C++ Windows Runtime (WRL)](../windows/windows-runtime-cpp-template-library-wrl.md).

Este documento mostra como usar a biblioteca de modelos C++ do Windows Runtime para criar um componente básico do COM. Embora você possa usar o mecanismo de implantação que melhor atenda às suas necessidades, este documento também mostra uma maneira básica de registrar e consumir o componente COM de um aplicativo da área de trabalho.

### <a name="to-use-the-windows-runtime-c-template-library-to-create-a-basic-classic-com-component"></a>Usar a biblioteca de modelos C++ do Windows Runtime para criar um componente básico do COM clássico

1. No Visual Studio, crie uma **solução em branco** projeto. Nomeie o projeto, por exemplo, `WRLClassicCOM`.

2. Adicionar um **projeto Win32** à solução. Nomeie o projeto, por exemplo, `CalculatorComponent`. Sobre o **configurações do aplicativo** guia, selecione **DLL**.

3. Adicionar um **arquivo Midl (. idl)** arquivo ao projeto. Nomeie o arquivo, por exemplo, `CalculatorComponent.idl`.

4. Adicione este código ao CalculatorComponent.idl:

   [!code-cpp[wrl-classic-com-component#1](../windows/codesnippet/CPP/how-to-create-a-classic-com-component-using-wrl_1.idl)]

5. No CalculatorComponent.cpp, defina o `CalculatorComponent` classe. O `CalculatorComponent` herda [Microsoft::WRL::RuntimeClass](../windows/runtimeclass-class.md). [Microsoft::WRL::RuntimeClassFlags\<ClassicCom >](../windows/runtimeclassflags-structure.md) Especifica que a classe deriva [IUnknown](/windows/desktop/api/unknwn/nn-unknwn-iunknown) e não [IInspectable](https://msdn.microsoft.com/library/br205821\(v=vs.85\).aspx). (`IInspectable` está disponível apenas para componentes de aplicativo de tempo de execução do Windows.) `CoCreatableClass` cria uma fábrica para a classe que pode ser usada com funções como [CoCreateInstance](/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance).

   [!code-cpp[wrl-classic-com-component#2](../windows/codesnippet/CPP/how-to-create-a-classic-com-component-using-wrl_2.cpp)]

6. Use o seguinte código para substituir o código em `dllmain.cpp`. Esse arquivo define as funções de exportação DLL. Essas funções usam a [Microsoft::WRL::Module](../windows/module-class.md) classe para gerenciar as fábricas de classes para o módulo.

   [!code-cpp[wrl-classic-com-component#3](../windows/codesnippet/CPP/how-to-create-a-classic-com-component-using-wrl_3.cpp)]

7. Adicionar um **arquivo de definição de módulo (. def)** arquivo ao projeto. Nomeie o arquivo, por exemplo, `CalculatorComponent.def`. Esse arquivo fornece o vinculador os nomes das funções a serem exportados.

8. Adicione este código ao CalculatorComponent.def:

    ```
    LIBRARY

    EXPORTS
        DllGetActivationFactory PRIVATE
        DllGetClassObject       PRIVATE
        DllCanUnloadNow         PRIVATE
    ```

9. Adicione runtimeobject à linha do vinculador. Para saber como, consulte [. Arquivos de lib como entrada de vinculador](../build/reference/dot-lib-files-as-linker-input.md).

### <a name="to-consume-the-com-component-from-a-desktop-app"></a>Para consumir o componente COM de um aplicativo da área de trabalho

1. Registre o componente COM o registro do Windows. Para fazer isso, crie um arquivo de entradas do registro, nomeie- `RegScript.reg`e adicione o seguinte texto. Substitua  *\<caminho da dll >* com o caminho da DLL — por exemplo, `C:\temp\WRLClassicCOM\Debug\CalculatorComponent.dll`.

    ```
    Windows Registry Editor Version 5.00

    [HKEY_CLASSES_ROOT\Wow6432Node\CLSID\{E68F5EDD-6257-4E72-A10B-4067ED8E85F2}]
    @="CalculatorComponent Class"

    [HKEY_CLASSES_ROOT\Wow6432Node\CLSID\{E68F5EDD-6257-4E72-A10B-4067ED8E85F2}\InprocServer32]
    @="<dll-path>"
    "ThreadingModel"="Apartment"

    [HKEY_CLASSES_ROOT\Wow6432Node\CLSID\{E68F5EDD-6257-4E72-A10B-4067ED8E85F2}\Programmable]

    [HKEY_CLASSES_ROOT\Wow6432Node\CLSID\{E68F5EDD-6257-4E72-A10B-4067ED8E85F2}\TypeLib]
    @="{9D3E6826-CB8E-4D86-8B14-89F0D7EFCD01}"

    [HKEY_CLASSES_ROOT\Wow6432Node\CLSID\{E68F5EDD-6257-4E72-A10B-4067ED8E85F2}\Version]
    @="1.0"
    ```

2. Execute RegScript.reg ou adicioná-lo ao seu projeto **evento pós-compilação**. Para obter mais informações, consulte [pré-build/evento pós-build linha de comando caixa de diálogo evento](/visualstudio/ide/reference/pre-build-event-post-build-event-command-line-dialog-box).

3. Adicionar um **aplicativo do Console Win32** projeto à solução. Nomeie o projeto, por exemplo, `Calculator`.

4. Use este código para substituir o conteúdo de `Calculator.cpp`:

   [!code-cpp[wrl-classic-com-component#6](../windows/codesnippet/CPP/how-to-create-a-classic-com-component-using-wrl_6.cpp)]

## <a name="robust-programming"></a>Programação robusta

Este documento usa funções padrão de COM para demonstrar que você pode usar a biblioteca de modelos C++ do Windows Runtime para criar um componente COM e torná-lo disponível para qualquer tecnologia habilitado para COM. Você também pode usar tipos de biblioteca de modelos de C++ de tempo de execução do Windows, como [Microsoft::WRL::ComPtr](../windows/comptr-class.md) em seu aplicativo da área de trabalho para gerenciar o tempo de vida de COM e outros objetos. O código a seguir usa a biblioteca de modelos de C++ de tempo de execução do Windows para gerenciar a vida útil do `ICalculatorComponent` ponteiro. O `CoInitializeWrapper` classe é um wrapper RAII que garante que a biblioteca COM é liberada e também garante que o tempo de vida da biblioteca COM dura mais do que o `ComPtr` objeto de ponteiro inteligente.

[!code-cpp[wrl-classic-com-component#7](../windows/codesnippet/CPP/how-to-create-a-classic-com-component-using-wrl_7.cpp)]

## <a name="see-also"></a>Consulte também

[WRL (Biblioteca de Modelos C++ do Tempo de Execução do Windows)](../windows/windows-runtime-cpp-template-library-wrl.md)