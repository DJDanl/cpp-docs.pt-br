---
title: Criar um aplicativo OpenGL ES no Android e iOS
ms.date: 10/09/2019
ms.assetid: 76a67886-df57-4a81-accb-2e3c2eaf607b
ms.openlocfilehash: 278fd66202332417f7663542f0d66a3ec545b715
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92924295"
---
# <a name="build-an-opengl-es-application-on-android-and-ios"></a>Criar um aplicativo OpenGL ES no Android e iOS

Você pode criar soluções e projetos do Visual Studio para aplicativos iOS e Android que compartilhem código comum. Este artigo o orienta por meio de um modelo de solução combinado. Ele cria um aplicativo iOS e um aplicativo de atividade nativa do Android. Os aplicativos têm código C++ em comum que usa o OpenGL ES para exibir o mesmo cubo de rotação animado em cada plataforma. OpenGL ES (OpenGL para sistemas inseridos ou GLES) é uma API gráfica 2D e 3D. Há suporte em muitos dispositivos móveis.

## <a name="requirements"></a>Requisitos

Atenda a todos os requisitos de sistema para criar um aplicativo OpenGL ES para iOS e Android. Se este não for o caso, instale a carga de trabalho do Desenvolvimento Móvel com C++ no Instalador do Visual Studio. Para obter os modelos OpenGL ES e para compilar para o iOS, inclua as ferramentas de desenvolvimento do C++ iOS opcionais. Para compilar para Android, instale as ferramentas de desenvolvimento C++ Android e as ferramentas de terceiros necessárias: Android NDK, Apache Ant e Google Android Emulator.

Para obter melhor desempenho do emulador em plataformas Intel, uma opção é instalar o Intel Hardware Accelerated Execution Manager (HAXM). Para obter instruções detalhadas, consulte [instalar o desenvolvimento móvel de plataforma cruzada com C++](../cross-platform/install-visual-cpp-for-cross-platform-mobile-development.md).

Para compilar e testar o aplicativo iOS, você precisará de um computador Mac. Configure-o de acordo com as instruções de instalação. Para saber mais sobre como configurar para desenvolvimento no iOS, confira [Instalar e configurar ferramentas para criação usando o iOS](../cross-platform/install-and-configure-tools-to-build-using-ios.md).

## <a name="create-a-new-opengles-application-project"></a>Criar um projeto de aplicativo OpenGLES

Neste tutorial, você primeiro cria um novo projeto de aplicativo OpenGL ES. e, em seguida, compilar e executar o aplicativo padrão em um emulador do Android. Em seguida, você cria o aplicativo para iOS e executa o aplicativo em um dispositivo iOS.

::: moniker range="msvc-150"

1. No Visual Studio, escolha **Arquivo** > **Novo** > **Projeto** .

1. Na caixa de diálogo **Novo Projeto** , em **Modelos** , escolha **Visual C++** > **Multiplataforma** e, em seguida, escolha o modelo **Aplicativo OpenGLES (Android, iOS)** .

1. Dê um nome ao aplicativo como *MyOpenGLESApp* e escolha **OK** .

   ![Novo projeto de aplicativo OpenGLs](../cross-platform/media/cppmdd-opengles-newproj.png "Novo projeto de aplicativo OpenGLs")

   O Visual Studio cria a nova solução e abre o Gerenciador de Soluções.

   ![MyOpenGLESApp em Gerenciador de Soluções](../cross-platform/media/cppmdd-opengles-solexpl.png "MyOpenGLESApp em Gerenciador de Soluções")

::: moniker-end

::: moniker range=">=msvc-160"

1. No Visual Studio, escolha **Arquivo** > **Novo** > **Projeto** .

1. Na caixa de diálogo **criar um novo projeto** , selecione o modelo **aplicativo OpenGL (Android, Ios)** e, em seguida, escolha **Avançar** .

1. Na caixa de diálogo **configurar seu novo projeto** , insira um nome como *MyOpenGLESApp* em **nome do projeto** e, em seguida, escolha **criar** .

   O Visual Studio cria a nova solução e abre o Gerenciador de Soluções.

   ![MyOpenGLESApp em Gerenciador de Soluções](../cross-platform/media/cppmdd-opengles-solexpl.png "MyOpenGLESApp em Gerenciador de Soluções")

::: moniker-end

A nova solução de Aplicativo OpenGL ES inclui três projetos de biblioteca e dois projetos de aplicativo. A pasta bibliotecas inclui um projeto de código compartilhado. E dois projetos específicos da plataforma que fazem referência ao código compartilhado:

- `MyOpenGLESApp.Android.NativeActivity` contém as referências e o código de cola que implementa seu aplicativo como uma Atividade Nativa no Android. Os pontos de entrada do código de associação são implementados em *main.cpp* , que inclui o código compartilhado comum em `MyOpenGLESApp.Shared`. Os cabeçalhos pré-compilados estão em *pch.h* . Esse projeto de aplicativo de Atividade Nativa é compilado em um arquivo ( *.so* ) de biblioteca compartilhada que é obtido pelo projeto de `MyOpenGLESApp.Android.Packaging`.

- `MyOpenGLESApp.iOS.StaticLibrary` cria um arquivo ( *.a* ) da biblioteca estática do iOS que contém o código compartilhado no `MyOpenGLESApp.Shared`. Ele está vinculado ao aplicativo criado pelo projeto `MyOpenGLESApp.iOS.Application`.

- `MyOpenGLESApp.Shared` contém o código compartilhado que funciona em várias plataformas. Ele utiliza macros de pré-processador para compilação condicional do código específico da plataforma. O código compartilhado é escolhido pela referência de projeto no `MyOpenGLESApp.Android.NativeActivity` e no `MyOpenGLESApp.iOS.StaticLibrary`.

A solução tem dois projetos para compilar aplicativos para as plataformas Android e iOS:

- `MyOpenGLESApp.Android.Packaging` cria o arquivo *.apk* para implantação em um emulador ou dispositivo Android. Esse arquivo contém os recursos e o arquivo AndroidManifest.xml no qual as propriedades do manifesto são definidas. Também contém o arquivo *build.xml* que controla o processo de build Ant. Ele é definido como o projeto de inicialização por padrão, para que possa ser implantado e executado diretamente no Visual Studio.

- `MyOpenGLESApp.iOS.Application` contém os recursos e o código de União Objective-C para criar um aplicativo iOS que vincula ao código de biblioteca estática C++ no `MyOpenGLESApp.iOS.StaticLibrary` . Esse projeto cria um pacote de build que é transferido para seu Mac pelo Visual Studio e pelo agente remoto. Quando você compila este projeto, o Visual Studio envia os arquivos e os comandos para compilar e implantar seu aplicativo no Mac.

## <a name="build-and-run-the-android-app"></a>Criar e executar o aplicativo Android

A solução criada pelo modelo define o aplicativo Android como o projeto padrão.  Você pode compilar e executar esse aplicativo para verificar sua instalação e configuração. Para um teste inicial, execute o aplicativo em um dos perfis de dispositivo instalados pelo emulador para Android. Se preferir testar seu aplicativo em outro destino, você poderá carregar o emulador de destino. Ou conecte um dispositivo ao seu computador.

### <a name="to-build-and-run-the-android-native-activity-app"></a>Para compilar e executar o aplicativo de Atividade Nativa Android

1. Se ainda não estiver selecionado, escolha **x86** na lista suspensa **Plataformas da Solução** .

   ![Definir a plataforma da solução como x86](../cross-platform/media/cppmdd-opengles-solutionplat.png "Definir a plataforma da solução como x86")

   Use x86 para ter o emulador como destino. Para ter um dispositivo como destino, escolha a plataforma de solução com base no processador do dispositivo. Se a lista **Plataformas da Solução** não for exibida, escolha **Plataformas da Solução** na lista **Adicionar/Remover Botões** e, em seguida, escolha sua plataforma.

1. No **Gerenciador de Soluções** , abra o menu de atalho do projeto `MyOpenGLESApp.Android.Packaging` e, em seguida, escolha **Compilar** .

   ![Compilar projeto de empacotamento Android](../cross-platform/media/cppmdd-opengles-andbuild.png "Compilar projeto de empacotamento Android")

   A janela Saída exibe a saída do processo de build para a biblioteca compartilhado Android e o aplicativo Android.

   ![Compilar saída para projetos Android](../cross-platform/media/cppmdd-opengles-andoutput.png "Compilar saída para projetos Android")

1. Escolha um dos perfis de dispositivos Android emulados como seu destino de implantação.

   ![Escolher destino de implantação](../cross-platform/media/cppmdd-opengles-pickemulator.png "Escolher destino de implantação")

   Você pode ter instalado outros emuladores ou conectado a um dispositivo Android. Você pode escolher na lista suspensa destino da implantação. Para executar o aplicativo, a Plataforma de Solução compilada deverá corresponder à plataforma do dispositivo de destino.

1. Pressione **F5** para iniciar a depuração ou **Shift** + **F5** para iniciar sem depuração.

   O Visual Studio inicia o emulador, que leva vários segundos para carregar e implantar o código. Confira aqui como o aplicativo aparece no emulador:

   ![Aplicativo em execução no Android Emulator](../cross-platform/media/cppmdd-opengles-andemulator.png "Aplicativo em execução no Android Emulator")

   Quando o aplicativo tiver sido iniciado, você poderá definir pontos de interrupção e usar o depurador para executar o código em etapas, examinar os locais e inspecionar os valores.

1. Pressione **Shift** + **F5** para parar a depuração.

   O emulador é um processo separado que continua sendo executado. É possível editar, compilar e implantar o código várias vezes no mesmo emulador. Seu aplicativo aparece na coleção de aplicativo no emulador e pode ser iniciado diretamente de lá.

   Os projetos de biblioteca e aplicativo de atividades nativas do Android gerados colocam o código compartilhado C++ em uma biblioteca dinâmica. Ele inclui o código "Glue" para a interface com a plataforma Android. A maior parte do código do aplicativo está na biblioteca. O manifesto, os recursos e as instruções de compilação estão no projeto de empacotamento. O código compartilhado é chamado de main.cpp no projeto NativeActivity. Para obter mais informações sobre como programar uma Atividade Nativa do Android, consulte a página [Conceitos](https://developer.android.com/ndk/guides/concepts.html) do NDK do Android Developer.

   O Visual Studio compila projetos de atividades nativas do Android usando o Android NDK. Ele usa Clang como o conjunto de ferramentas de plataforma. O Visual Studio mapeia as propriedades do projeto nos comandos Compile, link e Debug na plataforma de destino. Para obter detalhes, abra a caixa de diálogo **Páginas de Propriedade** para o projeto MyOpenGLESApp.Android.NativeActivity. Para saber mais sobre as opções de linha de comando, consulte o [Manual do usuário do compilador Clang](https://clang.llvm.org/docs/UsersManual.html).

## <a name="build-and-run-the-ios-app-on-an-ios-device"></a>Criar e executar o aplicativo iOS em um dispositivo iOS

Você cria e edita o projeto de aplicativo do iOS no Visual Studio. Devido a restrições de licenciamento, ele deve ser compilado e implantado a partir de um Mac. O Visual Studio comunica-se com um agente remoto em execução no Mac para transferir arquivos de projeto e executar comandos de build, implantação e depuração. Instale e configure seu Mac e o Visual Studio para comunicação antes de compilar o aplicativo iOS. Para obter instruções detalhadas, consulte [instalar e configurar ferramentas para compilar usando o Ios](../cross-platform/install-and-configure-tools-to-build-using-ios.md). Execute o agente remoto no seu Mac e emparelhe-o com o Visual Studio. Em seguida, você pode criar e executar o aplicativo iOS para verificar a instalação e a instalação.

Para implantar seu aplicativo em um dispositivo iOS, primeiro configure a assinatura automática no Xcode. A assinatura automática cria um perfil de provisionamento para assinar uma compilação do aplicativo.

### <a name="to-set-up-automatic-signing-on-xcode"></a>Para configurar a assinatura automática no Xcode

1. Se você ainda não fez isso, instale o [Xcode](https://developer.apple.com/xcode/) no seu Mac.

1. Abra o aplicativo Xcode no seu Mac.

1. Crie um novo projeto Xcode **Aplicativo de Modo de Exibição Único** . Preencha os campos obrigatórios durante a criação do projeto. Os valores podem ser arbitrários, pois o projeto é usado apenas para criar um perfil de provisionamento usado posteriormente para assinar uma compilação do aplicativo.

1. Adicione sua ID da Apple que está inscrita em uma conta do [Programa de Desenvolvedor da Apple](https://developer.apple.com/programs/) no Xcode. Sua ID da Apple é usada como uma identidade de assinatura para assinar aplicativos. Para adicionar a identidade de assinatura no Xcode, abra o menu do **Xcode** e escolha **Preferências** . Selecione **Contas** e clique no botão Adicionar (+) para adicionar sua ID da Apple. Para obter instruções detalhadas, confira [Adicionar sua conta de ID da Apple](https://help.apple.com/xcode/mac/current/#/devaf282080a).

1. A partir das configurações "Gerais" do projeto Xcode, altere o valor do **Identificador de Pacote** para `com.<NameOfVSProject>`, onde `<NameOfVSProject>` é o mesmo nome do projeto de solução do Visual Studio que você criou. Por exemplo, se você criou um projeto chamado `MyOpenGLESApp` no Visual Studio, configure **Identificador de Pacote** como `com.MyOpenGLESApp`.

   ![Identificador do pacote do Xcode](../cross-platform/media/cppmdd-opengles-iosxcodeid.png "Identificador do pacote do Xcode")

1. Para habilitar a assinatura automática, selecione. Gerencie a assinatura automaticamente**.

   ![Assinatura automática do Xcode](../cross-platform/media/cppmdd-opengles-iosxcodesign.png "Assinatura automática do Xcode")

1. Selecione o nome da equipe da ID da Apple que você adicionou como a **Equipe** de desenvolvimento.

   ![Equipe do Xcode](../cross-platform/media/cppmdd-opengles-iosxcodeteam.png "Equipe do Xcode")

### <a name="to-build-and-run-the-ios-app-on-an-ios-device"></a>Criar e executar o aplicativo iOS em um dispositivo iOS

1. Execute o agente remoto no seu Mac e verifique se o Visual Studio está emparelhado com o agente remoto. Para iniciar o agente remoto, abra uma janela do aplicativo Terminal e digite `vcremote`. Para obter mais informações, consulte [Configurar o agente remoto no Visual Studio](../cross-platform/install-and-configure-tools-to-build-using-ios.md#ConfigureVS).

   ![Janela do terminal do Mac executando vcremote](../cross-platform/media/cppmdd-common-vcremote.png "Janela do terminal do Mac executando vcremote")

1. Anexe um dispositivo iOS ao seu Mac. Quando você conecta seu dispositivo a um computador pela primeira vez, um alerta pergunta se você confia no computador para acessar seu dispositivo. Habilite o dispositivo para confiar no computador Mac.

1. No Visual Studio, se ainda não estiver selecionado, escolha a plataforma de solução na lista suspensa **Plataformas de Solução** com base no processador do dispositivo. Neste exemplo, é um processador **ARM64** .

   ![Definir a plataforma da solução como ARM64](../cross-platform/media/cppmdd-opengles-pickplatformarm64.png "Definir a plataforma da solução como ARM64")

1. No Gerenciador de Soluções, abra o menu de atalho para o projeto MyOpenGLESApp.iOS.Application e escolha **Descarregar Projeto** para descarregar o projeto.

1. Novamente, abra o menu de atalho para o projeto MyOpenGLESApp.iOS.Application descarregado e escolha **Editar project.pbxproj** para editar o arquivo do projeto. No arquivo `project.pbxproj`, procure o atributo `buildSettings` e adicione `DEVELOPMENT_TEAM` usando sua ID de equipe da Apple. A captura de tela abaixo mostra um valor de exemplo de `123456ABC` para a ID de equipe da Apple. Você pode encontrar o valor da sua ID de equipe da Apple no Xcode. Vá para **Configurações da Compilação** e passe o mouse sobre o nome da equipe de desenvolvimento para mostrar uma dica de ferramenta. A dica de ferramenta mostra a ID da equipe.

   ![Definir equipe de desenvolvimento](../cross-platform/media/cppmdd-opengles-iosdevelopmentteam.png "Definir equipe de desenvolvimento")

1. Feche o arquivo `project.pbxproj`, abra o menu de atalho para o projeto MyOpenGLESApp.iOS.Application e escolha **Recarregar Projeto** para recarregar o projeto.

1. Agora crie o projeto MyOpenGLESApp.iOS.Application abrindo o menu de atalho do projeto e escolhendo **Compilar** .

   ![Compilar projeto de aplicativo iOS](../cross-platform/media/cppmdd-opengles-iosbuild.png "Compilar projeto de aplicativo iOS")

   A janela saída exibe a saída do processo de compilação. Ele mostra os resultados da biblioteca estática do iOS e do aplicativo iOS. No Mac, a janela Terminal executando o agente remoto mostra a atividade de comando e transferência de arquivo.

   No seu computador Mac, você pode ser solicitado a permitir que o codesign acesse seu conjunto de chaves. Escolha **Permitir** para continuar.

1. Escolha o seu dispositivo iOS na barra de ferramentas para executar o aplicativo no seu dispositivo conectado ao seu Mac. Se o aplicativo não iniciar, verifique se o dispositivo dá permissão para que o aplicativo implantado seja executado no dispositivo. Essa permissão pode ser definida acessando **configurações**  >  **geral**  >  **Gerenciamento de dispositivo** no dispositivo. Selecione sua conta de Aplicativo de Desenvolvedor, insira sua conta e verifique o aplicativo. Tente executar o aplicativo novamente no Visual Studio.

   ![aplicativo iOS no dispositivo iOS](../cross-platform/media/cppmdd-opengles-iosdevice.png "aplicativo iOS no dispositivo iOS")

   Quando seu aplicativo tiver sido iniciado, você poderá definir pontos de interrupção e usar o depurador do Visual Studio para examinar locais, consultar a pilha de chamadas e inspecionar os valores.

   ![Depurador em ponto de interrupção no aplicativo iOS](../cross-platform/media/cppmdd-opengles-iosdebug.png "Depurador em ponto de interrupção no aplicativo iOS")

1. Pressione **Shift** + **F5** para parar a depuração.

   Os projetos de aplicativo e biblioteca do iOS gerados colocam o código C++ em uma biblioteca estática que implementa somente o código compartilhado. A maior parte do código do aplicativo esta no projeto de `Application`. As chamadas para o código de biblioteca compartilhada neste projeto de modelo são feitas no arquivo *GameViewController.m* . Para compilar seu aplicativo iOS, o Visual Studio usa o conjunto de ferramentas de plataforma do Xcode, que exige a comunicação com um cliente remoto em execução em um Mac.

   O Visual Studio transfere os arquivos de projeto para o cliente remoto. Em seguida, ele envia comandos para compilar o aplicativo usando o Xcode. O cliente remoto envia informações de status de build de volta ao Visual Studio. Quando o aplicativo tiver sido compilado com êxito, o Visual Studio poderá enviar comandos para executar e depurar o aplicativo. O depurador no Visual Studio controla o aplicativo em execução no seu dispositivo iOS conectado ao seu Mac. O Visual Studio mapeia as propriedades do projeto para as opções usadas para compilar, vincular e depurar na plataforma iOS de destino. Para obter detalhes de opção de linha de comando do compilador, abra a caixa de diálogo **Páginas de Propriedade** para o projeto MyOpenGLESApp.iOS.StaticLibrary.

## <a name="customize-your-apps"></a>Personalizar seus aplicativos

Você pode modificar o código C++ compartilhado para adicionar ou alterar funcionalidade comum. Altere as chamadas para o código compartilhado nos `MyOpenGLESApp.Android.NativeActivity` projetos e `MyOpenGLESApp.iOS.Application` para que correspondam. Você pode usar macros de pré-processador para especificar seções específicas de plataforma no seu código comum. A macro do pré-processador `__ANDROID__` é predefinida ao compilar para Android. A macro do pré-processador `__APPLE__` é predefinida ao compilar para iOS.

Para ver o IntelliSense para uma plataforma de projeto específica, escolha o projeto na lista suspensa seletor de contexto. Ele está na barra de navegação na parte superior da janela do editor.

![Lista suspensa do seletor de contexto do projeto no editor](../cross-platform/media/cppmdd-opengles-contextswitcher.png)

Problemas do IntelliSense no código que é usado pelo projeto atual são marcados com uma linha ondulada vermelha. Um problema de marcas de linha ondulada roxa em outros projetos. O Visual Studio não dá suporte à coloração de código nem a arquivos IntelliSense para Java ou Objective-C. No entanto, você ainda pode modificar os arquivos de origem e os recursos. Use-os para definir o nome do aplicativo, o ícone e outros detalhes de implementação.
