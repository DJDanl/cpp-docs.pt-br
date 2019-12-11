---
title: /WL (habilitar diagnóstico de uma linha)
ms.date: 11/04/2016
f1_keywords:
- /wl
helpviewer_keywords:
- -WL compiler option [C++]
- /WL compiler option [C++]
- WL compiler option [C++]
ms.assetid: 332cadb4-8ea6-45fe-b67d-33ddec1f2c2e
ms.openlocfilehash: b1ded1cd18eb75ed47b76c1353ad82a7fa497ba9
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74988570"
---
# <a name="wl-enable-one-line-diagnostics"></a>/WL (habilitar diagnóstico de uma linha)

Anexa informações adicionais a uma mensagem de erro ou de aviso.

## <a name="syntax"></a>Sintaxe

```
/WL
```

## <a name="remarks"></a>Comentários

Mensagens de erro e de aviso C++ do compilador podem ser seguidas por informações adicionais que aparecem, por padrão, em uma nova linha. Quando você compila a partir da linha de comando, a linha adicional de informações pode ser acrescentada à mensagem de erro ou de aviso. Isso pode ser desejável se você capturar a saída da compilação para um arquivo de log e, em seguida, processar esse log para localizar todos os erros e avisos. Um ponto e vírgula irá separar o erro ou a mensagem de aviso da linha adicional.

Nem todas as mensagens de erro e de aviso têm uma linha adicional de informações. O código a seguir gerará um erro que tem uma linha adicional de informações; Ele permitirá que você teste o efeito ao usar o **/WL**.

```cpp
// compiler_option_WL.cpp
// compile with: /WL
#include <queue>
int main() {
   std::queue<int> q;
   q.fromthecontinuum();   // C2039
}
```

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Clique na pasta **CC++ /** .

1. Clique na página de propriedades de **linha de comando** .

1. Digite a opção do compilador na caixa **Opções adicionais** .

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
