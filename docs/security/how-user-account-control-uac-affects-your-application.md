---
title: Como o controle de conta de usuário (UAC) afeta seu aplicativo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- UAC [C++]
- security [C++], User Account Control
- user accounts [C++]
- User Account Control [C++]
ms.assetid: 0d001870-253e-4989-b689-f78035953799
author: ghogen
ms.author: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 020a7a16e38ee40c99a7a5b77c88002e3135bfa1
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="how-user-account-control-uac-affects-your-application"></a>Como o Controle de Conta de Usuário (UAC) afeta o aplicativo
O UAC (Controle de Conta de Usuário) é um recurso do Windows Vista no qual as contas de usuário têm privilégios limitados. Você pode encontrar informações detalhadas sobre o UAC nestes sites:  
  
-   [Guia passo a passo do controle de conta de usuário do Windows Vista](http://go.microsoft.com/fwlink/p/?linkid=53781)  
  
-   [Diretrizes para aplicativos em um ambiente com menos privilégios e as práticas recomendadas do desenvolvedor](http://go.microsoft.com/fwlink/p/?linkid=82444)  
  
-   [Compreender e configurar o controle de conta de usuário no Windows Vista](http://go.microsoft.com/fwlink/p/?linkid=82445)  
  
## <a name="building-projects-after-enabling-uac"></a>Criando projetos após a habilitação do UAC  
 Se você criar um projeto do Visual C++ no Windows Vista com o UAC desabilitado e, posteriormente, habilitar o UAC, deverá limpar e recriar o projeto para que funcione corretamente.  
  
## <a name="applications-that-require-administrative-privileges"></a>Aplicativos que exigem privilégios de administrador  
 Por padrão, o vinculador do Visual C++ insere um fragmento do UAC no manifesto de um aplicativo com o nível de execução `asInvoker`. Se o aplicativo requer privilégios administrativos para ser executado corretamente (por exemplo, se ele altera o nó HKLM do Registro ou se grava nas áreas protegidas do disco, como o diretório do Windows), modifique seu aplicativo.  
  
 A primeira opção é modificar o fragmento UAC do manifesto para alterar o nível de execução para *requireAdministrator*. O aplicativo solicitará que o usuário forneça as credenciais administrativas para que seja executado. Para obter informações sobre como fazer isso, consulte [/MANIFESTUAC (insere informações UAC no manifesto)](../build/reference/manifestuac-embeds-uac-information-in-manifest.md).  
  
 A segunda opção é não inserir um fragmento UAC no manifesto, especificando o **/MANIFESTUAC: no** opção de vinculador. Nesse caso, o aplicativo será executado virtualizado. Todas as alterações feitas no Registro ou no sistema de arquivos não persistirão depois que o aplicativo for encerrado.  
  
 Este fluxograma descreve como o aplicativo será executado, caso o UAC esteja habilitado e caso o aplicativo tenha um manifesto do UAC:  
  
 ![Comportamento do carregador do Windows Vista](media/uacflowchart.png "UACflowchart")  
  
## <a name="see-also"></a>Consulte também  
 [Práticas Recomendadas de segurança](security-best-practices-for-cpp.md)