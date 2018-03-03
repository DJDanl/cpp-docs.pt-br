---
title: "C. 1 notação | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
ms.assetid: a23b2631-8096-4bf3-ac23-ba4f4bd7a52a
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: e9772b2a4b27521c7aa256f9ee7760a4687152b9
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="c1-notation"></a>C.1 Notação
As regras da gramática consistem no nome de um não terminal, seguido por dois-pontos, seguido por alternativas de substituição em linhas separadas.  
  
 A expressão sintática termopt indica que o termo é opcional dentro da substituição.  
  
 A expressão sintática *termo*optseq é equivalente a *termo seq*aceitar com as seguintes regras adicionais:  
  
 *termo seq* :  
  
 *termo*  
  
 *termo do termo seq*  
  
 *termo seq* , *termo*