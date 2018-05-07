---
title: Sequência de operações para criação de controles ActiveX | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- MFC ActiveX controls [MFC], creating
- ActiveX controls [MFC], creating
- sequence [MFC], for creating ActiveX controls
- OLE controls [MFC], MFC
- sequence [MFC]
ms.assetid: 7d868c53-a0af-4ef6-a89c-e1c03c583a53
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: caf4c74f2263505ad5d7112021003f92c85a4b84
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="sequence-of-operations-for-creating-activex-controls"></a>Sequência de operações para criação de controles ActiveX
A tabela a seguir mostra a função e a função do framework na criação de controles ActiveX (anteriormente conhecidos como controles OLE).  
  
### <a name="creating-activex-controls"></a>Criação de controles ActiveX  
  
|Tarefa|Fazer|A estrutura faz|  
|----------|------------|------------------------|  
|Crie uma estrutura de controle ActiveX.|Execute o Assistente de controle ActiveX MFC para criar o controle. Especifique as opções desejadas nas páginas de opções. Opções incluem o tipo e o nome do controle no projeto, subclassificação, licenciamento e um método de caixa sobre.|O Assistente de controle ActiveX MFC cria os arquivos para um controle ActiveX com a funcionalidade básica, incluindo arquivos de origem para seu aplicativo, o controle e a página de propriedades ou a páginas. um arquivo de recurso; um arquivo de projeto; e outros, todos adaptados às suas especificações.|  
|Veja o que oferecem o controle e o Assistente de controle ActiveX sem adicionar uma linha de seu próprio código.|Criar o controle ActiveX e testá-lo com o Internet Explorer ou o [exemplo TSTCON](../visual-cpp-samples.md).|O controle em execução tem a capacidade de ser redimensionado e movido. Ele também tem um **caixa sobre** método (se escolhidas) que pode ser invocado.|  
|Implemente os métodos e propriedades do controle.|Implemente suas propriedades e métodos específicos de controle com a adição de funções de membro para fornecer uma interface exposta para os dados do controle. Adicione variáveis de membro para armazenar estruturas de dados e usar manipuladores de eventos para disparar eventos quando você determinar.|A estrutura já definiu um mapa para dar suporte a eventos do controle, propriedades e métodos, deixando-o para se concentrar em como as propriedades e métodos são implementados. A página de propriedade padrão é visível e um método de caixa sobre padrão é fornecido.|  
|Cria uma página de propriedade ou as páginas do controle.|Use os editores de recursos do Visual C++ para editar visualmente a interface de página de propriedades do controle:<br /><br /> -Crie páginas de propriedades adicionais.<br />-Criar e editar bitmaps, ícones e cursores.<br /><br /> Você também pode testar as páginas de propriedade no editor de caixa de diálogo.|O arquivo de recurso padrão criado pelo Assistente de aplicativo MFC fornece muitos dos recursos que você precisa. O Visual C++ permite editar os recursos existentes e adicionar novos recursos, fácil e visualmente.|  
|Teste as propriedades, métodos e eventos do controle.|Recriar o controle e use o contêiner de teste para testar se os manipuladores estão funcionando corretamente.|Você pode chamar os métodos do controle e manipular suas propriedades por meio da interface de página de propriedade ou por meio de contêiner de teste. Além disso, use o contêiner de teste para acompanhar eventos acionados a partir do controle e notificações recebidas pelo contêiner do controle.|  
  
## <a name="see-also"></a>Consulte também  
 [Compilando no Framework](../mfc/building-on-the-framework.md)   
 [Sequência de operações para criação de aplicativos MFC](../mfc/sequence-of-operations-for-building-mfc-applications.md)   
 [Sequência de operações para criação de aplicativos OLE](../mfc/sequence-of-operations-for-creating-ole-applications.md)   
 [Sequência de operações para criação de aplicativos de banco de dados](../mfc/sequence-of-operations-for-creating-database-applications.md)

