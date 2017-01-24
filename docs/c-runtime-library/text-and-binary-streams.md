---
title: "Texto e fluxos bin&#225;rios | Microsoft Docs"
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
  - "fluxos binários"
  - "fluxos de texto"
ms.assetid: 57035e4a-955d-4e04-a560-fcf67ce68b4e
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Texto e fluxos bin&#225;rios
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um fluxo de texto consiste em uma ou mais linhas do texto que podem ser gravada em uma exibição de texto orientada para que possam ser lidas.  Ao ler de um fluxo de texto, o programa lê `NL` \(nova linha\) no final de cada linha.  Gravados em um fluxo de texto, o programa grava `NL` para sinalizar o final de uma linha.  Para corresponder convenções de diferentes entre ambientes de destino para representar texto em arquivos, funções da biblioteca podem alterar o número e as representações de caracteres passados entre o programa e um fluxo de texto.  
  
 Assim, posicione em um fluxo de texto é limitado.  Você pode obter o indicador atual de arquivo posição chamando [fgetpos](../c-runtime-library/reference/fgetpos.md) ou [ftell](../c-runtime-library/reference/ftell-ftelli64.md).  Você pode posicionar um fluxo de texto em uma posição obteve essa forma, ou o início ou término do fluxo, chamando [fsetpos](../Topic/fsetpos.md) ou [fseek](../c-runtime-library/reference/fseek-fseeki64.md).  Qualquer outra alteração da posição bem pode não haver suporte.  
  
 Para a portabilidade máximo, o programa não deve escrever:  
  
-   Arquivos vazios.  
  
-   Caracteres de espaço no final de uma linha.  
  
-   Linhas parciais \(omitindo `NL` no final de um arquivo\).  
  
-   caracteres diferentes de caracteres imprimíveis, de NL, e de `HT` \(guia horizontal\).  
  
 Se você segue estas regras, a sequência de caracteres que você leia de um fluxo de texto \(como caracteres de bytes ou multibyte\) corresponderá à sequência de caracteres escrever ao fluxo de texto quando você criou o arquivo.  Se não, funções da biblioteca podem remover um arquivo que você cria se o arquivo está vazio quando você fecha o.  Ou pode modificar ou excluir caracteres que você grava no arquivo.  
  
 Um fluxo binário consiste em um ou mais bytes de informações arbitrária.  Você pode escrever o valor armazenado em um objeto arbitrário para o fluxo binário de orientado a \(\) e ler exatamente o que foi armazenado no objeto quando você o escreveu.  Funções da biblioteca não alteram os bytes que você passa entre o programa e um fluxo binário.  Podem, no entanto, acrescente um número arbitrário de bytes nulos do arquivo que você grava com um fluxo binário.  O programa deve tratar desses bytes nulos adicionais ao final de qualquer fluxo binário.  
  
 Assim, posicione em um fluxo binário é bem definido, com exceção de posicionamento em relação ao fim do fluxo.  Você pode obter e alterar o indicador atual de arquivo posição da mesma maneira que o fluxo de texto.  Além disso, os deslocamentos usados por [ftell](../c-runtime-library/reference/ftell-ftelli64.md) e por [fseek](../c-runtime-library/reference/fseek-fseeki64.md) contagem de bytes do início do fluxo \(que é o byte zero\), a aritmética de inteiro nesses deslocamentos produzirá resultados previsíveis.  
  
 Um fluxo de bytes trata um arquivo com uma sequência de bytes.  No programa, o fluxo é semelhante à mesma sequência de bytes, com exceção das possíveis alterações descritas acima.  
  
## Consulte também  
 [Arquivos e fluxos](../c-runtime-library/files-and-streams.md)