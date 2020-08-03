---
title: /Yu (usar arquivo de cabeçalho pré-compilado)
ms.date: 07/31/2020
f1_keywords:
- /Yu
helpviewer_keywords:
- Yu compiler option [C++]
- /Yu compiler option [C++]
- -Yu compiler option [C++]
- PCH files, use existing
- .pch files, use existing
- precompiled header files, use existing
ms.assetid: 24f1bd0e-b624-4296-a17e-d4b53e374e1f
ms.openlocfilehash: 8cccce39949f23e4ceb72807ecaef3597ab733c4
ms.sourcegitcommit: f2a135d69a2a8ef1777da60c53d58fe06980c997
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/03/2020
ms.locfileid: "87520456"
---
# <a name="yu-use-precompiled-header-file"></a>`/Yu`(Usar arquivo de cabeçalho pré-compilado)

Instrui o compilador a usar um arquivo de cabeçalho pré-compilado () existente *`.pch`* na compilação atual.

## <a name="syntax"></a>Sintaxe

> **`/Yu`**\[*nome do arquivo*]

## <a name="arguments"></a>Argumentos

*nome do arquivo*<br/>
O nome de um arquivo de cabeçalho, que é incluído no arquivo de origem usando uma `#include` diretiva de pré-processador.

## <a name="remarks"></a>Comentários

O nome do arquivo de inclusão deve ser o mesmo para a **`/Yc`** opção que cria o cabeçalho pré-compilado e para qualquer **`/Yu`** opção posterior que indica o uso do cabeçalho pré-compilado.

Para **`/Yc`** , *filename* especifica o ponto em que a pré-compilação é interrompida; o compilador pré-compila todos os códigos, embora o *nome* do arquivo, e nomeia o cabeçalho pré-compilado resultante usando o nome de base do arquivo de inclusão e uma extensão do *`.pch`* .

O *`.pch`* arquivo deve ter sido criado usando **`/Yc`** .

O compilador trata todo o código que ocorre antes do arquivo. h como pré-compilado. Ele ignora apenas além da `#include` diretiva associada ao *`.h`* arquivo, usa o código contido no *`.pch`* arquivo e, em seguida, compila todo o código após o *nome*do arquivo.

Na linha de comando, nenhum espaço é permitido entre **`/Yu`** e *filename*.

Quando você especifica a **`/Yu`** opção sem um nome de arquivo, o programa de origem deve conter um [`#pragma hdrstop`](../../preprocessor/hdrstop.md) pragma que especifica o nome do arquivo do cabeçalho pré-compilado, *`.pch`* arquivo. Nesse caso, o compilador usará o cabeçalho pré-compilado ( *`.pch`* arquivo) nomeado por [`/Fp (Name .pch file)`](fp-name-dot-pch-file.md) . O compilador pula para o local desse pragma e restaura o estado compilado do arquivo de cabeçalho pré-compilado especificado. Em seguida, ele compila apenas o código que segue o pragma. Se `#pragma hdrstop` o não especificar um nome de arquivo, o compilador procurará um arquivo com um nome derivado do nome base do arquivo de origem com uma *`.pch`* extensão. Você também pode usar a **`/Fp`** opção para especificar um *`.pch`* arquivo diferente.

Se você especificar a **`/Yu`** opção sem um nome de arquivo e falhar ao especificar um `hdrstop` pragma, uma mensagem de erro será gerada e a compilação não será bem-sucedida.

Se as **`/Yc`** opções _filename_ e **`/Yu`** _filename_ ocorrerem na mesma linha de comando e fizerem referência ao mesmo nome de arquivo, **`/Yc`** _filename_ terá precedência, Precompilando todo o código até e incluindo o arquivo nomeado. Esse recurso simplifica a gravação de makefiles.

Como os *`.pch`* arquivos contêm informações sobre o ambiente de computador e as informações de endereço de memória sobre o programa, você deve usar apenas um *`.pch`* arquivo no computador em que ele foi criado.

Para obter mais informações sobre cabeçalhos pré-compilados, consulte:

- [`/Y`(Cabeçalhos pré-compilados)](y-precompiled-headers.md)

- [Arquivos de cabeçalho pré-compilados](../creating-precompiled-header-files.md)

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Especifique [ `/Yc` (criar arquivo de cabeçalho pré-compilado)](yc-create-precompiled-header-file.md) em um arquivo. cpp em seu projeto.

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a página de propriedade de cabeçalhos pré-compilados de **Propriedades de configuração**  >  **C/C++**  >  **Precompiled Headers** .

1. Modifique a propriedade de **cabeçalho pré-compilada** , a propriedade **Criar/usar PCH por arquivo** ou a propriedade **Criar/usar cabeçalho pré-compilado** .

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Veja <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.PrecompiledHeaderThrough%2A> e <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.UsePrecompiledHeader%2A>.

## <a name="example"></a>Exemplo

Se o código a seguir:

```cpp
#include <afxwin.h>   // Include header for class library
#include "resource.h" // Include resource definitions
#include "myapp.h"    // Include information specific to this app
...
```

é compilado usando a linha de comando `CL /YuMYAPP.H PROG.CPP` , o compilador não processa as três instruções include. Em vez disso, ele usa código pré-compilado do *`MYAPP.pch`* , que economiza o tempo envolvido no pré-processamento de todos os três arquivos (e quaisquer arquivos que possam incluir).

Você pode usar a opção [`/Fp (Name .pch file)`](fp-name-dot-pch-file.md) com a **`/Yu`** opção de especificar o nome do *`.pch`* arquivo se o nome for diferente do argumento *filename* **`/Yc`** ou do nome base do arquivo de origem, como no exemplo a seguir:

```cmd
CL /YuMYAPP.H /FpMYPCH.pch PROG.CPP
```

Este comando especifica um arquivo de cabeçalho pré-compilado chamado *`MYPCH.pch`* . O compilador usa seu conteúdo para restaurar o estado pré-compilado de todos os arquivos de cabeçalho até e incluindo *`MYAPP.h`* . Em seguida, o compilador compila o código que ocorre após a `#include "MYAPP.h"` diretiva *.

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
