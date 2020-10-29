---
title: Configurar um desenvolvimento remoto seguro em Linux em conformidade com o FIPS
description: Como configurar uma conexão criptográfica compatível com FIPS entre o Visual Studio e um computador Linux para desenvolvimento remoto.
ms.date: 01/17/2020
ms.openlocfilehash: b7eb6bfd32d362415eda057bfa78afe80fb9e2f4
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92924691"
---
# <a name="set-up-fips-compliant-secure-remote-linux-development"></a>Configurar um desenvolvimento remoto seguro em Linux em conformidade com o FIPS

::: moniker range="<=msvc-150"

O suporte ao Linux está disponível no Visual Studio 2017 e posterior. O desenvolvimento de Linux remoto seguro em conformidade com FIPS está disponível no Visual Studio 2019 versão 16,5 e posterior.

::: moniker-end

::: moniker range="msvc-160"

A publicação 140-2 do padrão FIPS (FIPS) é um padrão governamental dos EUA para módulos criptográficos. As implementações do padrão são validadas pelo NIST. O Windows [validou o suporte para módulos de criptografia compatíveis com FIPS](/windows/security/threat-protection/fips-140-validation). No Visual Studio 2019 versão 16,5 e posterior, você pode usar uma conexão criptográfica segura e compatível com FIPS para seu sistema Linux para desenvolvimento remoto.

Veja como configurar uma conexão segura e compatível com o FIPS entre o Visual Studio e seu sistema Linux remoto. Este guia é aplicável quando você cria projetos CMake ou MSBuild do Linux no Visual Studio. Este artigo é a versão compatível com FIPS das instruções de conexão em [conectar-se ao computador Linux remoto](connect-to-your-remote-linux-computer.md).

## <a name="prepare-a-fips-compliant-connection"></a>Preparar uma conexão compatível com FIPS

Alguma preparação é necessária para usar uma conexão SSH segura e criptograficamente compatível com FIPS entre o Visual Studio e seu sistema Linux remoto. Para conformidade com FIPS-140-2, o Visual Studio dá suporte apenas a chaves RSA.

Os exemplos neste artigo usam o Ubuntu 18, 4 LTS com o servidor OpenSSH versão 7,6. No entanto, as instruções devem ser as mesmas para qualquer distribuição usando uma versão moderadamente recente do OpenSSH.

### <a name="to-set-up-the-ssh-server-on-the-remote-system"></a>Para configurar o servidor SSH no sistema remoto

1. No sistema Linux, instale e inicie o servidor OpenSSH:

   ```bash
   sudo apt install openssh-server
   sudo service ssh start
   ```

1. Se você quiser que o servidor SSH seja iniciado automaticamente quando o sistema for inicializado, habilite-o usando systemctl:

   ```bash
   sudo systemctl enable ssh
   ```

1. Abra */etc/ssh/sshd_config* como raiz. Edite (ou adicione, se eles não existirem) as seguintes linhas:

   ```config
   Ciphers aes256-cbc,aes192-cbc,aes128-cbc,3des-cbc
   HostKeyAlgorithms ssh-rsa
   KexAlgorithms diffie-hellman-group-exchange-sha256,diffie-hellman-group-exchange-sha1,diffie-hellman-group14-sha1
   MACs hmac-sha2-256,hmac-sha1
   ```

   > [!NOTE]
   > SSH-RSA é o único algoritmo de chave de host compatível com FIPS versus suporta. Os \* Algoritmos AES-CTR também são compatíveis com FIPS, mas a implementação no Visual Studio não é aprovada. Os \* algoritmos de troca de chave ECDH são compatíveis com FIPS, mas o Visual Studio não dá suporte a eles.

   Você não está limitado a essas opções. Você pode configurar o ssh para usar codificações adicionais, algoritmos de chave de host e assim por diante. Algumas outras opções de segurança relevantes que talvez você queira considerar são `PermitRootLogin` , `PasswordAuthentication` e `PermitEmptyPasswords` . Para obter mais informações, consulte a página do manual para sshd_config ou o artigo [configuração do servidor SSH](https://www.ssh.com/ssh/sshd_config).

1. Depois de salvar e fechar sshd_config, reinicie o servidor SSH para aplicar a nova configuração:

   ```bash
   sudo service ssh restart
   ```

Em seguida, você criará um par de chaves RSA no computador com Windows. Em seguida, você copiará a chave pública para o sistema Linux remoto para uso pelo SSH.

### <a name="to-create-and-use-an-rsa-key-file"></a>Para criar e usar um arquivo de chave RSA

1. No computador com Windows, gere um par de chaves RSA pública/privada usando este comando:

   ```cmd
   ssh-keygen -t rsa -b 4096
   ```

   O comando cria uma chave pública e uma chave privada. Por padrão, as chaves são salvas em *% USERPROFILE% \\ . ssh \\ Id_rsa* e *% USERPROFILE% \\ . ssh \\ id_rsa. pub* . (No PowerShell, use `$env:USERPROFILE` em vez da macro cmd `%USERPROFILE%` ) se você alterar o nome da chave, use o nome alterado nas etapas a seguir.  Recomendamos que você use uma senha para aumentar a segurança.

1. No Windows, copie a chave pública para o computador Linux:

   ```cmd
   scp %USERPROFILE%\.ssh\id_rsa.pub user@hostname:
   ```

1. No sistema Linux, adicione a chave à lista de chaves autorizadas e verifique se o arquivo tem as permissões corretas:

   ```bash
   cat ~/id_rsa.pub >> ~/.ssh/authorized_keys
   chmod 600 ~/.ssh/authorized_keys
   ```

1. Agora, você pode testar para ver se a nova chave funciona no ssh. Use-o para entrar no Windows:

    ```cmd
    ssh -i %USERPROFILE%\.ssh\id_rsa user@hostname
    ```

Você configurou com êxito as chaves de criptografia SSH, criadas e implantadas e testou sua conexão. Agora você está pronto para configurar a conexão do Visual Studio.

## <a name="connect-to-the-remote-system-in-visual-studio"></a>Conectar-se ao sistema remoto no Visual Studio

1. No Visual Studio, escolha **ferramentas > opções** na barra de menus para abrir a caixa de diálogo **Opções** . Em seguida, selecione a **plataforma cruzada > Gerenciador de conexões** para abrir a caixa de diálogo Gerenciador de conexões.

   Se você ainda não configurou uma conexão no Visual Studio antes, quando você cria seu projeto pela primeira vez, o Visual Studio abre a caixa de diálogo Gerenciador de conexões para você.

1. Na caixa de diálogo Gerenciador de conexões, escolha o botão **Adicionar** para adicionar uma nova conexão.

   ![Gerenciador de Conexões](media/settings_connectionmanager.png)

   A janela **conectar ao sistema remoto** é exibida.

   ![Conectar-se ao Site Remoto](media/connect.png)

1. Na caixa de diálogo **conectar ao sistema remoto** , insira os detalhes de conexão do computador remoto.

   | Entrada | Descrição
   | ----- | ---
   | **Nome do Host**           | Nome ou endereço IP do dispositivo de destino
   | **Porta**                | Porta na qual o serviço SSH está em execução, normalmente 22
   | **Nome de usuário**           | Usuário como o qual será autenticado
   | **Tipo de autenticação** | Escolha a chave privada para uma conexão compatível com FIPS
   | **Arquivo de chave privada**    | Arquivo de chave privada criado para conexão ssh
   | **Senha**          | Frase secreta usada com a chave privada selecionada acima

   Altere o tipo de autenticação para **chave privada** . Insira o caminho para sua chave privada no campo **arquivo de chave privada** . Você pode usar o botão **procurar** para navegar até o arquivo de chave privada. Em seguida, digite a senha usada para criptografar o arquivo de chave privada no campo **senha** .

1. Escolha o botão **conectar** para tentar uma conexão com o computador remoto.

   Se a conexão for realizada com sucesso, o Visual Studio configurará o IntelliSense para usar os cabeçalhos remotos. Para saber mais, veja [IntelliSense para cabeçalhos em sistemas remotos](configure-a-linux-project.md#remote_intellisense).

   Se a conexão falhar, as caixas de entrada que precisarem ser alteradas serão destacadas em vermelho.

   ![Erro do Gerenciador de Conexões](media/settings_connectionmanagererror.png)

   Para obter mais informações sobre como solucionar problemas de conexão, consulte [conectar-se ao computador Linux remoto](connect-to-your-remote-linux-computer.md).

## <a name="command-line-utility-for-the-connection-manager"></a>Utilitário de linha de comando para o Gerenciador de conexões  

**Visual studio 2019 versão 16,5 ou posterior** : ConnectionManager.exe é um utilitário de linha de comando para gerenciar conexões de desenvolvimento remoto fora do Visual Studio. Ele é útil para tarefas como o provisionamento de uma nova máquina de desenvolvimento. Ou você pode usá-lo para configurar o Visual Studio para integração contínua. Para obter exemplos e uma referência completa ao comando ConnectionManager, consulte [referência de ConnectionManager](connectionmanager-reference.md).  

## <a name="optional-enable-or-disable-fips-mode"></a>Opcional: habilitar ou desabilitar o modo FIPS

É possível habilitar o modo FIPS globalmente no Windows.

1. Para habilitar o modo FIPS, pressione **Windows + R** para abrir a caixa de diálogo Executar e, em seguida, execute gpedit. msc.

1. Expanda **política de computador Local > configuração do computador > configurações do Windows > configurações de segurança > políticas locais** e selecione **Opções de segurança** .

1. Em **política** , selecione **criptografia do sistema: Use algoritmos compatíveis com FIPS para criptografia, hash e assinatura** e pressione **Enter** para abrir sua caixa de diálogo.

1. Na guia **configuração de segurança local** , selecione **habilitado** ou **desabilitado** e escolha **OK** para salvar as alterações.

> [!WARNING]
> Habilitar o modo FIPS pode fazer com que alguns aplicativos sejam interrompidos ou se comportem inesperadamente. Para obter mais informações, consulte a postagem de blog [por que não estamos mais recomendando o "modo FIPS"](https://techcommunity.microsoft.com/t5/microsoft-security-baselines/why-we-8217-re-not-recommending-8220-fips-mode-8221-anymore/ba-p/701037).

## <a name="additional-resources"></a>Recursos adicionais

[Documentação da Microsoft sobre a validação do FIPS 140](/windows/security/threat-protection/fips-140-validation)

[FIPS 140-2: requisitos de segurança para módulos de criptografia](https://csrc.nist.gov/publications/detail/fips/140/2/final) (do NIST)

[Programa de validação do algoritmo criptográfico: notas de validação](https://csrc.nist.gov/projects/cryptographic-algorithm-validation-program/Validation-Notes) (do NIST)

Postagem no blog da Microsoft sobre o [porquê não estamos recomendando mais "modo FIPS"](https://techcommunity.microsoft.com/t5/microsoft-security-baselines/why-we-8217-re-not-recommending-8220-fips-mode-8221-anymore/ba-p/701037)

[Configuração do servidor SSH](https://www.ssh.com/ssh/sshd_config)

## <a name="see-also"></a>Consulte Também

[Configurar um projeto do Linux](configure-a-linux-project.md)\
[Configurar um projeto CMake do Linux](cmake-linux-project.md)\
[Conectar-se ao computador Linux remoto](connect-to-your-remote-linux-computer.md)\
[Implante, execute e depure seu projeto do Linux](deploy-run-and-debug-your-linux-project.md)\
[Configurar sessões de depuração do CMake](../build/configure-cmake-debugging-sessions.md)

::: moniker-end
