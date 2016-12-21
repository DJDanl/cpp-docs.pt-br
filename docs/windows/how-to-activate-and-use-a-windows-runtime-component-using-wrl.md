---
title: "Como ativar e usar um componente de Tempo de Execu&#231;&#227;o do Windows com WRL | Microsoft Docs"
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
ms.assetid: 54828f02-6af3-45d1-b965-d0104442f8d5
caps.latest.revision: 17
caps.handback.revision: 17
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como ativar e usar um componente de Tempo de Execu&#231;&#227;o do Windows com WRL
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este documento mostra como usar [!INCLUDE[cppwrl](../windows/includes/cppwrl_md.md)] \([!INCLUDE[cppwrl_short](../windows/includes/cppwrl_short_md.md)]\) para inicializar [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] e como ativar e usar um componente de [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] .  
  
> [!NOTE]
>  Esse exemplo ativa um componente interno de [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] .  Para aprender a criar seu próprio componente que você pode alternar de maneira semelhante, consulte [Passo a passo: Criando um componente básico do Tempo de Execução do Windows](../windows/walkthrough-creating-a-basic-windows-runtime-component-using-wrl.md).  
  
 Para usar um componente, você deve adquirir um ponteiro de interface do tipo implementado pelo componente.  E como a tecnologia subjacente de [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] é o Component Object Model \(COM\), você deve seguir as regras de COM para manter uma instância do tipo.  Por exemplo, você deve manter *a contagem de referência* que determina quando o tipo é excluído de memória.  
  
 Para simplificar o uso de [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)], [!INCLUDE[cppwrl_short](../windows/includes/cppwrl_short_md.md)] fornece o modelo inteligente do ponteiro, [ComPtr\<T\>](../windows/comptr-class.md), que é executado automaticamente a contagem de referência.  Quando declara uma variável, especifique `ComPtr<`*interface\-name*`>` *identifier*.  Para acessar um membro da interface, aplicar o operador membros de acesso de seta \(`->`\) ao identificador.  
  
> [!IMPORTANT]
>  Quando você chama uma função da interface, sempre teste o valor de retorno de `HRESULT` .  
  
## Ativando e usando um componente de Tempo de Execução do Windows  
 As etapas a seguir usam a interface de `Windows::Foundation::IUriRuntimeClass` para demonstrar como criar uma fábrica de ativação para um componente de [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] , crie uma instância desse componente, além de recuperar um valor da propriedade.  Também mostram como inicializar [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)].  O exemplo completo a seguir.  
  
> [!IMPORTANT]
>  Embora você normalmente usa [!INCLUDE[cppwrl_short](../windows/includes/cppwrl_short_md.md)] em um aplicativo de [!INCLUDE[win8_appname_long](../build/includes/win8_appname_long_md.md)] , esse exemplo usa um aplicativo de console para ilustração.  Funções como `wprintf_s` não estão disponíveis em um aplicativo de [!INCLUDE[win8_appname_long](../build/includes/win8_appname_long_md.md)] .  Para obter mais informações sobre os tipos e funções que você pode usar em um aplicativo de [!INCLUDE[win8_appname_long](../build/includes/win8_appname_long_md.md)] , consulte [Funções de CRT sem suporte com \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx) e [O Win32 e COM para aplicativos do Windows Store](http://msdn.microsoft.com/library/windows/apps/br205757.aspx).  
  
#### Para ativar e usar um componente de Tempo de Execução do Windows  
  
1.  Inclua \(\)`#include`qualquer [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)]necessário, [!INCLUDE[cppwrl_short](../windows/includes/cppwrl_short_md.md)], ou cabeçalhos de biblioteca padrão do C\+\+.  
  
     [!CODE [wrl-consume-component#2](../CodeSnippet/VS_Snippets_Misc/wrl-consume-component#2)]  
  
     Recomendamos que você utiliza a política de `using namespace` no arquivo .cpp para tornar código mais legível.  
  
2.  Inicializar o thread em que o aplicativo é executado.  Cada aplicativo deve inicializar os threads e modelo de threading.  Este exemplo usa a classe de [Microsoft::WRL::Wrappers::RoInitializeWrapper](../Topic/RoInitializeWrapper%20Class.md) para inicializar [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] e especificá\-la [RO\_INIT\_MULTITHREADED](http://msdn.microsoft.com/library/windows/apps/br224661.aspx) como o modelo de threading.  A classe de `RoInitializeWrapper` chama `Windows::Foundation::Initialize` na construção e, `Windows::Foundation::Uninitialize` quando é destruída.  
  
     [!CODE [wrl-consume-component#3](../CodeSnippet/VS_Snippets_Misc/wrl-consume-component#3)]  
  
     Na segunda instrução, o operador de [RoInitializeWrapper::HRESULT](../windows/roinitializewrapper-hresult-parens-operator.md) retorna `HRESULT` de chamada a `Windows::Foundation::Initialize`.  
  
3.  Crie *uma fábrica de ativação* para a interface de `ABI::Windows::Foundation::IUriRuntimeClassFactory` .  
  
     [!CODE [wrl-consume-component#4](../CodeSnippet/VS_Snippets_Misc/wrl-consume-component#4)]  
  
     Os nomes totalmente qualificados de [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] para identificar tipos.  O parâmetro de `RuntimeClass_Windows_Foundation_Uri` é uma cadeia de caracteres que é fornecida por [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] e contém o nome da classe necessário em tempo de execução.  
  
4.  Inicializar uma variável de [Microsoft::WRL::Wrappers::HString](../windows/hstring-class.md) que representa o URI `"http://www.microsoft.com"`.  
  
     [!CODE [wrl-consume-component#6](../CodeSnippet/VS_Snippets_Misc/wrl-consume-component#6)]  
  
     Em [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)], não aloca memória para uma cadeia de caracteres que [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] use.  Em vez disso, [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] cria uma cópia da cadeia de caracteres em um buffer que mantém e use para operações de, e então retornará um identificador para o buffer que criou.  
  
5.  Use o método de fábrica de `IUriRuntimeClassFactory::CreateUri` para criar um objeto de `ABI::Windows::Foundation::IUriRuntimeClass` .  
  
     [!CODE [wrl-consume-component#7](../CodeSnippet/VS_Snippets_Misc/wrl-consume-component#7)]  
  
6.  Chame o método de `IUriRuntimeClass::get_Domain` para recuperar o valor da propriedade de `Domain` .  
  
     [!CODE [wrl-consume-component#8](../CodeSnippet/VS_Snippets_Misc/wrl-consume-component#8)]  
  
7.  Imprime o nome de domínio no console e retornar.  Qualquer `ComPtr` e os objetos de RAII permitem o escopo e são liberados automaticamente.  
  
     [!CODE [wrl-consume-component#9](../CodeSnippet/VS_Snippets_Misc/wrl-consume-component#9)]  
  
     [WindowsGetStringRawBuffer](http://msdn.microsoft.com/library/windows/apps/br224636.aspx) A função recupera o formato subjacente Unicode de cadeia de caracteres do URI.  
  
 Aqui está o exemplo completo:  
  
 [!CODE [wrl-consume-component#1](../CodeSnippet/VS_Snippets_Misc/wrl-consume-component#1)]  
  
## Compilando o código  
 Para compilar o código, copie\-a e cole\-o em um projeto do Visual Studio, ou cole\-o em um arquivo chamado `wrl-consume-component.cpp` e execute o comando a seguir em uma janela de prompt de comando do Visual Studio.  
  
 **cl.exe wrl\-consume\-component.cpp runtimeobject.lib**  
  
## Consulte também  
 [Biblioteca de Modelos C\+\+ do Tempo de Execução do Windows \(WRL\)](../Topic/Windows%20Runtime%20C++%20Template%20Library%20\(WRL\).md)