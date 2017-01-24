---
title: "Tipos de inteiro | Microsoft Docs"
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
  - "constantes de inteiros"
  - "tipo de dados inteiro, tipos de inteiros em C++"
  - "tipos de inteiros"
  - "números inteiros, tipos"
ms.assetid: c8926a5e-0e98-4e37-9b05-ce97961379bd
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Tipos de inteiro
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Cada constante de inteiro recebe um tipo baseado no seu valor e na forma como é expressa.  Você pode forçar qualquer constante inteira para o tipo **long** anexando a letra **l** ou **L** ao final da constante; você pode forçar seu tipo como `unsigned` anexando **u** ou **U** ao valor.  A letra minúscula **l** pode ser confundida com o dígito 1 e deve ser evitada.  Alguns formatos de constantes de inteiro de **long** são as seguintes:  
  
```  
/* Long decimal constants */  
10L  
79L  
  
/* Long octal constants */  
012L  
0115L  
  
/* Long hexadecimal constants */  
0xaL or 0xAL  
0X4fL or 0x4FL  
  
/* Unsigned long decimal constant */  
776745UL  
778866LU  
```  
  
 O tipo que você atribui a uma constante depende do valor que a constante representa.  O valor de uma constante deve estar no intervalo de valores representáveis para o seu tipo.  Um tipo de constante que determina quais conversões são executadas quando a constante é usada em uma expressão ou quando o sinal de subtração \(**–**\) é aplicado.  Esta lista resume as regras de conversão para constantes de número inteiro.  
  
-   O tipo de uma constante decimal sem um sufixo é `int`, **long int** ou **unsigned long int**.  O primeiro destes três tipos em que o valor da constante pode ser representado é o tipo atribuído à constante.  
  
-   O tipo atribuído às constantes octais e hexadecimais sem sufixos é `int`, `unsigned int`, **long int** ou **unsigned long int** , dependendo do tamanho da constante.  
  
-   O tipo atribuído às constantes com sufixo **u** ou **U** é **unsigned int** ou **unsigned long int** , dependendo do tamanho.  
  
-   O tipo atribuído às constantes com sufixo **l** ou **L** é **long int** ou **unsigned long int** , dependendo do tamanho.  
  
-   O tipo atribuído às constantes com sufixo **u** ou **U** e **l** ou **L** é **unsigned long int**.  
  
## Consulte também  
 [Constantes de inteiro C](../Topic/C%20Integer%20Constants.md)