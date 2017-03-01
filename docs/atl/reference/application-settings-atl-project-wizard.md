---
title: "Assistente de projeto de configurações do aplicativo, ATL | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- vc.appwiz.atl.com.appset
dev_langs:
- C++
helpviewer_keywords:
- ATL Project Wizard, application settings
ms.assetid: d48c9fc5-f439-49fd-884c-8bcfa7d52991
caps.latest.revision: 17
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 8514cce9dc2732d4a97ac51895e1ab28975fcfa3
ms.lasthandoff: 02/25/2017

---
# <a name="application-settings-atl-project-wizard"></a>Configurações do aplicativo, ATL Project Wizard
Use o **configurações do aplicativo** página do Assistente para criar e adicionar recursos básicos para um novo projeto ATL projeto ATL.  
  
## <a name="server-type"></a>Tipo de servidor  
 Escolha um dos três tipos de servidor:  
  
 **Biblioteca de vínculo dinâmico (DLL)**  
 Selecione para criar um servidor em processo.  
  
 **Arquivo executável (EXE)**  
 Selecione para criar um servidor fora de processo local. Essa opção não permite suporte para MFC ou COM+ 1.0. Ele não permite a mesclagem de código proxy/stub.  
  
 **Serviço (EXE)**  
 Selecione para criar um aplicativo do Windows que é executado em segundo plano quando o Windows inicia. Essa opção não permitir suporte a MFC ou COM+ 1.0 ou não que a mesclagem de código proxy/stub.  
  
## <a name="additional-options"></a>Opções adicionais  
  
> [!NOTE]
>  Todas as opções adicionais estão disponíveis para projetos de DLL somente.  
  
 **Permitir que a mesclagem de código proxy/stub**  
 Selecione o **permitem a mesclagem de código proxy/stub** caixa de seleção como uma conveniência ao empacotamento interfaces é necessária. Essa opção coloca o código de proxy e de stub gerado pelo MIDL no mesmo executável do servidor.  
  
 **Suporte MFC**  
 Selecione para especificar que o objeto inclui suporte a MFC. Esta opção vincula seu projeto para as bibliotecas MFC para que você possa acessar qualquer uma das classes e funções que eles contêm.  
  
 **Suporte COM+ 1.0**  
 Selecione esta opção para modificar as configurações de compilação do projeto para oferecer suporte a componentes COM+ 1.0. Além da lista padrão de bibliotecas, o assistente adiciona o comsvcs.lib de biblioteca específico do componente COM+ 1.0  
  
 Além disso, o mtxex.dll é carregado no sistema host quando o aplicativo é iniciado de atraso.  
  
-   **Registrador de componentes de suporte** se seu projeto ATL contém suporte para componentes COM+ 1.0, você pode definir essa opção. O registrador de componentes permite que seu objeto de COM+ 1.0 obter uma lista de componentes, registrar componentes ou cancelar o registro de componentes (individualmente ou todos de uma vez).  
  
## <a name="see-also"></a>Consulte também  
 [ATL Project Wizard](../../atl/reference/atl-project-wizard.md)   
 [Criando um projeto do ATL](../../atl/reference/creating-an-atl-project.md)   
 [Configurações de projeto padrão ATL](../../atl/reference/default-atl-project-configurations.md)


