---
title: Erro de Build prj0003 no projeto | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- PRJ0003
dev_langs:
- C++
helpviewer_keywords:
- PRJ0003
ms.assetid: fc5a84bb-c6d3-41d6-8dd6-475455820778
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: bcf80eb4d45fe1ae163772b96339c123996ae377
ms.sourcegitcommit: 54035dce0992ba5dce0323d67f86301f994ff3db
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/03/2018
---
# <a name="project-build-error-prj0003"></a>Erro de Build PRJ0003 no Projeto  
  
> Erro ao gerar '*linha de comando*'.  
  
O *linha de comando* comando formado de entrada no **páginas de propriedade** caixa de diálogo retornou um código de erro, mas nenhuma informação será exibida no **saída** janela.  

Os motivos possíveis para esse erro incluem:  
  
-   Seu projeto depende do servidor ATL. A partir do Visual Studio 2008, servidor ATL não é incluído como parte do Visual Studio, mas foi lançado como um projeto de código-fonte compartilhado no CodePlex. Para baixar as ferramentas e o código-fonte ATL Server, vá para [biblioteca do ATL Server e as ferramentas](http://go.microsoft.com/fwlink/p/?linkid=81979).  
  
-   Recursos insuficientes do sistema. Feche alguns aplicativos para resolver o problema.  
  
-   Privilégios de segurança insuficientes. Verifique se você tem privilégios suficientes.  
  
-   Executável caminhos especificados na **diretórios VC + +** não inclua o caminho para a ferramenta que você está tentando executar. Para obter informações, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md)  
  
-   Para projetos de makefile, você não tem um comando para executar em **criar linha de comando** ou **recriar a linha de comando**.  
  
## <a name="see-also"></a>Consulte também  
 [Erros e avisos de build do projeto (PRJxxxx)](../../error-messages/tool-errors/project-build-errors-and-warnings-prjxxxx.md)