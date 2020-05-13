---
title: Controles de lista virtuais
ms.date: 11/04/2016
helpviewer_keywords:
- cache, virtual list control item data
- list controls [MFC], virtual
- list controls [MFC], List view
- virtual list controls
ms.assetid: 319f841f-e426-423a-8276-d93f965b0b45
ms.openlocfilehash: 1ade5f404e134cf6de20756dcc5af169fefdec76
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81375498"
---
# <a name="virtual-list-controls"></a>Controles de lista virtuais

Um controle de lista virtual é um controle de exibição de lista que tem o estilo LVS_OWNERDATA. Esse estilo permite que o controle suporte uma contagem de itens até um **DWORD** (a contagem de itens padrão só se estende a um **int**). No entanto, a maior vantagem proporcionada por esse estilo é a capacidade de ter apenas um subconjunto de itens de dados na memória a qualquer momento. Isso permite que o controle de visualização de lista virtual se empreste para uso com grandes bancos de dados de informações, onde métodos específicos de acesso aos dados já estão em vigor.

> [!NOTE]
> Além de fornecer funcionalidade de `CListCtrl`lista virtual em , O MFC também fornece a mesma funcionalidade na classe [CListView.](../mfc/reference/clistview-class.md)

Existem alguns problemas de compatibilidade que você deve estar ciente ao desenvolver controles de lista virtuais. Para obter mais informações, consulte a seção Problemas de compatibilidade do tópico Controles de exibição de lista no SDK do Windows.

## <a name="handling-the-lvn_getdispinfo-notification"></a>Manuseio da Notificação de LVN_GETDISPINFO

Os controles de lista virtuais mantêm muito pouca informação sobre itens. Com exceção da seleção do item e das informações de foco, todas as informações do item são gerenciadas pelo proprietário do controle. As informações são solicitadas pelo framework através de uma mensagem de notificação LVN_GETDISPINFO. Para fornecer as informações solicitadas, o proprietário do controle de lista virtual (ou o próprio controle) deve lidar com essa notificação. Isso pode ser feito facilmente usando o [Assistente de Classe](reference/mfc-class-wizard.md) (consulte Mapeamento de [Mensagens para Funções](../mfc/reference/mapping-messages-to-functions.md)). O código resultante deve se parecer com `CMyDialog` o exemplo a seguir (onde possui o objeto de controle de lista virtual e a caixa de diálogo está lidando com a notificação):

[!code-cpp[NVC_MFCControlLadenDialog#23](../mfc/codesnippet/cpp/virtual-list-controls_1.cpp)]

No manipulador da mensagem de notificação LVN_GETDISPINFO, você deve verificar que tipo de informação está sendo solicitada. Os valores possíveis são:

- `LVIF_TEXT`O *membro pszText* deve ser preenchido.

- `LVIF_IMAGE`O membro *iImage* deve ser preenchido.

- `LVIF_INDENT`O *membro identificado deve* ser preenchido.

- `LVIF_PARAM`O *membro do IParam* deve ser preenchido. (Não presente para subitens.)

- `LVIF_STATE`O *deputado estadual* deve ser preenchido.

Em seguida, você deve fornecer qualquer informação solicitada de volta para a estrutura.

O exemplo a seguir (tirado do corpo do manipulador de notificação para o objeto de controle de lista) demonstra um método possível fornecendo informações para os buffers de texto e imagem de um item:

[!code-cpp[NVC_MFCControlLadenDialog#24](../mfc/codesnippet/cpp/virtual-list-controls_2.cpp)]

## <a name="caching-and-virtual-list-controls"></a>Cache e Controles de Listas Virtuais

Como esse tipo de controle de lista destina-se a grandes conjuntos de dados, recomenda-se que você faça cache de dados solicitados em cache para melhorar o desempenho de recuperação. A estrutura fornece um mecanismo de sugestão de cache para ajudar a otimizar o cache enviando uma mensagem de notificação LVN_ODCACHEHINT.

O exemplo a seguir atualiza o cache com o intervalo passado para a função do manipulador.

[!code-cpp[NVC_MFCControlLadenDialog#25](../mfc/codesnippet/cpp/virtual-list-controls_3.cpp)]

Para obter mais informações sobre a preparação e manutenção de um cache, consulte a seção Gerenciamento de cache do tópico Controles de exibição de listas no SDK do Windows.

## <a name="finding-specific-items"></a>Encontrando itens específicos

A mensagem de notificação LVN_ODFINDITEM é enviada pelo controle de lista virtual quando um item de controle de lista específico precisa ser encontrado. A mensagem de notificação é enviada quando o controle de exibição de lista recebe acesso rápido à tecla ou quando recebe uma mensagem LVM_FINDITEM. As informações de pesquisa são enviadas na forma de uma estrutura **LVFINDINFO,** que é membro da estrutura **NMLVFINDITEM.** Manuseie esta `OnChildNotify` mensagem substituindo a função do objeto de controle da lista e dentro do corpo do manipulador, verifique se a mensagem LVN_ODFINDITEM. Se for encontrado, execute as medidas apropriadas.

Você deve estar preparado para procurar um item que corresponda às informações fornecidas pelo controle de exibição da lista. Você deve retornar o índice do item se for bem sucedido, ou -1 se nenhum item correspondente for encontrado.

## <a name="see-also"></a>Confira também

[Usando CListCtrl](../mfc/using-clistctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
