---
title: -BIND | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /bind
dev_langs:
- C++
helpviewer_keywords:
- -BIND editbin option
- entry points, addresses
- BIND editbin option
- entry points
- /BIND editbin option
- import address table
ms.assetid: 3772b330-1868-4c90-857d-c31faa867982
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b77c778017dc78235948e8d23db136c1f63ab12d
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32372423"
---
# <a name="bind"></a>/BIND
```  
/BIND[:PATH=path]  
```  
  
## <a name="remarks"></a>Comentários  
 Essa opção define os endereços dos pontos de entrada na tabela de importação de endereço para um arquivo executável ou DLL. Use esta opção para reduzir o tempo de carregamento de um programa.  
  
 Especifique o programa arquivos executáveis e DLLs do *arquivos* argumento na linha de comando EDITBIN. Opcional *caminho* argumento /BIND. Especifica o local das DLLs usadas pelos arquivos especificados. Separe vários diretórios com um ponto e vírgula (**;**). Se *caminho* não for especificado, EDITBIN procura diretórios especificados na variável de ambiente PATH. Se *caminho* for especificado, EDITBIN ignora a variável de caminho.  
  
 Por padrão, o carregador de programa define os endereços de pontos de entrada ao carregar um programa. A quantidade de tempo que esse processo leva varia, dependendo do número de DLLs e o número de pontos de entrada referenciado no programa. Se um programa tiver sido modificado com /BIND. e se a base de dados de endereços para o arquivo executável e suas DLLs não entrem em conflito com DLLs que já estão carregados, o sistema operacional não precisa definir esses endereços. Em uma situação em que os arquivos são baseados incorretamente, o sistema operacional realoca DLLs do programa e recalcula os endereços de ponto de entrada, que adiciona ao tempo de carregamento do programa.  
  
## <a name="see-also"></a>Consulte também  
 [Opções de EDITBIN](../../build/reference/editbin-options.md)