---
title: "Coprocessador de ponto flutuante e convenções de chamada | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- floating-point numbers, coprocessor
- floating-point coprocessor
- floating-point numbers
ms.assetid: 3cc6615a-b308-4cf7-9570-83e192a832b3
caps.latest.revision: 7
author: mikeblome
ms.author: mblome
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
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 6d14f7f445064316c83b31e9b4cdc421d68d7255
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="floating-point-coprocessor-and-calling-conventions"></a>Coprocessador de ponto flutuante e convenções de chamada
Se você estiver escrevendo assembly rotinas para flutuante coprocessador de ponto, você deve preservar flutuante aponte a palavra de controle e limpar a pilha de coprocessador, a menos que você estiver retornando um **float** ou **duplo** valor (que a função deve retornar em ST(0)).  
  
## <a name="see-also"></a>Consulte também  
 [Convenções de chamada](../cpp/calling-conventions.md)
