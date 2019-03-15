---
title: /CLRHEADER
ms.date: 11/04/2016
f1_keywords:
- /CLRHEADER
helpviewer_keywords:
- -CLRHEADER dumpbin option
- /CLRHEADER dumpbin option
- CLRHEADER dumpbin option
ms.assetid: cf73424f-4541-47e2-b94e-69b95266ef2a
ms.openlocfilehash: 6a1240e2d3ad2ac3a454c610a6f49d07e50951e5
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57820696"
---
# <a name="clrheader"></a>/CLRHEADER

Exibir informações específicas de CLR.

## <a name="syntax"></a>Sintaxe

> /CLRHEADER *file*

### <a name="arguments"></a>Arguments

*file*<br/>
Um arquivo de imagem criado com [/clr](clr-common-language-runtime-compilation.md).

## <a name="remarks"></a>Comentários

**/CLRHEADER** exibe informações sobre os cabeçalhos de .NET usados em qualquer programa gerenciado. A saída mostra o local e o tamanho em bytes, do cabeçalho do .NET e seções no cabeçalho.

Somente o [/HEADERS](headers.md) opção DUMPBIN está disponível para uso em arquivos produzidos com o [/GL](gl-whole-program-optimization.md) opção de compilador.

Quando **/clrheader.** é usado em um arquivo que foi compilado com /clr, haverá uma **cabeçalho do clr:** seção na saída (DUMPBIN). O valor de **sinalizadores** indica qual opção /clr foi usada:

- 0 – /clr (a imagem pode conter código nativo).

Você também pode verificar programaticamente se uma imagem foi criada para o common language runtime.  Para obter mais informações, confira [Como: Determinar se uma imagem é nativa ou CLR](../../dotnet/how-to-determine-if-an-image-is-native-or-clr.md).

O **/clr: pure** e **/CLR: safe** opções do compilador são preteridas no Visual Studio 2015 e sem suporte no Visual Studio 2017. Código que deve ser "pura" ou "segura" deve ser movido para C#.

## <a name="see-also"></a>Consulte também

- [Opções de DUMPBIN](dumpbin-options.md)
