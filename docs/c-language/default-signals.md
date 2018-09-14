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
ms.openlocfilehash: 78c369665d398d4b326cf8d27ad0944a594fe1a4
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43758931"
---
# <a name="default-signals"></a>Sinais padrão

**ANSI 4.7.1.1** Se o equivalente a `signal(sig, SIG_DFL)` não for executado antes de uma chamada para o manipulador de sinal, o bloqueio de sinal será executado

No início da execução do programa, os sinais são definidos em seus status padrão.  
  
## <a name="see-also"></a>Consulte também

[Funções de biblioteca](../c-language/library-functions.md)