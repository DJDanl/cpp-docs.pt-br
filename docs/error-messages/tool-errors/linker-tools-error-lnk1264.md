---
title: Erro das Ferramentas de Vinculador LNK1264
ms.date: 11/04/2016
f1_keywords:
- LNK1264
helpviewer_keywords:
- LNK1264
ms.assetid: 23b1aad7-d382-42c1-bae8-db68575c57a8
ms.openlocfilehash: 00041e677ac7b69df9981551ee3b6cc18f9eb33d
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80183755"
---
# <a name="linker-tools-error-lnk1264"></a>Erro das Ferramentas de Vinculador LNK1264

/LTCG: PGINSTRUMENT especificado, mas nenhuma geração de código é necessária; falha na instrumentação

**/LTCG: PGINSTRUMENT** foi especificado, mas não foram encontrados arquivos. obj que foram compilados com [/GL](../../build/reference/gl-whole-program-optimization.md). A instrumentação não pode ocorrer e o link falhou. Deve haver pelo menos um arquivo. obj na linha de comando que é compilado com **/GL** para que a instrumentação possa ocorrer.

A PGO (otimização guiada por perfil) só está disponível em compiladores de 64 bits.
