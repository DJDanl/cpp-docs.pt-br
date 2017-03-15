---
title: "Propriedade do modificador de acelerador | Microsoft Docs"
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
helpviewer_keywords: 
  - "Propriedade de Modificador"
ms.assetid: f05a9379-e037-4cfb-b6ef-d2c655bcfa7f
caps.latest.revision: 5
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Propriedade do modificador de acelerador
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A seguir estão as entradas legais para a propriedade de modificador na tabela accelerator.  
  
|Valor|Descrição|  
|-----------|---------------|  
|**Nenhum**|Usuário pressiona somente o valor da chave.  Isso é mais efetivamente usado com os valores de ASCII\/ANSI 001 a 026, que é interpretado como ^ A ^ Z \(CTRL\-A por meio de CTRL\-Z\).|  
|**ALT**|Usuário deve pressionar a tecla ALT antes do valor de chave.|  
|**CTRL**|Usuário deve pressionar a tecla CTRL antes do valor de chave.  Não é válido com o tipo de ASCII.|  
|**SHIFT**|Usuário deve pressionar a tecla SHIFT antes do valor da chave.|  
|**Ctrl \+ Alt.**|Usuário deve pressionar a tecla CTRL e a tecla ALT antes do valor de chave.  Não é válido com o tipo de ASCII.|  
|**Ctrl \+ Shift.**|Usuário deve pressionar a tecla CTRL e SHIFT antes do valor da chave.  Não é válido com o tipo de ASCII.|  
|**Alt \+ Shift.**|Usuário deve pressionar a tecla ALT e SHIFT antes do valor da chave.  Não é válido com o tipo de ASCII.|  
|**Ctrl \+ Alt \+ Shift.**|Usuário deve pressionar CTRL, ALT e SHIFT antes do valor da chave.  Não é válido com o tipo de ASCII.|  
  
## Requisitos  
 Win32  
  
## Consulte também  
 [Configurando propriedades do acelerador](../windows/setting-accelerator-properties.md)   
 [Editor de aceleradores](../Topic/Accelerator%20Editor.md)