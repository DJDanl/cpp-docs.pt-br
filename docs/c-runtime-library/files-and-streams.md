---
title: Arquivos e fluxos
description: Uma visão geral dos arquivos e fluxos na biblioteca de tempo de execução do Microsoft C.
ms.date: 11/04/2016
ms.topic: conceptual
helpviewer_keywords:
- files [C++]
- streams
ms.assetid: f61e712b-eac9-4c28-bb18-97c3786ef387
ms.openlocfilehash: 39133cfdb4784c42561a159d6d176bcbd23644af
ms.sourcegitcommit: 9451db8480992017c46f9d2df23fb17b503bbe74
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/30/2020
ms.locfileid: "91589959"
---
# <a name="files-and-streams"></a>Arquivos e fluxos

Um programa se comunica com o ambiente de destino ao ler e gravar arquivos. Um arquivo pode ser:

- Um conjunto de dados que você pode ler e gravar repetidamente.

- Um fluxo de bytes gerado por um programa (como um pipeline).

- Um fluxo de bytes recebidos de ou enviado para um dispositivo periférico.

Os dois últimos itens são arquivos interativos. Normalmente, os arquivos são o principal meio de interação com um programa. Você manipula todos esses tipos de arquivos em grande parte da mesma maneira — chamando funções de biblioteca. Você inclui o cabeçalho padrão STDIO.H para declarar a maioria dessas funções.

Antes que você possa realizar muitas das operações em um arquivo, o arquivo deverá ser aberto. Abrir um arquivo o associa a um fluxo, uma estrutura de dados dentro da biblioteca C padrão que encobre várias diferenças entre arquivos de diversos tipos. A biblioteca mantém o estado de cada fluxo em um objeto do tipo FILE.

O ambiente de destino abre três arquivos antes da inicialização do programa. Você pode abrir um arquivo chamando a função de biblioteca [fopen, _wfopen](../c-runtime-library/reference/fopen-wfopen.md) com dois argumentos. (A `fopen` função foi preterida, use [fopen_s _wfopen_s](../c-runtime-library/reference/fopen-s-wfopen-s.md) em vez disso.) O primeiro argumento é um nome de arquivo. O segundo argumento é uma cadeia de caracteres em C que especifica:

- Se você pretende ler dados do arquivo ou gravar dados nele ou ambos.

- Se você pretende gerar novo conteúdo para o arquivo (ou criar um arquivo caso ele ainda não exista) ou deixar o conteúdo existente no local.

- Se as gravações em um arquivo podem alterar o conteúdo existente ou se só devem acrescentar bytes ao final do arquivo.

- Se você deseja manipular um fluxo de texto ou um fluxo binário.

Depois que o arquivo for aberto com êxito, você poderá determinar se o fluxo é orientado a bytes (um fluxo de bytes) ou orientado a largos (um fluxo largo). Inicialmente, um fluxo não está associado. Chamar determinadas funções para operar no fluxo o torna orientado a byte, enquanto outras funções determinadas o tornam orientado a largo. Uma vez estabelecido, um fluxo mantém sua orientação até ser fechado por uma chamada a [fclose](../c-runtime-library/reference/fclose-fcloseall.md) ou [freopen](../c-runtime-library/reference/freopen-wfreopen.md).

© 1989-2001 de P.J. Plauger e Jim Brodie. Todos os direitos reservados.

## <a name="see-also"></a>Confira também

[Fluxos de texto e binários](../c-runtime-library/text-and-binary-streams.md)<br/>
[Fluxos de bytes e largos](../c-runtime-library/byte-and-wide-streams.md)<br/>
[Controlando fluxos](../c-runtime-library/controlling-streams.md)<br/>
[Estados de fluxo](../c-runtime-library/stream-states.md)
