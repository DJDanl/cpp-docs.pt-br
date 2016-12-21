---
title: "Usando v&#225;rios conjuntos de resultados a partir de um procedimento armazenado | Microsoft Docs"
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
  - "vários conjuntos de resultados"
  - "procedimentos armazenados, retornando conjuntos de resultados"
ms.assetid: c450c12c-a76c-4ae4-9675-071a41eeac05
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Usando v&#225;rios conjuntos de resultados a partir de um procedimento armazenado
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A maioria de vários conjuntos de resultados de retorno de procedimentos armazenados.  Tal procedimento armazenado em geral inclui uma ou mais instruções select.  O consumidor necessário considerar isso para tratar todos os conjuntos de resultados.  
  
### Para tratar vários conjuntos de resultados  
  
1.  Crie uma classe de `CCommand` com `CMultipleResults` como um argumento do modelo e com o acessador de sua escolha.  Geralmente, esse é um acessador dinâmico ou manual.  Se você usar outro tipo de acessador, você não pode determinar as colunas de saída para cada conjunto de linhas.  
  
2.  Execute o procedimento armazenado como de costume e associar as colunas [Como posso busco dados?](../../data/oledb/fetching-data.md)\(consulte\).  
  
3.  Use os dados.  
  
4.  Chame `GetNextResult` na classe de `CCommand` .  Se outro conjunto de linhas de resultado está disponível, `GetNextResult` retorna S\_OK e você deverá associar novamente suas colunas se você estiver usando um acessador manual.  Se `GetNextResult` retorna um erro, não há nenhum conjunto de resultados adicional disponível.  
  
## Consulte também  
 [Usando procedimentos armazenados](../../data/oledb/using-stored-procedures.md)