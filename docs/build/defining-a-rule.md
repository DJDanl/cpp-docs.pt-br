---
title: "Definindo uma regra | Microsoft Docs"
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
  - "definindo regras de inferência"
  - "programa NMAKE, regras de inferência"
ms.assetid: 071cd092-3f2e-4065-b0fb-36a9d393cfa8
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Definindo uma regra
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

*O fromext* representa a extensão de um arquivo dependente, e *o toext* representa a extensão do arquivo de destino.  
  
```  
.fromext.toext:  
   commands  
```  
  
## Comentários  
 As extensões não diferenciam maiúsculas de minúsculas.  Macros podem ser chamadas para representar *o fromext* e *o toext*; macros são expandidos durante pré\-processamento.  *O fromext* acima do ponto \(.\) deve aparecer no início da linha.  Os dois\-pontos \(:\) é precedido por zero ou mais espaços ou guias.  Pode ser seguido somente por espaços ou guias, um ponto\-e\-vírgula \(;\) para especificar um comando, um sinal de número \(\#\) especifique um comentário, ou um caractere de nova linha.  Nenhum outro espaço é permitido.  Os comandos são especificados como em blocos de descrição.  
  
## Que você deseja saber mais?  
 [Caminhos de pesquisa nas regras](../build/search-paths-in-rules.md)  
  
## Consulte também  
 [Regras de inferência](../build/inference-rules.md)