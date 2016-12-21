---
title: "Convers&#245;es de atribui&#231;&#227;o | Microsoft Docs"
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
  - "conversões de atribuição"
  - "conversões, atribuição"
ms.assetid: 4ee01013-de32-4aae-b12e-0051d0cde927
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Convers&#245;es de atribui&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Em operações de atribuição, o tipo do valor que está sendo atribuído é convertido no tipo da variável que recebe a atribuição.  O C permite conversões por atribuição entre os tipos integrais e flutuantes, mesmo se as informações forem perdidas na conversão.  O método de conversão usado depende dos tipos envolvidos na atribuição, conforme descrito em [Conversões aritméticas comuns](../c-language/usual-arithmetic-conversions.md) e nas seguintes seções:  
  
-   [Conversões de tipos integrais com sinal](../c-language/conversions-from-signed-integral-types.md)  
  
-   [Conversões de tipos integrais sem sinal](../c-language/conversions-from-unsigned-integral-types.md)  
  
-   [Conversões de tipos de ponto flutuante](../Topic/Conversions%20from%20Floating-Point%20Types.md)  
  
-   [Conversões em e de tipos de ponteiro](../c-language/conversions-to-and-from-pointer-types.md)  
  
-   [Conversões de outros tipos](../c-language/conversions-from-other-types.md)  
  
 Os qualificadores de tipo não afetam o capacidade de conversão, embora um valor l **const** não possa ser usado no lado esquerdo da atribuição.  
  
## Consulte também  
 [Conversões de tipo](../c-language/type-conversions-c.md)