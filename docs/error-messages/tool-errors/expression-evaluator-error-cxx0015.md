---
title: "CXX0015 de erro do avaliador de expressão | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- CXX0015
dev_langs:
- C++
helpviewer_keywords:
- CXX0015
- CAN0015
ms.assetid: 35efaf77-d578-48d8-bfc5-fdeb2a46a8b5
caps.latest.revision: 6
author: corob-msft
ms.author: corob
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 22b4db607b40f73cc5c240b7fd75f5230832ec0f
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="expression-evaluator-error-cxx0015"></a>Erro CXX0015 (avaliador de expressão)
expressão muito complexa (estouro de pilha)  
  
 A expressão inserida era muito complexa ou aninhadas muito profundamente para a quantidade de armazenamento disponível para o avaliador de expressão C.  
  
 Estouro geralmente ocorre devido a muitos cálculos pendentes.  
  
 Reorganizar a expressão para que cada componente da expressão pode ser avaliada como ele é encontrado, em vez de ter que esperar para outras partes da expressão a ser calculada.  
  
 Divida a expressão em vários comandos.  
  
 Esse erro é idêntico ao CAN0015.
