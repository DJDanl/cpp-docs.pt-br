---
title: Compilador aviso (nível 3) C4306 | Microsoft Docs
ms.custom: ''
ms.date: 08/27/2018
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4306
dev_langs:
- C++
helpviewer_keywords:
- C4306
ms.assetid: 5b2192d7-402d-4b6d-8619-08105e7dcac7
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ab5372213819375a6c1fec3cfc43970415b6486a
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43219988"
---
# <a name="compiler-warning-level-3-c4306"></a>Compilador aviso (nível 3) C4306

> '*identificador*': conversão de '*type1*'para'*type2*' de tamanho maior

O identificador é o tipo convertido para um ponteiro maior. Os bits altos não preenchidos do novo tipo serão preenchidos com zeros.

Esse aviso pode indicar uma conversão indesejada. O ponteiro resultante pode não ser válido.