---
title: DLLs (C + + c++ /CX) | Microsoft Docs
ms.custom: ''
ms.date: 02/06/2018
ms.technology: cpp-windows
ms.topic: language-reference
ms.assetid: 5b8bcc57-64dd-4c54-9f24-26a25bd5dddd
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1ac06336e5ba80406157285ebe660080aff6e319
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43763627"
---
# <a name="dlls-ccx"></a>DLLs (C++/CX)

Você pode usar o Visual Studio para criar uma DLL Win32 padrão ou um DLL que pode ser consumido por aplicativos de plataforma Universal do Windows (UWP) do componente de tempo de execução do Windows. Uma DLL padrão que foi criada usando uma versão do Visual Studio ou o compilador Visual C++ anterior ao Visual Studio 2012 pode não carregar corretamente em um aplicativo UWP e não pode passar o teste de verificação do aplicativo em que a Microsoft Store.

## <a name="windows-runtime-component-dlls"></a>DLLs de componentes de tempo de execução do Windows

Em quase todos os casos, quando você deseja criar uma DLL para usar em um aplicativo UWP, criá-lo como um componente de tempo de execução do Windows usando o modelo de projeto, esse nome. Você pode criar um projeto de componente de tempo de execução do Windows para DLLs que tenham tipos de tempo de execução do Windows públicos ou privados. Um componente de tempo de execução do Windows pode ser acessado em aplicativos que são escritos em qualquer linguagem compatível com o Windows Runtime. Por padrão, as configurações do compilador para um componente de tempo de execução do Windows projeto use a **/ZW** alternar. Um arquivo .winmd deve ter o mesmo nome do namespace raiz. Por exemplo, uma classe denominada A.B.C.MyClass poderá ser instanciada somente se for definida em um arquivo de metadados denominado A.winmd ou A.B.winmd ou A.B.C.winmd. O nome da DLL não precisa coincidir com o nome do arquivo .winmd.

Para obter mais informações, consulte [Criando componentes do tempo de execução do Windows em C++](/windows/uwp/winrt-components/creating-windows-runtime-components-in-cpp).

### <a name="to-reference-a-third-party-windows-runtime-component-binary-in-your-project"></a>Para fazer referência a um componente de tempo de execução do Windows de terceiros binário no seu projeto

1. Abra o menu de atalho do projeto que usará a DLL e escolha **Propriedades**. Na página **Propriedades Comuns** , escolha o botão **Adicionar Nova Referência** .

1. Um componente de tempo de execução do Windows consiste em um arquivo DLL e um arquivo. winmd que contém os metadados. Normalmente, esses arquivos estão localizados na mesma pasta. No painel esquerdo da caixa de diálogo **Adicionar Referência** , escolha o botão **Procurar** e navegue para o local da DLL e seu arquivo .winmd. Para obter mais informações, consulte [SDKs de extensão](/visualstudio/extensibility/creating-a-software-development-kit#ExtensionSDKs).

## <a name="standard-dlls"></a>DLLs padrão

Você pode criar uma DLL padrão para o código de C++ que não consomem ou geram tipos públicos do tempo de execução do Windows e consumi-lo em um aplicativo UWP. Quando você deseja apenas migrar de uma DLL existente para compilar nesta versão do Visual Studio, mas não converter o código em um projeto de componente de tempo de execução do Windows, use o tipo de projeto de biblioteca de vínculo dinâmico (DLL). Quando você usa as etapas a seguir, a DLL será implantada juntamente com o executável de seu aplicativo no pacote .appx.

### <a name="to-create-a-standard-dll-in-visual-studio"></a>Para criar uma DLL padrão no Visual Studio

1. Na barra de menus, escolha **arquivo**, **New**, **projeto**e, em seguida, selecione o **biblioteca de vínculo dinâmico (DLL)** modelo.

1. Digite um nome para o projeto e escolha o botão **OK** .

1. Adicione o código. Não se esqueça de usar `__declspec(dllexport)` para funções que você pretende exportar, por exemplo, `__declspec(dllexport) Add(int I, in j);`

1. Adicione `#include winapifamily.h` para incluir esse arquivo de cabeçalho do SDK do Windows para aplicativos UWP e defina a macro `WINAPI_FAMILY=WINAPI_PARTITION_APP`.

### <a name="to-reference-a-standard-dll-project-from-the-same-solution"></a>Para referenciar um projeto de DLL padrão da mesma solução

1. Abra o menu de atalho do projeto que usará a DLL e escolha **Propriedades**. Na página **Propriedades Comuns** , escolha o botão **Adicionar Nova Referência** .

1. No painel esquerdo, selecione **Solução**e marque a caixa de seleção apropriada no painel direito.

1. Nos arquivos de código de origem, adicione uma instrução `#include` para o arquivo de cabeçalho de DLL, conforme necessário.

### <a name="to-reference-a-standard-dll-binary"></a>Para referenciar um binário de DLL padrão

1. Copie os arquivos DLL, .lib e o arquivo de cabeçalho e cole-os em um local conhecido, por exemplo, na pasta do seu projeto atual.

1. Abra o menu de atalho do projeto que usará a DLL e escolha **Propriedades**. Na página **Propriedades de Configuração**, **Vinculador**, **Entrada** , adicione o arquivo .lib como uma dependência.

1. Nos arquivos de código de origem, adicione uma instrução `#include` para o arquivo de cabeçalho de DLL, conforme necessário.

### <a name="to-migrate-an-existing-win32-dll-for-uwp-app-compatibility"></a>Para migrar uma Win32 DLL existente para compatibilidade de aplicativo UWP

1. Criar um projeto do tipo DLL (Universal Windows) e adicione seu código-fonte existente para ele.

1. Adicione `#include winapifamily.h` para incluir esse arquivo de cabeçalho do SDK do Windows para aplicativos UWP e defina a macro `WINAPI_FAMILY=WINAPI_PARTITION_APP`.

1. Nos arquivos de código de origem, adicione uma instrução `#include` para o arquivo de cabeçalho de DLL, conforme necessário.
