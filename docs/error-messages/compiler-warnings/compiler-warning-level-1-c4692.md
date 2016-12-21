---
title: "Compilador C4692 de aviso (n&#237;vel 1) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "C4692"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4692"
ms.assetid: f6fb3acc-8228-491a-9c30-ce302d8a9c75
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compilador C4692 de aviso (n&#237;vel 1)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

função “”: a assinatura do membro não privado contém o tipo nativo privadas “native\_type” do assembly  
  
 Um tipo que é visível fora do assembly contém uma função de membro cuja assinatura contém um tipo nativo que não é visível fora do assembly.  Consequentemente, a função de membro não deve ser chamada se o tipo de conteúdo é instanciado fora do assembly.  
  
 Para obter mais informações, consulte [Visibilidade do tipo](../../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Type_visibility).  
  
 Esse aviso é desativada por padrão.  Para obter mais informações, consulte [Avisos de compilador desativados por padrão](../Topic/Compiler%20Warnings%20That%20Are%20Off%20by%20Default.md).  
  
## Exemplo  
 O exemplo a seguir produz C4692.  
  
```  
// C4692.cpp  
// compile with: /W1 /c /clr  
#pragma warning(default:4692)  
class Private_Native_Class {};  
public class Public_Native_Class {};  
public ref class Public_Ref_Class {  
public:  
   void Test(Private_Native_Class *) {}   // C4692  
   void Test2(Public_Native_Class *) {}   // OK  
};  
```