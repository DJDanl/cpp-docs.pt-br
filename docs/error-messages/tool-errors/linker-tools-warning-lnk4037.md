---
title: Ferramentas de vinculador aviso LNK4037 | Microsoft Docs
ms.custom: ''
ms.date: 10/04/2017
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK4037
dev_langs:
- C++
helpviewer_keywords:
- LNK4037
ms.assetid: 9ba02fd3-b04f-4679-bab9-26fa82cf09bb
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6b87f0a415d6ae7d282e29c2ca67fda043c2a901
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="linker-tools-warning-lnk4037"></a>Aviso LNK4037 ferramentas de vinculador

>'*símbolo*' não existe; ignorado

O nome decorado *símbolo* não pôde ser ordenados por meio de [/ORDER](../../build/reference/order-put-functions-in-order.md) porque não foi encontrado no programa. Verifique a especificação de *símbolo* no arquivo de resposta de ordem. Para obter mais informações, consulte o [/ORDER (colocar funções na ordem)](../../build/reference/order-put-functions-in-order.md) opção de vinculador.

> [!NOTE]
> LINK não é possível ordenar funções estáticas, como nomes de função estática não são nomes de símbolos públicos. Quando **/ORDER** for especificado, este vinculador aviso é gerado para cada símbolo no arquivo de resposta de ordem é estáticas ou não localizado.