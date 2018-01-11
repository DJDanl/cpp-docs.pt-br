---
title: "Static Const Int Linkage não é mais Literal | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- literal attribute [C++]
- constants, declaring
- integral constant expressions
ms.assetid: d2a5e3d2-ffb0-4b61-8114-bec5993a1195
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 8f34682fa780ef430d27104d3df9658f9e32ad39
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="static-const-int-linkage-is-no-longer-literal"></a>Static Const Int Linkage não é mais literal
Declaração de constante membro de uma classe foi alterado de extensões gerenciadas para C++ para Visual C++.  
  
 Embora `static const` integrais membros ainda têm suporte, o atributo de vinculação foi alterado. O atributo de vinculação anterior agora é executado em um membro integral literal. Por exemplo, considere a seguinte classe das extensões gerenciadas:  
  
```  
public __gc class Constants {  
public:  
   static const int LOG_DEBUG = 4;  
};  
```  
  
 Isso gera os seguintes atributos CIL subjacentes para o campo (Observe o atributo literal):  
  
```  
.field public static literal int32   
modopt([Microsoft.VisualC]Microsoft.VisualC.IsConstModifier) STANDARD_CLIENT_PRX = int32(0x00000004)  
```  
  
 Enquanto isso ainda compila sob a nova sintaxe:  
  
```  
public ref class Constants {  
public:  
   static const int LOG_DEBUG = 4;  
};  
```  
  
 ele não emite o atributo literal e, portanto, não estiver exibido como uma constante de tempo de execução de CLR:  
  
```  
.field public static int32 modopt([Microsoft.VisualC]Microsoft.VisualC.IsConstModifier) STANDARD_CLIENT_PRX = int32(0x00000004)  
```  
  
 Para ter o mesmo atributo literal entre idioma, a declaração deve ser alterada para recentemente com o suporte `literal` membro de dados, como segue,  
  
```  
public ref class Constants {  
public:  
   literal int LOG_DEBUG = 4;  
};  
```  
  
## <a name="see-also"></a>Consulte também  
 [Declarações de membro em uma classe ou Interface (C + + CLI)](../dotnet/member-declarations-within-a-class-or-interface-cpp-cli.md)   
 [literal](../windows/literal-cpp-component-extensions.md)