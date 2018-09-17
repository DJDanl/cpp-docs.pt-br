---
title: -Qvec-report (nível de relatórios do Vetorizador automático) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
dev_langs:
- C++
ms.assetid: 4778c9a3-0692-4085-9b05-1bfeadf4c74a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c11beb3f8a5b9b189fff237012580765f8858fc0
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45717555"
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

[/Q opções (operações de nível baixo)](../../build/reference/q-options-low-level-operations.md)
[opções do compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)<br/>
[Programação paralela em código nativo](https://blogs.msdn.microsoft.com/nativeconcurrency/2012/04/12/auto-vectorizer-in-visual-studio-2012-overview/)