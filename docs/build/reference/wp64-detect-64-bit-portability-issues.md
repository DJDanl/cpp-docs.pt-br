---
title: /Wp64 (detectar problemas de portabilidade de 64 bits)
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCCLWCECompilerTool.Detect64BitPortabilityProblems
- VC.Project.VCCLCompilerTool.Detect64BitPortabilityProblems
- /wp64
helpviewer_keywords:
- 64-bit compiler [C++], detecting portability problems
- /Wp64 compiler option [C++]
- -Wp64 compiler option [C++]
- Wp64 compiler option [C++]
ms.assetid: 331ae5aa-e627-4d03-8f63-dd2c2d76dadd
ms.openlocfilehash: e5c30ac9096094948a83195f5b3990794c421685
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81335884"
---
# <a name="wp64-detect-64-bit-portability-issues"></a>/Wp64 (detectar problemas de portabilidade de 64 bits)

Esta opção de compilador é obsoleta. Em versões do Visual Studio antes do Visual Studio 2013, isso detecta problemas de portabilidade de 64 bits em tipos que também são marcados com a [palavra-chave __w64.](../../cpp/w64.md)

## <a name="syntax"></a>Sintaxe

```
/Wp64
```

## <a name="remarks"></a>Comentários

Por padrão, em versões do Visual Studio antes do Visual Studio 2013, a opção de compilador **/Wp64** está desligada no compilador MSVC que constrói código x86 de 32 bits, e ligado no compilador MSVC que constrói código x64 de 64 bits.

> [!IMPORTANT]
> A opção de compilador [/Wp64](wp64-detect-64-bit-portability-issues.md) e [__w64](../../cpp/w64.md) palavra-chave são preteridas no Visual Studio 2010 e visual Studio 2012, e não suportadas a partir do Visual Studio 2013. Se você converter um projeto que usa este switch, o switch não será migrado durante a conversão. Para usar essa opção no Visual Studio 2010 ou visual Studio 2012, você deve digitar o interruptor do compilador em **Opções Adicionais** na seção Linha de **Comando** das propriedades do projeto. Se você usar a opção **compilador /Wp64** na linha de comando, o compilador emitirá aviso de linha de comando D9002. Em vez de usar essa opção e palavra-chave para detectar problemas de portabilidade de 64 bits, use um compilador MSVC que tenha como alvo uma plataforma de 64 bits e especifique a opção [/W4.](compiler-option-warning-level.md) Para obter mais informações, consulte [Configure projetos C++ para alvos x64 de 64 bits](../configuring-programs-for-64-bit-visual-cpp.md).

As variáveis dos seguintes tipos são testadas em um sistema operacional de 32 bits como se estivessem sendo usadas em um sistema operacional de 64 bits:

- INT

- long

- ponteiro

Se você compilar regularmente seu aplicativo usando um compilador que constrói código x64 de 64 bits, você pode desabilitar **/Wp64** em suas compilações de 32 bits porque o compilador de 64 bits detectará todos os problemas. Para obter mais informações sobre como direcionar um sistema operacional Windows de 64 [bits, consulte Configure projetos C++ para alvos x64 de 64 bits](../configuring-programs-for-64-bit-visual-cpp.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto.

   Para obter mais informações, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Clique na pasta **C/C++.**

1. Clique na página de propriedade Linha de **Comando.**

1. Modifique a **caixa Opções adicionais** para incluir **/Wp64**.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.Detect64BitPortabilityProblems%2A>.

## <a name="see-also"></a>Confira também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)<br/>
[Configurar projetos C++ para destinos x64 de 64 bits](../configuring-programs-for-64-bit-visual-cpp.md)
