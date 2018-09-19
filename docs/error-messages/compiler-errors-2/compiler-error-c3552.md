---
title: Erro do compilador C3552 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3552
dev_langs:
- C++
helpviewer_keywords:
- C3552
ms.assetid: 83401524-1bf1-44c0-8aca-a6eb35c4224c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: dd9f7ae37500e115fa33fa61298cab800c88f9c7
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46081254"
---
# <a name="compiler-error-c3552"></a>Erro do compilador C3552

'typename': um tipo de retorno especificado tardia não pode conter 'auto'

Se você usar o `auto` palavra-chave como um espaço reservado para o tipo de retorno de uma função, você deve fornecer um tipo de retorno com especificação tardia. No entanto, você não pode usar outro `auto` palavra-chave para especificar o retorno com especificação tardia tipo. Por exemplo, o fragmento de código a seguir produz o erro C3552.

`auto myFunction->auto; // C3552`