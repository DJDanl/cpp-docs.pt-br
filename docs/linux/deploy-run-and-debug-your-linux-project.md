---
title: Implantar, executar e depurar seu projeto Linux em C++ no Visual Studio
description: Descreve como compilar, executar e depurar o código no destino remoto de dentro de um projeto do Linux em C++ no Visual Studio.
ms.date: 06/07/2019
ms.assetid: f7084cdb-17b1-4960-b522-f84981bea879
ms.openlocfilehash: e68feab3a71cd5bb3f6b88eee52f0872ef4bb213
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "80077832"
---
# <a name="deploy-run-and-debug-your-linux-project"></a>Implantar, executar e depurar o projeto do Linux

::: moniker range="vs-2015"

O suporte ao Linux está disponível no Visual Studio 2017 e posterior.

::: moniker-end

Depois de criar um projeto do Linux em C++ no Visual Studio e se conectar a ele usando o [Gerenciador de Conexões do Linux](connect-to-your-remote-linux-computer.md), você pode executá-lo e depurá-lo. Você compilará, executará e depurará o código no destino remoto.

::: moniker range="vs-2019"

**Visual Studio 2019 versão 16.1** Você pode ter como destino diferentes sistemas Linux para depuração e build. Por exemplo, você pode fazer uma compilação cruzada no x64 e implantar em um dispositivo ARM ao visar cenários de IoT. Para saber mais, confira [Especificar computadores diferentes para compilação e depuração](#separate_build_debug), mais adiante neste artigo.

::: moniker-end

Há várias maneiras de interagir com o projeto do Linux e depurá-lo.

- Realize a depuração usando os recursos tradicionais do Visual Studio, como pontos de interrupção, janelas Inspeção e focalizar uma variável. Usando esses métodos, você pode depurar como faria normalmente para outros tipos de projeto.

- Exiba a saída do computador de destino em uma janela do Console do Linux. Você também pode usar o console para enviar entradas para o computador de destino.

## <a name="debug-your-linux-project"></a>Depurar o projeto do Linux

1. Selecione o modo de depuração na página de propriedades **Depuração**.

   ::: moniker range="vs-2019"

   O GDB é usado para depurar aplicativos em execução no Linux. Durante a depuração em um sistema remoto (exceto o WSL), o GDB pode ser executado em dois modos diferentes, que podem ser selecionados na opção **Modo de Depuração**, na página de propriedades **Depuração** do projeto:

   ![Opções do GDB](media/vs2019-debugger-settings.png)

   ::: moniker-end

   ::: moniker range="vs-2017"

   O GDB é usado para depurar aplicativos em execução no Linux. O GDB pode ser executado em dois modos diferentes, que podem ser selecionados na opção **Modo de Depuração**, na página de propriedades **Depuração** do projeto:

   ![Opções do GDB](media/vs2017-debugger-settings.png)

   ::: moniker-end

   - No modo **gdbserver**, o GDB é executado localmente, que se conecta ao gdbserver no sistema remoto.  Observe que esse é o único modo ao qual a janela do Console do Linux dá suporte.

   - No modo **gdb**, o depurador do Visual Studio conduz o GDB no sistema remoto. Essa é uma opção melhor se a versão local do GDB não é compatível com a versão instalada no computador de destino. |

   > [!NOTE]
   > Se não for possível atingir os pontos de interrupção no modo de depuração gdbserver, tente usar o gdb. O gdb precisa primeiro ser [instalado](download-install-and-setup-the-linux-development-workload.md) no destino remoto.

1. Selecione o destino remoto usando a barra de ferramentas padrão **Depurar** no Visual Studio.

   Quando o destino remoto estiver disponível, você o verá listados por nome ou endereço IP.

   ![Destino remoto](media/remote_target.png)

   Se ainda não tiver se conectado ao destino remoto, você verá uma instrução para usar o [Gerenciador de Conexões do Linux](connect-to-your-remote-linux-computer.md) para se conectar a ele.

   ![Arquitetura Remota](media/architecture.png)

1. Definir um ponto de interrupção clicando na medianiz esquerda de algum código que você sabe que será executado.

   Um ponto vermelho aparecerá na linha de código em que você definiu o ponto de interrupção.

1. Pressione **F5** (ou **Depurar > Iniciar depuração**) para iniciar a depuração.

   Quando você inicia a depuração, o aplicativo é compilado no destino remoto antes de ser iniciado. Os possíveis erros de compilação serão exibidos na janela **Lista de Erros**.

   Se não houver nenhum erro, o aplicativo será iniciado e o depurador pausará no ponto de interrupção.

   ![Atingir um ponto de interrupção](media/hit_breakpoint.png)

   Agora, você pode interagir com o aplicativo em seu estado atual, exibir variáveis e percorrer o código pressionando as teclas de comando como **F10** ou **F11**.

1. Se você quiser usar o Console do Linux para interagir com o aplicativo, selecione **Depurar > Console do Linux**.

   ![Menu do Console do Linux](media/consolemenu.png)

   Esse console exibirá qualquer saída do console do computador de destino, bem como usará a entrada e a enviará ao computador de destino.

   ![Janela do Console do Linux](media/consolewindow.png)

## <a name="configure-other-debugging-options-msbuild-based-projects"></a>Configurar outras opções de depuração (projetos baseados em MSBuild)

- Argumentos de linha de comando podem ser passados para o executável usando o item **Argumentos do Programa** na página de propriedades **Depuração** do projeto.

   ![Argumentos do Programa](media/settings_programarguments.png)

- Opções específicas do depurador podem ser passadas para o GDB usando a entrada **Comandos adicionais do depurador**.  Por exemplo, talvez você deseje ignorar os sinais SIGILL (instrução inválida).  Seria possível usar o comando **handle** para isso, adicionando o seguinte à entrada **Comandos Adicionais do Depurador**, como mostrado acima:

   `handle SIGILL nostop noprint`

## <a name="configure-other-debugging-options-cmake-projects"></a>Configurar outras opções de depuração (projetos do CMake)

Você pode especificar argumentos de linha de comando adicionais para um projeto do CMake no arquivo launch.vs.json. Para saber mais, veja [Depurar o projeto do CMake](cmake-linux-project.md#debug_cmake_project)

## <a name="debug-with-attach-to-process"></a>Depuração com Anexar ao Processo

A página de propriedades [Depuração](prop-pages/debugging-linux.md) para projetos do Visual Studio e as configurações de **Launch.vs.json** para projetos do CMake têm configurações que permitem anexar a um processo em execução. Caso você precise ter controle adicional além do que é fornecido nessas configurações, coloque um arquivo chamado `Microsoft.MIEngine.Options.xml` na raiz da solução ou do workspace. Este é um exemplo simples:

```xml
<?xml version="1.0" encoding="utf-8"?>
<SupplementalLaunchOptions>
    <AttachOptions>
      <AttachOptionsForConnection AdditionalSOLibSearchPath="/home/user/solibs">
        <ServerOptions MIDebuggerPath="C:\Program Files (x86)\Microsoft Visual Studio\Preview\Enterprise\Common7\IDE\VC\Linux\bin\gdb\7.9\x86_64-linux-gnu-gdb.exe"
ExePath="C:\temp\ConsoleApplication17\ConsoleApplication17\bin\x64\Debug\ConsoleApplication17.out"/>
        <SetupCommands>
          <Command IgnoreFailures="true">-enable-pretty-printing</Command>
        </SetupCommands>
      </AttachOptionsForConnection>
    </AttachOptions>
</SupplementalLaunchOptions>
```

**AttachOptionsForConnection** tem a maioria dos atributos que você poderá precisar. O exemplo acima mostra como especificar uma localização para pesquisar bibliotecas .so adicionais. O elemento filho **ServerOptions** permite anexar ao processo remoto com gdbserver. Para fazer isso, você precisará especificar um cliente local do gdb (aquele fornecido no Visual Studio 2017 é mostrado acima) e uma cópia local do binário com símbolos. O elemento **SetupCommands** permite passar comandos diretamente para o gdb. Encontre todas as opções disponíveis no [esquema LaunchOptions.xsd](https://github.com/Microsoft/MIEngine/blob/master/src/MICore/LaunchOptions.xsd) no GitHub.

::: moniker range="vs-2019"

## <a name="specify-different-machines-for-building-and-debugging"></a><a name="separate_build_debug"></a> Especificar computadores diferentes para compilação e depuração

No Visual Studio de 2019 versão 16.1, você pode separar o computador de compilação remoto do seu computador de depuração remoto para projetos do CMake e projetos do Linux baseados no MSBuild destinados a um computador Linux remoto. Por exemplo, você pode fazer uma compilação cruzada no x64 e implantar em um dispositivo ARM ao visar cenários de IoT.

### <a name="msbuild-based-projects"></a>Projetos baseados em MSBuild

Por padrão, a máquina de depuração remota é a mesma da máquina de compilação remota **(Configuration Properties** > **General** > **Remote Build Machine**). Para especificar um novo computador de depuração remoto, clique com botão direito no projeto no **Gerenciador de Soluções** e vá para **Propriedades da Configuração** > **Depuração** > **Computador de Depuração Remoto**.  

![Computador de depuração remoto do Linux](media/linux-remote-debug-machine.png)

O menu suspenso para **Computador de Depuração Remoto** é preenchido com todas as conexões remotas estabelecidas. Para adicionar uma nova conexão remota, navegue até o **Gerenciador** > de**Conexões entre** **Plataformas** > **Cross Platform** > de Ferramentas ou procure por "Gerenciador de Conexões" no **Lançamento Rápido**. Você também pode especificar um novo diretório de implantação remota nas páginas de propriedades do projeto (Configuration**Properties** > **General** > **Remote Deploy Directory).**

Por padrão, somente os arquivos necessários para depurar o processo serão implantados no computador de depuração remoto. Você pode usar o **Gerenciador de Soluções** para configurar os arquivos de origem que serão implantados no computador de depuração remoto. Ao clicar em um arquivo de origem, você verá uma visualização de suas Propriedades de Arquivo logo abaixo do Gerenciador de Soluções.

![Arquivos implantáveis do Linux](media/linux-deployable-content.png)

A propriedade **Content** especifica se o arquivo será implantado no computador de depuração remoto. Você pode desativar a implantação inteiramente navegando no**Gerenciador de Configuração de** **Páginas** > de Propriedade e desverificando **o Implante** para a configuração desejada.

Em alguns casos, você pode exigir mais controle sobre a implantação do projeto. Por exemplo, alguns arquivos que você quer implantar podem estar fora da sua solução ou você quer personalizar o seu diretório de implantação remoto por arquivo ou diretório. Nesses casos, acrescente os seguintes blocos de código ao arquivo .vcxproj e substitua "example.cpp" pelos nomes de arquivo reais:

```xml

<ItemGroup>
   <RemoteDeploy Include="__example.cpp">
<!-- This is the source Linux machine, can be empty if DeploymentType is LocalRemote -->
      <SourceMachine>$(RemoteTarget)</SourceMachine>
      <TargetMachine>$(RemoteDebuggingTarget)</TargetMachine>
      <SourcePath>~/example.cpp</SourcePath>
      <TargetPath>~/example.cpp</TargetPath>
<!-- DeploymentType can be LocalRemote, in which case SourceMachine will be empty and SourcePath is a local file on Windows -->
      <DeploymentType>RemoteRemote</DeploymentType>
<!-- Indicates whether the deployment contains executables -->
      <Executable>true</Executable>
   </RemoteDeploy>
</ItemGroup>
```

### <a name="cmake-projects"></a>Projetos do CMake

Para projetos do CMake que se destinam a um computador Linux remoto, você pode especificar um novo computador de depuração remoto em launch.vs.json. Por padrão, o valor de "remoteMachineName" é sincronizado com a propriedade "remoteMachineName" em CMakeSettings.json, que corresponde ao seu computador de compilação remoto. Essas propriedades não precisam mais corresponder, e o valor de "remoteMachineName" em launch.vs.json determinará qual computador remoto será usado para implantação e depuração.

![Computador de depuração remoto do CMake](media/cmake-remote-debug-machine.png)

O IntelliSense sugere uma lista de todas as conexões remotas estabelecidas. Você pode adicionar uma nova conexão remota navegando para **o Tools** > **Options** > **Cross Platform** > **Connection Manager** ou procurando por "Connection Manager" no Quick **Launch**.

Se quiser controle completo sobre a implantação, você poderá acrescentar os seguintes blocos de código ao arquivo launch.vs.json. Lembre-se de substituir os valores do espaço reservado pelos valores reais:

```json

"disableDeploy": false,
"deployDirectory": "~\foo",
"deploy" : [
   {
      "sourceMachine": "127.0.0.1 (username=example1, port=22, authentication=Password)",
      "targetMachine": "192.0.0.1 (username=example2, port=22, authentication=Password)",
      "sourcePath": "~/example.cpp",
      "targetPath": "~/example.cpp",
      "executable": "false"
   }
]

```

::: moniker-end

## <a name="next-steps"></a>Próximas etapas

- Para depurar dispositivos ARM no Linux, consulte esta postagem no blog: [Debugging an embedded ARM device in Visual Studio](https://blogs.msdn.microsoft.com/vcblog/2018/01/10/debugging-an-embedded-arm-device-in-visual-studio/) (Depurando um dispositivo ARM inserido no Visual Studio).

## <a name="see-also"></a>Confira também

[Propriedades do depurador C++ (Linux C++)](prop-pages/debugging-linux.md)
