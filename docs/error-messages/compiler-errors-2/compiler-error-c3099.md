---
title: C3099 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3099
dev_langs:
- C++
helpviewer_keywords:
- C3099
ms.assetid: b3dded0f-76c9-42c1-991b-532eb8619661
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: b0303ef909d6f18cb54c70bc64ab06d415e96da5
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3099"></a>C3099 de erro do compilador
'palavra-chave': usar [System::AttributeUsageAttribute] atributos gerenciados; Use [Windows::Foundation::Metadata::AttributeUsageAttribute] para atributos de WinRT  
  
 Use <xref:System.AttributeUsageAttribute> para declarar **/clr** atributos. Use `Windows::Foundation::Metadata::AttributeUsageAttribute` para declarar os atributos de tempo de execução do Windows.  
  
 Para obter mais informações sobre atributos /CLR, consulte [atributos definidos pelo usuário](../../windows/user-defined-attributes-cpp-component-extensions.md). Para atributos com suporte em tempo de execução do Windows, consulte [Windows.Foundation.Metadata namespace](http://msdn.microsoft.com/library/windows/apps/windows.foundation.metadata.aspx)  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3099 e mostra como corrigi-lo.  
  
```  
// C3099.cpp  
// compile with: /clr /c  
using namespace System;  
[usage(10)]   // C3099  
// try the following line instead  
// [AttributeUsageAttribute(AttributeTargets::All)]  
ref class A : Attribute {};  
```
