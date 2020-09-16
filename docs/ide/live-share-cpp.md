---
title: Colaborar com o Live Share para C++ no Visual Studio
description: Usar o Live Share para C++ no Visual Studio para colaborar e compartilhar código em tempo real.
ms.date: 05/24/2019
ms.openlocfilehash: 60830ad6c6b98f644e1c3ddb2e78fbf7397ae919
ms.sourcegitcommit: c1fd917a8c06c6504f66f66315ff352d0c046700
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/16/2020
ms.locfileid: "90684515"
---
# <a name="collaborate-using-live-share-for-c"></a>Colaborar usando o Live Share para C++

No Visual Studio 2019 e no Visual Studio Code, você pode usar o **Live Share** para colaborar em projetos C++ em tempo real. Com o **Live Share**, outra pessoa pode editar e depurar o código sem precisar instalar o projeto ou uma de suas dependências. Vocês veem as edições um do outro conforme elas ocorrem, e cada edição é marcada com o nome da pessoa que a fez.

![C&#43;&#43; Live Share edição](../ide/media/live-share-edit-cpp.png "Live Share edição em C++")

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

![Depuração do C&#43;&#43; Live Share](../ide/media/live-share-debug-cpp.png "Live Share a depuração em C++")

## <a name="start-and-end-a-live-share-session"></a>Iniciar e encerrar uma sessão do Live Share

Para iniciar uma sessão de Live share no Visual Studio, clique no botão compartilhar na parte superior direita ou vá para **arquivo**  >  **iniciar a sessão de colaboração**. Isso gerará um link que você poderá compartilhar com seus colaboradores.

![Uma pequena captura de tela do botão Live Share.](../ide/media/live-share-button-cpp.png "Botão de Live Share")

Para encerrar uma sessão, selecione **Encerrar Sessão de Colaboração** na lista suspensa **Compartilhamento**.

![Captura de tela da lista suspensa de compartilhamento com a opção encerrar sessão de colaboração realçada.](../ide/media/live-share-end-session-cpp.png "Botão de Live Share")

## <a name="for-more-information"></a>Para obter mais informações

Para obter mais informações sobre o **Live Share** no Visual Studio, confira [O que é o Visual Studio Live Share?](/visualstudio/liveshare/). Para obter mais informações sobre o Live Share no Visual Studio Code, confira [ Live Share](https://marketplace.visualstudio.com/items?itemName=ms-vsliveshare.vsliveshare).

## <a name="see-also"></a>Consulte Também

[Editar e refatorar o código (C++)](writing-and-refactoring-code-cpp.md)</br>
[Navegar pela base de código C++ no Visual Studio](navigate-code-cpp.md)</br>
[Ler e entender o código C++](read-and-understand-code-cpp.md)</br>
