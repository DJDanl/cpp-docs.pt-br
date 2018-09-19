---
title: Erro das LNK1201 das ferramentas de vinculador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK1201
dev_langs:
- C++
helpviewer_keywords:
- LNK1201
ms.assetid: 64c3f496-a428-4b54-981e-faa82ef9c8a1
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4c133748f95846160e1387e31e023d9ce459b281
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46055245"
---
# <a name="linker-tools-error-lnk1201"></a>Erro das Ferramentas de Vinculador LNK1201

Erro ao gravar no banco de dados do programa 'filename'; verificar se há espaço em disco insuficiente, caminho inválido ou privilégio insuficiente

LINK não foi possível gravar no banco de dados do programa (PDB) para o arquivo de saída.

### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir

1. Arquivo está corrompido. Exclua o arquivo PDB e vincular novamente.

1. Espaço em disco insuficiente para gravar o arquivo.

1. Unidade não está disponível, possivelmente devido a um problema de rede.

1. O depurador está ativo no programa que você está tentando vincular.

1. Sem espaço de heap.  Ver [C1060](../../error-messages/compiler-errors-1/fatal-error-c1060.md) para obter mais informações.