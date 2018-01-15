---
title: "-/errorreport (erros de compilador interno de relatório) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- VC.Project.VCCLCompilerTool.ErrorReporting
- /errorreport
dev_langs: C++
helpviewer_keywords:
- /errorReport compiler option [C++]
- -errorReport compiler option [C++]
ms.assetid: 819828f8-b0a5-412c-9c57-bf822f17e667
caps.latest.revision: "21"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 9b34df09ca53441789fc90061748ad591149d6b2
ms.sourcegitcommit: 54035dce0992ba5dce0323d67f86301f994ff3db
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/03/2018
---
# <a name="errorreport-report-internal-compiler-errors"></a>/errorReport (erros de compilador internos do relatório)
Permite que você forneça informações de ICE (erro interno do compilador) diretamente à Microsoft.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/errorReport:[ none | prompt | queue | send ]  
```  
  
## <a name="arguments"></a>Arguments  
 **none**  
 Relatórios sobre erros internos do compilador não serão coletados ou enviados à Microsoft.  
  
 **prompt**  
 Solicita que você envie um relatório quando um erro interno do compilador for recebido. **prompt** é o padrão quando um aplicativo é compilado no ambiente de desenvolvimento.  
  
 **queue**  
 Enfileira o relatório de erros. Quando você faz logon com privilégios de administrador, uma janela é exibida para que você pode relatar falhas desde a última vez em que você estava logado (você não precisará enviar relatórios de falhas mais de uma vez a cada três dias). **fila** é o padrão quando um aplicativo é compilado em um prompt de comando.  
  
 **send**  
 Envia automaticamente relatórios de erros do compilador interno para a Microsoft se o relatório está habilitado pelas configurações do sistema de relatório de erros do Windows.  
  
## <a name="remarks"></a>Comentários  
 Um ICE (erro interno do compilador) ocorre quando o compilador não pode processar um arquivo de código-fonte. Quando um ICE ocorre, o compilador não produz um arquivo de saída ou qualquer diagnóstico útil que você pode usar para corrigir o código.  
  
 Nas versões anteriores, quando você obteve um ICE, era recomendado para chamar o Atendimento Microsoft para relatar o problema. Com **/errorReport**, você pode fornecer informações de ICE diretamente à Microsoft. Os relatórios de erro podem ajudar a melhorar versões futuras do compilador.  
  
 A capacidade do usuário de enviar relatórios depende das permissões de política de usuário e de computador.  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra o projeto **páginas de propriedade** caixa de diálogo. Para obter mais informações, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Clique o **C/C++** pasta.  
  
3.  Clique o **avançado** página de propriedades.  
  
4.  Modificar o **relatório de erros** propriedade.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.ErrorReporting%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)