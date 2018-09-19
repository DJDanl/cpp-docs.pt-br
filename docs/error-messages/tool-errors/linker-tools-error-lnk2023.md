---
title: Erro das LNK2023 das ferramentas de vinculador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK2023
dev_langs:
- C++
helpviewer_keywords:
- LNK2023
ms.assetid: c99e35a8-739a-4a20-a715-29b8c3744703
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7d8deaf8bfb10d3ceb56380560320ebb2cf9a7b8
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46090315"
---
# <a name="linker-tools-error-lnk2023"></a>Erro das Ferramentas de Vinculador LNK2023

dll incorreto ou o ponto de entrada \<dll ou ponto de entrada >

O vinculador está carregando uma versão incorreta do msobj90.dll. Certifique-se de que link.exe e msobj90.dll em seu caminho tenham a mesma versão.

Uma dependência de msobj90.dll pode não estar presente. A lista de dependências para msobj90.dll é:

- Msvcr90.dll

- Kernel32.dll

Verifique seu computador para quaisquer outras cópias msobj90.dll que podem estar desatualizados.