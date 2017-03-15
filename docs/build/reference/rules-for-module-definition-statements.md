---
title: "Regras para instru&#231;&#245;es de defini&#231;&#227;o do m&#243;dulo | Microsoft Docs"
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
  - ".def"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "arquivos de definição de módulo"
  - "arquivos de definição de módulo, sintaxe de instrução"
ms.assetid: f65cd3a7-65d7-4d06-939f-a8b1ecd50f2d
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Regras para instru&#231;&#245;es de defini&#231;&#227;o do m&#243;dulo
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

As seguintes regras de sintaxe se aplicam a todas as instruções em um arquivo .def.  Outras regras que se aplicam a instruções específicas são descritas com cada instrução.  
  
-   As instruções, as palavras\-chave de atributo, e os identificadores especificados pelo usuário diferenciam maiúsculas de minúsculas.  
  
-   Os nomes de arquivo longos que contêm espaços ou ponto\-e\-vírgula \(;\) devem ser incluídos entre aspas \("\).  
  
-   Use um ou mais espaços, guias, ou caracteres de nova linha para separar uma palavra\-chave da instrução de seus argumentos e para separar instruções do.  Dois\-pontos \(:\) ou sinal de igual \(\=\) que designa um argumento é cercado por zero ou mais espaços, guias, ou caracteres de nova linha.  
  
-   Uma instrução de **NOME** ou de **BIBLIOTECA** , se usado, deve preceder todas as outras instruções.  
  
-   As instruções de **SECTIONS** e de **EXPORTS** podem aparecer mais de uma vez no arquivo .def.  Cada instrução pode levar várias especificações, que devem ser separadas por um ou mais espaços, guias, ou caracteres de nova linha.  A palavra\-chave da instrução deve aparecer uma vez antes da primeira especificação e pode ser repetido antes de cada especificação adicional.  
  
-   Muitas instruções têm uma opção de linha de comando equivalente de LINK.  Consulte a descrição da opção do LINK para obter mais detalhes.  
  
-   Os comentários no arquivo .def são designados por um ponto\-e\-vírgula \(;\) no início de cada linha de comentário.  Um comentário não pode compartilhar uma linha com uma instrução, mas pode aparecer entre as especificações em uma instrução multilinha. \(**SECTIONS** e **EXPORTS** são instruções multilinha.\)  
  
-   Os argumentos numéricos são especificados na base 10 ou hexadecimal.  
  
-   Se um argumento de cadeia de caracteres, corresponde [palavras reservadas](../../build/reference/reserved-words.md)deve ser incluído entre aspas duplas \("\).  
  
## Consulte também  
 [Arquivos de definição do módulo \(.Def\)](../Topic/Module-Definition%20\(.Def\)%20Files.md)   
 [Frequently Asked Questions on Building](http://msdn.microsoft.com/pt-br/56a3bb8f-0181-4989-bab4-a07ba950ab08)