---
title: Macros de nome de arquivo | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- macros, NMAKE
- filename macros in NMAKE
- NMAKE program, filename macros
ms.assetid: 20afd6b3-5b6c-4e33-9d01-309ce98ef9db
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: b2073e4fcb365b3beb10d4040c0f54d9f61a0431
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="filename-macros"></a>Macros de nome de arquivo
Macros de nome de arquivo são predefinidas como nomes de arquivo especificado na dependência (nome de arquivo completo não especificações no disco). Essas macros não precisam ser colocados entre parênteses quando invocado; Especifique apenas um $ conforme mostrado.  
  
|Macro|Significado|  
|-----------|-------------|  
|**$@**|Nome completo do destino atual (caminho, nome de base, extensão), como no momento especificado.|  
|**$$@**|Nome completo do destino atual (caminho, nome de base, extensão), como no momento especificado. Válido apenas como um dependente em uma dependência.|  
|**$\***|Nome do destino atual de base e o caminho menos extensão de arquivo.|  
|**$\*\***|Todos os dependentes do destino atual.|  
|**$?**|Todos os dependentes com um carimbo de hora posterior que o destino atual.|  
|**$<**|Arquivo dependente com um carimbo de hora posterior que o destino atual. Válido somente em comandos em regras de inferência.|  
  
 Para especificar a parte de uma macro de nome de arquivo predefinido, acrescente um modificador de macro e colocar a macro modificada entre parênteses.  
  
|Modificador|Parte do nome de arquivo resultante|  
|--------------|-----------------------------|  
|**D**|Unidade e diretório|  
|**B**|Nome de base|  
|**F**|Nome de base e de extensão|  
|**R**|Unidade mais o diretório mais o nome de base|  
  
## <a name="see-also"></a>Consulte também  
 [Macros NMAKE especiais](../build/special-nmake-macros.md)