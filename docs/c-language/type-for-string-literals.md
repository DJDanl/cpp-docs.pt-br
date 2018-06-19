---
title: Tipo para literais da cadeia de caracteres | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- string literals, type
- types [C], string literals
ms.assetid: f50a28af-20c1-4440-bdc6-564c86a309c8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1bfabc412c46a5fa73bf0cd3d000bb3823e5a389
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32386765"
---
# <a name="type-for-string-literals"></a>Tipo para literais da cadeia de caracteres
As literais da cadeias de caracteres têm a matriz do tipo `char` (ou seja, **char[ ]**). (As cadeias de caracteres amplos têm a matriz do tipo `wchar_t` (ou seja, **wchar_t[ ]**)). Isso significa que uma cadeia de caracteres é uma matriz com elementos do tipo `char`. O número de elementos na matriz é igual ao número de caracteres na cadeia de caracteres mais um, para o caractere nulo de encerramento.  
  
## <a name="see-also"></a>Consulte também  
 [Literais da cadeia de caracteres C](../c-language/c-string-literals.md)