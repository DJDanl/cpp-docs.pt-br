---
title: Conectar-se a seu sistema Linux de destino no Visual Studio
description: Como se conectar a um computador Linux remoto ou WSL de dentro de um projeto do Visual Studio C++.
ms.date: 09/04/2019
ms.assetid: 5eeaa683-4e63-4c46-99ef-2d5f294040d4
ms.openlocfilehash: 3d91faa7aa83c86e8c2f3544ee61c16f75f8c346
ms.sourcegitcommit: 0cfc43f90a6cc8b97b24c42efcf5fb9c18762a42
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/05/2019
ms.locfileid: "73626762"
---
# <a name="connect-to-your-target-linux-system-in-visual-studio"></a>Conectar-se a seu sistema Linux de destino no Visual Studio

::: moniker range="vs-2015"

O suporte ao Linux está disponível no Visual Studio 2017 e posterior.

::: moniker-end

::: moniker range=">=vs-2017"

É possível configurar um projeto do Linux para ter como destino um computador remoto ou o WSL (Subsistema Windows para Linux). Nos computadores remotos e no WSL no Visual Studio 2017, você precisa configurar uma conexão remota. 

## <a name="connect-to-a-remote-linux-computer"></a>Conectar-se a um computador Linux remoto

Ao compilar um projeto do C++ Linux para um sistema Linux remoto (VM ou computador físico), o código-fonte do Linux é copiado para o computador Linux remoto e, em seguida, compilado com base nas configurações do Visual Studio.

Para configurar essa conexão remota:

1. Compile o projeto pela primeira vez ou crie manualmente uma nova entrada selecionando **Ferramentas > Opções** e, em seguida, abra o nó **Plataforma Cruzada > Gerenciador de Conexão** clique no botão **Adicionar**.

   ![Gerenciador de Conexões](media/settings_connectionmanager.png)

   Em qualquer cenário, a janela **Conectar-se ao sistema remoto** será exibida.

   ![Conectar-se ao Site Remoto](media/connect.png)

1. Insira as seguintes informações:

   | Entrada | Descrição
   | ----- | ---
   | **Nome do host**           | Nome ou endereço IP do dispositivo de destino
   | **Porta**                | Porta na qual o serviço SSH está em execução, normalmente 22
   | **Nome de usuário**           | Usuário como o qual será autenticado
   | **Tipo de autenticação** | Há suporte tanto para senha quanto para chave privada
   | **Senha**            | A senha do nome de usuário inserido
   | **Arquivo de chave privada**    | Arquivo de chave privada criado para conexão ssh
   | **Frase secreta**          | Frase secreta usada com a chave privada selecionada acima

   Você pode usar uma senha ou chave de arquivo e a frase secreta para autenticação. Em muitos cenários de desenvolvimento, a autenticação de senha é suficiente. Se preferir usar um arquivo de chave pública/privada, você pode criar um novo ou [reutilizar um existente](https://security.stackexchange.com/questions/10203/reusing-private-public-keys). Atualmente, apenas chaves RSA e DSA têm suporte. 
   
   Você pode criar uma chave RSA privada seguindo estas etapas:

    1. No computador Windows, crie o par de chaves ssh com `ssh-keygen -t rsa`. Isso criará uma chave pública e uma chave privada. Por padrão, as chaves são colocadas sob `C:\Users\%USERNAME%\.ssh` com nomes `id_rsa.pub` e `id_rsa`.

    1. No Windows, copie a chave pública para o computador Linux: `scp -p C:\Users\%USERNAME%\.ssh\id_rsa.pub user@hostname`.

    1. No sistema Linux, adicione a chave à lista de chaves autorizadas (e verifique se que o arquivo tem as permissões corretas): `cat ~/id_rsa.pub >> ~/.ssh/authorized_keys; chmod 600 ~/.ssh/authorized_keys`

1. Clique no botão **conectar** para tentar uma conexão com o computador remoto. 

   Se a conexão for bem-sucedida, o Visual Studio começará a configurar o IntelliSense para usar os cabeçalhos remotos. Para saber mais, veja [IntelliSense para cabeçalhos em sistemas remotos](configure-a-linux-project.md#remote_intellisense).

   Se a conexão falhar, as caixas de entrada que precisarem ser alteradas serão destacadas em vermelho.

   ![Erro do Gerenciador de Conexões](media/settings_connectionmanagererror.png)

   Se você estiver usando arquivos de chave para autenticação, verifique se o servidor SSH do computador de destino está em execução e configurado corretamente.

   ::: moniker-end

   ::: moniker range="vs-2019"

   Vá para **Ferramentas > Opções > Plataforma Cruzada > Registro em Log** para habilitar o registro em log para ajudar a solucionar problemas de conexão:

   ![Log remoto](media/remote-logging-vs2019.png)

   Os logs incluem conexões, todos os comandos enviados para o computador remoto (texto, código de saída e tempo de execução) e toda a saída do Visual Studio para o shell. O registro em log funciona para qualquer projeto CMake de plataforma cruzada ou do Linux com base em MSBuild no Visual Studio.

   Você pode configurar a saída para ir para um arquivo ou para o painel **Log de Plataforma Cruzada** na Janela de Saída. Nos projetos Linux baseados no MSBuild, os comandos emitidos para o computador remoto pelo MSBuild não são roteados para a **Janela de Saída** porque são emitidos fora do processo. Em vez disso, eles são registrados em um arquivo com o prefixo "msbuild_".
   
## <a name="tcp-port-forwarding"></a>Encaminhamento de porta TCP

O suporte ao Linux do Visual Studio tem uma dependência do encaminhamento de porta TCP. **Rsync** e **gdbserver** serão afetados se o encaminhamento de porta TCP estiver desabilitado no seu sistema remoto. 

Rsync é usado por projetos do Linux baseados em MSBuild e projetos CMake para [Copiar cabeçalhos do seu sistema remoto para o Windows a ser usado para o IntelliSense](configure-a-linux-project.md#remote_intellisense). Se não for possível habilitar o encaminhamento de porta TCP, você poderá desabilitar o download automático de cabeçalhos remotos por meio de ferramentas > Opções > > do Gerenciador de conexões > de cabeçalhos remotos do IntelliSense Manager. Se o sistema remoto ao qual você está tentando se conectar não tiver o encaminhamento de porta TCP habilitado, você verá o erro a seguir quando o download de cabeçalhos remotos para IntelliSense for iniciado.

![Erro de cabeçalhos](media/port-forwarding-headers-error.png)

Rsync também é usado pelo suporte do CMake do Visual Studio para copiar arquivos de origem para o sistema remoto. Se não for possível habilitar o encaminhamento de porta TCP, você poderá usar o SFTP como seu método de fontes de cópia remota. O SFTP é geralmente mais lento do que o rsync, mas não tem uma dependência no encaminhamento de porta TCP. Você pode gerenciar o método de fontes de cópia remota com a propriedade remoteCopySourcesMethod no [Editor de configurações do cmake](../build/cmakesettings-reference.md#additional-settings-for-cmake-linux-projects). Se o encaminhamento de porta TCP estiver desabilitado em seu sistema remoto, você verá um erro na janela de saída CMake na primeira vez que o rsync é invocado.

![Erro de rsync](media/port-forwarding-copy-error.png)

Gdbserver pode ser usado para depuração em dispositivos inseridos. Se não for possível habilitar o encaminhamento de porta TCP, você precisará usar o gdb para todos os cenários de depuração remota. O gdb é usado por padrão durante a depuração de projetos em um sistema remoto. 

   ::: moniker-end

## <a name="connect-to-wsl"></a>Conectar ao WSL

::: moniker range="vs-2017"

No Visual Studio 2017, você se conecta à WSL usando as mesmas etapas para se conectar a um computador Linux remoto, conforme descrito anteriormente neste artigo. Use **localhost** para o **Nome do Host**.

::: moniker-end

::: moniker range="vs-2019"

Suporte nativo adicionado do Visual Studio 2019 versão 16.1 para uso de C++ com o [WSL (Subsistema Windows para Linux)](https://docs.microsoft.com/windows/wsl/about).  Isso significa que você não precisa mais adicionar uma conexão remota ou configurar o SSH para criar e depurar em sua instalação local do WSL. É possível encontrar detalhes sobre [como instalar o WSL](https://docs.microsoft.com/windows/wsl/install-win10) aqui.

Para configurar a instalação do WSL para funcionar com o Visual Studio, você precisará das seguintes ferramentas instaladas: gcc ou Clang, gdb, Make, rsync e zip. Você pode instalá-los em distribuições que usam a apt usando esse comando, que também instala o compilador g + +: 

```bash
sudo apt install g++ gdb make rsync zip
```
Para obter mais informações, consulte [baixar, instalar e configurar a carga de trabalho do Linux](download-install-and-setup-the-linux-development-workload.md).

Para configurar seu projeto para WSL, confira [Configurar um projeto do Linux](configure-a-linux-project.md) ou [Configurar um projeto do Linux CMake](cmake-linux-project.md) dependendo de qual tipo de projeto que você tem. Para seguir as instruções passo a passo para criar um aplicativo de console simples com o WSL, confira esta postagem introdutória no blog sobre [C++ com Visual Studio 2019 e o WSL (Subsistema Windows para Linux)](https://devblogs.microsoft.com/cppblog/c-with-visual-studio-2019-and-windows-subsystem-for-linux-wsl/).

::: moniker-end

## <a name="see-also"></a>Consulte também

[Configurar um projeto do Linux](configure-a-linux-project.md)<br />
[Configurar um projeto do Linux CMake](cmake-linux-project.md)<br />
[Implantar, executar e depurar o projeto do Linux](deploy-run-and-debug-your-linux-project.md)<br />
[Configurar sessões de depuração do CMake](../build/configure-cmake-debugging-sessions.md)
