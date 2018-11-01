---
title: /Qvec-report (nível de relatórios do vetorizador automático)
ms.date: 11/04/2016
ms.assetid: 4778c9a3-0692-4085-9b05-1bfeadf4c74a
ms.openlocfilehash: dc8c1d3bc65b0160fd489f1cdebe06e4fc9a0992
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50590223"
---
# <a name="qvec-report-auto-vectorizer-reporting-level"></a>/Qvec-report (nível de relatórios do vetorizador automático)

Habilita o recurso de relatório do compilador [Vetorizador automático](../../parallel/auto-parallelization-and-auto-vectorization.md) e especifica o nível de mensagens informativas de saída durante a compilação.

## <a name="syntax"></a>Sintaxe

```
/Qvec-report:{1}{2}
```

## <a name="remarks"></a>Comentários

**/ Qvec-report: 1**<br/>
Gera uma mensagem informativa para loops que são vetorizado.

**/Qvec--2 do relatório:**<br/>
Gera uma mensagem informativa para loops que são vetorizados e loops não vetorizados, junto com um código de motivo.

Para obter informações sobre códigos de motivo e mensagens, consulte [mensagens do Vetorizador e Paralelizador](../../error-messages/tool-errors/vectorizer-and-parallelizer-messages.md).

### <a name="to-set-the-qvec-report-compiler-option-in-visual-studio"></a>Para definir a opção de compilador /Qvec-report no Visual Studio

1. No **Gerenciador de Soluções**, abra o menu de atalho para o projeto e escolha **Propriedades**.

1. No **páginas de propriedades** caixa de diálogo **C/C++**, selecione **linha de comando**.

1. No **opções adicionais** , digite `/Qvec-report:1` ou `/Qvec-report:2`.

### <a name="to-set-the-qvec-report-compiler-option-programmatically"></a>Para definir a opção de compilador /Qvec-report programaticamente

- Use o exemplo de código em <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Opções /Q (operações de nível baixo)](../../build/reference/q-options-low-level-operations.md)<br/>
[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)<br/>
[Programação paralela em código nativo](https://blogs.msdn.microsoft.com/nativeconcurrency/2012/04/12/auto-vectorizer-in-visual-studio-2012-overview/)