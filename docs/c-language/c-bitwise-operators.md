---
title: "Operadores bit a bit C | Microsoft Docs"
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
  - "Operador &, operadores bit a bit"
  - "Operador ^"
  - "Operador ^, operadores bit a bit"
  - "Operador |, operadores bit a bit"
  - "Operador ampersand (&)"
  - "Operador AND"
  - "operadores bit a bit"
  - "operadores bit a bit, Visual C"
  - "operadores [C], bit a bit"
ms.assetid: e22127b1-9a2d-4876-b01d-c8f72cec3317
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Operadores bit a bit C
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os operadores bit a bit executam as operações E bit a bit \(**&**\), OR exclusivo bit a bit \(**^**\) e OR inclusivo bit a bit \(       **&#124;** \).  
  
 **Sintaxe**  
  
 *expressão AND*:  
 *expressão de igualdade*  
  
 *expressão AND*  **&**  *expressão de igualdade*  
  
 *expressão OR exclusiva*:  
 *expressão AND*  
  
 *expressão OR exclusiva*  **^**  *expressão AND*  
  
 *expressão OR inclusiva*:  
 *expressão OR exclusiva*  
  
 *expressão OR inclusiva:* &#124; *expressão OR exclusiva*  
  
 Os operandos dos operadores bit a bit devem ter tipos integrais, mas seus tipos podem ser diferentes.  Esses operadores executam conversões aritméticas comuns; o tipo do resultado é o tipo dos operandos após a conversão.  
  
 Os operadores bit a bit de C são descritos abaixo:  
  
|Operador|Descrição|  
|--------------|---------------|  
|**&**|O operador AND bit a bit compara cada bit do primeiro operando com o bit correspondente de seu segundo operando.  Se os dois bits forem 1, o bit de resultado correspondente será definido como 1.  Caso contrário, o bit de resultado correspondente será definido como 0.|  
|**^**|O operador OR exclusivo bit a bit compara cada bit do primeiro operando ao bit correspondente do seu segundo operando.  Se um bit for 0 e o outro bit for 1, o bit resultante correspondente será definido como 1.  Caso contrário, o bit de resultado correspondente será definido como 0.|  
|**&#124;**|O operador OR inclusivo bit a bit compara cada bit do primeiro operando com o bit correspondente de seu segundo operando.  Se um bit for 1, o bit de resultado correspondente será definido como 1.  Caso contrário, o bit de resultado correspondente será definido como 0.|  
  
## Exemplos  
 Essas declarações são usadas para os três exemplos a seguir:  
  
```  
short i = 0xAB00;  
short j = 0xABCD;  
short n;  
  
n = i & j;  
```  
  
 O resultado atribuído a `n` neste primeiro exemplo é o mesmo que `i` \(0xAB00 hexadecimal\).  
  
```  
n = i | j;  
  
n = i ^ j;  
```  
  
 O operador OR inclusivo bit a bit no segundo exemplo resulta no valor 0xABCD \(hexadecimal\), enquanto o OU exclusivo bit a bit no terceiro exemplo gerencia 0xCD \(hexadecimal\).  
  
 **Específico da Microsoft**  
  
 Os resultados de operação bit a bit em números inteiros assinados é definido pela implementação de acordo com o padrão ANSI C.  Para o compilador C da Microsoft, as operações bit a bit em números inteiros assinados funcionam da mesma forma que as operações bit a bit em inteiros não assinados.  Por exemplo, `-16 & 99` pode ser expresso em binário como  
  
```  
  11111111 11110000  
& 00000000 01100011  
  _________________  
  00000000 01100000  
```  
  
 O resultado do E bit a bit é decimal 96.  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [Operador AND bit a bit: &](../cpp/bitwise-and-operator-amp.md)   
 [Operador OR exclusivo bit a bit: ^](../cpp/bitwise-exclusive-or-operator-hat.md)   
 [Operador OR inclusivo bit a bit: &#124;](../cpp/bitwise-inclusive-or-operator-pipe.md)