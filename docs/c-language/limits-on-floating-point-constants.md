---
title: "Limites em constantes de ponto flutuante | Microsoft Docs"
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
  - "arquivo de cabeçalho FLOAT.H"
  - "constantes de ponto flutuante, limites"
  - "números de ponto flutuante, limites flutuantes"
  - "limites, constantes de ponto flutuante"
  - "intervalos, constantes de ponto flutuante"
ms.assetid: 2d975868-2af6-45d7-a8af-db79f2c6b67b
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Limites em constantes de ponto flutuante
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Os limites dos valores de constantes de ponto flutuante são fornecidos na seguinte tabela.  O arquivo de cabeçalho FLOAT.H contém essas informações.  
  
### Limites em constantes de ponto flutuante  
  
|Constante|Significado|Valor|  
|---------------|-----------------|-----------|  
|**FLT\_DIGDBL\_DIGLDBL\_DIG**|Número de dígitos, *q*, de modo que um número de ponto flutuante com *q* dígitos decimais possam ser arredondados em uma representação de ponto flutuante e retornarem sem perda de precisão.|6 15 15|  
|**FLT\_EPSILONDBL\_EPSILONLDBL\_EPSILON**|O menor número positivo *x*, de modo que *x* \+ 1,0 não seja igual a 1,0.|1.192092896e–07F 2.2204460492503131e–016 2.2204460492503131e–016|  
|**FLT\_GUARD**||0|  
|**FLT\_MANT\_DIGDBL\_MANT\_DIGLDBL\_MANT\_DIG**|Número de dígitos na raiz especificada por **FLT\_RADIX** no significando de ponto flutuante.  A raiz é 2; portanto, esses valores especificam bits.|24 53 53|  
|**FLT\_MAXDBL\_MAXLDBL\_MAX**|Número de ponto flutuante representável máximo.|3.402823466e\+38F 1.7976931348623158e\+308 1.7976931348623158e\+308|  
|**FLT\_MAX\_10\_EXPDBL\_MAX\_10\_EXPLDBL\_MAX\_10\_EXP**|Inteiro máximo de modo que 10 gerados para esse número sejam um número de ponto flutuante representável.|38 308 308|  
|**FLT\_MAX\_EXPDBL\_MAX\_EXPLDBL\_MAX\_EXP**|Inteiro máximo de modo que **FLT\_RADIX** gerado para esse número seja um número de ponto flutuante representável.|128 1024 1024|  
|**FLT\_MINDBL\_MINLDBL\_MIN**|Valor positivo mínimo.|1.175494351e–38F 2.2250738585072014e–308 2.2250738585072014e–308|  
|**FLT\_MIN\_10\_EXPDBL\_MIN\_10\_EXPLDBL\_MIN\_10\_EXP**|Inteiro negativo mínimo de modo que 10 gerados para esse número sejam um número de ponto flutuante representável.|–37<br /><br /> –307<br /><br /> –307|  
|**FLT\_MIN\_EXPDBL\_MIN\_EXPLDBL\_MIN\_EXP**|Inteiro negativo mínimo de modo que **FLT\_RADIX** gerado para esse número seja um número de ponto flutuante representável.|–125<br /><br /> –1021<br /><br /> –1021|  
|**FLT\_NORMALIZE**||0|  
|**FLT\_RADIX\_DBL\_RADIX\_LDBL\_RADIX**|Raiz de representação do expoente.|2 2 2|  
|**FLT\_ROUNDS\_DBL\_ROUNDS\_LDBL\_ROUNDS**|Arredondamento do modo para a adição de ponto flutuante.|1 \(aproximado\) 1 \(aproximado\) 1 \(aproximado\)|  
  
 Observe que as informações da tabela acima podem ser diferentes em implementações futuras.  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [Constantes de ponto flutuante C](../c-language/c-floating-point-constants.md)