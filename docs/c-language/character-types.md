---
title: "Tipos de caractere | Microsoft Docs"
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
  - "tipos de dados de caracteres [C]"
  - "tipos [C], caractere"
ms.assetid: d3ca8cda-c0d7-43af-9472-697e8ef015ce
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Tipos de caractere
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma constante de caractere inteiro não precedida pela letra **L** tem o tipo `int`.  O valor de uma constante de caractere inteiro que contém um único caractere é o valor numérico do caractere interpretado como um inteiro.  Por exemplo, o valor numérico do caractere `a` é 97 em decimal e 61 em hexadecimal.  
  
 Sintaticamente, “uma constante de caractere largo” é uma constante de caractere com a letra **L** de prefixo.  Uma constante de caractere largo tem o tipo `wchar_t`, um tipo de inteiro definido no arquivo de cabeçalho STDDEF.H.  Por exemplo:  
  
```  
char    schar =  'x';   /* A character constant          */  
wchar_t wchar = L'x';   /* A wide-character constant for   
                            the same character           */  
```  
  
 As constantes de caractere largo têm 16 bits de largura e especificam membros do conjunto estendido de caracteres de execução.  Elas permitem que você expresse caracteres em alfabetos que são muito grandes para serem representados pelo tipo `char`.  Consulte [Multibyte e caracteres largos](../Topic/Multibyte%20and%20Wide%20Characters.md) para obter mais informações sobre os caracteres largos.  
  
## Consulte também  
 [Constantes de caractere C](../Topic/C%20Character%20Constants.md)