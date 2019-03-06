---
title: /ALLOWISOLATION
ms.date: 11/04/2016
f1_keywords:
- /ALLOWISOLATION
helpviewer_keywords:
- -ALLOWISOLATION editbin option
- /ALLOWISOLATION editbin option
- ALLOWISOLATION editbin option
ms.assetid: 91430344-f64f-491a-a5a5-7ea3b21cbe68
ms.openlocfilehash: ac9d1f067259b092a261702b51f2355d4f908469
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57417431"
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
