---
title: /RANGE
ms.date: 11/04/2016
f1_keywords:
- /RANGE
helpviewer_keywords:
- /RANGE dumpbin option
- -RANGE dumpbin option
ms.assetid: 7eeba266-32be-49cc-a350-96bdf541f98a
ms.openlocfilehash: 011a8f9b2c8d0722e9aff98d52bb47dc549cc769
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57421630"
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
