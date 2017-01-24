---
title: "Especifica&#231;&#245;es de caractere octa e hexadecimal | Microsoft Docs"
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
  - "caracteres hexadecimais"
  - "caracteres octais"
ms.assetid: 9264f3ec-46b8-41a5-b21a-8f7ed0a11871
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Especifica&#231;&#245;es de caractere octa e hexadecimal
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A sequência **\\***ooo* significa que você pode especificar qualquer caractere no conjunto de caracteres ASCII como um código de caracteres octal de três dígitos.  O valor numérico inteiro octal especifica o valor de caractere desejado ou do caractere largo.  
  
 De maneira semelhante, a sequência **\\x***hhh* permite especificar qualquer caractere ASCII como um código de caracteres hexadecimal.  Por exemplo, você pode atribuir o caractere de backspace ASCII como a sequência de escape C normal \(**\\b**\) ou codificá\-lo como **\\010** \(octal\) ou **\\x008** \(hexadecimal\).  
  
 Você pode usar somente os dígitos de 0 a 7 em uma sequência de escape octal.  As sequências de escape octais nunca poderão ser maiores do que três dígitos e são encerradas pelo primeiro caractere que não seja um dígito octal.  Embora não seja necessário usar todos os três dígitos, você deve usar pelo menos um.  Por exemplo, a representação octal é **\\10** para o caractere de backspace ASCII e **\\101** para a letra A, conforme atribuído em um gráfico ASCII.  
  
 De maneira semelhante, você deve usar pelo menos um dígito para uma sequência de escape hexadecimal, mas você pode omitir o segundo e o terceiro dígitos.  Portanto, você poderá especificar a sequência de escape hexadecimal para o caractere de backspace como **\\x8**, **\\x08** ou **\\x008**.  
  
 O valor da sequência de escape octal ou hexadecimal deve estar no intervalo de valores representáveis para o tipo **unsigned char** para uma constante de caractere e um tipo `wchar_t` para uma constante de caractere amplo.  Consulte [Caracteres multibytes e largos](../Topic/Multibyte%20and%20Wide%20Characters.md) para obter informações sobre constantes de caractere largo.  
  
 Ao contrário das constantes de escape octal, o número de dígitos hexadecimais em uma sequência de escape é ilimitado.  Uma sequência de escape hexadecimal é encerrada no primeiro caractere que não seja um dígito hexadecimal.  Como os dígitos hexadecimais incluem as letras **a** por meio de **f**, tenha atenção para garantir que a sequência de escape seja encerrada no dígito pretendido.  Para evitar confusão, você pode colocar definições octais ou hexadecimais de caracteres em uma definição de macro:  
  
```  
#define Bell '\x07'  
```  
  
 Para valores hexadecimais, você pode dividir a cadeia de caracteres para mostrar claramente o valor correto:  
  
```  
"\xabc"    /* one character  */  
"\xab" "c" /* two characters */  
```  
  
## Consulte também  
 [Constantes de caractere C](../Topic/C%20Character%20Constants.md)