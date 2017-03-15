---
title: "__debugbreak | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "__debugbreak_cpp"
  - "__debugbreak"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "__debugbreak intrínseco"
  - "pontos de interrupção, __debugbreak intrínseco"
ms.assetid: 1d1e1c0c-891a-4613-ae4b-d790094ba830
caps.latest.revision: 16
caps.handback.revision: 16
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# __debugbreak
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Cria um ponto de interrupção no código, onde o sistema solicitará que o usuário execute o depurador.  
  
## Sintaxe  
  
```  
void __debugbreak();  
```  
  
## Requisitos  
  
|Intrínseco|Arquitetura|Cabeçalho|  
|----------------|-----------------|---------------|  
|`__debugbreak`|x86, ARM, [!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|\<intrin.h\>|  
  
## Comentários  
 A função intrínseca do compilador `__debugbreak`, similar à função [DebugBreak](http://msdn.microsoft.com/library/windows/desktop/ms679297.aspx), é um meio usado pelo Win32 para criar um ponto de interrupção.  
  
> [!NOTE]
>  Quando você usa **\/clr** para compilar, uma função contendo `__debugbreak` é compilada no MSIL.  `asm int 3` faz com que a função seja compilada como nativa.  Para obter mais informações, consulte [\_\_asm](../assembler/inline/asm.md).  
  
 Por exemplo:  
  
```  
main() {  
   __debugbreak();  
}  
```  
  
 é similar a:  
  
```  
main() {  
   __asm {  
      int 3  
   }  
}  
```  
  
 em computadores x86.  
  
 Essa rotina só está disponível como função intrínseca.  
  
## FIM de Específico da Microsoft  
  
## Consulte também  
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)   
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)