---
title: RC2148 de erro do compilador de recurso | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- RC2148
dev_langs:
- C++
helpviewer_keywords:
- RC2148
ms.assetid: 0290065c-35d3-4815-80c5-40bf7132ae1d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d10e18eef4691c0a018feb583ffb93499e86ccb6
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="resource-compiler-error-rc2148"></a>Erro RC2148 (compilador de recurso)
ID de SUBIDIOMA muito grande  
  
 O valor de ID de SUBIDIOMA estava fora do intervalo.  
  
 O **idioma** instrução deve usar a seguinte sintaxe:  
  
 **IDIOMA** *primary_language_ID*,*secondary_language_ID*  
  
 IDs de SUBIDIOMA válidas são definidas como **SUBLANG_** constantes no arquivo Winnt. h.