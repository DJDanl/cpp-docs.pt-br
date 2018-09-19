---
title: Ferramentas de vinculador LNK4014 aviso | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK4014
dev_langs:
- C++
helpviewer_keywords:
- LNK4014
ms.assetid: 394903e9-3ded-4ea4-b7c0-a3535d4b4da4
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: df0a3b6f30733413a0f27c0b8daa07394bb04b07
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46023105"
---
# <a name="linker-tools-warning-lnk4014"></a>Aviso LNK4014 (Ferramentas de Vinculador)

não é possível localizar o objeto de membro "objectname"

Não foi possível encontrar LIB `objectname` na biblioteca.

O **/remover** e **/extract** opções exigem o nome completo do objeto membro que deve ser excluído ou copiados para um arquivo. O nome completo inclui o caminho do arquivo original do objeto. Para ver os nomes completos de objetos de membro em uma biblioteca, use DUMPBIN [/ARCHIVEMEMBERS](../../build/reference/archivemembers.md) ou LIB [/lista](../../build/reference/managing-a-library.md).