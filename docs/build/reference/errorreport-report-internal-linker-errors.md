---
title: "-/ERRORREPORT (erros de vinculador internos do relatório) | Microsoft Docs"
ms.custom: 
ms.date: 12/28/2017
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
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
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 6ddf65ed2a17dae2d86b0dc4582f1d3158328898
ms.sourcegitcommit: 54035dce0992ba5dce0323d67f86301f994ff3db
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/03/2018
---
# <a name="errorreport-report-internal-linker-errors"></a>/ERRORREPORT (erros de vinculador internos do relatório)

> **/errorreport:**[ **nenhum** | **prompt** | **fila** | **enviar** ]

## <a name="arguments"></a>Arguments

**none**  
Relatórios sobre erros internos do compilador não serão coletados ou enviados à Microsoft.

**prompt**  
Solicita que você envie um relatório quando um erro interno do compilador for recebido. **prompt** é o padrão quando um aplicativo é compilado no ambiente de desenvolvimento.

**queue**  
Enfileira o relatório de erros. Quando você faz logon com privilégios de administrador, uma janela é exibida para que você pode relatar falhas desde a última vez em que você estava logado (você não precisará enviar relatórios de falhas mais de uma vez a cada três dias). **fila** é o padrão quando um aplicativo é compilado em um prompt de comando.

**send**  
Envia automaticamente relatórios de erros do compilador interno para a Microsoft se o relatório está habilitado pelas configurações de serviço de relatório de erros do Windows.

## <a name="remarks"></a>Comentários

O **/ERRORREPORT** opção permite que você forneça informações de erro (ICE) interno do compilador diretamente à Microsoft.

A opção **/errorreport: Send** envia automaticamente informações de erro à Microsoft, se habilitado pelas configurações do serviço de relatório de erros do Windows.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra o projeto **páginas de propriedade** caixa de diálogo. Para obter mais informações, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Abra o **propriedades de configuração** > **vinculador** > **avançado** página de propriedades.

1. Modificar o **relatório de erros** propriedade.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.ErrorReporting%2A>.

## <a name="see-also"></a>Consulte também

[/errorReport (relatório de erros do compilador interno)](../../build/reference/errorreport-report-internal-compiler-errors.md)  
[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)  
[Opções do vinculador](../../build/reference/linker-options.md)  
