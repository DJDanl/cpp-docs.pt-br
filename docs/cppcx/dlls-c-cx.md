---
title: DLLs (C + + CX) | Microsoft Docs
ms.custom: 
ms.date: 02/03/2017
ms.prod: windows-client-threshold
ms.technology: cpp-windows
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: 5b8bcc57-64dd-4c54-9f24-26a25bd5dddd
caps.latest.revision: "21"
author: ghogen
ms.author: ghogen
manager: ghogen
ms.openlocfilehash: a3202ba5bd5b42b3f4853348258d5c4e3e5a2072
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="dlls-ccx"></a>DLLs (C++/CX)
Você pode usar o Visual Studio para criar uma DLL padrão do Win32 ou uma DLL que pode ser consumido por aplicativos de plataforma Universal do Windows de componente do tempo de execução do Windows. Uma DLL padrão que foi criada usando uma versão do Visual Studio ou do compilador Visual C++ anterior ao Visual Studio 2012 pode não carregar corretamente em um aplicativo de plataforma Universal do Windows e pode não passar no teste de verificação do aplicativo no [!INCLUDE[win8_appstore_long](../cppcx/includes/win8-appstore-long-md.md)].  
  
## <a name="windows-runtime-component-dlls"></a>DLLs de componentes de tempo de execução do Windows  
 Em quase todos os casos, quando você quiser criar uma DLL para uso em um aplicativo de plataforma Universal do Windows, criá-lo como um componente de tempo de execução do Windows usando o modelo de projeto do nome. Você pode criar um projeto de componente de tempo de execução do Windows para DLLs que tenham tipos públicos ou privados do Windows Runtime. Um componente de tempo de execução do Windows pode ser acessado em aplicativos que são escritos em qualquer linguagem compatível com o Windows Runtime. Por padrão, as configurações do compilador para um componente de tempo de execução do Windows projeto usar o **/ZW** alternar. Um arquivo .winmd deve ter o mesmo nome do namespace raiz. Por exemplo, uma classe denominada A.B.C.MyClass poderá ser instanciada somente se for definida em um arquivo de metadados denominado A.winmd ou A.B.winmd ou A.B.C.winmd. O nome da DLL não precisa coincidir com o nome do arquivo .winmd.  
  
 Para obter mais informações, consulte [Creating Windows Runtime Components in C++](/MicrosoftDocs/windows-uwp/blob/docs/windows-apps-src/winrt-components/creating-windows-runtime-components-in-cpp.md).  
  
#### <a name="to-reference-a-third-party-windows-runtime-component-binary-in-your-project"></a>Para fazer referência a um componente de tempo de execução do Windows de terceiros binário em seu projeto  
  
1.  Abra o menu de atalho do projeto que usará a DLL e escolha **Propriedades**. Na página **Propriedades Comuns** , escolha o botão **Adicionar Nova Referência** .  
  
2.  Um componente de tempo de execução do Windows consiste em um arquivo DLL e um arquivo. winmd que contém os metadados. Normalmente, esses arquivos estão localizados na mesma pasta. No painel esquerdo da caixa de diálogo **Adicionar Referência** , escolha o botão **Procurar** e navegue para o local da DLL e seu arquivo .winmd. Para obter mais informações, veja [Tutorial: criando e usando SDKs de extensão](http://msdn.microsoft.com/en-us/001e2fca-3d56-43ab-a5e0-0561d085679f).  
  
## <a name="standard-dlls"></a>DLLs padrão  
 Você pode criar uma DLL padrão para o código C++ que não consuma ou produza tipos públicos do Windows Runtime e consumi-lo em um aplicativo de plataforma Universal do Windows. Use o tipo de projeto de DLL de plataforma Universal do Windows quando você quiser apenas migrar para uma DLL existente para compilar nesta versão do Visual Studio, mas não converter o código em um projeto de componente de tempo de execução do Windows. Quando você usa as etapas a seguir, a DLL será implantada juntamente com o executável de seu aplicativo no pacote .appx.  
  
#### <a name="to-create-a-standard-dll-in-visual-studio"></a>Para criar uma DLL padrão no Visual Studio  
  
1.  Na barra de menus, escolha **arquivo**, **novo**, **projeto**e, em seguida, selecione o modelo de DLL de plataforma Universal do Windows.  
  
2.  Digite um nome para o projeto e escolha o botão **OK** .  
  
3.  Adicione o código. Não se esqueça de usar `__declspec(dllexport)` para funções que você pretende exportar, por exemplo, `__declspec(dllexport) Add(int I, in j);`  
  
4.  Adicionar `#include winapifamily.h` para incluir esse arquivo de cabeçalho do SDK do Windows para aplicativos de plataforma Universal do Windows e defina a macro `WINAPI_FAMILY=WINAPI_PARTITION_APP`.  
  
#### <a name="to-reference-a-standard-dll-project-from-the-same-solution"></a>Para referenciar um projeto de DLL padrão da mesma solução  
  
1.  Abra o menu de atalho do projeto que usará a DLL e escolha **Propriedades**. Na página **Propriedades Comuns** , escolha o botão **Adicionar Nova Referência** .  
  
2.  No painel esquerdo, selecione **Solução**e marque a caixa de seleção apropriada no painel direito.  
  
3.  Nos arquivos de código de origem, adicione uma instrução `#include` para o arquivo de cabeçalho de DLL, conforme necessário.  
  
#### <a name="to-reference-a-standard-dll-binary"></a>Para referenciar um binário de DLL padrão  
  
1.  Copie os arquivos DLL, .lib e o arquivo de cabeçalho e cole-os em um local conhecido, por exemplo, na pasta do seu projeto atual.  
  
2.  Abra o menu de atalho do projeto que usará a DLL e escolha **Propriedades**. Na página **Propriedades de Configuração**, **Vinculador**, **Entrada** , adicione o arquivo .lib como uma dependência.  
  
3.  Nos arquivos de código de origem, adicione uma instrução `#include` para o arquivo de cabeçalho de DLL, conforme necessário.  
  
#### <a name="to-migrate-an-existing-win32-dll-for-universal-windows-platform-app-compatibility"></a>Para migrar uma Win32 DLL existente para compatibilidade de aplicativo da plataforma Universal do Windows  
  
1.  Crie um projeto do tipo DLL de plataforma Universal do Windows e adicione seu código-fonte existente a ele.  
  
2.  Adicionar `#include winapifamily.h` para incluir esse arquivo de cabeçalho do SDK do Windows para aplicativos de plataforma Universal do Windows e defina a macro `WINAPI_FAMILY=WINAPI_PARTITION_APP`.  
  
3.  Nos arquivos de código de origem, adicione uma instrução `#include` para o arquivo de cabeçalho de DLL, conforme necessário.  
  

