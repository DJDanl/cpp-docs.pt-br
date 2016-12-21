---
title: "Carregando todas as importa&#231;&#245;es para uma DLL carregada com atraso | Microsoft Docs"
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
  - "Opção de vinculador __HrLoadAllImportsForDll"
ms.assetid: 975fcd97-1a56-4a16-9698-e1a249d2d592
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Carregando todas as importa&#231;&#245;es para uma DLL carregada com atraso
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A função de **\_\_HrLoadAllImportsForDll** , que é definida em delayhlp.cpp, diz o vinculador para carregar todas as importações de uma DLL que é especificado com a opção do vinculador de [\/delayload](../../build/reference/delayload-delay-load-import.md) .  
  
 Carregar todas as importações permite que você coloque o tratamento de erros em um local em seu código e não tem que usar a manipulação de exceção em torno de chamadas às importações reais.  Ele também evita uma situação em que seu aplicativo parcialmente falhe com um processo no resultado de código auxiliar não carrega uma importação.  
  
 A chamada **\_\_HrLoadAllImportsForDll** não altera o comportamento de ganchos e manipulação de erros; consulte [Tratamento de erros e notificação](../../build/reference/error-handling-and-notification.md) para obter mais informações.  
  
 O nome da DLL passado a **\_\_HrLoadAllImportsForDll** é comparado ao nome armazenado dentro da DLL próprio e diferencia maiúsculas e minúsculas.  
  
 O exemplo a seguir mostra como chamar **\_\_HrLoadAllImportsForDll**:  
  
```  
if (FAILED(__HrLoadAllImportsForDll("delay1.dll"))) {  
   printf ( "failed on snap load, exiting\n" );  
   exit(2);  
}  
```  
  
## Consulte também  
 [Suporte de vinculador para DLLs carregadas com atraso](../../build/reference/linker-support-for-delay-loaded-dlls.md)