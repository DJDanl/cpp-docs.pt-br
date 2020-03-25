---
title: Aviso RW4004 (compilador de recurso)
ms.date: 11/04/2016
f1_keywords:
- RW4004
helpviewer_keywords:
- RW4004
ms.assetid: 596b6a89-9ce7-4ba7-bdcb-e8054c7efafa
ms.openlocfilehash: ca0fb271a5ab43994ec37cc8d59c33877903f6e8
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80182338"
---
# <a name="resource-compiler-warning-rw4004"></a>Aviso RW4004 (compilador de recurso)

Caractere ASCII não equivalente ao código de chave virtual

Um literal de cadeia de caracteres foi usado para o código de chave virtual em um acelerador de tipo VIRTKEY.

Esse aviso permite que você continue, mas lembre-se de que as chaves do acelerador geradas podem não corresponder à cadeia de caracteres que você indicou. (VIRTKEYs use códigos-chave diferentes dos aceleradores ASCII.)

Embora literais de cadeia de caracteres sejam sintaticamente válidos, você só pode garantir que você obtenha o acelerador que deseja usando o **VK_\* valores #define** no Windows. h.
