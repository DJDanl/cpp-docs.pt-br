---
title: Executando como um membro do grupo de usuários | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- PRJ0050
- VCD0047
dev_langs:
- C++
helpviewer_keywords:
- Users Group [C++]
- security [C++], Users Group
- Windows accounts [C++]
- non administrator users [C++]
- user accounts [C++]
- administrator (not running as) [C++]
ms.assetid: e48a03ec-d345-49f6-809a-1a291eecbc81
author: ghogen
ms.author: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 4faeae9100cf6e60a2eeda19baea20ba42be197f
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="running-as-a-member-of-the-users-group"></a>Executando como um membro do grupo de usuários
Este tópico explica como a configuração de contas de usuário do Windows como membro do grupo Usuários (em vez do grupo Administradores) aumenta a segurança reduzindo as chances de contaminação com código mal-intencionado.  
  
## <a name="security-risks"></a>Riscos de segurança  
 A execução como administrador torna o sistema vulnerável a vários tipos de ataque de segurança, como "cavalos de Troia" e "estouro de buffer". Uma simples visita a um site da Internet como administrador pode ser danoso ao sistema, pois o código mal-intencionado que é baixado de um site da Internet pode atacar o computador. Se ele for bem-sucedido, herdará as suas permissões de administrador e poderá executar ações como excluir todos os arquivos, reformatar o disco rígido e criar novas contas de usuário com acesso administrativo.  
  
## <a name="non-administrator-user-groups"></a>Grupos de usuários não administradores  
 As contas de usuário do Windows que os desenvolvedores normalmente usam devem ser adicionadas aos grupos Usuários ou Usuários Avançados. Os desenvolvedores também devem ser adicionados ao grupo Depuração. Ser um membro do grupo Usuários permite que você execute tarefas rotineiras, inclusive a execução de programas e o acesso a sites da Internet, sem expor o computador a riscos desnecessários. Como membro do grupo Usuários Avançados, você também pode executar tarefas como instalação de aplicativos, instalação de impressoras e a maioria das operações do Painel de Controle. Se você precisa executar tarefas administrativas, como atualizar o sistema operacional ou configurar parâmetros de sistema, faça logon em uma conta de administrador apenas pelo tempo necessário para executar a tarefa administrativa. Como alternativa, o Windows **runas** comando pode ser usado para iniciar aplicativos específicos com acesso administrativo.  
  
## <a name="exposing-customers-to-security-risks"></a>Exposição dos clientes a riscos de segurança  
 Não fazer parte do grupo Administradores é particularmente importante para desenvolvedores porque, além de proteger os computadores de desenvolvimento, impede que os desenvolvedores escrevam inadvertidamente um código que exija que os clientes ingressem no grupo Administradores para executar os aplicativos que você desenvolve. Se código que requer acesso de administrador é introduzido durante o desenvolvimento, ele falhará em tempo de execução, alertando para o fato de que o aplicativo exige agora que os clientes executem como administradores.  
  
## <a name="code-that-requires-administrator-privileges"></a>Código que exige privilégios de administrador  
 Alguns códigos exigem acesso de administrador para serem executados. Se possível, devem ser estudadas alternativas a esse tipo de código. Exemplos de operações de código que requerem acesso de administrador são:  
  
-   Gravação em áreas protegidas do sistema de arquivos, como os diretórios Windows ou Arquivos de Programas  
  
-   Gravação em áreas protegidas do Registro, como HKEY_LOCAL_MACHINE  
  
-   Instalação de assemblies no Cache de Assembly Global (GAC)  
  
 Em geral, essas ações devem ser limitadas aos programas de instalação de aplicativos. Isso permite que os usuários utilizem o status de administrador somente temporariamente.  
  
## <a name="debugging"></a>Depuração  
 Você pode depurar todos os aplicativos que iniciar no Visual Studio (nativos e não gerenciados) como não administrador tornando-se parte do grupo Depuração. Isso inclui a capacidade de anexar a um aplicativo em execução usando o comando Anexar ao Processo. No entanto, é necessário fazer parte do grupo Administrador para depurar aplicativos nativos ou gerenciados iniciados por um usuário diferente.  
  
## <a name="see-also"></a>Consulte também  
 [Práticas Recomendadas de segurança](security-best-practices-for-cpp.md)