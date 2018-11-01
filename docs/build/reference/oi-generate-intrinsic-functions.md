---
title: /Oi (gerar funções intrínsecas)
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCCLCompilerTool.EnableIntrinsicFunctions
- /oi
- VC.Project.VCCLWCECompilerTool.EnableIntrinsicFunctions
helpviewer_keywords:
- Oi compiler option [C++]
- intrinsic functions, generate
- /Oi compiler option [C++]
- -Oi compiler option [C++]
- generate intrinsic functions compiler option [C++]
ms.assetid: fa4a3bf6-0ed8-481b-91c0-add7636132b4
ms.openlocfilehash: 067b8b11b716935c684a127632a8fadaf3d9a447
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50646055"
---
# <a name="oi-generate-intrinsic-functions"></a>/Oi (gerar funções intrínsecas)

Substitui algumas chamadas de função com formas intrínsecas ou especiais de outra forma da função que ajudam a seu aplicativo é executado mais rapidamente.

## <a name="syntax"></a>Sintaxe

```
/Oi[-]
```

## <a name="remarks"></a>Comentários

Programas que usam funções intrínsecas são mais rápidos porque eles não têm a sobrecarga das chamadas de função, mas podem ser maiores por causa do código adicional criado.

Ver [intrínseco](../../preprocessor/intrinsic.md) para obter mais informações sobre quais funções têm formas intrínsecas.

**/Oi** é apenas uma solicitação para o compilador para substituir algumas chamadas de função com intrínsecos; o compilador pode chamar a função (e não substituir a chamada de função com um intrínseco) se isso resultar em melhor desempenho.

**x86 específico**

As funções de ponto flutuantes intrínsecas não executa nenhuma verificação especiais nos valores de entrada e então funcionam em intervalos restringidos de entrada e tem o tratamento de exceção diferentes e condições de limite que as rotinas da biblioteca com o mesmo nome. Usar as formas intrínsecas reais implica em perda de manipulação de exceção do IEEE e perda de `_matherr` e `errno` funcionalidade; o último implica em perda de conformidade com ANSI. No entanto, as formas intrínsecas podem acelerar consideravelmente programas intensivos de ponto flutuante e, para muitos programas, os problemas de conformidade são pouco valor prático.

Você pode usar o [Za](../../build/reference/za-ze-disable-language-extensions.md) opção de compilador para substituir a geração das opções de ponto flutuantes intrínsecas true. Nesse caso, as funções são geradas como rotinas de biblioteca que passam argumentos diretamente para o chip de ponto flutuante em vez de enviá-los para a pilha do programa.

**END x86 específico**

Você também usar [intrínseco](../../preprocessor/intrinsic.md) para criar funções intrínsecas, ou [função (C/C++)](../../preprocessor/function-c-cpp.md) para forçar explicitamente uma chamada de função.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Clique o **C/C++** pasta.

1. Clique o **otimização** página de propriedades.

1. Modificar a **Habilitar funções intrínsecas** propriedade.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.EnableIntrinsicFunctions%2A>.

## <a name="see-also"></a>Consulte também

[Opções /O (otimizar código)](../../build/reference/o-options-optimize-code.md)<br/>
[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)<br/>
[Intrínsecos do compilador](../../intrinsics/compiler-intrinsics.md)