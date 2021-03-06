---
title: /Gw (Otimizar dados globais)
ms.date: 11/04/2016
f1_keywords:
- /Gw
helpviewer_keywords:
- /Gw compiler option [C++]
- -Gw compiler option [C++]
ms.assetid: 6f90f4e9-5eb8-4c47-886e-631278a5a4a9
ms.openlocfilehash: 8afdb21defbbc8309b27749ab18a40f9555139e5
ms.sourcegitcommit: 28eae422049ac3381c6b1206664455dbb56cbfb6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/31/2019
ms.locfileid: "66450141"
---
# <a name="gw-optimize-global-data"></a>/Gw (Otimizar dados globais)

Dados globais do pacote nas seções COMDAT para otimização.

## <a name="syntax"></a>Sintaxe

```
/Gw[-]
```

## <a name="remarks"></a>Comentários

O **/Gw** opção faz com que o compilador para dados globais do pacote em seções individuais de COMDAT. Por padrão, **/Gw** está desativado e deve ser habilitado explicitamente. Para desabilitá-la explicitamente, use **/Gw-** . Quando ambos **/Gw** e [/GL](gl-whole-program-optimization.md) estiver habilitado, o vinculador usa otimização de programa inteiro para comparar as seções COMDAT em vários arquivos de objeto para excluir dados globais não referenciados ou mesclar dados idênticos de globais somente leitura. Isso pode reduzir significativamente o tamanho do binário resultante executável.

Quando você compila e vincula separadamente, você pode usar o [/OPT: REF](opt-optimizations.md) opção de vinculador para excluir do executável que os dados globais não referenciados nos arquivos de objeto compilados com o **/Gw** opção.

Você também pode usar o [/OPT: ICF](opt-optimizations.md) e [/LTCG](ltcg-link-time-code-generation.md) opções de vinculador juntos para mesclar no executável qualquer somente leitura globais dados idênticos em vários arquivos de objeto compilados com o **/Gw** opção.

Para obter mais informações, consulte [apresentando o comutador de compilador de /Gw](https://devblogs.microsoft.com/cppblog/introducing-gw-compiler-switch/) sobre o C++ Blog da equipe.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione o **C/C++** pasta.

1. Selecione o **linha de comando** página de propriedades.

1. Modificar a **opções adicionais** propriedade incluir **/Gw** e, em seguida, escolha **Okey**.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
