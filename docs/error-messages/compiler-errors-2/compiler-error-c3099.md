---
title: Erro do compilador C3099 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3099
dev_langs:
- C++
helpviewer_keywords:
- C3099
ms.assetid: b3dded0f-76c9-42c1-991b-532eb8619661
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ea57a79fab92152824b7c9aaf0c5d50c14fee32e
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43211989"
---
# <a name="compiler-error-c3099"></a>Erro do compilador C3099
'palavra-chave': use [System::AttributeUsageAttribute] para atributos gerenciados. Use [Windows::Foundation::Metadata::AttributeUsageAttribute] para atributos de WinRT  
  
 Use <xref:System.AttributeUsageAttribute> declarar **/clr** atributos. Use `Windows::Foundation::Metadata::AttributeUsageAttribute` declarar atributos de tempo de execução do Windows.  
  
 Para obter mais informações sobre atributos /CLR, consulte [atributos definidos pelo usuário](../../windows/user-defined-attributes-cpp-component-extensions.md). Para atributos com suporte em tempo de execução do Windows, consulte [namespace do Windows](https://msdn.microsoft.com/library/windows/apps/windows.foundation.metadata.aspx)  
  
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