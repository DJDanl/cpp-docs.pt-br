---
title: "Compilador (nível 4) de aviso C4985 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: C4985
ms.assetid: 832f001c-afe7-403d-a8b4-02334724c79e
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: cb2b95e10a5a5e2b6fcaf67ab41880580267ec7a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-4-c4985"></a>Compilador C4985 de aviso (nível 4)
nome do símbolo: atributos não presentes em declaração anterior.  
  
 As anotações de linguagem (SAL) de anotação do código-fonte código na declaração do método atual ou definição diferem das anotações em uma declaração anterior. As anotações de SAL mesmo devem ser usadas na definição e as declarações de um método.  
  
 O SAL fornece um conjunto de anotações que você pode usar para descrever como uma função usa os parâmetros, as suposições faz sobre eles e as garantias faz em Concluir. As anotações são definidas no arquivo de cabeçalho de sal.  
  
 Observe que as macros SAL não expandirá a menos que o projeto tenha a [/ANALYZE](../../build/reference/analyze-code-analysis.md) sinalizador especificado. Quando você especifica **/ANALYZE**, o compilador pode gerar C4985, mesmo se nenhum aviso ou erro apareceu sem **/ANALYZE**.  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
1.  Use as anotações de SAL mesmo na definição de um método e todas as suas declarações.  
  
## <a name="see-also"></a>Consulte também  
 [Anotações de SAL](../../c-runtime-library/sal-annotations.md)