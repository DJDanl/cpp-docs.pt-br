---
title: "Como: criar um componente COM clássico com WRL | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs: C++
ms.assetid: 5efe7690-90d5-4c3c-9e53-11a14cefcb19
caps.latest.revision: "6"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 04b84a5deedc5ef112507f4e0f8ccb29af418c28
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="how-to-create-a-classic-com-component-using-wrl"></a>Como criar um componente COM clássico com WRL
Você pode usar a biblioteca de modelo (WRL) do Windows em tempo de execução C++ para criar componentes básicos do COM clássico para uso em aplicativos de área de trabalho, além disso, para usá-lo para [!INCLUDE[win8_appstore_long](../build/reference/includes/win8_appstore_long_md.md)] aplicativos. Para a criação de componentes COM, a biblioteca de modelos do Windows em tempo de execução C++ podem exigir menos código do que o ATL. Para obter informações sobre o subconjunto COM a biblioteca de modelos de C++ do Windows Runtime oferece suporte, consulte [biblioteca de modelo em C++ Windows Runtime (WRL)](../windows/windows-runtime-cpp-template-library-wrl.md).  
  
 Este documento mostra como usar a biblioteca de modelos do Windows em tempo de execução C++ para criar um componente básico do COM. Embora você possa usar o mecanismo de implantação que melhor atenda às suas necessidades, este documento também mostra uma maneira simples de registrar e consumir o componente COM de um aplicativo de área de trabalho.  
  
### <a name="to-use-the-windows-runtime-c-template-library-to-create-a-basic-classic-com-component"></a>Para usar a biblioteca de modelos do Windows em tempo de execução C++ para criar um componente COM clássico básico  
  
1.  No Visual Studio, crie um **solução em branco** projeto. Nome do projeto, por exemplo, `WRLClassicCOM`.  
  
2.  Adicionar um **projeto Win32** à solução. Nome do projeto, por exemplo, `CalculatorComponent`. Sobre o **configurações do aplicativo** guia, selecione **DLL**.  
  
3.  Adicionar um **arquivo Midl (. idl)** arquivo ao projeto. Nomeie o arquivo, por exemplo, `CalculatorComponent.idl`.  
  
4.  Adicione este código para CalculatorComponent.idl:  
  
     [!code-cpp[wrl-classic-com-component#1](../windows/codesnippet/CPP/how-to-create-a-classic-com-component-using-wrl_1.idl)]  
  
5.  No CalculatorComponent.cpp, defina o `CalculatorComponent` classe. O `CalculatorComponent` classe herda de [Microsoft::WRL::RuntimeClass](../windows/runtimeclass-class.md). [Microsoft::WRL::RuntimeClassFlags\<ClassicCom >](../windows/runtimeclassflags-structure.md) Especifica que a classe derivada de [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509\(v=vs.85\).aspx) e não [IInspectable](http://msdn.microsoft.com/library/br205821\(v=vs.85\).aspx). (`IInspectable` está disponível somente para [!INCLUDE[win8_appstore_short](../windows/includes/win8_appstore_short_md.md)] componentes do aplicativo.) `CoCreatableClass` cria uma fábrica para a classe que pode ser usada com funções como [CoCreateInstance](http://msdn.microsoft.com/library/windows/desktop/ms686615\(v=vs.85\).aspx).  
  
     [!code-cpp[wrl-classic-com-component#2](../windows/codesnippet/CPP/how-to-create-a-classic-com-component-using-wrl_2.cpp)]  
  
6.  Use o código a seguir para substituir o código em dllmain.cpp. Esse arquivo define as funções de exportação DLL. Essas funções usam o [Microsoft::WRL::Module](../windows/module-class.md) classe para gerenciar as fábricas de classe para o módulo.  
  
     [!code-cpp[wrl-classic-com-component#3](../windows/codesnippet/CPP/how-to-create-a-classic-com-component-using-wrl_3.cpp)]  
  
7.  Adicionar um **o arquivo de definição de módulo (. def)** arquivo ao projeto. Nomeie o arquivo, por exemplo, `CalculatorComponent.def`. Esse arquivo fornece o vinculador os nomes das funções a serem exportados.  
  
8.  Adicione este código para CalculatorComponent.def:  
  
    ```
    LIBRARY

    EXPORTS
        DllGetActivationFactory PRIVATE
        DllGetClassObject       PRIVATE
        DllCanUnloadNow         PRIVATE  
    ```

9. Adicione runtimeobject.lib à linha de vinculador. Para saber mais, consulte [. Lib arquivos como entrada de vinculador](../build/reference/dot-lib-files-as-linker-input.md).  
  
### <a name="to-consume-the-com-component-from-a-desktop-app"></a>Para consumir o componente COM de um aplicativo de área de trabalho  
  
1.  Registre o componente COM o registro do Windows. Para fazer isso, crie um arquivo de entradas do registro, nomeie-o `RegScript.reg`e adicione o seguinte texto. Substituir  *\<caminho de dll >* com o caminho da sua DLL — por exemplo, `C:\\temp\\WRLClassicCOM\\Debug\\CalculatorComponent.dll`.  
  
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
  
2.  Execute RegScript.reg ou adicioná-lo ao seu projeto **evento de pós-compilação**. Para obter mais informações, consulte [pré-compilação evento/pós-build linha de comando caixa de diálogo evento](/visualstudio/ide/reference/pre-build-event-post-build-event-command-line-dialog-box).  
  
3.  Adicionar um **aplicativo do Console Win32** projeto à solução. Nome do projeto, por exemplo, `Calculator`.  
  
4.  Use este código para substituir o conteúdo de Calculator.cpp:  
  
     [!code-cpp[wrl-classic-com-component#6](../windows/codesnippet/CPP/how-to-create-a-classic-com-component-using-wrl_6.cpp)]  
  
## <a name="robust-programming"></a>Programação robusta  
 Este documento usa funções COM padrão para demonstrar que você pode usar a biblioteca de modelos do Windows em tempo de execução C++ para criar um componente COM e disponibilizá-la para qualquer tecnologia habilitado COM. Você também pode usar tipos de biblioteca de modelos C++ do Windows Runtime, como [Microsoft::WRL::ComPtr](../windows/comptr-class.md) em seu aplicativo de área de trabalho para gerenciar o tempo de vida de COM e outros objetos. O código a seguir usa a biblioteca de modelos do Windows em tempo de execução C++ para gerenciar o tempo de vida de `ICalculatorComponent` ponteiro. O `CoInitializeWrapper` classe é um wrapper RAII que garante que a biblioteca COM é liberada e também garante que o tempo de vida da biblioteca COM superam o `ComPtr` objeto ponteiro inteligente.  
  
 [!code-cpp[wrl-classic-com-component#7](../windows/codesnippet/CPP/how-to-create-a-classic-com-component-using-wrl_7.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [WRL (Biblioteca de Modelos C++ do Tempo de Execução do Windows)](../windows/windows-runtime-cpp-template-library-wrl.md)