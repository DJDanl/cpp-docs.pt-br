---
title: "Defini&#231;&#245;es e declara&#231;&#245;es (C++) | Microsoft Docs"
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
ms.assetid: 56b809c0-e602-4f18-9ca5-cd7a8fbaaf30
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Defini&#231;&#245;es e declara&#231;&#245;es (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Específico da Microsoft  
 A interface da DLL refere\-se a todos os itens \(funções e dados\) que sabidamente são exportados por algum programa no sistema; ou seja, todos os itens que são declarados como **dllimport** ou `dllexport`.  Todas as declarações incluídas na interface da DLL devem especificar o atributo **dllimport** ou `dllexport`.  No entanto, a definição deve especificar apenas o atributo `dllexport`.  Por exemplo, a definição de função a seguir gera um erro de compilador:  
  
```  
__declspec( dllimport ) int func() {   // Error; dllimport  
                                    // prohibited on definition.  
   return 1;  
}  
```  
  
 Este código também gera um erro:  
  
```  
#define DllImport   __declspec( dllimport )  
  
__declspec( dllimport ) int i = 10;  // Error; this is a  
                                     // definition.  
```  
  
 No entanto, esta é uma sintaxe correta:  
  
```  
__declspec( dllexport ) int i = 10;     // Okay--export definition  
```  
  
 O uso de `dllexport` implica uma definição, enquanto **dllimport** implica uma declaração.  Você deve usar a palavra\-chave `extern` com `dllexport` para forçar uma declaração; caso contrário, uma definição é implícita.  Assim, os seguintes exemplos estão corretos:  
  
```  
#define DllImport   __declspec( dllimport )  
#define DllExport   __declspec( dllexport )  
  
extern DllImport int k; // These are both correct and imply a  
DllImport int j;        // declaration.  
```  
  
 Os exemplos a seguir esclarecem o que foi dito acima:  
  
```  
static __declspec( dllimport ) int l; // Error; not declared extern.  
  
void func() {  
    static __declspec( dllimport ) int s;  // Error; not declared  
                                           // extern.  
    __declspec( dllimport ) int m;         // Okay; this is a   
                                           // declaration.  
    __declspec( dllexport ) int n;         // Error; implies external  
                                           // definition in local scope.  
    extern __declspec( dllimport ) int i;  // Okay; this is a  
                                           // declaration.  
    extern __declspec( dllexport ) int k;  // Okay; extern implies  
                                           // declaration.  
    __declspec( dllexport ) int x = 5;     // Error; implies external  
                                           // definition in local scope.  
}  
```  
  
## FIM de Específico da Microsoft  
  
## Consulte também  
 [dllexport, dllimport](../cpp/dllexport-dllimport.md)