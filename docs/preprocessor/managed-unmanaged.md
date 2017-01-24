---
title: "gerenciado, n&#227;o gerenciado | Microsoft Docs"
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
  - "vc-pragma.unmanaged"
  - "managed_CPP"
  - "unmanaged_CPP"
  - "vc-pragma.managed"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "pragma gerenciado"
  - "pragmas, gerenciadas"
  - "pragmas, não gerenciado"
  - "pragma não gerenciado"
ms.assetid: f072ddcc-e1ec-408a-8ce1-326ddb60e4a4
caps.latest.revision: 15
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# gerenciado, n&#227;o gerenciado
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Habilita o controle do nível da função para criar funções como gerenciadas ou o não gerenciadas.  
  
## Sintaxe  
  
```  
  
        #pragma managed  
#pragma unmanaged  
#pragma managed([push,] on | off)  
#pragma managed(pop)  
```  
  
## Comentários  
 A opção do compilador [\/clr](../build/reference/clr-common-language-runtime-compilation.md) fornece controle do nível do módulo para compilar funções ou como gerenciada ou não gerenciada.  
  
 Uma função não gerenciada será criada para a plataforma nativa e a execução dessa parte do programa será passada para a plataforma nativa pelo Common Language Runtime.  
  
 As funções são criadas como gerenciadas por padrão quando **\/clr** é usado.  
  
 Ao aplicar esses pragmas:  
  
-   Adicione o pragma que precede uma função mas não em um corpo da função.  
  
-   Adicione o pragma após `#include` instruções.  Não use esses pragmas antes `#include` instruções.  
  
 O compilador ignora os pragmas `managed` e `unmanaged` se **\/clr** não for usado na compilação.  
  
 Quando uma função de modelo é instanciada, o estado de pragma no momento da definição do modelo determina se ela é gerenciada ou não gerenciada.  
  
 Para obter mais informações, consulte [Inicialização de assemblies mistos](../Topic/Initialization%20of%20Mixed%20Assemblies.md).  
  
## Exemplo  
  
```  
// pragma_directives_managed_unmanaged.cpp  
// compile with: /clr  
#include <stdio.h>  
  
// func1 is managed  
void func1() {  
   System::Console::WriteLine("In managed function.");  
}  
  
// #pragma unmanaged  
// push managed state on to stack and set unmanaged state  
#pragma managed(push, off)  
  
// func2 is unmanaged  
void func2() {  
   printf("In unmanaged function.\n");  
}  
  
// #pragma managed  
#pragma managed(pop)  
  
// main is managed  
int main() {  
   func1();  
   func2();  
}  
```  
  
  **Em uma função gerenciada.  Em uma função não gerenciada.**    
## Consulte também  
 [Diretivas Pragma e a palavra\-chave \_\_Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)