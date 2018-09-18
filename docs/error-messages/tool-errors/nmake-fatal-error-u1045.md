---
title: NMAKE Erro Fatal U1045 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- U1045
dev_langs:
- C++
helpviewer_keywords:
- U1045
ms.assetid: dc70d162-14b9-4107-9237-7514044d72e3
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c2b9be4f7440d9e79d603e917c1886aebe7c44af
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46056879"
---
# <a name="nmake-fatal-error-u1045"></a>Erro fatal U1045 (NMAKE)

falha de geração: mensagem

Um programa ou comando chamado pelo NMAKE falhou pelo motivo específico. Quando NMAKE chama outro programa — por exemplo, o compilador ou vinculador — a chamada pode falhar ou um erro pode ser retornado pelo programa chamado. Essa mensagem é usada para relatar o erro.

Para corrigir esse problema, primeiro determine a causa do erro. Você pode usar os comandos relatados pela NMAKE [/N](../../build/nmake-options.md) opção para verificar as configurações de ambiente e repetir as ações executadas por NMAKE na linha de comando.