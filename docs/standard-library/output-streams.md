---
title: "Fluxos de Sa&#237;da | Microsoft Docs"
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
  - "fluxos de saída"
ms.assetid: b49410e3-5caa-4153-9d0d-c4266408dc83
caps.latest.revision: 12
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Fluxos de Sa&#237;da
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um objeto de fluxo de saída é um destino para bytes.  As três classes as mais importantes do fluxo de saída são `ostream`, `ofstream`, e `ostringstream`.  
  
 A classe de `ostream` , pela classe derivada, `basic_ostream`oferece suporte aos objetos predefinidos de fluxo:  
  
-   saída padrão de`cout`  
  
-   erro padrão de`cerr`com proteção limitada  
  
-   `clog` semelhante a `cerr` mas com proteção completa  
  
 Os objetos são construídos com pouca frequência de `ostream`; os objetos predefinidos geralmente são usados.  Em alguns casos, você pode reatribuir objetos predefinidos após a inicialização do programa.  A classe de `ostream` , que pode ser configurada para a operação em buffer ou não armazenado, é mais adequada para a saída sequenciais em modo gráfico.  Toda a funcionalidade da classe base, `ios`, é incluída em `ostream`.  Se você criar um objeto da classe `ostream`, você deve especificar um objeto de `streambuf` para o construtor.  
  
 A classe de `ofstream` oferece suporte a saídas do arquivo em disco.  Se você precisar de um disco de saída somente leitura, construir um objeto da classe `ofstream`.  Você pode especificar se os objetos de `ofstream` aceitam binário ou os dados do modo gráfico para construir o objeto de `ofstream` ou ao chamar a função de membro de `open` do objeto.  Muitas opções e funções de membro de formatação aplicam a `ofstream` objetos, e todas as funcionalidades das classes base `ios` e `ostream` será incluída.  
  
 Se você especificar um nome de arquivo no construtor, esse arquivo é aberto automaticamente quando o objeto é construído.  Se não, você pode usar a função de membro de `open` invocado depois do construtor padrão.  
  
 Como a função `sprintf_s`de tempo de execução, a classe de `ostringstream` oferece suporte a saídas em cadeias de caracteres de memória.  Para criar uma cadeia de caracteres na memória usando a formatação do fluxo de E\/S, construir um objeto da classe `ostringstream`.  
  
## Nesta seção  
 [Construindo objetos de fluxo de saída](../Topic/Constructing%20Output%20Stream%20Objects.md)  
  
 [Usando operadores de inserção e controlando o formato](../standard-library/using-insertion-operators-and-controlling-format.md)  
  
 [Funções de Membro de Fluxo de Arquivo de Saída](../standard-library/output-file-stream-member-functions.md)  
  
 [Efeitos do buffer](../standard-library/effects-of-buffering.md)  
  
 [Arquivos de Saída Binários](../standard-library/binary-output-files.md)  
  
 [Sobrecarregando o operador \<\< para as suas próprias classes](../Topic/Overloading%20the%20%3C%3C%20Operator%20for%20Your%20Own%20Classes.md)  
  
 [Elaborando os seus próprios manipuladores sem argumentos](../standard-library/writing-your-own-manipulators-without-arguments.md)  
  
## Consulte também  
 [\<ostream\> Membros](http://msdn.microsoft.com/pt-br/a5afd034-0e3c-41ee-bbd7-468d9188da1d)   
 [ofstream](../Topic/ofstream.md)   
 [ostringstream](../Topic/ostringstream.md)   
 [os membros do basic\_ostream](http://msdn.microsoft.com/pt-br/82e5cc91-7c0c-4950-a8ce-ac779cfbbd93)   
 [Programação iostream](../Topic/iostream%20Programming.md)