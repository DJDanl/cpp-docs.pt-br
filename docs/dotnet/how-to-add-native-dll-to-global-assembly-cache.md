---
title: "Como adicionar DLL nativo ao cache de assembly global | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "get-started-article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "DLLs [C++], nativa"
  - "GAC (cache de assembly global), carregando DLLs nativas"
  - "DLLs nativas [C++]"
ms.assetid: 25e8d78a-b197-4269-b4e9-237a544ab3c8
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como adicionar DLL nativo ao cache de assembly global
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode colocar um DLL nativa \(não por\) em cachê de assembly global.  
  
## Exemplo  
 **\/ASSEMBLYLINKRESOURCE** permite digitar um DLL nativa em um assembly.  
  
 Para obter mais informações, consulte [\/ASSEMBLYLINKRESOURCE \(Link para recurso do .NET Framework\)](../build/reference/assemblylinkresource-link-to-dotnet-framework-resource.md).  
  
```  
/ASSEMBLYLINKRESOURCE:MyComponent.dll  
```  
  
## Consulte também  
 [Usando interop C\+\+ \(PInvoke implícito\)](../dotnet/using-cpp-interop-implicit-pinvoke.md)