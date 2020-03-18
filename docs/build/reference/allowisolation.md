---
title: /ALLOWISOLATION
ms.date: 11/04/2016
f1_keywords:
- /ALLOWISOLATION_EDITBIN
helpviewer_keywords:
- -ALLOWISOLATION editbin option
- /ALLOWISOLATION editbin option
- ALLOWISOLATION editbin option
ms.assetid: 91430344-f64f-491a-a5a5-7ea3b21cbe68
ms.openlocfilehash: 3dae8ee83e25492fab0ba2c6a55681728d5f3453
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79440376"
---
# <a name="allowisolation"></a>/ALLOWISOLATION

Especifica o comportamento da pesquisa de manifesto.

## <a name="syntax"></a>Sintaxe

```

/ALLOWISOLATION[:NO]
```

## <a name="remarks"></a>Comentários

**/ALLOWISOLATION** faz com que o sistema operacional faça pesquisas e cargas de manifesto.

**/ALLOWISOLATION** é o padrão.

**/ALLOWISOLATION: não** indica que os executáveis são carregados como se não houvesse nenhum manifesto e faz com que a [Referência EDITBIN](editbin-reference.md) defina o `IMAGE_DLLCHARACTERISTICS_NO_ISOLATION` bit no campo `DllCharacteristics` do cabeçalho opcional.

Quando o isolamento está desabilitado para um executável, o carregador do Windows não tenta encontrar um manifesto do aplicativo para o processo recém-criado. O novo processo não tem um contexto de ativação padrão, mesmo se houver um manifesto no próprio executável ou se houver um manifesto com o nome *executável-Name*. exe. manifest.

## <a name="see-also"></a>Consulte também

[Opções de EDITBIN](editbin-options.md)<br/>
[/ALLOWISOLATION (pesquisa de manifesto)](allowisolation-manifest-lookup.md)<br/>
[Referência de arquivos de manifesto](/windows/win32/SbsCs/manifest-files-reference)
