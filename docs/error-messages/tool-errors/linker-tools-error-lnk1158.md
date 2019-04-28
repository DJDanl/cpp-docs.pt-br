---
title: Erro das Ferramentas de Vinculador LNK1158
ms.date: 11/04/2016
f1_keywords:
- LNK1158
helpviewer_keywords:
- LNK1158
ms.assetid: 45febf16-d9e1-42db-af91-532e2717fd6a
ms.openlocfilehash: 0dbb40fb1fe0405f3685a5e7246ecba2b53ec526
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62254946"
---
# <a name="linker-tools-error-lnk1158"></a>Erro das Ferramentas de Vinculador LNK1158

não é possível executar 'filename'

O determinado arquivo executável chamado pelo [LINK](../../build/reference/linking.md) está fora do diretório que contém o LINK nem em um diretório especificado na variável de ambiente PATH.

Por exemplo, você receberá esse erro se você tentar usar o parâmetro PGOPTIMIZE para o [/LTCG](../../build/reference/ltcg-link-time-code-generation.md) opção de vinculador em um computador com um sistema operacional de 32 bits.