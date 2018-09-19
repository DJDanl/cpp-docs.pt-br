---
title: Erro das LNK2027 das ferramentas de vinculador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK2027
dev_langs:
- C++
helpviewer_keywords:
- LNK2027
ms.assetid: e2f857a8-8e8a-4697-bbff-12ccb84a35c1
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 022e363af575e29e3085dcaec21257fa7e4ab5f1
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46116835"
---
# <a name="linker-tools-error-lnk2027"></a>Erro das Ferramentas de Vinculador LNK2027

módulo não resolvidas referência 'module'

Um arquivo passado para o vinculador tem uma dependência em um módulo que não foi especificado com **/ASSEMBLYMODULE** nem passados diretamente para o vinculador.

Para resolver das LNK2027, siga um destes procedimentos:

- Não passe para o vinculador o arquivo que contém a dependência do módulo.

- Especificar o módulo com **/ASSEMBLYMODULE**.

- Se o módulo é um. netmodule seguro, passe o módulo diretamente para o vinculador.

Para obter mais informações, consulte [/ASSEMBLYMODULE (Adicionar um módulo de MSIL ao Assembly)](../../build/reference/assemblymodule-add-a-msil-module-to-the-assembly.md) e [arquivos. netmodule como entrada de vinculador](../../build/reference/netmodule-files-as-linker-input.md).