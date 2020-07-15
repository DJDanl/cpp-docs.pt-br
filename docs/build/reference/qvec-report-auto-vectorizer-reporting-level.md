---
title: /Qvec-report (nível de relatórios do vetorizador automático)
ms.date: 11/04/2016
ms.assetid: 4778c9a3-0692-4085-9b05-1bfeadf4c74a
ms.openlocfilehash: 260cf89d50110f960eb6f320dccbb4a1d80f65bc
ms.sourcegitcommit: 31a443c9998cf5cfbaff00fcf815b133f55b2426
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/14/2020
ms.locfileid: "86373808"
---
# <a name="qvec-report-auto-vectorizer-reporting-level"></a>/Qvec-report (nível de relatórios do vetorizador automático)

Habilita o recurso de relatório do compilador [Vetorizador automático automaticamente](../../parallel/auto-parallelization-and-auto-vectorization.md) e especifica o nível de mensagens informativas para saída durante a compilação.

## <a name="syntax"></a>Sintaxe

```
/Qvec-report:{1}{2}
```

## <a name="remarks"></a>Comentários

**/Qvec-Report: 1**<br/>
Gera uma mensagem informativa para loops que são vetorizados.

**/Qvec-Report: 2**<br/>
Gera uma mensagem informativa para loops que são vetorizados e para loops que não são vetorizados, juntamente com um código de motivo.

Para obter informações sobre códigos de motivo e mensagens, consulte [mensagens vetorizador automático e paralelizador automático](../../error-messages/tool-errors/vectorizer-and-parallelizer-messages.md).

### <a name="to-set-the-qvec-report-compiler-option-in-visual-studio"></a>Para definir a opção de compilador/Qvec-Report no Visual Studio

1. No **Gerenciador de soluções**, abra o menu de atalho do projeto e, em seguida, escolha **Propriedades**.

1. Na caixa de diálogo **páginas de propriedades** , em **C/C++**, selecione **linha de comando**.

1. Na caixa **Opções adicionais** , digite `/Qvec-report:1` ou `/Qvec-report:2` .

### <a name="to-set-the-qvec-report-compiler-option-programmatically"></a>Para definir a opção de compilador/Qvec-Report programaticamente

- Use o exemplo de código em <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Confira também

[Opções de/q (operações de nível baixo)](q-options-low-level-operations.md)<br/>
[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)<br/>
[Vetorização de código nativo no Visual Studio](https://docs.microsoft.com/archive/blogs/nativeconcurrency/auto-vectorizer-in-visual-studio-2012-overview)
