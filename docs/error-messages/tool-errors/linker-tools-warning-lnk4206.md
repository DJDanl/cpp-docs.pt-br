---
title: Aviso LNK4206 das ferramentas de vinculador | Microsoft Docs
ms.date: 12/05/2017
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK4206
dev_langs:
- C++
helpviewer_keywords:
- LNK4206
ms.assetid: 6c108e33-00cf-4c5a-830d-d65d470930a7
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f0cb74776f307affb0455d972e27e594e6d06294
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="linker-tools-warning-lnk4206"></a>Aviso LNK4206 (Ferramentas de Vinculador)

> informações de tipo precompilado não encontradas; '*filename*' não vinculado ou sobrescrito; vinculação de objeto quando sem informação de depuração

O *filename* arquivo de objeto, compilado usando [/Yc](../../build/reference/yc-create-precompiled-header-file.md), não foi especificado no comando LINK ou foi substituído.

Um cenário comum para esse aviso é quando o obj que foi compilado com /Yc está em uma biblioteca, e em que não há nenhuma referência de símbolo para esse obj do seu código.  Nesse caso, o vinculador será não usar (ou até mesmo ver) do arquivo. obj.  Nessa situação, você deve recompilar o código e usar [/Yl](../../build/reference/yl-inject-pch-reference-for-debug-library.md) para os objetos compilados usando [/Yu](../../build/reference/yu-use-precompiled-header-file.md).