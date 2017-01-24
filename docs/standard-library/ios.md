---
title: "&lt;ios&gt; | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "std.<ios>"
  - "std::<ios>"
  - "<ios>"
  - "ios/std::<ios>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Cabeçalho ios"
ms.assetid: d3d4c161-2f37-4f04-93cc-0a2a89984a9c
caps.latest.revision: 20
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# &lt;ios&gt;
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Define vários tipos e funções básicas para a operação do iostreams.  Esse cabeçalho é geralmente incluído para você por outra cabeçalhos de iostream; Você raramente incluí\-lo diretamente.  
  
## Sintaxe  
  
```  
  
#include <ios>  
  
```  
  
## Comentários  
 Um grande grupo de funções são manipuladores.  Um manipulador declarado em \< ios \> altera os valores armazenados em seu objeto de argumento da classe [ios\_base](../standard-library/ios-base-class.md).  Outros manipuladores de executam ações em fluxos controlados por objetos de um tipo derivado dessa classe, como uma especialização de uma das classes de modelo [basic\_istream](../Topic/basic_istream%20Class.md) ou [basic\_ostream](../Topic/basic_ostream%20Class.md).  Por exemplo, [noskipws](../Topic/noskipws.md)\(**str**\) limpa o sinalizador de formato `ios_base::skipws` no objeto **str**, que pode ser de um desses tipos.  
  
 Você também pode chamar um manipulador ao inseri\-la em um fluxo de saída ou extraí\-lo de um fluxo de entrada, devido a operações de inserção e extração especiais fornecidas para as classes derivadas de `ios_base`.  Por exemplo:  
  
```  
istr >> noskipws;  
```  
  
 chamadas [noskipws](../Topic/noskipws.md)\(**istr**\).  
  
### DefsTipo  
  
|||  
|-|-|  
|[ios](../Topic/ios.md)|Oferece suporte a classe ios da biblioteca iostream antigo.|  
|[streamoff](../Topic/streamoff.md)|Oferece suporte a operações internas.|  
|[streampos](../Topic/streampos.md)|Contém a posição atual do ponteiro de buffer ou ponteiro de arquivo.|  
|[streamsize](../Topic/streamsize.md)|Especifica o tamanho do fluxo.|  
|[wios](../Topic/wios.md)|Oferece suporte a classe wios da biblioteca iostream antigo.|  
|[wstreampos](../Topic/wstreampos.md)|Contém a posição atual do ponteiro de buffer ou ponteiro de arquivo.|  
  
### Manipuladores  
  
|||  
|-|-|  
|[boolalpha](../Topic/boolalpha.md)|Especifica que as variáveis do tipo [bool](../cpp/bool-cpp.md) aparecem como **true** ou **false** no fluxo.|  
|[dec](../Topic/dec.md)|Especifica que as variáveis integer aparecem na notação de 10 de base.|  
|[defaultfloat](../Topic/%3Cios%3E%20defaultfloat.md)|Configura os sinalizadores de uma `ios_base` objeto para usar um formato de exibição padrão para valores de ponto flutuante.|  
|[fixo](../Topic/fixed.md)|Especifica que um número de ponto flutuante é exibido em notação decimal fixo.|  
|[hex](../Topic/hex.md)|Especifica que as variáveis integer aparecem na notação de 16 base.|  
|[interno](../Topic/internal%20\(Standard%20C++%20Library\).md)|Faz com que o sinal de um número para ser justificado à esquerda e o número a ser justificado à direita.|  
|[esquerda](../Topic/left.md)|Faz com que o texto que não seja tão largo quando a largura da saída apareçam na liberação do fluxo com a margem esquerda.|  
|[noboolalpha](../Topic/noboolalpha.md)|Especifica que as variáveis do tipo [bool](../cpp/bool-cpp.md) aparecem como 1 ou 0 no fluxo.|  
|[noshowbase](../Topic/noshowbase.md)|Desativa indicando a notação base em que um número é exibido.|  
|[noshowpoint](../Topic/noshowpoint.md)|Exibe somente a parte de número inteiro de números de ponto flutuante cuja parte fracionária é zero.|  
|[noshowpos](../Topic/noshowpos.md)|Faz com que os números positivos não explicitamente sejam assinados.|  
|[noskipws](../Topic/noskipws.md)|Fazer com que os espaços a serem lidos pelo fluxo de entrada.|  
|[nounitbuf](../Topic/nounitbuf.md)|Causas de saída sejam armazenados em buffer e processadas quando o buffer estiver cheio.|  
|[nouppercase](../Topic/nouppercase.md)|Especifica que os dígitos hexadecimais e o expoente em notação científica aparecem em letras minúsculas.|  
|[oct](../Topic/oct%20\(%3Cios%3E\).md)|Especifica que as variáveis integer aparecem na notação 8 base.|  
|[direita](../Topic/right.md)|Faz com que o texto que não seja tão largo quando a largura da saída apareçam na liberação do fluxo com a margem direita.|  
|[científica](../Topic/scientific.md)|Causas números a serem exibidos usando notação científica de ponto flutuante.|  
|[showbase](../Topic/showbase.md)|Indica a notação base em que um número é exibido.|  
|[showpoint](../Topic/showpoint.md)|Exibe a parte de número inteiro de um número de ponto flutuante e dígitos à direita do ponto decimal, mesmo quando a parte fracionária é zero.|  
|[showpos](../Topic/showpos.md)|Faz com que os números positivos sejam assinados explicitamente.|  
|[skipws](../Topic/skipws.md)|Fazer com que espaços não sejam lidos pelo fluxo de entrada.|  
|[unitbuf](../Topic/unitbuf.md)|Causas de saída a serem processadas quando o buffer não está vazio.|  
|[maiúscula](../Topic/uppercase.md)|Especifica que os dígitos hexadecimais e o expoente em notação científica aparecem em maiúsculas.|  
  
### Classes  
  
|||  
|-|-|  
|[basic\_ios](../Topic/basic_ios%20Class.md)|A classe de modelo descreve as funções de membro e armazenamento comuns para ambos os fluxos de entrada \(classe de modelo [basic\_istream](../Topic/basic_istream%20Class.md)\) e fluxos de saída \(classe de modelo [basic\_ostream](../Topic/basic_ostream%20Class.md)\) que dependem dos parâmetros do modelo.|  
|[fpos](../Topic/fpos%20Class.md)|A classe de modelo descreve um objeto que pode armazenar todas as informações necessárias para restaurar um indicador de posição de arquivo arbitrário em qualquer fluxo.|  
|[ios\_base](../standard-library/ios-base-class.md)|A classe descreve o armazenamento e funções de membro fluxos comuns a entrada e saída que não dependem dos parâmetros do modelo.|  
  
## Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Programação iostream](../Topic/iostream%20Programming.md)   
 [Convenções iostreams](../standard-library/iostreams-conventions.md)