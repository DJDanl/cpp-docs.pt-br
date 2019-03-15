---
title: /Fm (mapfile de nome)
ms.date: 11/04/2016
f1_keywords:
- /fm
helpviewer_keywords:
- -Fm compiler option [C++]
- mapfiles [C++], creating linker
- files [C++], creating map
- Fm compiler option [C++]
- /Fm compiler option [C++]
ms.assetid: 8154448a-93a7-4546-8e4c-5c44d0aff45d
ms.openlocfilehash: eebb1bc0c553dba1934aea75e2e63edc0f222fff
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57815382"
---
# <a name="fm-name-mapfile"></a>/Fm (mapfile de nome)

Instrui o vinculador a produzir um arquivo de mapa que contém uma lista de segmentos na ordem em que aparecem no arquivo de .exe correspondente ou DLL.

## <a name="syntax"></a>Sintaxe

```
/Fmpathname
```

## <a name="remarks"></a>Comentários

Por padrão, o arquivo de mapa recebe o nome base do arquivo de origem C ou C++ correspondente com um. Extensão de mapa.

Especificando **/Fm** tem o mesmo efeito, como se você tiver especificado o [/MAP (Gerar Mapfile)](map-generate-mapfile.md) a opção de vinculador.

Se você especificar [/c (compilar sem vinculação)](c-compile-without-linking.md) para suprimir a vinculação, **/Fm** não tem nenhum efeito.

Símbolos globais em um arquivo de mapa geralmente têm um ou mais sublinhados à esquerda, porque o compilador adiciona um sublinhado à esquerda para nomes de variável. Muitos símbolos globais que aparecem no arquivo de mapa são usados internamente pelo compilador e bibliotecas padrão.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Clique o **C/C++** pasta.

1. Clique o **linha de comando** página de propriedades.

1. Digite a opção de compilador na **opções adicionais** caixa.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Opções do arquivo de saída (/F)](output-file-f-options.md)<br/>
[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)<br/>
[Especificando o nome de caminho](specifying-the-pathname.md)
