---
title: -Fm (nomear Mapfile) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /fm
dev_langs:
- C++
helpviewer_keywords:
- -Fm compiler option [C++]
- mapfiles [C++], creating linker
- files [C++], creating map
- Fm compiler option [C++]
- /Fm compiler option [C++]
ms.assetid: 8154448a-93a7-4546-8e4c-5c44d0aff45d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: bce549cd782c8d79066b16d2e3791ba906e9c4f9
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46410527"
---
# <a name="fm-name-mapfile"></a>/Fm (mapfile de nome)

Instrui o vinculador a produzir um arquivo de mapa que contém uma lista de segmentos na ordem em que aparecem no arquivo de .exe correspondente ou DLL.

## <a name="syntax"></a>Sintaxe

```
/Fmpathname
```

## <a name="remarks"></a>Comentários

Por padrão, o arquivo de mapa recebe o nome base do arquivo de origem C ou C++ correspondente com um. Extensão de mapa.

Especificando **/Fm** tem o mesmo efeito, como se você tiver especificado o [/MAP (Gerar Mapfile)](../../build/reference/map-generate-mapfile.md) a opção de vinculador.

Se você especificar [/c (compilar sem vinculação)](../../build/reference/c-compile-without-linking.md) para suprimir a vinculação, **/Fm** não tem nenhum efeito.

Símbolos globais em um arquivo de mapa geralmente têm um ou mais sublinhados à esquerda, porque o compilador adiciona um sublinhado à esquerda para nomes de variável. Muitos símbolos globais que aparecem no arquivo de mapa são usados internamente pelo compilador e bibliotecas padrão.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Clique o **C/C++** pasta.

1. Clique o **linha de comando** página de propriedades.

1. Digite a opção de compilador na **opções adicionais** caixa.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Opções do arquivo de saída (/F)](../../build/reference/output-file-f-options.md)<br/>
[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)<br/>
[Especificando o nome de caminho](../../build/reference/specifying-the-pathname.md)