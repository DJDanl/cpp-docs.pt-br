---
title: "Atualizando uma coluna quando outra tabela cont&#233;m uma refer&#234;ncia para a linha | Microsoft Docs"
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
  - "conjuntos de linhas, atualizações de coluna"
ms.assetid: abb5db69-055d-431f-b12d-ad2940a661ba
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Atualizando uma coluna quando outra tabela cont&#233;m uma refer&#234;ncia para a linha
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Alguns provedores podem detectar que as colunas da linha alterados, mas muitos provedores não podem.  No resultado, a atualização de uma coluna pode resultar em um erro quando há uma referência à linha que você está tentando atualizar.  Para resolver esse problema, crie um acessador separado que contém somente as colunas que você deseja alterar.  Passe o número desse acessador a `SetData`.  
  
## Consulte também  
 [Usando acessadores](../../data/oledb/using-accessors.md)