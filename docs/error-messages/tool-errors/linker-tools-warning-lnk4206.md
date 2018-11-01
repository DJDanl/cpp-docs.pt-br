---
title: Aviso LNK4206 (Ferramentas de Vinculador)
ms.date: 12/05/2017
f1_keywords:
- LNK4206
helpviewer_keywords:
- LNK4206
ms.assetid: 6c108e33-00cf-4c5a-830d-d65d470930a7
ms.openlocfilehash: dc81df89609f59834c8a3271dd64f3b99b281f90
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50613624"
---
# <a name="linker-tools-warning-lnk4206"></a>Aviso LNK4206 (Ferramentas de Vinculador)

> informações de tipo precompilado não encontradas; '*filename*' não vinculado ou substituído; vinculando objeto quando sem informação de depuração

O *filename* arquivo de objeto compilado usando [/Yc](../../build/reference/yc-create-precompiled-header-file.md), não foi especificado no comando LINK ou foi substituído.

Um cenário comum para esse aviso é quando o. obj que foi compilado com /Yc está em uma biblioteca, e em que não há nenhuma referência de símbolo para esse. obj do seu código.  Nesse caso, o vinculador será não usar (ou até mesmo ver) o arquivo. obj.  Nessa situação, você deve recompilar seu código e usar [/Yl](../../build/reference/yl-inject-pch-reference-for-debug-library.md) para os objetos compilados usando [/Yu](../../build/reference/yu-use-precompiled-header-file.md).