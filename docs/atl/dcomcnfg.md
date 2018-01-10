---
title: DCOMCNFG | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: DCOMCNFG
dev_langs: C++
helpviewer_keywords:
- DCOMCNFG utility
- DCOM, configuring in ATL
ms.assetid: 5a8126e9-ef27-40fb-a66e-9dce8d1a7e80
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: f40b372666ba2b623450eb0e58a6c0ff372559ec
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="dcomcnfg"></a>DCOMCNFG
**DCOMCNFG** é um utilitário do Windows NT 4.0 que permite configurar diversas configurações específicas de DCOM no registro. O **DCOMCNFG** janela tem três páginas: aplicativos de segurança padrão e propriedades padrão. Com o Windows 2000, uma quarta página, protocolos padrão, está presente.  
  
## <a name="default-security-page"></a>Página de segurança padrão  
 Você pode usar a página de segurança padrão para especificar permissões padrão para objetos do sistema. A página de segurança padrão tem três seções: acesso, inicialização e configuração. Para alterar os padrões da seção, clique em correspondente **Editar padrão** botão. Essas configurações de segurança padrão são armazenadas no registro em `HKEY_LOCAL_MACHINE\Software\Microsoft\OLE`.  
  
## <a name="default-protocols-page"></a>Página de protocolos padrão  
 Esta página lista o conjunto de protocolos de rede disponíveis para DCOM neste computador. A ordem reflete a prioridade na qual eles serão usados; o primeiro na lista tem a prioridade mais alta. Protocolos podem ser adicionados ou excluídos desta página.  
  
## <a name="default-properties-page"></a>Página de propriedades padrão  
 Na página de propriedades padrão, você deve selecionar o **habilitar COM distribuído no computador** caixa de seleção se desejar que os clientes em outros computadores para acessar COM objetos em execução neste computador. Selecionar esta opção define a `HKEY_LOCAL_MACHINE\Software\Microsoft\OLE\EnableDCOM` valor `Y`.  
  
## <a name="applications-page"></a>Página de aplicativos  
 Você alterar as configurações de um determinado objeto com a página de aplicativos. Basta selecionar o aplicativo na lista e clique no **propriedades** botão. A janela Propriedades tem cinco páginas:  
  
-   A página geral confirma o aplicativo que você está trabalhando.  
  
-   A página de local permite que você especifique onde o aplicativo deve ser executado quando um cliente chama `CoCreateInstance` no CLSID relevante. Se você selecionar o **executar o aplicativo no seguinte computador** caixa de seleção e insira um nome de computador, em seguida, um `RemoteServerName` valor for adicionado a AppID do aplicativo. Limpar o **executar o aplicativo neste computador** renomeações de caixa de seleção o `LocalService` valor `_LocalService` e, assim, a desabilita.  
  
-   A página de segurança é semelhante à segurança padrão página encontrada no **DCOMCNFG** janela, exceto pelo fato de que essas configurações se aplicam somente ao aplicativo atual. Novamente, as configurações são armazenadas sob a AppID para esse objeto.  
  
-   A página de identificação identifica qual usuário é usado para executar o aplicativo.  
  
-   Página pontos de extremidade lista o conjunto de protocolos e pontos de extremidade disponíveis para uso pelos clientes do servidor selecionado do DCOM.  
  
## <a name="see-also"></a>Consulte também  
 [Serviços](../atl/atl-services.md)

