---
title: Sincronizar alterações entre o Xcode e o Visual Studio
ms.date: 10/17/2019
ms.assetid: c71a4d7c-120e-4559-a114-3a99c4b860a9
ms.openlocfilehash: ab941551c519acee49f658d8a8ff1b9fe0e4ba49
ms.sourcegitcommit: a673f6a54cc97e3d4cd032b10aa8dce7f0539d39
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/28/2020
ms.locfileid: "78177531"
---
# <a name="sync-changes-between-xcode-and-visual-studio"></a>Sincronizar alterações entre o Xcode e o Visual Studio

O desenvolvimento móvel com C++ componentes no Visual Studio inclui recursos remotos para sincronizar seu trabalho entre seu PC e seu Mac. Quando suas máquinas com o Visual Studio e o Mac são emparelhadas, novas opções estão disponíveis para projetos de aplicativos iOS no Visual Studio que você pode usar para abrir seu projeto no Xcode, mover seu código entre o Xcode e o Visual Studio e limpar o diretório de projeto do Xcode temporário.

Para usar as opções de Computador Remoto, o projeto deve ser um projeto de Aplicativo do iOS e o Visual Studio deve ser emparelhado com o Mac. Para obter pré-requisitos e instruções sobre como emparelhar um Mac, confira [Instalar e configurar ferramentas de build usando o iOS](../cross-platform/install-and-configure-tools-to-build-using-ios.md).

## <a name="the-remote-machine-menu"></a>O menu Computador Remoto

Em **Gerenciador de Soluções**, clique com o botão direito do mouse em um projeto de Aplicativo do iOS para mostrar o menu de contexto. Selecione o item **Computador Remoto** para mostrar as opções remotas disponíveis.

![O item de menu do computador remoto no Gerenciador de Soluções](../cross-platform/media/cppmdd-u2-remotemachine-menu.jpg "O item de menu do computador remoto no Gerenciador de Soluções")

Esses comandos permitem que você abra seu projeto no Xcode, mova as alterações locais ou todo o projeto entre o Visual Studio e o Xcode e limpe os arquivos temporários no computador remoto.

## <a name="open-in-xcode"></a>Abrir no Xcode

Para abrir o projeto no Xcode do Visual Studio, no submenu **máquina remota** , escolha **abrir no Xcode** para abrir o projeto selecionado no computador remoto emparelhado. O servidor de `vcremote` é usado para abrir o Xcode no seu Mac e navegar até um diretório temporário criado no seu Mac que contém uma cópia do projeto. O Visual Studio exibe uma caixa de diálogo que mostra o diretório temporário usado para o projeto. As ações realizadas no computador remoto também são mostradas na janela **Saída** do Visual Studio. Para vê-las, talvez você precise selecionar **Computador Remoto do Visual C++** na lista suspensa **Mostrar saída de** na parte superior da janela **Saída**.

![A janela saída mostra as ações de computador remoto.](../cross-platform/media/cppmdd-u2-remotemachine-output.png "A janela saída mostra as ações de computador remoto")

No seu Mac, você pode usar todas as ferramentas do Xcode para editar seu código e recursos, storyboards e ações. No Visual Studio, seu projeto de aplicativo iOS é anotado com "aberto no Xcode" para indicar que as alterações podem ser feitas no computador remoto. Depois que as edições forem concluídas, é possível usar os comandos Efetuar Pull de Remoto ou Pull Incremental de Remoto para copiar as alterações de volta para o projeto do Visual Studio.

## <a name="push-to-remote-and-incremental-push-to-remote"></a>Enviar por Push para Remoto e Push Incremental para Remoto

Se você tiver feito alterações no projeto de Aplicativo do iOS no Visual Studio, os comandos Enviar por Push para Remoto e Push Incremental para Remoto poderão ser usados para mover os arquivos de projeto alterados para o computador remoto emparelhado. O comando Enviar por Push para Remoto copia todos os arquivos de projeto para o computador remoto. O comando Push Incremental para Remoto copia apenas os arquivos alterados para o computador remoto. Para projetos grandes com pequenas alterações, o comando incremental pode economizar tempo e largura de banda.

Para copiar os arquivos de projeto para o Mac, no Visual Studio, no **Gerenciador de Soluções**, clique com o botão direito do mouse no projeto de Aplicativo do iOS para abrir o menu de contexto. Selecione **Computador Remoto** e escolha **Enviar por Push para Remoto** ou **Push Incremental para Remoto** para copiar os arquivos de projeto do Visual Studio para o Mac.

## <a name="pull-from-remote-and-incremental-pull-from-remote"></a>Efetuar Pull de Remoto e Pull Incremental de Remoto

Depois de fazer alterações em seu projeto no Xcode, mova as alterações de volta para o Visual Studio para manter os projetos em sincronia.

Para copiar os arquivos de projeto do Mac, no Visual Studio, no **Gerenciador de Soluções**, clique com o botão direito do mouse no projeto de Aplicativo do iOS para abrir o menu de contexto. Selecione **Computador Remoto** e escolha **Efetuar Pull de Remoto** ou **Pull Incremental de Remoto** para copiar os arquivos de projeto do Mac para o Visual Studio.

## <a name="clean-remote"></a>Limpar Remoto

É possível usar o comando Limpar Remoto para excluir os arquivos no diretório de projeto temporário no computador remoto. O conteúdo do diretório, incluindo arquivos de origem ou produtos de build, é removido do Mac. Verifique se você sincronizou todas as alterações que deseja manter de volta para o Visual Studio usando Efetuar Pull de Remoto ou Pull Incremental de Remoto antes de usar o comando Limpar Remoto.

Para limpar o diretório de projeto temporário no computador remoto, no Visual Studio, no **Gerenciador de Soluções**, clique com o botão direito do mouse no projeto de Aplicativo do iOS para abrir o menu de contexto. Selecione **Computador Remoto** e escolha **Limpar Remoto** para remover os arquivos do diretório de projeto do Mac.
