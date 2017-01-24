---
title: "Arqu&#233;tipos de ATL | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "archetype"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "ATL, arquétipos"
ms.assetid: 809fb0af-c0f4-4cc0-b5bc-afe3de5d9722
caps.latest.revision: 9
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Arqu&#233;tipos de ATL
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Em esse contexto, *um arquétipo* é uma classe teórica que fornece um conjunto de métodos, dos membros de dados, funções estáticas, de typedefs, ou outros recursos.  O arquétipo também inclui uma descrição de semântica necessário criar ou usar a classe para representar um conceito específico.  As classes que imitam o arquétipo fornecendo os mesmos recursos personificam o mesmo conceito e podem ser usadas no arquétipo podem ser usadas.  
  
 Os arquétipos são úteis em C\+\+ para descrever os recursos de valores válidos para parâmetros de modelo.  O designer de modelo tem uma exibição clara dos recursos necessários e permissões do modelo, e o compilador aplica aos requisitos sintáticos em tempo de compilação, mas o usuário de um modelo precisa descrever a documentação da semântica e de permitir as relações entre os arquétipos as classes e a ser escritos claramente para fora.  
  
 Exemplos de arquétipos na biblioteca do C\+\+ padrão são diferentes tipos de iterador e de contêiner.  Esses arquétipos são descritos em tópicos [Convenções de iterador](../Topic/Iterators.md) e [contêiner de STL](../../standard-library/stl-containers.md).  
  
 o servidor de ATL define os seguintes arquétipos:  
  
|Nome|Descrição|  
|----------|---------------|  
|[Arquétipo de trabalho](../../atl/reference/worker-archetype.md)|As classes de acordo com o arquétipo *de trabalho* fornecem código para itens de trabalho de processo enfileirados em um pool de segmentos.|  
  
## Consulte também  
 [Conceitos](../../atl/active-template-library-atl-concepts.md)   
 [Componentes da área de trabalho COM ATL](../../atl/atl-com-desktop-components.md)