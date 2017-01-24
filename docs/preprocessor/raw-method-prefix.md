---
title: "raw_method_prefix | Microsoft Docs"
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
  - "raw_method_prefix"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Atributo raw_method_prefix"
ms.assetid: 71490313-af78-4bb2-b28a-eee67950d30b
caps.latest.revision: 4
caps.handback.revision: 4
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# raw_method_prefix
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico do C\+\+**  
  
 Especifica um prefixo diferente para evitar colisões de nome.  
  
## Sintaxe  
  
```  
raw_method_prefix("Prefix")  
```  
  
#### Parâmetros  
 `Prefix`  
 O prefixo a ser usado.  
  
## Comentários  
 As propriedades e os métodos de baixo nível são expostos por funções de membro nomeadas com o prefixo padrão **raw\_** para evitar colisões de nomes com as funções de membro de tratamento de erros de alto nível.  
  
> [!NOTE]
>  Os efeitos do atributo `raw_method_prefix` não serão alterados pela presença do atributo [raw\_interfaces\_only](#_predir_raw_interfaces_only).  `raw_method_prefix` sempre tem precedência sobre `raw_interfaces_only` na especificação de um prefixo.  Se os dois atributos forem usados na mesma instrução `#import`, o prefixo especificado pelo atributo `raw_method_prefix` será usado.  
  
 **FIM de Específico do C\+\+**  
  
## Consulte também  
 [Atributos \#import](../preprocessor/hash-import-attributes-cpp.md)   
 [Diretiva \#import](../Topic/%23import%20Directive%20\(C++\).md)