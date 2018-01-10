---
title: Blocos | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- function definitions, blocks in code
- blocks
- compound statements
- statements, compound
ms.assetid: be231a92-c712-464e-ae25-a4becb20f7f5
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 60126db8e2a8f7fe9e56041c4f5b119df828958c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="blocks"></a>Blocos
Uma sequência de declarações, definições e instruções entre chaves (**{ }**) é denominada "bloco". Existem dois tipos de blocos em C. A "instrução composta", uma instrução composta por uma ou mais instruções (consulte [A instrução composta](../c-language/compound-statement-c.md)), é um tipo de bloco. O outro, a "definição de função", consiste em uma instrução composta (o corpo da função) com o "cabeçalho" associado à função (o nome da função, o tipo de retorno e os parâmetros, formais). Um bloco dentro de outros blocos é chamado de "aninhado".  
  
 Observe que, ainda que todas as instruções compostas estejam entre chaves, nem tudo que está entre chaves constitui uma instrução composta. Por exemplo, embora as especificações de matriz, estrutura ou dos elementos de enumeração possam aparecer entre chaves, elas não são instruções compostas.  
  
## <a name="see-also"></a>Consulte também  
 [Arquivos e programas de origem](../c-language/source-files-and-source-programs.md)