---
title: Implantar, executar e depurar seu projeto Linux em C++ no Visual Studio
description: Descreve como compilar, executar e depurar o código no destino remoto de dentro de um projeto do Linux em C++ no Visual Studio.
ms.date: 09/12/2018
ms.assetid: f7084cdb-17b1-4960-b522-f84981bea879
ms.openlocfilehash: cdafb064f8a6269c5ccae938e280b5f47bff3b00
ms.sourcegitcommit: b4645761ce5acf8c2fc7a662334dd5a471ea976d
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/07/2019
ms.locfileid: "57562881"
---
# <a name="deploy-run-and-debug-your-linux-project"></a>Implantar, executar e depurar o projeto do Linux

Depois de criar um projeto do Linux em C++ no Visual Studio e se conectar a ele usando o [Gerenciador de Conexões do Linux](connect-to-your-remote-linux-computer.md), você pode executá-lo e depurá-lo. Você compilará, executará e depurará o código no destino remoto.

Há várias maneiras de interagir com o projeto do Linux e depurá-lo.

- Realize a depuração usando os recursos tradicionais do Visual Studio, como pontos de interrupção, janelas Inspeção e focalizar uma variável. Usando esses métodos, você pode depurar como faria normalmente para outros tipos de projeto.

- Exibir a saída do computador de destino em uma janela especial do Console do Linux. Você também pode usar o console para enviar entradas para o computador de destino.

## <a name="debug-your-linux-project"></a>Depurar o projeto do Linux

1. Selecione o modo de depuração na página de propriedades **Depuração**.

   O GDB é usado para depurar aplicativos em execução no Linux. O GDB pode ser executado em dois modos diferentes, que podem ser selecionados na opção **Modo de Depuração**, na página de propriedades **Depuração** do projeto:

   ![Opções do GDB](media/settings_debugger.png)

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

## <a name="next-steps"></a>Próximas etapas

- Para depurar dispositivos ARM no Linux, leia esta postagem no blog: [Depurando um dispositivo ARM inserido no Visual Studio](https://blogs.msdn.microsoft.com/vcblog/2018/01/10/debugging-an-embedded-arm-device-in-visual-studio/).

- Para depurar usando o comando **Anexar ao Processo**, confira esta postagem no blog: [Melhorias à Carga de Trabalho em Linux C++ para Sistema de Projeto, Janela de Console do Linux, rsync e Anexar ao Processo](https://blogs.msdn.microsoft.com/vcblog/2018/03/13/linux-c-workload-improvements-to-the-project-system-linux-console-window-rsync-and-attach-to-process/).

## <a name="see-also"></a>Consulte também

[Propriedades do depurador C++ (Linux C++)](prop-pages/debugging-linux.md)
