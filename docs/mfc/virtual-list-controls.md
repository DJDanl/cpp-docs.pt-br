---
title: Controles de lista virtuais
ms.date: 11/04/2016
helpviewer_keywords:
- cache, virtual list control item data
- list controls [MFC], virtual
- list controls [MFC], List view
- virtual list controls
ms.assetid: 319f841f-e426-423a-8276-d93f965b0b45
ms.openlocfilehash: a6e76a812a6196c487f72516e2b88198a544fdc7
ms.sourcegitcommit: 3caf5261b3ea80d9cf14038c116ba981d655cd13
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/11/2019
ms.locfileid: "70907339"
---
# <a name="virtual-list-controls"></a>Controles de lista virtuais

Um controle de lista virtual é um controle de exibição de lista que tem o estilo LVS_OWNERDATA. Esse estilo permite que o controle dê suporte a uma contagem de itens até um **DWORD** (a contagem de itens padrão se estende apenas a um **int**). No entanto, a maior vantagem fornecida por esse estilo é a capacidade de ter apenas um subconjunto de itens de dados na memória a qualquer momento. Isso permite que o controle de exibição de lista virtual se consiga para usar com grandes bancos de dados de informações, em que métodos específicos de acesso ao data já estão em vigor.

> [!NOTE]
>  Além de fornecer a funcionalidade de lista virtual `CListCtrl`no, o MFC também fornece a mesma funcionalidade na classe [CListView](../mfc/reference/clistview-class.md) .

Há alguns problemas de compatibilidade que você deve estar atento ao desenvolver controles de lista virtual. Para obter mais informações, consulte a seção problemas de compatibilidade do tópico controles de exibição de lista no SDK do Windows.

## <a name="handling-the-lvn_getdispinfo-notification"></a>Manipulando a notificação LVN_GETDISPINFO

Os controles de lista virtual mantêm muito pouco informações sobre o item. Exceto para a seleção de item e as informações de foco, todas as informações de item são gerenciadas pelo proprietário do controle. As informações são solicitadas pela estrutura por meio de uma mensagem de notificação do LVN_GETDISPINFO. Para fornecer as informações solicitadas, o proprietário do controle de lista virtual (ou o próprio controle) deve lidar com essa notificação. Isso pode ser feito facilmente usando o [Assistente de classe](reference/mfc-class-wizard.md) (consulte [mapeando mensagens para funções](../mfc/reference/mapping-messages-to-functions.md)). O código resultante deve ser semelhante ao exemplo a seguir (onde `CMyDialog` é proprietário do objeto de controle de lista virtual e a caixa de diálogo está manipulando a notificação):

[!code-cpp[NVC_MFCControlLadenDialog#23](../mfc/codesnippet/cpp/virtual-list-controls_1.cpp)]

No manipulador da mensagem de notificação LVN_GETDISPINFO, você deve verificar quais tipos de informações estão sendo solicitadas. Os valores possíveis são:

- `LVIF_TEXT`O membro *pszText* deve ser preenchido.

- `LVIF_IMAGE`O membro *iImage* deve ser preenchido.

- `LVIF_INDENT`O membro *iIndent* deve ser preenchido.

- `LVIF_PARAM`O membro *lParam* deve ser preenchido. (Não está presente para subitens.)

- `LVIF_STATE`O membro de *estado* deve ser preenchido.

Em seguida, você deve fornecer todas as informações que são solicitadas de volta para a estrutura.

O exemplo a seguir (extraído do corpo do manipulador de notificação para o objeto de controle de lista) demonstra um método possível fornecendo informações para os buffers de texto e a imagem de um item:

[!code-cpp[NVC_MFCControlLadenDialog#24](../mfc/codesnippet/cpp/virtual-list-controls_2.cpp)]

## <a name="caching-and-virtual-list-controls"></a>Cache e controles de lista virtual

Como esse tipo de controle de lista destina-se a grandes conjuntos de dados, é recomendável que você armazene em cache os dados de item solicitados para melhorar o desempenho de recuperação. A estrutura fornece um mecanismo de dicas de cache para ajudar na otimização do cache enviando uma mensagem de notificação LVN_ODCACHEHINT.

O exemplo a seguir atualiza o cache com o intervalo passado para a função de manipulador.

[!code-cpp[NVC_MFCControlLadenDialog#25](../mfc/codesnippet/cpp/virtual-list-controls_3.cpp)]

Para obter mais informações sobre como preparar e manter um cache, consulte a seção Gerenciamento de cache do tópico listar controles de exibição na SDK do Windows.

## <a name="finding-specific-items"></a>Localizando itens específicos

A mensagem de notificação LVN_ODFINDITEM é enviada pelo controle de lista virtual quando um item de controle de lista específico precisa ser encontrado. A mensagem de notificação é enviada quando o controle de exibição de lista recebe acesso rápido à chave ou recebe uma mensagem LVM_FINDITEM. As informações de pesquisa são enviadas na forma de uma estrutura **LVFINDINFO** , que é membro da estrutura **NMLVFINDITEM** . Manipule essa mensagem substituindo a `OnChildNotify` função do objeto de controle de lista e dentro do corpo do manipulador, verifique a mensagem LVN_ODFINDITEM. Se for encontrado, execute a ação apropriada.

Você deve estar preparado para procurar um item que corresponda às informações fornecidas pelo controle de exibição de lista. Você deve retornar o índice do item se for bem-sucedido ou-1 se nenhum item correspondente for encontrado.

## <a name="see-also"></a>Consulte também

[Usando CListCtrl](../mfc/using-clistctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
