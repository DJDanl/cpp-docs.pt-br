---
title: "C. 1 notação | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: a23b2631-8096-4bf3-ac23-ba4f4bd7a52a
caps.latest.revision: "4"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 20ad99729f526cd9cb5f1e4e6c239272341462e7
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="c1-notation"></a>C.1 Notação
As regras da gramática consistem no nome de um não terminal, seguido por dois-pontos, seguido por alternativas de substituição em linhas separadas.  
  
 A expressão sintática termopt indica que o termo é opcional dentro da substituição.  
  
 A expressão sintática *termo*optseq é equivalente a *termo seq*aceitar com as seguintes regras adicionais:  
  
 *termo seq* :  
  
 *termo*  
  
 *termo do termo seq*  
  
 *termo seq* , *termo*