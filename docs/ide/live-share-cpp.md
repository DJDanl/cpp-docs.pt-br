---
title: Colaborar com o Live Share para C++ no Visual Studio
description: Usar o Live Share para C++ no Visual Studio para colaborar e compartilhar código em tempo real.
ms.date: 05/24/2019
ms.openlocfilehash: e6e983c6acb56dffd12756d8bbaccef32dd57f38
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80077774"
---
# <a name="collaborate-using-live-share-for-c"></a>Colaborar usando o Live Share para C++

No Visual Studio 2019 e no Visual Studio Code, você pode usar o **Live Share** para colaborar em projetos C++ em tempo real. Com o **Live Share**, outra pessoa pode editar e depurar o código sem precisar instalar o projeto ou uma de suas dependências. Vocês veem as edições um do outro conforme elas ocorrem, e cada edição é marcada com o nome da pessoa que a fez.

![C&#43; &#43; Live share edição](../ide/media/live-share-edit-cpp.png "Live Share edição emC++")

## <a name="live-share-host-and-guests"></a>Host e participantes do Live Share

Em uma sessão do Live Share, há um host e um ou mais participantes. O host e os participantes podem usar o Visual Studio ou o Visual Studio Code. Um host do Visual Studio 2019 no Windows pode compartilhar algo com um participante do Visual Studio Code no Linux.

O host fornece aos participantes tudo o que eles precisam para serem produtivos. Os participantes não precisam ter o código-fonte, o compilador, dependências externas, nem mesmo os mesmos componentes instalados.

O host e os participantes podem usar estes recursos do IntelliSense:

- Lista de Membros
- Ajuda do Parâmetro
- Informação Rápida
- Depuração/pontos de interrupção
- Localizar Todas as Referências
- Ir para definição
- Pesquisa de símbolos (Ctrl+T)
- Realce de referência
- Diagnóstico/erros/rabiscos

![Depuração&#43; &#43; de Live share do C](../ide/media/live-share-debug-cpp.png "Live Share depuração emC++")

## <a name="start-and-end-a-live-share-session"></a>Iniciar e encerrar uma sessão do Live Share

Para iniciar uma sessão do Live Share no Visual Studio, clique no botão Compartilhar no canto superior direito ou acesse **Arquivo** > **Iniciar Sessão de Colaboração**. Isso gerará um link que você poderá compartilhar com seus colaboradores.

![Botão&#43; &#43; de Live share de C](../ide/media/live-share-button-cpp.png "Botão de Live Share")

Para encerrar uma sessão, selecione **Encerrar Sessão de Colaboração** na lista suspensa **Compartilhamento**.

![Botão&#43; &#43; de Live share de C](../ide/media/live-share-end-session-cpp.png "Botão de Live Share")

## <a name="for-more-information"></a>Para obter mais informações

Para obter mais informações sobre o **Live Share** no Visual Studio, confira [O que é o Visual Studio Live Share?](/visualstudio/liveshare/). Para obter mais informações sobre o Live Share no Visual Studio Code, confira [ Live Share](https://marketplace.visualstudio.com/items?itemName=ms-vsliveshare.vsliveshare).

## <a name="see-also"></a>Consulte Também

[Editar e refatorar o código (C++)](writing-and-refactoring-code-cpp.md)</br>
[Navegar pela base de código C++ no Visual Studio](navigate-code-cpp.md)</br>
[Ler e entender o código C++](read-and-understand-code-cpp.md)</br>