---
title: "-Yl (injetar referência PCH para biblioteca de depuração) | Microsoft Docs"
ms.custom: 
ms.date: 12/04/2017
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: /yl
dev_langs: C++
helpviewer_keywords:
- -Yl compiler option [C++]
- Yl compiler option [C++]
- /Yl compiler option [C++]
ms.assetid: 8e4a396a-6790-4a9f-8387-df015a3220e7
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 6e777977f6d869d2bbc28d980f6445851e54396b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="yl-inject-pch-reference-for-debug-library"></a>/Yl (injetar referência PCH para biblioteca de depuração)

O **/Yl** opção cria um símbolo comum para um arquivo de cabeçalho pré-compilado e injeta referências a esse símbolo em todos os arquivos que usam o cabeçalho pré-compilado. Isso disponibiliza as informações de tipo completo de símbolos de cabeçalho pré-compilado para o depurador em todos os arquivos que usam o cabeçalho pré-compilado. Essa opção é habilitada por padrão. Erros de vinculador devido à ausência de informações de depuração em bibliotecas vinculadas que usam cabeçalhos pré-compilados pode impedir o uso dessa opção.

## <a name="syntax"></a>Sintaxe

>**/Yl**  
>**/Yl**_nome_  
>**/Yl-**  

### <a name="arguments"></a>Arguments

*name*  
Um nome opcional usado para definir um símbolo para arquivos armazenados e referenciada no objeto que definem ou usam o cabeçalho pré-compilado.

*\-*  
Desabilita explicitamente a um traço (-) o **/Yl** opção de compilador.

## <a name="remarks"></a>Comentários

O **/Yl** opção permite que o depurador obter informações completas sobre os tipos em um cabeçalho pré-compilado em cada arquivo que inclui o cabeçalho pré-compilado. Esta opção cria um nome de símbolo internos, injeta a definição do símbolo no arquivo de objeto usado para criar o cabeçalho pré-compilado, o [/Yc](../../build/reference/yc-create-precompiled-header-file.md) opção e insere uma referência a símbolo em todos os arquivos que incluem o pré-compilado cabeçalho usando o [/Yu](../../build/reference/yu-use-precompiled-header-file.md) opção de compilador. Como todos os arquivos de origem que usam o cabeçalho pré-compilado para fazer referência ao símbolo nomeado, o vinculador sempre vincula o arquivo de objeto que define o símbolo e o cabeçalho pré-compilado associado, as informações de depuração. Essa opção é habilitada por padrão.

O **/Yl**_nome_ opção é usada para criar explicitamente o símbolo de identificação para o arquivo de cabeçalho pré-compilado. O compilador usa o *nome* argumento para criar um símbolo semelhante a \_ \_ @@ \_PchSym\_@00@... @*nome* , onde a cadeia de caracteres representa um geradas pelo vinculador reticências (...). Se o argumento for omitido, o compilador gera automaticamente um nome de símbolo.

**/Yl-** desativa o comportamento padrão e não coloca uma identificação referência de símbolo nos arquivos de objeto que incluem o cabeçalho pré-compilado. Essa opção pode ser necessária para arquivos compilados sem o arquivo de cabeçalho pré-compilado presente.

Se você usar **/Yl-**, **/Yc** e [/Z7](../../build/reference/z7-zi-zi-debug-information-format.md) opções para criar uma biblioteca, o compilador cria um arquivo de cabeçalho pré-compilado que contém informações de depuração que são armazenadas em um arquivo de objeto em vez de um arquivo. PDB. [LNK1211](../../error-messages/tool-errors/linker-tools-error-lnk1211.md) erros ou [LNK4206](../../error-messages/tool-errors/linker-tools-warning-lnk4206.md) avisos podem ocorrer em compilações que usam essa biblioteca e o cabeçalho pré-compilado, se o arquivo de origem usado para criar o cabeçalho pré-compilado não define qualquer símbolos. O vinculador pode excluir este arquivo de objeto de biblioteca do link, junto com as informações de depuração de cabeçalho pré-compilado associado ao nada no arquivo de objeto é referenciado no cliente de biblioteca. Para resolver o problema, especifique **/Yl** quando você usa **/Yc** para criar um arquivo de cabeçalho pré-compilado e **/Yu** para usá-lo. Isso garante que o arquivo de objeto que contém as informações de depuração é incluído em sua compilação.

Para obter mais informações sobre cabeçalhos pré-compilados, consulte:

- [/Y (cabeçalhos pré-compilados)](../../build/reference/y-precompiled-headers.md)

- [Criando arquivos de cabeçalho pré-compilado](../../build/reference/creating-precompiled-header-files.md)

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Escolha o **linha de comando** página de propriedades no **C/C++** pasta.

1. Adicionar o **/Yl**_nome_ opção de compilador no **opções adicionais** caixa. Escolha **Okey** para salvar suas alterações.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Opções do Compilador](../../build/reference/compiler-options.md)  
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)  
