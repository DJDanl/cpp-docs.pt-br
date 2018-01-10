---
title: Testes de caractere | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: 376ba061-bae3-427e-9569-33fa5949a199
caps.latest.revision: "6"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: aeea6573b49e3bb093c3eb343ac3c89c27f0466b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="character-testing"></a>Testes de caractere
**ANSI 4.3.1** Os conjuntos de caracteres testados pelas funções `isalnum`, `isalpha`, `iscntrl`, `islower`, `isprint` e `isupper`  
  
 A lista a seguir descreve essas funções como são implementadas pelo compilador Microsoft C.  
  
|Função|Testes para|  
|--------------|---------------|  
|`isalnum`|Caracteres 0 – 9, A–Z, a–z ASCII 48– 57, 65– 90, 97– 122|  
|`isalpha`|Caracteres A–Z, a–z ASCII 65–90, 97–122|  
|`iscntrl`|ASCII 0 – 31, 127|  
|`islower`|Caracteres A–Z ASCII 97–122|  
|`isprint`|Caracteres A–Z, a–z, 0 – 9, pontuação, espaço ASCII 32–126|  
|`isupper`|Caracteres A–Z ASCII 65–90|  
  
## <a name="see-also"></a>Consulte também  
 [Funções de biblioteca](../c-language/library-functions.md)