---
title: /Zo (Enhance Optimized Debugging)
ms.date: 11/04/2016
f1_keywords:
- -Zo
- /Zo
helpviewer_keywords:
- Zo compiler option [C++]
- /Zo compiler option [C++]
- -Zo compiler option [C++]
ms.assetid: eea8d89a-7fe0-4fe1-86b2-7689bbebbd7f
ms.openlocfilehash: 2fb64b0cc39d5b7ff0c96d3eae47197c455526f5
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62315346"
---
# <a name="zo-enhance-optimized-debugging"></a>/Zo (Enhance Optimized Debugging)

Gere informações de depuração aprimoradas para código otimizado em compilações sem depuração.

## <a name="syntax"></a>Sintaxe

```cpp
/Zo[-]
```

## <a name="remarks"></a>Comentários

O **/Zo** comutador de compilador gera informações de depuração aprimoradas para código otimizado. Otimização pode usar os registros para variáveis locais, reordenar o código, vetorizar loops e chamadas de função embutida. Essas otimizações podem obscurecer a relação entre o código-fonte e o código de objeto compilado. O **/Zo** opção faz com que o compilador gere informações de depuração adicionais para variáveis locais e as funções embutidas. Usá-lo para ver as variáveis na **Autos**, **Locals**, e **Assista** windows quando você percorre o código no depurador do Visual Studio otimizado. Ele também permite que os rastreamentos de pilha mostrar as funções embutidas no depurador WinDBG. Depurar builds que desabilitou as otimizações ([/Od](od-disable-debug.md)) não é necessário para as informações de depuração adicionais geradas quando **/Zo** for especificado. Use o **/Zo** alternar para as configurações de versão de depuração com a otimização ativada. Para obter mais informações sobre opções de otimização, consulte [/O opções (otimizar código)](o-options-optimize-code.md). O **/Zo** opção é habilitada por padrão no Visual Studio quando você especificar informações de depuração com **/Zi** ou **/Z7**. Especificar **/Zo-** desabilitar explicitamente essa opção do compilador.

O **/Zo** comutador está disponível a partir do Visual Studio 2013 atualização 3, e ele substitui o antigo não documentado **/d2Zi+** alternar.

### <a name="to-set-the-zo-compiler-option-in-visual-studio"></a>Para definir a opção de compilador /Zo no Visual Studio

1. Abra o **páginas de propriedade** caixa de diálogo para o projeto. Para obter mais informações, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione o **propriedades de configuração**, **C/C++** pasta.

1. Selecione o **linha de comando** página de propriedades.

1. Modificar a **opções adicionais** propriedade incluir `/Zo` e, em seguida, escolha **Okey**.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Opções /O (otimizar código)](o-options-optimize-code.md)<br/>
[/Z7, /Zi, /ZI (Formato de Informações de Depuração)](z7-zi-zi-debug-information-format.md)<br/>
[Editar e continuar](/visualstudio/debugger/edit-and-continue)
