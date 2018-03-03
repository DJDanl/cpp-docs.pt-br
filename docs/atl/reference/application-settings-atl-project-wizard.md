---
title: "Assistente de projeto de configurações do aplicativo, ATL | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- vc.appwiz.atl.com.appset
dev_langs:
- C++
helpviewer_keywords:
- ATL Project Wizard, application settings
ms.assetid: d48c9fc5-f439-49fd-884c-8bcfa7d52991
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 12b7e383716d7cfa330bdfdebe21c33550669cc2
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="application-settings-atl-project-wizard"></a>Configurações do aplicativo, Assistente de projeto ATL
Use o **configurações de aplicativo** página do Assistente de projeto de ATL para criar e adicionar recursos básicos para um novo projeto ATL.  
  
## <a name="server-type"></a>Tipo de servidor  
 Escolha um dos três tipos de servidor:  
  
 **Biblioteca de vínculo dinâmico (DLL)**  
 Selecione para criar um servidor em processo.  
  
 **Executável (EXE)**  
 Selecione para criar um servidor local de fora do processo. Essa opção não permite o suporte para MFC ou COM+ 1.0. Ele não permite a mesclagem de código proxy/stub.  
  
 **Serviço (EXE)**  
 Selecione para criar um aplicativo do Windows que é executado em segundo plano quando o Windows iniciar. Essa opção não permitir o suporte para MFC ou COM+ 1.0 ou não que a mesclagem de código proxy/stub.  
  
## <a name="additional-options"></a>Opções adicionais  
  
> [!NOTE]
>  Todas as opções adicionais estão disponíveis para projetos DLL apenas.  
  
 **Permitir mesclagem do código proxy/stub**  
 Selecione o **Permitir mesclagem do código proxy/stub** caixa de seleção como uma conveniência ao empacotamento interfaces é necessária. Essa opção coloca o código de proxy e stub gerado pelo MIDL no mesmo executável do servidor.  
  
 **Suporte MFC**  
 Selecione para especificar que o objeto inclui suporte do MFC. Esta opção vincula seu projeto para as bibliotecas MFC para que você pode acessar qualquer uma das classes e funções que eles contêm.  
  
 **Suporte de COM+ 1.0**  
 Selecione para modificar as configurações de compilação de projeto para dar suporte aos componentes COM+ 1.0. Além da lista padrão de bibliotecas, o assistente adiciona o comsvcs.lib de biblioteca específico do componente COM+ 1.0  
  
 Além disso, o mtxex.dll é carregado no sistema host quando o aplicativo é iniciado de atraso.  
  
-   **Suporte do registrador de componente** se seu projeto ATL contém suporte para os componentes COM+ 1.0, você pode definir essa opção. O registrador de componente permite que seu objeto de COM+ 1.0 obter uma lista de componentes, registrar componentes ou cancelar o registro de componentes (individualmente ou todos de uma vez).  
  
## <a name="see-also"></a>Consulte também  
 [Assistente de projeto ATL](../../atl/reference/atl-project-wizard.md)   
 [Criando um projeto ATL](../../atl/reference/creating-an-atl-project.md)   
 [Configurações de projeto padrão da ATL](../../atl/reference/default-atl-project-configurations.md)

