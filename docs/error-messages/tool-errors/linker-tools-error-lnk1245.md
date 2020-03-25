---
title: Erro das Ferramentas de Vinculador LNK1245
ms.date: 11/04/2016
f1_keywords:
- LNK1245
helpviewer_keywords:
- LNK1245
ms.assetid: 179c8165-ffbb-44cd-9f24-5250f29577cc
ms.openlocfilehash: 19e3f820b5bd7fdd8eac2f7b5a96fb5923ae0b92
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80183794"
---
# <a name="linker-tools-error-lnk1245"></a>Erro das Ferramentas de Vinculador LNK1245

subsistema ' subsistema ' inválido especificado; /SUBSYSTEM deve ser WINDOWS, WINDOWSCE ou CONSOLE

o [/CLR](../../build/reference/clr-common-language-runtime-compilation.md) foi usado para compilar o objeto e uma das seguintes condições era verdadeira:

- Um ponto de entrada personalizado foi definido ([/entry](../../build/reference/entry-entry-point-symbol.md)), de modo que o vinculador não pode inferir um subsistema.

- Um valor foi passado para a opção de vinculador [/Subsystem](../../build/reference/subsystem-specify-subsystem.md) que não é válida para objetos/CLR.

Para ambas as situações, a resolução é especificar um valor válido para a opção de vinculador/SUBSYSTEM.
