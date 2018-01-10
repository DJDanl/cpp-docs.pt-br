---
title: Ferramentas de vinculador aviso LNK4037 | Microsoft Docs
ms.custom: 
ms.date: 10/04/2017
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: LNK4037
dev_langs: C++
helpviewer_keywords: LNK4037
ms.assetid: 9ba02fd3-b04f-4679-bab9-26fa82cf09bb
caps.latest.revision: "0"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 0c93eab2faf81e4cd743eae4befa2f842c100589
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="linker-tools-warning-lnk4037"></a>Aviso LNK4037 ferramentas de vinculador

>'*símbolo*' não existe; ignorado

O nome decorado *símbolo* não pôde ser ordenados por meio de [/ORDER](../../build/reference/order-put-functions-in-order.md) porque não foi encontrado no programa. Verifique a especificação de *símbolo* no arquivo de resposta de ordem. Para obter mais informações, consulte o [/ORDER (colocar funções na ordem)](../../build/reference/order-put-functions-in-order.md) opção de vinculador.

> [!NOTE]
> LINK não é possível ordenar funções estáticas, como nomes de função estática não são nomes de símbolos públicos. Quando **/ORDER** for especificado, este vinculador aviso é gerado para cada símbolo no arquivo de resposta de ordem é estáticas ou não localizado.