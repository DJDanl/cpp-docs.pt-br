---
title: Erro das Ferramentas de Vinculador LNK2027
ms.date: 11/04/2016
f1_keywords:
- LNK2027
helpviewer_keywords:
- LNK2027
ms.assetid: e2f857a8-8e8a-4697-bbff-12ccb84a35c1
ms.openlocfilehash: e74912780bab3056ead36ae3705f0910805228e9
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62299004"
---
# <a name="linker-tools-error-lnk2027"></a>Erro das Ferramentas de Vinculador LNK2027

módulo não resolvidas referência 'module'

Um arquivo passado para o vinculador tem uma dependência em um módulo que não foi especificado com **/ASSEMBLYMODULE** nem passados diretamente para o vinculador.

Para resolver das LNK2027, siga um destes procedimentos:

- Não passe para o vinculador o arquivo que contém a dependência do módulo.

- Especificar o módulo com **/ASSEMBLYMODULE**.

- Se o módulo é um. netmodule seguro, passe o módulo diretamente para o vinculador.

Para obter mais informações, consulte [/ASSEMBLYMODULE (Adicionar um módulo de MSIL ao Assembly)](../../build/reference/assemblymodule-add-a-msil-module-to-the-assembly.md) e [arquivos. netmodule como entrada de vinculador](../../build/reference/netmodule-files-as-linker-input.md).