---
title: "Classes de suporte COM do compilador | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "_com_raise_error"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Compilador cl.exe, Suporte COM"
  - "COM, suporte de compilador"
ms.assetid: 6d800d9b-b902-4033-9639-740a30b06f88
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classes de suporte COM do compilador
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 As classes padrão são usadas para dar suporte a alguns dos tipos COM.  As classes são definidas em comdef.h e nos arquivos de cabeçalho gerados a partir da biblioteca de tipos.  
  
|Classe|Finalidade|  
|------------|----------------|  
|[\_bstr\_t](../cpp/bstr-t-class.md)|Encapsula o tipo `BSTR` para fornecer operadores e métodos úteis.|  
|[\_com\_error](../cpp/com-error-class.md)|Define o objeto de erro lançado por [\_com\_raise\_error](../cpp/com-raise-error.md) na maioria das falhas.|  
|[\_com\_ptr\_t](../cpp/com-ptr-t-class.md)|Encapsula ponteiros de interface COM e automatiza as chamadas necessárias para `AddRef`, **Release** e `QueryInterface`.|  
|[\_variant\_t](../cpp/variant-t-class.md)|Encapsula o tipo **VARIANT** para fornecer operadores e métodos úteis.|  
  
## FIM de Específico da Microsoft  
  
## Consulte também  
 [Suporte COM do compilador](../Topic/Compiler%20COM%20Support.md)   
 [Funções globais COM do compilador](../cpp/compiler-com-global-functions.md)   
 [Referência de linguagem C\+\+](../cpp/cpp-language-reference.md)