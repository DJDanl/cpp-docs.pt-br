---
title: '/Module: exportHeader (criar unidades de cabeçalho)'
description: 'Use a opção de compilador/Module: exportHeader para criar unidades de cabeçalho de módulo para o nome do cabeçalho ou arquivos de inclusão especificados.'
ms.date: 09/13/2020
f1_keywords:
- /module:exportHeader
helpviewer_keywords:
- /module:exportHeader
- Create header units
ms.openlocfilehash: f0c0ce1c593df742af77aa36189df1e89de75b6b
ms.sourcegitcommit: b492516cc65120250b9ea23f96f7f63f37f99fae
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/14/2020
ms.locfileid: "90079050"
---
# <a name="moduleexportheader-create-header-units"></a>`/module:exportHeader` (Criar unidades de cabeçalho)

Informa ao compilador para criar as unidades de cabeçalho especificadas pelos argumentos de entrada. O compilador gera a saída em arquivos IFC ( *`.ifc`* ).

## <a name="syntax"></a>Sintaxe

> **`/module:exportHeader`** *`header-name`* \[...]\
> **`/module:exportHeader`** *`filename`* \[...]

### <a name="arguments"></a>Argumentos

*`header-name`*\
O arquivo de cabeçalho a ser exportado. O *`header-name`* argumento deve ter a mesma forma que um argumento para uma `#include` diretiva.

*`filename`*\
O caminho relativo ou absoluto para o arquivo de cabeçalho do qual criar uma unidade de cabeçalho.

## <a name="remarks"></a>Comentários

A **`/module:exportHeader`** opção do compilador requer que você habilite o suporte a módulos experimentais usando a [`/experimental:module`](experimental-module.md) opção do compilador, juntamente com a opção [/std: c + + mais recente](std-specify-language-standard-version.md) . Essa opção está disponível a partir do Visual Studio 2019 versão 16,8.

Uma **`/module:exportHeader`** opção de compilador pode especificar quantos argumentos de nome de cabeçalho forem necessários para sua compilação. Você não precisa especificá-los separadamente.

Por padrão, o compilador não produz um arquivo de objeto quando uma unidade de cabeçalho é compilada. Para produzir um arquivo de objeto, especifique a **`/Fo`** opção do compilador. Para obter mais informações, consulte [ `/Fo` (nome do arquivo de objeto)](fo-object-file-name.md).

O compilador resolve um *`header-name`* com base na ordem de pesquisa de diretório de inclusão, incluindo qualquer que você especificar. Para obter mais informações, consulte [ `/I` (diretórios de inclusão adicionais)](i-additional-include-directories.md).

O argumento *`header-name`* deve ser especificado da mesma maneira que apareceria na origem. O argumento é sensível a regras de cotação e `<` operadores to e `>` na linha de comando. O comando com escape correto para criar uma unidade de cabeçalho como `<vector>` usar o prompt de comando VS2019 pode ser semelhante a:

```cmd
cl ... /experimental:module /module:exportHeader "<vector>"
```

A criação de um cabeçalho de projeto local como `"utils/util.h"` pode ser semelhante a:

```cmd
cl ... /experimental:module /module:exportHeader """util/util.h"""
```

As regras de cotação em outros processadores de linha de comando podem ser diferentes.

Ao usar a *`header-name`* forma de **`/module:exportHeader`** , você pode achar útil usar a opção complementar **`/module:showResolvedHeader`** . A **`/module:showResolvedHeader`** opção imprime um caminho absoluto para o arquivo ao *`header-name`* qual o argumento é resolvido.

**`/module:exportHeader`** pode lidar com várias entradas ao mesmo tempo em **`/MP`** . Recomendamos que você use **`/module:output <directory>`** para criar um arquivo IFC separado para cada compilação.

### <a name="examples"></a>Exemplos

Os cabeçalhos fornecidos `"C:\util\util.h"` e `"C:\app\app.h"` , você pode exportá-los como *`header-name`* argumentos usando este comando:

```cmd
cl /IC:\ /experimental:module /module:exportHeader """util/util.h""" """app/app.h""" /FoC:\obj
```

Você pode exportá-los como *`filename`* argumentos usando este comando:

```cmd
cl /IC:\ /experimental:module /module:exportHeader C:\util\util.h C:\app\app.h /FoC:\obj
```

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Defina a lista suspensa **configuração** para **todas as configurações**.

1. Selecione a **Configuration Properties**  >  página de propriedade de linha de comando**C/C++** Propriedades de configuração  >  **Command Line** .

1. Modifique a propriedade **Opções adicionais** para adicionar a *`/module:exportHeader`* opção e quaisquer argumentos. Em seguida, escolha **OK** ou **aplicar** para salvar suas alterações.

## <a name="see-also"></a>Confira também

[`/experimental:module` (Habilitar suporte a módulo)](experimental-module.md)\
[`/headerUnit` (Use a unidade de cabeçalho IFC)](headerunit.md)\
[`/module:reference` (Use o módulo nomeado IFC)](module-reference.md)\
[`/translateInclude` (Traduzir incluir diretivas em diretivas de importação)](translateinclude.md)
