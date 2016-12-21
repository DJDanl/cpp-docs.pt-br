---
title: "Estrutura HSE_VERSION_INFO | Microsoft Docs"
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
  - "HSE_VERSION_INFO"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura HSE_VERSION_INFO"
ms.assetid: 4837312d-68c8-4d05-9afa-1934d7d49b20
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura HSE_VERSION_INFO
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa estrutura é apontada pelo parâmetro de `pVer` na função de membro de `CHttpServer::GetExtensionVersion` .  Fornece o número da versão do ISA e uma descrição de texto do ISA.  
  
## Sintaxe  
  
```  
  
      typedef struct _HSE_VERSION_INFO {  
   DWORD dwExtensionVersion;  
   CHAR lpszExtensionDesc[HSE_MAX_EXT_DLL_NAME_LEN];  
} HSE_VERSION_INFO, *LPHSE_VERSION_INFO;  
```  
  
#### Parâmetros  
 *dwExtensionVersion*  
 O número da versão do ISA.  
  
 *lpszExtensionDesc*  
 A descrição de texto do ISA.  A implementação padrão fornece o texto de espaço reservado; substituição `CHttpServer::GetExtensionVersion` para fornecer sua própria descrição.  
  
## Requisitos  
 **Header:** httpext.h  
  
## Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)