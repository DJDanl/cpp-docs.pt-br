---
title: -WL (habilitar diagnóstico de uma linha) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /wl
dev_langs:
- C++
helpviewer_keywords:
- -WL compiler option [C++]
- /WL compiler option [C++]
- WL compiler option [C++]
ms.assetid: 332cadb4-8ea6-45fe-b67d-33ddec1f2c2e
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e82a3273673d45d1abf3ac201d7a0f63334cecbb
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45718645"
---
# <a name="wl-enable-one-line-diagnostics"></a>/WL (habilitar diagnóstico de uma linha)

Acrescenta informações adicionais para uma mensagem de aviso ou erro.

## <a name="syntax"></a>Sintaxe

```
/WL
```

## <a name="remarks"></a>Comentários

Mensagens de erro e aviso do compilador do C++ podem ser seguidas por informações adicionais que aparece, por padrão, em uma nova linha. Quando você compila da linha de comando, a linha de informações adicional pode ser anexada à mensagem de aviso ou erro. Isso pode ser desejável se você captura a saída de compilação para um arquivo de log e, em seguida, processo que o log para localizar todos os erros e avisos. Um ponto e vírgula vai separar a mensagem de aviso ou erro na linha de adicionais.

Nem todas as mensagens de erro e aviso têm uma linha adicional de informações. O código a seguir gerará um erro que tenha uma linha adicional de informações; ele permitirá que você testar o efeito quando você usa **/WL**.

```
// compiler_option_WL.cpp
// compile with: /WL
#include <queue>
int main() {
   std::queue<int> q;
   q.fromthecontinuum();   // C2039
}
```

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Clique o **C/C++** pasta.

1. Clique o **linha de comando** página de propriedades.

1. Digite a opção de compilador na **opções adicionais** caixa.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)