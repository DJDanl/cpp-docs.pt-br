---
title: Compilador aviso (nível 3) C4622 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4622
dev_langs:
- C++
helpviewer_keywords:
- C4622
ms.assetid: d3c879f0-4492-4f4b-b26d-230993f3a933
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d91e3c914d6c3feeb9d2326c94efe2bc54ac98f4
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46023235"
---
# <a name="compiler-warning-level-3-c4622"></a>Compilador aviso (nível 3) C4622

substituindo informação de depuração formada durante a criação de cabeçalho pré-compilado no arquivo de objeto: 'file'

Informações de CodeView no arquivo especificado foram perdidas quando ele foi compilado com o [/Yu](../../build/reference/yu-use-precompiled-header-file.md) opção (usar cabeçalho pré-compilado).

Renomeie o arquivo de objeto (usando [/Fo](../../build/reference/fo-object-file-name.md)) ao criar ou usando o cabeçalho pré-compilado do arquivo e fornecer um link usando o novo arquivo de objeto.