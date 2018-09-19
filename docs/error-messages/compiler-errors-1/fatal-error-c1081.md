---
title: Erro fatal C1081 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C1081
dev_langs:
- C++
helpviewer_keywords:
- C1081
ms.assetid: e58adf17-cbe1-4955-a5c7-80622bbba249
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b34f2f19a0bb8770ea9292fef120c415c0fb255a
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46060519"
---
# <a name="fatal-error-c1081"></a>Erro fatal C1081

'symbol': nome de arquivo muito longo

O comprimento de um nome de caminho do arquivo excede `_MAX_PATH` (definido pelo stdlib. h como 260 caracteres). Encurte o nome do arquivo.

Se você chamar CL.exe com um nome de arquivo curto, o compilador pode precisar gerar um nome de caminho completo. Por exemplo, `cl -c myfile.cpp` pode fazer com que o compilador gere:

```
D:\<very-long-directory-path>\myfile.cpp
```