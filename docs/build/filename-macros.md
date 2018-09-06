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
ms.openlocfilehash: bc231dfb156460a2a0cc383b6d038a98c6e2015b
ms.sourcegitcommit: d10a2382832373b900b1780e1190ab104175397f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/06/2018
ms.locfileid: "43894402"
---
# <a name="filename-macros"></a>Macros de nome de arquivo

Macros de nome de arquivo são predefinidas, como nomes de arquivo especificado na dependência (nome de arquivo completo não especificações no disco). Essas macros não precisa ser colocada entre parênteses quando invocado; Especifique apenas um $ conforme mostrado.

|Macro|Significado|
|-----------|-------------|
|**$\@**|Nome completo do destino atual (caminho, nome de base, extensão), como no momento especificado.|
|**$$\@**|Nome completo do destino atual (caminho, nome de base, extensão), como no momento especificado. Válido apenas como um dependente em uma dependência.|
|**$&#42;**|Do destino atual caminho e o nome base menos a extensão de arquivo.|
|**$&#42;&#42;**|Todos os dependentes do destino atual.|
|**$?**|Todos os dependentes com um carimbo de hora posterior que o destino atual.|
|**$<**|Arquivo dependente com um carimbo de hora posterior que o destino atual. Válido somente em comandos nas regras de inferência de tipos.|

Para especificar a parte de uma macro predefinida de nome de arquivo, acrescentar um modificador de macro e coloque a macro modificada entre parênteses.

|Modificador|Parte do nome do arquivo resultante|
|--------------|-----------------------------|
|**D**|Unidade e diretório|
|**B**|Nome de base|
|**F**|Nome de base e extensão|
|**R**|Unidade e diretório e nome de base|

## <a name="see-also"></a>Consulte também

[Macros NMAKE especiais](../build/special-nmake-macros.md)
