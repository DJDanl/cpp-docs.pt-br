---
title: Instalar desenvolvimento de tecnologia móvel multiplataforma com C++
ms.date: 10/17/2019
ms.assetid: aaea6b8d-55eb-4427-8185-c050f855c257
ms.openlocfilehash: 0304bd9aaf4194e7dd785b1293f59624ba365f8a
ms.sourcegitcommit: a673f6a54cc97e3d4cd032b10aa8dce7f0539d39
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/28/2020
ms.locfileid: "78177434"
---
# <a name="install-cross-platform-mobile-development-with-c"></a>Instalar desenvolvimento de tecnologia móvel multiplataforma com C++

Você pode usar C++ o no Visual Studio para criar aplicativos do Windows Desktop, plataforma universal do Windows (UWP) e aplicativos do Linux. E agora, você pode criar C++ aplicativos para Android e Ios. O **desenvolvimento móvel com C++**  carga de trabalho é um conjunto de componentes instalável no Visual Studio. Ele inclui modelos do Visual Studio para iOS, Android e UWP de plataforma cruzada. A carga de trabalho instala as ferramentas e os SDKs de plataforma cruzada que você precisa para começar rapidamente. Você não precisará localizar, baixar e configurá-los por conta própria. É possível usar essas ferramentas no Visual Studio para criar, editar, depurar e testar seus projetos de plataforma cruzada com facilidade.

Este artigo descreve como instalar as ferramentas e o software de terceiros necessários para desenvolver aplicativos de plataforma cruzada no C++ usando o Visual Studio. Para obter uma visão geral, confira [Visual C++ para desenvolvimento móvel multiplataforma](https://visualstudio.microsoft.com/vs/features/cplusplus-mdd/)

## <a name="requirements"></a>Requisitos

::: moniker range="vs-2017"

- Para obter os requisitos de instalação, confira [Requisitos do sistema da família de produtos do Visual Studio](/visualstudio/productinfo/vs2017-system-requirements-vs).

   > [!IMPORTANT]
   > Se você estiver usando o Windows 7 ou o Windows Server 2008 R2, poderá desenvolver código para aplicativos da área de trabalho do Windows, aplicativos e bibliotecas de atividades nativas do Android e aplicativos e bibliotecas de código para iOS, mas não para aplicativos da Windows Store ou UWP.

::: moniker-end
::: moniker range=">=vs-2019"

- Para obter os requisitos de instalação, confira [Requisitos do sistema da família de produtos do Visual Studio](/visualstudio/releases/2019/system-requirements).

   > [!IMPORTANT]
   > Se estiver usando o Windows 7 ou o Windows Server 2008 R2, você poderá desenvolver código para aplicativos de Área de Trabalho do Windows, bibliotecas e aplicativos do tipo Native Acivity do Android e aplicativos e bibliotecas de código para iOS, mas não aplicativos para a Windows Phone ou UWP.

::: moniker-end

Para compilar aplicativos para plataformas de dispositivo específicas, há alguns requisitos adicionais:

- Os emuladores do Android x86 que acompanham o SDK do Android funcionam melhor em computadores que podem usar aceleração de hardware, como o HAXM (Intel Hardware Accelerated Execution Manager). Para obter mais informações, consulte [aceleração de hardware para desempenho de emulador (Hyper-V &AMP; HAXM)](/xamarin/android/get-started/installation/android-emulator/hardware-acceleration?tabs=vswin&pivots=windows).

- O código de compilação para iOS requer uma ID da Apple, uma conta de programa de desenvolvedor do iOS e um computador Mac que possa executar o [Xcode](https://developer.apple.com/xcode/) versão 10,2 ou posterior no os X Mavericks (versão 10,9) ou versões posteriores. Para obter um link para etapas de instalação, veja [Ferramentas de instalação para iOS](#install-tools-for-ios).

- Emuladores do Windows Phone exigem um computador que possa executar o Hyper-V. O recurso do Hyper-V do Windows deve ser habilitado antes que você possa instalar e executar os emuladores. Para obter mais informações, consulte os [requisitos de sistema](/visualstudio/cross-platform/system-requirements-for-the-visual-studio-emulator-for-android) do emulador.

## <a name="get-the-tools"></a>Obter as ferramentas

O Desenvolvimento Mobile com C++ Está disponível nas edições Community, Professional e Enterprise do Visual Studio. Para obter o Visual Studio, acesse a página [Downloads do Visual Studio](https://visualstudio.microsoft.com/downloads/). As ferramentas de desenvolvimento móvel em plataforma cruzada estão disponíveis a partir do Visual Studio 2015.

## <a name="install-the-tools"></a>Instalar as ferramentas

O instalador do Visual Studio inclui um **desenvolvimento móvel com C++ carga de** trabalho. Essa carga de trabalho C++ instala as ferramentas de linguagem, os modelos e os componentes necessários para o desenvolvimento do Android e do Ios no Visual Studio. Ele inclui os conjuntos de ferramentas GCC e Clang necessários para compilações e depuração do Android. A carga de trabalho instala o SDK do Android e os componentes para se comunicar com um Mac para o desenvolvimento do iOS. Ele também instala ferramentas de terceiros e kits de desenvolvimento de software necessários para dar suporte ao desenvolvimento de aplicativos iOS e Android. A maioria dessas ferramentas de terceiros são softwares livres necessários para dar suporte à plataforma Android.

- O kit de desenvolvimento nativo do Android (NDK), o C++ Apache Ant e as ferramentas de desenvolvimento do C++ Android são necessários para criar código direcionado para a plataforma Android.

- O Google Android Emulator e o HAXM (Intel Hardware Accelerated Execution Manager) são os componentes opcionais, mas recomendados. (Os drivers Intel HAXM funcionam apenas em processadores Intel e são incompatíveis com algumas VMs, incluindo o Hyper-V.) Você pode desenvolver e depurar diretamente em um dispositivo Android, mas geralmente é mais fácil usar um emulador em sua área de trabalho para depuração.

- C++as ferramentas de desenvolvimento do iOS são C++ necessárias para criar código direcionado para a plataforma Ios.

> [!NOTE]
> Se estiver usando o Visual Studio 2015, confira [Instalar Visual C++ para Desenvolvimento Móvel Multiplataforma (Visual Studio 2015)](install-visual-cpp-for-cross-platform-mobile-development.md?view=vs-2015)

### <a name="install-the-mobile-development-with-c-workload"></a>Instalação da carga de trabalho Desenvolvimento Mobile com C++

1. Execute o **Instalador do Visual Studio** pelo menu **Iniciar**.

1. Se você já tiver instalado o Visual Studio, escolha o botão **Modificar** para a versão instalada do Visual Studio que você deseja modificar. Caso contrário, escolha **Instalar** para instalar o Visual Studio.

1. Com a guia **Cargas de Trabalho** selecionada, role a tela para baixo e selecione a carga **Desenvolvimento Mobile com C++** no Instalador do Visual Studio. Após a seleção dessa carga de trabalho, outros componentes necessários para desenvolvimento em C++ também serão selecionados. Você também pode escolher outras cargas de trabalho e componentes individuais para instalação simultânea. Para compilar o código de plataforma cruzada que também é direcionado ao UWP, selecione a carga de trabalho **Desenvolvimento na Plataforma Universal do Windows**.

1. No painel **Detalhes da instalação**, expanda **Desenvolvimento Mobile com C++** . Na seção **Opcional**, você pode escolher outras versões do NDK, o Android Emulator do Google, o Hardware Accelerated Execution Manager da Intel e a ferramenta de aceleração de compilação IncrediBuild.

1. Por padrão, um ou mais componentes de instalação do SDK do Android estão incluídos na carga de trabalho. Há outras versões do SDK do Android disponíveis. Para adicionar uma à sua instalação, escolha a guia **Componentes Individuais** e, em seguida, role para baixo até a seção **SDKs, bibliotecas e estruturas** para fazer sua seleção.

1. Escolha o botão **Modificar** ou **Instalar** para instalar a carga de trabalho **Desenvolvimento Mobile com C++** e suas outras cargas de trabalho e componentes selecionados.

   Quando a instalação for concluída, feche o instalador e reinicie o computador. Algumas ações de instalação para os componentes de terceiros não entram em vigor até que o computador seja reiniciado.

   > [!IMPORTANT]
   > Você deve reiniciar para certificar-se de que tudo esteja instalado corretamente.

1. Abra o Visual Studio.

## <a name="install-tools-for-ios"></a>Instalar as ferramentas para iOS

Você pode usar o Visual Studio para editar, depurar e implantar o código do iOS no simulador do iOS. Ou, para um dispositivo iOS. Devido a restrições de licenciamento, o código deve ser criado remotamente em um Mac. Para compilar e executar aplicativos iOS usando o Visual Studio, primeiro configure e configure o agente remoto no seu Mac. Para obter instruções detalhadas sobre a instalação, os pré-requisitos e as opções de configuração, confira [Instalar e configurar ferramentas de build usando o iOS](../cross-platform/install-and-configure-tools-to-build-using-ios.md). Se não estiver compilando para iOS, você poderá ignorar esta etapa.

## <a name="install-or-update-dependencies-manually"></a>Instalar ou atualizar as dependências manualmente

Você não precisa instalar todas as dependências de terceiros ao instalar o **desenvolvimento móvel com C++**  carga de trabalho (ou no Visual Studio 2015, a opção C++ Visual Mobile Development). Instale-os mais tarde usando as etapas em [instalar as ferramentas](#install-the-tools). O Instalador do Visual Studio é atualizado regularmente para instalar os componentes mais recentes de produtos de terceiros. Use-o para instalar SDKs e NDKs atualizados. Também é possível instalar ou atualizá-las independentemente do Visual Studio.

Você pode executar o aplicativo Gerenciador do SDK no diretório SDK do Android novamente para atualizar o SDK. E, para instalar ferramentas opcionais e outros níveis de API. A instalação das atualizações pode falhar, a menos que você use **Executar como administrador** para executar o aplicativo Gerenciador de SDK. Se tiver problemas ao compilar um aplicativo Android, verifique o Gerenciador de SDK quanto a atualizações para seus SDKs instalados.

Para usar alguns dos emuladores de SDK do Android, talvez seja necessário configurar a aceleração de hardware. Para obter mais informações, consulte [aceleração de hardware para desempenho de emulador (Hyper-V &AMP; HAXM)](/xamarin/android/get-started/installation/android-emulator/hardware-acceleration?tabs=vswin).

Na maioria dos casos, o Visual Studio pode detectar as configurações para o software de terceiros que você instalou. Ele mantém os caminhos de instalação em variáveis de ambiente internas. É possível substituir os caminhos padrão dessas ferramentas de desenvolvimento de plataforma cruzada no IDE do Visual Studio.

### <a name="to-set-the-paths-for-third-party-tools"></a>Para definir os caminhos para as ferramentas de terceiros

1. Na barra de menus do Visual Studio, selecione **Ferramentas** > **Opções**.

1. Na caixa de diálogo **Opções**, selecione **Multiplataforma** > **C++**  > **Android**.

   ![Opções de caminho de ferramenta do Android](../cross-platform/media/cppmdd-options-android.png "Opções de caminho de ferramenta do Android")

1. Para alterar o caminho usado por uma ferramenta, marque a caixa de seleção ao lado do caminho e edite o caminho da pasta na caixa de texto. Você também pode usar o botão Procurar ( **...** ) para abrir uma caixa de diálogo **Selecionar local** para escolher a pasta.

1. Escolha **OK** para salvar os locais de pasta da ferramenta personalizada.

## <a name="see-also"></a>Confira também

[Instalar e configurar ferramentas para compilar usando o iOS](install-and-configure-tools-to-build-using-ios.md)\
[Visual C++ para desenvolvimento móvel multiplataforma](https://visualstudio.microsoft.com/vs/features/cplusplus-mdd/)
