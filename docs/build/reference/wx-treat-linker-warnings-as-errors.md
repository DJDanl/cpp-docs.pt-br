---
title: /WX (tratar avisos do vinculador como erros)
ms.date: 11/04/2016
f1_keywords:
- /WX
helpviewer_keywords:
- /WX linker option
- -WX linker option
- WX linker option
ms.assetid: e4ba97c7-93f7-43ae-a4bb-d866790926c9
ms.openlocfilehash: b4b29ed364d39c5f105dded703b8530c08db35e6
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62316295"
---
# <a name="wx-treat-linker-warnings-as-errors"></a>/WX (tratar avisos do vinculador como erros)

```
/WX[:NO]
```

## <a name="remarks"></a>Comentários

/WX faz com que nenhum arquivo de saída a ser gerado se o vinculador gera um aviso.

Isso é semelhante à **/WX** para o compilador (consulte [/w, /W0, / W1, / w2, / w3, / W4, / W1, / w2, / w3, / W4, /Wall, /wd, /, /wo, /Wv, /WX (nível de aviso)](compiler-option-warning-level.md) para obter mais informações). No entanto, especificando **/WX** para a compilação não implica em que **/WX** também estará em vigor para a fase de link; você deve especificar explicitamente **/WX** para cada ferramenta.

Por padrão, **/WX** não está em vigor. Para tratar avisos do vinculador como erros, especifique **/WX**. **/WX:no** é o mesmo que não especificar **/WX**.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Clique o **vinculador** pasta.

1. Clique o **linha de comando** página de propriedades.

1. Digite a opção para o **opções adicionais** caixa.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

1. Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções de vinculador MSVC](linker-options.md)
