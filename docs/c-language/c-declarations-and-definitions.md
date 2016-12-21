---
title: "Declara&#231;&#245;es e defini&#231;&#245;es C | Microsoft Docs"
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
ms.assetid: 575f0c9b-5554-4346-be64-b2129ca9227f
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Declara&#231;&#245;es e defini&#231;&#245;es C
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma "declaração" estabelece uma associação entre uma variável, uma função ou um tipo específico e os respectivos atributos.  A [visão geral das declarações](../Topic/Overview%20of%20Declarations.md) apresenta a sintaxe ANSI do não terminal `declaration`.  Uma declaração também especifica onde e quando um identificador pode ser acessado \(a "vinculação" de um identificador\).  Consulte [Tempo de vida, escopo, visibilidade e vinculação](../Topic/Lifetime,%20Scope,%20Visibility,%20and%20Linkage.md) para obter informações sobre vinculação.  
  
 Uma "definição" de uma variável estabelece as mesmas associações que uma declaração, mas também faz com que ocorra a alocação de armazenamento para a variável.  
  
 Por exemplo, as funções `main`, `find` e `count` e as variáveis `var` e `val` são definidas em um arquivo de origem, nesta ordem:  
  
```  
int main() {}  
  
int var = 0;  
double val[MAXVAL];  
char find( fileptr ) {}  
int count( double f ) {}  
```  
  
 As variáveis `var` e `val` podem ser usadas nas funções `find` e `count`; nenhuma declaração adicional é necessária.  Porém, esses nomes não são visíveis \(não podem ser acessados\) em `main`.  
  
## Consulte também  
 [Arquivos e programas de origem](../c-language/source-files-and-source-programs.md)