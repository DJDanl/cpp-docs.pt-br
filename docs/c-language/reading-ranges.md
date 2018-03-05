---
title: Lendo intervalos | Microsoft Docs
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
ms.assetid: 99de29ce-ab14-46f4-97e1-2081fd996b53
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 36fd3354e21b063dba05e24e1e3ba0d206a89343
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="reading-ranges"></a>Intervalos de leitura
**ANSI 4.9.6.2** A interpretação de um caractere de sublinhado (–) que não é o primeiro nem o último caractere da scanlist para % [conversão na função `fscanf`  
  
 A linha a seguir  
  
```  
fscanf( fileptr, "%[A-Z]", strptr);  
```  
  
 lê qualquer número de caracteres de A a Z para a cadeia de caracteres para a qual `strptr` aponta.  
  
## <a name="see-also"></a>Consulte também  
 [Funções de biblioteca](../c-language/library-functions.md)