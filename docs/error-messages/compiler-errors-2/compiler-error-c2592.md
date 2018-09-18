---
title: Erro do compilador C2592 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2592
dev_langs:
- C++
helpviewer_keywords:
- C2592
ms.assetid: 833a4d7b-66ef-4d4c-ae83-a533c2b0eb07
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 3f2377f48eb8102771705f2dedc67a7a15f6fa95
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46030971"
---
# <a name="compiler-error-c2592"></a>Erro do compilador C2592

'class': 'base_class_2' é herdado de 'base_class_1' e não pode ser especificado novamente

Você só pode especificar classes base que não herdam de outras classes base. Nesse caso, apenas `base_class_1` é necessária na especificação de `class` porque `base_class_1` já herda `base_class_2`.