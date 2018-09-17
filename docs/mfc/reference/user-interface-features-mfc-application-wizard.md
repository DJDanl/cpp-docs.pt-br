---
title: Recursos de Interface do usuário, o Assistente de aplicativo MFC | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- vc.appwiz.mfc.exe.ui
dev_langs:
- C++
helpviewer_keywords:
- MFC Application Wizard, user interface features
ms.assetid: 59e7b829-a665-42eb-be23-3f2a36eb2dad
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 29961e7b597683d3735203de9a47646b2a320469
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45722547"
---
# <a name="user-interface-features-mfc-application-wizard"></a>Funcionalidades da interface do usuário, Assistente de Aplicativo MFC

Este tópico explica as opções que você pode usar para especificar a aparência de seu aplicativo. Recursos de interface do usuário disponíveis para seu projeto dependem do tipo de aplicativo que você especificou na [tipo de aplicativo, Assistente de aplicativo MFC](../../mfc/reference/application-type-mfc-application-wizard.md) página do Assistente de aplicativo MFC. Por exemplo, se você criar um aplicativo de interface de documento único, não é possível adicionar estilos de quadro filho.  
  
- **Estilos de quadro principal**

   Define os recursos do quadro de janela principal do seu aplicativo.  
  
   |Opção|Descrição|  
   |------------|-----------------|  
   |**Quadro grosso**|Cria uma janela que tem uma borda de dimensionamento. O padrão.|  
   |**Minimizar caixa**|Inclui uma caixa de minimização na janela do quadro principal. O padrão.|  
   |**Caixa de maximização**|Inclui uma caixa de maximização na janela do quadro principal. O padrão.|  
   |**Minimizado**|Abre a janela de quadro principal como um ícone.|  
   |**Maximizado**|Abre a janela de quadro principal para o tamanho total da exibição.|  
   |**Menu do sistema**|Inclui um menu de sistema na janela do quadro principal. O padrão.|  
   |**Caixa sobre**|Inclui um **sobre** caixa para o aplicativo. O usuário pode acessar essa caixa de caixa de diálogo **ajudar** menu. O padrão e ficará inalterável, a menos que você selecione **caixa de diálogo com base**, no [tipo de aplicativo, Assistente de aplicativo MFC](../../mfc/reference/application-type-mfc-application-wizard.md) página.<br /><br /> **Observação** normalmente, uma opção indisponível indica que o assistente não se aplica a opção para o projeto, se a caixa de seleção do item não está disponível é marcada ou desmarcada. Nesse caso, o assistente sempre adiciona uma **sobre** caixa para o projeto, a menos que você especifique primeiro o projeto como caixa de diálogo com base e, em seguida, desmarque a caixa.|  
   |**Barra de status inicial**|Adiciona uma barra de status ao seu aplicativo. A barra de status contém indicadores de automática para as teclas do teclado CAPS LOCK, NUM LOCK e bloqueio de ROLAGEM e uma linha de mensagem que exibe a Ajuda para sequências de comandos de menu e barra de ferramentas de botões. Clicar nesta opção também adiciona a comandos de menu para exibir ou ocultar a barra de status. Por padrão, um aplicativo tem uma barra de status. Não disponível para tipos de aplicativo baseado em caixa de diálogo.|  
   |**Janela dividida**|Fornece uma barra divisória. Na barra de divisão divide os modos de exibição principal do aplicativo. Em um aplicativo de interface MDI vários documentos, janela de cliente do quadro filho MDI é uma janela separadora e, em um aplicativo de interface (SDI) de documento único e vários aplicativos de nível superior do documento, a janela do cliente do quadro principal é uma janela separadora. Não disponível para tipos de aplicativo baseado em caixa de diálogo.|  
  
- **Estilos de quadro filho**

   Especifica a aparência e o estado inicial dos quadros filho em seu aplicativo. Estilos de quadro filho estão disponíveis para apenas os aplicativos MDI.  
  
   |Opção|Descrição|  
   |------------|-----------------|  
   |**Caixa de minimizar o filho**|Especifica se uma janela filho tem um botão Minimizar (habilitado por padrão).|  
   |**Caixa de maximização do filho**|Especifica se uma janela filho tem um botão Maximizar (habilitado por padrão).|  
   |**Filho maximizado**|Especifica se uma janela filho inicialmente é maximizada, definindo o cs.style sinalizador WS_MAXIMIZE na [PreCreateWindow](../../mfc/reference/cwnd-class.md#precreatewindow) função de membro de `CChildFrame`.|  
  
- **Barras de comando (menu/barra de ferramentas/faixa de opções)**

   Indica se o seu aplicativo inclui menus, barras de ferramentas e/ou uma faixa de opções. Não disponível para aplicativos com base na caixa de diálogo.  
  
   |Opção|Descrição|  
   |------------|-----------------|  
   |**Usar um menu clássico**|Especifica que o aplicativo contém um menu clássico, não arrastável.|  
   |**Use uma barra de ferramentas de encaixe clássica**|Adiciona uma barra de ferramentas padrão do Windows ao seu aplicativo. A barra de ferramentas contém botões para criar um novo documento. Abrir e salvar arquivos de documento; Recortar, copiar, colar ou imprimir texto; e entrar no modo de Ajuda. A habilitação dessa opção também adiciona a comandos de menu para exibir ou ocultar a barra de ferramentas.|  
   |**Use uma barra de ferramentas de estilo de navegador**|Adiciona uma barra de ferramentas do Internet Explorer-estilo ao seu aplicativo.|  
   |**Use uma barra de menus e barra de ferramentas**|Indica que o aplicativo contém uma barra de menu arrastável e uma barra de ferramentas.|  
   |**Imagens e barras de ferramentas definidas pelo usuário**|Permite ao usuário personalizar a barra de ferramentas e as imagens da barra de ferramentas em tempo de execução.|  
   |**Comportamento de menu personalizado**|Especifica se o menu contém a lista completa de itens quando aberto, ou se ele contém apenas os comandos que o usuário usa com mais frequência.|  
   |**Usar uma faixa de opções**|Usa uma faixa de opções do Office 2007 semelhante em seu aplicativo em vez de uma barra de menu ou barra de ferramentas.|  
  
- **Título da caixa de diálogo**

   Para [classe CDialog](../../mfc/reference/cdialog-class.md)-com base em aplicativos, esse título aparecerá na barra de título da caixa de diálogo. Para editar esse campo, você deve primeiro selecionar o **caixa de diálogo com base** opção sob **tipo de aplicativo**. Para obter mais informações, consulte [tipo de aplicativo, Assistente de aplicativo MFC](../../mfc/reference/application-type-mfc-application-wizard.md).  
  
## <a name="see-also"></a>Consulte também  
 [Assistente de aplicativo do MFC](../../mfc/reference/mfc-application-wizard.md)

