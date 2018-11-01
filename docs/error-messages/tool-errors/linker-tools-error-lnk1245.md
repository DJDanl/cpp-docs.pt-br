---
title: Erro das Ferramentas de Vinculador LNK1245
ms.date: 11/04/2016
f1_keywords:
- LNK1245
helpviewer_keywords:
- LNK1245
ms.assetid: 179c8165-ffbb-44cd-9f24-5250f29577cc
ms.openlocfilehash: 4cf9a6c4356872b727a10a360396e51e38928b29
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50505476"
---
# <a name="linker-tools-error-lnk1245"></a>Erro das Ferramentas de Vinculador LNK1245

subsistema inválido 'subsistema' especificado; / O subsistema deve ser WINDOWS, WINDOWSCE ou CONSOLE

[/CLR](../../build/reference/clr-common-language-runtime-compilation.md) foi usado para compilar o objeto e uma das condições a seguir era true:

- Um ponto de entrada personalizado foi definido ([/ENTRY](../../build/reference/entry-entry-point-symbol.md)), de modo que o vinculador não foi possível deduzir um subsistema.

- Um valor que foi passado para o [/SUBSYSTEM](../../build/reference/subsystem-specify-subsystem.md) opção de vinculador que não é válida para /clr objetos.

Para ambas as situações, a resolução é especificar um valor válido para a opção de vinculador /SUBSYSTEM.