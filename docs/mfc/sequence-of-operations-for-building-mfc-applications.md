---
title: Sequência de operações para compilar aplicativos MFC | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- applications [MFC], developing
ms.assetid: 6973c714-fe20-48c6-926b-de88356b3a3d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 305533a0bd6113e3df2c29f5f8b16ae54e0bb2be
ms.sourcegitcommit: 997e6b7d336cddb388bb6e9e56527725fcaa0624
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/08/2018
ms.locfileid: "48861324"
---
# <a name="sequence-of-operations-for-building-mfc-applications"></a>Sequência de operações para compilar aplicativos MFC

A tabela a seguir explica a sequência geral, que você pode seguir normalmente à medida que desenvolve seu aplicativo do MFC.

### <a name="sequence-for-building-an-application-with-the-framework"></a>Sequência para a criação de um aplicativo com o Framework

|Tarefa|Você faz|A estrutura faz|
|----------|------------|------------------------|
|Crie um aplicativo de esqueleto.|Execute o [Assistente de aplicativo MFC](../mfc/reference/mfc-application-wizard.md). Especifica as opções desejadas nas páginas de opções. As opções incluem fazer o aplicativo, um componente COM, contêiner ou ambos; Adicionar automação; e, fazendo com que o aplicativo com suporte a banco de dados.|O Assistente de aplicativo do MFC cria os arquivos para um aplicativo de esqueleto, incluindo arquivos de origem para seu aplicativo, documento, exibição e janelas com moldura; um arquivo de recurso; um arquivo de projeto; e outros, todos adaptados às suas especificações.|
|Veja o que oferecem a estrutura e o Assistente de aplicativo do MFC sem adicionar uma linha de seu próprio código.|Compilar o aplicativo de esqueleto e executá-lo no Visual C++.|O aplicativo em execução esqueleto deriva standard muitas **arquivo**, **editar**, **exibição**, e **ajuda** comandos de menu do framework. Para aplicativos MDI, você também obtém um menu totalmente funcional do Windows e a estrutura gerencia a criação, a organização e destruição de janelas filho MDI.|
|Construa a interface do usuário do seu aplicativo.|Usar o Visual C++ [editores de recursos](../windows/resource-editors.md) para editar visualmente a interface do usuário do aplicativo:<br /><br /> -Crie menus.<br />-Defina aceleradores.<br />-Crie caixas de diálogo.<br />-Criar e editar bitmaps, ícones e cursores.<br />-Edite a barra de ferramentas criada para você pelo Assistente de aplicativo MFC.<br />-Criar e editar outros recursos.<br /><br /> Você também pode testar as caixas de diálogo no editor de caixa de diálogo.|O arquivo de recurso padrão criado pelo Assistente de aplicativo do MFC fornece muitos dos recursos que você precisa. Visual C++ permite editar os recursos existentes e adicionar novos recursos, fácil e visualmente.|
|Menus são mapeados para funções do manipulador.|Use o **eventos** botão na [janela propriedades](/visualstudio/ide/reference/properties-window) para se conectar a menus e aceleradores para funções de manipulador no seu código.|A janela Propriedades insere as entradas de mapa de mensagem e modelos de função vazios os arquivos de origem que você especificar e gerencia muitas tarefas de codificação manuais.|
|Escreva seu código de manipulador.|Use o modo de exibição de classe para ir diretamente para o código no editor de código fonte. Preencha o código para suas funções de manipulador. Para obter mais informações sobre como usar o modo de exibição de classe e sobre os assistentes que adicionam o código a um projeto, consulte [adicionando funcionalidade com assistentes de código](../ide/adding-functionality-with-code-wizards-cpp.md).|Class View abre o editor, rola para o modelo de função vazios e posiciona o cursor para você.|
|Mapear os botões de barra de ferramentas para comandos.|Mapear cada botão na barra de ferramentas para um comando de menu ou acelerador atribuindo o botão a ID de comando apropriado.|O framework controla o desenho, habilitar, desabilitar, verificação e outros aspectos visuais dos botões da barra de ferramentas.|
|Teste suas funções de manipulador.|Recompilar o programa e usar as ferramentas de depuração internas para testar se seus manipuladores funcionam corretamente.|É possível etapa ou por meio do código para ver como seus manipuladores são chamados de rastreamento. Se você tiver preenchido o código do manipulador, executam os manipuladores de comandos. O framework desabilitará automaticamente os itens de menu e botões de barra de ferramentas que não são manipuladas.|
|Adicione [caixas de diálogo](../mfc/dialog-boxes.md).|Criar recursos de modelo de caixa de diálogo com o editor de caixa de diálogo. Em seguida, crie uma classe de caixa de diálogo e o código que manipula a caixa de diálogo.|A estrutura gerencia a caixa de diálogo e facilita a recuperação de informações inseridas pelo usuário.|
|Inicializar, validar e recuperar dados de caixa de diálogo.|Você também pode definir como os controles da caixa de diálogo devem ser inicializado e validado. Use o Visual Studio para adicionar variáveis de membro à classe de caixa de diálogo e mapeá-los para controles de caixa de diálogo. Especifica regras de validação a ser aplicado a cada controle enquanto o usuário insere dados. Forneça seus próprio validações personalizadas se desejar.|A estrutura gerencia a validação e inicialização da caixa de diálogo. Se o usuário insere informações inválidas, o framework exibe uma caixa de mensagem e permite que o usuário inserir os dados novamente.|
|Crie classes adicionais.|Use modo de exibição de classe para criar classes de janela com moldura além daquelas criadas automaticamente pelo Assistente de aplicativo do MFC, exibição e documentos adicionais. Você pode criar classes de conjunto de registros do banco de dados adicionais, classes de caixa de diálogo e assim por diante. (Com a exibição de classe, você pode criar classes não derivadas de classes do MFC.)|Modo de exibição de classe adiciona essas classes para os arquivos de origem e ajuda você a definir suas conexões com todos eles manipulam os comandos.|
|Adicione componentes prontos para uso ao seu aplicativo.|Use o `New Item dialog box` para adicionar uma variedade de itens.|Esses itens são fáceis de integrar ao seu aplicativo e salve a você uma grande quantidade de trabalho.|
|Implemente sua classe de documento.|Implemente sua classe de documento específico do aplicativo ou classes. Adicione variáveis de membro para armazenar estruturas de dados. Adicione funções de membro para fornecer uma interface para os dados.|A estrutura já sabe como interagir com arquivos de dados do documento. Ele pode abrir e fechar os arquivos de documento, ler e gravar os dados do documento e lidar com outras interfaces do usuário. Você pode se concentrar em como os dados do documento são manipulados.|
|Implementar a abrir, salvar e salve como comandos.|Escrever código para o documento `Serialize` função de membro.|O framework exibe caixas de diálogo para o **aberto**, **salve**, e **Salvar como** os comandos no **arquivo** menu. Ele grava e leituras de volta um documento usando o formato de dados especificado no seu `Serialize` função de membro.|
|Implemente sua classe de exibição.|Implementar uma ou mais classes de exibição correspondente aos seus documentos. Implemente funções de membro do modo de exibição que é mapeado para a interface do usuário com o modo de exibição de classe. Uma variedade de [CView](../mfc/reference/cview-class.md)-as classes derivadas estão disponíveis, incluindo [CListView](../mfc/reference/clistview-class.md) e [CTreeView](../mfc/reference/ctreeview-class.md).|A estrutura gerencia a maioria da relação entre um documento e sua exibição. Funções de membro da exibição acessam documentos do modo de exibição para renderizar sua imagem na tela ou página impressa e atualizar estruturas de dados do documento em resposta a comandos de edição do usuário.|
|Aprimore a impressão padrão.|Se você precisar dar suporte a impressão de várias páginas, substitua as funções de membro de exibição.|O framework oferece suporte a **Print**, **Configurar página**, e **Visualizar impressão** comandos no **arquivo** menu. Você deve informar a ele como dividir seu documento em várias páginas.|
|Adicione a rolagem.|Se você precisar dar suporte a rolagem, derivar seu modo de exibição de classe ou classes de [CScrollView](../mfc/reference/cscrollview-class.md).|O modo de exibição adicionará automaticamente barras de rolagem quando a janela de exibição se torna muito pequena.|
|Crie modos de exibição de formulário.|Se você deseja basear suas opiniões sobre os recursos de modelo de caixa de diálogo, derive seu modo de exibição de classe ou classes de [CFormView](../mfc/reference/cformview-class.md).|A exibição usa o recurso de modelo de caixa de diálogo para exibir controles. O usuário pode pressionar tab do controle até o controle no modo de exibição.|
|Crie formulários de banco de dados.|Se você quiser que um aplicativo de acesso a dados baseado em formulário, derive sua classe de exibição da [CRecordView](../mfc/reference/crecordview-class.md) (para a programação de ODBC).|O modo de exibição funciona como um modo de exibição de formulário, mas seus controles estão conectados aos campos de um [CRecordset](../mfc/reference/crecordset-class.md) objeto que representa uma tabela de banco de dados. MFC move dados entre os controles e o conjunto de registros para você.|
|Crie um texto simples de editor.|Se você quiser que seu modo de exibição para ser um editor de texto simples, derivar seu modo de exibição de classe ou classes de [CEditView](../mfc/reference/ceditview-class.md) ou [CRichEditView](../mfc/reference/cricheditview-class.md).|O modo de exibição fornece a edição de funções, suporte a área de transferência e arquivo de entrada/saída. `CRichEditView` fornece o texto com estilo.|
|Adicione janelas separadoras.|Se você quiser dar suporte a divisão de janela, adicione uma [CSplitterWnd](../mfc/reference/csplitterwnd-class.md) o objeto para a sua janela de quadro SDI ou uma janela filho MDI e conectá-la na janela do [OnCreateClient](../mfc/reference/cframewnd-class.md#oncreateclient) função de membro.|A estrutura fornece controles de caixa de separador ao lado de barras de rolagem e gerencia a dividir seu modo de exibição em vários painéis. Se o usuário é uma janela dividida, o framework cria e anexa objetos de visualização adicionais ao documento.|
|Criar, testar e depurar seu aplicativo.|Use os recursos do Visual C++ para criar, testar e depurar seu aplicativo.|Visual C++ permite ajustar a compilação, o link e outras opções. Ele também permite que você procure sua estrutura de código e a classe de origem.|

## <a name="see-also"></a>Consulte também

[Sequência de operações para a criação de aplicativos OLE](../mfc/sequence-of-operations-for-creating-ole-applications.md)<br/>
[Sequência de operações para criação de controles ActiveX](../mfc/sequence-of-operations-for-creating-activex-controls.md)<br/>
[Sequência de operações para criação de aplicativos de banco de dados](../mfc/sequence-of-operations-for-creating-database-applications.md)<br/>
[Compilando no Framework](../mfc/building-on-the-framework.md)

