---
title: Erro das LNK1158 das ferramentas de vinculador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK1158
dev_langs:
- C++
helpviewer_keywords:
- LNK1158
ms.assetid: 45febf16-d9e1-42db-af91-532e2717fd6a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0ce319aa4529c74cad00342b09aa0ed98bb49ce7
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46094163"
---
# <a name="linker-tools-error-lnk1158"></a>Erro das Ferramentas de Vinculador LNK1158

não é possível executar 'filename'

O determinado arquivo executável chamado pelo [LINK](../../build/reference/linker-command-line-syntax.md) está fora do diretório que contém o LINK nem em um diretório especificado na variável de ambiente PATH.

Por exemplo, você receberá esse erro se você tentar usar o parâmetro PGOPTIMIZE para o [/LTCG](../../build/reference/ltcg-link-time-code-generation.md) opção de vinculador em um computador com um sistema operacional de 32 bits.