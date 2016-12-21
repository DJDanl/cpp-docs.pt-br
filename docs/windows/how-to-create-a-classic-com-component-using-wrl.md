---
title: "Como criar um componente COM cl&#225;ssico com WRL | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
dev_langs: 
  - "C++"
ms.assetid: 5efe7690-90d5-4c3c-9e53-11a14cefcb19
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como criar um componente COM cl&#225;ssico com WRL
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode usar o [!INCLUDE[cppwrl](../windows/includes/cppwrl_md.md)] ([!INCLUDE[cppwrl_short](../windows/includes/cppwrl_short_md.md)]) para criar básicos componentes COM clássicos para uso em aplicativos de desktop, além disso, para usá-lo para [!INCLUDE[win8_appstore_long](../build/reference/includes/win8_appstore_long_md.md)] aplicativos. A criação de componentes COM, o [!INCLUDE[cppwrl_short](../windows/includes/cppwrl_short_md.md)] pode exigir menos código do que o ATL. Para obter informações sobre o subconjunto de COM que o [!INCLUDE[cppwrl_short](../windows/includes/cppwrl_short_md.md)] oferece suporte, consulte [biblioteca de modelos em C++ Windows Runtime (WRL)](../Topic/Windows%20Runtime%20C++%20Template%20Library%20\(WRL\).md).  
  
 Este documento mostra como usar o [!INCLUDE[cppwrl_short](../windows/includes/cppwrl_short_md.md)] para criar um componente básico. Embora você possa usar o mecanismo de implantação que melhor atenda às suas necessidades, este documento também mostra uma maneira básica de registrar e consumir o componente COM um aplicativo de desktop.  
  
### <a name="to-use-the-includecppwrlshorttokencppwrlshortmdmd-to-create-a-basic-classic-com-component"></a>Para usar o [!INCLUDE[cppwrl_short](../windows/includes/cppwrl_short_md.md)] para criar um componente COM clássico básico  
  
1.  No Visual Studio, crie um **solução em branco** projeto. Nomeie o projeto como, por exemplo, `WRLClassicCOM`.  
  
2.  Adicione um **Win32 Project** à solução. Nomeie o projeto como, por exemplo, `CalculatorComponent`. Sobre o **configurações de aplicativo** Selecione **DLL**.  
  
3.  Adicione um **arquivo Midl (. idl)** arquivo ao projeto. Nomeie o arquivo, por exemplo, `CalculatorComponent.idl`.  
  
4.  Adicione este código ao CalculatorComponent.idl:  
  
     [!code-cpp[wrl-classic-com-component#1](../windows/codesnippet/CPP/how-to-create-a-classic-com-component-using-wrl_1.idl)]  
  
5.  No CalculatorComponent.cpp, defina o `CalculatorComponent` classe. O `CalculatorComponent` classe herda de [Microsoft::WRL::RuntimeClass](../windows/runtimeclass-class.md). [Microsoft::WRL::RuntimeClassFlags \< ClassicCom>](../windows/runtimeclassflags-structure.md) Especifica que a classe derivada de [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509\(v=vs.85\).aspx) e não [IInspectable](http://msdn.microsoft.com/library/br205821\(v=vs.85\).aspx). (`IInspectable` está disponível somente para [!INCLUDE[win8_appstore_short](../windows/includes/win8_appstore_short_md.md)] componentes do aplicativo.) `CoCreatableClass` cria uma fábrica para a classe que pode ser usada com funções como [CoCreateInstance](http://msdn.microsoft.com/library/windows/desktop/ms686615\(v=vs.85\).aspx).  
  
     [!code-cpp[wrl-classic-com-component#2](../windows/codesnippet/CPP/how-to-create-a-classic-com-component-using-wrl_2.cpp)]  
  
6.  Use o código a seguir para substituir o código em dllmain.cpp. Esse arquivo define as funções de exportação DLL. Essas funções usam a [Microsoft::WRL::Module](../windows/module-class.md) classe para gerenciar as fábricas de classes para o módulo.  
  
     [!code-cpp[wrl-classic-com-component#3](../windows/codesnippet/CPP/how-to-create-a-classic-com-component-using-wrl_3.cpp)]  
  
7.  Adicione um **o arquivo de definição de módulo (. def)** arquivo ao projeto. Nomeie o arquivo, por exemplo, `CalculatorComponent.def`. Esse arquivo fornece o vinculador os nomes das funções a serem exportados.  
  
8.  Adicione este código ao CalculatorComponent.def:  
  
     [!CODE [wrl-classic-com-component#4](../CodeSnippet/VS_Snippets_Misc/wrl-classic-com-component#4)]  
  
9. Adicione runtimeobject.lib à linha de vinculador. Para saber como, consulte [. Arquivos lib como entrada de vinculador](../build/reference/dot-lib-files-as-linker-input.md).  
  
### <a name="to-consume-the-com-component-from-a-desktop-app"></a>Para consumir o componente COM um aplicativo de desktop  
  
1.  Registre o componente COM o registro do Windows. Para fazer isso, crie um arquivo de entradas do registro, nomeie-o `RegScript.reg`, e adicione o seguinte texto. Substitua *\< caminho da dll >* com o caminho do seu DLL — por exemplo, `C:\\temp\\WRLClassicCOM\\Debug\\CalculatorComponent.dll`.  
  
     [!CODE [wrl-classic-com-component#5](../CodeSnippet/VS_Snippets_Misc/wrl-classic-com-component#5)]  
  
2.  Execute RegScript.reg ou adicioná-lo ao seu projeto **evento pós-compilação**. Para obter mais informações, consulte [pré-compilação evento/pós-compilação linha de comando caixa de diálogo evento](../Topic/Pre-build%20Event-Post-build%20Event%20Command%20Line%20Dialog%20Box.md).  
  
3.  Adicione um **aplicativo do Console Win32** projeto à solução. Nomeie o projeto como, por exemplo, `Calculator`.  
  
4.  Use este código para substituir o conteúdo de Calculator.cpp:  
  
     [!code-cpp[wrl-classic-com-component#6](../windows/codesnippet/CPP/how-to-create-a-classic-com-component-using-wrl_6.cpp)]  
  
## <a name="robust-programming"></a>Programação robusta  
 Este documento usa as funções padrão COM para demonstrar que você pode usar o [!INCLUDE[cppwrl_short](../windows/includes/cppwrl_short_md.md)] para criar um componente COM e torná-lo disponível para qualquer tecnologia habilitado para COM. Você também pode usar [!INCLUDE[cppwrl_short](../windows/includes/cppwrl_short_md.md)] tipos como [Microsoft::WRL::ComPtr](../windows/comptr-class.md) em seu aplicativo da área de trabalho para gerenciar o tempo de vida de COM e outros objetos. O código a seguir usa o [!INCLUDE[cppwrl_short](../windows/includes/cppwrl_short_md.md)] para gerenciar a vida útil do `ICalculatorComponent` ponteiro. O `CoInitializeWrapper` classe é um wrapper RAII que garante que a biblioteca COM é liberada e também garante que é maior que o tempo de vida da biblioteca COM o `ComPtr` objeto de ponteiro inteligente.  
  
 [!code-cpp[wrl-classic-com-component#7](../windows/codesnippet/CPP/how-to-create-a-classic-com-component-using-wrl_7.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Biblioteca de modelos C++ do Windows Runtime (WRL)](../Topic/Windows%20Runtime%20C++%20Template%20Library%20\(WRL\).md)