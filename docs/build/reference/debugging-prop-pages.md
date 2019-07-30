---
title: C++Depurando páginas de propriedades
ms.date: 7/24/2019
ms.topic: article
ms.assetid: 78115a6b-3799-4515-814e-8566b5bdc55d
f1_keywords:
- VC.Project.IVCLocalDebugPageObject.Command
- VC.Project.IVCLocalDebugPageObject.CommandArguments
- VC.Project.IVCLocalDebugPageObject.WorkingDirectory
- VC.Project.IVCLocalDebugPageObject.Attach
- VC.Project.IVCLocalDebugPageObject.DebuggerType
- VC.Project.IVCLocalDebugPageObject.Environment
- VC.Project.IVCLocalDebugPageObject.GPUDebuggerTargetType
- VC.Project.IVCLocalDebugPageObject.GPUBreakOnAllThreads
- VC.Project.IVCLocalDebugPageObject.EnvironmentMerge
- VC.Project.IVCLocalDebugPageObject.SQLDebugging
- VC.Project.IVCLocalDebugPageObject.AmpDefaultAccelerator
- VC.Project.IVCRemoteDebugPageObject.RemoteCommand
- VC.Project.IVCRemoteDebugPageObject.CommandArguments
- VC.Project.IVCRemoteDebugPageObject.WorkingDirectory
- VC.Project.IVCRemoteDebugPageObject.RemoteMachine
- VC.Project.IVCRemoteDebugPageObject.Remote
- VC.Project.IVCRemoteDebugPageObject.DebuggerType
- VC.Project.IVCRemoteDebugPageObject.Environment
- VC.Project.IVCRemoteDebugPageObject.GPUDebuggerTargetType
- VC.Project.IVCRemoteDebugPageObject.GPUBreakOnAllThreads
- VC.Project.IVCRemoteDebugPageObject.Attach
- VC.Project.IVCRemoteDebugPageObject.SQLDebugging
- VC.Project.IVCRemoteDebugPageObject.DeploymentDirectory
- VC.Project.IVCRemoteDebugPageObject.AdditionalFiles
- VC.Project.IVCRemoteDebugPageObject.Remote
- VC.Project.IVCRemoteDebugPageObject.AmpDefaultAccelerator
- VC.Project.VCDebugSettings.WebBrowser.WebBrowserDebuggerHttpUrl
- VC.Project.VCDebugSettings.WebBrowser.DebuggerType
- VC.Project.IVCWebSvcDebugPageObject.HttpUrl
- VC.Project.IVCWebSvcDebugPageObject.DebuggerType
- VC.Project.IVCWebSvcDebugPageObject.SQLDebugging
ms.openlocfilehash: a63ac181b4ef281d6d78d951a46bba85103ba636
ms.sourcegitcommit: 7b039b5f32f6c59be6c6bb1cffafd69c3bfadd35
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/26/2019
ms.locfileid: "68537792"
---
# <a name="c-debugging-property-pages"></a>C++Depurando páginas de propriedades

Essas páginas de propriedades são encontradas em**Propriedades** > do **projeto** > **depuração**de**Propriedades** > de configuração. Escolha o tipo de depurador no controle suspenso. Para obter mais informações sobre C++ o código de [depuração, consulte Tutorial: Aprenda a depurar C++ código usando o Visual](/visualstudio/debugger/getting-started-with-the-debugger-cpp) Studio e a [depuração de código nativo](/visualstudio/debugger/debugging-native-code).

## <a name="local-windows-debugger-property-page"></a>Página de propriedades do depurador local do Windows

### <a name="command"></a>Comando

O comando de depuração a ser executado.

### <a name="command-arguments"></a>Argumentos de comando

Os argumentos de linha de comando a serem passados para o aplicativo.

### <a name="working-directory"></a>Diretório de trabalho

O diretório de trabalho do aplicativo. Por padrão, o diretório que contém o arquivo de projeto.

### <a name="attach"></a>Attach

Especifica se o depurador deve tentar anexar a um processo existente quando a depuração é iniciada.

### <a name="debugger-type"></a>Tipo de Depurador

Especifica o tipo de depurador a ser usado. Quando definido como auto, o tipo de depurador será selecionado com base no conteúdo do arquivo exe.

**Durante**

- **Somente nativo** -somente nativo
- **Somente** gerenciados-somente gerenciados
- Misto misto
- Auto **-automático**
- Script **-script**
- **Somente GPU (C++ amp)** -somente GPU (C++ amp)

### <a name="environment"></a>Ambiente

Especifica o ambiente do programa a ser depurado ou as variáveis a serem mescladas com o ambiente existente.

### <a name="debugging-accelerator-type"></a>Tipo de acelerador de depuração

O tipo de acelerador de depuração a ser usado para depurar o código de GPU. (Disponível quando o depurador de GPU estiver ativo.)

### <a name="gpu-default-breakpoint-behavior"></a>Comportamento de ponto de interrupção padrão de GPU

Define a frequência com que o depurador de GPU é interrompido.

**Durante**

- **Interromper uma vez por distorção** -quebra uma vez por distorção
- **Interrupção para cada thread (como o comportamento da CPU)** – interromper para cada thread (como o comportamento da CPU)

### <a name="merge-environment"></a>Ambiente de mesclagem

Mesclar variáveis de ambiente especificadas com o ambiente existente.

### <a name="sql-debugging"></a>Depuração SQL

Anexe o depurador do SQL.

### <a name="amp-default-accelerator"></a>Acelerador padrão amp

Substitua C++ a seleção de acelerador padrão do amp. A propriedade não se aplica ao depurar código gerenciado.

## <a name="remote-windows-debugger-property-page"></a>Página de propriedades do depurador remoto do Windows

Para obter mais informações sobre depuração remota, consulte [depuração remota de C++ um projeto Visual no Visual Studio](/visualstudio/debugger/remote-debugging-cpp).

### <a name="remote-command"></a>Comando remoto

O comando de depuração a ser executado.

### <a name="remote-command-arguments"></a>Argumentos de comando remoto

Os argumentos de linha de comando a serem passados para o aplicativo.

### <a name="working-directory"></a>Diretório de trabalho

O diretório de trabalho do aplicativo. Por padrão, o diretório que contém o arquivo de projeto.

### <a name="remote-server-name"></a>Nome do servidor remoto

Especifica um nome de servidor remoto.

### <a name="connection"></a>Conexão

Especifica o tipo de conexão.

**Durante**

- **Remoto com autenticação do Windows** – remoto com [autenticação do Windows](/windows-server/security/windows-authentication/windows-authentication-overview).
- **Remoto sem autenticação** -remota sem autenticação.

### <a name="debugger-type"></a>Tipo de Depurador

Especifica o tipo de depurador a ser usado. Quando definido como auto, o tipo de depurador será selecionado com base no conteúdo do arquivo exe.

**Durante**

- **Somente nativo** -somente nativo
- **Somente** gerenciados-somente gerenciados
- Misto misto
- Auto **-automático**
- Script **-script**
- **Somente GPU (C++ amp)** -somente GPU (C++ amp)

### <a name="environment"></a>Ambiente

Especifica o ambiente do programa a ser depurado ou as variáveis a serem mescladas com o ambiente existente.

### <a name="debugging-accelerator-type"></a>Tipo de acelerador de depuração

O tipo de acelerador de depuração a ser usado para depurar o código de GPU. (Disponível quando o depurador de GPU estiver ativo.)

### <a name="gpu-default-breakpoint-behavior"></a>Comportamento de ponto de interrupção padrão de GPU

Define a frequência com que o depurador de GPU é interrompido.

**Durante**

- **Interromper uma vez por distorção** -quebra uma vez por distorção
- **Interrupção para cada thread (como o comportamento da CPU)** – interromper para cada thread (como o comportamento da CPU)

### <a name="attach"></a>Attach

Especifica se o depurador deve tentar anexar a um processo existente quando a depuração é iniciada.

### <a name="sql-debugging"></a>Depuração SQL

Anexe o depurador do SQL.

### <a name="deployment-directory"></a>Diretório de implantação

Ao depurar em um computador remoto, se você quiser que o conteúdo da saída do projeto (exceto por arquivos PDB) seja copiado para o computador remoto, especifique o caminho aqui.

### <a name="additional-files-to-deploy"></a>Arquivos adicionais a implantar

Ao depurar em um computador remoto, os arquivos e diretórios especificados aqui (além da saída do projeto) são copiados para o diretório de implantação se um tiver sido especificado.

### <a name="deploy-visual-c-debug-runtime-libraries"></a>Implantar bibliotecas em tempo de execução de depuração do Visual C++

Especifica se as bibliotecas de tempo de execução de depuração para a plataforma ativa (Win32, x64 ou ARM) devem ser implantadas.

### <a name="amp-default-accelerator"></a>Acelerador padrão amp

Substitua C++ a seleção de acelerador padrão do amp. A propriedade não se aplica ao depurar código gerenciado.

## <a name="web-browser-debugger-property-page"></a>Página de propriedades do depurador do navegador da Web

### <a name="http-url"></a>URL HTTP

Especifica a URL para o projeto.

### <a name="debugger-type"></a>Tipo de Depurador

Especifica o tipo de depurador a ser usado. Quando definido como auto, o tipo de depurador será selecionado com base no conteúdo do arquivo exe.

**Durante**

- **Somente nativo** -somente nativo
- **Somente** gerenciados-somente gerenciados
- Misto misto
- Auto **-automático**
- Script **-script**

## <a name="web-service-debugger-property-page"></a>Página de propriedades do depurador de serviço Web

### <a name="http-url"></a>URL HTTP

Especifica a URL para o projeto.

### <a name="debugger-type"></a>Tipo de Depurador

Especifica o tipo de depurador a ser usado. Quando definido como auto, o tipo de depurador será selecionado com base no conteúdo do arquivo exe.

**Durante**

- **Somente nativo** -somente nativo
- **Somente** gerenciados-somente gerenciados
- Misto misto
- Auto **-automático**
- Script **-script**

### <a name="sql-debugging"></a>Depuração SQL

Anexe o depurador do SQL.