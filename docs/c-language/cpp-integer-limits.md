---
title: "Limites de inteiro C++ | Microsoft Docs"
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
  - "limites de inteiros"
  - "limites, inteiro"
  - "limites, constantes de inteiros"
ms.assetid: 0c23cbd6-29fb-4d9c-b689-5984e19748de
caps.latest.revision: 11
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Limites de inteiro C++
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Os limites para tipos de inteiros estão listadas na tabela a seguir.  Esses limites são definidos no arquivo de cabeçalho padrão LIMITS.H.  O Microsoft C também permite a declaração de variáveis de inteiro dimensionadas, que são tipos integrais de 8, 16 ou 32 bits de tamanho.  Para obter mais informações sobre inteiros dimensionados, consulte [Tipos de inteiros dimensionados](../c-language/c-sized-integer-types.md).  
  
### Limites em constantes de inteiro  
  
|**Constante**|Significado|Valor|  
|-------------------|-----------------|-----------|  
|**CHAR\_BIT**|Número de bits na menor variável que não é um campo de bit.|8|  
|**SCHAR\_MIN**|Valor mínimo para uma variável do tipo **signed char**.|–128|  
|**SCHAR\_MAX**|Valor máximo para uma variável do tipo **signed char**.|127|  
|**UCHAR\_MAX**|Valor máximo para uma variável do tipo `unsigned char`.|255 \(0xff\)|  
|**CHAR\_MIN**|Valor mínimo para uma variável do tipo `char`.|–128; 0 se a opção \/J for usada|  
|**CHAR\_MAX**|Valor máximo para uma variável do tipo `char`.|127; 255 se a opção \/J for usada|  
|**MB\_LEN\_MAX**|Número máximo de bytes em uma constante de vários caracteres.|5|  
|**SHRT\_MIN**|Valor mínimo para uma variável do tipo **short**.|–32768|  
|**SHRT\_MAX**|Valor máximo para uma variável do tipo **short**.|32767|  
|**USHRT\_MAX**|Valor máximo para uma variável do tipo **unsigned short**.|65535 \(0xffff\)|  
|**INT\_MIN**|Valor mínimo para uma variável do tipo `int`.|–2147483647 – 1|  
|**INT\_MAX**|Valor máximo para uma variável do tipo `int`.|2147483647|  
|**UINT\_MAX**|Valor máximo para uma variável do tipo `unsigned int`.|4294967295 \(0xffffffff\)|  
|**LONG\_MIN**|Valor mínimo para uma variável do tipo **long**.|–2147483647 – 1|  
|**LONG\_MAX**|Valor máximo para uma variável do tipo **long**.|2147483647|  
|**ULONG\_MAX**|Valor máximo para uma variável do tipo `unsigned long`.|4294967295 \(0xffffffff\)|  
  
 Se um valor exceder a representação do maior inteiro, o compilador da Microsoft gera um erro.  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [Constantes de inteiro C](../Topic/C%20Integer%20Constants.md)