---
title: "Criando programas que usam automação remota | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: Remote Automation, creating programs
ms.assetid: 8eb31320-1037-4029-b1f3-fdc9406dbaf1
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: deb832e0baed30507ef3f9929fb5f12805b7a807
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="creating-programs-that-use-remote-automation"></a>Criando programas que usam automação remota
Qualquer objeto de automação e qualquer controlador de automação, é possível usar automação remota sem qualquer alteração feita no código-fonte, sem a necessidade de recompilação e sem a necessidade de vinculando novamente. Depois que você tiver uma configuração que funciona localmente (ou seja, no mesmo computador), você precisa passar por apenas algumas etapas para executá-lo remotamente.  
  
#### <a name="to-execute-the-remote-automation-object"></a>Para executar o objeto de automação remota  
  
1.  Registre o aplicativo no computador cliente ou máquinas.  
  
2.  Configure o acesso do cliente para usar um servidor remoto.  
  
3.  Instalar e registrar o aplicativo na máquina do servidor ou máquinas.  
  
4.  Configure o servidor para permitir a ativação remota.  
  
5.  Instale o Gerenciador de automação em computadores do servidor.  
  
6.  Execute o Gerenciador de automação em todos os servidores.  
  
7.  Execute o aplicativo nos clientes.  
  
 Etapa 1 é mais facilmente conseguida carregar e executar o aplicativo de servidor no computador cliente, como a maioria dos servidores são self registrando. Se você testou o programa de instalação localmente com antecedência, esta etapa já foi concluída. Se o aplicativo do servidor não for self registrar, talvez você queira fazer isso. Caso contrário, você precisará fornecer um arquivo de registro que o usuário local pode executar para realizar esta etapa. Se você não fizer nenhuma dessas opções, você ou um administrador será necessário editar o registro manualmente, um procedimento que não é recomendado para tudo, exceto os usuários mais avançados.  
  
 Etapa 2 envolve o uso do Gerenciador de Conexão de automação remota (RAC). Execute o Gerenciador de RAC e certifique-se de que o guia de conexão do servidor é superior. Em seguida, localize a entrada para o objeto de servidor no **Classes OLE** painel e clique nele. Mova para o **endereço de rede** combinação caixa e insira o nome da máquina do servidor no qual o arquivo executável remoto será executado. Por exemplo, você pode inserir \\\MyServer aqui. Selecione o protocolo de rede apropriada na lista fornecida. Talvez seja necessário verificar com o administrador de rede para determinar qual protocolo é recomendado. Em muitos casos, esse será o TCP/IP. Finalmente, convém escolher um nível de autenticação. Na maioria dos casos, isso será esquerda como (nenhum) ou padrão. Agora com o botão direito no servidor de **Classes OLE** painel. Isso produzirá um menu de atalho do qual você pode selecionar a operação local ou remota. Selecione remoto.  
  
 Etapa 3 envolve corretamente instalar e registrar o aplicativo de servidor na máquina do servidor selecionado ou máquinas. Novamente, se o aplicativo tem sua própria registrar, executá-la uma vez também registrará-lo.  
  
 Etapa 4 envolve a configuração do servidor para permitir a execução remota. Executar o Gerenciador de RAC na máquina do servidor e verifique se o **acesso para cliente** guia tem o foco. Escolha o modelo de ativação que você deseja (normalmente **permitir remoto cria pela chave**. Se você escolher essa opção, você também precisará clique o **permitir a ativação remota** caixa de seleção para definir o valor da entrada do registro para 'Y'). Se você estiver executando o Windows NT ou Windows 2000 e você escolhe a opção de permitir remoto cria (ACL), você também tem a opção para editar a ACL por push o **Editar ACL** botão.  
  
 Para permitir a automação remota funcione, você precisa garantir que o Gerenciador de automação está instalado e em execução na máquina do servidor ou máquinas. Se não estiver instalado, copie AUTMGR32. EXE para o diretório de sistema do Windows. Para obter informações sobre como fazer isso, consulte [instalação de automação remota](../mfc/remote-automation-installation.md). Para iniciar a automação remota, execute o Gerenciador de automação. Ele exibirá uma janela de status pequeno em que um número de mensagens será exibido. Depois de iniciada, isso minimizará em si. Se você quiser continuar a ver informações de status, você pode clicar no **Gerenciador de automação** guia na barra de tarefas para restaurar a janela.  
  
 A etapa final é executar o aplicativo cliente no computador cliente. Se você tiver seguido as etapas acima, ele deve conectar-se ao objeto do servidor e executar com precisão como localmente, embora um pouco menor.  
  
 Observe que o Gerenciador de RAC também permite que você alterne entre a automação remota e distributed COM (DCOM, nessas plataformas que dão suporte ao DCOM) com um único clique de um botão de opção. Se você escolher DCOM, você pode definir várias opções de configuração. Consulte a documentação do DCOM para obter mais detalhes.  
  
## <a name="see-also"></a>Consulte também  
 [Automação remota](../mfc/remote-automation.md)   
 [Executando automação remota usando AUTOCLIK e AUTODRIV](../mfc/running-remote-automation-using-autoclik-and-autodriv.md)

