---
title: Instalar e configurar ferramentas de build usando o iOS
ms.date: 10/17/2019
ms.assetid: d0c311c9-9eb9-42c5-ba07-25604362cd28
ms.openlocfilehash: 26dea080f3d3f05885f348dcaf1c66a0db2a36b5
ms.sourcegitcommit: 6280a4c629de0f638ebc2edd446de2a9b11f0406
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2020
ms.locfileid: "90041985"
---
# <a name="install-and-configure-tools-to-build-using-ios"></a>Instalar e configurar ferramentas de build usando o iOS

Você pode usar o Visual Studio com o **desenvolvimento móvel** de plataforma cruzada com ferramentas C++ para editar, depurar e implantar o código Ios no simulador do Ios ou em um dispositivo IOS. Mas, devido a restrições de licenciamento, o código deve ser compilado e executado remotamente em um Mac. Para compilar e executar aplicativos iOS usando o Visual Studio, é necessário instalar e configurar o agente remoto, [vcremote](https://www.npmjs.com/package/vcremote), no Mac. O agente remoto trata de solicitações de build do Visual Studio e executa o aplicativo em um dispositivo iOS conectado ao Mac, ou no Simulator de iOS no Mac.

> [!NOTE]
> Para saber mais sobre como usar os serviços hospedados em nuvem do Mac, em vez de um Mac, confira [Configurar o Visual Studio para se conectar ao seu Mac hospedado na nuvem](/visualstudio/cross-platform/tools-for-cordova/tips-workarounds/host-a-mac-in-the-cloud?view=toolsforcordova-2017&preserve-view=true#configure-visual-studio-to-connect-to-your-cloud-hosted-mac). As instruções são para compilação usando as Ferramentas do Visual Studio para Apache Cordova. Para usar as instruções para criar usando o C++, substitua `vcremote` por `remotebuild` .

Depois de instalar as ferramentas para criar usando o iOS, consulte este artigo para obter maneiras de configurar e atualizar rapidamente o agente remoto para o desenvolvimento do iOS no Visual Studio e no seu Mac.

## <a name="prerequisites"></a>Pré-requisitos

Para instalar e usar o agente remoto para desenvolver código para iOS, é necessário primeiro ter estes pré-requisitos:

- Um computador Mac executando macOS Mojave versão 10.14 ou posterior

- Uma [ID da Apple](https://appleid.apple.com/)

- Uma conta do [Programa de Desenvolvedor da Apple](https://developer.apple.com/programs/) ativa

   Você pode obter uma conta gratuita que permita aplicativos de sideload para um dispositivo iOS somente para teste, mas não para distribuição.

- [Xcode](https://developer.apple.com/xcode/downloads/) versão 10.2.1 ou posterior

   O Xcode pode ser baixado da App Store.

- Ferramentas de linha de comando do Xcode

   Para instalar as ferramentas de linha de comando do Xcode, abra o aplicativo terminal em seu Mac e insira o seguinte comando:

   `xcode-select --install`

- Uma conta de ID da Apple configurada no Xcode como uma identidade de assinatura para assinar aplicativos

   Para ver ou definir a identidade de assinatura no Xcode, abra o menu do **Xcode** e escolha **Preferences** (Preferências). Selecione **Accounts** (Contas) e escolha sua Apple ID e, em seguida, escolha o botão **View Details** (Exibir Detalhes). Veja [Adicionar sua conta de ID da Apple](https://help.apple.com/xcode/mac/current/#/devaf282080a) para obter instruções detalhadas.

   Para obter informações detalhadas sobre requisitos de assinatura, consulte [O que é a assinatura de aplicativo](https://help.apple.com/xcode/mac/current/#/dev3a05256b8).

- Se estiver usando um dispositivo iOS para desenvolvimento, use um Perfil de provisionamento configurado no Xcode para seu dispositivo

   O Xcode fornece a assinatura automática na qual ele cria certificados de autenticação conforme necessário. Para obter informações detalhadas sobre a assinatura automática do Xcode, consulte [assinatura automática](https://help.apple.com/xcode/mac/current/#/dev80cc24546).

   Se quiser fazer a assinatura manual, você precisará criar um perfil de provisionamento para seu aplicativo. Para obter informações detalhadas sobre como criar Perfis de provisionamento, consulte [Criar um perfil de provisionamento de desenvolvimento](https://help.apple.com/developer-account/#/devf2eb157f8).

- [Node.js](https://nodejs.org/) versão 12.14.1 e NPM versão 6.13.4

   Instale a versão 12.14.1 do Node.js no seu Mac. Se você instalar o pacote de Node.js, ele deverá vir com o NPM versão 6.13.4. Outras versões do Node.js e do NPM podem não dar suporte a alguns módulos usados no agente remoto `vcremote` , o que pode causar `vcremote` falha na instalação. Recomendamos que você instale Node.js usando um Gerenciador de pacotes, como o [node versão Manager](https://nodejs.org/en/download/package-manager/#nvm). Evite usar o comando `sudo` para instalar o Node.js, pois alguns módulos podem falhar ao serem instalados ao usar o `sudo` .

## <a name="install-the-remote-agent-for-ios"></a><a name="Install"></a> Instalar o agente remoto para iOS

Quando você instala o desenvolvimento móvel com carga de trabalho C++, o Visual Studio pode se comunicar com o [vcremote](https://www.npmjs.com/package/vcremote), um agente remoto em execução no seu Mac para transferir arquivos, compilar e executar seu aplicativo Ios e enviar comandos de depuração.

Antes de instalar o agente remoto, verifique se você satisfez os [pré-requisitos](#prerequisites) e concluiu as etapas de instalação em [instalar o desenvolvimento móvel de plataforma cruzada com o C++](../cross-platform/install-visual-cpp-for-cross-platform-mobile-development.md#install-the-tools).

### <a name="to-download-and-install-the-remote-agent"></a><a name="DownloadInstall"></a> Para baixar e instalar o agente remoto

- No aplicativo de terminal no seu Mac, verifique se a versão Node.js atualmente em uso é a versão necessária 12.14.1. Para verificar a versão, execute o comando:

  `node -v`
  
  Se não for a versão correta, talvez seja necessário seguir as instruções de instalação do Node.js nos pré-requisitos. Em seguida, reinicie o Node.js.

- Depois de verificar se o Node.js necessário está em uso, execute este comando para instalar o vcremote nessa versão do Node.js:

   `npm install -g --unsafe-perm vcremote`

   A opção de instalação global (**-g**) é recomendada, mas não é necessária. Se você não usar a opção de instalação global, o vcremote será instalado no caminho ativo atual no aplicativo de terminal.

   Durante a instalação, o `vcremote` é instalado e o modo de desenvolvedor é ativado no seu Mac. [Homebrew](https://brew.sh/) e dois pacotes NPM, `vcremote-lib` e `vcremote-utils` também são instalados. Após a conclusão da instalação, ignore os avisos sobre dependências opcionais ignoradas.

   > [!NOTE]
   > Para instalar o Homebrew, você deve ter acesso sudo (administrador). Se precisar instalar `vcremote` o sem sudo, você poderá instalar o Homebrew manualmente em um local usr/local e adicionar sua pasta bin ao seu caminho. Para obter mais informações, consulte a [Documentação do Homebrew](https://github.com/Homebrew/homebrew/wiki/Installation). Para habilitar manualmente o modo de desenvolvedor, digite este comando no aplicativo Terminal: `DevToolsSecurity -enable`

Se atualizar para uma nova versão do Visual Studio, você também deverá atualizar para a versão atual do agente remoto. Para atualizar o agente remoto, repita as etapas para baixar e instalá-lo.

## <a name="start-the-remote-agent"></a><a name="Start"></a> Iniciar o agente remoto

O agente remoto deve estar em execução para o Visual Studio compilar e executar seu código do iOS. O Visual Studio deve ser emparelhado ao agente remoto antes que possa se comunicar. Por padrão, o agente remoto é executado no modo de conexão segura, o que requer um PIN para emparelhar ao Visual Studio.

### <a name="to-start-the-remote-agent"></a><a name="RemoteAgentStartServer"></a> Para iniciar o agente remoto

- No aplicativo Terminal no seu Mac, insira:

   `vcremote`

   Esse comando inicia o agente remoto com um diretório de compilação padrão do `~/vcremote` . Para ver opções de configuração adicionais, consulte [Configurar o agente remoto no Mac](#ConfigureMac).

Na primeira vez que você iniciar o agente e sempre que criar um novo certificado de cliente, você receberá as informações necessárias para configurar o agente no Visual Studio, incluindo o nome do host, a porta e o PIN.

![Usar o vcremote para gerar um PIN seguro](../cross-platform/media/cppmdd-vcremote-generateclientcert.png "Usar o vcremote para gerar um PIN seguro")

Se você pretende configurar o agente remoto no Visual Studio usando o nome do host, execute o ping para o Mac do Windows usando o nome de host para verificar se ele está acessível. Caso contrário, poderá ser necessário usar o endereço IP em vez disso.

O PIN gerado é de uso único e só é válido por um período limitado. Se você não emparelhar o Visual Studio ao agente remoto antes desse período expirar, será necessário gerar um novo PIN. Para obter mais informações, consulte [Gerar um novo PIN de segurança](#GeneratePIN).

É possível usar o agente remoto no modo desprotegido. No modo desprotegido, o agente remoto pode ser emparelhado ao Visual Studio sem um PIN.

#### <a name="to-disable-secured-connection-mode"></a>Para desabilitar o modo de conexão segura

- Para desabilitar o modo de conexão segura no `vcremote` , digite este comando no aplicativo de terminal em seu Mac:

   `vcremote --secure false`

#### <a name="to-enable-secured-connection-mode"></a>Para habilitar o modo de conexão segura

- Para habilitar o modo de conexão segura, digite este comando:

   `vcremote --secure true`

Depois de iniciar o agente remoto, você pode usá-lo no Visual Studio até pará-lo.

#### <a name="to-stop-the-remote-agent"></a>Para parar o agente remoto

- Na janela do terminal `vcremote` está em execução no, digite o **controle** + **C**.

## <a name="configure-the-remote-agent-in-visual-studio"></a><a name="ConfigureVS"></a> Configurar o agente remoto no Visual Studio

Para se conectar ao agente remoto do Visual Studio, você deve especificar a configuração remota nas opções do Visual Studio.

### <a name="to-configure-the-remote-agent-from-visual-studio"></a>Para configurar o agente remoto do Visual Studio

1. Se o agente não estiver sendo executado no Mac, siga as etapas em [Iniciar o agente remoto](#Start). Seu Mac deve estar em execução para que o `vcremote` Visual Studio Emparelhe, conecte e compile seu projeto com êxito.

1. No Mac, obtenha o nome do host ou o endereço IP do seu Mac.

   É possível obter o endereço IP usando o comando **ifconfig** em uma janela do Terminal. Use o endereço inet listado no adaptador de rede ativo.

1. Na barra de menus do Visual Studio, escolha **Ferramentas**, **Opções**.

1. Na caixa de diálogo **Opções**, expanda **Multiplataforma**, **C++**, **iOS**.

1. Nos campos **Nome do Host** e **Porta**, insira os valores especificados pelo agente remoto quando você o iniciou. O nome do host pode ser o nome DNS ou o endereço IP do seu Mac. A porta padrão é a 3030.

   > [!NOTE]
   > Se não puder executar ping do Mac usando o nome do host, você precisará usar o endereço IP.

1. Se você usar o agente remoto no modo de conexão segura padrão, marque a caixa de seleção **Seguro** e insira o valor do PIN especificado pelo agente remoto no campo **Pin**. Se você usar o agente remoto no modo de conexão não segura, desmarque a caixa de seleção **Seguro** e deixe o campo **Pin** em branco.

1. Escolha **Emparelhamento** para habilitar o emparelhamento.

   ![Configurar conexão vcremote para compilações do iOS](../cross-platform/media/cppmdd-options-ios.png "Configurar conexão vcremote para compilações do iOS")

   O emparelhamento persiste até que você altere o nome do host ou a porta. Se você alterar o nome do host ou a porta na caixa de diálogo **Opções**, para desfazer a alteração, escolha o botão **Reverter** para reverter o emparelhamento anterior.

   Se o emparelhamento não for bem-sucedido, verifique se o agente remoto está em execução seguindo as etapas em [Iniciar o agente remoto](#Start). Se muito tempo tiver decorrido desde que o PIN do agente remoto foi gerado, siga as etapas em [Gerar um novo PIN de segurança](#GeneratePIN) no Mac e tente novamente. Se você estiver usando o nome de host do seu Mac, tente usar o endereço IP no campo **Nome do Host** em vez disso.

1. Atualize o nome da pasta no campo **Raiz Remota** para especificar a pasta usada pelo agente remoto no diretório base (*~*) no Mac. Por padrão, o agente remoto usa `/Users/<username>/vcremote` como a raiz remota.

1. Escolha **OK** para salvar as configurações de conexão de emparelhamento remoto.

O Visual Studio usa as mesmas informações para se conectar ao agente remoto no seu Mac sempre que você usá-lo. Você não precisa emparelhar o Visual Studio ao agente remoto novamente a menos que gere um novo certificado de segurança no Mac ou que seu nome de host ou endereço IP seja alterado.

## <a name="generate-a-new-security-pin"></a><a name="GeneratePIN"></a> Gerar um novo PIN de segurança

Quando você inicia o agente remoto pela primeira vez, o PIN gerado é válido por um período limitado — por padrão, 10 minutos. Se você não emparelhar o Visual Studio ao agente remoto antes desse período expirar, será necessário gerar um novo PIN.

### <a name="to-generate-a-new-pin"></a>Para gerar um novo PIN

1. Pare o agente ou abra uma segunda janela do aplicativo Terminal no Mac e use-a para inserir o comando.

1. Digite este comando no aplicativo Terminal:

   `vcremote generateClientCert`

   O agente remoto gera um novo PIN temporário. Para emparelhar o Visual Studio usando o novo PIN, repita as etapas em [Configurar o agente remoto no Visual Studio](#ConfigureVS).

## <a name="generate-a-new-server-certificate"></a><a name="GenerateCert"></a> Gerar um novo certificado do servidor

Por motivos de segurança, os certificados de servidor que emparelham o Visual Studio ao agente remoto estão vinculados ao nome de host ou ao endereço IP do seu Mac. Se esses valores forem alterados, você precisará gerar um novo certificado do servidor e reconfigurar o Visual Studio com os novos valores.

### <a name="to-generate-a-new-server-certificate"></a>Para gerar um novo certificado do servidor

1. Pare o `vcremote` agente.

1. Digite este comando no aplicativo Terminal:

   `vcremote resetServerCert`

1. Quando for solicitado a confirmar, digite `Y`.

1. Digite este comando no aplicativo Terminal:

   `vcremote generateClientCert`

   Esse comando gera um novo PIN temporário.

1. Para emparelhar o Visual Studio usando o novo PIN, repita as etapas em [Configurar o agente remoto no Visual Studio](#ConfigureVS).

## <a name="configure-the-remote-agent-on-the-mac"></a><a name="ConfigureMac"></a> Configurar o agente remoto no Mac

Você pode configurar o agente remoto usando várias opções de linha de comando. Por exemplo, você pode especificar a porta para escutar solicitações de compilação e especificar o número máximo de compilações a serem mantidas no sistema de arquivos. Por padrão, o limite é de 10 compilações. O agente remoto removerá as compilações que ultrapassarem o máximo no desligamento.

### <a name="to-configure-the-remote-agent"></a>Para atualizar o agente remoto

- Para ver uma lista completa dos comandos do agente remoto, no aplicativo Terminal, digite:

   `vcremote --help`

- Para desabilitar o modo de segurança e habilitar conexões simples baseadas em HTTP, digite:

   `vcremote --secure false`

   Quando usar essa opção, desmarque a caixa de segurança **Seguro** e deixe o campo **Pin** em branco ao configurar o agente no Visual Studio.

- Para especificar um local para arquivos de agente remoto, digite:

   `vcremote --serverDir directory_path`

   em que *directory_path* é o local no seu Mac para colocar os arquivos de log, compilações e certificados de servidor. Por padrão, esse local é `/Users/<username>/vcremote` . As compilações são organizadas por número de build nesse local.

- Para usar um processo em segundo plano para capturar `stdout` e `stderr` para um arquivo chamado server.log, digite:

   `vcremote > server.log 2>&1 &`

   O arquivo server.log pode ajudar na solução de problemas de build.

- Para executar o agente usando um arquivo de configuração em vez de parâmetros de linha de comando, digite:

   `vcremote --config config_file_path`

   em que *config_file_path* é o caminho para um arquivo de configuração no formato JSON. As opções de inicialização e seus valores não devem incluir traços.

## <a name="troubleshoot-the-remote-agent"></a>Solucionar problemas de agente remoto

### <a name="debugging-on-an-ios-device"></a>Depuração em um dispositivo iOS

Se a depuração em um dispositivo iOS não funcionar, poderá haver problemas com a ferramenta [ideviceinstaller](https://github.com/libimobiledevice/ideviceinstaller), que é usada para comunicação com um dispositivo iOS. Essa ferramenta é normalmente instalada a partir do Homebrew durante a instalação do `vcremote` . Siga as etapas abaixo para solucionar esse problema.

Abra o aplicativo de terminal e atualize `ideviceinstaller` e suas dependências executando os seguintes comandos na ordem:

1. Verifique se o Homebrew está atualizado

   `brew update`

1. Desinstalar `libimobiledevice` e `usbmuxd`

   `brew uninstall --ignore-dependencies libimobiledevice`

   `brew uninstall --ignore-dependencies usbmuxd`

1. Instale a versão mais recente do `libimobiledevice` e `usbmuxd`

   `brew install --HEAD usbmuxd`

   `brew unlink usbmuxd`

   `brew link usbmuxd`

   `brew install --HEAD libimobiledevice`

1. Desinstalar e reinstalar `ideviceinstaller`

   `brew uninstall ideviceinstaller`

   `brew install ideviceinstaller`

Verifique se `ideviceinstaller` o pode se comunicar com o dispositivo ao tentar listar os aplicativos instalados no dispositivo:

`ideviceinstaller -l`

Se os `ideviceinstaller` erros que não podem acessar a pasta `/var/db/lockdown` , altere o privilégio na pasta com:

`sudo chmod 777 /var/db/lockdown`

Em seguida, verifique novamente se o `ideviceinstaller` pode se comunicar com o dispositivo.

## <a name="see-also"></a>Confira também

- [Instalar desenvolvimento de tecnologia móvel multiplataforma com C++](../cross-platform/install-visual-cpp-for-cross-platform-mobile-development.md)
