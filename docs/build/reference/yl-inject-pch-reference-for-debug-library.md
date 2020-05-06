---
title: /Yl (injetar referência PCH para biblioteca de depuração)
ms.date: 01/29/2018
f1_keywords:
- /yl
helpviewer_keywords:
- -Yl compiler option [C++]
- Yl compiler option [C++]
- /Yl compiler option [C++]
ms.assetid: 8e4a396a-6790-4a9f-8387-df015a3220e7
ms.openlocfilehash: 816ba66c94e616407a8891cd149a41e44e29358d
ms.sourcegitcommit: 6b749db14b4cf3a2b8d581fda6fdd8cb98bc3207
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/05/2020
ms.locfileid: "82825711"
---
# <a name="yl-inject-pch-reference-for-debug-library"></a>/Yl (injetar referência PCH para biblioteca de depuração)

A opção **/YL** gera um símbolo exclusivo em um arquivo de cabeçalho pré-compilado, e uma referência a esse símbolo é injetada em todos os arquivos de objeto que usam o cabeçalho pré-compilado.

## <a name="syntax"></a>Sintaxe

>**/YL**\
>**/Yl**_Nome_ do/YL\
>**/Yl-**

### <a name="arguments"></a>Argumentos

*name*<br/>
Um nome opcional usado como parte do símbolo exclusivo.

*\-*<br/>
Um traço (-) desabilita explicitamente a opção de compilador **/YL** .

## <a name="remarks"></a>Comentários

A opção de compilador **/YL** cria uma definição de símbolo exclusiva em um arquivo de cabeçalho pré-compilado criado usando a opção [/YC](yc-create-precompiled-header-file.md) . Referências a esse símbolo são injetadas automaticamente em todos os arquivos que incluem o cabeçalho pré-compilado usando a opção de compilador [/Yu](yu-use-precompiled-header-file.md) . A opção **/YL** é habilitada por padrão quando **/YC** é usado para criar um arquivo de cabeçalho pré-compilado.

A opção de_nome_ **/YL**é usada para criar um símbolo identificável no arquivo de cabeçalho pré-compilado. O compilador usa o argumento *Name* como parte do nome de símbolo decorado que ele cria, `__@@_PchSym_@00@...@name`semelhante a, onde as reticências (...) representam uma cadeia de caracteres exclusiva gerada pelo compilador. Se o argumento *Name* for omitido, o compilador gerará automaticamente um nome de símbolo. Normalmente, você não precisa saber o nome do símbolo. No entanto, quando o projeto usa mais de um arquivo de cabeçalho pré-compilado, a opção de_nome_ **/YL**pode ser útil para determinar quais arquivos de objeto usam qual cabeçalho pré-compilado. Você pode usar o *nome* como uma cadeia de caracteres de pesquisa para localizar a referência de símbolo em um arquivo de despejo.

**/YL-** desabilita o comportamento padrão e não coloca um símbolo de identificação no arquivo de cabeçalho pré-compilado. Os arquivos compilados que incluem esse cabeçalho pré-compilado não obtêm uma referência de símbolo comum.

Quando **/YC** não for especificado, qualquer opção de **/YL** não terá nenhum efeito, mas se especificado, ele deverá corresponder a qualquer opção de **/YL** passada quando **/YC** for especificado.

Se você usar as opções **/YL-**, **/YC** e [/Z7](z7-zi-zi-debug-information-format.md) para criar um arquivo de cabeçalho pré-compilado, as informações de depuração serão armazenadas no arquivo de objeto para o arquivo de origem usado para criar o cabeçalho pré-compilado, em vez de um arquivo. pdb separado. Se esse arquivo de objeto, em seguida, fizer parte de uma biblioteca, erros de [LNK1211](../../error-messages/tool-errors/linker-tools-error-lnk1211.md) ou avisos de [LNK4206](../../error-messages/tool-errors/linker-tools-warning-lnk4206.md) poderão ocorrer em compilações que usam essa biblioteca e o arquivo de cabeçalho pré-compilado, se o arquivo de origem usado para criar o arquivo de cabeçalho pré-compilado não definir nenhum próprio símbolo. O vinculador pode excluir o arquivo de objeto do link, juntamente com as informações de depuração associadas, quando nada no arquivo de objeto for referenciado no cliente de biblioteca. Para resolver esse problema, especifique **/YL** (ou remova a opção **/YL-** ) ao usar o **/YC** para criar o arquivo de cabeçalho pré-compilado. Isso garante que o arquivo de objeto da biblioteca que contém as informações de depuração é vinculado em seu Build.

Para obter mais informações sobre cabeçalhos pré-compilados, consulte:

- [/Y (cabeçalhos pré-compilados)](y-precompiled-headers.md)

- [Arquivos de cabeçalho pré-compilados](../creating-precompiled-header-files.md)

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a página de propriedade de**linha de comando** **C/C++** >  **Propriedades** > de configuração.

1. Adicione a opção **/YL**_Name_ Compiler na caixa de **Opções adicionais** . Escolha **OK** para salvar suas alterações.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Confira também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
