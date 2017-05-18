---
title: "Fluxos de texto e binários | Microsoft Docs"
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
- binary streams
- text streams
ms.assetid: 57035e4a-955d-4e04-a560-fcf67ce68b4e
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Human Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: c35e6f8c0bd5e3daff4b4c358134fd2d7329d71e
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="text-and-binary-streams"></a>Texto e fluxos binários
Um fluxo de texto consiste em uma ou mais linhas de texto que podem ser gravados em uma exibição de texto para que possam ser lidos. Durante a leitura de um fluxo de texto, o programa lê um `NL` (nova linha) no final de cada linha. Ao gravar em um fluxo de texto, o programa grava um `NL` para sinalizar o final de uma linha. Para corresponder a convenções diferentes entre ambientes de destino para a representação de texto em arquivos, as funções da biblioteca podem alterar o número e representações de caracteres transmitidos entre o programa e um fluxo de texto.  
  
 Portanto, o posicionamento em um fluxo de texto é limitado. Você pode obter o indicador de posição do arquivo atual chamando [fgetpos](../c-runtime-library/reference/fgetpos.md) ou [ftell](../c-runtime-library/reference/ftell-ftelli64.md). Você pode posicionar um fluxo de texto em uma posição obtidos dessa forma, ou no início ou no final do fluxo, chamando [fsetpos](../c-runtime-library/reference/fsetpos.md) ou [fseek](../c-runtime-library/reference/fseek-fseeki64.md). Qualquer outra alteração de posição pode não ter suporte.  
  
 Para fins de portabilidade máxima, o programa não deve escrever:  
  
-   Arquivos vazios.  
  
-   Caracteres de espaço no final de uma linha.  
  
-   Linhas parciais (omitindo o `NL` no final de um arquivo).  
  
-   caracteres além dos caracteres imprimíveis, NL e `HT` (tabulação horizontal).  
  
 Se você seguir essas regras, a sequência de caracteres que você ler de um fluxo de texto (em bytes ou caracteres multibyte) corresponderá a sequência de caracteres que você escreveu para o fluxo de texto quando você criou o arquivo. Caso contrário, as funções de biblioteca podem remover um arquivo criado se o arquivo está vazio quando você fechá-lo. Ou pode alterar ou excluir caracteres gravados no arquivo.  
  
 Um fluxo binário consiste em um ou mais bytes de informações arbitrárias. É possível gravar o valor armazenado em um objeto arbitrário para um fluxo binário (orientado a bytes) e ler exatamente o que foi armazenado no objeto quando você o escreveu. As funções de biblioteca não alteram os bytes transmitidos entre o programa e um fluxo binário. No entanto, eles podem, acrescentar um número arbitrário de bytes nulos para o arquivo que você escreve com um fluxo binário. O programa precisa lidar com esses bytes nulos adicionais no final de qualquer fluxo binário.  
  
 Portanto, é bem definido, com exceção de posicionamento relativo ao final do fluxo de posicionamento em um fluxo binário. Você pode obter e alterar o indicador de posição do arquivo atual da mesma maneira que um fluxo de texto. Além disso, os deslocamentos usados por [ftell](../c-runtime-library/reference/ftell-ftelli64.md) e [fseek](../c-runtime-library/reference/fseek-fseeki64.md) contagem de bytes do início do fluxo (que é zero bytes) para operações aritméticas com esses deslocamentos inteiro produz resultados previsíveis.  
  
 Um fluxo de bytes trata um arquivo como uma sequência de bytes. Dentro do programa, o fluxo é semelhante a mesma sequência de bytes, exceto as possíveis alterações descritas acima.  
  
## <a name="see-also"></a>Consulte também  
 [Arquivos e fluxos](../c-runtime-library/files-and-streams.md)
