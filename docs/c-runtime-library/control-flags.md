---
title: Sinalizadores de controle
ms.date: 11/04/2016
f1_keywords:
- c.flags
helpviewer_keywords:
- flags, control
- heap allocation, control flags
- debug heap, control flags
ms.assetid: 8dbd24a5-0633-42d1-9771-776db338465f
ms.openlocfilehash: 7ac5f239ea4d242618fb23ba617a3a6539492053
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57750108"
---
# <a name="control-flags"></a>Sinalizadores de controle

A versão de depuração da biblioteca em tempo de execução do Microsoft C usa os seguintes sinalizadores para controlar a alocação de heap e o processo de relatório. Para obter mais informações, consulte [Técnicas de Depuração CRT](/visualstudio/debugger/crt-debugging-techniques).

|Sinalizador|Descrição|
|----------|-----------------|
|[_CRTDBG_MAP_ALLOC](../c-runtime-library/crtdbg-map-alloc.md)|Mapeia as funções de heap de base para seus equivalentes da versão de depuração|
|[_DEBUG](../c-runtime-library/debug.md)|Permite o uso das versões de depuração das funções de tempo de execução|
|[_crtDbgFlag](../c-runtime-library/crtdbgflag.md)|Controla como o gerenciador de heap de depuração acompanha as alocações|

Esses sinalizadores podem ser definidos com uma opção de linha de comando /D ou com uma diretiva `#define`. Quando o sinalizador é definido com `#define`, a diretiva deve aparecer antes que o arquivo de cabeçalho incluir a instrução para as declarações de rotina.

## <a name="see-also"></a>Consulte também

[Variáveis globais e tipos padrão](../c-runtime-library/global-variables-and-standard-types.md)
