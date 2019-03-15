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
ms.openlocfilehash: 02012e7561fe8462f5f25ae13d961c35561666ec
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57819659"
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

**/ALLOWISOLATION:no** indica que os executáveis sejam carregados como não se houvesse nenhum manifesto e causas [referência de EDITBIN](editbin-reference.md) para definir a `IMAGE_DLLCHARACTERISTICS_NO_ISOLATION` bit no cabeçalho opcional `DllCharacteristics` campo.

Quando o isolamento é desabilitado por um executável, o carregador do Windows não tenta encontrar um manifesto de aplicativo para o processo recém-criado. O novo processo não tem um contexto de ativação padrão, mesmo se houver um manifesto no executável em si ou se não houver um manifesto que tem o nome *nome do executável*. manifest.

## <a name="see-also"></a>Consulte também

[Opções de EDITBIN](editbin-options.md)<br/>
[/ALLOWISOLATION (pesquisa de manifesto)](allowisolation-manifest-lookup.md)<br/>
[Referência de arquivos de manifesto](/windows/desktop/SbsCs/manifest-files-reference)
