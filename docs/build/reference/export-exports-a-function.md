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
ms.openlocfilehash: ae9ab3c2e8f077d943b69b419694fbf686ffdf38
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45703853"
---
# <a name="export-exports-a-function"></a>/EXPORT (exporta uma função)

Exporta uma função por nome ou ordinal ou dados, do seu programa.

## <a name="syntax"></a>Sintaxe

> **/ EXPORTAÇÃO:**<em>Nome_da_entrada</em>[**,\@**<em>ordinal</em>[**, NONAME**]] [**, dados**]

## <a name="remarks"></a>Comentários

O **/exportação** opção especifica um item de dados ou função para exportar a partir do seu programa para que outros programas que podem chamar a função ou usar os dados. Exportações normalmente são definidas em uma DLL.

O *Nome_da_entrada* é o nome do item de dados ou função como ele deve ser usada pelo programa de chamada. *ordinal* Especifica um índice na tabela de exportações no intervalo de 1 a 65.535; se você não especificar *ordinal*, LINK atribui um. O **NONAME** palavra-chave exporta a função apenas como um ordinal, sem uma *Nome_da_entrada*.

O **dados** palavra-chave especifica que o item exportado é um item de dados. O item de dados no programa cliente deve ser declarado usando **extern __declspec(dllimport)**.

Há quatro métodos para exportar uma definição, listada na ordem recomendada de uso:

1. [dllexport](../../cpp/dllexport-dllimport.md) no código-fonte

1. Uma [exportações](../../build/reference/exports.md) instrução em um arquivo. def

1. Uma especificação /EXPORT em um comando LINK

1. Um [comentário](../../preprocessor/comment-c-cpp.md) diretiva no código-fonte do formulário `#pragma comment(linker, "/export: definition ")`.

Todos esses métodos podem ser usados no mesmo programa. Quando LINK compila um programa que contém exportações, ele também cria uma biblioteca de importação, a menos que um arquivo. EXP seja usado na compilação.

Usos LINK decorados formas de identificadores. O compilador decora um identificador ao criar o arquivo. obj. Se *Nome_da_entrada* é especificado para o vinculador no seu não decorado de formulário (conforme ele aparece no código-fonte), LINK tenta corresponder ao nome. Se ele não é possível localizar uma correspondência exclusiva, o LINK emite uma mensagem de erro. Use o [DUMPBIN](../../build/reference/dumpbin-reference.md) ferramenta para obter o [nome decorado](../../build/reference/decorated-names.md) forma de um identificador quando você precisa especificá-lo para o vinculador.

> [!NOTE]
> Não especifique a forma decorada de identificadores de C que são declarados `__cdecl` ou `__stdcall`.

Se você precisar exportar um nome não decorado de função e ter exportações diferentes dependendo da configuração de build (por exemplo, em compilações de 32 bits ou 64 bits), você pode usar diferentes arquivos de definição para cada configuração. (As diretivas de pré-processador condicionais não são permitidas em arquivos DEF.) Como alternativa, você pode usar um `#pragma comment` diretiva antes de uma declaração de função, como mostrado aqui, onde `PlainFuncName` é o nome não decorado, e `_PlainFuncName@4` é o nome decorado da função:

```cpp
#pragma comment(linker, "/export:PlainFuncName=_PlainFuncName@4")
BOOL CALLBACK PlainFuncName( Things * lpParams)
```

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração de propriedades do projeto Visual C++](../../ide/working-with-project-properties.md).

2. Selecione o **propriedades de configuração** > **vinculador** > **linha de comando** página de propriedades.

3. Insira a opção para o **opções adicionais** caixa.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)
