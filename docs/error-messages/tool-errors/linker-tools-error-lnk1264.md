---
title: Erro das LNK1264 das ferramentas de vinculador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK1264
dev_langs:
- C++
helpviewer_keywords:
- LNK1264
ms.assetid: 23b1aad7-d382-42c1-bae8-db68575c57a8
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8232e83774dc53755b77ad9c8b3bbb2a0bcc6ae6
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46102731"
---
# <a name="linker-tools-error-lnk1264"></a>Erro das Ferramentas de Vinculador LNK1264

/LTCG:PGINSTRUMENT especificado, mas não há geração de código necessária; falhado de instrumentação

**/LTCG:PGINSTRUMENT** foi especificado mas. obj não foram encontrados arquivos que foram compiladas com [/GL](../../build/reference/gl-whole-program-optimization.md). Não é possível obter a instrumentação local e o link falhou. Deve haver pelo menos um arquivo. obj na linha de comando que é compilado com **/GL** para que a instrumentação possa ocorrer.

Otimização Guiada de perfil (PGO) só está disponível nos compiladores de 64 bits.