---
title: Conectar-se a seu sistema Linux de destino no Visual Studio
description: Como se conectar a um computador Linux remoto ou a um subsistema do Windows para Linux de dentro C++ de um projeto do Visual Studio.
ms.date: 01/17/2020
ms.openlocfilehash: d0065b63d7a81d3ae3d68b26184c88aca77f601c
ms.sourcegitcommit: a930a9b47bd95599265d6ba83bb87e46ae748949
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/22/2020
ms.locfileid: "76518212"
---
# <a name="connect-to-your-target-linux-system-in-visual-studio"></a>Conectar-se a seu sistema Linux de destino no Visual Studio

::: moniker range="vs-2015"

O suporte ao Linux está disponível no Visual Studio 2017 e posterior.

::: moniker-end

::: moniker range="vs-2017"

É possível configurar um projeto do Linux para ter como destino um computador remoto ou o WSL (Subsistema Windows para Linux). Para máquinas remotas e para WSL, você precisa configurar uma conexão remota no Visual Studio 2017.

::: moniker-end

::: moniker range="vs-2019"

É possível configurar um projeto do Linux para ter como destino um computador remoto ou o WSL (Subsistema Windows para Linux). Para um computador remoto, você precisa configurar uma conexão remota no Visual Studio. Para se conectar ao WSL, pule para a seção [conectar-se ao WSL](#connect-to-wsl) .

::: moniker-end

::: moniker range=">=vs-2017"

Ao usar uma conexão remota, o Visual Studio C++ cria projetos do Linux no computador remoto. Não importa se é uma máquina física, uma VM na nuvem ou WSL.
Para compilar o projeto, o Visual Studio copia o código-fonte para o computador Linux remoto. Em seguida, o código é compilado com base nas configurações do Visual Studio.

::: moniker-end

::: moniker range="vs-2019"

> [!NOTE]
> O Visual Studio 2019 versão 16,5 e posterior também oferece suporte a conexões criptográficas compatíveis com Secure, padrão FIPS (FIPS) 140-2 para sistemas Linux para desenvolvimento remoto. Para usar uma conexão compatível com FIPS, siga as etapas em [Configurar o desenvolvimento Linux remoto seguro em conformidade com FIPS](set-up-fips-compliant-secure-remote-linux-development.md) em vez disso.

::: moniker-end

::: moniker range=">=vs-2017"

## <a name="set-up-the-ssh-server-on-the-remote-system"></a>Configurar o servidor SSH no sistema remoto

Se o ssh ainda não estiver configurado e em execução no seu sistema Linux, siga estas etapas para instalá-lo. Os exemplos neste artigo usam o Ubuntu 18, 4 LTS com o servidor OpenSSH versão 7,6. No entanto, as instruções devem ser as mesmas para qualquer distribuição usando uma versão moderadamente recente do OpenSSH.

1. No sistema Linux, instale e inicie o servidor OpenSSH:

   ```bash
   sudo apt install openssh-server
   sudo service ssh start
   ```

1. Se você quiser que o servidor SSH seja iniciado automaticamente quando o sistema for inicializado, habilite-o usando systemctl:

   ```bash
   sudo systemctl enable ssh
   ```

## <a name="set-up-the-remote-connection"></a>Configurar a conexão remota

1. No Visual Studio, escolha **ferramentas > opções** na barra de menus para abrir a caixa de diálogo **Opções** . Em seguida, selecione a **plataforma cruzada > Gerenciador de conexões** para abrir a caixa de diálogo Gerenciador de conexões.

   Se você ainda não configurou uma conexão no Visual Studio antes, quando você cria seu projeto pela primeira vez, o Visual Studio abre a caixa de diálogo Gerenciador de conexões para você.

1. Na caixa de diálogo Gerenciador de conexões, escolha o botão **Adicionar** para adicionar uma nova conexão.

   ![Gerenciador de Conexões](media/settings_connectionmanager.png)

   Em qualquer cenário, a janela **conectar ao sistema remoto** é exibida.

   ![Conectar-se ao Site Remoto](media/connect.png)

1. Insira as seguintes informações:

   | Entrada | Descrição
   | ----- | ---
   | **Nome do host**           | Nome ou endereço IP do dispositivo de destino
   | **Porta**                | Porta na qual o serviço SSH está em execução, normalmente 22
   | **Nome de usuário**           | Usuário como o qual será autenticado
   | **Tipo de autenticação** | A senha e a chave privada têm suporte
   | **Senha**            | A senha do nome de usuário inserido
   | **Arquivo de chave privada**    | Arquivo de chave privada criado para conexão ssh
   | **Frase secreta**          | Frase secreta usada com a chave privada selecionada acima

   Você pode usar uma senha ou um arquivo de chave e uma senha para autenticação. Para muitos cenários de desenvolvimento, a autenticação de senha é suficiente, mas os arquivos de chave são mais seguros. Se você já tiver um par de chaves, é possível reutilizá-lo. Atualmente, o Visual Studio dá suporte apenas a chaves RSA e DSA para conexões remotas.

1. Escolha o botão **conectar** para tentar uma conexão com o computador remoto.

   Se a conexão for realizada com sucesso, o Visual Studio configurará o IntelliSense para usar os cabeçalhos remotos. Para saber mais, veja [IntelliSense para cabeçalhos em sistemas remotos](configure-a-linux-project.md#remote_intellisense).

   Se a conexão falhar, as caixas de entrada que precisarem ser alteradas serão destacadas em vermelho.

   ![Erro do Gerenciador de Conexões](media/settings_connectionmanagererror.png)

   Se você usar arquivos de chave para autenticação, verifique se o servidor SSH da máquina de destino está em execução e configurado corretamente.

   ::: moniker-end

   ::: moniker range="vs-2019"

## <a name="logging-for-remote-connections"></a>Registro em log para conexões remotas

   Você pode habilitar o log para ajudar a solucionar problemas de conexão. Na barra de menus, selecione **ferramentas > opções**. Na caixa de diálogo **Opções** , selecione **registro em log de > de plataforma cruzada**:

   ![Log remoto](media/remote-logging-vs2019.png)

   Os logs incluem conexões, todos os comandos enviados para o computador remoto (texto, código de saída e tempo de execução) e toda a saída do Visual Studio para o shell. O registro em log funciona para qualquer projeto CMake de plataforma cruzada ou do Linux com base em MSBuild no Visual Studio.

   Você pode configurar a saída para ir para um arquivo ou para o painel de **log da plataforma cruzada** na janela de saída. Para projetos do Linux baseados em MSBuild, os comandos do MSBuild enviados para o computador remoto não são roteados para a **janela de saída** porque eles são emitidos fora do processo. Em vez disso, eles são registrados em um arquivo, com um prefixo de "msbuild_".

## <a name="command-line-utility-for-the-connection-manager"></a>Utilitário de linha de comando para o Gerenciador de conexões  

**Visual studio 2019 versão 16,5 ou posterior**: ConnectionManager. exe é um utilitário de linha de comando para gerenciar conexões de desenvolvimento remoto fora do Visual Studio. Ele é útil para tarefas como o provisionamento de uma nova máquina de desenvolvimento. Ou você pode usá-lo para configurar o Visual Studio para integração contínua. Para obter exemplos e uma referência completa ao comando ConnectionManager, consulte [referência de ConnectionManager](connectionmanager-reference.md).  

::: moniker-end

::: moniker range=">=vs-2017"

## <a name="tcp-port-forwarding"></a>Encaminhamento de porta TCP

O suporte ao Linux do Visual Studio tem uma dependência do encaminhamento de porta TCP. **Rsync** e **gdbserver** serão afetados se o encaminhamento de porta TCP estiver desabilitado no seu sistema remoto. Se você for afetado por essa dependência, poderá votar neste [tíquete de sugestão](https://developercommunity.visualstudio.com/idea/840265/dont-rely-on-ssh-tcp-port-forwarding-for-c-remote.html) na Comunidade de desenvolvedores.

rsync é usado por projetos do Linux baseados em MSBuild e projetos CMake para [Copiar cabeçalhos do seu sistema remoto para o Windows para uso pelo IntelliSense](configure-a-linux-project.md#remote_intellisense). Quando não for possível habilitar o encaminhamento de porta TCP, desabilite o download automático de cabeçalhos remotos. Para desabilitá-lo, use **ferramentas > opções > > do Gerenciador de conexões > cabeçalhos remotos Gerenciador do IntelliSense**. Se o sistema remoto não tiver o encaminhamento de porta TCP habilitado, você verá esse erro quando o download de cabeçalhos remotos para IntelliSense começar:

![Erro de cabeçalhos](media/port-forwarding-headers-error.png)

rsync também é usado pelo suporte do CMake do Visual Studio para copiar arquivos de origem para o sistema remoto. Se você não puder habilitar o encaminhamento de porta TCP, poderá usar o SFTP como seu método de fontes de cópia remota. o SFTP é geralmente mais lento do que o rsync, mas não tem uma dependência no encaminhamento de porta TCP. Você pode gerenciar o método de fontes de cópia remota com a propriedade **remoteCopySourcesMethod** no [Editor de configurações do cmake](../build/cmakesettings-reference.md#additional-settings-for-cmake-linux-projects). Se o encaminhamento de porta TCP estiver desabilitado em seu sistema remoto, você verá um erro na janela de saída CMake na primeira vez que invoca rsync.

![Erro de rsync](media/port-forwarding-copy-error.png)

gdbserver pode ser usado para depuração em dispositivos inseridos. Se você não puder habilitar o encaminhamento de porta TCP, deverá usar o gdb para todos os cenários de depuração remota. o gdb é usado por padrão durante a depuração de projetos em um sistema remoto.

## <a name="connect-to-wsl"></a>Conectar ao WSL

::: moniker-end

::: moniker range="vs-2017"

No Visual Studio 2017, você usa as mesmas etapas para se conectar ao WSL como você usa para um computador Linux remoto. Use **localhost** para o **Nome do Host**.

::: moniker-end

::: moniker range="vs-2019"

Suporte nativo adicionado do Visual Studio 2019 versão 16.1 para uso de C++ com o [WSL (Subsistema Windows para Linux)](/windows/wsl/about). Isso significa que você pode criar e depurar diretamente na instalação do WSL local. Você não precisa mais adicionar uma conexão remota ou configurar o SSH. É possível encontrar detalhes sobre [como instalar o WSL](/windows/wsl/install-win10) aqui.

Para configurar a instalação do WSL para funcionar com o Visual Studio, você precisará das seguintes ferramentas instaladas: gcc ou Clang, gdb, Make, rsync e zip. Você pode instalá-los em distribuições que usam a apt usando esse comando, que também instala o compilador g + +:

```bash
sudo apt install g++ gdb make rsync zip
```

Para obter mais informações, consulte [baixar, instalar e configurar a carga de trabalho do Linux](download-install-and-setup-the-linux-development-workload.md).

Para configurar um projeto do MSBuild para WSL, consulte [configurar um projeto do Linux](configure-a-linux-project.md). Para configurar um projeto do CMake para o WSL, consulte [configurar um projeto CMake do Linux](cmake-linux-project.md). Para seguir as instruções passo a passo para criar um aplicativo de console simples com o WSL, confira esta postagem introdutória no blog sobre [C++ com Visual Studio 2019 e o WSL (Subsistema Windows para Linux)](https://devblogs.microsoft.com/cppblog/c-with-visual-studio-2019-and-windows-subsystem-for-linux-wsl/).

::: moniker-end

## <a name="see-also"></a>Veja também

[Configurar um projeto do Linux](configure-a-linux-project.md)\
[Configurar um projeto CMake do Linux](cmake-linux-project.md)\
[Implante, execute e depure seu projeto do Linux](deploy-run-and-debug-your-linux-project.md)\
[Configurar sessões de depuração do CMake](../build/configure-cmake-debugging-sessions.md)
