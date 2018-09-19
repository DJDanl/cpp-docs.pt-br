---
title: Ferramentas de vinculador LNK4010 aviso | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK4010
dev_langs:
- C++
helpviewer_keywords:
- LNK4010
ms.assetid: 2824cf99-4174-4b60-a6e2-c01e9f1ee52d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e214f603c31c72533d81a140023363880532191c
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46068059"
---
# <a name="linker-tools-warning-lnk4010"></a>Aviso LNK4010 (Ferramentas de Vinculador)

número de número de versão de subsistema inválido; versão de subsistema padrão assumida

Você pode especificar uma versão do subsistema da imagem ([/SUBSYSTEM](../../build/reference/subsystem-specify-subsystem.md)). Cada subsistema tem um requisito mínimo de versão. Se a versão especificada é menor do que o mínimo, este aviso ocorrerá e o vinculador usará apenas o subsistema de padrão.