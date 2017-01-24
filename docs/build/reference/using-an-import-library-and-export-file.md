---
title: "Usando uma biblioteca de importa&#231;&#227;o e um arquivo de exporta&#231;&#227;o | Microsoft Docs"
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
helpviewer_keywords: 
  - "exportações circulares"
  - "exportar arquivos"
  - "importar bibliotecas, usando"
ms.assetid: 2634256a-8aa5-4495-8c9e-6cde10e4ed76
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Usando uma biblioteca de importa&#231;&#227;o e um arquivo de exporta&#231;&#227;o
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Quando um programa \(um arquivo executável ou DLL\) exporta a outro programa que também importar, ou se mais de dois programas a exportação e importação de se, os comandos vincular esses programas devem acomodar exporta circulares.  
  
 Em uma situação sem exporta circulares, ao vincular um programa que usa a exportações de outro programa, você deve especificar a biblioteca de importação para o programa exportando.  A biblioteca de importação para o programa exportando é criada quando você vincula o que exporta o programa.  Em virtude disso, você deve vincular o programa exportando antes que o programa importação.  Por exemplo, se as importações de ONE.dll de TWO.dll, você primeiro deve vincular ONE.dll e obter a biblioteca ONE.lib de importação.  Em seguida, você especifica ONE.lib ao vincular TWO.dll.  Quando o vinculador cria TWO.dll, o também cria a biblioteca de importação, TWO.lib.  Use TWO.lib ao vincular os programas de importação de TWO.dll.  
  
 No entanto, em uma situação circular de exportação, não é possível vincular todos os programas interdependentes usando bibliotecas de importação de outros programas.  No exemplo discutido anterior, se TWO.dll exporta igualmente a ONE.dll, a biblioteca de importação para TWO.dll não existirá ainda quando ONE.dll está vinculado.  Quando as exporta circulares existirem, você deve usar o LIB para criar uma biblioteca de importação e um arquivo de exportação para um dos programas.  
  
 Para iniciar, escolha um dos programas no qual executar o LIB.  No comando de LIB, listar todos os objetos e bibliotecas para o programa e especifique \/DEF.  Se o programa usa um arquivo .def ou especificações de \/EXPORT, especifique esses também.  
  
 Depois que você criar a biblioteca de importação \(.lib\) e o arquivo de exportação \(.exp\) do programa, você usa a biblioteca de importação para vincular outro programa ou programas.  O LINK cria uma biblioteca de importação para cada programa que exportando cria.  Por exemplo, se você executar o LIB nos objetos e exportações em para ONE.dll, você cria ONE.lib e ONE.exp.  Agora você pode usar ONE.lib ao vincular TWO.dll; esta etapa também cria a biblioteca TWO.lib de importação.  
  
 Finalmente, vincular o programa que você iniciou com.  No comando de LINK, especifique os objetos e as bibliotecas do programa, o arquivo de .exp que o LIB criou para o programa, e a biblioteca ou as bibliotecas de importação para as exporta usadas pelo programa.  Para retomar o exemplo, o comando de LINK para ONE.dll contém ONE.exp e TWO.lib, assim como os objetos e as bibliotecas que entram em ONE.dll.  Não especifique o arquivo .def ou as especificações do \/EXPORT no comando de LINK; eles não são necessários, como as definições de exportação estão contidas no arquivo de .exp.  Ao vincular usando um arquivo de .exp, o LINK não cria uma biblioteca de importação, porque assume que uma esteve criado quando o arquivo de .exp foi criado.  
  
## Consulte também  
 [Trabalhando com bibliotecas de importação e arquivos de exportação](../../build/reference/working-with-import-libraries-and-export-files.md)