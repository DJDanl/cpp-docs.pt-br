---
title: "Tipo duplo | Microsoft Docs"
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
  - "tipo de dados double"
  - "mantissas, variáveis de ponto flutuante"
  - "portabilidade [C++], tipo duplo"
  - "tipo duplo"
ms.assetid: 17c85b24-1475-4d41-a03c-ddf2d6561d34
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Tipo duplo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os valores de precisão double com tipo double têm 8 bytes.  O formato é semelhante ao formato de float, exceto que tem um expoente excess\-1023 de 11 bits e uma mantissa de 52 bits, mais 1 bit implícito de ordem alta.  Esse formato fornece um intervalo de aproximadamente 1.7E\-308 a 1.7E\+308 para o tipo double.  
  
 **Específico da Microsoft**  
  
 O tipo double contém 64 bits: 1 para o sinal, 11 para o expoente e 52 para a mantissa.  O intervalo é \+\/\-1.7E308 com pelo menos 15 dígitos de precisão.  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [Armazenamento de tipos básicos](../c-language/storage-of-basic-types.md)