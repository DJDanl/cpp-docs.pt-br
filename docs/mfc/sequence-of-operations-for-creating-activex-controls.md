---
title: Sequência de operações para criação de controles ActiveX
ms.date: 11/04/2016
helpviewer_keywords:
- MFC ActiveX controls [MFC], creating
- ActiveX controls [MFC], creating
- sequence [MFC], for creating ActiveX controls
- OLE controls [MFC], MFC
- sequence [MFC]
ms.assetid: 7d868c53-a0af-4ef6-a89c-e1c03c583a53
ms.openlocfilehash: 020c044cc0b3b96df102a5ab6625c945f1033f67
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62308427"
---
# <a name="sequence-of-operations-for-creating-activex-controls"></a>Sequência de operações para criação de controles ActiveX

A tabela a seguir mostra a sua função e a função da estrutura na criação de controles ActiveX (anteriormente conhecidos como controles OLE).

### <a name="creating-activex-controls"></a>Criação de controles ActiveX

|Tarefa|Você faz|A estrutura faz|
|----------|------------|------------------------|
|Crie uma estrutura de controle ActiveX.|Execute o Assistente de controle ActiveX MFC para criar seu controle. Especifica as opções desejadas nas páginas de opções. As opções incluem o tipo e o nome do controle no projeto, licenciamento, a criação de subclasses e um método de caixa sobre.|O Assistente de controle ActiveX MFC cria os arquivos para um controle ActiveX com funcionalidade básica, incluindo arquivos de origem para seu aplicativo, o controle e a página de propriedades ou a páginas; um arquivo de recurso; um arquivo de projeto; e outros, todos adaptados às suas especificações.|
|Veja o que oferecem o controle e o Assistente de controle ActiveX sem adicionar uma linha de seu próprio código.|Criar o controle ActiveX e testá-lo com o Internet Explorer ou o [exemplo TSTCON](../overview/visual-cpp-samples.md).|O controle em execução tem a capacidade de ser redimensionado e movido. Ele também tem um **About Box** método (se escolhido) que pode ser invocado.|
|Implemente os métodos e propriedades do controle.|Implemente suas propriedades e métodos específicos de controle, adicionando funções de membro para fornecer uma interface exposta para os dados do controle. Adicione variáveis de membro para armazenar estruturas de dados e usar manipuladores de eventos para disparar eventos quando você determinar.|O framework já definiu um mapa para dar suporte a eventos do controle, propriedades e métodos, deixando-o para se concentrar em como as propriedades e métodos são implementados. A página de propriedade padrão é visível e um método de caixa sobre o padrão é fornecido.|
|Construa páginas ou página de propriedades do controle.|Use os editores de recursos do Visual C++ para editar visualmente a interface de página de propriedade do controle:<br /><br />-Crie páginas de propriedades adicionais.<br />-Criar e editar bitmaps, ícones e cursores.<br /><br /> Você também pode testar as páginas de propriedade no editor de caixa de diálogo.|O arquivo de recurso padrão criado pelo Assistente de aplicativo do MFC fornece muitos dos recursos que você precisa. Visual C++ permite editar os recursos existentes e adicionar novos recursos, fácil e visualmente.|
|Propriedades, métodos e eventos do controle de teste.|Recompile o controle e usar o contêiner de teste para testar se seus manipuladores funcionam corretamente.|Você pode invocar métodos do controle e manipulam suas propriedades por meio da interface de página de propriedade ou por meio do contêiner de teste. Além disso, use o contêiner de teste para acompanhar eventos acionados a partir do controle e notificações recebidas pelo contêiner do controle.|

## <a name="see-also"></a>Consulte também

[Compilando no Framework](../mfc/building-on-the-framework.md)<br/>
[Sequência de operações para compilar aplicativos MFC](../mfc/sequence-of-operations-for-building-mfc-applications.md)<br/>
[Sequência de operações para a criação de aplicativos OLE](../mfc/sequence-of-operations-for-creating-ole-applications.md)<br/>
[Sequência de operações para criação de aplicativos de banco de dados](../mfc/sequence-of-operations-for-creating-database-applications.md)
