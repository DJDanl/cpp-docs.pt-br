---
title: Ferramentas de vinculador LNK1309 erro | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK1309
dev_langs:
- C++
helpviewer_keywords:
- LNK1309
ms.assetid: 10146071-883f-4849-97d1-c7468f90efbb
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0ffecdc891a9fe0d1c17d6e36c87f5df10b449ec
ms.sourcegitcommit: a4454b91d556a3dc43d8755cdcdeabcc9285a20e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/04/2018
ms.locfileid: "34704092"
---
# <a name="linker-tools-error-lnk1309"></a>Erro das Ferramentas de Vinculador LNK1309

> *type1* módulo detectado; inválido com o comutador /CLRIMAGETYPE:*type2*

## <a name="remarks"></a>Comentários

Um tipo de imagem CLR foi solicitado com **/CLRIMAGETYPE** , mas o vinculador não pôde produzir uma imagem desse tipo porque um ou mais módulos são incompatíveis com o tipo.

Por exemplo, você verá LNK1309 se você especificar **Safe** e passar um módulo compilado com **/clr: pure**.

O **/clr: pure** e **/CLR: safe** bibliotecas de suporte e as opções do compilador são substituídas no Visual Studio 2015 e sem suporte no Visual Studio de 2017.

Você também verá LNK1309 se você tentar compilar um aplicativo parcialmente confiável de puro CLR usando. lib de ptrustu [d]. Para obter informações sobre como criar um aplicativo parcialmente confiável, consulte [como: criar um aplicativo parcialmente confiável pela remoção de dependência na DLL da biblioteca CRT](../../dotnet/create-a-partially-trusted-application.md).

Para obter mais informações, consulte [/clr (Common Language Runtime Compilation)](../../build/reference/clr-common-language-runtime-compilation.md) e [/CLRIMAGETYPE (especificar tipo de imagem CLR)](../../build/reference/clrimagetype-specify-type-of-clr-image.md).