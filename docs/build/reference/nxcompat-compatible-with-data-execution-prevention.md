---
title: /NXCOMPAT (compatível com prevenção de execução de dados) | Microsoft Docs
ms.custom: ''
ms.date: 12/29/2017
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /NXCOMPAT
dev_langs:
- C++
helpviewer_keywords:
- /NXCOMPAT linker option
- -NXCOMPAT linker option
- NXCOMPAT linker option
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: bb4f8a91545a196bc92fdc0ec44e89a7d5680185
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32374798"
---
# <a name="nxcompat-compatible-with-data-execution-prevention"></a>/NXCOMPAT (compatível com Prevenção de Execução de Dados)

Indica que um executável é compatível com o recurso do Windows Data Execution Prevention.

## <a name="syntax"></a>Sintaxe

> **/NXCOMPAT**[**: NENHUM**]

## <a name="remarks"></a>Comentários

Por padrão, **/NXCOMPAT** está em.

**/NXCOMPAT: no** pode ser usado para especificar explicitamente um executável como incompatíveis com prevenção de execução de dados.

Para obter mais informações sobre a prevenção de execução de dados, consulte estes artigos:

- [Uma descrição detalhada do recurso prevenção de execução de dados (DEP)](http://go.microsoft.com/fwlink/p/?linkid=157771)

- [Prevenção de execução de dados](http://go.microsoft.com/fwlink/p/?linkid=157770)

- [Prevenção de execução de dados (Windows Embedded)](http://go.microsoft.com/fwlink/p/?linkid=157768)

### <a name="to-set-this-linker-option-in-visual-studio"></a>Para definir essa opção do vinculador no Visual Studio

1. Abra o projeto **páginas de propriedade** caixa de diálogo. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Escolha o **propriedades de configuração** > **vinculador** > **linha de comando** página de propriedades.

1. Insira a opção no **opções adicionais** caixa. Escolha **Okey** ou **aplicar** para aplicar a alteração.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)  
[Opções do vinculador](../../build/reference/linker-options.md)  
