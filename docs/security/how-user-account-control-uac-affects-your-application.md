---
title: Como o controle de conta de usuário (UAC) afeta o aplicativo | Microsoft Docs
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
ms.openlocfilehash: 91c5af565ac7de14d947f2376ae408caa0f890fe
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40013571"
---
# <a name="how-user-account-control-uac-affects-your-application"></a>Como o Controle de Conta de Usuário (UAC) afeta o aplicativo
O UAC (Controle de Conta de Usuário) é um recurso do Windows Vista no qual as contas de usuário têm privilégios limitados. Você pode encontrar informações detalhadas sobre o UAC nestes sites:  
  
-   [Guia passo a passo do controle de conta de usuário do Windows Vista](http://go.microsoft.com/fwlink/p/?linkid=53781)  
  
-   [Desenvolvedor de práticas recomendadas e diretrizes para aplicativos em um ambiente com privilégios mínimos](http://go.microsoft.com/fwlink/p/?linkid=82444)  
  
-   [Compreendendo e configurando o controle de conta de usuário no Windows Vista](http://go.microsoft.com/fwlink/p/?linkid=82445)  
  
## <a name="building-projects-after-enabling-uac"></a>Criando projetos após a habilitação do UAC  
 Se você criar um projeto do Visual C++ no Windows Vista com o UAC desabilitado e, posteriormente, habilitar o UAC, deverá limpar e recriar o projeto para que funcione corretamente.  
  
## <a name="applications-that-require-administrative-privileges"></a>Aplicativos que exigem privilégios de administrador  
 Por padrão, o vinculador do Visual C++ insere um fragmento do UAC no manifesto de um aplicativo com o nível de execução `asInvoker`. Se o aplicativo requer privilégios administrativos para ser executado corretamente (por exemplo, se ele altera o nó HKLM do Registro ou se grava nas áreas protegidas do disco, como o diretório do Windows), modifique seu aplicativo.  
  
 A primeira opção é modificar o fragmento do UAC do manifesto para alterar o nível de execução para *requireAdministrator*. O aplicativo solicitará que o usuário forneça as credenciais administrativas para que seja executado. Para obter informações sobre como fazer isso, consulte [/MANIFESTUAC (insere informações UAC no manifesto)](../build/reference/manifestuac-embeds-uac-information-in-manifest.md).  
  
 A segunda opção é não inserir um fragmento do UAC no manifesto especificando a opção `/MANIFESTUAC:NO` do vinculador. Nesse caso, o aplicativo será executado virtualizado. Todas as alterações feitas no Registro ou no sistema de arquivos não persistirão depois que o aplicativo for encerrado.  
  
 Este fluxograma descreve como o aplicativo será executado, caso o UAC esteja habilitado e caso o aplicativo tenha um manifesto do UAC:  
  
 ![Comportamento do carregador do Windows Vista](media/uacflowchart.png "UACflowchart")  
  
## <a name="see-also"></a>Consulte também  
 [Práticas Recomendadas de segurança](security-best-practices-for-cpp.md)