---
title: /MANIFESTINPUT (especificar entrada de manifesto)
ms.date: 07/24/2019
ms.assetid: a0b0c21e-1f9b-4d8c-bb3f-178f57fa7f1b
ms.openlocfilehash: d7c8351c915f5666ada9939df686c81c86ab89ba
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81337500"
---
# <a name="manifestinput-specify-manifest-input"></a>/MANIFESTINPUT (especificar entrada de manifesto)

Especifica um arquivo de entrada manifesto para incluir no manifesto incorporado na imagem.

## <a name="syntax"></a>Sintaxe

```
/MANIFESTINPUT:filename
```

### <a name="parameters"></a>Parâmetros

*Filename*<br/>
O arquivo manifesto para incluir no manifesto incorporado.

## <a name="remarks"></a>Comentários

A opção **/MANIFESTINPUT** especifica o caminho de um arquivo de entrada para usar para criar o manifesto incorporado em uma imagem executável. Se você tiver vários arquivos de entrada manifesto, use o switch várias vezes — uma vez para cada arquivo de entrada. Os arquivos de entrada manifesto são mesclados para criar o manifesto incorporado. Esta opção requer a opção **/MANIFEST:EMBED.**

Esta opção não pode ser definida diretamente no Visual Studio. Em vez disso, use a propriedade **Arquivos manifestos adicionais** do projeto para especificar arquivos manifestos adicionais para incluir. Para obter mais informações, consulte [Manifest Tool Property Pages](manifest-tool-property-pages.md).

## <a name="see-also"></a>Confira também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções de vinculador MSVC](linker-options.md)
