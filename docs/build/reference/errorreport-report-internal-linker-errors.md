---
title: /ERRORREPORT (erros de vinculador internos do relatório)
ms.date: 12/28/2017
f1_keywords:
- /ERRORREPORT
- VC.Project.VCLinkerTool.ErrorReporting
helpviewer_keywords:
- /ERRORREPORT linker option
- ERRORREPORT linker option
- -ERRORREPORT linker option
ms.assetid: f5fab595-a2f1-4eb0-ab5c-1c0fbd3d8c28
ms.openlocfilehash: 26cc157cb7247a3a2ea7c10b415df1160540c9ad
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62271723"
---
# <a name="errorreport-report-internal-linker-errors"></a>/ERRORREPORT (erros de vinculador internos do relatório)

> **/errorreport:**[ **none** | **prompt** | **queue** | **send** ]

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

1. Abra o projeto **páginas de propriedade** caixa de diálogo. Para obter mais informações, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Abra o **propriedades de configuração** > **vinculador** > **avançado** página de propriedades.

1. Modificar a **relatório de erros** propriedade.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.ErrorReporting%2A>.

## <a name="see-also"></a>Consulte também

[/errorReport (relatar erros internos do compilador)](errorreport-report-internal-compiler-errors.md)<br/>
[Referência de vinculador MSVC](linking.md)<br/>
[Opções de vinculador MSVC](linker-options.md)
