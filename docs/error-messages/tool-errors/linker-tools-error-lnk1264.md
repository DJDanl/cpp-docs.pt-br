---
title: Erro das Ferramentas de Vinculador LNK1264
ms.date: 11/04/2016
f1_keywords:
- LNK1264
helpviewer_keywords:
- LNK1264
ms.assetid: 23b1aad7-d382-42c1-bae8-db68575c57a8
ms.openlocfilehash: ca17b6946b9e988507af2786825223e042356d0e
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62160582"
---
# <a name="linker-tools-error-lnk1264"></a>Erro das Ferramentas de Vinculador LNK1264

/LTCG:PGINSTRUMENT especificado, mas não há geração de código necessária; falhado de instrumentação

**/LTCG:PGINSTRUMENT** foi especificado mas. obj não foram encontrados arquivos que foram compiladas com [/GL](../../build/reference/gl-whole-program-optimization.md). Não é possível obter a instrumentação local e o link falhou. Deve haver pelo menos um arquivo. obj na linha de comando que é compilado com **/GL** para que a instrumentação possa ocorrer.

Otimização Guiada de perfil (PGO) só está disponível nos compiladores de 64 bits.