---
title: Especificador de classe de armazenamento de registro
ms.date: 11/04/2016
helpviewer_keywords:
- register variables
- register storage class
ms.assetid: 7577bf48-88ec-4191-873c-ef4217a4034e
ms.openlocfilehash: 513213222ee2c598455709a0891977a0949c8555
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87229552"
---
# <a name="register-storage-class-specifier"></a>Especificador de classe de armazenamento de registro

**Específico da Microsoft**

O compilador do Microsoft C/C++ não honra as solicitações de variáveis de registro feitas pelo usuário. No entanto, para portabilidade, todas as demais semânticas associadas à **`register`** palavra-chave são respeitadas pelo compilador. Por exemplo, você não pode aplicar o operador address-of unário ( **&** ) a um objeto Register, nem a **`register`** palavra-chave ser usada em matrizes.

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Especificadores de classe de armazenamento para declarações de nível interno](../c-language/storage-class-specifiers-for-internal-level-declarations.md)
