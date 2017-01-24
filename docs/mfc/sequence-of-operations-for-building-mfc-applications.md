---
title: "Sequ&#234;ncia de opera&#231;&#245;es para compila&#231;&#227;o de aplicativos MFC | Microsoft Docs"
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
  - "aplicativos [MFC], desenvolvendo"
ms.assetid: 6973c714-fe20-48c6-926b-de88356b3a3d
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Sequ&#234;ncia de opera&#231;&#245;es para compila&#231;&#227;o de aplicativos MFC
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A tabela a seguir explica a sequência geral que você normalmente deve seguir ao desenvolver seu aplicativo MFC.  
  
### Valor de sequência criando um aplicativo com a estrutura  
  
|Tarefa|Você fizer|A estrutura faz|  
|------------|----------------|---------------------|  
|Crie um aplicativo do esqueleto.|Executar [Assistente do aplicativo MFC](../Topic/MFC%20Application%20Wizard.md).  Especifique as opções que você deseja nas páginas de opções.  As opções incluem a fatura o aplicativo de um componente COM, contêiner, ou ambos; adicionando a automação; e fazendo o aplicativo base de dados \- ciente.|O assistente de aplicativo MFC cria os arquivos para um aplicativo do esqueleto, incluindo arquivos de origem do aplicativo, o documento, exibição, e janelas do quadro; um arquivo de recurso; um arquivo de projeto; e outro, qualquer personalizada para suas especificações.|  
|Veja o que a estrutura e o assistente de aplicativo MFC oferecem sem adicionar uma linha de seu próprio código.|Criar o aplicativo do esqueleto e executá\-lo no Visual C\+\+.|O aplicativo do esqueleto em execução deriva muito **Arquivo**padrão, **Editar**, **Exibir**, e comandos de menu de **Ajuda** da estrutura.  Para aplicativos MDI, você também obtém a completamente \- o menu do windows funcional, e a estrutura gerenciam a criação, a organização, e destruição de janelas filho MDI.|  
|Construir a interface de usuário de seu aplicativo.|Use o Visual C\+\+ [editores de recursos](../mfc/resource-editors.md) para editar visualmente a interface de usuário do aplicativo:<br /><br /> -   Criar menus.<br />-   Defina aceleradores.<br />-   Caixas de diálogo criar.<br />-   Criar e editar bitmaps, ícones, e cursores.<br />-   Editar a barra de ferramentas criada pelo assistente de aplicativo MFC.<br />-   Criar e editar outros recursos.<br /><br /> Você também pode testar as caixas de diálogo no publicador da caixa de diálogo.|O arquivo de recursos padrão criado pelo assistente de aplicativo MFC fornece muitos dos recursos que você precisa.  Visual C\+\+ permite editar recursos existentes e adicionar facilmente e visualmente novos recursos.|  
|Menus do mapa às funções do manipulador.|Use o botão de **Eventos** em [Janela Propriedades](../Topic/Properties%20Window.md) para se conectar menus e aceleradores às funções do manipulador em seu código.|As entradas retornadas mapa de inserções da janela Propriedades vazia e modelos da função nos arquivos de origem que você especificou e gerencia muitas tarefas manuais de codificação.|  
|Escreva o código do manipulador.|Use a exibição da classe para ir diretamente ao código no editor de origem.  Preencha o código para suas funções do manipulador.  Para obter mais informações sobre como usar a exibição da classe e os assistentes de adicionar código a um projeto, consulte [Adicionando funcionalidade com assistentes de código](../ide/adding-functionality-with-code-wizards-cpp.md).|A exibição da classe abrir o editor, confirmadas ao modelo vazio da função e posiciona o cursor para você.|  
|Botões da barra de ferramentas do mapa aos comandos.|Mapeie cada botão na barra de ferramentas a um menu ou um comando de acelerador atribuindo no botão a ID de comando apropriado|A estrutura controla o desenho, habilitar, desabilitar, marque, e outros aspectos visuais dos botões da barra de ferramentas.|  
|Teste as funções do manipulador.|A recriação do programa e use as ferramentas de depuração internos para testar se os manipuladores funcionem corretamente.|Você pode avançar ou rastrear com o código para ver como os manipuladores são chamados.  Se você completou o código do manipulador, manipuladores executar comandos.  A estrutura desabilitará automaticamente os itens de menu e os botões da barra de ferramentas que ainda não foram tratadas.|  
|Adicionar [caixas de diálogo](../mfc/dialog-boxes.md).|Criar recursos de diálogo\- modelo com o publicador da caixa de diálogo.  Crie uma classe da caixa de diálogo e o código que trata a caixa de diálogo.|A estrutura gerencia a caixa de diálogo e facilita\-a recuperar informações inserida pelo usuário.|  
|Inicializar, validar, e recuperar dados da caixa de diálogo.|Você também pode definir como os controles da caixa de diálogo devem ser inicializados e validado.  Use o Visual Studio para adicionar variáveis de membro à classe da caixa de diálogo e mapeie\-os para aos controles da caixa de diálogo.  Especificar as regras de validação a ser aplicado a cada controle como o usuário insere dados.  Fornecer suas próprias validações personalizados se você deseja.|A estrutura gerencia a inicialização e a validação da caixa de diálogo.  Se o usuário inserir informações inválidas, a estrutura exibe uma caixa de mensagem e permite que o usuário digite novamente os dados.|  
|Crie classes adicionais.|Use a exibição da classe para criar o documento, a exibição, e classes adicionais de quadro\- janela além de aquelas criadas automaticamente pelo assistente de aplicativo MFC.  Você pode criar classes adicionais de conjuntos de registros base de dados, as classes da caixa de diálogo, e assim por diante. \(Com a exibição da classe, você não pode criar classes derivadas das classes MFC\).|A exibição da classe adiciona essas classes a seus arquivos de origem e ajudará você define suas conexões com todos os comandos tratam.|  
|Adicionar componentes prontos para uso ao aplicativo.|Use `New Item dialog box` para adicionar uma variedade de itens.|Esses itens são fáceis integrar seu aplicativo e salve\-o muito trabalho.|  
|Implementar a sua classe do documento.|Implementar suas classe ou classes específicos do aplicativo do documento.  Adicionar variáveis de membro para manter estruturas de dados.  Adicione funções de membro para fornecer uma interface para os dados.|A estrutura já sabe interagir com os arquivos de dados do documento.  Pode abrir e fechar os arquivos de documento, ler e gravar os dados de documento, e trata outras interfaces do usuário.  Você pode passar o mouse sobre como os dados de documento são manipulados.|  
|Implementar Abrir, salvar, e salve como comandos.|Grave o código para a função de membro de `Serialize` do documento.|Exibe a estrutura caixas de diálogo para **Abrir**, **Salvar**, e comandos de **Salvar como** no menu de **Arquivo** .  Grava e leitura para um documento usando o formato de dados especificado na função de membro de `Serialize` .|  
|Implementar a sua classe da exibição.|Implementar uma ou mais classes de exibição que correspondem aos seus documentos.  Implementar as funções de membro da exibição que você mapear para a interface do usuário com a exibição da classe.  Uma variedade de [CView](../Topic/CView%20Class.md)\- classes derivadas estão disponíveis, inclusive [CListView](../mfc/reference/clistview-class.md) e [CTreeView](../mfc/reference/ctreeview-class.md).|A estrutura gerencia a maioria da relação entre um documento e sua exibição.  As funções de membro de exibição acessam o documento de exibição para renderização da imagem na tela ou na página impressa e atualizar as estruturas de dados de documento em resposta aos comandos de edição do usuário.|  
|Aprimorar a impressão padrão.|Se precisar dar suporte a impressão de várias páginas, funções de membro de exibição de substituição.|A estrutura da suporte a **Imprimir**, **Configurar Página**, e comandos de **Visualizar Impressão** no menu de **Arquivo** .  Você deve informar como interromper o documento em várias páginas.|  
|Adicionar a rolagem.|Se precisar dar suporte à rolagem, derivar suas classes classe ou da exibição de [CScrollView](../mfc/reference/cscrollview-class.md).|A exibição automaticamente adiciona barras de rolagem quando a janela de exibição se tornam muito pequena.|  
|Criar exibições de formulário.|Se você deseja basear as exibições em recursos de diálogo\- modelo, derivar suas classes classe ou da exibição de [CFormView](../mfc/reference/cformview-class.md).|A exibição usa o recurso de diálogo\- modelo aos controles de exibição.  O usuário pode alternar de controle ao controle na exibição.|  
|Criar formas da base de dados.|Se você desejar um aplicativo de acesso a dados de autenticação baseado, derivar a sua classe da exibição de [CRecordView](../mfc/reference/crecordview-class.md) para que o programa \(ODBC\).|A exibição funciona como uma exibição de formulário, mas seus controles estão conectados a campos de um objeto de [CRecordset](../Topic/CRecordset%20Class.md) que representa uma tabela de base de dados.  MFC O mover dados entre os controles e o conjunto de registros para você.|  
|Crie um editor de texto simples.|Se desejar que sua exibição para ser um editor de texto simples, derivar suas classes classe ou da exibição de [CEditView](../Topic/CEditView%20Class.md) ou de [CRichEditView](../mfc/reference/cricheditview-class.md).|A exibição fornece funções de edição, suporte à área de transferência e, entrada\/saída do arquivo.  `CRichEditView` fornece o texto denominado.|  
|Adicionar o windows do separador.|Se você quiser oferecer suporte a janela que divide, adicionar um objeto de [CSplitterWnd](../mfc/reference/csplitterwnd-class.md) à janela do quadro de SDI ou janela filho MDI e enganche\-o acima na função de membro de [OnCreateClient](../Topic/CFrameWnd::OnCreateClient.md) da janela.|A estrutura fornece controles de separador\- caixa ao lado das barras de rolagem e gerencia a divisão da exibição em vários painéis.  Se o usuário divide uma janela do, a estrutura cria e anexar exibir objetos adicionais ao documento.|  
|Criar, testar e depurar, seu aplicativo.|Use as instalações do Visual C\+\+, para criar, testar e depurar seu aplicativo.|Visual C\+\+ permite ajustar cria, vincula, e outras opções.  Também permite procurar a estrutura de origem e da classe.|  
  
## Consulte também  
 [Sequência de operações para criação de aplicativos OLE](../mfc/sequence-of-operations-for-creating-ole-applications.md)   
 [Sequência de operações para criação de controles ActiveX](../mfc/sequence-of-operations-for-creating-activex-controls.md)   
 [Sequência de operações para criação de aplicativos de banco de dados](../mfc/sequence-of-operations-for-creating-database-applications.md)   
 [Aproveitando o Framework](../mfc/building-on-the-framework.md)