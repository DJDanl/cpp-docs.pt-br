---
title: /BIND
ms.date: 11/04/2016
f1_keywords:
- /bind
helpviewer_keywords:
- -BIND editbin option
- entry points, addresses
- BIND editbin option
- entry points
- /BIND editbin option
- import address table
ms.assetid: 3772b330-1868-4c90-857d-c31faa867982
ms.openlocfilehash: eb364f951e97da6a3c4950290669d835e4c24be4
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57418913"
---
# <a name="bind"></a>/BIND

```
/BIND[:PATH=path]
```

## <a name="remarks"></a>Comentários

Essa opção define os endereços dos pontos de entrada na tabela de endereço de importação para um arquivo executável ou DLL. Use esta opção para reduzir o tempo de carregamento de um programa.

Especifique o arquivo executável do programa e o DLLs na *arquivos* argumento na linha de comando EDITBIN. Opcional *caminho* /BIND. argumento especifica o local das DLLs usadas pelos arquivos especificados. Separe vários diretórios com um ponto e vírgula (**;**). Se *caminho* não for especificado, EDITBIN procura os diretórios especificados na variável de ambiente PATH. Se *caminho* for especificado, EDITBIN ignora a variável de caminho.

Por padrão, o carregador do programa define os endereços de pontos de entrada ao carregar um programa. A quantidade de tempo que leva esse processo varia, dependendo do número de DLLs e o número de pontos de entrada referenciados no programa. Se um programa tiver sido modificado com /BIND. e se a base de dados de endereços para o arquivo executável e suas DLLs não entrem em conflito com DLLs que já estão carregadas, o sistema operacional não precisa definir esses endereços. Em uma situação em que os arquivos incorretamente são baseados, o sistema operacional realoca DLLs do programa e recalcula os endereços de ponto de entrada, que adiciona ao tempo de carregamento do programa.

## <a name="see-also"></a>Consulte também

[Opções de EDITBIN](../../build/reference/editbin-options.md)
