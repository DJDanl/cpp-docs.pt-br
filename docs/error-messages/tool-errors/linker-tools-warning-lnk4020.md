---
title: Aviso LNK4020 (Ferramentas de Vinculador)
ms.date: 05/29/2018
f1_keywords:
- LNK4020
helpviewer_keywords:
- LNK4020
ms.openlocfilehash: e818909cc0b590b0f7727846cfd7b469e8bc0e3f
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80194220"
---
# <a name="linker-tools-warning-lnk4020"></a>Aviso LNK4020 (Ferramentas de Vinculador)

> um registro de tipo em '*filename*' está corrompido; alguns tipos e símbolos podem não estar acessíveis a partir do depurador

O *nome* do arquivo PDB tem um registro de tipo corrompido.

Esse problema é geralmente secundário a outros problemas de compilação; a menos que esse seja o primeiro problema de compilação relatado, lide com os outros erros e avisos primeiro. Se esse for o primeiro problema relatado, talvez seja necessário limpar seus diretórios de compilação e recompilar seu projeto. Se você usar processos de Build paralelos, veja se o erro persiste quando você serializa sua compilação.
