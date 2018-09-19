---
title: RW4004 de aviso do compilador de recurso | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- RW4004
dev_langs:
- C++
helpviewer_keywords:
- RW4004
ms.assetid: 596b6a89-9ce7-4ba7-bdcb-e8054c7efafa
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 33305f1f86c0cc1722e4a235ec27927f6e70675f
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46095983"
---
# <a name="resource-compiler-warning-rw4004"></a>Aviso RW4004 (compilador de recurso)

Caractere ASCII não é equivalente a código de tecla virtual

Um literal de cadeia de caracteres foi usado para o código de tecla virtual em um acelerador de tipo VIRTKEY.

Esse aviso permite que você continuar, mas lembre-se de que as teclas de aceleração geradas podem não corresponder a cadeia de caracteres que você indicou. (VIRTKEYs usar códigos de tecla diferentes de aceleradores de ASCII).

Enquanto os literais de cadeia de caracteres são sintaticamente válidos, você só pode garantir que você obtenha o Acelerador que desejar usando o **VK_\* #define** valores no Windows. h.