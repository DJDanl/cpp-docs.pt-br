---
title: "Configurar um Link est&#225;tico para o c&#243;digo de registro (C++) | Microsoft Docs"
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
  - "a vinculação estática para código de registrador da ATL"
  - "Vinculando [C++], código de registrador da ATL"
ms.assetid: 835f5885-87a6-48fa-91e6-60988ee65538
caps.latest.revision: 11
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Configurar um Link est&#225;tico para o c&#243;digo de registro (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Clientes de C\+\+ podem criar um vínculo estático ao código do registrador. Vinculação estática do analisador do registrador adiciona aproximadamente 5 mil para uma compilação de versão.  
  
 A maneira mais simples de configurar a vinculação estática pressupõe que você especificou [DECLARE\_REGISTRY\_RESOURCEID](../Topic/DECLARE_REGISTRY_RESOURCEID.md) na declaração do objeto. \(Esta é a especificação padrão usada pelos ATL\)  
  
### Para criar um vínculo estático usando DECLARE\_REGISTRY\_RESOURCEID  
  
1.  Especifique [\/D](../build/reference/d-preprocessor-definitions.md)`_ATL_STATIC_REGISTRY` em vez de \/D**\_ATL\_DLL**.  
  
2.  Recompile.  
  
## Consulte também  
 [Componente de registro \(Registrar\)](../atl/atl-registry-component-registrar.md)