---
title: Como criar um componente COM clássico com WRL
description: Use a Windows Runtime WRL (biblioteca de modelos C++) para criar componentes COM clássicos básicos para uso em aplicativos da área de trabalho.
ms.date: 10/23/2020
ms.topic: reference
ms.openlocfilehash: 417c2e4635b380717662fa0762062f0228659de4
ms.sourcegitcommit: bf54b407169900bb668c85a67b31dbc0f069fe65
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2020
ms.locfileid: "92497190"
---
# <a name="how-to-create-a-classic-com-component-using-wrl"></a>Como criar um componente COM clássico com WRL

Você pode usar a Windows Runtime WRL (biblioteca de modelos C++) para criar componentes COM clássicos básicos para uso em aplicativos de desktop, além de usá-los para aplicativos da UWP (Plataforma Universal do Windows). Para a criação de componentes COM, a Windows Runtime biblioteca de modelos C++ pode exigir menos código do que a ATL. Para obter informações sobre o subconjunto de COM com suporte da biblioteca de modelos do Windows Runtime C++, consulte [Windows Runtime C++ Template Library (WRL)](windows-runtime-cpp-template-library-wrl.md).

Este documento mostra como usar a biblioteca de modelos do Windows Runtime C++ para criar um componente COM básico. Embora você possa usar o mecanismo de implantação que melhor atenda às suas necessidades, este documento também mostra uma maneira básica de registrar e consumir o componente COM de um aplicativo de desktop.

### <a name="to-use-the-windows-runtime-c-template-library-to-create-a-basic-classic-com-component"></a>Para usar a biblioteca de modelos do Windows Runtime C++ para criar um componente COM clássico básico

1. No Visual Studio, crie um projeto de **solução em branco** . Nomeie o projeto, por exemplo, `WRLClassicCOM` .

2. Adicione um **projeto Win32** à solução. Nomeie o projeto, por exemplo, `CalculatorComponent` . Na guia **configurações do aplicativo** , selecione **dll**.

3. Adicione um arquivo **MIDL (. idl)** ao projeto. Nomeie o arquivo, por exemplo, `CalculatorComponent.idl` .

4. Adicione este código a CalculatorComponent. idl:

   [!code-cpp[wrl-classic-com-component#1](../codesnippet/CPP/how-to-create-a-classic-com-component-using-wrl_1.idl)]

5. Em CalculatorComponent. cpp, defina a `CalculatorComponent` classe. A `CalculatorComponent` classe herda de [Microsoft:: WRL:: RuntimeClass](runtimeclass-class.md). [Microsoft:: WRL:: RuntimeClassFlags \<ClassicCom> ](runtimeclassflags-structure.md) Especifica que a classe deriva de [IUnknown](/windows/win32/api/unknwn/nn-unknwn-iunknown) e não [IInspectable](/windows/win32/api/inspectable/nn-inspectable-iinspectable). ( `IInspectable` está disponível apenas para Windows Runtime componentes de aplicativo.) `CoCreatableClass` cria uma fábrica para a classe que pode ser usada com funções como [CoCreateInstance](/windows/win32/api/combaseapi/nf-combaseapi-cocreateinstance).

   [!code-cpp[wrl-classic-com-component#2](../codesnippet/CPP/how-to-create-a-classic-com-component-using-wrl_2.cpp)]

6. Use o código a seguir para substituir o código em `dllmain.cpp` . Esse arquivo define as funções de exportação de DLL. Essas funções usam a classe [Microsoft:: WRL:: module](module-class.md) para gerenciar as fábricas de classes para o módulo.

   [!code-cpp[wrl-classic-com-component#3](../codesnippet/CPP/how-to-create-a-classic-com-component-using-wrl_3.cpp)]

7. Adicione um arquivo de **definição de módulo (. def)** ao projeto. Nomeie o arquivo, por exemplo, `CalculatorComponent.def` . Esse arquivo fornece ao vinculador os nomes das funções a serem exportadas. Abra a caixa de diálogo **páginas** de propriedades do seu projeto e, em seguida, em **Configuration Properties**  >  entrada do**vinculador**de propriedades de configuração  >  **Input**, defina a propriedade do **arquivo de definição de módulo** para o arquivo def.

8. Adicione este código a CalculatorComponent. def:

    ```
    LIBRARY

    EXPORTS
        DllGetActivationFactory PRIVATE
        DllGetClassObject       PRIVATE
        DllCanUnloadNow         PRIVATE
    ```

9. Adicione runtimeobject. lib à linha do vinculador. Para saber como, consulte [ `.Lib` arquivos como entrada de vinculador](../../build/reference/dot-lib-files-as-linker-input.md).

### <a name="to-consume-the-com-component-from-a-desktop-app"></a>Para consumir o componente COM de um aplicativo de área de trabalho

1. Registre o componente COM com o registro do Windows. Para fazer isso, crie um arquivo de entradas de registro, nomeie- `RegScript.reg` o e adicione o texto a seguir. Substitua *\<dll-path>* pelo caminho da sua DLL — por exemplo, `C:\temp\WRLClassicCOM\Debug\CalculatorComponent.dll` .

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

2. Execute RegScript. reg ou adicione-o ao evento de **pós-Build**do seu projeto. Para obter mais informações, consulte [caixa de diálogo linha de comando de evento de pré-compilação evento/pós-](/visualstudio/ide/reference/pre-build-event-post-build-event-command-line-dialog-box)compilação.

3. Adicione um projeto de **aplicativo do console do Win32** à solução. Nomeie o projeto, por exemplo, `Calculator` .

4. Use este código para substituir o conteúdo de `Calculator.cpp` :

   [!code-cpp[wrl-classic-com-component#6](../codesnippet/CPP/how-to-create-a-classic-com-component-using-wrl_6.cpp)]

## <a name="robust-programming"></a>Programação robusta

Este documento usa funções COM padrão para demonstrar que você pode usar a biblioteca de modelos do Windows Runtime C++ para criar um componente COM e disponibilizá-lo para qualquer tecnologia habilitada para COM. Você também pode usar Windows Runtime tipos de biblioteca de modelos C++, como [Microsoft:: WRL:: ComPtr](comptr-class.md) em seu aplicativo de área de trabalho para gerenciar o tempo de vida de com e outros objetos. O código a seguir usa a Windows Runtime biblioteca de modelos C++ para gerenciar o tempo de vida do `ICalculatorComponent` ponteiro. A `CoInitializeWrapper` classe é um wrapper RAII que garante que a biblioteca com seja liberada e também garante que o tempo de vida da biblioteca com fique inativo no `ComPtr` objeto de ponteiro inteligente.

[!code-cpp[wrl-classic-com-component#7](../codesnippet/CPP/how-to-create-a-classic-com-component-using-wrl_7.cpp)]

## <a name="see-also"></a>Confira também

[Biblioteca de Modelos C++ do Windows Runtime  (WRL)](windows-runtime-cpp-template-library-wrl.md)
