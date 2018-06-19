---
title: Controles de lista virtual | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- cache, virtual list control item data
- list controls [MFC], virtual
- list controls [MFC], List view
- virtual list controls
ms.assetid: 319f841f-e426-423a-8276-d93f965b0b45
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 0b580e455aab7ff95beb85c02b8e3ca79dfa8a46
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33384186"
---
# <a name="virtual-list-controls"></a>Controles de lista virtuais
Um controle de lista virtual é um controle de exibição de lista que tem o **LVS_OWNERDATA** estilo. Esse estilo permite que o controle oferecer suporte a uma contagem de itens até um `DWORD` (somente estende a contagem de item padrão para uma `int`). No entanto, a maior vantagem fornecida por este estilo é a capacidade de ter apenas um subconjunto de itens de dados na memória a qualquer momento. Isso permite que o controle de exibição de lista virtual prestam para uso com grandes bancos de dados de informações, em que os métodos específicos de acesso aos dados já estão em vigor.  
  
> [!NOTE]
>  Além de fornecer a funcionalidade de lista virtual no `CListCtrl`, MFC também fornece a mesma funcionalidade de [CListView](../mfc/reference/clistview-class.md) classe.  
  
 Há alguns problemas de compatibilidade, que você deve estar ciente ao desenvolver controles de lista virtual. Para obter mais informações, consulte a seção de problemas de compatibilidade do tópico controles de exibição de lista no SDK do Windows.  
  
## <a name="handling-the-lvngetdispinfo-notification"></a>Manipulando a notificação LVN_GETDISPINFO  
 Controles de lista virtual mantêm informações sobre o item muito pouco. Exceto para a seleção de item e informações de foco, todas as informações de item são gerenciadas pelo proprietário do controle. As informações são solicitadas pelo framework por meio de um **LVN_GETDISPINFO** mensagem de notificação. Para fornecer as informações solicitadas, o proprietário do controle de lista virtual (ou o próprio controle) deve tratar essa notificação. Isso pode ser feito facilmente usando a janela Propriedades (consulte [mapeando mensagens para funções](../mfc/reference/mapping-messages-to-functions.md)). O código resultante deve ser algo como o exemplo a seguir (onde `CMyDialog` possui o objeto de controle de lista virtual e a caixa de diálogo está manipulando a notificação):  
  
 [!code-cpp[NVC_MFCControlLadenDialog#23](../mfc/codesnippet/cpp/virtual-list-controls_1.cpp)]  
  
 No manipulador para o **LVN_GETDISPINFO** mensagem de notificação, você deve verificar o tipo de informação está sendo solicitado. Os valores possíveis são:  
  
-   `LVIF_TEXT` O `pszText` membro deve ser preenchido.  
  
-   `LVIF_IMAGE` O `iImage` membro deve ser preenchido.  
  
-   **LVIF_INDENT** o *iIndent* membro deve ser preenchido.  
  
-   `LVIF_PARAM` O *lParam* membro deve ser preenchido. (Não está presente para subitens.)  
  
-   `LVIF_STATE` O *estado* membro deve ser preenchido.  
  
 Em seguida, você deve fornecer quaisquer informações foi solicitadas a estrutura.  
  
 O exemplo a seguir (obtido do corpo do manipulador de notificação para o objeto de controle de lista) demonstra um método possível fornecendo informações para os buffers de texto e imagem de um item:  
  
 [!code-cpp[NVC_MFCControlLadenDialog#24](../mfc/codesnippet/cpp/virtual-list-controls_2.cpp)]  
  
## <a name="caching-and-virtual-list-controls"></a>Controles de lista de cache e Virtual  
 Porque esse tipo de controle de lista foi desenvolvido para grandes conjuntos de dados, é recomendável que você armazenar em cache dados de item solicitado para melhorar o desempenho de recuperação. O framework fornece um mecanismo de dicas de cache para ajudar a otimizar o cache, enviando um **LVN_ODCACHEHINT** mensagem de notificação.  
  
 O exemplo a seguir atualiza o cache com o intervalo passado para a função de manipulador.  
  
 [!code-cpp[NVC_MFCControlLadenDialog#25](../mfc/codesnippet/cpp/virtual-list-controls_3.cpp)]  
  
 Para obter mais informações sobre como preparar e manter um cache, consulte a seção de gerenciamento de Cache do tópico controles de exibição de lista no SDK do Windows.  
  
## <a name="finding-specific-items"></a>Localizando itens específicos  
 O **LVN_ODFINDITEM** mensagem de notificação é enviada pelo controle de lista virtual quando um item de controle de lista específica precisa ser encontrado. A mensagem de notificação é enviada quando o controle de exibição de lista recebe acesso rápido de chave ou quando ele recebe um **LVM_FINDITEM** mensagem. Informações de pesquisa são enviadas na forma de um **LVFINDINFO** estrutura, que é um membro do **NMLVFINDITEM** estrutura. Lidar com essa mensagem, substituindo o `OnChildNotify` função da sua lista de objeto de controle e dentro do corpo do manipulador, procure o **LVN_ODFINDITEM** mensagem. Se encontrado, execute a ação apropriada.  
  
 Você deve estar preparado para procurar um item que corresponde às informações fornecidas pelo controle de exibição de lista. Você deve retornar o índice do item se for bem-sucedido, ou -1 se nenhum item correspondente for encontrado.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CListCtrl](../mfc/using-clistctrl.md)   
 [Controles](../mfc/controls-mfc.md)

