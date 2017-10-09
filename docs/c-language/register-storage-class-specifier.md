---
title: Especificador de classe de armazenamento de registro | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- register variables
- register storage class
ms.assetid: 7577bf48-88ec-4191-873c-ef4217a4034e
caps.latest.revision: 8
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 16d1bf59dfd4b3ef5f037aed9c0f6febfdf1a2e8
ms.openlocfilehash: 95c06471b7d8ea60754c29a9bde3159174e9c194
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="register-storage-class-specifier"></a>Especificador de classe de armazenamento de registro
**Seção específica da Microsoft**  
  
 O compilador do Microsoft C/C++ não honra as solicitações de variáveis de registro feitas pelo usuário. No entanto, para fins de portabilidade, qualquer outra semântica associada à palavra-chave **register** é honrada pelo compilador. Por exemplo, você não pode aplicar o operador unário address-of (**&**) a um objeto registro e a palavra-chave **register** não pode ser usada em matrizes.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Especificadores de classe de armazenamento para declarações de nível interno](../c-language/storage-class-specifiers-for-internal-level-declarations.md)
