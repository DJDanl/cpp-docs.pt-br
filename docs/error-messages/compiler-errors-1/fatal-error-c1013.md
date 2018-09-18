---
title: Erro fatal C1013 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C1013
dev_langs:
- C++
helpviewer_keywords:
- C1013
ms.assetid: 5514a679-efe7-4055-bdd3-5693ca0c332f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 33c10062cac83984fb1c68835780497b89c4cbc1
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46050498"
---
# <a name="fatal-error-c1013"></a>Erro fatal C1013

limite do compilador: muitos parênteses abertos

Uma expressão contém muitos níveis de parênteses em uma única expressão. Simplifique a expressão ou dividi-la em várias instruções.

Antes do Visual C++ 6.0 Service Pack 3, o limite de parênteses aninhados em uma única expressão era 59. Atualmente, o limite de parênteses aninhados é 256.