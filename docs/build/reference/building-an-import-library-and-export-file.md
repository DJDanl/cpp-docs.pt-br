---
title: Compilando uma biblioteca de importação e um arquivo de exportação
ms.date: 09/05/2018
f1_keywords:
- VC.Project.VCLibrarianTool.ModuleDefinitionFile
- VC.Project.VCLibrarianTool.ExportNamedFunctions
- VC.Project.VCLibrarianTool.GenerateDebug
- VC.Project.VCLibrarianTool.ForceSymbolReferences
helpviewer_keywords:
- OUT library manager option
- INCLUDE library manager option
- /DEF library manager option
- exporting data
- import libraries, building
- -INCLUDE library manager option
- /OUT library manager option
- DEF library manager option
- -DEF library manager option
- -OUT library manager option
- /INCLUDE library manager option
- -EXPORT library manager option
- exporting data, export (.exp) files
- /EXPORT library manager option
- EXPORT library manager option
- .lib files
- EXP files
ms.assetid: 2fe4f30a-1dd6-4b05-84b5-0752e1dee354
ms.openlocfilehash: 5cb5224b3edaf84dbcb7c0429044a647fb5ac19a
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87229747"
---
# <a name="building-an-import-library-and-export-file"></a>Compilando uma biblioteca de importação e um arquivo de exportação

Para criar uma biblioteca de importação e um arquivo de exportação, use a seguinte sintaxe:

> **Lib/def**[**:**<em>deffile</em>] [*Opções*] [*objfiles*] [*bibliotecas*]

Quando/DEF é especificado, LIB cria os arquivos de saída das especificações de exportação que são passadas no comando LIB. Há três métodos para especificar exportações, listados na ordem recomendada de uso:

1. Uma **`__declspec(dllexport)`** definição em um dos *objfiles* ou *bibliotecas*

1. Uma especificação de/EXPORT:*Name* na linha de comando lib

1. Uma definição em uma instrução **Exports** em um *deffile*

Esses são os mesmos métodos que você usa para especificar exportações ao vincular um programa de exportação. Um programa pode usar mais de um método. Você pode especificar partes do comando LIB (como várias especificações *objfiles* ou/Export) em um arquivo de comando no comando LIB, assim como você pode em um comando de link.

As opções a seguir se aplicam à criação de uma biblioteca de importação e arquivo de exportação:

> **/Out:** *importar*

Substitui o nome de arquivo de saída padrão para a biblioteca de *importação* que está sendo criada. Quando/OUT não for especificado, o nome padrão será o nome base do primeiro arquivo de objeto ou biblioteca no comando LIB e a extensão. lib. O arquivo de exportação recebe o mesmo nome base que a biblioteca de importação e a extensão. exp.

> **/Export:** *entryname* \[ **=** *InternalName*] \[ , **\@** <em>ordinal</em> \[ , **NoName**]] \[ , **dados**]

Exporta uma função do seu programa para permitir que outros programas chamem a função. Você também pode exportar dados (usando a palavra-chave **Data** ). As exportações geralmente são definidas em uma DLL.

O *entryname* é o nome da função ou do item de dados, pois ele deve ser usado pelo programa de chamada. Opcionalmente, você pode especificar o *InternalName* como a função conhecida no programa de definição; Por padrão, o *InternalName* é o mesmo que *entryname*. O *ordinal* especifica um índice na tabela de exportação no intervalo de 1 a 65.535; Se você não especificar *ordinal*, lib atribuirá um. A palavra-chave **NoName** exporta a função somente como um ordinal, sem um *entryname*. A palavra-chave **Data** é usada para exportar objetos somente de dados.

> **/Include:** *símbolo*

Adiciona o *símbolo* especificado à tabela de símbolos. Essa opção é útil para forçar o uso de um objeto de biblioteca que, de outra forma, não seria incluído.

Observe que, se você criar sua biblioteca de importação em uma etapa preliminar, antes de criar o. dll, você deverá passar o mesmo conjunto de arquivos de objeto ao compilar o. dll, como você passou ao criar a biblioteca de importação.

## <a name="see-also"></a>Confira também

[Trabalhando com bibliotecas de importação e arquivos de exportação](working-with-import-libraries-and-export-files.md)
