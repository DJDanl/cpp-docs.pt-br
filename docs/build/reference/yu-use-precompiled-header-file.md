---
title: /Yu (usar arquivo de cabeçalho pré-compilado)
ms.date: 11/04/2016
f1_keywords:
- /yu
helpviewer_keywords:
- Yu compiler option [C++]
- /Yu compiler option [C++]
- -Yu compiler option [C++]
- PCH files, use existing
- .pch files, use existing
- precompiled header files, use existing
ms.assetid: 24f1bd0e-b624-4296-a17e-d4b53e374e1f
ms.openlocfilehash: 8d2b02c378179ac2603ec095efe89ce78f9f1afa
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50505333"
---
# <a name="yu-use-precompiled-header-file"></a>/Yu (usar arquivo de cabeçalho pré-compilado)

Instrui o compilador a usar um arquivo de cabeçalho pré-compilado (. pch) existente na compilação atual.

## <a name="syntax"></a>Sintaxe

```
/Yu[filename]
```

## <a name="arguments"></a>Arguments

*filename*<br/>
O nome de um arquivo de cabeçalho, que está incluído no arquivo de origem usando um **#include** diretiva de pré-processador.

## <a name="remarks"></a>Comentários

O nome do arquivo de inclusão deve ser o mesmo para ambos os **/Yc** opção que cria o cabeçalho pré-compilado e qualquer subsequentes **/Yu** opção que indica o uso do cabeçalho pré-compilado.

Para **/Yc**, `filename` Especifica o ponto no qual pré-compilação para; o compilador pré-compila todo o código no entanto `filename` e nomes de cabeçalho pré-compilado resultante usando o nome base do arquivo de inclusão e uma extensão de. pch.

O arquivo. pch deve ter sido criado usando **/Yc**.

O compilador trata todo o código que ocorrem antes do arquivo. h como pré-compilado. Ele ignora apenas posteriores a **#include** diretiva associada ao arquivo. h, usa o código contido no arquivo. pch e, em seguida, compila todos os códigos de após `filename`.

Na linha de comando, não é permitido nenhum espaço entre **/Yu** e `filename`.

Quando você especifica o **/Yu** opção sem um nome de arquivo, seu programa de origem deve conter um [#pragma hdrstop](../../preprocessor/hdrstop.md) pragma que especifica o nome do arquivo de cabeçalho pré-compilado, o arquivo. pch. Nesse caso, o compilador usará o cabeçalho pré-compilado (arquivo. pch) nomeado por [/Fp (nome. Arquivo pch)](../../build/reference/fp-name-dot-pch-file.md). O compilador ignora até o local desse pragma, restaura o estado compilado do arquivo de cabeçalho pré-compilado especificado pelo pragma e, em seguida, compila somente o código que se segue ao pragma. Se **#pragma hdrstop** não especifica um nome de arquivo, o compilador procura um arquivo com um nome derivado do nome base do arquivo de origem com uma extensão. pch. Você também pode usar o **/Fp** opção para especificar um arquivo. pch diferentes.

Se você especificar o **/Yu** opção sem um nome de arquivo e não especificar um **hdrstop** pragma, uma mensagem de erro é gerada e a compilação for bem-sucedida.

Se o **/Yc** `filename` e **/Yu** `filename` opções ocorrem na mesma linha de comando e ambas referenciam o mesmo nome de arquivo **/Yc** `filename` leva precedência, pré-compilar todo o código até e incluindo o arquivo nomeado. Esse recurso simplifica a gravação de makefiles.

Como arquivos. pch contêm informações sobre o ambiente de máquina, bem como informações de endereço de memória sobre o programa, você só deve usar um arquivo pch na máquina onde ele foi criado.

Para obter mais informações sobre cabeçalhos pré-compilados, consulte:

- [/Y (cabeçalhos pré-compilados)](../../build/reference/y-precompiled-headers.md)

- [Criando arquivos de cabeçalho pré-compilado](../../build/reference/creating-precompiled-header-files.md)

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Especificar [/Yc (criar a arquivo de cabeçalho pré-compilado)](../../build/reference/yc-create-precompiled-header-file.md) em um arquivo. cpp no projeto.

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Clique o **C/C++** pasta.

1. Clique o **cabeçalhos pré-compilados** página de propriedades.

1. Modificar a **criar/usar PCH através de arquivo** propriedade ou o **criar/usar cabeçalho de pré-compilado** propriedade.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.PrecompiledHeaderThrough%2A> e <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.UsePrecompiledHeader%2A>.

## <a name="examples"></a>Exemplos

Se o código a seguir:

```
#include <afxwin.h>   // Include header for class library
#include "resource.h" // Include resource definitions
#include "myapp.h"    // Include information specific to this app
...
```

é compilado com a linha de comando `CL /YuMYAPP.H PROG.CPP`, o compilador não processa os três incluem instruções mas código pré-compilado de usos de MYAPP.pch, assim, economizando o tempo envolvido no pré-processamento de todos os três arquivos (e todos eles podem incluir os arquivos).

Você pode usar o [/Fp (nome. Arquivo pch)](../../build/reference/fp-name-dot-pch-file.md) a opção com o **/Yu** opção para especificar o nome do arquivo. pch, se o nome é diferente do que o argumento de nome de arquivo para **/Yc** ou o nome base do arquivo de origem, como no a seguir:

```
CL /YuMYAPP.H /FpMYPCH.pch PROG.CPP
```

Este comando Especifica um arquivo de cabeçalho pré-compilado chamado MYPCH.pch. O compilador usa seu conteúdo para restaurar o estado de todos os arquivos de cabeçalho até e incluindo MYAPP.h do pré-compilado. O compilador, em seguida, compila o código que ocorre após o MYAPP.h **incluem** instrução.

## <a name="see-also"></a>Consulte também

[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)