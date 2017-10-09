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
caps.latest.revision: 6
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 16d1bf59dfd4b3ef5f037aed9c0f6febfdf1a2e8
ms.openlocfilehash: d6e5ea4e5f8bae3fda190ac7a7136035aea0c948
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="diagnostic-printed-by-the-assert-function"></a>Diagnóstico impresso pela função assert
**ANSI 4.2** O diagnóstico impresso pela função **assert** e seu comportamento de término  
  
 A função **assert** imprimirá uma mensagem de diagnóstico e chamará a rotina **abort** se a expressão for false (0). A mensagem de diagnóstico tem o formato  
  
 **Assertion failed**: *expressão***, arquivo** *nome_de_arquivo***, linha** *número_de_linha*  
  
 onde nome_de_arquivo é o nome do arquivo de origem e número_de_linha é o número da linha da asserção que falhou no arquivo de origem. Nenhuma ação será executada se a expressão for true (diferente de zero).  
  
## <a name="see-also"></a>Consulte também  
 [Funções de biblioteca](../c-language/library-functions.md)
