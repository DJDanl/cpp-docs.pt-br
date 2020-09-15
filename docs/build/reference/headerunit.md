---
title: /headerUnit (use a unidade de cabeçalho IFC)
description: Use a opção de compilador/headerUnit para especificar uma unidade de cabeçalho IFC existente para importar na compilação atual.
ms.date: 09/13/2020
f1_keywords:
- /headerUnit
helpviewer_keywords:
- /headerUnit
- Use header unit IFC
ms.openlocfilehash: 2734df728b188dcfbbe5f475cfc67715a070975d
ms.sourcegitcommit: b492516cc65120250b9ea23f96f7f63f37f99fae
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/14/2020
ms.locfileid: "90079054"
---
# <a name="headerunit-use-header-unit-ifc"></a>`/headerUnit` (Use a unidade de cabeçalho IFC)

Informa ao compilador para converter `#include` diretivas para um nome de cabeçalho importável em uma `import header-name;` diretiva, em vez de usar a inclusão textual.

## <a name="syntax"></a>Sintaxe

> **`/headerUnit`** *`header-filename`*=*`ifc-filename`*

### <a name="arguments"></a>Argumentos

*`header-filename`*\
O nome de um arquivo que o compilador resolve um `header-name` para. Durante `import header-name ;` o compilador, o é resolvido `header-name` para algum arquivo no disco. Use *`header-filename`* para especificar esse arquivo. Uma vez correspondente, o compilador abre o IFC correspondente chamado por *`ifc-filename`* para importação.

*`ifc-filename`*\
O nome de um arquivo que contém *dados de IFC*, informações de módulo predefinidas. Para importar mais de uma unidade de cabeçalho, inclua uma **`/headerUnit`** opção separada para cada arquivo.

## <a name="remarks"></a>Comentários

A **`/headerUnit`** opção do compilador requer que você habilite o suporte a módulos experimentais usando a [`/experimental:module`](experimental-module.md) opção do compilador, juntamente com a opção [/std: c + + mais recente](std-specify-language-standard-version.md) . Essa opção está disponível a partir do Visual Studio 2019 versão 16,8.

O compilador não pode mapear um único *`header-name`* para vários arquivos IFC. Embora seja possível mapear vários *`header-name`* argumentos para um único IFC, isso não é recomendável. O conteúdo do IFC é importado como se fosse apenas o cabeçalho especificado por *`header-name`* .

### <a name="examples"></a>Exemplos

Dado um projeto que faz referência a dois arquivos de cabeçalho e suas unidades de cabeçalho, listadas nesta tabela:

| Arquivo de cabeçalho | Arquivo IFC |
|--|--|
| *`C:\utils\util.h`* | *`C:\util.h.ifc`* |
| *`C:\app\app.h`* | *`C:\app.h.ifc`* |

As opções do compilador para fazer referência às unidades de cabeçalho para esses arquivos de cabeçalho específicos podem ser semelhantes a este exemplo:

```CMD
cl ... /experimental:module /translateInclude /headerUnit C:\utils\util.h=C:\util.h.ifc /headerUnit C:\app\app.h=C:\app.h.ifc
```

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Defina a lista suspensa **configuração** para **todas as configurações**.

1. Selecione a **Configuration Properties**  >  página de propriedade de linha de comando**C/C++** Propriedades de configuração  >  **Command Line** .

1. Modifique a propriedade **Opções adicionais** para adicionar as *`/headerUnit`* Opções e os argumentos. Em seguida, escolha **OK** ou **aplicar** para salvar suas alterações.

## <a name="see-also"></a>Confira também

[`/experimental:module` (Habilitar suporte a módulo)](experimental-module.md)\
[`/module:exportHeader` (Criar unidades de cabeçalho)](module-exportheader.md)\
[`/module:reference` (Use o módulo nomeado IFC)](module-reference.md)\
[`/translateInclude` (Traduzir incluir diretivas em diretivas de importação)](translateinclude.md)\
