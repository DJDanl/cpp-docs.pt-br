---
title: /CLRHEADER
ms.date: 05/16/2019
f1_keywords:
- /CLRHEADER
helpviewer_keywords:
- -CLRHEADER dumpbin option
- /CLRHEADER dumpbin option
- CLRHEADER dumpbin option
ms.assetid: cf73424f-4541-47e2-b94e-69b95266ef2a
ms.openlocfilehash: 5974606448dad103c8f12a126b8d17c688927c88
ms.sourcegitcommit: a10c9390413978d36b8096b684d5ed4cf1553bc8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/17/2019
ms.locfileid: "65837158"
---
# <a name="clrheader"></a>/CLRHEADER

Exiba informações específicas do CLR.

## <a name="syntax"></a>Sintaxe

> *Arquivo* /CLRHEADER

### <a name="arguments"></a>Arguments

*file*<br/>
Um arquivo de imagem compilado com [/clr](clr-common-language-runtime-compilation.md).

## <a name="remarks"></a>Comentários

**/CLRHEADER** exibe informações sobre os cabeçalhos do .NET usados em qualquer programa gerenciado. A saída mostra a localização e o tamanho em bytes, do cabeçalho do .NET e seções no cabeçalho.

Somente a opção [/HEADERS](headers.md) DUMPBIN está disponível para uso em arquivos produzidos com a opção do compilador [/GL](gl-whole-program-optimization.md).

Quando **/CLRHEADER** é usado em um arquivo que foi compilado com /clr, há uma seção **Cabeçalho clr:** na saída do compartimento de despejo. O valor de **flags** indica qual opção /clr foi usada:

- 0 -- /clr (a imagem pode conter um código nativo).

Verifique também de forma programática se uma imagem foi compilada para o Common Language Runtime.  Para obter mais informações, confira [Como: Determinar se uma imagem é nativa ou CLR](../../dotnet/how-to-determine-if-an-image-is-native-or-clr.md).

As opções do compilador **/clr:pure** e **/clr:safe** foram preteridas no Visual Studio 2015 e estão sem suporte no Visual Studio 2017 e posterior. O código que precisa ser "puro" ou "seguro" deve ser portado para o C#.

## <a name="see-also"></a>Consulte também

- [Opções de DUMPBIN](dumpbin-options.md)
