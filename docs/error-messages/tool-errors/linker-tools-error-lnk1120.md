---
title: Erro das LNK1120 das ferramentas de vinculador | Microsoft Docs
ms.custom: ''
ms.date: 05/17/2017
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK1120
dev_langs:
- C++
helpviewer_keywords:
- LNK1120
ms.assetid: 56aa7d36-921f-4daf-b44d-cca0d4fb1b51
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f1d2a55d683e9c8b9d6a0da2b3e5fa78d5a39933
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45725563"
---
# <a name="linker-tools-error-lnk1120"></a>Erro das Ferramentas de Vinculador LNK1120

> *número* externos não resolvidos  
  
Erro das LNK1120 reporta a contagem (*número*) de erros de símbolo externo não resolvido para esta operação de link. A maioria não resolvidos são relatados individualmente por erros de símbolo externo [erro das ferramentas de vinculador LNK2001](../../error-messages/tool-errors/linker-tools-error-lnk2001.md) e [erro das ferramentas de vinculador LNK2019](../../error-messages/tool-errors/linker-tools-error-lnk2019.md), que precedem a mensagem de erro, uma vez para cada externo não resolvido Erro de símbolo.  
  
Para corrigir esse erro, corrija todos os outros erros externos não resolvidos ou outros erros de vinculador que precedem-lo na saída da compilação. Esse erro não é relatado quando nenhum erro externo não resolvido permanecem.  
