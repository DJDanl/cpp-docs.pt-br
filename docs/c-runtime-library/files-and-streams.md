---
title: Arquivos e Fluxos | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- files [C++]
- streams
ms.assetid: f61e712b-eac9-4c28-bb18-97c3786ef387
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: e0285d8395b5a135ac75c40914232ad820f36f00
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="files-and-streams"></a>Arquivos e fluxos
Um programa se comunica com o ambiente de destino ao ler e gravar arquivos. Um arquivo pode ser:  
  
-   Um conjunto de dados que você pode ler e gravar repetidamente.  
  
-   Um fluxo de bytes gerado por um programa (como um pipeline).  
  
-   Um fluxo de bytes recebidos de ou enviado para um dispositivo periférico.  
  
 Os dois últimos itens são arquivos interativos. Normalmente, os arquivos são o principal meio de interação com um programa. Você manipula todos esses tipos de arquivos em grande parte da mesma maneira — chamando funções de biblioteca. Você inclui o cabeçalho padrão STDIO.H para declarar a maioria dessas funções.  
  
 Antes que você possa realizar muitas das operações em um arquivo, o arquivo deverá ser aberto. Abrir um arquivo o associa a um fluxo, uma estrutura de dados dentro da biblioteca C padrão que encobre várias diferenças entre arquivos de diversos tipos. A biblioteca mantém o estado de cada fluxo em um objeto do tipo FILE.  
  
 O ambiente de destino abre três arquivos antes da inicialização do programa. Você pode abrir um arquivo chamando a função de biblioteca [fopen, _wfopen](../c-runtime-library/reference/fopen-wfopen.md) com dois argumentos. (A função `fopen` foi preterida, use [fopen_s, _wfopen_s](../c-runtime-library/reference/fopen-s-wfopen-s.md)). O primeiro argumento é um nome de arquivo. O segundo argumento é uma cadeia de caracteres em C que especifica:  
  
-   Se você pretende ler dados do arquivo ou gravar dados nele ou ambos.  
  
-   Se você pretende gerar novo conteúdo para o arquivo (ou criar um arquivo caso ele ainda não exista) ou deixar o conteúdo existente no local.  
  
-   Se as gravações em um arquivo podem alterar o conteúdo existente ou se só devem acrescentar bytes ao final do arquivo.  
  
-   Se você deseja manipular um fluxo de texto ou um fluxo binário.  
  
 Depois que o arquivo for aberto com êxito, você poderá determinar se o fluxo é orientado a bytes (um fluxo de bytes) ou orientado a largos (um fluxo largo). Inicialmente, um fluxo não está associado. Chamar determinadas funções para operar no fluxo o torna orientado a byte, enquanto outras funções determinadas o tornam orientado a largo. Uma vez estabelecido, um fluxo mantém sua orientação até ser fechado por uma chamada a [fclose](../c-runtime-library/reference/fclose-fcloseall.md) ou [freopen](../c-runtime-library/reference/freopen-wfreopen.md).  
  
 © 1989-2001 de P.J. Plauger e Jim Brodie. Todos os direitos reservados.  
  
## <a name="see-also"></a>Consulte também  
 [Texto e fluxos binários](../c-runtime-library/text-and-binary-streams.md)   
 [Byte e fluxos largos](../c-runtime-library/byte-and-wide-streams.md)   
 [Controle de fluxos](../c-runtime-library/controlling-streams.md)   
 [Estados de fluxo](../c-runtime-library/stream-states.md)