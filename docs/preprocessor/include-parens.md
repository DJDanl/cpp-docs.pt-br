---
title: "include() | Microsoft Docs"
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
  - "include()"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "atributo include()"
ms.assetid: 86c9dcb2-d9e0-4fd5-97d7-0bb3e23d6ecc
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# include()
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico do C\+\+**  
  
 Desabilita a exclusão automática.  
  
## Sintaxe  
  
```  
include("Name1"[,"Name2", ...])  
```  
  
#### Parâmetros  
 `Name1`  
 Primeiro item a ser incluído de modo forçado.  
  
 `Name2`  
 O segundo item a ser incluído de modo forçado \(se necessário\).  
  
## Comentários  
 As bibliotecas de tipos podem conter definições dos itens definidos em cabeçalhos do sistema ou em outras bibliotecas de tipos.  `#import` tenta impedir vários erros de definição excluindo automaticamente esses itens.  Se os itens tiverem sido excluídos, conforme indicado por [Aviso do compilador \(nível 3\) C4192](../error-messages/compiler-warnings/compiler-warning-level-3-c4192.md), e isso não deveria ter ocorrido, esse atributo poderá ser usado para desabilitar a exclusão automática.  Esse atributo pode usar qualquer número de argumentos, cada um sendo o nome do item da biblioteca de tipos a ser incluído.  
  
 **FIM de Específico do C\+\+**  
  
## Consulte também  
 [Atributos \#import](../preprocessor/hash-import-attributes-cpp.md)   
 [Diretiva \#import](../Topic/%23import%20Directive%20\(C++\).md)