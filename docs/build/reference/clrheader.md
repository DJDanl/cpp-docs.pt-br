---
title: -CLRHEADER | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /CLRHEADER
dev_langs:
- C++
helpviewer_keywords:
- -CLRHEADER dumpbin option
- /CLRHEADER dumpbin option
- CLRHEADER dumpbin option
ms.assetid: cf73424f-4541-47e2-b94e-69b95266ef2a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f6cda2f03e8a0473d2c45f54c96ca97b043d80d5
ms.sourcegitcommit: a4454b91d556a3dc43d8755cdcdeabcc9285a20e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/01/2018
ms.locfileid: "34704435"
---
# <a name="clrheader"></a>/CLRHEADER

Exibir informações específicas de CLR.

## <a name="syntax"></a>Sintaxe

> / CLRHEADER *arquivo*

### <a name="arguments"></a>Arguments

|||
|-|-|
*file*| Um arquivo de imagem criados com [/clr](../../build/reference/clr-common-language-runtime-compilation.md).

## <a name="remarks"></a>Comentários

**/ CLRHEADER** exibe informações sobre os cabeçalhos de .NET usado em qualquer programa gerenciado. A saída mostra o local e o tamanho, em bytes, do cabeçalho de .NET e seções de cabeçalho.

Somente o [/HEADERS](../../build/reference/headers.md) opção DUMPBIN está disponível para uso em arquivos produzidos com o [/GL](../../build/reference/gl-whole-program-optimization.md) opção de compilador.

Quando **/CLRHEADER** é usado em um arquivo que foi compilado com /clr, haverá uma **cabeçalho do clr:** seção na saída dumpbin. O valor de **sinalizadores** indica qual opção /clr foi usada:

- 0 – /clr (a imagem pode conter código nativo).

Também por meio de programação, você pode verificar se uma imagem foi criada para o common language runtime.  Para obter mais informações, consulte [como: determinar se uma imagem é nativa ou CLR](../../dotnet/how-to-determine-if-an-image-is-native-or-clr.md).

O **/clr: pure** e **/CLR: safe** opções do compilador são substituídas no Visual Studio 2015 e sem suporte no Visual Studio de 2017. Código que deve ser "pura" ou "segurança" deve ser movido para c#.

## <a name="see-also"></a>Consulte também

- [Opções de DUMPBIN](../../build/reference/dumpbin-options.md)
