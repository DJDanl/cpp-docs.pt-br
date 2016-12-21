---
title: "Arquivos e fluxos | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Arquivos  [C++]"
  - "fluxos"
ms.assetid: f61e712b-eac9-4c28-bb18-97c3786ef387
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Arquivos e fluxos
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um programa se comunica com o ambiente de destino ler e gravar arquivos.  Um arquivo pode ser:  
  
-   Um conjunto de dados que você pode ler e gravar repetidamente.  
  
-   Um fluxo de bytes gerados por um programa \(como um pipeline\).  
  
-   Um fluxo de bytes recebidos do ou enviados a um dispositivo periférico.  
  
 Os últimos dois itens são arquivos interativos.  Os arquivos são normalmente os principais mídia pelo qual interagir com um programa.  Você manipula todos esses tipos de arquivos da mesma forma — chamando funções da biblioteca.  Você incluir o cabeçalho padrão STDIO.H para declarar a maioria dessas funções.  
  
 Antes de poder executar muitas das operações em um arquivo, o arquivo deve ser aberto.  Ao abrir um arquivo associe\-o a um fluxo, uma estrutura de dados na biblioteca padrão C aquela brilho sobre as diferenças entre arquivos de vários tipos.  A biblioteca mantém o estado de cada fluxo em um objeto de tipo FILE.  
  
 O ambiente de destino abre três arquivos antes da inicialização do programa.  Você pode abrir um arquivo chamando a função de biblioteca [fopen, \_wfopen](../c-runtime-library/reference/fopen-wfopen.md) com dois argumentos. \(A função de `fopen` foi preterida, use [fopen\_s, \_wfopen\_s](../c-runtime-library/reference/fopen-s-wfopen-s.md) em seu lugar.\) O primeiro argumento for um nome de arquivo.  O segundo argumento é a cadeia de caracteres c que especifica:  
  
-   Se você pretende ler dados do arquivo ou gravar dados a ele ou ambos.  
  
-   Se você pretende gerar novos conteúdo do arquivo \(ou para criar um arquivo se não existia anteriormente\) ou deixar o conteúdo existente no lugar.  
  
-   Se o é gravado em um arquivo podem alterar conteúdo existente ou só devem acrescentar bytes no final do arquivo.  
  
-   Se você deseja manipular um fluxo de texto ou um fluxo binário.  
  
 O arquivo é aberto uma vez com êxito, você pode determinar se o fluxo é orientado por byte \(um fluxo de bytes\) ou orientado a largura \(um fluxo amplo\).  Um fluxo não associado é inicialmente.  Chamar determinadas funções para operar no fluxo torna o byte orientada, quando se esqueça de outras funções\) orientado por todo.  Uma vez que estabelecido, um fluxo manterá sua orientação até que o seja encerrado por uma chamada a [fclose](../c-runtime-library/reference/fclose-fcloseall.md) ou a [freopen](../c-runtime-library/reference/freopen-wfreopen.md).  
  
 © 1989\-2001 por P.J.  Plauger e Jim Brodie.  Todos os direitos reservados.  
  
## Consulte também  
 [Texto e fluxos binários](../c-runtime-library/text-and-binary-streams.md)   
 [Byte e fluxos largos](../c-runtime-library/byte-and-wide-streams.md)   
 [Controlando fluxos](../c-runtime-library/controlling-streams.md)   
 [Estados de fluxo](../Topic/Stream%20States.md)