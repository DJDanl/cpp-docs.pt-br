---
title: DLLs (C++/CX)
ms.date: 02/06/2018
ms.assetid: 5b8bcc57-64dd-4c54-9f24-26a25bd5dddd
ms.openlocfilehash: 4db0ed4f11f03c65c440c7b654653347da1d4536
ms.sourcegitcommit: 180f63704f6ddd07a4172a93b179cf0733fd952d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/06/2019
ms.locfileid: "70740267"
---
# <a name="dlls-ccx"></a>DLLs (C++/CX)

Você pode usar o Visual Studio para criar uma DLL Win32 padrão ou uma DLL de componente Windows Runtime que possa ser consumida por aplicativos Plataforma Universal do Windows (UWP). Uma DLL padrão que foi criada usando uma versão do Visual Studio ou o compilador da C++ Microsoft anterior ao visual Studio 2012 pode não ser carregada corretamente em um aplicativo UWP e pode não passar o teste de verificação do aplicativo no Microsoft Store.

## <a name="windows-runtime-component-dlls"></a>Windows Runtime DLLs de componente

Em quase todos os casos, quando você deseja criar uma DLL para uso em um aplicativo UWP, crie-a como um componente Windows Runtime usando o modelo de projeto desse nome. Você pode criar um projeto de componente Windows Runtime para DLLs que têm tipos de Windows Runtime públicos ou privados. Um componente Windows Runtime pode ser acessado de aplicativos que são escritos em qualquer linguagem compatível com Windows Runtime. Por padrão, as configurações do compilador para um projeto de componente Windows Runtime usam a opção **/zw** Um arquivo .winmd deve ter o mesmo nome do namespace raiz. Por exemplo, uma classe denominada A.B.C.MyClass poderá ser instanciada somente se for definida em um arquivo de metadados denominado A.winmd ou A.B.winmd ou A.B.C.winmd. O nome da DLL não precisa coincidir com o nome do arquivo .winmd.

Para obter mais informações, consulte [Creating Windows Runtime Components in C++](/windows/uwp/winrt-components/creating-windows-runtime-components-in-cpp).

### <a name="to-reference-a-third-party-windows-runtime-component-binary-in-your-project"></a>Para fazer referência a um binário de componente de Windows Runtime de terceiros em seu projeto

1. Abra o menu de atalho do projeto que usará a DLL e escolha **Propriedades**. Na página **Propriedades Comuns** , escolha o botão **Adicionar Nova Referência** .

1. Um componente de Windows Runtime consiste em um arquivo DLL e um arquivo. winmd que contém os metadados. Normalmente, esses arquivos estão localizados na mesma pasta. No painel esquerdo da caixa de diálogo **Adicionar Referência** , escolha o botão **Procurar** e navegue para o local da DLL e seu arquivo .winmd. Para obter mais informações, consulte [SDKs de extensão](/visualstudio/extensibility/creating-a-software-development-kit#extension-sdks).

## <a name="standard-dlls"></a>DLLs padrão

Você pode criar uma DLL padrão para C++ o código que não consuma nem produzir tipos de Windows Runtime públicos e consumi-lo de um aplicativo UWP. Use o tipo de projeto DLL (Dynamic-Link Library) quando você apenas quiser migrar uma DLL existente para compilar nesta versão do Visual Studio, mas não converter o código em um projeto de componente Windows Runtime. Quando você usa as etapas a seguir, a DLL será implantada juntamente com o executável de seu aplicativo no pacote .appx.

### <a name="to-create-a-standard-dll-in-visual-studio"></a>Para criar uma DLL padrão no Visual Studio

1. Na barra de menus, escolha **arquivo**, **novo**, **projeto**e, em seguida, selecione o modelo **biblioteca de vínculo dinâmico (DLL)** .

1. Digite um nome para o projeto e escolha o botão **OK** .

1. Adicione o código. Não se esqueça de usar `__declspec(dllexport)` para funções que você pretende exportar, por exemplo, `__declspec(dllexport) Add(int I, in j);`

1. Adicione `#include winapifamily.h` para incluir esse arquivo de cabeçalho do SDK do Windows para aplicativos UWP e definir a macro `WINAPI_FAMILY=WINAPI_PARTITION_APP`.

### <a name="to-reference-a-standard-dll-project-from-the-same-solution"></a>Para referenciar um projeto de DLL padrão da mesma solução

1. Abra o menu de atalho do projeto que usará a DLL e escolha **Propriedades**. Na página **Propriedades Comuns** , escolha o botão **Adicionar Nova Referência** .

1. No painel esquerdo, selecione **Solução**e marque a caixa de seleção apropriada no painel direito.

1. Nos arquivos de código de origem, adicione uma instrução `#include` para o arquivo de cabeçalho de DLL, conforme necessário.

### <a name="to-reference-a-standard-dll-binary"></a>Para referenciar um binário de DLL padrão

1. Copie os arquivos DLL, .lib e o arquivo de cabeçalho e cole-os em um local conhecido, por exemplo, na pasta do seu projeto atual.

1. Abra o menu de atalho do projeto que usará a DLL e escolha **Propriedades**. Na página **Propriedades de Configuração**, **Vinculador**, **Entrada** , adicione o arquivo .lib como uma dependência.

1. Nos arquivos de código de origem, adicione uma instrução `#include` para o arquivo de cabeçalho de DLL, conforme necessário.

### <a name="to-migrate-an-existing-win32-dll-for-uwp-app-compatibility"></a>Para migrar uma DLL Win32 existente para compatibilidade de aplicativo UWP

1. Crie um projeto do tipo DLL (universal do Windows) e adicione o código-fonte existente a ele.

1. Adicione `#include winapifamily.h` para incluir esse arquivo de cabeçalho do SDK do Windows para aplicativos UWP e definir a macro `WINAPI_FAMILY=WINAPI_PARTITION_APP`.

1. Nos arquivos de código de origem, adicione uma instrução `#include` para o arquivo de cabeçalho de DLL, conforme necessário.
