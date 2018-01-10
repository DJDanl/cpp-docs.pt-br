---
title: Tipo para literais da cadeia de caracteres | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- string literals, type
- types [C], string literals
ms.assetid: f50a28af-20c1-4440-bdc6-564c86a309c8
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 2342777bfd2b1a039e68766e8dfe00ac2fa2f932
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="type-for-string-literals"></a>Tipo para literais da cadeia de caracteres
As literais da cadeias de caracteres têm a matriz do tipo `char` (ou seja, **char[ ]**). (As cadeias de caracteres amplos têm a matriz do tipo `wchar_t` (ou seja, **wchar_t[ ]**)). Isso significa que uma cadeia de caracteres é uma matriz com elementos do tipo `char`. O número de elementos na matriz é igual ao número de caracteres na cadeia de caracteres mais um, para o caractere nulo de encerramento.  
  
## <a name="see-also"></a>Consulte também  
 [Literais da cadeia de caracteres C](../c-language/c-string-literals.md)