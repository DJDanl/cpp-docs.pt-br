---
title: "Sequência de operações para criação de aplicativos MFC | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: applications [MFC], developing
ms.assetid: 6973c714-fe20-48c6-926b-de88356b3a3d
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: ae1169b438a181e22696502352c19353421469b1
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="sequence-of-operations-for-building-mfc-applications"></a>Sequência de operações para compilar aplicativos MFC
A tabela a seguir explica a sequência geral, que normalmente você pode seguir à medida que desenvolve seu aplicativo do MFC.  
  
### <a name="sequence-for-building-an-application-with-the-framework"></a>Sequência de criação de um aplicativo com o Framework  
  
|Tarefa|Fazer|A estrutura faz|  
|----------|------------|------------------------|  
|Crie um aplicativo de esqueleto.|Execute o [Assistente de aplicativo MFC](../mfc/reference/mfc-application-wizard.md). Especifique as opções desejadas nas páginas de opções. As opções incluem fazer o aplicativo, um componente COM, contêiner ou ambos; adicionando automação; e fazer com que o aplicativo com reconhecimento de banco de dados.|O Assistente de aplicativo MFC cria os arquivos para um aplicativo de esqueleto, incluindo arquivos de origem para seu aplicativo, documento, exibição e janelas com moldura; um arquivo de recurso; um arquivo de projeto; e outros, todos adaptados às suas especificações.|  
|Veja o que oferecem a estrutura e o Assistente de aplicativo MFC sem adicionar uma linha de seu próprio código.|Compilar o aplicativo de esqueleto e execute-o no Visual C++.|O aplicativo em execução esqueleto deriva padrão muitos **arquivo**, **editar**, **exibição**, e **ajuda** comandos de menu do framework. Para aplicativos MDI, você também obtém um menu do Windows totalmente funcional e o framework gerencia a criação, a organização e a destruição de janelas filho MDI.|  
|Criar uma interface de usuário do seu aplicativo.|Use o Visual C++ [editores de recursos](../windows/resource-editors.md) editar visualmente a interface do usuário do aplicativo:<br /><br /> -Crie menus.<br />-Defina aceleradores.<br />-Crie caixas de diálogo.<br />-Criar e editar bitmaps, ícones e cursores.<br />-Edite a barra de ferramentas criada para você pelo Assistente de aplicativo MFC.<br />-Criar e editar outros recursos.<br /><br /> Você também pode testar as caixas de diálogo no editor de caixa de diálogo.|O arquivo de recurso padrão criado pelo Assistente de aplicativo MFC fornece muitos dos recursos que você precisa. O Visual C++ permite editar os recursos existentes e adicionar novos recursos, fácil e visualmente.|  
|Menus são mapeados para funções de manipulador.|Use o **eventos** no botão de [janela propriedades](/visualstudio/ide/reference/properties-window) para se conectar a menus e aceleradores para funções de manipulador em seu código.|A janela Propriedades insere entradas de mapa de mensagem e modelos de função vazio para os arquivos de origem que você especificar e gerencia muitas tarefas de codificação manuais.|  
|Escreva o código de manipulador.|Use a exibição de classe para ir diretamente para o código no editor de código fonte. Preencha o código para as funções de manipulador. Para obter mais informações sobre como usar o modo de exibição de classe e sobre os assistentes que adicionar código a um projeto, consulte [adicionando funcionalidade com assistentes de código](../ide/adding-functionality-with-code-wizards-cpp.md).|Exibição de classe abre o editor, rola para o modelo de função vazio e posiciona o cursor para você.|  
|Mapear botões da barra de comandos.|Mapear cada botão na barra de ferramentas para um comando de menu ou acelerador atribuindo o botão a ID de comando apropriado.|A estrutura controla o desenho, habilitar, desabilitar, verificação e outros aspectos visuais dos botões de barra de ferramentas.|  
|Teste suas funções de manipulador.|Recrie o programa e usar as ferramentas de depuração internas para testar se os manipuladores estão funcionando corretamente.|Você pode entrar ou rastrear através do código para ver como seus manipuladores são chamados. Se você tiver preenchido o código do manipulador, execute os manipuladores de comandos. A estrutura desabilitará automaticamente os itens de menu e botões de barra de ferramentas que não são manipuladas.|  
|Adicionar [caixas de diálogo](../mfc/dialog-boxes.md).|Criar recursos de modelo de caixa de diálogo com o editor de caixa de diálogo. Em seguida, crie uma classe de caixa de diálogo e o código que manipula a caixa de diálogo.|A estrutura gerencia a caixa de diálogo e facilita a recuperação de informações inseridas pelo usuário.|  
|Inicializar, validar e recuperar dados de caixa de diálogo.|Você também pode definir como os controles da caixa de diálogo devem ser inicializado e validada. Use o Visual Studio para adicionar variáveis de membro para a classe de caixa de diálogo e mapeá-los para controles de caixa de diálogo. Especifica regras de validação a ser aplicada a cada controle que o usuário insere dados. Fornece sua própria validação personalizada se desejar.|A estrutura gerencia a inicialização da caixa de diálogo e validação. Se o usuário insere informações inválidas, o framework exibe uma caixa de mensagem e permite que o usuário inserir os dados novamente.|  
|Crie classes adicionais.|Use a exibição de classe para criar classes de janela com moldura além daquelas criadas automaticamente pelo Assistente de aplicativo MFC, exibição e documentos adicionais. Você pode criar classes de conjunto de registros do banco de dados adicionais, classes de caixa de diálogo e assim por diante. (Com a exibição de classe, você pode criar classes não derivadas de classes do MFC.)|Exibição de classe adiciona essas classes para seus arquivos de origem e ajuda a definir suas conexões para todos eles tratam os comandos.|  
|Adicione componentes prontos para uso ao seu aplicativo.|Use o `New Item dialog box` para adicionar uma série de itens.|Esses itens são fáceis de integrar seu aplicativo e salvar a você uma grande quantidade de trabalho.|  
|Implemente sua classe de documento.|Implemente a classe de documento específico do aplicativo ou classes. Adicione variáveis de membro para armazenar estruturas de dados. Adicione funções de membro para fornecer uma interface para os dados.|A estrutura já sabe como interagir com os arquivos de dados de documento. Ele pode abrir e fechar os arquivos de documento, ler e gravar os dados do documento e lidar com outras interfaces de usuário. Você pode se concentrar em como os dados do documento são manipulados.|  
|Implementar abrir, salvar e salve como comandos.|Escrever código para o documento `Serialize` função de membro.|A estrutura exibe caixas de diálogo para o **abrir**, **salvar**, e **Salvar como** comandos no **arquivo** menu. Ele grava e leituras novamente um documento usando o formato de dados especificado no seu `Serialize` função de membro.|  
|Implemente a classe de exibição.|Implementar uma ou mais classes de exibição correspondente aos seus documentos. Implemente funções de membro do modo de exibição que é mapeado para a interface do usuário com o modo de exibição de classe. Uma variedade de [CView](../mfc/reference/cview-class.md)-classes derivadas estão disponíveis, incluindo [CListView](../mfc/reference/clistview-class.md) e [CTreeView](../mfc/reference/ctreeview-class.md).|A estrutura gerencia a maioria da relação entre um documento e sua exibição. Funções de membro da exibição acessar documentos do modo de exibição para renderizar a imagem na tela ou página impressa e atualizar estruturas de dados do documento em resposta a comandos de edição do usuário.|  
|Melhorar a impressão padrão.|Se você precisar dar suporte a impressão de várias páginas, substitua funções de membro de exibição.|A estrutura oferece suporte a **impressão**, **Configurar página**, e **Visualizar impressão** comandos no **arquivo** menu. Você deve dizer a ele como dividir o documento em várias páginas.|  
|Adicione a rolagem.|Se você precisar dar suporte a rolagem, derive a classe de exibição ou classes de [CScrollView](../mfc/reference/cscrollview-class.md).|O modo de exibição automaticamente adiciona barras de rolagem quando a janela de exibição se tornar muito pequena.|  
|Crie modos de exibição de formulário.|Se você deseja basear as exibições em recursos de modelo de caixa de diálogo, derive a classe de exibição ou classes de [CFormView](../mfc/reference/cformview-class.md).|A exibição usa o recurso de modelo de caixa de diálogo para exibir controles. O usuário pode usar tab de controle para controle no modo de exibição.|  
|Crie formulários de banco de dados.|Se você quiser que um aplicativo de acesso a dados baseado em formulário, derive sua classe de exibição da [CRecordView](../mfc/reference/crecordview-class.md) (para programação de ODBC).|O modo de exibição funciona como um modo de exibição de formulário, mas seus controles estão conectados aos campos de um [CRecordset](../mfc/reference/crecordset-class.md) objeto que representa uma tabela de banco de dados. MFC move dados entre os controles e o conjunto de registros para você.|  
|Crie um texto simple editor.|Se desejar que a exibição para ser um editor de texto simples, derive sua classe de exibição ou classes de [CEditView](../mfc/reference/ceditview-class.md) ou [CRichEditView](../mfc/reference/cricheditview-class.md).|O modo de exibição fornece a edição de funções, suporte a área de transferência e arquivo de entrada/saída. `CRichEditView`Fornece um estilo de texto.|  
|Adicione janelas separadoras.|Se você deseja dar suporte a divisão de janela, adicione um [CSplitterWnd](../mfc/reference/csplitterwnd-class.md) de objeto para a janela do quadro SDI ou janela filho MDI e associá-lo na janela de [OnCreateClient](../mfc/reference/cframewnd-class.md#oncreateclient) função de membro.|A estrutura fornece controles divisor caixa ao lado de barras de rolagem e gerencia dividindo a exibição em vários painéis. Se o usuário dividir uma janela, o framework cria e anexa os objetos de exibição adicionais ao documento.|  
|Criar, testar e depurar seu aplicativo.|Use os recursos do Visual C++ para criar, testar e depurar seu aplicativo.|Visual C++ permite ajustar a compilação, link e outras opções. Ele também permite que você procure sua estrutura de classe e de código de origem.|  
  
## <a name="see-also"></a>Consulte também  
 [Sequência de operações para criação de aplicativos OLE](../mfc/sequence-of-operations-for-creating-ole-applications.md)   
 [Sequência de operações para criação de controles ActiveX](../mfc/sequence-of-operations-for-creating-activex-controls.md)   
 [Sequência de operações para criação de aplicativos de banco de dados](../mfc/sequence-of-operations-for-creating-database-applications.md)   
 [Compilando no Framework](../mfc/building-on-the-framework.md)

