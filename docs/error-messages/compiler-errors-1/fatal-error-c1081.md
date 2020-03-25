---
title: Erro fatal C1081
ms.date: 11/04/2016
f1_keywords:
- C1081
helpviewer_keywords:
- C1081
ms.assetid: e58adf17-cbe1-4955-a5c7-80622bbba249
ms.openlocfilehash: b8630a26d14c68a5f1abe45bb0b8d0141d0dedbb
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80204185"
---
# <a name="fatal-error-c1081"></a>Erro fatal C1081

' Symbol ': nome de arquivo muito longo

O comprimento de um nome de caminho de arquivo excede `_MAX_PATH` (definido por STDLIB. h como 260 caracteres). Diminua o nome do arquivo.

Se você chamar CL. exe com um nome de arquivo curto, talvez o compilador precise gerar um nome de caminho completo. Por exemplo, `cl -c myfile.cpp` pode fazer com que o compilador gere:

```
D:\<very-long-directory-path>\myfile.cpp
```
