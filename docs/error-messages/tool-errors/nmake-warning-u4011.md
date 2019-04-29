---
title: Aviso U4011 (NMAKE)
ms.date: 11/04/2016
f1_keywords:
- U4011
helpviewer_keywords:
- U4011
ms.assetid: e8244514-eba6-4285-8853-7baeefdcd8a4
ms.openlocfilehash: 3b73e92c929b3dd5924584ab732f731d565d0430
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62359768"
---
# <a name="nmake-warning-u4011"></a>Aviso U4011 (NMAKE)

'target': nem todos os dependentes disponíveis; destino não compilado

Um serviço dependente do destino especificado não existe ou foi desatualizado, e um comando para atualizar o dependente retornou um código de saída diferente de zero. A opção /K disse NMAKE para continuar processando as partes não relacionadas da compilação e emitir um código de saída 1 quando a sessão NMAKE for concluída.

Esse aviso é precedido por aviso [U4010](../../error-messages/tool-errors/nmake-warning-u4010.md) para cada dependente que falhou ao ser criado ou atualizado.