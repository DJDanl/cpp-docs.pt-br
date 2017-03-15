---
title: C3099 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
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
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: eb33437900a0677755c669e1413e47c1c737d2ed
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3099"></a>C3099 de erro do compilador
'palavra-chave': usar [System::AttributeUsageAttribute] atributos gerenciados; Use [Windows::Foundation::Metadata::AttributeUsageAttribute] para atributos do WinRT  
  
 Use <xref:System.AttributeUsageAttribute>para declarar **/clr** atributos.</xref:System.AttributeUsageAttribute> Use `Windows::Foundation::Metadata::AttributeUsageAttribute` para declarar atributos de tempo de execução do Windows.  
  
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
