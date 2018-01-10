---
title: Sinalizadores de controle | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: c.flags
dev_langs: C++
helpviewer_keywords:
- flags, control
- heap allocation, control flags
- debug heap, control flags
ms.assetid: 8dbd24a5-0633-42d1-9771-776db338465f
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 71e0b1d01e291a1fa48740ccb6389a1b064433b8
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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