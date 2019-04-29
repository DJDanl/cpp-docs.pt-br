---
title: Erro fatal C1081
ms.date: 11/04/2016
f1_keywords:
- C1081
helpviewer_keywords:
- C1081
ms.assetid: e58adf17-cbe1-4955-a5c7-80622bbba249
ms.openlocfilehash: f3c9f9bde5da7fb120accbb9a8d72e5715ab9d2b
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62229413"
---
# <a name="fatal-error-c1081"></a>Erro fatal C1081

'symbol': nome de arquivo muito longo

O comprimento de um nome de caminho do arquivo excede `_MAX_PATH` (definido pelo stdlib. h como 260 caracteres). Encurte o nome do arquivo.

Se você chamar CL.exe com um nome de arquivo curto, o compilador pode precisar gerar um nome de caminho completo. Por exemplo, `cl -c myfile.cpp` pode fazer com que o compilador gere:

```
D:\<very-long-directory-path>\myfile.cpp
```