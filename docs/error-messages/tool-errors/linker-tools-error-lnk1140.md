---
title: Erro das LNK1140 das ferramentas de vinculador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK1140
dev_langs:
- C++
helpviewer_keywords:
- LNK1140
ms.assetid: 468d7651-a7cd-47b9-aead-5bb2fab56121
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9f850360bc749a41e548cebae9f58f9fc7d3d420
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46044698"
---
# <a name="linker-tools-error-lnk1140"></a>Erro das Ferramentas de Vinculador LNK1140

muitos módulos para o banco de dados do programa; Vincular ao /PDB: NONE

O projeto contém os módulos mais que 4096.

### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir usando as seguintes soluções possíveis

1. Vincular novamente usando [/PDB: NONE](../../build/reference/pdb-use-program-database.md).

1. Compile alguns módulos sem as informações de depuração.

1. Reduza o número de módulos.