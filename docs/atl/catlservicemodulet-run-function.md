---
title: "Fun&#231;&#227;o de CAtlServiceModuleT::Run | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "CServiceModule::Run"
  - "CServiceModule.Run"
  - "CSecurityDescriptor"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Serviços ATL, segurança"
ms.assetid: 42c010f0-e60e-459c-a63b-a53a24cda93b
caps.latest.revision: 12
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Fun&#231;&#227;o de CAtlServiceModuleT::Run
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Executar** contém chamadas a `PreMessageLoop`, a `RunMessageLoop`, e a `PostMessageLoop`.  Após ser chamado, `PreMessageLoop` armazena primeiro a identificação do segmento de serviço  O serviço usará este identificação para fechar enviando uma mensagem de **WM\_QUIT** usando a função da API do Win32, [PostThreadMessage](http://msdn.microsoft.com/library/windows/desktop/ms644946).  
  
 `PreMessageLoop` então chama `InitializeSecurity`.  Por padrão, `InitializeSecurity` chama [CoInitializeSecurity](http://msdn.microsoft.com/library/windows/desktop/ms693736) com o descritor de segurança definido PARA ANULAR, o que significa que qualquer usuário tem acesso ao objeto.  
  
 Se você não deseja que o serviço para especificar sua própria segurança, substituição `PreMessageLoop` e não chama `InitializeSecurity`, e COM determinará nas configurações de segurança do Registro.  Uma maneira conveniente para configurar configurações do Registro é com o utilitário de [DCOMCNFG](../Topic/DCOMCNFG.md) abordado posteriormente em esta seção.  
  
 Uma vez que a segurança é especificada, o objeto está registrado com COM para que os novos clientes podem se conectar ao programa.  Finalmente, o programa com o gerenciador \(SCM\) do controle de serviço que está executando o programa e inserir um loop de mensagem.  O programa permanecerá executando até que envia uma mensagem interrupção em cima de desligamento de serviço.  
  
## Consulte também  
 [Serviços](../atl/atl-services.md)   
 [Classe de CSecurityDesc](../atl/reference/csecuritydesc-class.md)   
 [Classe de CSid](../atl/reference/csid-class.md)   
 [Classe de CDacl](../atl/reference/cdacl-class.md)   
 [CAtlServiceModuleT::Run](../Topic/CAtlServiceModuleT::Run.md)