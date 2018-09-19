---
title: Erro do compilador C2854 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2854
dev_langs:
- C++
helpviewer_keywords:
- C2854
ms.assetid: 917fec9c-790a-4149-8dfc-00d17a09199c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7bd49c9fbfa88667cdb2e8bd57466632c0a051e3
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46074806"
---
# <a name="compiler-error-c2854"></a>Erro do compilador C2854

Erro de sintaxe em #pragma hdrstop

O `#pragma hdrstop` fornece um nome de arquivo inválido. O pragma pode ser seguido por um nome de arquivo opcional entre parênteses e aspas:

O exemplo a seguir gera C2854:

```
// C2854.cpp
// compile with: /c
#pragma hdrstop( "\\source\\pchfiles\\myheader.pch" ]   // C2854
// try the following line instead
// #pragma hdrstop( "\\source\\pchfiles\\myheader.pch" )
```