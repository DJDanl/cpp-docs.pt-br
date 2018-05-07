---
title: RC2151 de erro do compilador de recurso | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- RC2151
dev_langs:
- C++
helpviewer_keywords:
- RC2151
ms.assetid: 3c47e535-c78d-4338-aab9-9b47e2c34728
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8349aa14de6aec96fa1b526cbcffbe79036f804d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="resource-compiler-error-rc2151"></a>Erro RC2151 (compilador de recurso)
não é possível reutilizar a constantes de cadeia de caracteres  
  
 Você está usando o mesmo valor duas vezes em um **STRINGTABLE** instrução. Verifique se que você está misturando não sobrepostos valores decimais e hexadecimais.  
  
 Cada ID em um **STRINGTABLE** devem ser exclusivos. Para máxima eficiência use contíguas constantes com início em um múltiplo de 16.