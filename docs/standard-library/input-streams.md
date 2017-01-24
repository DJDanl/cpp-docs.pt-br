---
title: "Fluxos de entrada | Microsoft Docs"
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
  - "dados [C++], lendo de fluxo de entrada"
  - "objetos de fluxo de entrada"
  - "fluxos de entrada"
  - "lendo dados [C++], de fluxos de entrada"
ms.assetid: f14d8954-8f8c-4c3c-8b99-14ddb3683f94
caps.latest.revision: 11
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Fluxos de entrada
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um objeto do fluxo de entrada é uma origem de bytes.  As três classes as mais importantes do fluxo de entrada são [istream](http://msdn.microsoft.com/pt-br/6801779e-260e-416d-b4ec-fef5ff1b2371), [ifstream](../Topic/ifstream.md), e [istringstream](../Topic/istringstream.md).  
  
 A classe de `istream` é usada melhor para a entrada sequencial de modo gráfico.  Você pode configurar objetos da classe `istream` para a operação em buffer ou não armazenado.  Toda a funcionalidade da classe base, `ios`, é incluída em `istream`.  Você construirá raramente objetos da classe `istream`.  Em vez disso, você usará geralmente o objeto predefinido de `cin` , que é realmente um objeto da classe [ostream](../standard-library/ostream.md).  Em alguns casos, você pode atribuir `cin` a outros objetos de fluxo após a inicialização do programa.  
  
 A classe de `ifstream` oferece suporte à entrada do arquivo em disco.  Se você precisar de um arquivo de disco de entrada somente leitura, construir um objeto da classe `ifstream`.  Você pode especificar binário ou os dados do modo gráfico.  Se você especificar um nome de arquivo no construtor, o arquivo é aberto automaticamente quando o objeto é construído.  Se não, você pode usar a função de `open` invocado depois do construtor padrão.  Muitas opções e funções de membro de formatação aplicam a `ifstream` objetos.  Toda a funcionalidade das classes base `ios` e `istream` é incluída em `ifstream`.  
  
 Como a função de biblioteca `sscanf_s`, a classe de `istringstream` oferece suporte à entrada de cadeias de caracteres de memória.  Para extrair dados de uma matriz de caractere que tem um terminador nulo, aloque e inicializar a cadeia de caracteres, então construir um objeto da classe `istringstream`.  
  
## Nesta seção  
 [Construindo objetos de fluxo de entrada](../Topic/Constructing%20Input%20Stream%20Objects.md)  
  
 [Usando operadores de extração](../Topic/Using%20Extraction%20Operators.md)  
  
 [Testando erros de extração](../standard-library/testing-for-extraction-errors.md)  
  
 [Manipuladores de Fluxo de Entrada](../standard-library/input-stream-manipulators.md)  
  
 [Funções de Membro de Fluxo de Entrada](../standard-library/input-stream-member-functions.md)  
  
 [Sobrecarregando o operador \>\> para as suas próprias classes](../standard-library/overloading-the-input-operator-for-your-own-classes.md)  
  
## Consulte também  
 [Programação iostream](../Topic/iostream%20Programming.md)