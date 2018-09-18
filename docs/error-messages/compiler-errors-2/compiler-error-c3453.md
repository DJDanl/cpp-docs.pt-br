---
title: Erro do compilador C3453 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3453
dev_langs:
- C++
helpviewer_keywords:
- C3453
ms.assetid: dbefdbcf-f697-4239-b7a5-1d99b85e9e7f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7c35c039727cba004db879aea02c086cea4ddcec
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46068788"
---
# <a name="compiler-error-c3453"></a>Erro do compilador C3453

'attribute': atributo não aplicado porque qualificador 'assembly' não correspondeu

Assembly ou atributos de nível de módulo só podem ser especificados como instruções autônomas.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3453.

```
// C3453.cpp
// compile with: /clr /c
[assembly:System::CLSCompliant(true)]   // C3453
// try the following line instead
// [assembly:System::CLSCompliant(true)];
ref class X {};
```