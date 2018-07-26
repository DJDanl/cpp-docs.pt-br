---
title: Implantar, executar e depurar seu projeto Linux em C++ no Visual Studio | Microsoft Docs
description: Descreve como compilar, executar e depurar o código no destino remoto de dentro de um projeto do Linux em C++ no Visual Studio.
ms.custom: ''
ms.date: 07/20/2018
ms.technology:
- cpp-linux
ms.tgt_pltfrm: Linux
ms.topic: conceptual
ms.assetid: f7084cdb-17b1-4960-b522-f84981bea879
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
- linux
ms.openlocfilehash: 57f8aea7d3ff3ddfd28beff6647dc16885d972e3
ms.sourcegitcommit: 7eadb968405bcb92ffa505e3ad8ac73483e59685
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/23/2018
ms.locfileid: "39207673"
---
# <a name="deploy-run-and-debug-your-linux-project"></a>Implantar, executar e depurar o projeto do Linux

Depois de criar um projeto do Linux em C++ no Visual Studio e se conectar a ele usando o [Gerenciador de Conexões do Linux](../linux/connect-to-your-remote-linux-computer.md), você pode executá-lo e depurá-lo. Você compilará, executará e depurará o código no destino remoto.

Há várias maneiras de interagir com o projeto do Linux e depurá-lo.

* Realize a depuração usando os recursos tradicionais do Visual Studio, como pontos de interrupção, janelas Inspeção e focalizar uma variável. Usando esses métodos, você pode depurar como faria normalmente para outros tipos de projeto.
* Exibir a saída do computador de destino em uma janela especial do Console do Linux. Você também pode usar o console para enviar entradas para o computador de destino.

## <a name="debug-your-linux-project"></a>Depurar o projeto do Linux

1. Selecione o modo de depuração na página de propriedades **Depuração**.

    O GDB é usado para depurar aplicativos em execução no Linux.  No entanto, isso pode ser executado em dois modos diferentes, que podem ser selecionados na opção **Modo de Depuração**, na página de propriedades **Depuração** do projeto:

    ![Opções do GDB](media/settings_debugger.png)

    - No modo **gdbserver**, o GDB é executado localmente, que se conecta ao gdbserver em execução no sistema remoto.  Observe que esse é o único modo que dá suporte à janela do Console do Linux.

    - No modo **gdb**, o depurador do Visual Studio executa o GDB no sistema remoto, que será mais compatível se a versão local do GDB não for compatível com a versão instalada no computador de destino. |

    > [!NOTE] 
    > Se não for possível atingir os pontos de interrupção no modo de depuração gdbserver, tente usar o gdb. O gdb precisa primeiro ser [instalado](../linux/download-install-and-setup-the-linux-development-workload.md) no destino remoto.

2. Selecione o destino remoto usando a barra de ferramentas padrão **Depurar** no Visual Studio.

    Quando o destino remoto estiver disponível, você o verá listados por nome ou endereço IP.

    ![Destino remoto](media/remote_target.png)

    Se ainda não tiver se conectado ao destino remoto, você verá uma instrução para usar o [Gerenciador de Conexões do Linux](../linux/connect-to-your-remote-linux-computer.md) para se conectar a ele.

    ![Arquitetura Remota](media/architecture.png)

3. Definir um ponto de interrupção clicando na medianiz esquerda de algum código que você sabe que será executado.

    Um ponto vermelho aparecerá na linha de código em que você definiu o ponto de interrupção.

4. Pressione **F5** (ou **Depurar > Iniciar depuração**) para iniciar a depuração.

    Quando você inicia a depuração, o aplicativo é compilado no destino remoto antes de ser iniciado. Os possíveis erros de compilação serão exibidos na janela **Lista de Erros**.

    Se não houver nenhum erro, o aplicativo será iniciado e o depurador pausará no ponto de interrupção.

    ![Atingir um ponto de interrupção](media/hit_breakpoint.png)  

    Agora, você pode interagir com o aplicativo em seu estado atual, exibir variáveis e percorrer o código pressionando as teclas de comando como **F10** ou **F11**.

4. Se você quiser usar o Console do Linux para interagir com o aplicativo, selecione **Depurar > Console do Linux**.

  ![Menu do Console do Linux](media/consolemenu.png)

  Esse console exibirá qualquer saída do console do computador de destino, bem como usará a entrada e a enviará ao computador de destino.

  ![Janela do Console do Linux](media/consolewindow.png)

## <a name="configure-other-debugging-options"></a>Configurar outras opções de depuração

* Argumentos de linha de comando podem ser passados para o executável usando o item **Argumentos do Programa** na página de propriedades **Depuração** do projeto.
  
  ![Argumentos do Programa](media/settings_programarguments.png)

* Opções específicas do depurador podem ser passadas para o GDB usando a entrada **Comandos adicionais do depurador**.  Por exemplo, talvez você deseje ignorar os sinais SIGILL (instrução inválida).  Você poderá usar o comando **handle** para fazer isso.  adicionando o seguinte à entrada **Comandos adicionais do depurador**, conforme mostrado acima:

  ```handle SIGILL nostop noprint```

## <a name="next-steps"></a>Próximas etapas

* Para depurar dispositivos ARM no Linux, consulte esta postagem no blog: [Debugging an embedded ARM device in Visual Studio](https://blogs.msdn.microsoft.com/vcblog/2018/01/10/debugging-an-embedded-arm-device-in-visual-studio/) (Depurando um dispositivo ARM inserido no Visual Studio).

* Para depurar usando o comando **Anexar ao Processo**, consulte esta postagem no blog: [Linux C++ Workload improvements to the Project System, Linux Console Window, rsync and Attach to Process](https://blogs.msdn.microsoft.com/vcblog/2018/03/13/linux-c-workload-improvements-to-the-project-system-linux-console-window-rsync-and-attach-to-process/) (Melhorias na carga de trabalho do Linux C++ para o Sistema de Projeto, para a Janela de Console do Linux, para rsync e para Anexar ao Processo).

## <a name="see-also"></a>Consulte também
[Propriedades de depuração de C++ (Linux C++)](../linux/prop-pages/debugging-linux.md).
