---
title: Implantar, executar e depurar seu projeto Linux em C++ no Visual Studio
description: Descreve como compilar, executar e depurar o código no destino remoto de dentro de um projeto do Linux em C++ no Visual Studio.
ms.date: 06/07/2019
ms.assetid: f7084cdb-17b1-4960-b522-f84981bea879
ms.openlocfilehash: 707915a502aafefee47af7e84b534e06ba678b3d
ms.sourcegitcommit: 8adabe177d557c74566c13145196c11cef5d10d4
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/10/2019
ms.locfileid: "66821624"
---
# <a name="deploy-run-and-debug-your-linux-project"></a>Implantar, executar e depurar o projeto do Linux

::: moniker range="vs-2015"

O suporte ao Linux está disponível no Visual Studio 2017 e posterior.

::: moniker-end

Depois de criar um projeto do Linux em C++ no Visual Studio e se conectar a ele usando o [Gerenciador de Conexões do Linux](connect-to-your-remote-linux-computer.md), você pode executá-lo e depurá-lo. Você compilará, executará e depurará o código no destino remoto.

::: moniker range="vs-2019"

**Visual Studio 2019 versão 16.1** Você pode ter como destino diferentes sistemas Linux para depuração e build. Especifique o computador de build na página de propriedades **Geral** e o computador de depuração na página de propriedades **Depuração**.

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

## <a name="configure-other-debugging-options"></a>Configurar outras opções de depuração

- Argumentos de linha de comando podem ser passados para o executável usando o item **Argumentos do Programa** na página de propriedades **Depuração** do projeto.

   ![Argumentos do Programa](media/settings_programarguments.png)

- Opções específicas do depurador podem ser passadas para o GDB usando a entrada **Comandos adicionais do depurador**.  Por exemplo, talvez você deseje ignorar os sinais SIGILL (instrução inválida).  Você poderá usar o comando **handle** para fazer isso.  adicionando o seguinte à entrada **Comandos adicionais do depurador**, conforme mostrado acima:

   `handle SIGILL nostop noprint`

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

## <a name="next-steps"></a>Próximas etapas

- Para depurar dispositivos ARM no Linux, leia esta postagem no blog: [Depurando um dispositivo ARM inserido no Visual Studio](https://blogs.msdn.microsoft.com/vcblog/2018/01/10/debugging-an-embedded-arm-device-in-visual-studio/).

## <a name="see-also"></a>Consulte também

[Propriedades do depurador C++ (Linux C++)](prop-pages/debugging-linux.md)
