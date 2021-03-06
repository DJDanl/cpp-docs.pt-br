---
title: /Zg (gerar protótipos de função)
ms.date: 11/04/2016
f1_keywords:
- /zg
helpviewer_keywords:
- Zg compiler option [C++]
- /Zg compiler option [C++]
- function prototypes, generate function prototypes compiler option
- -Zg compiler option [C++]
- generate function prototypes compiler option
ms.assetid: c8df1b46-24ff-46f2-8356-e0a144b21dd2
ms.openlocfilehash: 591460b78a461aa2e33f873b79d6dcec0277f99f
ms.sourcegitcommit: 7d64c5f226f925642a25e07498567df8bebb00d4
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2019
ms.locfileid: "65446205"
---
# <a name="zg-generate-function-prototypes"></a>/Zg (gerar protótipos de função)

Removidos. Cria um protótipo de função para cada função definida no arquivo de origem, mas não compila o arquivo de origem.

## <a name="syntax"></a>Sintaxe

```
/Zg
```

## <a name="remarks"></a>Comentários

Essa opção do compilador não está mais disponível. Ele foi removido no Visual Studio 2015. Esta página permanece para usuários de versões mais antigas do Visual Studio.

O protótipo de função inclui o tipo de retorno de função e uma lista de tipo de argumento. Lista de argumentos de tipo é criada entre os tipos dos parâmetros formais da função. Qualquer protótipos de função já está presentes no arquivo de origem são ignorados.

A lista de protótipos é gravada na saída padrão. Essa lista podem ser úteis para verificar se os argumentos reais e parâmetros formais de uma função são compatíveis. Você pode salvar a lista ao redirecionar saída padrão para um arquivo. Em seguida, você pode usar **#include** para tornar a lista de protótipos de função a uma parte de seu arquivo de origem. Isso faz com que o compilador execute a verificação de tipo de argumento.

Se você usar o **/Zg** opção e o seu programa contiver parâmetros formais que têm o struct, enum, ou tipo de união (ou ponteiros para esses tipos), a declaração de cada struct, enum ou tipo de união deve ter uma marca (nome). No exemplo a seguir, o nome da marca é `MyStruct`.

```C
// Zg_compiler_option.c
// compile with: /Zg
typedef struct MyStruct { int i; } T2;
void f2(T2 * t) {}
```

O **/Zg** opção foi preterida no Visual Studio 2005 e foi removida no Visual Studio 2015. O compilador MSVC removeu o suporte para o código mais antigo, estilo C. Para obter uma lista de opções do compilador preterido, consulte **preteridos e removidos opções do compilador** na [opções de compilador listadas por categoria](compiler-options-listed-by-category.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Clique o **C/C++** pasta.

1. Clique o **linha de comando** página de propriedades.

1. Digite a opção de compilador na **opções adicionais** caixa.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
