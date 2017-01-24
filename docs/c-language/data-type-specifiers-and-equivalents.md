---
title: "Especificadores de tipo de dados e equivalentes | Microsoft Docs"
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
  - "tipos de dados [C++], equivalentes"
  - "tipos de dados [C++], especificadores"
  - "identificadores,   (tipo de dados)"
  - "tipos integrais de sinal estendido"
  - "tipos simples, nomes"
  - "nomes de tipos [C++], simples"
  - "especificadores de tipo [C++], list"
  - "inteiros de ampliação"
  - "extensão de zero"
ms.assetid: 0d4b515a-4f68-4786-83cf-a5d43c7cb6f3
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Especificadores de tipo de dados e equivalentes
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este manual geralmente usa os formatos dos especificadores de tipo listados na tabela a seguir em vez dos formatos longos, e presume que o tipo `char` seja com sinal por padrão.  Portanto, ao longo deste manual, `char` é equivalente a **signed char**.  
  
### Especificadores e equivalentes de tipo  
  
|Especificador de tipo|Equivalente\(s\)|  
|---------------------------|----------------------|  
|**signed char**1|`char`|  
|**signed int**|**signed**, `int`|  
|**signed short int**|**short**, `signed short`|  
|**signed long int**|**long**, **signed long**|  
|`unsigned char`|—|  
|`unsigned int`|`unsigned`|  
|**unsigned short int**|**unsigned short**|  
|**unsigned long int**|`unsigned long`|  
|**float**|—|  
|`long double`2|—|  
  
 1   Quando você tornar o tipo `char` sem sinal por padrão \(especificando a opção do compilador \/J\), você não poderá abreviar **signed char** como `char`.  
  
 2   Em sistemas operacionais de 32 bits, o compilador Microsoft C mapeia o tipo **long double** para o tipo **double**.  
  
 **Específico da Microsoft**  
  
 Você pode especificar a opção do compilador \/J para alterar o tipo `char` padrão de com sinal para sem sinal.  Quando essa opção é aplicada, `char` significa o mesmo que `unsigned char`, e você deve usar a palavra\-chave **signed** para declarar um valor de caractere com sinal.  Se um valor `char` for declarado explicitamente com sinal, a opção \/J não o afetará, e o valor será estendido com sinal quando ampliado para um tipo `int`.  O tipo `char` é estendido em zero quando ampliado para o tipo `int`.  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [Especificadores de tipo C](../c-language/c-type-specifiers.md)