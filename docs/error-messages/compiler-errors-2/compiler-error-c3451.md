---
title: C3451 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3451
dev_langs:
- C++
helpviewer_keywords:
- C3451
ms.assetid: a4897a69-e3e7-40bb-bb1c-598644904012
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7a8aa09f0eb38364179be1608c3f230fe8059509
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33250410"
---
# <a name="compiler-error-c3451"></a>C3451 de erro do compilador
'attribute': não é possível aplicar o atributo não gerenciado para 'type'  
  
 Um atributo de C++ não pode ser aplicado a um tipo CLR. Consulte [referência de atributos C++](../../windows/cpp-attributes-reference.md) para obter mais informações.  
  
 Para obter mais informações, consulte [atributos definidos pelo usuário](../../windows/user-defined-attributes-cpp-component-extensions.md).  
  
 Esse erro pode ser gerado como resultado do trabalho de conformidade do compilador que foi feito para o Visual C++ 2005: o [uuid](../../windows/uuid-cpp-attributes.md) atributo não é permitido em um atributo definido pelo usuário usando a programação de CLR. Use <xref:System.Runtime.InteropServices.GuidAttribute> em seu lugar.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3451.  
  
```  
// C3451.cpp  
// compile with: /clr /c  
using namespace System;  
[ attribute(AttributeTargets::All) ]  
public ref struct MyAttr {};  
  
[ MyAttr, helpstring("test") ]   // C3451  
// try the following line instead  
// [ MyAttr ]  
public ref struct ABC {};  
```