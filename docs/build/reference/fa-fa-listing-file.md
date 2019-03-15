---
title: /FA, /Fa (listando arquivo)
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCCLWCECompilerTool.AssemblerListingLocation
- VC.Project.VCCLCompilerTool.ConfigureASMListing
- VC.Project.VCCLWCECompilerTool.AssemblerOutput
- VC.Project.VCCLCompilerTool.AssemblerListingLocation
- /fa
- VC.Project.VCCLCompilerTool.AssemblerOutput
- VC.Project.VCCLCompilerTool.UseUnicodeForAssemblerListing
helpviewer_keywords:
- FA compiler option [C++]
- /FA compiler option [C++]
- -FA compiler option [C++]
- listing file type
- assembly-only listing
ms.assetid: c7507d0e-c69d-44f9-b8e2-d2c398697402
ms.openlocfilehash: b78704ea12365d9e10222d75c6807517f7cdb893
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57812506"
---
# <a name="fa-fa-listing-file"></a>/FA, /Fa (listando arquivo)

Cria um arquivo de listagem que contém o código de montador.

## <a name="syntax"></a>Sintaxe

> **/FA**[**c**\][**s**\][**u**] **/Fa**_pathname_

## <a name="remarks"></a>Comentários

O **/FA** opção de compilador gera um arquivo de listagem do assembler para cada unidade de tradução na compilação, que geralmente corresponde a um arquivo de origem C ou C++. Por padrão, somente o assembler está incluído no arquivo de listagem, que é codificado como ANSI. Opcional **c**, **s**, e **u** argumentos a serem **/FA** controle se código de máquina ou código-fonte são saída junto com o assembler listagem, e se a listagem é codificada como UTF-8.

Por padrão, cada arquivo de listagem obtém o mesmo nome base que o arquivo de origem e tem uma extensão. ASM. Quando o código de máquina está incluído com o uso de **c** opção, o arquivo de listagem tem uma extensão. Cod. Você pode alterar o nome e a extensão do arquivo de listagem e o diretório onde ele é criado usando o **/Fa** opção.

### <a name="fa-arguments"></a>/FA argumentos

nenhum<br/>
Somente o idioma assembler está incluído na lista.

**c**<br/>
Opcional. Inclui o código de máquina na listagem.

**s**<br/>
Opcional. Inclui código-fonte na lista.

**u**<br/>
Opcional. Codifica o arquivo de listagem em formato UTF-8 e inclui um marcador de ordem de byte. Por padrão, o arquivo é codificado como ANSI. Use `u` para criar um arquivo de listagem que exibe corretamente em qualquer sistema, ou se você estiver usando Unicode de arquivos de código de origem como entrada para o compilador.

Se os dois **s** e **u** são especificados e se uma fonte de arquivo de código usa uma codificação Unicode diferente de UTF-8, em seguida, as linhas de código no arquivo. ASM talvez não sejam exibidos corretamente.

### <a name="fa-argument"></a>/FA argumento

nenhum<br/>
Uma *origem*arquivo. ASM é criado para cada arquivo de código fonte na compilação.

*filename*<br/>
Um arquivo de listagem denominado *filename*. ASM é colocado no diretório atual. Isso só é válido durante a compilação de um arquivo de código fonte único.

*filename.extension*<br/>
Um arquivo de listagem denominado *filename.extension* é colocado no diretório atual. Isso só é válido durante a compilação de um arquivo de código fonte único.

*directory*__\\__<br/>
Uma *arquivo_de_origem*arquivo. ASM é criado e colocado no especificado *diretório* para cada arquivo de código do código-fonte na compilação. Observe a barra invertida necessária. São permitidos apenas os caminhos do disco atual.

*directory*__\\__*filename*<br/>
Um arquivo de listagem chamado *filename*ASM é colocado especificado *diretório*. Isso só é válido durante a compilação de um arquivo de código fonte único.

*directory*__\\__*filename.extension*<br/>
Um arquivo de listagem chamado *filename.extension* é colocado no especificado *diretório*. Isso só é válido durante a compilação de um arquivo de código fonte único.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **C/C++** > **arquivos de saída** página de propriedades.

1. Modificar a **saída do Assembler** propriedade para definir o **/FAc** e **/FAs** opções de assembler, máquina e código-fonte. Modificar a **usar Unicode para listagem de montador** propriedade para definir o **/FAu** opção para a saída de ANSI ou UTF-8. Modificar a **local da lista ASM** para definir o **/Fa** opção para listar o nome de arquivo e o local.

Observe que definir ambos **saída do Assembler** e **usar Unicode para listagem de montador** propriedades podem causar [D9025 de aviso de linha de comando](../../error-messages/tool-errors/command-line-warning-d9025.md). Para combinar essas opções no IDE, use o **opções adicionais** campo o **linha de comando** em vez disso, a página de propriedades.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AssemblerListingLocation%2A> ou <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AssemblerOutput%2A>. Para especificar **/FAu**, consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="example"></a>Exemplo

A linha de comando a seguir produz uma fonte combinada e listagem de código de computador chamado HELLO.cod:

```cmd
CL /FAcs HELLO.CPP
```

## <a name="see-also"></a>Consulte também

[Opções do arquivo de saída (/F)](output-file-f-options.md)<br/>
[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)<br/>
[Especificando o nome de caminho](specifying-the-pathname.md)
