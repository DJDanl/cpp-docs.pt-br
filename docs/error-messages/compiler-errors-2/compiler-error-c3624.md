---
title: Erro do compilador C3624
ms.date: 11/04/2016
f1_keywords:
- C3624
helpviewer_keywords:
- C3624
ms.assetid: eaac6a4f-eb11-4e4d-ab12-124ba995c5cf
ms.openlocfilehash: bb574b194f01aa1da27b962ed6be327f4f988c3c
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50563521"
---
# <a name="compiler-error-c3624"></a>Erro do compilador C3624

'type': uso deste tipo requer uma referência ao assembly 'assembly'

Não foi especificado um assembly (referência) necessário para compilar seu código; Passe o assembly para o [#using](../../preprocessor/hash-using-directive-cpp.md) diretiva.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3624:

```
// C3624.cpp
// compile with: /clr /c
#using <System.Windows.Forms.dll>

// Uncomment the following 2 lines to resolve.
// #using <System.dll>
// #using <System.Drawing.dll>

using namespace System;

public ref class MyForm : public Windows::Forms::Form {};   // C3624
```
