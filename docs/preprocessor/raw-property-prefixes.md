---
title: "raw_property_prefixes | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "raw_property_prefixes"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Atributo raw_property_prefixes"
ms.assetid: 03a0f48c-c460-4175-a762-9f7f8d84b12f
caps.latest.revision: 4
caps.handback.revision: 4
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# raw_property_prefixes
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico do C\+\+**  
  
 Especifica prefixos alternativos para três métodos da propriedade.  
  
## Sintaxe  
  
```  
raw_property_prefixes("GetPrefix","PutPrefix","PutRefPrefix")  
```  
  
#### Parâmetros  
 `GetPrefix`  
 Prefixo para ser usado nos métodos **propget**.  
  
 `PutPrefix`  
 Prefixo para ser usado nos métodos **propput**.  
  
 `PutRefPrefix`  
 Prefixo para ser usado nos métodos **propputref**.  
  
## Comentários  
 Por padrão, os métodos **propget**, **propput** e **propputref** são expostos por funções de membro nomeadas com prefixos de **get\_**, **put\_** e **putref\_** respectivamente.  Esses prefixos são compatíveis com os nomes usados nos arquivos de cabeçalho gerados pelo MIDL.  
  
 **FIM de Específico do C\+\+**  
  
## Consulte também  
 [Atributos \#import](../preprocessor/hash-import-attributes-cpp.md)   
 [Diretiva \#import](../Topic/%23import%20Directive%20\(C++\).md)