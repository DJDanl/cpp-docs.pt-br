---
title: /NXCOMPAT (compatível com Prevenção de Execução de Dados)
description: Descreve a opção de vinculador/NXCOMPAT do Microsoft C/C++ (MSVC), que marca um executável como compatível com o DEP (prevenção de execução de dados).
ms.date: 12/17/2019
f1_keywords:
- /NXCOMPAT
helpviewer_keywords:
- /NXCOMPAT linker option
- -NXCOMPAT linker option
- NXCOMPAT linker option
ms.openlocfilehash: f3a0906a49e3524fff3e1ef1643d1eceee28f169
ms.sourcegitcommit: a5fa9c6f4f0c239ac23be7de116066a978511de7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75298981"
---
# <a name="nxcompat-compatible-with-data-execution-prevention"></a>/NXCOMPAT (compatível com Prevenção de Execução de Dados)

Indica que um executável é compatível com o recurso de prevenção de execução de dados do Windows.

## <a name="syntax"></a>Sintaxe

> **/NXCOMPAT**[ **:NO**]

## <a name="remarks"></a>Comentários

Por padrão, **/NXCOMPAT** está on.

**/NXCOMPAT: não** pode ser usado para especificar explicitamente um executável como incompatível com a prevenção de execução de dados.

Para obter mais informações sobre a prevenção de execução de dados, consulte estes artigos:

- [Prevenção de execução de dados](/windows/win32/Memory/data-execution-prevention)

- [Prevenção de execução de dados (Windows Embedded)](/previous-versions/windows/embedded/ms913190\(v=winembedded.5\))

### <a name="to-set-this-linker-option-in-visual-studio"></a>Para definir essa opção do vinculador no Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Escolha as **Propriedades de configuração** > **vinculador** > página de propriedades de **linha de comando** .

1. Insira a opção na caixa **Opções adicionais** . Escolha **OK** ou **aplicar** para aplicar a alteração.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Veja também

[referência do vinculador MSVC](linking.md)\
[Opções de vinculador MSVC](linker-options.md)
