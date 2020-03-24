---
title: Aviso LNK4037 (Ferramentas de Vinculador)
ms.date: 10/04/2017
f1_keywords:
- LNK4037
helpviewer_keywords:
- LNK4037
ms.assetid: 9ba02fd3-b04f-4679-bab9-26fa82cf09bb
ms.openlocfilehash: 43fae7d0f19f96998d2e1a1739bc3e596bbd9ea9
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80194194"
---
# <a name="linker-tools-warning-lnk4037"></a>Aviso LNK4037 (Ferramentas de Vinculador)

>'*Symbol*' não existe; aceita

Não foi possível ordenar o *símbolo* de nome decorado usando a opção [/Order](../../build/reference/order-put-functions-in-order.md) porque ele não foi encontrado no programa. Verifique a especificação do *símbolo* no arquivo de resposta do pedido. Para obter mais informações, consulte a opção de vinculador [/Order (put functions in order)](../../build/reference/order-put-functions-in-order.md) .

> [!NOTE]
> O LINK não pode ordenar funções estáticas porque nomes de funções estáticas não são nomes de símbolos públicos. Quando **/Order** é especificado, esse aviso do vinculador é gerado para cada símbolo no arquivo de resposta da ordem que é estático ou não encontrado.
