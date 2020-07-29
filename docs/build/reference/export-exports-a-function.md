---
title: /EXPORT (exporta uma função)
ms.date: 09/05/2018
f1_keywords:
- VC.Project.VCLinkerTool.ExportFunctions
- /export
helpviewer_keywords:
- /EXPORT linker option
- EXPORT linker option
- -EXPORT linker option
ms.assetid: 0920fb44-a472-4091-a8e6-73051f494ca0
ms.openlocfilehash: a55b2a4ce72de644fe426894ab389f62bd29b204
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87232684"
---
# <a name="export-exports-a-function"></a>/EXPORT (exporta uma função)

Exporta uma função por nome ou ordinal ou dados de seu programa.

## <a name="syntax"></a>Sintaxe

> **/Export:**<em>entryname</em>[**, \@ **<em>ordinal</em>[**, NoName**]] [**, data**]

## <a name="remarks"></a>Comentários

A opção **/Export** especifica uma função ou item de dados a ser exportado do seu programa para que outros programas possam chamar a função ou usar os dados. As exportações geralmente são definidas em uma DLL.

O *entryname* é o nome da função ou do item de dados, pois ele deve ser usado pelo programa de chamada. *ordinal* especifica um índice na tabela Exports no intervalo de 1 a 65.535; Se você não especificar *ordinal*, o link atribuirá um. A palavra-chave **NoName** exporta a função somente como um ordinal, sem um *entryname*.

A palavra-chave **Data** especifica que o item exportado é um item de dados. O item de dados no programa cliente deve ser declarado usando o **DllImport (__declspec externo)**.

Há quatro métodos para exportar uma definição, listados na ordem recomendada de uso:

1. [__declspec (dllexport)](../../cpp/dllexport-dllimport.md) no código-fonte

1. Uma instrução [Exports](exports.md) em um arquivo. def

1. Uma especificação /EXPORT em um comando LINK

1. Uma diretiva de [Comentário](../../preprocessor/comment-c-cpp.md) no código-fonte, do formulário `#pragma comment(linker, "/export: definition ")` .

Todos esses métodos podem ser usados no mesmo programa. Quando o LINK cria um programa que contém exportações, ele também cria uma biblioteca de importação, a menos que um arquivo. exp seja usado na compilação.

O LINK usa formulários decorados de identificadores. O compilador decora um identificador quando ele cria o arquivo. obj. Se *entryname* for especificado para o vinculador em sua forma não decorada (como aparece no código-fonte), o link tentará corresponder ao nome. Se não for possível encontrar uma correspondência exclusiva, o LINK emitirá uma mensagem de erro. Use a ferramenta [DUMPBIN](dumpbin-reference.md) para obter a forma de [nome decorado](decorated-names.md) de um identificador quando você precisar especificá-lo para o vinculador.

> [!NOTE]
> Não especifique a forma decorada de identificadores C que são declarados **`__cdecl`** ou **`__stdcall`** .

Se você precisar exportar um nome de função não decorado e tiver exportações diferentes dependendo da configuração da compilação (por exemplo, em builds de 32 bits ou 64 bits), poderá usar arquivos DEF diferentes para cada configuração. (As Diretivas condicionais de pré-processador não são permitidas em arquivos DEF.) Como alternativa, você pode usar uma `#pragma comment` diretiva antes de uma declaração de função, como mostrado aqui, onde `PlainFuncName` é o nome não decorado e `_PlainFuncName@4` é o nome decorado da função:

```cpp
#pragma comment(linker, "/export:PlainFuncName=_PlainFuncName@4")
BOOL CALLBACK PlainFuncName( Things * lpParams)
```

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a **Configuration Properties**  >  página de propriedade da linha de comando do**vinculador**de propriedades de configuração  >  **Command Line** .

1. Insira a opção na caixa **Opções adicionais** .

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Confira também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções do vinculador MSVC](linker-options.md)
