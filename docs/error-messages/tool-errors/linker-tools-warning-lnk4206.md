---
title: Aviso LNK4206 (Ferramentas de Vinculador)
ms.date: 12/05/2017
f1_keywords:
- LNK4206
helpviewer_keywords:
- LNK4206
ms.assetid: 6c108e33-00cf-4c5a-830d-d65d470930a7
ms.openlocfilehash: 1758fffb72e183e8a186d115b2b3f3b30c32e047
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80193869"
---
# <a name="linker-tools-warning-lnk4206"></a>Aviso LNK4206 (Ferramentas de Vinculador)

> informações de tipo pré-compilado não encontradas; '*filename*' não vinculado ou substituído; Vinculando objeto quando sem informação de depuração

O arquivo de objeto *filename* , compilado usando [/YC](../../build/reference/yc-create-precompiled-header-file.md), não foi especificado no comando link ou foi substituído.

Um cenário comum para esse aviso é quando o. obj que foi compilado com/Yc está em uma biblioteca e onde não há referências de símbolo a esse. obj do seu código.  Nesse caso, o vinculador não usará (ou até mesmo vê) o arquivo. obj.  Nessa situação, você deve recompilar seu código e usar [/YL](../../build/reference/yl-inject-pch-reference-for-debug-library.md) para os objetos compilados usando [/Yu](../../build/reference/yu-use-precompiled-header-file.md).
