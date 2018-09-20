---
title: -ERRORREPORT (informar erros de vinculador internos) | Microsoft Docs
ms.custom: ''
ms.date: 12/28/2017
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /ERRORREPORT
- VC.Project.VCLinkerTool.ErrorReporting
dev_langs:
- C++
helpviewer_keywords:
- /ERRORREPORT linker option
- ERRORREPORT linker option
- -ERRORREPORT linker option
ms.assetid: f5fab595-a2f1-4eb0-ab5c-1c0fbd3d8c28
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 3b4b19eed4b481ffa44688e15fb1567e73da1a8f
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46373445"
---
# <a name="errorreport-report-internal-linker-errors"></a>/ERRORREPORT (erros de vinculador internos do relatório)

> **/errorreport:**[ **none** | **prompt** | **fila** | **enviar** ]

## <a name="arguments"></a>Arguments

**none**<br/>
Relatórios sobre erros internos do compilador não serão coletados ou enviados à Microsoft.

**prompt**<br/>
Solicita que você envie um relatório quando um erro interno do compilador for recebido. **prompt** é o padrão quando um aplicativo é compilado no ambiente de desenvolvimento.

**queue**<br/>
Enfileira o relatório de erros. Quando você fazer logon com privilégios de administrador, uma janela é exibida para que você pode relatar falhas desde a última vez em que você estivesse conectado no (você não precisará enviar relatórios de falhas mais de uma vez a cada três dias). **fila** é o padrão quando um aplicativo é compilado em um prompt de comando.

**send**<br/>
Envia automaticamente relatórios de erros do compilador interno à Microsoft se o relatório é habilitado pelas configurações de serviço de relatório de erros do Windows.

## <a name="remarks"></a>Comentários

O **/ERRORREPORT** opção permite que você forneça informações de ICE (erro) interno do compilador diretamente à Microsoft.

A opção **/errorreport: Send** envia automaticamente informações de erro à Microsoft, se habilitado pelas configurações do serviço de relatório de erros do Windows.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra o projeto **páginas de propriedade** caixa de diálogo. Para obter mais informações, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Abra o **propriedades de configuração** > **vinculador** > **avançado** página de propriedades.

1. Modificar a **relatório de erros** propriedade.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.ErrorReporting%2A>.

## <a name="see-also"></a>Consulte também

[/errorReport (relatar erros internos do compilador)](../../build/reference/errorreport-report-internal-compiler-errors.md)<br/>
[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)
