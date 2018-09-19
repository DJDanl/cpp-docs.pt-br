---
title: Especificador de classe de armazenamento de registro | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- register variables
- register storage class
ms.assetid: 7577bf48-88ec-4191-873c-ef4217a4034e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: e15b6bd4136e2644dbd040ac509b35af772ae4c3
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46028318"
---
# <a name="register-storage-class-specifier"></a>Especificador de classe de armazenamento de registro

**Seção específica da Microsoft**

O compilador do Microsoft C/C++ não honra as solicitações de variáveis de registro feitas pelo usuário. No entanto, para fins de portabilidade, qualquer outra semântica associada à palavra-chave **register** é honrada pelo compilador. Por exemplo, você não pode aplicar o operador unário address-of (**&**) a um objeto registro e a palavra-chave **register** não pode ser usada em matrizes.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Especificadores de classe de armazenamento para declarações de nível interno](../c-language/storage-class-specifiers-for-internal-level-declarations.md)