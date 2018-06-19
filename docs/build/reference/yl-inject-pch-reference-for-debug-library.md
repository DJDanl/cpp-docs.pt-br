---
title: -Yl (injetar referência PCH para biblioteca de depuração) | Microsoft Docs
ms.custom: ''
ms.date: 01/29/2018
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /yl
dev_langs:
- C++
helpviewer_keywords:
- -Yl compiler option [C++]
- Yl compiler option [C++]
- /Yl compiler option [C++]
ms.assetid: 8e4a396a-6790-4a9f-8387-df015a3220e7
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a73e79cd50343292ae63dfa831a7638d6444fc64
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32378464"
---
# <a name="yl-inject-pch-reference-for-debug-library"></a>/Yl (injetar referência PCH para biblioteca de depuração)

O **/Yl** opção gera um símbolo exclusivo em um arquivo de cabeçalho pré-compilado e uma referência neste símbolo é injetada em todos os arquivos de objeto que usam o cabeçalho pré-compilado.

## <a name="syntax"></a>Sintaxe

>**/Yl**  
>**/Yl**_name_  
>**/Yl-**  

### <a name="arguments"></a>Arguments

*name*  
Um nome opcional usado como parte do símbolo exclusivo.

*\-*  
Desabilita explicitamente a um traço (-) o **/Yl** opção de compilador.

## <a name="remarks"></a>Comentários

O **/Yl** opção de compilador cria uma definição de símbolo exclusivo em um arquivo de cabeçalho pré-compilado criado usando o [/Yc](../../build/reference/yc-create-precompiled-header-file.md) opção. Referências a este símbolo são inseridas automaticamente em todos os arquivos que incluem o cabeçalho pré-compilado usando o [/Yu](../../build/reference/yu-use-precompiled-header-file.md) opção de compilador. O **/Yl** opção é habilitada por padrão quando **/Yc** é usado para criar um arquivo de cabeçalho pré-compilado.

O **/Yl**_nome_ opção é usada para criar um símbolo de identificação no arquivo de cabeçalho pré-compilado. O compilador usa o *nome* argumento como parte do nome do símbolo decorado que cria, semelhante ao \_ \_ @@ \_PchSym\_@00@... @ *nome*, onde o cadeia de caracteres representa o botão de reticências (...) um exclusivo gerado pelo compilador. Se o *nome* argumento for omitido, o compilador gera um nome de símbolo automaticamente. Normalmente, você não precisa saber o nome do símbolo. No entanto, quando seu projeto usa mais de um arquivo de cabeçalho pré-compilado, o **/Yl**_nome_ opção pode ser útil para determinar qual objeto arquivos de uso que o cabeçalho pré-compilado. Você pode usar *nome* como uma cadeia de caracteres de pesquisa para localizar a referência de símbolo em um arquivo de despejo de memória.

**/Yl-** desativa o comportamento padrão e não coloca um símbolo de identificação no arquivo de cabeçalho pré-compilado. Arquivos compilados que incluem esse cabeçalho pré-compilado não obter uma referência de símbolo comum.

Quando **/Yc** não for especificado, qualquer **/Yl** opção não tem nenhum efeito, mas se especificado deve corresponder qualquer **/Yl** opção passados quando **/Yc** é especificado.

Se você usar **/Yl-**, **/Yc** e [/Z7](../../build/reference/z7-zi-zi-debug-information-format.md) opções para criar um arquivo de cabeçalho pré-compilado, as informações de depuração é armazenado no arquivo de objeto para o arquivo de origem usado para criar o cabeçalho pré-compilado, em vez de um arquivo. PDB separado. Se esse arquivo de objeto, em seguida, é feito a parte de uma biblioteca, [LNK1211](../../error-messages/tool-errors/linker-tools-error-lnk1211.md) erros ou [LNK4206](../../error-messages/tool-errors/linker-tools-warning-lnk4206.md) avisos podem ocorrer em compilações que usam essa biblioteca e o arquivo de cabeçalho pré-compilado, se o arquivo de origem usado para criar o arquivo de cabeçalho pré-compilado não define qualquer símbolos em si. O vinculador pode excluir o arquivo de objeto do link, junto com as informações de depuração associados, quando nada no arquivo de objeto é referenciado no cliente de biblioteca. Para resolver esse problema, especifique **/Yl** (ou remover o **/Yl-** opção) quando você usa **/Yc** para criar o arquivo de cabeçalho pré-compilado. Isso garante que o arquivo de objeto de biblioteca que contém as informações de depuração obtém vinculado em sua compilação.

Para obter mais informações sobre cabeçalhos pré-compilados, consulte:

- [/Y (cabeçalhos pré-compilados)](../../build/reference/y-precompiled-headers.md)

- [Criando arquivos de cabeçalho pré-compilado](../../build/reference/creating-precompiled-header-files.md)

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **C/C++** > **linha de comando** página de propriedades.

1. Adicionar o **/Yl**_nome_ opção de compilador no **opções adicionais** caixa. Escolha **Okey** para salvar suas alterações.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Opções do Compilador](../../build/reference/compiler-options.md)  
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)  
