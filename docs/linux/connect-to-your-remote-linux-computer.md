---
title: Conectar-se a seu sistema Linux de destino no Visual Studio
description: Como se conectar a um computador Linux remoto ou WSL de dentro de um projeto do Visual Studio C++.
ms.date: 06/19/2019
ms.assetid: 5eeaa683-4e63-4c46-99ef-2d5f294040d4
ms.openlocfilehash: 7fa09c49df3da39084edb6735a7a2ccc724c34d3
ms.sourcegitcommit: 3ae8025df7fd50f5f56a0a2b5396533218bcc7dc
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/20/2019
ms.locfileid: "67285256"
---
# <a name="connect-to-your-target-linux-system-in-visual-studio"></a>Conectar-se a seu sistema Linux de destino no Visual Studio

::: moniker range="vs-2015"

O suporte ao Linux está disponível no Visual Studio 2017 e posterior.

::: moniker-end

::: moniker range=">=vs-2017"

Configure um projeto do Linux para ter como destino um computador remoto ou o WSL (Subsistema do Windows para Linux). Nos computadores remotos e no WSL no Visual Studio 2017, você precisa configurar uma conexão. 

## <a name="connect-to-a-remote-linux-computer"></a>Conectar-se a um computador Linux remoto

Ao compilar um projeto do C++ Linux para um sistema Linux remoto (VM ou computador físico), o código do Linux é copiado para o computador Linux remoto e, em seguida, compilado com base nas configurações do Visual Studio.

Para configurar essa conexão remota:

1. Compile o projeto pela primeira vez ou crie manualmente uma nova entrada selecionando **Ferramentas > Opções** e, em seguida, abra o nó **Plataforma Cruzada > Gerenciador de Conexão** clique no botão **Adicionar**.

   ![Gerenciador de Conexões](media/settings_connectionmanager.png)

   Em qualquer cenário, a janela **Conectar-se ao sistema remoto** será exibida.

   ![Conectar-se ao Site Remoto](media/connect.png)

1. Insira as seguintes informações:

   | Entrada | DESCRIÇÃO
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

   ::: moniker-end

## <a name="connect-to-wsl"></a>Conectar ao WSL

::: moniker range="vs-2017"

No Visual Studio 2017, você se conecta à WSL usando as mesmas etapas para se conectar a um computador Linux remoto, conforme descrito anteriormente neste artigo. Use **localhost** para o **Nome do Host**.

::: moniker-end

::: moniker range="vs-2019"

No Visual Studio 2019 versão 16.1, não é necessário adicionar uma conexão remota ou configurar o SSH quando o destino é o WSL. Tudo o que é necessário no sistema Linux é gdb, gcc, make, rsync e zip. O Visual Studio requer rsync e zip somente para extrair os arquivos de cabeçalho no primeiro uso da sua instância WSL para o sistema de arquivos do Windows usar no IntelliSense. No Visual Studio 2019 versão 16.1, suporte WSL é baseado no Windows versão 1809. Você pode estar executando uma versão posterior do Windows, mas o Visual Studio ainda não aproveita os novos recursos WSL.

Se a sua distribuição dá suporte a apt, você pode instalar os pacotes necessários com este comando:

```bash
sudo apt install g++ gdb make rsync zip
```

Para configurar seu projeto para WSL, confira [Configurar um projeto do Linux](configure-a-linux-project.md) ou [Configurar um projeto do Linux CMake](cmake-linux-project.md) dependendo de qual tipo de projeto que você tem.

::: moniker-end

## <a name="see-also"></a>Veja também

[Configurar um projeto do Linux](configure-a-linux-project.md)<br />
[Configurar um projeto do Linux CMake](cmake-linux-project.md)<br />
[Implantar, executar e depurar o projeto do Linux](deploy-run-and-debug-your-linux-project.md)<br />




