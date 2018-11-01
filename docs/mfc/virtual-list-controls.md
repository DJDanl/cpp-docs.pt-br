---
title: Controles de lista virtuais
ms.date: 11/04/2016
helpviewer_keywords:
- cache, virtual list control item data
- list controls [MFC], virtual
- list controls [MFC], List view
- virtual list controls
ms.assetid: 319f841f-e426-423a-8276-d93f965b0b45
ms.openlocfilehash: b9da918017d300d7af61b1fd3ab27869e136bb8d
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50573640"
---
# <a name="virtual-list-controls"></a>Controles de lista virtuais

Um controle de lista virtual é um controle de exibição de lista que tem o estilo LVS_OWNERDATA. Esse estilo permite que o controle dar suporte a uma contagem de itens até um **DWORD** (a contagem de itens padrão só se estende para um **int**). No entanto, a maior vantagem fornecida por esse estilo é a capacidade de ter apenas um subconjunto de itens de dados na memória a qualquer momento. Isso permite que o controle de exibição de lista virtual se prestam para uso com grandes bancos de dados de informações, em que os métodos específicos de acesso aos dados já estão em vigor.

> [!NOTE]
>  Além de fornecer funcionalidade de lista virtual no `CListCtrl`, MFC também fornece a mesma funcionalidade na [CListView](../mfc/reference/clistview-class.md) classe.

Há alguns problemas de compatibilidade, que você deve estar atento ao desenvolver controles de lista virtual. Para obter mais informações, consulte a seção de problemas de compatibilidade do tópico de controles de exibição de lista no SDK do Windows.

## <a name="handling-the-lvngetdispinfo-notification"></a>Manipulando a notificação LVN_GETDISPINFO

Controles de lista virtuais mantêm informações muito pouco sobre o item. Exceto para as informações de foco e seleção de item, todas as informações do item são gerenciadas pelo proprietário do controle. Informações são solicitadas pelo framework por meio de uma mensagem de notificação LVN_GETDISPINFO. Para fornecer as informações solicitadas, o proprietário do controle de lista virtual (ou o controle em si) deve tratar essa notificação. Isso pode ser feito facilmente usando a janela Propriedades (consulte [mapeando mensagens para funções](../mfc/reference/mapping-messages-to-functions.md)). O código resultante deve ser algo parecido com o exemplo a seguir (onde `CMyDialog` possui o objeto de controle de lista virtual e a caixa de diálogo está tratando a notificação):

[!code-cpp[NVC_MFCControlLadenDialog#23](../mfc/codesnippet/cpp/virtual-list-controls_1.cpp)]

No manipulador de mensagem de notificação LVN_GETDISPINFO, você deve verificar para ver quais tipos de informações está sendo solicitado. Os valores possíveis são:

- `LVIF_TEXT` O *pszText* membro deve ser preenchido.

- `LVIF_IMAGE` O *iImage* membro deve ser preenchido.

- `LVIF_INDENT` O *iIndent* membro deve ser preenchido.

- `LVIF_PARAM` O *lParam* membro deve ser preenchido. (Não apresentam de subelementos.)

- `LVIF_STATE` O *estado* membro deve ser preenchido.

Em seguida, você deve fornecer quaisquer informações são solicitadas para a estrutura.

O exemplo a seguir (obtido do corpo do manipulador de notificação para o objeto de controle de lista) demonstra um método possível, fornecendo informações para os buffers de texto e imagem de um item:

[!code-cpp[NVC_MFCControlLadenDialog#24](../mfc/codesnippet/cpp/virtual-list-controls_2.cpp)]

## <a name="caching-and-virtual-list-controls"></a>Controles de lista virtuais e armazenamento em cache

Como esse tipo de controle de lista é destinado para grandes conjuntos de dados, é recomendável que você armazenar em cache dados de item solicitado para melhorar o desempenho de recuperação. O framework fornece um mecanismo de cache-dicas para ajudar a otimizar o cache, enviando uma mensagem de notificação LVN_ODCACHEHINT.

O exemplo a seguir atualiza o cache com o intervalo passado para a função do manipulador.

[!code-cpp[NVC_MFCControlLadenDialog#25](../mfc/codesnippet/cpp/virtual-list-controls_3.cpp)]

Para obter mais informações sobre preparação e manter um cache, consulte a seção de gerenciamento de Cache do tópico de controles de exibição de lista no SDK do Windows.

## <a name="finding-specific-items"></a>Localizando itens específicos

A mensagem de notificação LVN_ODFINDITEM é enviada pelo controle de lista virtual quando um item de controle de lista específica precisa ser encontrado. A mensagem de notificação é enviada quando o controle de exibição de lista recebe acesso rápido a chave ou quando ele recebe uma mensagem LVM_FINDITEM. Informações de pesquisa são enviadas na forma de um **LVFINDINFO** estrutura, que é um membro da **NMLVFINDITEM** estrutura. Lidar com essa mensagem, substituindo o `OnChildNotify` função da sua lista de objeto de controle e dentro do corpo do manipulador, procure a mensagem LVN_ODFINDITEM. Se encontrado, execute a ação apropriada.

Você deve estar preparado para procurar um item que corresponda a informação fornecida pelo controle de exibição de lista. Você deve retornar o índice do item se for bem-sucedido ou -1 se nenhum item correspondente for encontrado.

## <a name="see-also"></a>Consulte também

[Usando CListCtrl](../mfc/using-clistctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)

