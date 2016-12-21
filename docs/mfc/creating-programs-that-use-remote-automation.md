---
title: "Criando programas que usam automa&#231;&#227;o remota | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Automação remota, criando programas"
ms.assetid: 8eb31320-1037-4029-b1f3-fdc9406dbaf1
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Criando programas que usam automa&#231;&#227;o remota
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Qualquer objeto de automação, e qualquer controlador de automação, podem usar a automação remoto sem nenhuma alteração ao código\-fonte, sem a necessidade da recompilação, e sem a necessidade de relinking.  Depois que você tiver uma configuração que o trabalho localmente \(isto é, no mesmo computador\), você precisa passar por apenas algumas etapas o executar remotamente.  
  
#### Para executar o objeto de automação remoto  
  
1.  Registrar o aplicativo no computador cliente ou em computadores.  
  
2.  Configurar o acesso de cliente ao servidor remoto de uso.  
  
3.  Para instalar e registrar o aplicativo no computador ou em computadores do servidor.  
  
4.  Configurar o servidor para permitir a ativação remota.  
  
5.  Instalar o gerenciador de automação nos computadores do servidor.  
  
6.  Executar o gerenciador de automação em server.  
  
7.  Execute o aplicativo nos clientes.  
  
 A etapa 1 é realizada o mais facilmente carregando e executando o aplicativo para servidores no computador cliente, porque a maioria dos servidores forem registrar self.  Se você testar a configuração localmente com antecedência, essa fase já está completo.  Se o aplicativo de servidor não é auto que se registra, talvez você queira fazer isso.  Caso contrário, você precisará fornecer um arquivo de registro que o usuário local pode executar para executar essa etapa.  Se você não fizer nenhuma dessas ações, você ou um administrador precisará editar manualmente o Registro, um procedimento que não é recomendado para todos menos a maioria dos usuários avançados.  
  
 A etapa 2 envolve o uso do gerenciador remoto de \(RAC\) de conexão de automação.  Executar o gerenciador de RAC e verifique se o guia de conexão do servidor é o mais alto.  Em seguida, encontra a entrada para o objeto de servidor no painel de **OLE Classes** e clique em.  Na **Endereço de rede** mover a caixa de combinação e digite o nome do computador do servidor em que o arquivo executável remoto será executado.  Por exemplo, você pode digitar \\\\Meuservidor aqui.  Escolha o protocolo de rede apropriada na lista fornecida.  Você pode precisar verifique com o administrador da rede para determinar qual protocolo é recomendado.  Em muitos casos, esse será o TCP\/IP.  Finalmente, talvez você queira escolhendo um nível de autenticação.  Na maioria dos casos, isso será deixado como \(nenhum\) ou opção.  Clique com o botão direito do mouse no servidor agora no painel de **OLE Classes** .  Isso gerará um menu de atalho da qual você poderá selecionar a operação local ou remoto.  Remotos selecione.  
  
 A etapa 3 envolve corretamente instalar e registrar o aplicativo de servidor no computador ou em computadores selecionados do servidor.  Além disso, se o aplicativo é auto que se registra, execute uma vez registrar\-o\-&z também.  
  
 A etapa 4 envolve configurar o servidor para permitir a execução remota.  Executar o gerenciador de RAC no computador do servidor e, verifique se o guia de **Acesso para cliente** tem o foco.  Escolha o modelo de ativação que você quer \(normalmente **Allow Remote Creates by Key**.  Se você escolher esta opção, você também precisará clicar na caixa de seleção de **Allow Remote Activation** para definir o valor de entrada de Registro para “Y "\).  Se você estiver executando o Windows NT 2000 ou o Windows e você escolhe o remoto para permitir a criação da opção \(ACL\), você também tem a opção para editar o ACL enviando o botão de **Edit ACL** .  
  
 Para permitir que a automação remoto funcione, você precisa em garantir que o gerenciador de automação é instalado e em execução no computador ou em computadores do servidor.  Se não estiver instalada, copie AUTMGR32.EXE para o diretório do sistema do windows.  Para obter informações sobre como fazer isso, consulte [Instalação remota de automação](../Topic/Remote%20Automation%20Installation.md).  Para iniciar a automação remoto, execute o gerenciador de automação.  Exibirá uma pequena janela de status em que um número de mensagens serão mostradas.  Uma vez que foi iniciado, minimizar\-se\-&z.  Se você quiser continuar consultando informações de status, você pode clicar na guia de **Automation Manager** na barra de tarefas para restaurar a janela.  
  
 A última etapa é executar o aplicativo cliente no computador cliente.  Se você seguiu as etapas acima, deve se conectar ao objeto de servidor e executar precisamente como feito localmente, embora um pouco mais lento.  
  
 Observe que o gerenciador de RAC também permite a troca entre a automação remoto e COM distribuída \(DCOM, nessas plataformas que ofereçam suporte para o DCOM\) com um único clique do botão de opção.  Se você escolher DCOM, você pode definir várias opções de configuração.  Consulte a documentação do DCOM para obter detalhes adicionais.  
  
## Consulte também  
 [Automação remota](../mfc/remote-automation.md)   
 [Executando automação remota usando AUTOCLIK e AUTODRIV](../mfc/running-remote-automation-using-autoclik-and-autodriv.md)