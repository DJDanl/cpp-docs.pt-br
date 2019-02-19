---
title: Especificador de classe de armazenamento de registro
ms.date: 11/04/2016
helpviewer_keywords:
- register variables
- register storage class
ms.assetid: 7577bf48-88ec-4191-873c-ef4217a4034e
ms.openlocfilehash: 0fac6db2254a909d0ec558a7e76f7ccf32aa7ac3
ms.sourcegitcommit: f4be868c0d1d78e550fba105d4d3c993743a1f4b
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/12/2019
ms.locfileid: "56147341"
---
# <a name="register-storage-class-specifier"></a>Especificador de classe de armazenamento de registro

**Seção específica da Microsoft**

O compilador do Microsoft C/C++ não honra as solicitações de variáveis de registro feitas pelo usuário. No entanto, para fins de portabilidade, qualquer outra semântica associada à palavra-chave **register** é honrada pelo compilador. Por exemplo, você não pode aplicar o operador unário address-of (**&**) a um objeto registro e a palavra-chave **register** não pode ser usada em matrizes.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Especificadores de classe de armazenamento para declarações de nível interno](../c-language/storage-class-specifiers-for-internal-level-declarations.md)
