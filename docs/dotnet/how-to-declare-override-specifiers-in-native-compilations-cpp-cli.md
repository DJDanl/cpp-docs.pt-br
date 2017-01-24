---
title: "Como declarar especificadores de substitui&#231;&#227;o em compila&#231;&#245;es nativas (C++/CLI) | Microsoft Docs"
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
  - "Substituir especificadores em compilação nativa, substituindo"
ms.assetid: d0551836-9ac7-41eb-a6e9-a4b3ef60767d
caps.latest.revision: 13
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como declarar especificadores de substitui&#231;&#227;o em compila&#231;&#245;es nativas (C++/CLI)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

[selado](../windows/sealed-cpp-component-extensions.md), [sumário](../windows/abstract-cpp-component-extensions.md), e [substituição](../windows/override-cpp-component-extensions.md) estão disponíveis nas compilações que não usam **\/ZW** ou [\/clr](../build/reference/clr-common-language-runtime-compilation.md).  
  
> [!NOTE]
>  O idioma padrão ISO C\+\+11 tem o identificador de [substituição](../cpp/override-specifier.md) e o identificador de [final](../cpp/final-specifier.md) , e ambos têm suporte em uso `final` do Visual Studio em vez de `sealed` no código que parece ser compilado como o nativo somente.  
  
## Exemplo  
  
### Descrição  
 O exemplo a seguir mostra que `sealed` é válido em compilações nativos.  
  
### Código  
  
```  
// sealed_native_keyword.cpp  
#include <stdio.h>  
__interface I1 {  
   virtual void f();  
   virtual void g();  
};  
  
class X : public I1 {  
public:  
   virtual void g() sealed {}  
};  
  
class Y : public X {  
public:  
  
   // the following override generates a compiler error  
   virtual void g() {}   // C3248 X::g is sealed!  
};  
```  
  
## Exemplo  
  
### Descrição  
 O exemplo seguinte mostra que `override` é válido em compilações nativos.  
  
### Código  
  
```  
// override_native_keyword.cpp  
#include <stdio.h>  
__interface I1 {  
   virtual void f();  
};  
  
class X : public I1 {  
public:  
   virtual void f() override {}   // OK  
   virtual void g() override {}   // C3668 I1::g does not exist  
};  
```  
  
## Exemplo  
  
### Descrição  
 Este exemplo mostra que `abstract` é válido em compilações nativos.  
  
### Código  
  
```  
// abstract_native_keyword.cpp  
class X abstract {};  
  
int main() {  
   X * MyX = new X;   // C3622 cannot instantiate abstract class  
}  
```  
  
## Consulte também  
 [Especificadores de Substituição](../windows/override-specifiers-cpp-component-extensions.md)