---
title: Compilando uma biblioteca de importação e um arquivo de exportação | Microsoft Docs
ms.custom: ''
ms.date: 09/05/2018
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCLibrarianTool.ModuleDefinitionFile
- VC.Project.VCLibrarianTool.ExportNamedFunctions
- VC.Project.VCLibrarianTool.GenerateDebug
- VC.Project.VCLibrarianTool.ForceSymbolReferences
dev_langs:
- C++
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c6a980a96198db80f0956895292d37f123d0351c
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45723301"
---
# <a name="building-an-import-library-and-export-file"></a>Compilando uma biblioteca de importação e um arquivo de exportação

Para criar uma biblioteca de importação e exportação de arquivo, use a seguinte sintaxe:

> **LIB /DEF**[**:**<em>deffile</em>] [*opções*] [*objfiles*] [*bibliotecas*]

Quando /DEF for especificado, a biblioteca cria os arquivos de saída das especificações de exportação que são passadas no comando LIB. Há três métodos para especificação de exportações, listadas na ordem recomendada de uso:

1. Um **dllexport** definição de uma da *objfiles* ou *bibliotecas*

2. Uma especificação de /EXPORT:*nome* na linha de comando LIB

3. Uma definição em uma **exportações** instrução em um *deffile*

Esses são os mesmos métodos que você use para especificar exportações ao vincular a um programa de exportação. Um programa pode usar mais de um método. Você pode especificar partes do comando LIB (como o múltiplo *objfiles* ou /EXPORT especificações) em um arquivo de comando no comando LIB, assim como você pode em um comando LINK.

As opções a seguir se aplicam à criação de uma biblioteca de importação e exportar o arquivo:

> **/ Entrada saída:** *importar*

Substitui o nome de arquivo de saída padrão para o *importação* biblioteca que está sendo criada. Quando /out sobrescreve não for especificado, o nome padrão é o nome base do primeiro arquivo de objeto ou da biblioteca, o comando LIB e a extensão. lib. O arquivo de exportação recebe o mesmo nome base que a biblioteca de importação e a extensão. exp.

> **/ EXPORTAÇÃO:** *Nome_da_entrada* \[ **=** *internalname*]\[,**\@** <em>ordinal</em>\[, **NONAME**]]\[, **dados**]

Exporta uma função do seu programa para permitir que outros programas chamar a função. Você também pode exportar dados (usando o **dados** palavra-chave). Exportações normalmente são definidas em uma DLL.

O *Nome_da_entrada* é o nome do item de dados ou função como ele deve ser usada pelo programa de chamada. Opcionalmente, você pode especificar o *internalname* como a função conhecida no programa de definição; por padrão, *internalname* é o mesmo que *Nome_da_entrada*. O *ordinal* Especifica um índice na tabela de exportação no intervalo de 1 a 65.535; se você não especificar *ordinal*, LIB atribui um. O **NONAME** palavra-chave exporta a função apenas como um ordinal, sem uma *Nome_da_entrada*. O **dados** palavra-chave é usado para exportar objetos de dados.

> **/ INCLUEM:** *símbolo*

Adiciona o *símbolo* à tabela de símbolos. Essa opção é útil para forçar o uso de um objeto de biblioteca, caso contrário, não poderia ser incluído.

Observe que se você criar sua biblioteca de importação em uma etapa preliminar, antes de criar seu. dll, você deve passar o mesmo conjunto de arquivos de objeto ao criar o arquivo. dll, conforme passado ao compilar a biblioteca de importação.

## <a name="see-also"></a>Consulte também

[Trabalhando com bibliotecas de importação e arquivos de exportação](../../build/reference/working-with-import-libraries-and-export-files.md)