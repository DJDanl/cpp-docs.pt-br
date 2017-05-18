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
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Human Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 73e873ae828c03d43a2ded15d95bc92016d434a7
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="register-storage-class-specifier"></a>Especificador de classe de armazenamento de registro
**Seção específica da Microsoft**  
  
 O compilador do Microsoft C/C++ não honra as solicitações de variáveis de registro feitas pelo usuário. No entanto, para fins de portabilidade, qualquer outra semântica associada à palavra-chave **register** é honrada pelo compilador. Por exemplo, você não pode aplicar o operador unário address-of (**&**) a um objeto registro e a palavra-chave **register** não pode ser usada em matrizes.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Especificadores de classe de armazenamento para declarações de nível interno](../c-language/storage-class-specifiers-for-internal-level-declarations.md)
