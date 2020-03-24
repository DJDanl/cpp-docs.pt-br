---
title: Aviso do compilador (nível 3) C4622
ms.date: 11/04/2016
f1_keywords:
- C4622
helpviewer_keywords:
- C4622
ms.assetid: d3c879f0-4492-4f4b-b26d-230993f3a933
ms.openlocfilehash: 295a183afb24121a2abefd336f6ea92110220155
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80185498"
---
# <a name="compiler-warning-level-3-c4622"></a>Aviso do compilador (nível 3) C4622

substituindo informações de depuração formadas durante a criação do cabeçalho pré-compilado no arquivo de objeto: ' file '

As informações de CodeView no arquivo especificado foram perdidas quando ele foi compilado com a opção [/Yu](../../build/reference/yu-use-precompiled-header-file.md) (use cabeçalhos pré-compilados).

Renomeie o arquivo de objeto (usando [/fo](../../build/reference/fo-object-file-name.md)) ao criar ou usar o arquivo de cabeçalho pré-compilado e vincular usando o novo arquivo de objeto.
