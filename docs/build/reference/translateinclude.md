---
title: /translateInclude (conversão incluir diretivas em diretivas de importação)
description: 'Use a opção de compilador/translateInclude para converter diretivas de #include para um nome de cabeçalho importável em uma diretiva de nome de cabeçalho de importação.'
ms.date: 09/13/2020
f1_keywords:
- /translateInclude
helpviewer_keywords:
- /translateInclude
- Translate include directives into import directives
ms.openlocfilehash: 0050f2cb117e48d69cf97a587ef128b9b45790af
ms.sourcegitcommit: b492516cc65120250b9ea23f96f7f63f37f99fae
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/14/2020
ms.locfileid: "90079049"
---
# <a name="translateinclude-translate-include-directives-into-import-directives"></a>`/translateInclude` (Traduzir incluir diretivas em diretivas de importação)

Informa ao compilador para converter `#include` diretivas para um nome de cabeçalho importável em uma `import header-name;` diretiva, em vez de usar a inclusão textual.

## <a name="syntax"></a>Sintaxe

> **`/translateInclude`**

## <a name="remarks"></a>Comentários

A **`/translateInclude`** opção do compilador requer que você habilite o suporte a módulos experimentais usando a [`/experimental:module`](experimental-module.md) opção do compilador, juntamente com a opção [/std: c + + mais recente](std-specify-language-standard-version.md) . Essa opção está disponível a partir do Visual Studio 2019 versão 16,8.

A **`/translateInclude`** opção efetivamente faz a seguinte transformação, em que o exemplo `<vector>` é uma unidade de cabeçalho importável:

```cpp
#include <vector>
```

O compilador substitui essa diretiva por:

```cpp
import <vector> ;
```

No MSVC, uma unidade de cabeçalho importável é uma chamada por uma **`/headerUnit`** referência. Para obter mais informações, consulte [ `/headerUnit` (usar unidade de cabeçalho IFC)](headerunit.md).

### <a name="examples"></a>Exemplos

Dado um projeto que faz referência a dois arquivos de cabeçalho e suas unidades de cabeçalho, listadas nesta tabela:

| Arquivo de cabeçalho | Arquivo IFC |
|--|--|
| *`C:\utils\util.h`* | *`C:\util.h.ifc`* |
| *`C:\app\app.h`* | *`C:\app.h.ifc`* |

E um arquivo de origem *`.cpp`* que inclui os cabeçalhos,

```cpp
#include "utils/util.h"
#include "app/app.h"

int main() { }
```

A **`/translateInclude`** opção permite que o compilador importe as unidades de cabeçalho em vez de compilar os cabeçalhos novamente. Aqui está um exemplo de linha de comando que traduz as diretivas include para *`util.h`* e *`app.h`* em importações das unidades de cabeçalho em vez disso:

```CMD
cl /IC:\ /experimental:module /translateInclude /headerUnit C:\utils\util.h=C:\util.h.ifc /headerUnit C:\app\app.h=C:\app.h.ifc
```

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Defina a lista suspensa **configuração** para **todas as configurações**.

1. Selecione a **Configuration Properties**  >  página de propriedade de linha de comando**C/C++** Propriedades de configuração  >  **Command Line** .

1. Modifique a propriedade **Opções adicionais** para adicionar a *`/translateInclude`* opção. Em seguida, escolha **OK** ou **aplicar** para salvar suas alterações.

## <a name="see-also"></a>Confira também

[`/experimental:module` (Habilitar suporte a módulo)](experimental-module.md)\
[ `/headerUnit` (Use a unidade de cabeçalho IFC)](headerunit.md). \
[`/module:exportHeader` (Criar unidades de cabeçalho)](module-exportheader.md)\
[`/module:reference` (Use o módulo nomeado IFC)](module-reference.md)
