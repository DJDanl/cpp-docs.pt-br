---
title: "/NXCOMPAT (compatível com prevenção de execução de dados) | Microsoft Docs"
ms.custom: 
ms.date: 12/29/2017
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
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
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 4669c24c3e15fc82f4ba81c83b8892ed18c24a5e
ms.sourcegitcommit: 54035dce0992ba5dce0323d67f86301f994ff3db
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/03/2018
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
