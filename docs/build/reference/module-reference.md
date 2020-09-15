---
title: '/Module: referência (use o módulo nomeado IFC)'
description: 'Use a opção de compilador/Module: Reference para criar unidades de cabeçalho de módulo para o nome do cabeçalho ou arquivos de inclusão especificados.'
ms.date: 09/13/2020
f1_keywords:
- /module:reference
helpviewer_keywords:
- /module:reference
- Use named module IFC
ms.openlocfilehash: 5f40f6b700c38f3238cc7a621313621085fbc289
ms.sourcegitcommit: b492516cc65120250b9ea23f96f7f63f37f99fae
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/14/2020
ms.locfileid: "90079052"
---
# <a name="modulereference-use-named-module-ifc"></a>`/module:reference` (Use o módulo nomeado IFC)

Informa ao compilador para usar um IFC existente ( *`.ifc`* ) para a compilação atual.

## <a name="syntax"></a>Sintaxe

> **`/module:reference`** *`module-name=filename`*\
> **`/module:reference`** *`filename`*

### <a name="arguments"></a>Argumentos

*`filename`*\
O nome de um arquivo que contém *dados de IFC*, informações de módulo predefinidas. Para importar mais de um módulo, inclua uma **`/module:reference`** opção separada para cada arquivo.

*`module-name`*\
Um nome válido de um nome de unidade de interface de módulo primário exportado ou nome de partição de módulo completo.

## <a name="remarks"></a>Comentários

A **`/module:reference`** opção do compilador requer que você habilite o suporte a módulos experimentais usando a [`/experimental:module`](experimental-module.md) opção do compilador, juntamente com a opção [/std: c + + mais recente](std-specify-language-standard-version.md) . Essa opção está disponível a partir do Visual Studio 2019 versão 16,8.

Se o **`/module:reference`** argumento for um *`filename`* sem um *`module-name`* , o arquivo será aberto em tempo de execução para verificar os *`filename`* nomes de argumentos de uma importação específica. Isso pode resultar em um desempenho de tempo de execução mais lento em cenários que têm muitos **`/module:reference`** argumentos.

O *`module-name`* deve ser um nome de unidade de interface de módulo primário válido ou nome de partição de módulo completo. Exemplos de nomes de interface de módulo primário incluem:

- `M`
- `M.N.O`
- `MyModule`
- `my_module`

Exemplos de nomes de partição de módulo completos incluem:

- `M:P`
- `M.N.O:P.Q`
- `MyModule:Algorithms`
- `my_module:algorithms`

Se uma referência de módulo for criada usando um *`module-name`* , outros módulos na linha de comando não serão pesquisados se o compilador encontrar uma importação desse nome. Por exemplo, dada esta linha de comando:

```cmd
cl ... /experimental:module /module:reference m.ifc /module:reference m=n.ifc
```

No caso acima, se o compilador ver `import m;` , *`m.ifc`* não é pesquisado.

### <a name="examples"></a>Exemplos

Considerando três módulos, conforme listado nesta tabela:

| Módulo | Arquivo IFC |
|--|--|
| *`M`* | *`m.ifc`* |
| *`M:Part1`* | *`m-part1.ifc`* |
| *`Core.Networking`* | *`Networking.ifc`* |

As opções de referência usando um *`filename`* argumento poderiam ser semelhantes a:

```cmd
cl ... /experimental:module /module:reference m.ifc /module:reference m-part.ifc /module:reference Networking.ifc
```

As opções de referência que usam *`module-name=filename`* poderiam ser semelhantes a:

```cmd
cl ... /experimental:module /module:reference m=m.ifc /module:reference M:Part1=m-part.ifc /module:reference Core.Networking=Networking.ifc
```

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Defina a lista suspensa **configuração** para **todas as configurações**.

1. Selecione a **Configuration Properties**  >  página de propriedade de linha de comando**C/C++** Propriedades de configuração  >  **Command Line** .

1. Modifique a propriedade **Opções adicionais** para adicionar a *`/module:reference`* opção e seus argumentos. Em seguida, escolha **OK** ou **aplicar** para salvar suas alterações.

## <a name="see-also"></a>Confira também

[`/experimental:module` (Habilitar suporte a módulo)](experimental-module.md)\
[`/headerUnit` (Use a unidade de cabeçalho IFC)](headerunit.md)\
[`/module:exportHeader` (Criar unidades de cabeçalho)](module-exportheader.md)\
[`/translateInclude` (Traduzir incluir diretivas em diretivas de importação)](translateinclude.md)
