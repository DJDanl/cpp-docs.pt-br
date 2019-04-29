---
title: Aviso RW4004 (compilador de recurso)
ms.date: 11/04/2016
f1_keywords:
- RW4004
helpviewer_keywords:
- RW4004
ms.assetid: 596b6a89-9ce7-4ba7-bdcb-e8054c7efafa
ms.openlocfilehash: bafd1084a665fc656fe184064a48e5fffc61c957
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62346074"
---
# <a name="resource-compiler-warning-rw4004"></a>Aviso RW4004 (compilador de recurso)

Caractere ASCII não é equivalente a código de tecla virtual

Um literal de cadeia de caracteres foi usado para o código de tecla virtual em um acelerador de tipo VIRTKEY.

Esse aviso permite que você continuar, mas lembre-se de que as teclas de aceleração geradas podem não corresponder a cadeia de caracteres que você indicou. (VIRTKEYs usar códigos de tecla diferentes de aceleradores de ASCII).

Enquanto os literais de cadeia de caracteres são sintaticamente válidos, você só pode garantir que você obtenha o Acelerador que desejar usando o **VK_\* #define** valores no Windows. h.