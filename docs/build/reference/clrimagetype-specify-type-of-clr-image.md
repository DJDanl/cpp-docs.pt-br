---
title: /CLRIMAGETYPE (especificar tipo de imagem CLR)
ms.date: 05/16/2019
f1_keywords:
- /CLRIMAGETYPE
- VC.Project.VCLinkerTool.CLRImageType
helpviewer_keywords:
- /CLRIMAGETYPE linker option
- -CLRIMAGETYPE linker option
ms.assetid: 04c60ee6-9dd7-4391-bc03-6926ad0fa116
ms.openlocfilehash: ee2e2ce359a4b877551adf9af71e0187b42cfd42
ms.sourcegitcommit: a10c9390413978d36b8096b684d5ed4cf1553bc8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/17/2019
ms.locfileid: "65837489"
---
# <a name="clrimagetype-specify-type-of-clr-image"></a>/CLRIMAGETYPE (especificar tipo de imagem CLR)

Defina o tipo de imagem CLR na imagem vinculada.

## <a name="syntax"></a>Sintaxe

> **/CLRIMAGETYPE:**{**IJW**|**PURE**|**SAFE**|**SAFE32BITPREFERRED**}

## <a name="remarks"></a>Comentários

O vinculador aceita objetos nativos e também objetos MSIL compilados usando [/clr](clr-common-language-runtime-compilation.md). As opções do compilador **/clr:pure** e **/clr:safe** foram preteridas no Visual Studio 2015 e estão sem suporte no Visual Studio 2017 e posterior. Quando objetos mistos forem passados no mesmo build, a capacidade de verificação do arquivo de saída resultante, por padrão, será igual ao nível mais baixo da capacidade de verificação dos módulos de entrada. Por exemplo, se você passar uma imagem nativa e uma imagem de modo misto (compiladas usando **/clr**), a imagem resultante será uma imagem de modo misto.

Use **/CLRIMAGETYPE** para especificar um nível inferior de capacidade de verificação, se isso for o que você precisa.

Para obter informações sobre como determinar o tipo de imagem CLR de um arquivo, confira [/CLRHEADER](clrheader.md).

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Expanda o nó **Propriedades de Configuração**.

1. Expanda o nó **Vinculador**.

1. Selecione a página de propriedades **Avançado**.

1. Modifique a propriedade **Tipo de Imagem CLR**.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

1. Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.CLRImageType%2A>.

## <a name="see-also"></a>Consulte também

- [Referência de vinculador MSVC](linking.md)
- [Opções de vinculador MSVC](linker-options.md)
