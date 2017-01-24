---
title: "Constantes de ponto flutuante C | Microsoft Docs"
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
  - "constantes, ponto flutuante"
  - "tipo de dados double, constantes de ponto flutuante"
  - "constantes de ponto flutuante"
  - "constantes de ponto flutuante, sobre constantes de ponto flutuante"
  - "números de ponto flutuante, constantes de ponto flutuante"
  - "tipos [C], constantes"
ms.assetid: e1bd9b44-d6ab-470c-93e5-07142c7a2062
caps.latest.revision: 12
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Constantes de ponto flutuante C
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma "constante de ponto flutuante" é um número decimal que representa um número real assinado.  A representação de um número real assinado inclui uma parte inteira, uma parte fracionária e um expoente.  Use as constantes de ponto flutuante para representar os valores de ponto flutuante que não podem ser alterados.  
  
## Sintaxe  
 *floating\-point\-constant*:  
 *fractional\-constant exponent\-part*  opt *floating\-suffix* opt  
  
 *digit\-sequence exponent\-part floating\-suffix*  opt  
  
 *fractional\-constant*:  
 *digit\-sequence*  opt **.** *digit\-sequence*  
  
 *digit\-sequence*  **.**  
  
 *exponent\-part*:  
 **e**  *sign*  opt *digit\-sequence*  
  
 **E**  *sign*  opt *digit\-sequence*  
  
 *sign* : one of  
 **\+ –**  
  
 *digit\-sequence*:  
 *digit*  
  
 *digit\-sequence digit*  
  
 *floating\-suffix* : one of  
 **f l F L**  
  
 Você pode omitir os dígitos anteriores ao ponto decimal \(a parte inteira do valor\) ou posteriores \(a parte fracionária\), mas não ambos.  Você pode retirar o ponto decimal apenas se incluir um expoente.  Nenhum caractere de espaço em branco pode separar os dígitos ou caracteres da constante.  
  
 Os exemplos a seguir ilustram alguns formatos de constantes de ponto flutuante e expressões:  
  
```  
15.75  
1.575E1   /* = 15.75   */  
1575e-2   /* = 15.75   */  
-2.5e-3   /* = -0.0025 */  
25E-4     /* =  0.0025 */  
```  
  
 As constantes de ponto flutuante são positivas a menos que sejam precedidas por um sinal de subtração \(**–**\).  Nesse caso, o sinal de subtração é tratado como um operador aritmético unário de negação.  As constantes de ponto flutuante têm o tipo **float**, **double** ou `long double`.  
  
 Uma constante de ponto flutuante sem **f**, **F**, **l** ou sufixo **L** tem o tipo **double**.  Se a letra **f** ou **F** for o sufixo, a constante tem o tipo **float**.  Se o sufixo for a letra **l** ou **L**, tem o tipo `long double`.  Por exemplo:  
  
```  
100L  /* Has type long double  */  
100F  /* Has type float        */  
```  
  
 Observe que o compilador C da Microsoft mapeia o tipo **long double** para **double**.  Consulte [Armazenamento de tipos básicos](../c-language/storage-of-basic-types.md) para obter mais informações sobre os tipos **double**, **float** e **long**.  
  
 Você pode omitir a parte inteira da constante de ponto flutuante, como mostrado nos seguintes exemplos.  O número .75 pode ser expressado de várias maneiras, incluindo:  
  
```  
.0075e2  
0.075e1  
.075e1  
75e-2  
```  
  
## Consulte também  
 [Constantes C](../c-language/c-constants.md)