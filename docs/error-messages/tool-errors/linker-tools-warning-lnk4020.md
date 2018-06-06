---
title: Ferramentas de vinculador aviso LNK4020 | Microsoft Docs
ms.custom: ''
ms.date: 05/29/2018
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK4020
dev_langs:
- C++
helpviewer_keywords:
- LNK4020
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7e55239b90910f6c151949c53939d4f8ed7c15c5
ms.sourcegitcommit: a4454b91d556a3dc43d8755cdcdeabcc9285a20e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/01/2018
ms.locfileid: "34570678"
---
# <a name="linker-tools-warning-lnk4020"></a>Aviso LNK4020 ferramentas de vinculador

> um registro de tipo '*filename*' está corrompido; alguns tipos e símbolos não podem ser acessados a partir do depurador

O arquivo PDB *filename* tem um registro de tipo corrompida.

Esse problema geralmente é secundário para outros problemas de compilação; a menos que esse é o primeiro problema de compilação relatados, lidar com os erros e avisos primeiro. Se esse for o primeiro problema relatado, você precisará limpar seus diretórios de compilação e recompilar o projeto. Se você usar processos de compilação paralela, veja se o erro persistir ao serializar sua compilação.