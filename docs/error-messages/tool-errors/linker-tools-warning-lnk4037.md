---
title: Aviso LNK4037 (Ferramentas de Vinculador)
ms.date: 10/04/2017
f1_keywords:
- LNK4037
helpviewer_keywords:
- LNK4037
ms.assetid: 9ba02fd3-b04f-4679-bab9-26fa82cf09bb
ms.openlocfilehash: 9a8121617e622fc12efe5bd26aac23faf2530f24
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62410298"
---
# <a name="linker-tools-warning-lnk4037"></a>Aviso LNK4037 (Ferramentas de Vinculador)

>'*símbolo*' não existe; ignorado

O nome decorado *símbolo* não pôde ser ordenados usando o [/ORDER](../../build/reference/order-put-functions-in-order.md) opção porque ele não pôde ser encontrado no programa. Verifique a especificação de *símbolo* no arquivo de resposta de ordem. Para obter mais informações, consulte o [/ORDER (colocar funções na ordem)](../../build/reference/order-put-functions-in-order.md) a opção de vinculador.

> [!NOTE]
> LINK não é possível ordenar funções estáticas, como nomes de função estática não são nomes de símbolos públicos. Quando **/ORDER** é especificado, esse aviso de vinculador é gerado para cada símbolo no arquivo de resposta de ordem que são estáticos ou não foi encontrado.