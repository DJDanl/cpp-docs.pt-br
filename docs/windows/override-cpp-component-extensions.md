---
title: "override  (C++ Component Extensions) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "overriding, override keyword [C++]"
  - "override keyword [C++]"
ms.assetid: 34d19257-1686-4fcd-96f5-af07c70ba914
caps.latest.revision: 19
caps.handback.revision: 19
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# override  (C++ Component Extensions)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A palavra\-chave contextuais de `override` indica que um membro de um tipo substitui uma classe base ou um membro de base da interface.  
  
## Comentários  
 A palavra\-chave `override` é válida durante a compilação de destinos nativos \(opção de compilador padrão\), destinos de Tempo de Execução do Windows \(opção de compilador **\/ZW**\) ou destinos de common language runtime \(opção de compilador **\/clr**\).  
  
 Para obter mais informações sobre especificadores de substituição, consulte [substituir especificador](../cpp/override-specifier.md) e [Especificadores de substituição e compilações nativas](../dotnet/how-to-declare-override-specifiers-in-native-compilations-cpp-cli.md).  
  
 Para obter mais informações sobre palavras\-chave sensíveis ao contexto, consulte [Palavras\-chave Contextuais](../windows/context-sensitive-keywords-cpp-component-extensions.md).  
  
## Exemplos  
 **Exemplo**  
  
 O exemplo de código a seguir mostra que `override` também pode ser usado em compilações nativas.  
  
```cpp#  
// override_keyword_1.cpp  
// compile with: /c  
struct I1 {  
   virtual void f();  
};  
  
struct X : public I1 {  
   virtual void f() override {}  
};  
```  
  
 **Exemplo**  
  
 O exemplo de código a seguir mostra que `override` também pode ser usado em compilações do Tempo de Execução do Windows.  
  
```cpp#  
// override_keyword_2.cpp  
// compile with: /ZW /c  
ref struct I1 {  
   virtual void f();  
};  
  
ref struct X : public I1 {  
   virtual void f() override {}  
};  
```  
  
 **Requisitos**  
  
 Opção do compilador: **\/ZW**  
  
 **Exemplo**  
  
 O exemplo de código a seguir mostra que `override` também pode ser usado em compilações de common language runtime.  
  
```cpp#  
// override_keyword_3.cpp  
// compile with: /clr /c  
ref struct I1 {  
   virtual void f();  
};  
  
ref struct X : public I1 {  
   virtual void f() override {}  
};  
```  
  
 **Requisitos**  
  
 Opção do compilador: **\/clr**  
  
## Consulte também  
 [substituir especificador](../cpp/override-specifier.md)   
 [Especificadores de Substituição](../windows/override-specifiers-cpp-component-extensions.md)