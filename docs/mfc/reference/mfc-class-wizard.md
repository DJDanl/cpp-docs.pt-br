---
title: "Assistente de classe MFC | Microsoft Docs"
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
  - "vc.wizards.classwizard"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Assistente de classe MFC"
  - "assistentes (MFC)"
ms.assetid: 8b0dd867-5d07-4214-99be-2a1c1995e6d9
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Assistente de classe MFC
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Permite adicionar mensagens e manipuladores de mensagem para classes em seu projeto.  Você também pode iniciar outros assistentes ou adicionar uma classe ao seu projeto.  
  
 Para abrir **Assistente de Classe MFC**, no menu de **Projeto** , clique em **Assistente de classe**.  Para abrir o assistente com um atalho de teclado, digite. CTRL\+SHIFT\+X.  
  
## Lista UIElement  
 **Projeto**  
 O nome de um projeto na solução.  
  
 Você pode selecionar outros projetos na solução na caixa de listagem suspensa.  
  
 **Nome da classe**  
 O nome de uma classe no projeto.  
  
 Quando você seleciona uma classe na lista de **Nome da classe** , os dados da classe populam os controles em **Assistente de Classe MFC**.  Quando você altera o valor de um controle, os dados da classe selecionada são afetados.  
  
 **Adicionar Classe**  
 Permite que você adicione uma classe de uma de várias fontes.  
  
 Dependendo da sua seleção, **MFC O assistente para adicionar classe**, **Adicione a classe do assistente de Typelib**, **Assistente de Adição de Classe do Controle ActiveX**, ou **Assistente do consumidor MFC ODBC** são iniciados.  
  
 **Classe Base**  
 A classe base da classe que é exibida em **Nome da classe**.  
  
 **Declaração de classe**  
 A classe na qual a classe de **Nome da classe** é declarada.  
  
 A caixa de **Declaração de classe** será exibida somente se o nome nele for diferente do nome em **Implementação da classe**.  
  
 **Recurso**  
 A ID de O recurso em **Nome da classe**, se houver.  Caso contrário, a caixa de **Recurso** está vazia.  
  
 **Implementação da classe**  
 O nome do arquivo que contém a implementação da classe em **Nome da classe**.  
  
 Você pode selecionar um arquivo diferente da implementação clicando na seta.  A tabela a seguir lista as opções disponíveis.  
  
|Opção|Descrição|  
|-----------|---------------|  
|**Abrir arquivo**|Sair do assistente da classe e abre o arquivo atual da implementação da classe.|  
|**Pasta de que contém aberta**|Abre a pasta que contém o arquivo atual da implementação da classe.|  
|**Caminho completo de cópia na área de transferência**|Copia o caminho do arquivo atual de implementação para a área de transferência.|  
  
 **Comandos**  
 Permite adicionar, excluir, editar, ou procurar um comando e pelo manipulador de mensagens.  
  
 Para adicionar um manipulador **Adicionar Manipulador**, clique em, ou clique duas vezes em um item na lista de **IDs de objeto** ou na lista de **Mensagens** .  O nome, a ID, e a mensagem resultantes são exibidos na lista de **Funções de membro** .  
  
 Para excluir um manipulador, selecione um item na lista de **Funções de membro** e clique em **Excluir Manipulador**.  
  
 Para alterar um manipulador, clique duas vezes no item correspondente na lista de **Funções de membro** .  Ou, selecione um item na caixa de listagem e clique em **Editar Código**.  
  
 **Mensagens**  
 Permite adicionar, excluir, editar, ou para pesquisar por uma mensagem e pelo manipulador de mensagens.  
  
 Para adicionar um manipulador **Adicionar Manipulador**, clique em, ou clique duas vezes em um item na lista de **Mensagens** .  
  
 Para adicionar uma mensagem personalizada, clique **Adicionar Mensagem Personalizada** ou pressione a tecla ENTER, e depois especifique valores na caixa de diálogo de **Adicionar Mensagem Personalizada** .  Nessa caixa de diálogo, você também pode selecionar **Mensagem Registrada** para tratar uma mensagem da janela que é garantida para ser exclusivo em todo o sistema operacional.  
  
 **Funções Virtuais**  
 Permite adicionar, excluir, editar, ou para pesquisar por uma função virtual, ou por uma função virtual substituída.  
  
 **Variáveis de membro**  
 Permite adicionar, excluir, editar, ou para pesquisar por uma variável de membro.  
  
 **Métodos**  
 Permite adicionar, excluir, ou procurar um método, e também vão\-nos a definição ou à declaração de um método.  
  
 Para adicionar um método, clique em **Adicionar método**, e depois especifique valores na caixa de diálogo de **Adicionar método** .  
  
 Para excluir um método, selecione um item na lista de **Métodos** e clique em **Excluir método**.  
  
 Para exibir uma declaração, selecione um item na lista de **Métodos** e clique em **Vá para a declaração.**  
  
 Para exibir uma definição, clique duas vezes em um item na lista de **Métodos** .  Ou, selecione um item na lista de **Métodos** e clique no botão de **Ir para definição** .  
  
## Consulte também  
 [Adicionando uma classe](../Topic/Adding%20a%20Class%20\(Visual%20C++\).md)