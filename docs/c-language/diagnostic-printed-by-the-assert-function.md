---
title: Diagnóstico impresso pela função assert | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
ms.assetid: 78b64200-520d-40da-9a61-71553f411d4f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1e824e94f79aa01ab3a82675fb3e8f76059c567d
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43195546"
---
# <a name="diagnostic-printed-by-the-assert-function"></a>Diagnóstico impresso pela função assert
**ANSI 4.2** O diagnóstico impresso pela função **assert** e seu comportamento de término  
  
A função **assert** imprimirá uma mensagem de diagnóstico e chamará a rotina **abort** se a expressão for false (0). A mensagem de diagnóstico tem o formato  

> **Assertion failed**: <em>expressão</em>**, arquivo** <em>nome_de_arquivo</em>**, linha** *número_de_linha*  

em que *nome_de_arquivo* é o nome do arquivo de origem e *número_de_linha* é o número de linha da asserção que falhou no arquivo de origem. Nenhuma ação será executada se a *expressão* for true (diferente de zero).  
  
## <a name="see-also"></a>Consulte também  
 [Funções de biblioteca](../c-language/library-functions.md)