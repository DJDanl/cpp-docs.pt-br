---
title: /sourceDependencies (relatar dependências no nível da origem)
description: Guia de referência para a opção de compilador/sourceDependencies no Microsoft C++.
ms.date: 07/29/2020
f1_keywords:
- /sourceDependencies
helpviewer_keywords:
- /sourceDependencies compiler option
- /sourceDependencies
ms.openlocfilehash: 0c1866812435c777f6f1fd7ed7f9db788a8cf031
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91502836"
---
# <a name="sourcedependencies-report-source-level-dependencies"></a>`/sourceDependencies` (Relatar dependências de nível de origem)

Instrui o compilador a gerar um arquivo JSON que detalha as dependências de nível de origem consumidas durante a compilação.

O arquivo JSON contém uma lista das dependências de origem, que incluem:

- Arquivos de cabeçalho (cabeçalhos transitivos e incluídos diretamente).
- O PCH usado (se **`/Yu`** for especificado).
- Módulos importados e unidades de cabeçalho importadas (unidades de cabeçalho/módulos transitivos e importados diretamente).

## <a name="syntax"></a>Sintaxe

> **`/sourceDependencies`***nome do arquivo*\
> **`/sourceDependencies`***do diretório*

## <a name="arguments"></a>Argumentos

*nome do arquivo*\
O compilador grava a saída de dependência de origem para o nome de arquivo especificado, que pode incluir um caminho relativo ou absoluto.

*active*\
Se o argumento for um diretório, o compilador gerará arquivos de dependência de origem no diretório especificado. O nome do arquivo de saída é baseado no nome completo do arquivo de entrada, com uma extensão acrescentada *`.json`* . Por exemplo, se o arquivo fornecido para o compilador for *`main.cpp`* , o nome de arquivo de saída gerado será *`main.cpp.json`* .

## <a name="remarks"></a>Comentários

A **`/sourceDependencies`** opção do compilador está disponível a partir do Visual Studio 2019 versão 16,7. Ele não é habilitado por padrão.

Quando você especifica a **`/MP`** opção do compilador, recomendamos usar **`/sourceDependencies`** com um argumento de diretório. Se você fornecer um único argumento de nome de arquivo, duas instâncias do compilador poderão tentar abrir o arquivo de saída simultaneamente e causar um erro. Para obter mais informações sobre o **`/MP`** , consulte [ `/MP` (compilar com vários processos)](mp-build-with-multiple-processes.md).

Quando ocorre um erro de compilador não fatal, as informações de dependência ainda são gravadas no arquivo de saída.

Todos os caminhos de arquivo aparecem como caminhos absolutos na saída.

### <a name="examples"></a>Exemplos

Dado o seguinte código de exemplo:

```cpp
// main.cpp
#include "header.h"
import m;
import "other.h";

int main() { }
```

Você pode usar **`/sourceDependencies`** junto com o restante das opções do seu compilador:

> `cl ... /sourceDependencies output.json ... main.cpp`

onde `...` representa suas outras opções de compilador. Essa linha de comando produz um arquivo JSON *`output.json`* com conteúdo semelhante a:

```JSON
{
    "Version": "1.0",
    "Data": {
        "Source": "C:\\...\\main.cpp",
        "PCH": "C:\\...\\pch.pch",
        "Includes": [
            "C:\\...\\header.h"
        ],
        "Modules": [
            "C:\\...\\m.ifc",
            "C:\\...\\other.h.ifc"
        ]
    }
}
```

Usamos `...` para abreviar os caminhos relatados; o relatório contém os caminhos absolutos. Os caminhos relatados dependem de onde o compilador encontra as dependências. Se os resultados forem inesperados, talvez você queira verificar as configurações de caminho de inclusão do seu projeto.

### <a name="to-set-the-sourcedependencies-compiler-option-in-visual-studio"></a>Para definir a opção de compilador/sourceDependencies no Visual Studio

1. Abra a caixa de diálogo **páginas de propriedades** do projeto. Para obter mais informações, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a **Configuration Properties**  >  página de propriedade de linha de comando**C/C++** Propriedades de configuração  >  **Command Line** .

1. Na caixa **Opções adicionais** , adicione *`/sourceDependencies: <filename>`* e, em seguida, escolha **OK** ou **aplicar** para salvar suas alterações.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Essa opção não tem um equivalente programático.

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)<br/>
