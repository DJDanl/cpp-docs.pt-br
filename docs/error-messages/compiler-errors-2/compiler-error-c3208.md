---
title: Erro do compilador C3208 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3208
dev_langs:
- C++
helpviewer_keywords:
- C3208
ms.assetid: 6d060bfe-52cf-4599-8f70-bdeb5a670df3
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 53564517eaed44c21e6eccb58ad6399788129687
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46078498"
---
# <a name="compiler-error-c3208"></a>Erro do compilador C3208

'function': lista de parâmetros de modelo para classe modelo 'class' não coincide com lista de parâmetros de template para parâmetro de modelo 'parameter'

Um parâmetro de modelo não tem o mesmo número de parâmetros de modelo que o modelo de classe fornecido.

O exemplo a seguir gera C3208:

```
// C3208.cpp
template <template <class T> class TT >
int f();

template <class T1, class T2>
struct S;

template <class T1>
struct R;

int i = f<S>();   // C3208
// try the following line instead
// int i = f<R>();
```