---
title: Aviso LNK4001 (Ferramentas de Vinculador)
ms.date: 11/04/2016
f1_keywords:
- LNK4001
helpviewer_keywords:
- LNK4001
ms.assetid: 0a8b1c3a-64ce-4311-b7c0-065995059246
ms.openlocfilehash: d9659b0cf372ff8ebc225b890fb68866872bb3d6
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80194402"
---
# <a name="linker-tools-warning-lnk4001"></a>Aviso LNK4001 (Ferramentas de Vinculador)

nenhum arquivo de objeto especificado; bibliotecas usadas

O vinculador passou um ou mais arquivos. lib, mas nenhum arquivo. obj.

Como o vinculador não é capaz de acessar informações em um arquivo. lib que é capaz de acessar em um arquivo. obj, esse aviso indica que você precisará especificar explicitamente outras opções do vinculador. Por exemplo, talvez seja necessário especificar as opções [/Machine](../../build/reference/machine-specify-target-platform.md), [/out](../../build/reference/out-output-file-name.md)ou [/entry](../../build/reference/entry-entry-point-symbol.md) .
