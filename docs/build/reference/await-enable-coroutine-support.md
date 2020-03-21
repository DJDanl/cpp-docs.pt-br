---
title: /await (habilitar suporte de corrotina)
ms.date: 08/15/2017
f1_keywords:
- /await
- -await
helpviewer_keywords:
- /await enable coroutine support [C++]
- -await enable coroutine support [C++]
- await enable coroutine support [C++]
ms.assetid: 302c8e69-09b6-4c58-bcdd-0a6a8713a8df
ms.openlocfilehash: eeab3f4a1afc73e341f04222a55c8ce429490742
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80078444"
---
# <a name="await-enable-coroutine-support"></a>/await (habilitar suporte de corrotina)

Use a opção de compilador **/Await** para habilitar o suporte do compilador para corrotinas.

## <a name="syntax"></a>Sintaxe

> /await

## <a name="remarks"></a>Comentários

A opção de compilador **/Await** habilita o suporte C++ do compilador para corrotinas e as palavras-chave **co_await**, **co_yield**e **co_return**. Essa opção fica desativada por padrão. Para obter informações sobre o suporte para corrotinas no Visual Studio, consulte o [blog da equipe do Visual Studio](https://blogs.msdn.microsoft.com/vcblog/category/coroutine/). Para obter mais informações sobre a proposta padrão de corrotinas, consulte [rascunho de trabalho do N4628 C++ , especificação técnica para extensões de corrotinas](https://wg21.link/n4628).

A opção **/Await** está disponível a partir do Visual Studio 2015.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **páginas de propriedades** do projeto.

1. Em **Propriedades de configuração**, expanda a pasta **CC++ /** e escolha a página de propriedades de **linha de comando** .

1. Insira a opção do compilador **/Await** na caixa **Opções adicionais** . Escolha **OK** ou **aplicar** para salvar suas alterações.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Confira também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
