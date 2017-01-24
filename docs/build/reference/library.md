---
title: "LIBRARY | Microsoft Docs"
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
  - "LIBRARY"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "instrução de arquivo .def LIBRARY"
ms.assetid: 1d7ccc92-e088-4ef7-9ef0-25c3862cc051
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# LIBRARY
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Informa o LINK para criar uma DLL.  Ao mesmo tempo, o LINK cria uma biblioteca de importação, a menos que um arquivo de .exp é usado na compilação.  
  
```  
LIBRARY [library][BASE=address]  
```  
  
## Comentários  
 O argumento *da biblioteca* especifica o nome da DLL.  Você também pode usar a opção do vinculador de [\/OUT](../../build/reference/out-output-file-name.md) especificar o nome da saída da DLL.  
  
 O argumento BASE\=*address* define o endereço base que o sistema operacional usa para carregar a DLL.  Este argumento substitui o local padrão da DLL de 0x10000000.  Consulte a descrição da opção de [\/BASE](../../build/reference/base-base-address.md) para obter detalhes sobre endereços de base.  
  
 Lembre\-se de usar a opção do vinculador de [\/DLL](../../build/reference/dll-build-a-dll.md) quando você cria uma DLL.  
  
## Consulte também  
 [Regras para instruções de definição do módulo](../../build/reference/rules-for-module-definition-statements.md)