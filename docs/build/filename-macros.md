---
title: Macros de nome de arquivo
ms.date: 11/04/2016
helpviewer_keywords:
- macros, NMAKE
- filename macros in NMAKE
- NMAKE program, filename macros
ms.assetid: 20afd6b3-5b6c-4e33-9d01-309ce98ef9db
ms.openlocfilehash: 2e7552d77d753d4e93734f2fc9a35b3b68d8d55c
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50457688"
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
