---
title: -errorReport (relatar erros do compilador interno) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCCLCompilerTool.ErrorReporting
- /errorreport
dev_langs:
- C++
helpviewer_keywords:
- /errorReport compiler option [C++]
- -errorReport compiler option [C++]
ms.assetid: 819828f8-b0a5-412c-9c57-bf822f17e667
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0c96225e566593987bef8ec9a82c73daacfcefb6
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45720103"
---
# <a name="errorreport-report-internal-compiler-errors"></a>/errorReport (erros de compilador internos do relatório)

Permite que você forneça informações de ICE (erro interno do compilador) diretamente à Microsoft.

## <a name="syntax"></a>Sintaxe

```
/errorReport:[ none | prompt | queue | send ]
```

## <a name="arguments"></a>Arguments

**none**<br/>
Relatórios sobre erros internos do compilador não serão coletados ou enviados à Microsoft.

**prompt**<br/>
Solicita que você envie um relatório quando um erro interno do compilador for recebido. **prompt** é o padrão quando um aplicativo é compilado no ambiente de desenvolvimento.

**queue**<br/>
Enfileira o relatório de erros. Quando você fazer logon com privilégios de administrador, uma janela é exibida para que você pode relatar falhas desde a última vez em que você estivesse conectado no (você não precisará enviar relatórios de falhas mais de uma vez a cada três dias). **fila** é o padrão quando um aplicativo é compilado em um prompt de comando.

**send**<br/>
Envia automaticamente relatórios de erros do compilador interno à Microsoft se o relatório é habilitado pelas configurações do sistema de relatório de erros do Windows.

## <a name="remarks"></a>Comentários

Um ICE (erro interno do compilador) ocorre quando o compilador não pode processar um arquivo de código-fonte. Quando um ICE ocorre, o compilador não produz um arquivo de saída ou qualquer diagnóstico útil que você pode usar para corrigir o código.

Em versões anteriores, quando você obteve um ICE, era incentivado a chamar o Microsoft Product Support Services para relatar o problema. Com o **/errorReport**, você pode fornecer informações de ICE diretamente à Microsoft. Os relatórios de erro podem ajudar a melhorar versões futuras do compilador.

A capacidade do usuário de enviar relatórios depende das permissões de política de usuário e de computador.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra o projeto **páginas de propriedade** caixa de diálogo. Para obter mais informações, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Clique o **C/C++** pasta.

1. Clique o **avançado** página de propriedades.

1. Modificar a **relatório de erros** propriedade.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.ErrorReporting%2A>.

## <a name="see-also"></a>Consulte também

[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)