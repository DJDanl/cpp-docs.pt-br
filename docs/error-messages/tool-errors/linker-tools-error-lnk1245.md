---
title: Erro das LNK1245 das ferramentas de vinculador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK1245
dev_langs:
- C++
helpviewer_keywords:
- LNK1245
ms.assetid: 179c8165-ffbb-44cd-9f24-5250f29577cc
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ef7bace5cec937399d7a2ed440e21b9b751f4141
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46041786"
---
# <a name="linker-tools-error-lnk1245"></a>Erro das Ferramentas de Vinculador LNK1245

subsistema inválido 'subsistema' especificado; / O subsistema deve ser WINDOWS, WINDOWSCE ou CONSOLE

[/CLR](../../build/reference/clr-common-language-runtime-compilation.md) foi usado para compilar o objeto e uma das condições a seguir era true:

- Um ponto de entrada personalizado foi definido ([/ENTRY](../../build/reference/entry-entry-point-symbol.md)), de modo que o vinculador não foi possível deduzir um subsistema.

- Um valor que foi passado para o [/SUBSYSTEM](../../build/reference/subsystem-specify-subsystem.md) opção de vinculador que não é válida para /clr objetos.

Para ambas as situações, a resolução é especificar um valor válido para a opção de vinculador /SUBSYSTEM.