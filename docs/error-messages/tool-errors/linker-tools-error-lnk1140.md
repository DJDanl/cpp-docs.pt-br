---
title: Erro das Ferramentas de Vinculador LNK1140
ms.date: 11/04/2016
f1_keywords:
- LNK1140
helpviewer_keywords:
- LNK1140
ms.assetid: 468d7651-a7cd-47b9-aead-5bb2fab56121
ms.openlocfilehash: 48c735f29918c4d1caeb15123f7376276d116fb4
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50482453"
---
# <a name="linker-tools-error-lnk1140"></a>Erro das Ferramentas de Vinculador LNK1140

muitos módulos para o banco de dados do programa; Vincular ao /PDB: NONE

O projeto contém os módulos mais que 4096.

### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir usando as seguintes soluções possíveis

1. Vincular novamente usando [/PDB: NONE](../../build/reference/pdb-use-program-database.md).

1. Compile alguns módulos sem as informações de depuração.

1. Reduza o número de módulos.