---
title: C3451 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C3451
dev_langs: C++
helpviewer_keywords: C3451
ms.assetid: a4897a69-e3e7-40bb-bb1c-598644904012
caps.latest.revision: "13"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: c1c0f9de919fbe646eaa6303fa5b1e9fcba886eb
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
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