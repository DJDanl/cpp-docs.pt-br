---
title: "Testando propriedades e eventos com cont&#234;iner de teste | Microsoft Docs"
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
  - "Contêiner de Teste de Controle ActiveX"
  - "Controles ActiveX [C++], testando"
  - "depurando controles ActiveX"
  - "propriedades [MFC], testando"
  - "contêiner de teste"
  - "testando, contêineres de teste"
  - "tstcon32.exe"
ms.assetid: 626867cf-fe53-4c30-8973-55bb93ef3917
caps.latest.revision: 13
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Testando propriedades e eventos com cont&#234;iner de teste
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O aplicativo de contêineres de teste, enviado no Visual C\+\+, é um contêiner do controle ActiveX para testar e depurar controles ActiveX.  O contêiner de teste permite que o desenvolvedor de controle testar a funcionalidade de controle alterar suas propriedades, invocando seus métodos, e acionando seus eventos.  O contêiner de teste pode exibir logs de notificações de associação de dados e também fornece recursos para testar uma funcionalidade de persistência de controle ActiveX: você pode salvar propriedades para um fluxo ou ao substorage, recarregar\-las, e examinar os dados armazenados do fluxo.  Esta seção descreve como usar os recursos básicos do contêiner de teste.  Para obter informações adicionais, selecione o menu de **Ajuda** quando em execução testam o contêiner.  
  
### Para acessar o contêiner de teste de controle ActiveX  
  
1.  Criar [Exemplo de TSTCON: Contêiner de teste de controle ActiveX](../top/visual-cpp-samples.md).  
  
### Para testar o controle ActiveX  
  
1.  No menu de **Editar** do contêiner de teste, clique em **Insert New Control**.  
  
2.  Na caixa de **Inserir controle** o controle, selecione e clique em **OK**desejados.  O controle será exibido no contêiner do controle.  
  
    > [!NOTE]
    >  Se o controle não está listado na caixa de diálogo de **Inserir controle** , certifique\-se de fazer com que seja registrado com o comando de **Registrar Controles** no menu de **Arquivo** do contêiner de teste.  
  
 Neste momento você pode testar as propriedades ou os eventos do controle.  
  
#### Para testar propriedades  
  
1.  No menu de **Controle** , clique **Invoke Methods**.  
  
2.  Na lista suspensa de **Nome do Método** , selecione o método de PropPut da propriedade que você deseja testar.  
  
3.  Modifique **Valor do Parâmetro** ou **Tipo de parâmetro** e clique no botão de **Definir valor** .  
  
4.  Clique **Invocar** para aplicar o novo valor ao objeto.  
  
     A propriedade contém agora o novo valor.  
  
#### Para testar eventos e especificar o destino de informações do evento.  
  
1.  No menu de **Opções** , clique em **Log**.  
  
2.  Especifique o destino de informações do evento.  
  
## Consulte também  
 [Controles ActiveX MFC](../mfc/mfc-activex-controls.md)   
 [Como depurar um controle ActiveX](../Topic/How%20to:%20Debug%20an%20ActiveX%20Control.md)