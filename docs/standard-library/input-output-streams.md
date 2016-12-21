---
title: "Fluxos de Entrada/Sa&#237;da | Microsoft Docs"
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
  - "E/S [C++], fluxo"
  - "E/S de fluxo"
ms.assetid: 21a97566-91a7-42d6-b2f8-a4c16bc926f1
caps.latest.revision: 11
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Fluxos de Entrada/Sa&#237;da
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

`basic_iostream`, que é definido no istream\>do \<arquivo de cabeçalho, será o modelo da classe para os objetos que manipulam fluxos baseados em caracteres de E\/S de entrada e saída.  
  
 Há dois typedefs que definem especializações caracteres específicas de `basic_iostream` e podem ajudar a facilitar o código ser: `iostream` \(para não ser confundido com o iostream do\>arquivo \<de cabeçalho\) é um fluxo de E\/S baseado em `basic_iostream<char>`; `wiostream` é um fluxo de E\/S baseado em `basic_iostream<wchar_t>`.  
  
 Para obter mais informações, consulte [Classe basic\_iostream](../standard-library/basic-iostream-class.md), [iostream](../Topic/iostream.md) e [wiostream](../Topic/wiostream.md).  
  
 Derivar de `basic_iostream` é o modelo `basic_fstream`da classe, que é usado para transmitir dados de caractere a e arquivos.  
  
 Também há typedefs que fornecem especializações caracteres específicas de `basic_fstream`.  São `fstream`, que é um fluxo de E\/S de arquivo baseado em `char`, e `wfstream`, que é um fluxo de E\/S de arquivo baseado em `wchar_t`.  Para obter mais informações, consulte [Classe basic\_fstream](../standard-library/basic-fstream-class.md), [fstream](../Topic/fstream.md) e [wfstream](../Topic/wfstream.md).  Usar esses typedefs requer a inclusão de fstream do arquivo \<de cabeçalho\>.  
  
> [!NOTE]
>  Quando um objeto de `basic_fstream` é usado para executar o arquivo E\/S, embora o buffer subjacente contém posições separada designadas para leitura e gravação, as posições de entrada atual e de saída atual são vinculadas em conjunto e, consequentemente, leia a movimentação de dados a posição de saída.  
  
 O modelo `basic_stringstream` da classe e a especialização comuns, `stringstream`, geralmente são usados para trabalhar com objetos de fluxo de E\/S para inserir e extrair dados de caractere.  Para obter mais informações, consulte [Classe basic\_stringstream](../standard-library/basic-stringstream-class.md).  
  
## Consulte também  
 [stringstream](../Topic/stringstream.md)   
 [Classe basic\_stringstream](../standard-library/basic-stringstream-class.md)   
 [\<sstream\>](../standard-library/sstream.md)   
 [Programação iostream](../Topic/iostream%20Programming.md)   
 [Biblioteca Padrão C\+\+](../standard-library/cpp-standard-library-reference.md)