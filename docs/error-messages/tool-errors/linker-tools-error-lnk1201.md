---
title: Erro das Ferramentas de Vinculador LNK1201
ms.date: 11/04/2016
f1_keywords:
- LNK1201
helpviewer_keywords:
- LNK1201
ms.assetid: 64c3f496-a428-4b54-981e-faa82ef9c8a1
ms.openlocfilehash: c5cbb9a7159a976ad0f96f46462669cff7b19f26
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62213258"
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