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
ms.openlocfilehash: 9ba06af937f15ff70e6de0aa36e394fef5815f0a
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="linker-tools-warning-lnk4037"></a>Aviso LNK4037 ferramentas de vinculador

>'*símbolo*' não existe; ignorado

O nome decorado *símbolo* não pôde ser ordenados por meio de [/ORDER](../../build/reference/order-put-functions-in-order.md) porque não foi encontrado no programa. Verifique a especificação de *símbolo* no arquivo de resposta de ordem. Para obter mais informações, consulte o [/ORDER (colocar funções na ordem)](../../build/reference/order-put-functions-in-order.md) opção de vinculador.

> [!NOTE]
> LINK não é possível ordenar funções estáticas, como nomes de função estática não são nomes de símbolos públicos. Quando **/ORDER** for especificado, este vinculador aviso é gerado para cada símbolo no arquivo de resposta de ordem é estáticas ou não localizado.