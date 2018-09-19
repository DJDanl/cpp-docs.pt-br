---
title: Assistente de projeto de configurações do aplicativo, o ATL | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- vc.appwiz.atl.com.appset
dev_langs:
- C++
helpviewer_keywords:
- ATL Project Wizard, application settings
ms.assetid: d48c9fc5-f439-49fd-884c-8bcfa7d52991
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 4cff60e5316202842b2ee22c5c6ba10813839b5d
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46035845"
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

