---
title: /Zm (especificar limite de alocação da memória de cabeçalho pré-compilado)
ms.date: 11/04/2016
f1_keywords:
- /zm
helpviewer_keywords:
- PCH files, memory allocation limit
- Zm compiler option [C++]
- /Zm compiler option [C++]
- precompiled header files, memory allocation limit
- Specify Precompiled Header Memory Allocation Limit compiler option
- cl.exe compiler, memory allocation limit
- .pch files, memory allocation limit
- memory allocation, Memory Allocation Limit compiler option
- -Zm compiler option [C++]
ms.assetid: 94c77d5e-6672-46a7-92e0-3f69e277727d
ms.openlocfilehash: ee42fc2d1065a755fa816a99563ccc9f0108e847
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50634792"
---
# <a name="zm-specify-precompiled-header-memory-allocation-limit"></a>/Zm (especificar limite de alocação da memória de cabeçalho pré-compilado)

Determina a quantidade de memória que o compilador atribui para construir cabeçalhos pré-compilados.

## <a name="syntax"></a>Sintaxe

```
/Zmfactor
```

## <a name="arguments"></a>Arguments

*factor*<br/>
Um fato de escala que determina a quantidade de memória que o compilador usa para construir cabeçalhos pré-compilados.

O *fator* argumento é uma porcentagem do tamanho padrão de um buffer de trabalho definido pelo compilador. O valor padrão de *fator* é 100 (porcentagem), mas você pode especificar quantidades maiores ou menores.

## <a name="remarks"></a>Comentários

Em versões anteriores do Visual C++, o compilador usou vários heaps discretos, e cada um tinha um limite finito. Atualmente, o compilador aumenta dinamicamente os heaps conforme necessário até o limite de tamanho total do heap e requer um buffer de tamanho fixo somente para construir cabeçalhos pré-compilados. Consequentemente, o **/Zm** opção de compilador raramente é necessária.

Se o compilador é executado fora do espaço de heap e emite o [C1060](../../error-messages/compiler-errors-1/fatal-error-c1060.md) mensagem de erro quando você usa o **/Zm** opção de compilador, você pode ter muita memória reservada. Considere remover a **/Zm** opção. Se o compilador emite o [C1076](../../error-messages/compiler-errors-1/fatal-error-c1076.md) mensagem de erro, uma que acompanha [C3859](../../error-messages/compiler-errors-2/compiler-error-c3859.md) mensagem especifica o *fator* argumento a ser usado ao recompilar usando o **/Zm** opção de compilador.

A tabela a seguir mostra como o *fator* argumento afeta o limite de alocação de memória se você pressupor que o tamanho do buffer de cabeçalho pré-compilado padrão é 75 MB.

|Valor de *fator*|Limite de alocação de memória|
|-----------------------|-----------------------------|
|10|7.5 MB|
|100|75 MB|
|200|150 MB|
|1000|750 MB|
|2000|1500 MB|

## <a name="other-ways-to-set-the-memory-allocation-limit"></a>Outras maneiras de definir o limite de alocação de memória

#### <a name="to-set-the-zm-compiler-option-in-the-visual-studio-development-environment"></a>Para definir a opção do compilador /Zm no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. No painel de navegação, selecione **propriedades de configuração**, **C/C++**, **linha de comando**.

1. Insira o **/Zm** opção de compilador na **opções adicionais** caixa.

#### <a name="to-set-the-zm-compiler-option-programmatically"></a>Para definir a opção do compilador /Zm via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)