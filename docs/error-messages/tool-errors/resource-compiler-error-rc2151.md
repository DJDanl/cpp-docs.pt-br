---
title: RC2151 de erro do compilador de recurso | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- RC2151
dev_langs:
- C++
helpviewer_keywords:
- RC2151
ms.assetid: 3c47e535-c78d-4338-aab9-9b47e2c34728
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
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: b5893d4622fb36d0a5dfb54a4003ddf178de05d1
ms.lasthandoff: 02/25/2017

---
# <a name="resource-compiler-error-rc2151"></a>Erro RC2151 (compilador de recurso)
não é possível reutilizar a constantes de cadeia de caracteres  
  
 Você está usando o mesmo valor duas vezes em uma **STRINGTABLE** instrução. Verifique se que você está misturando não sobrepostos valores decimais e hexadecimais.  
  
 Cada ID em um **STRINGTABLE** deve ser exclusivo. Para máxima eficiência use contíguo constantes com início em um múltiplo de 16.
