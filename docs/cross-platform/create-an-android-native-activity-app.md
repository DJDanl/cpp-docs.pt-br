---
title: Criar um aplicativo de Atividade Nativa do Android
ms.date: 10/17/2019
ms.assetid: 884014b1-5208-45ec-b0da-ad0070d2c24d
ms.openlocfilehash: 664729a920076839f5f9b4440768fe3adb846803
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92924197"
---
# <a name="create-an-android-native-activity-app"></a>Criar um aplicativo de Atividade Nativa do Android

Quando você instala o **desenvolvimento móvel** de plataforma cruzada com carga de trabalho do C++, o Visual Studio pode ser usado para criar aplicativos de atividade nativa do Android totalmente funcionais. O NDK (Kit de Desenvolvimento Nativo) do Android é um conjunto de ferramentas que permite implementar a maior parte de seu aplicativo Android usando um código C/C++ puro. Algum código JNI do Java atua como uma cola para permitir que o código C/C++ interaja com o Android. O NDK do Android introduziu a capacidade de criar aplicativos de Atividade Nativa com a API do Android Nível 9. O código de Atividade Nativa é popular para a criação de aplicativos de jogos e de uso intensivo de elementos gráficos que usam o Unreal Engine ou o OpenGL. Este tópico descreverá a criação de um aplicativo de Atividade Nativa simples que usa o OpenGL. Os tópicos adicionais descrevem o ciclo de vida do desenvolvedor referente à edição, build, depuração e implantação do código de Atividade Nativa.

## <a name="requirements"></a>Requisitos

Antes de criar um aplicativo de atividade nativa do Android, você deve verificar se atendeu a todos os requisitos do sistema e instalou o **desenvolvimento móvel com** a carga de trabalho do C++ no Visual Studio. Para obter mais informações, consulte [instalar o desenvolvimento móvel de plataforma cruzada com C++](../cross-platform/install-visual-cpp-for-cross-platform-mobile-development.md). Verifique se as ferramentas e os SDKs de terceiros necessários estão incluídos na instalação e se um emulador do Android está instalado.

## <a name="create-a-new-native-activity-project"></a>Criar um projeto de atividade nativa

Neste tutorial, você primeiro criará um novo projeto de atividade nativa do Android e, em seguida, compilará e executará o aplicativo padrão em um emulador do Android.

::: moniker range="msvc-150"

1. No Visual Studio, escolha **Arquivo** > **Novo** > **Projeto** .

1. Na caixa de diálogo **Novo Projeto** , em **Modelos** , escolha **Visual C++** > **Multiplataforma** e, em seguida, escolha o modelo **Aplicativo de Atividade Nativa (Android)** .

1. Dê um nome ao aplicativo como *MyAndroidApp* e escolha **OK** .

   ![Criar um projeto de atividade nativa](../cross-platform/media/cppmdd-newproject.png "Criar um projeto de atividade nativa")

   O Visual Studio cria a nova solução e abre o Gerenciador de Soluções.

   ![Projeto de atividade nativa no Gerenciador de Soluções](../cross-platform/media/cppmdd-rc-na-solutionexp.png "Projeto de atividade nativa no Gerenciador de Soluções")

::: moniker-end

::: moniker range=">=msvc-160"

1. No Visual Studio, escolha **Arquivo** > **Novo** > **Projeto** .

1. Na caixa de diálogo **criar um novo projeto** , selecione o modelo **aplicativo de atividade nativa (Android)** e, em seguida, escolha **Avançar** .

1. Na caixa de diálogo **configurar seu novo projeto** , insira um nome como *MyAndroidApp* em **nome do projeto** e, em seguida, escolha **criar** .

   O Visual Studio cria a nova solução e abre o Gerenciador de Soluções.

::: moniker-end

A nova solução de aplicativo de Atividade Nativa do Android inclui dois projetos:

- `MyAndroidApp.NativeActivity` contém as referências e o código de cola para que seu aplicativo seja executado como uma Atividade Nativa no Android. A implementação dos pontos de entrada do código de cola está em *main.cpp* . Os cabeçalhos pré-compilados estão em *pch.h* . Esse projeto de aplicativo de Atividade Nativa é compilado em um arquivo *.so* de biblioteca compartilhada que é obtido pelo projeto de Empacotamento.

- `MyAndroidApp.Packaging` cria o arquivo *.apk* para implantação em um emulador ou dispositivo Android. Isso contém os recursos e o arquivo *AndroidManifest.xml* no qual as propriedades do manifesto são definidas. Também contém o arquivo *build.xml* que controla o processo de build Ant. Ele é definido como o projeto de inicialização por padrão, para que possa ser implantado e executado diretamente no Visual Studio.

## <a name="build-and-run-the-default-android-native-activity-app"></a>Criar e executar o aplicativo de atividade nativa do Android padrão

Compile e execute o aplicativo gerado pelo modelo para verificar a instalação e a configuração. Para este teste inicial, execute o aplicativo em um dos perfis de dispositivo instalados pelo emulador do Android. Se você preferir testar seu aplicativo em outro destino, poderá carregar o emulador de destino ou conectar o dispositivo ao computador.

## <a name="to-build-and-run-the-default-native-activity-app"></a>Para compilar e executar o aplicativo de Atividade Nativa padrão

1. Se ainda não estiver selecionado, escolha **x86** na lista suspensa **Plataformas da Solução** .

     ![Seleção do menu suspenso de plataformas de solução x86](../cross-platform/media/cppmdd-rc-na-solution-x86.png "Seleção do menu suspenso de plataformas de solução x86")

     Se a lista **Plataformas da Solução** não estiver visível, escolha **Plataformas da Solução** na lista **Adicionar/Remover Botões** e, em seguida, escolha sua plataforma.

1. Na barra de menus, escolha **Compilar** compilar  >  **solução** .

     A Janela de Saída exibe a saída do processo de build dos dois projetos na solução.

1. Escolha um dos perfis do Android Emulator como seu destino de implantação.

     Se você tiver instalado outros emuladores ou conectado um dispositivo Android, poderá escolhê-los na lista suspensa de destino de implantação.

1. Pressione **F5** para iniciar a depuração ou **Shift** + **F5** para iniciar sem depuração.

   Veja a aparência do aplicativo padrão em um emulador do Android.

   ![O emulador que executa seu aplicativo](../cross-platform/media/cppmdd-emulator-running-app.png "O emulador que executa seu aplicativo")

   O Visual Studio inicia o emulador, que leva alguns segundos para carregar e implantar o código. Quando o aplicativo tiver sido iniciado, você poderá definir pontos de interrupção e usar o depurador para executar o código em etapas, examinar os locais e inspecionar os valores.

1. Pressione **Shift** + **F5** para parar a depuração.

   O emulador é um processo separado que continua sendo executado. É possível editar, compilar e implantar o código várias vezes no mesmo emulador.
