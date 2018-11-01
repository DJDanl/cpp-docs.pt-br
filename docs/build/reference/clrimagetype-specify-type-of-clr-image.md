---
title: /CLRIMAGETYPE (especificar tipo de imagem CLR)
ms.date: 11/04/2016
f1_keywords:
- /CLRIMAGETYPE
- VC.Project.VCLinkerTool.CLRImageType
helpviewer_keywords:
- /CLRIMAGETYPE linker option
- -CLRIMAGETYPE linker option
ms.assetid: 04c60ee6-9dd7-4391-bc03-6926ad0fa116
ms.openlocfilehash: c4cdb9a9ac3376762d6aa40fd4c13abbdc7b5487
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50461627"
---
# <a name="clrimagetype-specify-type-of-clr-image"></a>/CLRIMAGETYPE (especificar tipo de imagem CLR)

Defina o tipo de imagem CLR na imagem vinculada.

## <a name="syntax"></a>Sintaxe

> **/CLRIMAGETYPE:**{**IJW**|**PURO**|**SEGURO**|**SAFE32BITPREFERRED**}

## <a name="remarks"></a>Comentários

O vinculador aceita objetos nativos e também objetos MSIL que são compilados usando [/clr](../../build/reference/clr-common-language-runtime-compilation.md). O **/clr: pure** e **/CLR: safe** opções de compilador foram preteridas no Visual Studio 2015 e não têm suporte no Visual Studio 2017. Quando os objetos mistos na mesma compilação são passados, a capacidade de verificação do arquivo de saída resultante é, por padrão, igual ao nível mais baixo de capacidade de verificação dos módulos de entrada. Por exemplo, se você passar uma imagem nativa e uma imagem de modo misto (compiladas usando **/clr**), a imagem resultante será uma imagem de modo misto.

Você pode usar **/CLRIMAGETYPE** para especificar um nível inferior de verificabilidade, se esse for o que você precisa.

Para obter informações sobre como determinar o tipo de imagem CLR de um arquivo, consulte [/clrheader](../../build/reference/clrheader.md).

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Expanda o nó **Propriedades de Configuração**.

1. Expanda o **vinculador** nó.

1. Selecione o **avançado** página de propriedades.

1. Modificar a **tipo de imagem CLR** propriedade.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

1. Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.CLRImageType%2A>.

## <a name="see-also"></a>Consulte também

- [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)
- [Opções do vinculador](../../build/reference/linker-options.md)
