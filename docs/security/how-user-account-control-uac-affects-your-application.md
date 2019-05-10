---
title: Como o Controle de Conta de Usuário (UAC) afeta o aplicativo
ms.date: 11/19/2018
helpviewer_keywords:
- UAC [C++]
- security [C++], User Account Control
- user accounts [C++]
- User Account Control [C++]
ms.assetid: 0d001870-253e-4989-b689-f78035953799
ms.openlocfilehash: 3818b0ff7d4e4c551c41726dd44935beb5d32842
ms.sourcegitcommit: 7d64c5f226f925642a25e07498567df8bebb00d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2019
ms.locfileid: "65448479"
---
# <a name="how-user-account-control-uac-affects-your-application"></a>Como o Controle de Conta de Usuário (UAC) afeta o aplicativo

O UAC (Controle de Conta de Usuário) é um recurso do Windows Vista no qual as contas de usuário têm privilégios limitados. Você pode encontrar informações detalhadas sobre o UAC nestes sites:

- [Desenvolvedor de práticas recomendadas e diretrizes para aplicativos em um ambiente com privilégios mínimos](/windows/desktop/uxguide/winenv-uac)

## <a name="building-projects-after-enabling-uac"></a>Criando projetos após a habilitação do UAC

Se você criar um Visual Studio C++ project no Windows Vista com UAC desabilitado e, posteriormente, habilitar o UAC, você deve limpar e recompilar o projeto para que ele funcione corretamente.

## <a name="applications-that-require-administrative-privileges"></a>Aplicativos que exigem privilégios de administrador

Por padrão, o vinculador do Visual C++ insere um fragmento do UAC no manifesto de um aplicativo com um nível de execução de `asInvoker`. Se o aplicativo requer privilégios administrativos para ser executado corretamente (por exemplo, se ele altera o nó HKLM do Registro ou se grava nas áreas protegidas do disco, como o diretório do Windows), modifique seu aplicativo.

A primeira opção é modificar o fragmento do UAC do manifesto para alterar o nível de execução para *requireAdministrator*. O aplicativo solicitará que o usuário forneça as credenciais administrativas para que seja executado. Para obter informações sobre como fazer isso, consulte [/MANIFESTUAC (insere informações UAC no manifesto)](../build/reference/manifestuac-embeds-uac-information-in-manifest.md).

A segunda opção é não inserir um fragmento do UAC no manifesto especificando a opção `/MANIFESTUAC:NO` do vinculador. Nesse caso, o aplicativo será executado virtualizado. Todas as alterações feitas no Registro ou no sistema de arquivos não persistirão depois que o aplicativo for encerrado.

Este fluxograma descreve como o aplicativo será executado, caso o UAC esteja habilitado e caso o aplicativo tenha um manifesto do UAC:

![Comportamento do carregador do Windows](media/uacflowchart.png "comportamento do carregador do Windows")

## <a name="see-also"></a>Consulte também

[Práticas Recomendadas de segurança](security-best-practices-for-cpp.md)
