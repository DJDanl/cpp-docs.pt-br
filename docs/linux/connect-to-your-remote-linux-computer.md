---
title: Conectar-se a seu sistema Linux de destino no Visual Studio
description: Como se conectar a uma máquina Linux remota ou ao Windows Subsystem para Linux de dentro de um projeto Visual Studio C++.
ms.date: 01/17/2020
ms.openlocfilehash: 624dce6bb05e4f4a961628e0c6f455e11c14dff8
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81364356"
---
# <a name="connect-to-your-target-linux-system-in-visual-studio"></a>Conectar-se a seu sistema Linux de destino no Visual Studio

::: moniker range="vs-2015"

O suporte ao Linux está disponível no Visual Studio 2017 e posterior.

::: moniker-end

::: moniker range="vs-2017"

É possível configurar um projeto do Linux para ter como destino um computador remoto ou o WSL (Subsistema Windows para Linux). Tanto para máquinas remotas quanto para WSL, você precisa configurar uma conexão remota no Visual Studio 2017.

::: moniker-end

::: moniker range="vs-2019"

É possível configurar um projeto do Linux para ter como destino um computador remoto ou o WSL (Subsistema Windows para Linux). Para uma máquina remota, você precisa configurar uma conexão remota no Visual Studio. Para conectar-se à WSL, pule para a seção [Conectar à WSL.](#connect-to-wsl)

::: moniker-end

::: moniker range=">=vs-2017"

Ao usar uma conexão remota, o Visual Studio constrói projetos C++ Linux na máquina remota. Não importa se é uma máquina física, uma VM na nuvem, ou WSL.
Para construir o projeto, o Visual Studio copia o código-fonte para o seu computador Linux remoto. Em seguida, o código é compilado com base nas configurações do Visual Studio.

::: moniker-end

::: moniker range="vs-2019"

> [!NOTE]
> Visual Studio 2019 versão 16.5 e posteriormente também suporta conexões criptográficas seguras, compatíveis com fips (Federal Information Processing Standard) 140-2, compatíveis com sistemas Linux para desenvolvimento remoto. Para usar uma conexão compatível com FIPS, siga as etapas em [Configurar o desenvolvimento seguro do Linux compatível com FIPS.](set-up-fips-compliant-secure-remote-linux-development.md)

::: moniker-end

::: moniker range=">=vs-2017"

## <a name="set-up-the-ssh-server-on-the-remote-system"></a>Configure o servidor SSH no sistema remoto

Se o ssh ainda não estiver configurado e em execução no seu sistema Linux, siga estas etapas para instalá-lo. Os exemplos neste artigo usam o Ubuntu 18.04 LTS com o servidor OpenSSH versão 7.6. No entanto, as instruções devem ser as mesmas para qualquer distro usando uma versão moderadamente recente do OpenSSH.

1. No sistema Linux, instale e inicie o servidor OpenSSH:

   ```bash
   sudo apt install openssh-server
   sudo service ssh start
   ```

1. Se você quiser que o servidor ssh seja iniciado automaticamente quando o sistema for inicializado, habilite-o usando systemctl:

   ```bash
   sudo systemctl enable ssh
   ```

## <a name="set-up-the-remote-connection"></a>Configure a conexão remota

1. No Visual Studio, escolha **Ferramentas > Opções** na barra de menus para abrir a caixa de diálogo **Opções.** Em seguida, selecione **Cross Platform > Connection Manager** para abrir a caixa de diálogo Gerenciador de conexões.

   Se você não tiver configurado uma conexão no Visual Studio antes, quando você construir seu projeto pela primeira vez, o Visual Studio abrirá a caixa de diálogo Gerenciador de conexões para você.

1. Na caixa de diálogo Gerenciador de conexões, escolha o botão **Adicionar** para adicionar uma nova conexão.

   ![Gerenciador de Conexões](media/settings_connectionmanager.png)

   Em ambos os cenários, a janela **Conectar ao sistema remoto** é exibida.

   ![Conectar-se ao Site Remoto](media/connect.png)

1. Insira as seguintes informações:

   | Entrada | Descrição
   | ----- | ---
   | **Nome do host**           | Nome ou endereço IP do dispositivo de destino
   | **Porta**                | Porta na qual o serviço SSH está em execução, normalmente 22
   | **Nome de usuário**           | Usuário como o qual será autenticado
   | **Tipo de autenticação** | Senha e Chave Privada são suportadas
   | **Senha**            | A senha do nome de usuário inserido
   | **Arquivo de chave privada**    | Arquivo de chave privada criado para conexão ssh
   | **Senha**          | Frase secreta usada com a chave privada selecionada acima

   Você pode usar uma senha ou um arquivo-chave e uma senha para autenticação. Para muitos cenários de desenvolvimento, a autenticação de senha é suficiente, mas os arquivos-chave são mais seguros. Se você já tem um par de chaves, é possível reutilizá-lo. Atualmente, o Visual Studio só suporta chaves RSA e DSA para conexões remotas.

1. Escolha o botão **Conectar** para tentar uma conexão com o computador remoto.

   Se a conexão for bem-sucedida, o Visual Studio configura o IntelliSense para usar os cabeçalhos remotos. Para saber mais, veja [IntelliSense para cabeçalhos em sistemas remotos](configure-a-linux-project.md#remote_intellisense).

   Se a conexão falhar, as caixas de entrada que precisarem ser alteradas serão destacadas em vermelho.

   ![Erro do Gerenciador de Conexões](media/settings_connectionmanagererror.png)

   Se você usar arquivos-chave para autenticação, certifique-se de que o servidor SSH da máquina de destino esteja sendo executado e configurado corretamente.

   ::: moniker-end

   ::: moniker range="vs-2019"

## <a name="logging-for-remote-connections"></a>Registro para conexões remotas

   Você pode habilitar o registro para ajudar a solucionar problemas de conexão. Na barra de menus, selecione **Ferramentas > Opções**. Na caixa de diálogo **Opções,** selecione **Cross Platform > Logging**:

   ![Log remoto](media/remote-logging-vs2019.png)

   Os logs incluem conexões, todos os comandos enviados para o computador remoto (texto, código de saída e tempo de execução) e toda a saída do Visual Studio para o shell. O registro em log funciona para qualquer projeto CMake de plataforma cruzada ou do Linux com base em MSBuild no Visual Studio.

   Você pode configurar a saída para ir a um arquivo ou ao painel **De registro de plataforma sinuosa** na janela Saída. Para projetos Linux baseados no MSBuild, os comandos MSBuild enviados para a máquina remota não são roteados para a **janela de saída** porque são emitidos fora do processo. Em vez disso, eles são conectados a um arquivo, com um prefixo de "msbuild_".

## <a name="command-line-utility-for-the-connection-manager"></a>Utilitário de linha de comando para o Gerenciador de Conexões  

**Visual Studio 2019 versão 16.5 ou posterior**: ConnectionManager.exe é um utilitário de linha de comando para gerenciar conexões de desenvolvimento remoto fora do Visual Studio. É útil para tarefas como o provisionamento de uma nova máquina de desenvolvimento. Ou, você pode usá-lo para configurar o Visual Studio para integração contínua. Para exemplos e uma referência completa ao comando ConnectionManager, consulte [referência ConnectionManager](connectionmanager-reference.md).  

::: moniker-end

::: moniker range=">=vs-2017"

## <a name="tcp-port-forwarding"></a>Encaminhamento da porta TCP

O suporte ao Linux do Visual Studio tem uma dependência do encaminhamento da porta TCP. **Rsync** e **gdbserver** são afetados se o encaminhamento da porta TCP estiver desativado no sistema remoto. Se você for impactado por essa dependência, você pode aumentar este bilhete de [sugestão](https://developercommunity.visualstudio.com/idea/840265/dont-rely-on-ssh-tcp-port-forwarding-for-c-remote.html) na Comunidade de Desenvolvedores.

rsync é usado por projetos Linux baseados em MSBuild e CMake para [copiar cabeçalhos do seu sistema remoto para o Windows para uso pelo IntelliSense](configure-a-linux-project.md#remote_intellisense). Quando você não puder ativar o encaminhamento da porta TCP, desative o download automático de cabeçalhos remotos. Para desativá-lo, use **ferramentas > opções > gerenciador de conexão > de > > gerenciador de cabeçalhos remotos IntelliSense Manager**. Se o sistema remoto não tiver o encaminhamento da porta TCP ativado, você verá esse erro quando o download de cabeçalhos remotos para intelliSense começar:

![Erro de cabeçalhos](media/port-forwarding-headers-error.png)

rsync também é usado pelo suporte CMake do Visual Studio para copiar arquivos de origem para o sistema remoto. Se você não puder habilitar o encaminhamento da porta TCP, você poderá usar o SFTP como seu método de fontes de cópia remota. sftp é muitas vezes mais lento do que rsync, mas não tem uma dependência do encaminhamento da porta TCP. Você pode gerenciar o método de fontes de cópia remota com a propriedade **remoteCopySourcesMethod** no [CMake Settings Editor](../build/cmakesettings-reference.md#additional-settings-for-cmake-linux-projects). Se o encaminhamento da porta TCP estiver desativado no sistema remoto, você verá um erro na janela de saída CMake na primeira vez que ele invoca rsync.

![Erro de rsync](media/port-forwarding-copy-error.png)

gdbserver pode ser usado para depuração em dispositivos incorporados. Se você não puder habilitar o encaminhamento da porta TCP, então você deve usar o gdb para todos os cenários de depuração remota. gdb é usado por padrão ao depurar projetos em um sistema remoto.

## <a name="connect-to-wsl"></a>Conectar ao WSL

::: moniker-end

::: moniker range="vs-2017"

No Visual Studio 2017, você usa as mesmas etapas para se conectar à WSL que você usa para uma máquina Linux remota. Use **localhost** para o **Nome do Host**.

::: moniker-end

::: moniker range="vs-2019"

Suporte nativo adicionado do Visual Studio 2019 versão 16.1 para uso de C++ com o [WSL (Subsistema Windows para Linux)](/windows/wsl/about). Isso significa que você pode construir e depurar diretamente em sua instalação WSL local. Você não precisa mais adicionar uma conexão remota ou configurar O SSH. É possível encontrar detalhes sobre [como instalar o WSL](/windows/wsl/install-win10) aqui.

Para configurar sua instalação wsl para trabalhar com o Visual Studio, você precisa das seguintes ferramentas instaladas: gcc ou clang, gdb, make, ninja-build (necessário apenas para projetos CMake usando visual studio versão 16.6 ou posterior), rsync e zip. Você pode instalá-los em distros que usam apto usando este comando, que também instala o compilador g++:

```bash
sudo apt install g++ gdb make ninja-build rsync zip
```

Para obter mais informações, consulte [Baixar, instalar e configurar a carga de trabalho do Linux](download-install-and-setup-the-linux-development-workload.md).

Para configurar um projeto MSBuild para WSL, consulte [Configurar um projeto Linux](configure-a-linux-project.md). Para configurar um projeto CMake para WSL, consulte [Configure um projeto Linux CMake](cmake-linux-project.md). Para seguir as instruções passo a passo para criar um aplicativo de console simples com o WSL, confira esta postagem introdutória no blog sobre [C++ com Visual Studio 2019 e o WSL (Subsistema Windows para Linux)](https://devblogs.microsoft.com/cppblog/c-with-visual-studio-2019-and-windows-subsystem-for-linux-wsl/).

::: moniker-end

## <a name="see-also"></a>Consulte Também

[Configure um projeto Linux](configure-a-linux-project.md)\
[Configure um projeto Linux CMake](cmake-linux-project.md)\
[Implantar, executar e depurar seu projeto Linux](deploy-run-and-debug-your-linux-project.md)\
[Configurar sessões de depuração do CMake](../build/configure-cmake-debugging-sessions.md)
