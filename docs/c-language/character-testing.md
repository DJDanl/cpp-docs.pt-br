---
title: Testes de caractere | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
ms.assetid: 376ba061-bae3-427e-9569-33fa5949a199
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: cdf65de941486cb8256ba8e30a3f186d3e3702d6
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32381688"
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