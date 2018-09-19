---
title: Erro das LNK1241 das ferramentas de vinculador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK1241
dev_langs:
- C++
helpviewer_keywords:
- LNK1241
ms.assetid: 7b8b52eb-0231-4521-b52a-2bce8d3e8956
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e4c11a97dd99515ff7623b77ff31de5fb8577b5d
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46040616"
---
# <a name="linker-tools-error-lnk1241"></a>Erro das Ferramentas de Vinculador LNK1241

arquivo de recurso 'arquivo de recurso' já especificado

Esse erro é gerado se você executar **cvtres** manualmente a partir da linha de comando e se você passar o obj resultantes de arquivos para o vinculador além para outros arquivos. res.

Para especificar vários arquivos. res, passá-los todos para o vinculador como arquivos. res, não de dentro arquivos. obj criado por **cvtres**.