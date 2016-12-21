---
title: "Erro das Ferramentas de Vinculador LNK2031 | Microsoft Docs"
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
  - "LNK2031"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LNK2031"
ms.assetid: 18ed4b6e-3e75-443c-bbd8-2f6030dc89ee
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro das Ferramentas de Vinculador LNK2031
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

pôde gerar p\/invoke para o decorated\_name de function\_declaration”; “ ausentes \(convenção de chamada nos metadados  
  
 Ao tentar importar uma função nativo em uma imagem pura, lembre\-se de que as convenções implícitas de chamada diferem entre compilações nativas e puras.  Para obter mais informações sobre as imagens puras, consulte [Código puro e verificável](../../dotnet/pure-and-verifiable-code-cpp-cli.md).  
  
## Exemplo  
 Este exemplo de código gerenciado um componente COM exportado, nativo, a função cuja convenção de chamada é implicitamente [\_\_cdecl](../Topic/__cdecl.md).  
  
```  
// LNK2031.cpp  
// compile with: /LD  
extern "C" {  
   __declspec(dllexport) int func() { return 3; }  
};  
```  
  
## Exemplo  
 O exemplo a seguir cria um puro cliente que consome a função nativo.  No entanto, a convenção de chamada em **\/clr:pure** é [\_\_clrcall](../../cpp/clrcall.md).  O exemplo a seguir produz LNK2031.  
  
```  
// LNK2031_b.cpp  
// compile with: /clr:pure LNK2031.lib  
// LNK2031 expected  
extern "C" int func();  
  
int main() {  
   return func();  
}  
```  
  
## Exemplo  
 O exemplo a seguir mostra como consumir a função nativo de uma imagem pura.  Observe **\_\_cdecl** explícito que chama o especificador de convenção.  
  
```  
// LNK2031_c.cpp  
// compile with: /clr:pure LNK2031.lib  
extern "C" int __cdecl func();  
  
int main() {  
   return func();  
}  
```