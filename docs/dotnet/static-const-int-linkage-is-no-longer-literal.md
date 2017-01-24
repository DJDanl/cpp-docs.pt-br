---
title: "Static Const Int Linkage n&#227;o &#233; mais literal | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "constantes, declarando"
  - "expressões de constante integral"
  - "atributo literal [C++]"
ms.assetid: d2a5e3d2-ffb0-4b61-8114-bec5993a1195
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Static Const Int Linkage n&#227;o &#233; mais literal
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A declaração de um membro constante de uma classe foi alterada de extensões gerenciadas para C\+\+ a [!INCLUDE[cpp_current_long](../Token/cpp_current_long_md.md)].  
  
 Embora os membros de `static const` foi integral com suporte ainda, o atributo de vinculação foi alterada.  O atributo antigo de vinculação é levado agora um membro integral literal.  Por exemplo, considere a seguinte classe de extensão gerenciada:  
  
```  
public __gc class Constants {  
public:  
   static const int LOG_DEBUG = 4;  
};  
```  
  
 Isso permite gerenciar os seguintes atributos subjacentes de CIL para o campo \(observe o atributo literal\):  
  
```  
.field public static literal int32   
modopt([Microsoft.VisualC]Microsoft.VisualC.IsConstModifier) STANDARD_CLIENT_PRX = int32(0x00000004)  
```  
  
 Quando isso ainda criar na nova sintaxe:  
  
```  
public ref class Constants {  
public:  
   static const int LOG_DEBUG = 4;  
};  
```  
  
 não emite o atributo literal, e em virtude disso não é exibido como uma constante em tempo de execução de CLR:  
  
```  
.field public static int32 modopt([Microsoft.VisualC]Microsoft.VisualC.IsConstModifier) STANDARD_CLIENT_PRX = int32(0x00000004)  
```  
  
 Para ter o mesmo atributo literal entre processosé idioma, a declaração deve ser alterada para o membro de dados com suporte recente de `literal` , como segue,  
  
```  
public ref class Constants {  
public:  
   literal int LOG_DEBUG = 4;  
};  
```  
  
## Consulte também  
 [Declarações de membro em uma classe ou uma interface \(C\+\+\/CLI\)](../dotnet/member-declarations-within-a-class-or-interface-cpp-cli.md)   
 [literal](../windows/literal-cpp-component-extensions.md)