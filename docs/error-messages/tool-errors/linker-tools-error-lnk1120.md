---
title: Erro das Ferramentas de Vinculador LNK1120
ms.date: 05/17/2017
f1_keywords:
- LNK1120
helpviewer_keywords:
- LNK1120
ms.assetid: 56aa7d36-921f-4daf-b44d-cca0d4fb1b51
ms.openlocfilehash: b11318dcffb665d3b422fffcbd7e6275f35984dd
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62255099"
---
# <a name="linker-tools-error-lnk1120"></a>Erro das Ferramentas de Vinculador LNK1120

> *número* externos não resolvidos

Erro das LNK1120 reporta a contagem (*número*) de erros de símbolo externo não resolvido para esta operação de link. A maioria não resolvidos são relatados individualmente por erros de símbolo externo [erro das ferramentas de vinculador LNK2001](../../error-messages/tool-errors/linker-tools-error-lnk2001.md) e [erro das ferramentas de vinculador LNK2019](../../error-messages/tool-errors/linker-tools-error-lnk2019.md), que precedem a mensagem de erro, uma vez para cada externo não resolvido Erro de símbolo.

Para corrigir esse erro, corrija todos os outros erros externos não resolvidos ou outros erros de vinculador que precedem-lo na saída da compilação. Esse erro não é relatado quando nenhum erro externo não resolvido permanecem.
