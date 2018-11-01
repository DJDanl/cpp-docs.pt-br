---
title: Aviso LNK4020 ferramentas de vinculador
ms.date: 05/29/2018
f1_keywords:
- LNK4020
helpviewer_keywords:
- LNK4020
ms.openlocfilehash: 7810fd9a97a8f6e22ad362819a024358a9f4b07c
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50609736"
---
# <a name="linker-tools-warning-lnk4020"></a>Aviso LNK4020 ferramentas de vinculador

> um registro de tipo '*filename*' está corrompido; alguns tipos e símbolos não podem ser acessados a partir do depurador

O arquivo PDB *filename* tem um registro de tipo corrompido.

Esse problema geralmente é secundário para outros problemas de compilação; a menos que esse é o primeiro problema de compilação relatados, lidar com os outros erros e avisos primeiro. Se esse for o primeiro problema relatado, você talvez precise limpar seus diretórios de compilação e recompile o projeto. Se você usar processos de compilação paralela, veja se o erro persistir quando você serializa sua compilação.