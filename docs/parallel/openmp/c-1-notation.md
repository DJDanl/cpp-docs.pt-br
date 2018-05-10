---
title: C. 1 notação | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: a23b2631-8096-4bf3-ac23-ba4f4bd7a52a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 39e8610524e20aa99ea316d62f36b512700e377e
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="c1-notation"></a>C.1 Notação
As regras da gramática consistem no nome de um não terminal, seguido por dois-pontos, seguido por alternativas de substituição em linhas separadas.  
  
 A expressão sintática termopt indica que o termo é opcional dentro da substituição.  
  
 A expressão sintática *termo*optseq é equivalente a *termo seq*aceitar com as seguintes regras adicionais:  
  
 *termo seq* :  
  
 *Termo*  
  
 *termo do termo seq*  
  
 *termo seq* , *termo*