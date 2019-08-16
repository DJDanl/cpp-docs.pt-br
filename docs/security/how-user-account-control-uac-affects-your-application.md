---
title: Como o Controle de Conta de Usuário (UAC) afeta o aplicativo
ms.date: 11/19/2018
helpviewer_keywords:
- UAC [C++]
- security [C++], User Account Control
- user accounts [C++]
- User Account Control [C++]
ms.assetid: 0d001870-253e-4989-b689-f78035953799
ms.openlocfilehash: 8c283e86a71092bb510892b6361f3d0fddc2abb6
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69510149"
---
# <a name="how-user-account-control-uac-affects-your-application"></a>Como o Controle de Conta de Usuário (UAC) afeta o aplicativo

O UAC (Controle de Conta de Usuário) é um recurso do Windows Vista no qual as contas de usuário têm privilégios limitados. Você pode encontrar informações detalhadas sobre o UAC nestes sites:

- [Práticas recomendadas e diretrizes do desenvolvedor para aplicativos em um ambiente com privilégios mínimos](/windows/win32/uxguide/winenv-uac)

## <a name="building-projects-after-enabling-uac"></a>Criando projetos após a habilitação do UAC

Se você criar um projeto do C++ Visual Studio no Windows Vista com o UAC desabilitado e posteriormente habilitar o UAC, você deverá limpar e recompilar o projeto para que ele funcione corretamente.

## <a name="applications-that-require-administrative-privileges"></a>Aplicativos que exigem privilégios de administrador

Por padrão, o vinculador Visual C++ insere um fragmento UAC no manifesto de um aplicativo com um nível de execução de. `asInvoker` Se o aplicativo requer privilégios administrativos para ser executado corretamente (por exemplo, se ele altera o nó HKLM do Registro ou se grava nas áreas protegidas do disco, como o diretório do Windows), modifique seu aplicativo.

A primeira opção é modificar o fragmento do UAC do manifesto para alterar o nível de execução para *requireAdministrator*. O aplicativo solicitará que o usuário forneça as credenciais administrativas para que seja executado. Para obter informações sobre como fazer isso, consulte [/MANIFESTUAC (insere informações do UAC no manifesto)](../build/reference/manifestuac-embeds-uac-information-in-manifest.md).

A segunda opção é não inserir um fragmento do UAC no manifesto especificando a opção `/MANIFESTUAC:NO` do vinculador. Nesse caso, o aplicativo será executado virtualizado. Todas as alterações feitas no Registro ou no sistema de arquivos não persistirão depois que o aplicativo for encerrado.

Este fluxograma descreve como o aplicativo será executado, caso o UAC esteja habilitado e caso o aplicativo tenha um manifesto do UAC:

![Comportamento do carregador do Windows](media/uacflowchart.png "Comportamento do carregador do Windows")

## <a name="see-also"></a>Consulte também

[Práticas Recomendadas de segurança](security-best-practices-for-cpp.md)
