---
title: Sinalizadores de controle | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: conceptual
f1_keywords:
- c.flags
dev_langs:
- C++
helpviewer_keywords:
- flags, control
- heap allocation, control flags
- debug heap, control flags
ms.assetid: 8dbd24a5-0633-42d1-9771-776db338465f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: bfd37a3d76a39748efc0352df829a7b5c57146a9
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32388273"
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