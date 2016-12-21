---
title: "Limites flutuantes | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "arquivo de cabeçalho FLOAT.H"
  - "constantes de ponto flutuante, limites"
  - "números de ponto flutuante, limites flutuantes"
  - "limites, constantes de ponto flutuante"
  - "intervalos, constantes de ponto flutuante"
ms.assetid: fc718652-1f4c-4ed8-af60-0e769637459c
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Limites flutuantes
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 A tabela a seguir lista os limites nos valores de constantes de ponto flutuante.  Esses limites também são definidos no arquivo de cabeçalho padrão FLOAT.H.  
  
### Limites em constantes de ponto flutuante  
  
|Constante|Significado|Valor|  
|---------------|-----------------|-----------|  
|FLT\_DIG DBL\_DIG LDBL\_DIG|Número de dígitos, q, de modo que um número de ponto flutuante com dígitos decimais de q possam ser arredondados em uma representação de ponto flutuante e de volta sem perda de precisão.|6 15 15|  
|FLT\_EPSILON DBL\_EPSILON LDBL\_EPSILON|O menor número positivo x, de modo que x \+ 1,0 não é igual a 1,0.|1.192092896e–07F 2.2204460492503131e–016 2.2204460492503131e–016|  
|FLT\_GUARD||0|  
|FLT\_MANT\_DIG DBL\_MANT\_DIG LDBL\_MANT\_DIG|Número de dígitos na raiz especificada por FLT\_RADIX em significando de ponto flutuante.  A raiz é 2; portanto, esses valores especificam bits.|24 53 53|  
|FLT\_MAX DBL\_MAX LDBL\_MAX|Número de ponto flutuante representável máximo.|3.402823466e\+38F 1.7976931348623158e\+308 1.7976931348623158e\+308|  
|FLT\_MAX\_10\_EXP DBL\_MAX\_10\_EXP LDBL\_MAX\_10\_EXP|Inteiro máximo de modo que 10 gerados para esse número sejam um número de ponto flutuante representável.|38 308 308|  
|FLT\_MAX\_EXP DBL\_MAX\_EXP LDBL\_MAX\_EXP|Inteiro máximo de modo que FLT\_RADIX gerado para esse número seja um número de ponto flutuante representável.|128 1024 1024|  
|FLT\_MIN DBL\_MIN LDBL\_MIN|Valor positivo mínimo.|1.175494351e–38F 2.2250738585072014e–308 2.2250738585072014e–308|  
|FLT\_MIN\_10\_EXP DBL\_MIN\_10\_EXP LDBL\_MIN\_10\_EXP|Inteiro negativo mínimo de modo que 10 gerados para esse número sejam um número de ponto flutuante representável.|–37<br /><br /> –307<br /><br /> –307|  
|FLT\_MIN\_EXP DBL\_MIN\_EXP LDBL\_MIN\_EXP|Inteiro negativo mínimo de modo que FLT\_RADIX gerado para esse número seja um número de ponto flutuante representável.|–125<br /><br /> –1021<br /><br /> –1021|  
|FLT\_NORMALIZE||0|  
|FLT\_RADIX \_DBL\_RADIX \_LDBL\_RADIX|Raiz de representação do expoente.|2 2 2|  
|FLT\_ROUNDS \_DBL\_ROUNDS \_LDBL\_ROUNDS|Arredondamento do modo para a adição de ponto flutuante.|1 \(aproximado\) 1 \(aproximado\) 1 \(aproximado\)|  
  
> [!NOTE]
>  As informações da tabela podem ser diferente em versões futuras do produto.  
  
## FIM de Específico da Microsoft  
  
## Consulte também  
 [Limites de inteiro](../Topic/Integer%20Limits.md)