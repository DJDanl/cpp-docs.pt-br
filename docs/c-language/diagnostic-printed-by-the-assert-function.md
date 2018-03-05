---
title: "Diagnóstico impresso pela função assert | Microsoft Docs"
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
ms.assetid: 78b64200-520d-40da-9a61-71553f411d4f
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 243956f1d85b07b5d5b810ebfd112b2cbfe16242
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="diagnostic-printed-by-the-assert-function"></a>Diagnóstico impresso pela função assert
**ANSI 4.2** O diagnóstico impresso pela função **assert** e seu comportamento de término  
  
 A função **assert** imprimirá uma mensagem de diagnóstico e chamará a rotina **abort** se a expressão for false (0). A mensagem de diagnóstico tem o formato  
  
 **Assertion failed**: *expressão***, arquivo** *nome_de_arquivo***, linha** *número_de_linha*  
  
 onde nome_de_arquivo é o nome do arquivo de origem e número_de_linha é o número da linha da asserção que falhou no arquivo de origem. Nenhuma ação será executada se a expressão for true (diferente de zero).  
  
## <a name="see-also"></a>Consulte também  
 [Funções de biblioteca](../c-language/library-functions.md)