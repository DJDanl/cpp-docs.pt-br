---
title: Macros de nome de arquivo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- macros, NMAKE
- filename macros in NMAKE
- NMAKE program, filename macros
ms.assetid: 20afd6b3-5b6c-4e33-9d01-309ce98ef9db
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4e49c65a642dcee3e0f04fb5000a390fccae98ad
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
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