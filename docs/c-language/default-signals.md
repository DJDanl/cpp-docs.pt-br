---
title: Sinais Padrão | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- default signals
- defaults, signals
ms.assetid: db9fc17b-75c0-4d33-86be-c536584bbede
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 4ff2612538cd6953672d9f91dcb603b4676be100
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46098914"
---
# <a name="default-signals"></a>Sinais padrão

**ANSI 4.7.1.1** Se o equivalente a `signal(sig, SIG_DFL)` não for executado antes de uma chamada para o manipulador de sinal, o bloqueio de sinal será executado

No início da execução do programa, os sinais são definidos em seus status padrão.

## <a name="see-also"></a>Consulte também

[Funções de biblioteca](../c-language/library-functions.md)