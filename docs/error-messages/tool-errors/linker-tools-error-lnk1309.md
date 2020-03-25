---
title: Erro das Ferramentas de Vinculador LNK1309
ms.date: 11/04/2016
f1_keywords:
- LNK1309
helpviewer_keywords:
- LNK1309
ms.assetid: 10146071-883f-4849-97d1-c7468f90efbb
ms.openlocfilehash: 88b05512fd45adb6dc96a6c130ceccb74f3ab14e
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80194896"
---
# <a name="linker-tools-error-lnk1309"></a>Erro das Ferramentas de Vinculador LNK1309

> módulo *type1* detectado; inválido com o switch/CLRIMAGETYPE:*type2*

## <a name="remarks"></a>Comentários

Um tipo de imagem CLR foi solicitado com **/CLRIMAGETYPE** , mas o vinculador não pôde produzir uma imagem desse tipo porque um ou mais módulos eram incompatíveis com esse tipo.

Por exemplo, você verá LNK1309 se especificar **/CLRIMAGETYPE: safe** e passar um módulo criado com **/CLR: Pure**.

As opções do compilador **/CLR: Pure** e **/CLR: safe** e as bibliotecas de suporte são preteridas no Visual Studio 2015 e sem suporte no Visual Studio 2017.

Você também verá LNK1309 se tentar criar um aplicativo CLR puro parcialmente confiável usando ptrustu [d]. lib. Para obter informações sobre como criar um aplicativo parcialmente confiável, consulte [como: criar um aplicativo parcialmente confiável removendo a dependência na DLL da biblioteca do CRT](../../dotnet/create-a-partially-trusted-application.md).

Para obter mais informações, consulte [/CLR (compilação em tempo de execução de linguagem comum)](../../build/reference/clr-common-language-runtime-compilation.md) e [/CLRIMAGETYPE (especifique o tipo de imagem CLR)](../../build/reference/clrimagetype-specify-type-of-clr-image.md).
