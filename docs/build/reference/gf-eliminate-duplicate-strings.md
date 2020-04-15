---
title: /GF (eliminar cadeias de caracteres duplicadas)
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCCLCompilerTool.StringPooling
- VC.Project.VCCLWCECompilerTool.StringPooling
- /gf
helpviewer_keywords:
- duplicate strings
- Eliminate Duplicate Strings compiler option [C++]
- pooling strings compiler option [C++]
- -GF compiler option [C++]
- /GF compiler option [C++]
- GF compiler option [C++]
- strings [C++], pooling
ms.assetid: bb7b5d1c-8e1f-453b-9298-8fcebf37d16c
ms.openlocfilehash: e0d23004c7b710f51065db52410fbb15b7cca040
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81320486"
---
# <a name="gf-eliminate-duplicate-strings"></a>/GF (eliminar cadeias de caracteres duplicadas)

Permite que o compilador crie uma única cópia de strings idênticas na imagem do programa e na memória durante a execução. Esta é uma otimização chamada *poolde strings* que pode criar programas menores.

## <a name="syntax"></a>Sintaxe

```
/GF
```

## <a name="remarks"></a>Comentários

Se você usar **/GF,** o sistema operacional não troca a parte de seqüência de memória e pode ler as strings de volta do arquivo de imagem.

**/GF** pools strings como somente leitura. Se você tentar modificar strings em **/GF,** um erro de aplicativo ocorrerá.

O pool de strings permite que o que se destina vasagam como vários ponteiros para vários buffers seja múltiplo suscitado por vários ponteiros para um único buffer. No código a `s` `t` seguir, e são inicializados com a mesma seqüência. O agrupamento de cordas faz com que eles apontem para a mesma memória:

```
char *s = "This is a character buffer";
char *t = "This is a character buffer";
```

> [!NOTE]
> A opção [/ZI,](z7-zi-zi-debug-information-format.md) usada para Editar e Continuar, define automaticamente a opção **/GF.**

> [!NOTE]
> A opção **compilador /GF** cria uma seção endereçada para cada seqüência única. E, por padrão, um arquivo de objeto pode conter até 65.536 seções endereçadas. Se o seu programa contiver mais de 65.536 strings, use a opção [compilador /bigobj](bigobj-increase-number-of-sections-in-dot-obj-file.md) para criar mais seções.

**/GF** está em vigor quando [/O1](o1-o2-minimize-size-maximize-speed.md) ou [/O2](o1-o2-minimize-size-maximize-speed.md) é usado.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Clique na pasta **C/C++.**

1. Clique na página **de propriedade Geração de Código.**

1. Modifique a propriedade **Ativar pooling de strings.**

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.StringPooling%2A>.

## <a name="see-also"></a>Confira também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
