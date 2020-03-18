---
title: /errorReport (erros de compilador internos do relatório)
description: Referência para a opção de linhaC++ de comando/errorreport do Microsoft C/Compiler.
ms.date: 02/09/2020
f1_keywords:
- VC.Project.VCCLCompilerTool.ErrorReporting
helpviewer_keywords:
- /errorReport compiler option [C++]
- -errorReport compiler option [C++]
ms.assetid: 819828f8-b0a5-412c-9c57-bf822f17e667
ms.openlocfilehash: afc366728e62029ffbd3993e2fdd740e3aaf3369
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79439891"
---
# <a name="errorreport-report-internal-compiler-errors"></a>/errorReport (erros de compilador internos do relatório)

> [!NOTE]
> A opção **/errorreport** é preterida. A partir do Windows Vista, o relatório de erros é controlado pelas configurações [do relatório de erros do Windows (WER)](/windows/win32/wer/windows-error-reporting) .

## <a name="syntax"></a>Sintaxe

> **/errorreport:** \[**None** \| **prompt** de \| **fila** \| **Enviar** )

## <a name="remarks"></a>Comentários

Um erro de compilador interno (ICE) resulta quando o compilador não pode processar um arquivo de código-fonte. Quando ocorre uma ICE, o compilador não produz um arquivo de saída ou qualquer diagnóstico útil que você possa usar para corrigir seu código.

Os argumentos **/errorreport** são substituídos pelas configurações do serviço relatório de erros do Windows. O compilador envia automaticamente relatórios de erros internos à Microsoft, se os relatórios estiverem habilitados pelo Relatório de Erros do Windows. Nenhum relatório será enviado se for desabilitado pelo Relatório de Erros do Windows.


### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter mais informações, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Abra as **Propriedades de configuração** > página de propriedades **avançado** **CC++ /**  > .

1. Modifique a propriedade **relatório de erros** .

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.ErrorReporting%2A>.

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)\
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
