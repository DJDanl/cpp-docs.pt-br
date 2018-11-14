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
ms.openlocfilehash: e35cf79cdaa10c9632e1c588e2b49f45cfbef283
ms.sourcegitcommit: 1819bd2ff79fba7ec172504b9a34455c70c73f10
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/09/2018
ms.locfileid: "51330847"
---
# <a name="clrheader"></a>/CLRHEADER

Exibir informações específicas de CLR.

## <a name="syntax"></a>Sintaxe

> /CLRHEADER *arquivo*

### <a name="arguments"></a>Arguments

*file*<br/>
Um arquivo de imagem criado com [/clr](../../build/reference/clr-common-language-runtime-compilation.md).

## <a name="remarks"></a>Comentários

**/CLRHEADER** exibe informações sobre os cabeçalhos de .NET usados em qualquer programa gerenciado. A saída mostra o local e o tamanho em bytes, do cabeçalho do .NET e seções no cabeçalho.

Somente o [/HEADERS](../../build/reference/headers.md) opção DUMPBIN está disponível para uso em arquivos produzidos com o [/GL](../../build/reference/gl-whole-program-optimization.md) opção de compilador.

Quando **/clrheader.** é usado em um arquivo que foi compilado com /clr, haverá uma **cabeçalho do clr:** seção na saída (DUMPBIN). O valor de **sinalizadores** indica qual opção /clr foi usada:

- 0 – /clr (a imagem pode conter código nativo).

Você também pode verificar programaticamente se uma imagem foi criada para o common language runtime.  Para obter mais informações, consulte [como: determinar se uma imagem é nativa ou CLR](../../dotnet/how-to-determine-if-an-image-is-native-or-clr.md).

O **/clr: pure** e **/CLR: safe** opções do compilador são preteridas no Visual Studio 2015 e sem suporte no Visual Studio 2017. Código que deve ser "pura" ou "segura" deve ser movido para C#.

## <a name="see-also"></a>Consulte também

- [Opções de DUMPBIN](../../build/reference/dumpbin-options.md)
