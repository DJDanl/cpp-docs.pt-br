---
title: /NXCOMPAT (compatível com Prevenção de Execução de Dados)
ms.date: 12/29/2017
f1_keywords:
- /NXCOMPAT
helpviewer_keywords:
- /NXCOMPAT linker option
- -NXCOMPAT linker option
- NXCOMPAT linker option
ms.openlocfilehash: 7c788f5ec499f0edf0c44f1ff269af9767af6c08
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69492670"
---
# <a name="nxcompat-compatible-with-data-execution-prevention"></a>/NXCOMPAT (compatível com Prevenção de Execução de Dados)

Indica que um executável é compatível com o recurso de prevenção de execução de dados do Windows.

## <a name="syntax"></a>Sintaxe

> **/NXCOMPAT**[ **:NO**]

## <a name="remarks"></a>Comentários

Por padrão, **/NXCOMPAT** está on.

**/NXCOMPAT: não** pode ser usado para especificar explicitamente um executável como incompatível com a prevenção de execução de dados.

Para obter mais informações sobre a prevenção de execução de dados, consulte estes artigos:

- [Uma descrição detalhada do recurso DEP (prevenção de execução de dados)](https://support.microsoft.com/help/875352/a-detailed-description-of-the-data-execution-prevention-dep-feature-in)

- [Prevenção de execução de dados](/windows/win32/Memory/data-execution-prevention)

- [Prevenção de execução de dados (Windows Embedded)](/previous-versions/windows/embedded/ms913190\(v=winembedded.5\))

### <a name="to-set-this-linker-option-in-visual-studio"></a>Para definir essa opção do vinculador no Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Escolha a página de propriedade da**linha de comando** do**vinculador** > de **Propriedades** > de configuração.

1. Insira a opção na caixa **Opções adicionais** . Escolha **OK** ou **aplicar** para aplicar a alteração.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções de vinculador MSVC](linker-options.md)
