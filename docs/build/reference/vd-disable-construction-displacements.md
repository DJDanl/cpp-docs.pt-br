---
title: /vd (desabilitar deslocamentos de construção)
ms.date: 11/04/2016
f1_keywords:
- /vd
helpviewer_keywords:
- -vd0 compiler option [C++]
- vd1 compiler option [C++]
- /vdn (Disable Construction Displacement) compiler option
- constructor displacements
- vtordisp fields
- /vd0 compiler option [C++]
- -vd1 compiler option [C++]
- /vd1 compiler option [C++]
- displacements compiler option
- vd0 compiler option [C++]
- Disable Construction Displacements compiler option
ms.assetid: 93258964-14d7-4b1c-9cbc-d6f4d74eab69
ms.openlocfilehash: df8891cc71dd5a4cfd417969578c0c1b46ae3be3
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87223805"
---
# <a name="vd-disable-construction-displacements"></a>/vd (desabilitar deslocamentos de construção)

## <a name="syntax"></a>Sintaxe

```
/vdn
```

## <a name="arguments"></a>Argumentos

**0**<br/>
Suprime o membro de deslocamento do construtor/destruidor vtordisp. Escolha esta opção somente se você tiver certeza de que todos os construtores e destruidores de classe chamam funções virtuais virtualmente.

**1**<br/>
Habilita a criação de membros de substituição de construtor/destruidor vtordisp ocultos. Essa opção é o padrão.

**2**<br/>
Permite que você use o [operador de dynamic_cast](../../cpp/dynamic-cast-operator.md) em um objeto que está sendo construído. Por exemplo, um dynamic_cast de uma classe base virtual a uma classe derivada.

**/vd2** adiciona um campo vtordisp quando você tem uma base virtual com funções virtuais. **/vd1** deve ser suficiente. O caso mais comum em que **/vd2** é necessário é quando a única função virtual em sua base virtual é um destruidor.

## <a name="remarks"></a>Comentários

Essas opções se aplicam somente ao código C++ que usa bases virtuais.

Visual C++ implementa o suporte de substituição de construção C++ em situações em que a herança virtual é usada. As substituições de construção resolvem o problema criado quando uma função virtual, declarada em uma base virtual e substituída em uma classe derivada, é chamada de um Construtor durante a construção de uma classe derivada adicional.

O problema é que a função virtual pode receber um ponteiro incorreto **`this`** como resultado de discrepâncias entre os deslocamentos para as bases virtuais de uma classe e as substituições em suas classes derivadas. A solução fornece um ajuste de deslocamento de construção única, chamado de campo vtordisp, para cada base virtual de uma classe.

Por padrão, os campos vtordisp são introduzidos sempre que o código define construtores e destruidores definidos pelo usuário e também substitui as funções virtuais de bases virtuais.

Essas opções afetam os arquivos de origem inteiros. Use [vtordisp](../../preprocessor/vtordisp.md) para suprimir e, em seguida, reabilitar os campos de vtordisp de acordo com a classe.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Clique na pasta **C/C++** .

1. Clique na página de propriedades de **linha de comando** .

1. Digite a opção do compilador na caixa **Opções adicionais** .

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Confira também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)
