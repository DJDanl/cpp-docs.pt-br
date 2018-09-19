---
title: Compilador aviso (nível 4) C4517 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4517
dev_langs:
- C++
helpviewer_keywords:
- C4517
ms.assetid: 87cc12b8-7331-4f3a-a863-d6a75d9599c3
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f71fca2804a6869fbb58073eb0c11a3ac1f18153
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46098869"
---
# <a name="compiler-warning-level-4-c4517"></a>Compilador aviso (nível 4) C4517

declarações de acesso são preteridas; declarações de using membro fornecem uma alternativa melhor

O Comitê de C++ ANSI declarou declarações de acesso (alterando o acesso de um membro em uma classe derivada sem a [usando](../../cpp/using-declaration.md) palavra-chave) fiquem desatualizados. Declarações de acesso podem não ter suporte por versões futuras do C++.