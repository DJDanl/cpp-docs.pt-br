---
title: Aviso de NMAKE U4011 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- U4011
dev_langs:
- C++
helpviewer_keywords:
- U4011
ms.assetid: e8244514-eba6-4285-8853-7baeefdcd8a4
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a1038ee86f76789451565ab6799795c851c95a95
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46118330"
---
# <a name="nmake-warning-u4011"></a>Aviso U4011 (NMAKE)

'target': nem todos os dependentes disponíveis; destino não compilado

Um serviço dependente do destino especificado não existe ou foi desatualizado, e um comando para atualizar o dependente retornou um código de saída diferente de zero. A opção /K disse NMAKE para continuar processando as partes não relacionadas da compilação e emitir um código de saída 1 quando a sessão NMAKE for concluída.

Esse aviso é precedido por aviso [U4010](../../error-messages/tool-errors/nmake-warning-u4010.md) para cada dependente que falhou ao ser criado ou atualizado.