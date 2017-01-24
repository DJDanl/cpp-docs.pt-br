---
title: "Macros de nome de arquivo | Microsoft Docs"
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
  - "macros de nome de arquivo em NMAKE"
  - "Macros , NMAKE"
  - "programa NMAKE, macros de nome de arquivo"
ms.assetid: 20afd6b3-5b6c-4e33-9d01-309ce98ef9db
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Macros de nome de arquivo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Macros de nome de arquivo são predefinidos como os nomes dos arquivos especificados na dependência \(especificações não completas de nome de arquivo no disco\).  Esses macros não precisam ser incluídos entre parênteses quando invocados; especificar apenas $ como mostrado.  
  
|Macro|Significado|  
|-----------|-----------------|  
|**$@**|O nome completo de destino \(caminho atual, base, nome de extensão\), como especificado no momento.|  
|**$$@**|O nome completo de destino \(caminho atual, base, nome de extensão\), como especificado no momento.  Válido apenas como um dependente em uma dependência.|  
|**$\***|Nome do caminho atual e da base de destino menos a extensão de arquivo.|  
|**$\*\***|Todos os dependentes de destino atual.|  
|**$?**|Todos os dependentes com um carimbo de data\/hora posterior ao destino atual.|  
|**$\<**|Arquivo dependente com um carimbo de data\/hora posterior ao destino atual.  Válido apenas os comandos em regras de inferência.|  
  
 Para especificar a parte de uma macro predefinido de nome de arquivo, acrescente um modificador macro e incluir a macro alterado entre parênteses.  
  
|Modificador|Resultante parte do nome do arquivo|  
|-----------------|-----------------------------------------|  
|**D**|A unidade mais o diretório|  
|**B**|Baseie o nome|  
|**F**|Baseie o nome mais a extensão|  
|**R**|A unidade mais o diretório e o nome de base|  
  
## Consulte também  
 [Macros NMAKE especiais](../build/special-nmake-macros.md)