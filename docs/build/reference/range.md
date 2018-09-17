---
title: -O INTERVALO | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /RANGE
dev_langs:
- C++
helpviewer_keywords:
- /RANGE dumpbin option
- -RANGE dumpbin option
ms.assetid: 7eeba266-32be-49cc-a350-96bdf541f98a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 47e7525b8c1872616182141d624bff8f94571952
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45712186"
---
# <a name="range"></a>/RANGE

Modifica a saída de quando usado com outras opções de dumpbin, como /RAWDATA ou /DISASM (DUMPBIN).

## <a name="syntax"></a>Sintaxe

```
/RANGE:vaMin[,vaMax]
```

## <a name="parameters"></a>Parâmetros

*vaMin*<br/>
O endereço virtual no qual você deseja que a operação de dumpbin para começar.

*vaMax*<br/>
(Opcional) O endereço virtual no qual você deseja que a operação de dumpbin para terminar. Se não for especificado, dumpbin irá para o final do arquivo.

## <a name="remarks"></a>Comentários

Para ver os endereços virtuais para uma imagem, use o arquivo de mapa da imagem (RVA + Base), o **/DISASM** ou **/HEADERS** opção de dumpbin ou a janela de desmontagem no depurador do Visual Studio.

## <a name="example"></a>Exemplo

Neste exemplo, **/faixa** é usado para modificar a exibição da **/disasm** opção. Neste exemplo, o valor inicial é expresso como um número decimal e o valor final é especificado como um número hexadecimal.

```
dumpbin /disasm /range:4219334,0x004061CD t.exe
```

## <a name="see-also"></a>Consulte também

[Opções de DUMPBIN](../../build/reference/dumpbin-options.md)