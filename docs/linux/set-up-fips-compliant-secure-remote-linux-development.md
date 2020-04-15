---
title: Configurar um desenvolvimento remoto seguro em Linux em conformidade com o FIPS
description: Como configurar uma conexão criptográfica compatível com FIPS entre o Visual Studio e uma máquina Linux para desenvolvimento remoto.
ms.date: 01/17/2020
ms.openlocfilehash: 9a0e87f4ddf69bf489b52d4f83934d3279f2d085
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "76520889"
---
# <a name="set-up-fips-compliant-secure-remote-linux-development"></a>Configurar um desenvolvimento remoto seguro em Linux em conformidade com o FIPS

::: moniker range="<=vs-2017"

O suporte ao Linux está disponível no Visual Studio 2017 e posterior. O desenvolvimento do Linux remoto seguro compatível com FIPS está disponível na versão 16.5 do Visual Studio 2019 e posterior.

::: moniker-end

::: moniker range="vs-2019"

Federal Information Processing Standard (FIPS) A publicação 140-2 é um padrão do governo dos EUA para módulos criptográficos. As implementações da norma são validadas pelo NIST. O Windows [validou o suporte para módulos criptográficos compatíveis com FIPS.](/windows/security/threat-protection/fips-140-validation) No Visual Studio 2019 versão 16.5 e posterior, você pode usar uma conexão criptográfica segura compatível com FIPS ao seu sistema Linux para desenvolvimento remoto.

Veja como configurar uma conexão segura e compatível com FIPS entre o Visual Studio e seu sistema Linux remoto. Este guia é aplicável quando você constrói projetos CMake ou MSBuild Linux no Visual Studio. Este artigo é a versão compatível com FIPS das instruções de conexão em [Connect ao seu computador Linux remoto](connect-to-your-remote-linux-computer.md).

## <a name="prepare-a-fips-compliant-connection"></a>Prepare uma conexão compatível com FIPS

Alguma preparação é necessária para usar uma conexão ssh compatível com FIPS e criptograficamente segura entre o Visual Studio e seu sistema Linux remoto. Para conformidade FIPS-140-2, o Visual Studio só suporta chaves RSA.

Os exemplos neste artigo usam o Ubuntu 18.04 LTS com o servidor OpenSSH versão 7.6. No entanto, as instruções devem ser as mesmas para qualquer distro usando uma versão moderadamente recente do OpenSSH.

### <a name="to-set-up-the-ssh-server-on-the-remote-system"></a>Para configurar o servidor SSH no sistema remoto

1. No sistema Linux, instale e inicie o servidor OpenSSH:

   ```bash
   sudo apt install openssh-server
   sudo service ssh start
   ```

1. Se você quiser que o servidor ssh seja iniciado automaticamente quando o sistema for inicializado, habilite-o usando systemctl:

   ```bash
   sudo systemctl enable ssh
   ```

1. Abra */etc/ssh/sshd_config* como raiz. Editar (ou adicionar, se eles não existirem) as seguintes linhas:

   ```config
   Ciphers aes256-cbc,aes192-cbc,aes128-cbc,3des-cbc
   HostKeyAlgorithms ssh-rsa
   KexAlgorithms diffie-hellman-group-exchange-sha256,diffie-hellman-group-exchange-sha1,diffie-hellman-group14-sha1
   MACs hmac-sha2-256,hmac-sha1
   ```

   > [!NOTE]
   > ssh-rsa é o único algoritmo de chave de host compatível com FIPS VS suporta. Os algoritmos aes\*-ctr também são compatíveis com FIPS, mas a implementação no Visual Studio não é aprovada. Os algoritmos\* de troca de chaves são compatíveis com FIPS, mas o Visual Studio não os suporta.

   Você não está limitado a essas opções. Você pode configurar ssh para usar cifras adicionais, hospedar algoritmos-chave e assim por diante. Algumas outras opções de segurança `PermitRootLogin` `PasswordAuthentication`relevantes `PermitEmptyPasswords`que você pode querer considerar são , e . Para obter mais informações, consulte a página do homem para sshd_config ou o artigo [Configuração do servidor SSH](https://www.ssh.com/ssh/sshd_config).

1. Depois de salvar e fechar sshd_config, reinicie o servidor ssh para aplicar a nova configuração:

   ```bash
   sudo service ssh restart
   ```

Em seguida, você criará um par de tecla RSA no seu computador Windows. Em seguida, você vai copiar a chave pública para o sistema Linux remoto para uso por ssh.

### <a name="to-create-and-use-an-rsa-key-file"></a>Para criar e usar um arquivo-chave RSA

1. Na máquina Windows, gere um par de chaves RSA público/privado usando este comando:

   ```cmd
   ssh-keygen -t rsa -b 4096
   ```

   O comando cria uma chave pública e uma chave privada. Por padrão, as teclas são salvas para *%USERPROFILE%\\\\.ssh id_rsa* e *%USERPROFILE%\\.ssh\\id_rsa.pub*. (No Powershell, `$env:USERPROFILE` use em vez `%USERPROFILE%`da macro cmd ) Se você alterar o nome da chave, use o nome alterado nas etapas a seguir.  Recomendamos que você use uma senha para aumentar a segurança.

1. A partir do Windows, copie a chave pública para a máquina Linux:

   ```cmd
   scp %USERPROFILE%\.ssh\id_rsa.pub user@hostname:
   ```

1. No sistema Linux, adicione a chave à lista de chaves autorizadas e certifique-se de que o arquivo tenha as permissões corretas:

   ```bash
   cat ~/id_rsa.pub >> ~/.ssh/authorized_keys
   chmod 600 ~/.ssh/authorized_keys
   ```

1. Agora, você pode testar para ver se a nova chave funciona em ssh. Use-o para fazer login no Windows:

    ```cmd
    ssh -i %USERPROFILE%\.ssh\id_rsa user@hostname
    ```

Você configurou com sucesso ssh, criou e implantou chaves de criptografia e testou sua conexão. Agora você está pronto para configurar a conexão Visual Studio.

## <a name="connect-to-the-remote-system-in-visual-studio"></a>Conecte-se ao sistema remoto no Visual Studio

1. No Visual Studio, escolha **Ferramentas > Opções** na barra de menus para abrir a caixa de diálogo **Opções.** Em seguida, selecione **Cross Platform > Connection Manager** para abrir a caixa de diálogo Gerenciador de conexões.

   Se você não tiver configurado uma conexão no Visual Studio antes, quando você construir seu projeto pela primeira vez, o Visual Studio abrirá a caixa de diálogo Gerenciador de conexões para você.

1. Na caixa de diálogo Gerenciador de conexões, escolha o botão **Adicionar** para adicionar uma nova conexão.

   ![Gerenciador de Conexões](media/settings_connectionmanager.png)

   A **janela Conectar ao sistema remoto** é exibida.

   ![Conectar-se ao Site Remoto](media/connect.png)

1. Na caixa de diálogo **Conectar ao sistema remoto,** digite os detalhes de conexão da sua máquina remota.

   | Entrada | Descrição
   | ----- | ---
   | **Nome do host**           | Nome ou endereço IP do dispositivo de destino
   | **Porta**                | Porta na qual o serviço SSH está em execução, normalmente 22
   | **Nome de usuário**           | Usuário como o qual será autenticado
   | **Tipo de autenticação** | Escolha a chave privada para uma conexão compatível com FIPS
   | **Arquivo de chave privada**    | Arquivo de chave privada criado para conexão ssh
   | **Senha**          | Frase secreta usada com a chave privada selecionada acima

   Alterar o tipo de autenticação para **Chave Privada**. Digite o caminho para sua chave privada no campo **de arquivo de chave Privada.** Você pode usar o botão **Procurar** para navegar até o seu arquivo de chave privada. Em seguida, digite a senha usada para criptografar seu arquivo de chave privada no campo **Senha.**

1. Escolha o botão **Conectar** para tentar uma conexão com o computador remoto.

   Se a conexão for bem-sucedida, o Visual Studio configura o IntelliSense para usar os cabeçalhos remotos. Para saber mais, veja [IntelliSense para cabeçalhos em sistemas remotos](configure-a-linux-project.md#remote_intellisense).

   Se a conexão falhar, as caixas de entrada que precisarem ser alteradas serão destacadas em vermelho.

   ![Erro do Gerenciador de Conexões](media/settings_connectionmanagererror.png)

   Para obter mais informações sobre como solucionar problemas na sua conexão, consulte [Conecte-se ao seu computador Linux remoto](connect-to-your-remote-linux-computer.md).

## <a name="command-line-utility-for-the-connection-manager"></a>Utilitário de linha de comando para o Gerenciador de Conexões  

**Visual Studio 2019 versão 16.5 ou posterior**: ConnectionManager.exe é um utilitário de linha de comando para gerenciar conexões de desenvolvimento remoto fora do Visual Studio. É útil para tarefas como o provisionamento de uma nova máquina de desenvolvimento. Ou, você pode usá-lo para configurar o Visual Studio para integração contínua. Para exemplos e uma referência completa ao comando ConnectionManager, consulte [referência ConnectionManager](connectionmanager-reference.md).  

## <a name="optional-enable-or-disable-fips-mode"></a>Opcional: Habilitar ou desativar o modo FIPS

É possível ativar o modo FIPS globalmente no Windows.

1. Para ativar o modo FIPS, pressione **o Windows+R** para abrir a caixa de diálogo Executar e, em seguida, execute gpedit.msc.

1. Expandir **a política local de computador > configuração do computador > configurações do Windows > configurações** de segurança > políticas locais e selecionar **opções de segurança**.

1. Em **Política,** selecione **criptografia do sistema: use algoritmos compatíveis com FIPS para criptografia, hashing e assinatura**e, em seguida, **pressione Enter** para abrir sua caixa de diálogo.

1. Na guia **Configuração de configuração local,** selecione **Ativado** ou **desativado**e escolha **OK** para salvar suas alterações.

> [!WARNING]
> Ativar o modo FIPS pode fazer com que alguns aplicativos quebrem ou se comportem inesperadamente. Para obter mais informações, consulte o post no blog [Why We're Not Recommending "FIPS mode" Anymore](https://techcommunity.microsoft.com/t5/microsoft-security-baselines/why-we-8217-re-not-recommending-8220-fips-mode-8221-anymore/ba-p/701037).

## <a name="additional-resources"></a>Recursos adicionais

[Documentação da Microsoft sobre validação fips 140](/windows/security/threat-protection/fips-140-validation)

[FIPS 140-2: Requisitos de segurança para módulos criptográficos](https://csrc.nist.gov/publications/detail/fips/140/2/final) (da NIST)

[Programa de Validação de Algoritmos Criptográficos: Notas](https://csrc.nist.gov/projects/cryptographic-algorithm-validation-program/Validation-Notes) de Validação (da NIST)

Post no blog da Microsoft sobre [por que não estamos recomendando o "modo FIPS" mais](https://techcommunity.microsoft.com/t5/microsoft-security-baselines/why-we-8217-re-not-recommending-8220-fips-mode-8221-anymore/ba-p/701037)

[Configuração do servidor SSH](https://www.ssh.com/ssh/sshd_config)

## <a name="see-also"></a>Consulte Também

[Configure um projeto Linux](configure-a-linux-project.md)\
[Configure um projeto Linux CMake](cmake-linux-project.md)\
[Conecte-se ao seu computador Linux remoto](connect-to-your-remote-linux-computer.md)\
[Implantar, executar e depurar seu projeto Linux](deploy-run-and-debug-your-linux-project.md)\
[Configurar sessões de depuração do CMake](../build/configure-cmake-debugging-sessions.md)

::: moniker-end
