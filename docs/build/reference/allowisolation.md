---
title: -ALLOWISOLATION | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /ALLOWISOLATION
dev_langs:
- C++
helpviewer_keywords:
- -ALLOWISOLATION editbin option
- /ALLOWISOLATION editbin option
- ALLOWISOLATION editbin option
ms.assetid: 91430344-f64f-491a-a5a5-7ea3b21cbe68
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 07414c86663ea6143a471691b01e584cdc033258
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46392821"
---
# <a name="allowisolation"></a>/ALLOWISOLATION

Especifica o comportamento da pesquisa de manifesto.

## <a name="syntax"></a>Sintaxe

```

/ALLOWISOLATION[:NO]
```

## <a name="remarks"></a>Comentários

**/ALLOWISOLATION** faz com que o sistema operacional de manifesto cargas e pesquisas.

**/ALLOWISOLATION** é o padrão.

**/ALLOWISOLATION:no** indica que os executáveis sejam carregados como não se houvesse nenhum manifesto e causas [referência de EDITBIN](../../build/reference/editbin-reference.md) para definir a `IMAGE_DLLCHARACTERISTICS_NO_ISOLATION` bit no cabeçalho opcional `DllCharacteristics` campo.

Quando o isolamento é desabilitado por um executável, o carregador do Windows não tenta encontrar um manifesto de aplicativo para o processo recém-criado. O novo processo não tem um contexto de ativação padrão, mesmo se houver um manifesto no executável em si ou se não houver um manifesto que tem o nome *nome do executável*. manifest.

## <a name="see-also"></a>Consulte também

[Opções de EDITBIN](../../build/reference/editbin-options.md)<br/>
[/ALLOWISOLATION (pesquisa de manifesto)](../../build/reference/allowisolation-manifest-lookup.md)<br/>
[Referência de arquivos de manifesto](/windows/desktop/SbsCs/manifest-files-reference)