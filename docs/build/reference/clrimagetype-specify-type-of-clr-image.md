---
title: /CLRIMAGETYPE (especificar tipo de imagem CLR) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /CLRIMAGETYPE
- VC.Project.VCLinkerTool.CLRImageType
dev_langs:
- C++
helpviewer_keywords:
- /CLRIMAGETYPE linker option
- -CLRIMAGETYPE linker option
ms.assetid: 04c60ee6-9dd7-4391-bc03-6926ad0fa116
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b5efb2e73e854591be7134753cec21a708fff3e5
ms.sourcegitcommit: a4454b91d556a3dc43d8755cdcdeabcc9285a20e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/04/2018
ms.locfileid: "34705004"
---
# <a name="clrimagetype-specify-type-of-clr-image"></a>/CLRIMAGETYPE (especificar tipo de imagem CLR)

Defina o tipo de imagem CLR na imagem vinculada.

## <a name="syntax"></a>Sintaxe

> **/CLRIMAGETYPE:**{**IJW**|**PURO**|**SEGURO**|**SAFE32BITPREFERRED**}

## <a name="remarks"></a>Comentários

O vinculador aceita objetos nativo e também MSIL objetos que são compilados usando [/clr](../../build/reference/clr-common-language-runtime-compilation.md). O **/clr: pure** e **/CLR: safe** opções do compilador foi preteridas no Visual Studio 2015 e não têm suporte no Visual Studio de 2017. Quando são passados mistos objetos na mesma compilação, a capacidade de verificação do arquivo de saída resultante é, por padrão, igual ao menor nível de capacidade de verificação dos módulos de entrada. Por exemplo, se você passar uma imagem nativa e uma imagem de modo misto (compilados usando **/clr**), a imagem resultante será uma imagem de modo misto.

Você pode usar **/CLRIMAGETYPE** para especificar um nível mais baixo de capacidade de verificação, se esse for o que você precisa.

Para obter informações sobre como determinar o tipo de imagem CLR de um arquivo, consulte [/CLRHEADER](../../build/reference/clrheader.md).

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Expanda o **propriedades de configuração** nó.

1. Expanda o **vinculador** nó.

1. Selecione o **avançado** página de propriedades.

1. Modificar o **tipo de imagem CLR** propriedade.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

1. Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.CLRImageType%2A>.

## <a name="see-also"></a>Consulte também

- [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)
- [Opções do vinculador](../../build/reference/linker-options.md)
