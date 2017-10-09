---
title: Armazenamento de literais da cadeia de caracteres | Microsoft Docs
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
- string literals, storage
ms.assetid: ba5e4d2c-d456-44b3-a8ca-354af547ac50
caps.latest.revision: 9
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 16d1bf59dfd4b3ef5f037aed9c0f6febfdf1a2e8
ms.openlocfilehash: 2a1a001899e46fbd8894b72f2c8cd806f1834b7e
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="storage-of-string-literals"></a>Armazenamento de literais da cadeia de caracteres
Os caracteres de uma cadeia de caracteres literal são armazenados em locais de memória contíguos. Uma sequência de escape (como **\\\\** ou **\\“**) dentro de uma literal de cadeia de caracteres conta como um único caractere. Um caractere nulo (representado pela sequência de escape **\0**) é acrescentado automaticamente às literais de cadeia de caracteres e marca o fim de cada uma delas. (Isso ocorre durante o [fase da translação](../preprocessor/phases-of-translation.md) 7.) Observe que o compilador pode não armazenar duas cadeias de caracteres idênticas em dois endereços diferentes. [/GF](../build/reference/gf-eliminate-duplicate-strings.md) força o compilador a colocar uma única cópia de cadeias de caracteres idênticas no arquivo executável.  
  
## <a name="remarks"></a>Comentários  
 **Seção específica da Microsoft**  
  
 As cadeias de caracteres têm duração de armazenamento estático. Consulte [Classes de armazenamento](../c-language/c-storage-classes.md) para obter informações sobre a duração de armazenamento.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Literais da cadeia de caracteres C](../c-language/c-string-literals.md)
