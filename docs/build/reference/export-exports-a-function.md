---
title: -EXPORT (exporta uma função) | Microsoft Docs
ms.custom: ''
ms.date: 09/05/2018
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCLinkerTool.ExportFunctions
- /export
dev_langs:
- C++
helpviewer_keywords:
- /EXPORT linker option
- EXPORT linker option
- -EXPORT linker option
ms.assetid: 0920fb44-a472-4091-a8e6-73051f494ca0
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 16ec6be15635ebfc085615015b1221231645970d
ms.sourcegitcommit: d10a2382832373b900b1780e1190ab104175397f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/06/2018
ms.locfileid: "43894788"
---
# <a name="export-exports-a-function"></a>/EXPORT (exporta uma função)

Exporta uma função por nome ou ordinal ou dados, do seu programa.

## <a name="syntax"></a>Sintaxe

> **/ EXPORTAÇÃO:**<em>Nome_da_entrada</em>[**,\@**<em>ordinal</em>[**, NONAME**]] [**, dados**]

## <a name="remarks"></a>Comentários

Com a opção /EXPORT, você pode exportar uma função de seu programa para que outros programas podem chamar a função. Você também pode exportar os dados. Exportações normalmente são definidas em uma DLL.

O *Nome_da_entrada* é o nome do item de dados ou função como ele deve ser usada pelo programa de chamada. `ordinal` Especifica um índice na tabela de exportações no intervalo de 1 a 65.535; Se você não especificar `ordinal`, LINK atribui um. O **NONAME** palavra-chave exporta a função apenas como um ordinal, sem uma *Nome_da_entrada*.

O **dados** palavra-chave especifica que o item exportado é um item de dados. O item de dados no programa cliente deve ser declarado usando **extern __declspec(dllimport)**.

Há três métodos para exportar uma definição, listada na ordem recomendada de uso:

1. [dllexport](../../cpp/dllexport-dllimport.md) no código-fonte

2. Uma [exportações](../../build/reference/exports.md) instrução em um arquivo. def

3. Uma especificação /EXPORT em um comando LINK

Todos os três métodos podem ser usados no mesmo programa. Quando LINK compila um programa que contém exportações, ele também cria uma biblioteca de importação, a menos que um arquivo. EXP seja usado na compilação.

Usos LINK decorados formas de identificadores. O compilador decora um identificador ao criar o arquivo. obj. Se *Nome_da_entrada* é especificado para o vinculador no seu não decorado de formulário (conforme ele aparece no código-fonte), LINK tenta corresponder ao nome. Se ele não é possível localizar uma correspondência exclusiva, o LINK emite uma mensagem de erro. Use o [DUMPBIN](../../build/reference/dumpbin-reference.md) ferramenta para obter o [nomes decorados](../../build/reference/decorated-names.md) forma de um identificador quando você precisa especificá-lo para o vinculador.

> [!NOTE]
> Não especifique a forma decorada de identificadores de C que são declarados `__cdecl` ou `__stdcall`.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração de propriedades do projeto Visual C++](../../ide/working-with-project-properties.md).

2. Selecione o **propriedades de configuração** > **vinculador** > **linha de comando** página de propriedades.

3. Insira a opção para o **opções adicionais** caixa.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
[Opções do vinculador](../../build/reference/linker-options.md)