---
title: -AI (especificar diretórios de metadados) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCCLCompilerTool.AdditionalUsingDirectories
- VC.Project.VCNMakeTool.AssemblySearchPath
- /AI
- VC.Project.VCCLWCECompilerTool.AdditionalUsingDirectories
dev_langs:
- C++
helpviewer_keywords:
- /AI compiler option [C++]
- AI compiler option [C++]
- -AI compiler option [C++]
ms.assetid: fb9c1846-504c-4a3b-bb39-c8696de32f6f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 985ff4eb96b904dc9c5b4377b336109b00e06b40
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45716580"
---
# <a name="ai-specify-metadata-directories"></a>/AI (especificar diretórios de metadados)

Especifica um diretório em que o compilador pesquisará para resolver referências de arquivo passadas para diretiva `#using`.

## <a name="syntax"></a>Sintaxe

> **/AI**_diretório_

## <a name="arguments"></a>Arguments

*Diretório*<br/>
O diretório ou o caminho para o compilador pesquisar.

## <a name="remarks"></a>Comentários

Apenas um diretório pode ser passado para um **/AI** invocação. Especifique um **/AI** opção para cada caminho que você deseja que o compilador pesquise. Por exemplo, para adicionar C:\Project\Meta e C:\Common\Meta ao caminho de pesquisa do compilador para `#using` diretivas, adicione `/AI"C:\Project\Meta" /AI"C:\Common\Meta"` à linha de comando do compilador ou adicione cada diretório para o **adicionais #using diretórios** propriedade no Visual Studio.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

2. Selecione o **propriedades de configuração** > **C/C++** > **geral** página de propriedades.

3. Modificar a **adicionais #using diretórios** propriedade.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalUsingDirectories%2A>.

## <a name="see-also"></a>Consulte também

[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)<br/>
[Diretiva #using](../../preprocessor/hash-using-directive-cpp.md)