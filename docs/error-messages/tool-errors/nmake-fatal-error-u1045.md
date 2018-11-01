---
title: Erro fatal U1045 (NMAKE)
ms.date: 11/04/2016
f1_keywords:
- U1045
helpviewer_keywords:
- U1045
ms.assetid: dc70d162-14b9-4107-9237-7514044d72e3
ms.openlocfilehash: bb1dfac36eda263e656ca85fb1f5b74babfd2e2a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50607958"
---
# <a name="nmake-fatal-error-u1045"></a>Erro fatal U1045 (NMAKE)

falha de geração: mensagem

Um programa ou comando chamado pelo NMAKE falhou pelo motivo específico. Quando NMAKE chama outro programa — por exemplo, o compilador ou vinculador — a chamada pode falhar ou um erro pode ser retornado pelo programa chamado. Essa mensagem é usada para relatar o erro.

Para corrigir esse problema, primeiro determine a causa do erro. Você pode usar os comandos relatados pela NMAKE [/N](../../build/nmake-options.md) opção para verificar as configurações de ambiente e repetir as ações executadas por NMAKE na linha de comando.