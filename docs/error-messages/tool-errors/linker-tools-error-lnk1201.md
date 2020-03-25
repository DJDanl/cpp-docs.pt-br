---
title: Erro das Ferramentas de Vinculador LNK1201
ms.date: 11/04/2016
f1_keywords:
- LNK1201
helpviewer_keywords:
- LNK1201
ms.assetid: 64c3f496-a428-4b54-981e-faa82ef9c8a1
ms.openlocfilehash: 8d02743333c02c7cdff3b75e4a16bfecda442fa9
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80195104"
---
# <a name="linker-tools-error-lnk1201"></a>Erro das Ferramentas de Vinculador LNK1201

erro ao gravar no banco de dados do programa ' FileName '; verificar se há espaço em disco insuficiente, caminho inválido ou privilégio insuficiente

O LINK não pôde gravar no banco de dados do programa (PDB) para o arquivo de saída.

### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir

1. O arquivo está corrompido. Exclua o arquivo PDB e Revincule.

1. Não há espaço em disco suficiente para gravar o arquivo.

1. A unidade não está disponível, possivelmente devido a um problema de rede.

1. O depurador está ativo no programa que você está tentando vincular.

1. Sem espaço de heap.  Consulte [C1060](../../error-messages/compiler-errors-1/fatal-error-c1060.md) para obter mais informações.
