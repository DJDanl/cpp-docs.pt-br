---
title: Erro das Ferramentas de Vinculador LNK1309
ms.date: 11/04/2016
f1_keywords:
- LNK1309
helpviewer_keywords:
- LNK1309
ms.assetid: 10146071-883f-4849-97d1-c7468f90efbb
ms.openlocfilehash: ea675ca835dfc3fe4881e5fabbea746a4442b10a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50498973"
---
# <a name="linker-tools-error-lnk1309"></a>Erro das Ferramentas de Vinculador LNK1309

> *type1* módulo detectado; inválido com alternar /CLRIMAGETYPE:*type2*

## <a name="remarks"></a>Comentários

Um tipo de imagem CLR foi solicitado com **/CLRIMAGETYPE** , mas o vinculador não pôde produzir uma imagem desse tipo porque um ou mais módulos eram incompatíveis com esse tipo.

Por exemplo, você verá das LNK1309 se você especificar **Safe** e você passar um módulo compilado com **/clr: pure**.

O **/clr: pure** e **/CLR: safe** bibliotecas de suporte e as opções do compilador são preteridas no Visual Studio 2015 e sem suporte no Visual Studio 2017.

Você também verá das LNK1309 se você tentar compilar um aplicativo parcialmente confiável de puro CLR usando. lib de ptrustu [d]. Para obter informações sobre como criar um aplicativo parcialmente confiável, consulte [como: criar um aplicativo parcialmente confiável pela remoção de dependência em que a DLL da biblioteca CRT](../../dotnet/create-a-partially-trusted-application.md).

Para obter mais informações, consulte [/clr (compilação de tempo de execução de linguagem comum)](../../build/reference/clr-common-language-runtime-compilation.md) e [/CLRIMAGETYPE (especificar tipo de imagem CLR)](../../build/reference/clrimagetype-specify-type-of-clr-image.md).