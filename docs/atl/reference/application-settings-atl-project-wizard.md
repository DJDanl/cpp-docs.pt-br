---
title: Configurações do aplicativo, ATL Project Wizard
ms.date: 11/04/2016
f1_keywords:
- vc.appwiz.atl.com.appset
helpviewer_keywords:
- ATL Project Wizard, application settings
ms.assetid: d48c9fc5-f439-49fd-884c-8bcfa7d52991
ms.openlocfilehash: bd9d5c6ef1ccb86f2968b1e2d2706092b6db45e9
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62248994"
---
# <a name="application-settings-atl-project-wizard"></a>Configurações do aplicativo, ATL Project Wizard

Use o **configurações do aplicativo** página do Assistente de projeto da ATL para criar e adicionar recursos básicos para um novo projeto ATL.

## <a name="server-type"></a>Tipo de servidor

Escolha um dos três tipos de servidor:

- **Biblioteca de vínculo dinâmico (DLL)**

   Selecione para criar um servidor em processo.

- **Executável (EXE)**

   Selecione para criar um servidor local do out-of-process. Essa opção não permite o suporte para MFC ou COM+ 1.0. Ele não permite a mesclagem de código de proxy/stub.

- **Serviço (EXE)**

   Selecione para criar um aplicativo do Windows que é executado em segundo plano quando o Windows é iniciado. Essa opção não permite o suporte para MFC ou COM+ 1.0 ou não permite a mesclagem de código de proxy/stub.

## <a name="additional-options"></a>Opções adicionais

> [!NOTE]
> Todas as opções adicionais estão disponíveis para apenas os projetos DLL.

- **Permitir mesclagem do código de proxy/stub**

   Selecione o **Permitir mesclagem do código de proxy/stub** caixa de seleção como uma conveniência ao marshaling de interfaces é necessária. Essa opção coloca o código de proxy e stub gerado pelo MIDL no mesmo executável como o servidor.

- **Suporte MFC**

   Selecione esta opção para especificar que seu objeto inclui suporte do MFC. Esta opção vincula seu projeto para as bibliotecas MFC para que você possa acessar qualquer uma das classes e funções que eles contêm.

- **Suporte a COM+ 1.0**

   Selecione esta opção para modificar as configurações de build do projeto para dar suporte a componentes COM+ 1.0. Além da lista padrão de bibliotecas, o assistente adiciona o comsvcs.lib de biblioteca específico do componente COM+ 1.0

   Além disso, o mtxex.dll é atrasar carregada no sistema host, quando seu aplicativo é iniciado.

- **Registrador de componentes de suporte**

   Se seu projeto ATL contém suporte para componentes COM+ 1.0, você pode definir essa opção. O registrador de componentes permite que seu objeto COM+ 1.0 obter uma lista de componentes, componentes de registrar ou cancelar o registro de componentes (individualmente ou ao mesmo tempo).

## <a name="see-also"></a>Consulte também

[Assistente de Projeto da ATL](../../atl/reference/atl-project-wizard.md)<br/>
[Criando um projeto ATL](../../atl/reference/creating-an-atl-project.md)<br/>
[Configurações de projeto padrão da ATL](../../atl/reference/default-atl-project-configurations.md)
